#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "notepad.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
/*!
 * \brief MainWindow::~MainWindow
 */

MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * @brief MainWindow::on_btnNotepad_clicked
 */
void MainWindow::on_btnNotepad_clicked()
{
   newNotepadWindow = new Notepad();
   newNotepadWindow->show();
}
/*!
 * @brief MainWindow::on_paint_clicked
 */
void MainWindow::on_paint_clicked()
{
    newPainterWindow = new Painter();
    newPainterWindow->show();
}


