#ifndef PAINTER_H
#define PAINTER_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QPainter>
#include<QImage>
#include<QMouseEvent>
#include<QDesktopWidget>
#include <QInputDialog>
#include<QColorDialog>
#include<QRect>
#include <QtCore>
#include<QtGui>
#include <QDialog>
#include<QGraphicsScene>
#include <QUndoCommand>
#include<QFileDialog>
#include<QFile>
#include<QFileInfo>
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include <QFileInfo>
#include<QImageReader>





#define DEFAULT_SIZE  5;

namespace Ui {
class painter;
}

class QPainter;
class QImage;


/*!
 * Here we have all commands to be used for Painter class.
 */

/*!
 *@brief The Painter class for the drawing items and editing.
 */
class Painter : public QMainWindow
{

    Q_OBJECT

public:
    explicit Painter(QWidget *parent = 0);
//!destructor.
    ~Painter();


protected:
    /*!
     *Override paint Event to make image drawable.
     */
    void paintEvent(QPaintEvent *e) override;
    /*!
     * \brief mousePressEvent
     * \param e pointer. Mouse press.
     */

    void mousePressEvent(QMouseEvent  *e) override;
    /*!
     * \brief mouseMoveEvent
     * \param e pointer. Mouse moving while pressing.
     */

    void mouseMoveEvent(QMouseEvent * e) override;
    /*!
     * \brief mouseReleaseEvent
     * \param e pointer. Mouse relese.
     */

    void mouseReleaseEvent(QMouseEvent *e) override;
protected slots:


private slots:
    /*!
     *Method for set size of the pen.
     */
    void setSize();
    /*!
     *Method for set color of the pen.
     */
    void setColor();
    /*!
     *Method for erase.
     */
    void erase();
    /*!
     *Method for draw ellipse.
     */
   void ellipseDraw(int left, int top, int width, int height);
   /*!
    *Method for draw lines using painter.
    */
    void draw(QMouseEvent *e);
    /*!
     *Method for saving the drawn image.
     */
    void saveImage();
    /*!
     *Method for open previous drawn image.
     */
    void openFile();
    /*!
     *Method for opening dialogpos window and drawing an ellipse.
     */
    void openDialogEllipse();
    /*!
     *Method for drawing rectangel.
     */
    void rectangelDraw(int left,int top,int width, int height);
    /*!
     *Method for creating new image to draw.
     */
    void newImage();
    /*!
     *Method for opening dialogpos window and drawing a rectangel or square.
     */
    void openDialogRect();
    /*!
     *Display about Painter MessageBox.
     */
    void aboutPainter();
    /*!
     *Method for selecting default pen.
     */
    void selectPen();
    /*!
     *Method for selecting default brush.
     */
    void setBrush();
private:
    //decalre variables

    Ui::painter *ui;
//! QFIle type variable filename.
    /*!
     * \brief filename.
     */
    QFile filename;
    /*!
     *Declare a pointer variable called mPainter as a pointer of type QPainter.
     */
    QPainter *mPainter;
    /*!
     *Declare a pointer variable called mImage as a pointer of type QImage.
     */
    QImage * mImage;
    /*!
     *loadedImage variable for opening a image.
     */
    QImage  loadedImage;
    /*!
     * mBegin variable. If mouse pointer click and
     */
    QPoint mBegin;
    /*!
     * mEnd variable.
     */
    QPoint mEnd;
    /*!
     * mEnabled variable.
     */
    bool mEnabled;
    /*!
     * pSize variable.
     */
    int  pSize;
    /*!
     * p_Color variable.
     */
    QColor p_Color;
    /*!
     *Declare a pointer variable called ellipse as a pointer of type QGraphicsEllipseItem.
     */
    QGraphicsEllipseItem * ellipse;
    /*!
     *Declare a pointer variable called rectangel as a pointer of type QGraphicsEllipseItem.
     */
    QGraphicsRectItem * rectangel;
    /*!
     *Method for connecting methods for the action.
     */
    void setupConnectionsPainter();

    QImage *image;
    /*!
     * pixmap variable variable for load image.
     */
    QPixmap pixmap;
    /*!
     * Decalre variable image2 type QImage.
     */
 QImage image2;

 QImage * imageOpen;


};

#endif // PAINTER_H
