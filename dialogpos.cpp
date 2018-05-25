#include "dialogpos.h"
#include "ui_dialogpos.h"
#include"painter.h"

DialogPos::DialogPos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPos)
{
    ui->setupUi(this);

/*!
 * set max values for the spin boxes
 */
ui->spinBox_Height->setMaximum(800);
ui->spinBox_Left->setMaximum(800);
ui->spinBox_Top->setMaximum(800);
ui->spinBox_width->setMaximum(800);
ui->spinBox_Top->setMinimum(80);

}
/*!
 * \brief DialogPos::getHeight
 * \return height
 *
 */
int DialogPos::getHeight() const
{
    return height;


}
/*!
 * \brief DialogPos::setHeight
 * \param value
 */
void DialogPos::setHeight(int value)
{
    height = value;
}
/*!
 * \brief DialogPos::getWidth
 * \return width
 */
int DialogPos::getWidth() const
{
    return width;
}
/*!
 * \brief DialogPos::setWidth
 * \param value
 */
void DialogPos::setWidth(int value)
{
    width = value;
}
/*!
 * \brief DialogPos::getTop
 * \return
 */
int DialogPos::getTop() const
{
    return top;
}
/*!
 * \brief DialogPos::setTop
 * \param value
 */
void DialogPos::setTop(int value)
{
    top = value;
}
/*!
 * \brief DialogPos::getLeft
 * \return
 */
int DialogPos::getLeft() const
{
    return left;
}
/*!
 * \brief DialogPos::setLeft
 * \param value
 */
void DialogPos::setLeft(int value)
{
    left = value;
}
/*!
 * \brief DialogPos::~DialogPos
 *  destructor.
 */
DialogPos::~DialogPos()
{
    delete ui;
}
/*!
 * @brief DialogPos::on__ok_clicked
 * set left,top,width,height variables.
 */
void DialogPos::on__ok_clicked()
{
    setLeft(ui->spinBox_Left->value());
    setTop(ui->spinBox_Top->value());
    setWidth(ui->spinBox_width->value());
    setHeight(ui->spinBox_Height->value());
    close();

}
/**
 * @brief DialogPos::on_Cancel_clicked
 */
void DialogPos::on_Cancel_clicked()
{  ui->spinBox_Left->setValue(0);
    ui->spinBox_Height->setValue(0);
    ui->spinBox_Top->setValue(0);
    ui->spinBox_width->setValue(0);
    close();
}
void DialogPos::closeEvent(QCloseEvent *e){


e->accept();

}

