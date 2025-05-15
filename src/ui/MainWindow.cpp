#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // Create central widget and layout
  QWidget *centralWidget = new QWidget(this);
  QVBoxLayout *layout = new QVBoxLayout(centralWidget);

  // Create and add graph view
  m_graphView = new GraphView(this);
  layout->addWidget(m_graphView);

  setCentralWidget(centralWidget);

  // Connect signals
  connect(m_graphView, &GraphView::nodeClicked, this, &MainWindow::onNodeClicked);

  // Add some test nodes and edges
  m_graphView->addNode("node1", "Node 1", 0, 0);
  m_graphView->addNode("node2", "Node 2", 150, 0);
  m_graphView->addNode("node3", "Node 3", 75, 100);

  m_graphView->addEdge("node1", "node2");
  m_graphView->addEdge("node1", "node3");
  m_graphView->addEdge("node2", "node3");
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::onNodeClicked(const QString &nodeId)
{
  // Do something when a node is clicked
  QMessageBox::information(this, "Node Clicked", "You clicked on node: " + nodeId);
}