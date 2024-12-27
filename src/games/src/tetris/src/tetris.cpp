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
    this->wall_kick_data = init_wall_kick_data();

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
std::vector<std::vector<std::vector<Position>>> Tetris::init_wall_kick_data() {
    std::vector<std::vector<std::vector<Position>>> wall_kick_data = {

    // J, L, T, S, Z Blocks
    {
        {Position(0, 0), Position(-1, 0), Position(-1, -1), Position(0, 2), Position(-1, 2)},   // 0 → 1
        {Position(0, 0), Position(1, 0), Position(1, 1), Position(0, -2), Position(1, -2)},     // 1 → 2
        {Position(0, 0), Position(1, 0), Position(1, -1), Position(0, 2), Position(1, 2)},      // 2 → 3
        {Position(0, 0), Position(-1, 0), Position(-1, 1), Position(0, -2), Position(-1, -2)}   // 3 → 0
    },

    // I Block
    {
        {Position(0, 0), Position(-2, 0), Position(1, 0), Position(-2, -1), Position(1, 2)},    // 0 → 1
        {Position(0, 0), Position(-1, 0), Position(2, 0), Position(-1, 2), Position(2, -1)},    // 1 → 2
        {Position(0, 0), Position(2, 0), Position(-1, 0), Position(2, 1), Position(-1, -2)},    // 2 → 3
        {Position(0, 0), Position(1, 0), Position(-2, 0), Position(1, -2), Position(-2, 1)}     // 3 → 0
    }
    };
    return wall_kick_data;
}


std::vector<Block> Tetris::get_all_blocks() {
    return {L_Block(), J_Block(), I_Block(), T_Block(),
            O_Block(), S_Block(), Z_Block()};
}


void Tetris::reset_game() {
    this->grid.initialize_grid();
    this->blocks = get_all_blocks();
    this->current_block = get_random_block();
    this->next_block = get_random_block();
    this->game_over = false;
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

        // Block landed
        get_next_block();
    }
}


Position Tetris::get_wall_kick_position(int block_id, int rotate_state, int index) {
    if (block_id == 4)
        return Position(0, 0);

    else if (block_id == 3)
        return wall_kick_data[1][rotate_state][index];

    else
        return wall_kick_data[0][rotate_state][index];
}


bool Tetris::perform_wall_kick(int rotate_state) {
    int block_id = current_block.get_id();
    Position offset = Position(0, 0);
    int dx = 0;
    int dy = 0;

    // Try all positions for current block
    for (int i = 0; i < 5; i++) {
        offset = get_wall_kick_position(block_id, rotate_state, i);
        dx = offset.get_row();
        dy = offset.get_column();

        current_block.move_block(dx, dy);

        if (block_fits())
            return true;

        // Block doesn't fit, move back to orignal spot
        current_block.move_block(-dx, -dy);
    }
    return false;
}


void Tetris::rotate_block() {
    // O Block type, no need to rotate
    if (current_block.get_id() == 4)
        return;

    int prev_rotate_state = current_block.get_rotate_state();

    current_block.update_rotate_state(1);

    if (block_outside() || block_fits() == false) {
        if (perform_wall_kick(prev_rotate_state) == false)
            current_block.update_rotate_state(-1);
    }
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
void Tetris::draw_score() {
    char score_text[10];
    Vector2 text_size;

    sprintf(score_text, "%d", score);

    DrawText("Current Score", 475, 70, 30, WHITE);
    DrawText(score_text, 475, 100, 30, WHITE);
}


void Tetris::draw_next_block() {
    DrawText("Next Block", 475, 200, 30, WHITE);
    next_block.draw_block(350, 270);
}


void Tetris::draw_game() {
    grid.draw_grid(START_X, START_Y);
    current_block.draw_block(0, 0);
    draw_score();
    draw_next_block();
}


void Tetris::draw_title_screen() {
    Vector2 title_position = {(float)(SCREEN_WIDTH - title_image.width * 7)/2, 200.0f};

    DrawTextureEx(title_image, title_position, 0.0f, 7.0f, WHITE);
}


void Tetris::draw_exit_screen() {
    DrawRectangle(0, 100, SCREEN_WIDTH, SCREEN_HEIGHT / 2, BLACK);
    DrawText("Are you sure you want to exit? [Y/N]", 60, 300, 30, WHITE);
}


void Tetris::draw_play_again_screen() {
    DrawRectangle(0, 100, SCREEN_WIDTH, SCREEN_HEIGHT / 2, BLACK);
    DrawText("Would you like to play again? [Y/N]", 60, 300, 30, WHITE);
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

        if (game_over)
            current_screen = PLAY_AGAIN;
    }
    else if (current_screen == EXIT) {
        if (IsKeyPressed(KEY_Y))
            user_exit = true;

        else if (IsKeyPressed(KEY_N))
            current_screen = GAMEPLAY;
    }
    else if (current_screen == PLAY_AGAIN) {
        if (IsKeyPressed(KEY_Y)) {
            reset_game();
            current_screen = GAMEPLAY;
        }
        else if (IsKeyPressed(KEY_N))
            current_screen = TITLE;
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
        draw_exit_screen();
    }
    else if (current_screen == PLAY_AGAIN) {
        draw_play_again_screen();
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

        BeginDrawing();

        ClearBackground(background_color);
        display_current_screen();

        EndDrawing();
    }
    UnloadTexture(title_image);
    CloseWindow();

    return;
}
