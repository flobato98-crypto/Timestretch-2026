#include "MainWindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
}


void MainWindow::setupUi()
{
    setWindowTitle("TimeStretch 2026");

    resize(900, 600);


    QWidget *central = new QWidget(this);

    QVBoxLayout *layout = new QVBoxLayout(central);


    QLabel *title = new QLabel(
        "TimeStretch 2026\n\n"
        "Qt 6 Application Foundation",
        central
    );

    title->setAlignment(Qt::AlignCenter);


    layout->addWidget(title);


    setCentralWidget(central);
}
