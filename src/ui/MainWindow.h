#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GraphView.h"

namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void onNodeClicked(const QString &nodeId);

private:
  Ui::MainWindow *ui;
  GraphView *m_graphView;
};

#endif // MAINWINDOW_H