/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/


#include "tetris.h"


Tetris::Tetris() {}


Tetris::~Tetris() {}


void Tetris::setup_game(int rows, int columns) {
    // Initialize game data
    this->background_color = {44, 44, 127, 255};
    this->grid = Grid(rows, columns, CELL_SIZE);
    this->blocks = get_all_blocks();
    this->current_block = get_random_block();
    this->next_block = get_random_block();

    this->current_time = 0;
    this->last_update_time = 0;
    this->game_over = false;
    this->score = 0;
    this->high_score = 0;

    this->current_screen = TITLE;
    this->title_image = LoadTexture("../src/games/src/tetris/include/title_image.png");
    this->user_exit = false;
}


/*
 * Game functionality function definitions
 */
std::vector<Block> Tetris::get_all_blocks() {
    return {L_Block(), J_Block(), I_Block(), T_Block(),
            O_Block(), S_Block(), Z_Block()};
}


void Tetris::reset_game() {
    this->grid.initialize_grid();
    this->blocks = get_all_blocks();
    this->current_block = get_random_block();
    this->next_block = get_random_block();
    this->score = 0; 
}


Block Tetris::get_random_block() {
    // Block vector empty, add all blocks again
    if (blocks.empty())
        blocks = get_all_blocks();
        
    int random_index = rand() % blocks.size();

    // Get random block and remove it from vector
    Block random_block = blocks[random_index];
    blocks.erase(blocks.begin() + random_index);

    return random_block;
}


bool Tetris::block_outside() {
    std::vector<Position> cell_positions = current_block.get_cell_positions();

    // Check if any squares are outside grid
    for (Position square : cell_positions) {
        if (grid.outside_grid(square.get_row(), square.get_column()))
            return true;
    }
    return false;
}


bool Tetris::block_fits() {
    std::vector<Position> cell_positions = current_block.get_cell_positions();

    // Check if any squares conflict with other blocks
    for (Position square : cell_positions) {
        if (grid.get_cell(square.get_row(), square.get_column()) != 0)
            return false;
    }
    return true;
}


void Tetris::calculate_full_row_score(int full_rows) {
    // Calculate current game score
    if (full_rows == 1) {
        score += 100; 
    }
    else if (full_rows == 2) {
        score += 300;
    }
    else if (full_rows == 3) {
        score += 500;
    }
    else if (full_rows == 4) {
        score += 750;
    }
    // Calculate session high score
    if (score > high_score)
        high_score = score;
}


void Tetris::get_next_block() {
    std::vector<Position> cell_positions = current_block.get_cell_positions();
    int full_rows = 0;

    // Add block to grid
    for (Position square : cell_positions) {
        grid.update_grid_cell(square.get_row(), square.get_column(), current_block.get_id());
    }
    full_rows = clear_full_rows();
    calculate_full_row_score(full_rows);
    current_block = next_block;

    if (block_fits() == false)
        game_over = true;

    next_block = get_random_block();
}


void Tetris::draw_game() {
    grid.draw_grid(START_X, START_Y);
    current_block.draw_block();
    // draw score
    // draw next block
    // draw game over is game over
}


void Tetris::move_left() {
    current_block.move_block(0, -1);

    if (block_outside() || block_fits() == false)
        current_block.move_block(0, 1);
}


void Tetris::move_right() {
    current_block.move_block(0, 1);

    if (block_outside() || block_fits() == false)
        current_block.move_block(0, -1);
}


void Tetris::move_down() {
    if (game_over)
        return;

    current_block.move_block(1, 0);

    // Outside grid or collision
    if (block_outside() || block_fits() == false) {
        current_block.move_block(-1, 0);

        // Block placed, do these
        get_next_block();
    }
}


//
// EDIT LATER TO SUPPORT WALL KICKS/SUPER ROTATIONS
//
void Tetris::rotate_block() {
    // O Block type, no need to rotate
    if (current_block.get_id() == 4)
        return;

    current_block.update_rotate_state(1);

    if (block_outside() || block_fits() == false)
        current_block.update_rotate_state(-1);
}


void Tetris::move_to_bottom() {
    while (!block_outside() && block_fits()) {
        current_block.move_block(1, 0);
        score++;
    }

    if (block_outside() || block_fits() == false)
        current_block.move_block(-1, 0);
}


void Tetris::handle_input() {
    int key_pressed = GetKeyPressed();

    if (game_over) {
        return;
    }
    else if (key_pressed == KEY_LEFT) {
        move_left();
    }
    else if (key_pressed == KEY_RIGHT) {
        move_right();
    }
    else if (key_pressed == KEY_DOWN) {
        move_down();
        score++;
    }
    else if (key_pressed == KEY_UP) {
        rotate_block();
    }
    else if (key_pressed == KEY_SPACE) {
        move_to_bottom();
    }
}


void Tetris::move_block_down(double interval) {
    if (current_screen != GAMEPLAY)
        return;

    current_time = GetTime();

    // Check if time is within interval
    if (current_time - last_update_time >= interval) {
        last_update_time = current_time;

        // Move current block down one sqaure
        move_down();
    }
}


bool Tetris::full_row(int row) {
    // Check for valid row
    if (row < 0 || row >= grid.get_rows())
        return false;

    // Check values of each column in row
    for (int i = 0; i < grid.get_columns(); i++) {
        if (grid.get_cell(row, i) == 0)
            return false;
    }
    return true;
}


void Tetris::move_row_down(int row, int num_rows) {
    // Check for valid row
    if (row < 0 || row >= grid.get_rows())
        return;

    // Shift row down by num_rows and replace old row with zeroes
    for (int i = 0; i < grid.get_columns(); i++) {
        grid.update_grid_cell(row + num_rows, i, grid.get_cell(row, i));
        grid.update_grid_cell(row, i, 0);
    }
}


void Tetris::clear_row(int row) {
    // Check for valid row
    if (row < 0 || row >= grid.get_rows())
        return;

    // Update row with zeros
    for (int i = 0; i < grid.get_columns(); i++)
        grid.update_grid_cell(row, i, 0);
}


int Tetris::clear_full_rows() {
    int full_rows = 0;

    // Clear rows bottom up
    for (int i = grid.get_rows() - 1; i >= 0; i--) {
        if (full_row(i)) {
            clear_row(i);
            full_rows++;
        }
        else if (full_rows > 0) {
            move_row_down(i, full_rows);
        }
    }
    return full_rows;
}


/*
 * UI Function definitions
 */
void Tetris::draw_title_screen() {
    std::vector<Color> colors = get_colors();
    Vector2 title_position = {(float)(SCREEN_WIDTH - title_image.width * 7)/2, 200.0f};

    // Draw title image
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, background_color);
    DrawTextureEx(title_image, title_position, 0.0f, 7.0f, WHITE);
}


void Tetris::draw_exit_screen() {
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_WIDTH, background_color);
    DrawRectangle(0, 100, SCREEN_WIDTH, SCREEN_HEIGHT / 2, BLACK);
    DrawText("Are you sure you want to exit? [Y/N]", 60, 300, 30, WHITE);
}


void Tetris::get_current_screen() {
    if (current_screen == TITLE) {
        if (IsKeyPressed(KEY_ENTER))
            current_screen = GAMEPLAY;

        else if (IsKeyPressed(KEY_ESCAPE))
            current_screen = EXIT;
    }
    else if (current_screen == GAMEPLAY) {
        if (IsKeyPressed(KEY_ESCAPE))
            current_screen = EXIT;
    }
    else if (current_screen == EXIT) {
        if (IsKeyPressed(KEY_Y))
            user_exit = true;
        else if (IsKeyPressed(KEY_N))
            current_screen = GAMEPLAY;
    }
    else if (current_screen == PLAY_AGAIN) {
        std::cout << "NULL" << std::endl;
    }
}


void Tetris::display_current_screen() {
    if (current_screen == TITLE) {
        draw_title_screen();
    }
    else if (current_screen == GAMEPLAY) {
        handle_input();
        move_block_down(0.2);
        draw_game();
    }
    else if (current_screen == EXIT) {
        // display game play stuff
        draw_exit_screen();
    }
    else if (current_screen == PLAY_AGAIN) {
        // display are you sure you want to exit y/n
        std::cout << "NULL" << std::endl;
    }
}


void Tetris::run_game() {
    const int rows = 20;
    const int columns = 10;

    // Setup window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sirtet");
    SetTargetFPS(60);

    // Unbind ESC key
    SetExitKey(KEY_NULL);

    setup_game(rows, columns);

    while (!WindowShouldClose()) {
        if (user_exit) break;

        get_current_screen();

//------------------------------------//
        BeginDrawing();

        ClearBackground(background_color);
        display_current_screen();

        EndDrawing();
    }
    UnloadTexture(title_image);
    CloseWindow();

    return;
}
