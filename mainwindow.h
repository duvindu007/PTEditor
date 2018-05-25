#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"notepad.h"
#include"painter.h"



namespace Ui {
class MainWindow;
}
/*!
 * @brief The MainWindow class to open painter or text editer.
 */

class MainWindow : public QMainWindow
{


    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    /**
*Declare pointer variable newNotepadWindow.

*/
     Notepad * newNotepadWindow;
     /*!
      * Declare pointer variable newPainterWindow.
*/


     Painter * newPainterWindow;


private slots:

/*!
 * Method for when btnNotepad clicked.

*/
    void on_btnNotepad_clicked();


    /*!
     * Method for when push button paint clicked.

    */
    void on_paint_clicked();


private:

    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
