#include "ui/MainWindow.h"
#include <QApplication>
#include <QDebug>
#include <QScreen>
#include <QTimer>

int main(int argc, char *argv[]) {
  // Force software OpenGL rendering instead of hardware acceleration
  qputenv("QT_OPENGL", "software");
  qputenv("QT_QUICK_BACKEND", "software");

  // Enable Qt debugging
  qputenv("QT_DEBUG_PLUGINS", "1");

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

  // Reset window flags to default before showing
  mainWindow.setWindowFlags(Qt::Window);

  // Show window first before changing other properties
  mainWindow.show();

  // Process events to ensure window is created
  QApplication::processEvents();

  // Use a short timer to make sure window gets focus after initial setup
  QTimer::singleShot(100, [&]() {
    mainWindow.raise();
    mainWindow.activateWindow();

    qDebug() << "Window should be visible now";
  });

  // Execute the application
  return app.exec();
}