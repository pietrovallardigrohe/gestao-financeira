#include "ui/MainWindow.h"
#include <QApplication>
#include <QScreen>
#include "ui/Window.h"

void main(int argc, char *argv[])
{
  // Force software OpenGL rendering instead of hardware acceleration
  qputenv("QT_OPENGL", "software");
  qputenv("QT_QUICK_BACKEND", "software");

  QApplication app(argc, argv);

  app.quitOnLastWindowClosed();

  std::unique_ptr<MainWindow> main_window = initWindow(app);

  app.exec();
}