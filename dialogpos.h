#ifndef DIALOGPOS_H
#define DIALOGPOS_H

#include <QDialog>

namespace Ui {
class DialogPos;
}

//! DialogPos class.
/*!
 * Here we have the methods and variables of DialogPos class.
 * @brief The DialogPos class for storing the variables and providing the values of the varible to the Painter class for Ellipse and Rectangel.
 */

class DialogPos : public QDialog
{


    Q_OBJECT

public:
    explicit DialogPos(QWidget *parent = 0);


    ~DialogPos();
//getters and setters

    /*!
         *Getters to access the private variable left.
         */
    int getLeft() const;
    /*!
         *Setters to set the varible left.
         */
    void setLeft(int value);
    /*!

         *Getters to access the private variable top.
         */
    int getTop() const;
    /*!
         *Setters to set the varible top.

         */
    void setTop(int value);
    /*!

         *Getters to access the private variable width.
         */
    int getWidth() const;
    /*!
         *Setters to set the varible width.

         */
    void setWidth(int value);
    /*!

         *Getters to access the private variable height.
         */
    int getHeight() const;
    /*!
        * Setters to set the varible height.

         */
    void setHeight(int value);

    void closeEvent(QCloseEvent * e) override;
public slots:

    /*!
         *method for when user rejected(cancel).
         */

  void on_Cancel_clicked();
  /*!
      *method when user accepted.
       */

  void on__ok_clicked();

protected:

protected slots:

private slots:


private:
     /**
       *@param left,top,width,height are variables that used to set by the user to draw shapes.
       */

     //! A int variable.
     /*!
      We use this when we need to draw ellipse and rectangle.
     */
    int left;
    //! A int variable.

    /*!     We use this when we need to draw ellipse and rectangle.
        */
    int top;
   //! A int variable.

         /*! We use this when we need to draw ellipse and rectangle.
        */
    int width;

      //!    A int variable.
     /*! We use this when we need to draw ellipse and rectangle.
        */
    int height;

    Ui::DialogPos *ui;

};

#endif // DIALOGPOS_H
