#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  // Set up the UI from the UI file
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }