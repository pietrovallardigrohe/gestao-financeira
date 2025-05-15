#include "ui/MainWindow.h"
#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[]) {
  // Force software OpenGL rendering instead of hardware acceleration
  qputenv("QT_OPENGL", "software");
  qputenv("QT_QUICK_BACKEND", "software");

  QApplication app(argc, argv);

  // Create the main window
  MainWindow mainWindow;

  // Set window properties to ensure it's visible
  mainWindow.setWindowTitle("Gestão Financeira");
  mainWindow.resize(800, 600);

  // Position window at the center of the primary screen
  QScreen *screen = QGuiApplication::primaryScreen();
  QRect screenGeometry = screen->geometry();
  int x = (screenGeometry.width() - mainWindow.width()) / 2;
  int y = (screenGeometry.height() - mainWindow.height()) / 2;
  mainWindow.move(x, y);

  // Set the window to stay on top
  mainWindow.setWindowFlags(mainWindow.windowFlags() |
                            Qt::WindowStaysOnTopHint);

  // Make sure the window is visible and active
  mainWindow.setWindowState(Qt::WindowActive);
  mainWindow.show();
  mainWindow.raise();
  mainWindow.activateWindow();

  // Execute the application
  return app.exec();
}