/****************************************************************************
 * File Name:
 * Date:
 * Description:
 * Dependencies:
 * Author(s): Raymond Cen,
 *            Ivan Wong
 ****************************************************************************/

#pragma once

// Qt Libraries
#include <QObject>
#include <QtQml>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

// Standard Libraries


// Custom Libraries
#include "game_launcher.h"
#include "game.h"

// typedef struct 

class GameLauncher : public QObject {
    Q_OBJECT
    QML_ELEMENT
private:
    // Variables


    // Methods

protected:

public:
    //--------------------------------------------
    // Default Contructor for Game Launcher
    GameLauncher();

    //--------------------------------------------
    // Destructor for Game Launcher
    ~GameLauncher();

    //--------------------------------------------
    // Initialization function for Game Launcher
    void initializeLauncher();

    //--------------------------------------------
    // Function to add a game to the Game Launcher list
    void addGame(Game* new_game);

    //--------------------------------------------
    // Getter for the main window UI file path
    QString getMainWindowPath() const;

public slots:

// UI stuff

signals:

// UI changing stuff

};
