#include "painter.h"
#include "ui_painter.h"
#include "dialogpos.h"



Painter::Painter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::painter)
{

    ui->setupUi(this);
    //! menuBar()->setNativeMenuBar(false).
    /*! so the menu bar visibal in any platform.
     */
  menuBar()->setNativeMenuBar(false);
  /*!
   *Assign mImge to a new QImage and assign size and the format.
  */
//set a Qimage size fit to the form
    mImage= new QImage(QApplication::desktop()->size(),QImage::Format_ARGB32_Premultiplied);


    /*!
     *Assign Image to Qpainter to draw on.
     * @param mImage to draw.

    */
    mPainter= new QPainter(mImage);
    mEnabled= false;
    p_Color= QColor(Qt::black);
    pSize=DEFAULT_SIZE;
    setupConnectionsPainter(); //action slot method


}

Painter::~Painter()
{ delete ui;
    delete mPainter;
   delete mImage;
}
/*!
 *Override paint event.

*/
void Painter::paintEvent(QPaintEvent *e){



    QPainter  paint(this);
    paint.fillRect(mImage->rect(),Qt::white); // color the image so it can be used to draw
    paint.drawImage(0,0,*mImage);
    e->accept();


}
/*!
     *Override mousePressEvent to start the drawing.
     * line start from the position of the mouse click.

    */
void Painter::mousePressEvent(QMouseEvent *e){


    mEnabled= true;
    mBegin= e->pos(); // stating position
    e->accept();


}

/*!
 * \brief Painter::mouseMoveEvent
 * \param e
 */
void Painter::mouseMoveEvent(QMouseEvent *e){


    if(!mEnabled){
        e->accept();
        return;
    }


draw(e);


 e->accept();

} /*!
     *mouseReleasEvent stop drawing when mouse button release.
     *

    */
void Painter::mouseReleaseEvent(QMouseEvent *e){


    mEnabled = false;//
    e->accept();

}
/*!
 *Declare QPen type variable pen and assign the color as the value of p_color.
 * pen.setCapStyle(Qt::RoundCap) set the cap style of the pen.
 * And set pen.setWidth() to the value of the variable pSize.
 * drawline from the mouse position begin to end.
 *@param e .

*/
void Painter::draw(QMouseEvent *e){


    QPen pen(p_Color);
   pen.setCapStyle(Qt::RoundCap);
   pen.setWidth(pSize);
       mEnd = e->pos();
       mPainter->setPen(pen);
      mPainter->drawLine(mBegin,mEnd);    // draw line between from mouse press and relese
      mBegin=mEnd;
      update();

}
/*!
 *QInputDialog::getInt set up pen size.

*/

void Painter:: setSize(){


   pSize= QInputDialog::getInt(this,"Set pencil size","Enter pencil size:");



}
/*!
     *QColorDialog::getColor set up pen color.

    */

void Painter:: setColor(){

    p_Color=QColorDialog::getColor(Qt::black,this,"Change the color");

}


/*!
 *Made the color of the pen white.And when it draw it drwing over the drawn items in the image.
 * Use QInputDialog::getInt so user can selet the size of the erase.

*/

void Painter::erase(){

    p_Color = Qt::white;
    pSize= QInputDialog::getInt(this,"Set eraser size", "Eraser Size", 10);



}
/*!
 *Use QFiledialog::getOpenFileName to get the name of the file.
 * And use QString type variable fileName to assign the value.
 * use QFileInfo class to get system independent file information.
 * and use suffix() method to get the characters of the file name after the "." and assign it to the variable format.
 * find the format.
 * load the file to a variable pixmap of type QPixmap.
 * then convert the pixmap to image and assign it to loadedImage of type QImage.
 * initate mImage to address of the variable loadedImage.
 * assign new QPainter.

*/

void Painter::openFile(){

QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"), QDir::currentPath());

/**
use QFileInfo class to get system independent file information.
*/

QFileInfo fileinfo(fileName);

QString format = fileinfo.suffix();


if(format=="png"){

mPainter->end();



pixmap.load(fileName); //load open file to pix map so it can be convert to qimage

loadedImage =pixmap.toImage(); // convert pixmap to image

mImage->scaled(loadedImage.size());
mImage = &loadedImage;
mPainter = new QPainter(mImage); //asign new qpainter

update();
}
else{

    QMessageBox::about(this,"Warning","This is not in .png format");


}
}



/*!
 *End the painter device.
 * Returns a copy of the mImage scaled to a rectangle defined by the size of the mImage and assign to image2.
 * Fill the image2 with color white.
 * initate mImage to address of the variable image2.
 * set the paint device mImage.
 * mPainter.begin(mImage).

*/
void Painter::newImage(){


mPainter->end();//end the current painter
image2 = QImage(mImage->scaled(mImage->size()));
image2.fill(QColor(Qt::white).rgb());
mImage = &image2;
//mPainter = new QPainter(mImage); //asign new painter
mPainter->begin(mImage);
update();


}


/*!
 @param left, top, width,height for the use of parameters of drawRect().

*/
void Painter::rectangelDraw(int left,int top,int width, int height){


    QPen pen(p_Color);
   pen.setCapStyle(Qt::RoundCap);
   pen.setWidth(pSize);
mPainter->setPen(pen);
mPainter->drawRect(left,top,width,height);
update();

}



/**
 @param left, top, width,height for the use of parameters of drawEllipse().

*/
void Painter::ellipseDraw(int left,int top,int width, int height){

    QPen pen(p_Color);
   pen.setCapStyle(Qt::RoundCap);
   pen.setWidth(pSize);
mPainter->setPen(pen);
mPainter->drawEllipse(left,top,width,height);

update();

}

/*!
* Declare pointer variable of DialogPos.
* use exec() method to show the dialog.
* And pass the parameters to the ellipseDraw() using getters.


*/
void Painter::openDialogEllipse(){

DialogPos * dp = new DialogPos();

dp->exec();

dp->on__ok_clicked();
ellipseDraw(dp->getLeft(),dp->getTop(),dp->getWidth(),dp->getHeight());
update();
dp->close();


}
/*!
* Declare pointer variable of DialogPos.
* Use exec() method to show the dialog.
* And pass the parameters to the  rectangelDraw() using getters.
*/
void Painter::openDialogRect(){

    DialogPos * dp = new DialogPos();

    dp->exec();
    dp->on__ok_clicked();


    rectangelDraw(dp->getLeft(),dp->getTop(),dp->getWidth(),dp->getHeight());
    update();

dp->close();
}
/*!
   * Dispaly QMessageBox about the painter using about box.
    */
void Painter::aboutPainter()
{
    QMessageBox::about(this,"About","Author: Duvindu\n Date:17/12/2017\n Name: Painter\n");


}
/*!
   * Set p_Color default color as black.
   * And set pSIze 5(DEFAULT_SIZE).
    */

void Painter::selectPen()
{
    p_Color=Qt::black;
    pSize= DEFAULT_SIZE;



}
/*!
   * Set p_Color default color as black.
   * And set pSIze 20.
    */
void Painter::setBrush()
{
    p_Color=Qt::black;
    pSize=20;



}

/*!
  * Return the filename selected by the user using QFileDialog::getSaveFileName().
 * Fill the image2 with color white.
 * initate mImage to address of the variable image2.
 * set the paint device mImage.

    */

void Painter::saveImage(){

mPainter->end();
QString file = QFileDialog::getSaveFileName(this,"Open file ",".png"); //Open Qfile dialog and pass th file name


image2 = QImage(mImage->scaled(mImage->size()));
image2.fill(QColor(Qt::white).rgb());
QPainter painter(&image2);
painter.drawImage(0, 0,mImage->scaled(mImage->size()));
image2.save(file);

mPainter->begin(mImage);


}
/*!
   *Creates a connection of the given type from the signal in the sender object to the method in the receiver object.
   *

    */
void Painter::setupConnectionsPainter(){

connect(ui->SizeEdit,SIGNAL(triggered()),this,SLOT(setSize()));
connect(ui->actionColor,SIGNAL(triggered()),this,SLOT(setColor()));
connect(ui->actionErase,SIGNAL(triggered()),this,SLOT(erase()));
connect(ui->actionEllipse,SIGNAL(triggered()),this,SLOT(openDialogEllipse()));
connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(saveImage()));
connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openFile()));
connect(ui->actionRectangle,SIGNAL(triggered()),this,SLOT(openDialogRect()));
connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(newImage()));
connect(ui->actionAbout_Painter,SIGNAL(triggered()),this,SLOT(aboutPainter()));
connect(ui->actionPen,SIGNAL(triggered()),this,SLOT(selectPen()));
connect(ui->actionBrush,SIGNAL(triggered()),this,SLOT(setBrush()));
}



