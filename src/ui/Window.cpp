#include <QApplication>
#include <QScreen>
#include "MainWindow.h"
#include <memory>

std::unique_ptr<MainWindow> initWindow(QApplication &app)
{ // Create the main window
    std::unique_ptr<MainWindow> mainWindow = std::make_unique<MainWindow>();

    // Set window properties to ensure it's visible
    mainWindow->setWindowTitle("Gestão Financeira");
    mainWindow->resize(800, 600);

    // Position window at the center of the primary screen

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - mainWindow->width()) / 2;
    int y = (screenGeometry.height() - mainWindow->height()) / 2;
    mainWindow->move(x, y);

    // Set the window to stay on top
    mainWindow->setWindowFlags(mainWindow->windowFlags() |
                               Qt::WindowStaysOnTopHint);

    // Make sure the window is visible and active
    mainWindow->setWindowState(Qt::WindowActive);
    mainWindow->show();
    mainWindow->raise();
    mainWindow->activateWindow();

    mainWindow->setAttribute(Qt::WA_DeleteOnClose);

    MainWindow *raw_pointer = mainWindow.release();

    // QObject::connect(raw_pointer, &QObject::destroyed, &app, &QApplication::quit);

    // Execute the application
    return std::move(mainWindow);
}