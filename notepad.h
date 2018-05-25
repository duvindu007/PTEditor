#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QtCore>
#include <QFileDialog>
#include <QtGui>
#include <QMessageBox>
#include<QString>
#include <QtMessageHandler>
#include<QFile>
#include<QTextStream>
#include<QPrinter>
#include<QPrintDialog>
#include<QColor>
#include<QColorDialog>
#include<QFontDialog>
#include<QFont>
#include<QTextCursor>



namespace Ui {
class Notepad;
}
/*!
 * @brief The NotePad class for all the Methods and the varibles of the texteditor.
 */

class Notepad : public QMainWindow
{
    Q_OBJECT



public:
    explicit Notepad(QWidget *parent = 0);
    //! a destructor.
    ~Notepad();
    //! Getter method.
    /*! Getter for the access the private variable filename.
                */
    QString getFilename() const;
    //! Setter.

    /*! setters for the set the private variable filename.
     */
    void setFilename(const QString &value);





private slots:
    /*!
     * @brief zoomIn to the text.
     */
    void zoomIn();
    /*!
     * @brief zoomOut of the text.
     */

    void zoomOut();
    /*!
     * @brief Italic text.
     */
    void Italic();
    /*!
     * @brief Bold text.
     */
    void Bold();
    /*!
     * @brief underLine text.
     */
    void underLine();


   //declare methods
    /*!
     *Method for user to select back ground color of the text edit.
   */
 void setBackgroundcolorEditor();
 /*!
 *print the text file using QPrintDialog.
*/
 void print_text_file();
 /*!
Undo method.

*/
    void actionUndo();
    /*!
  Open new text file
   */
 void openNew();
 /*!
Method redo.

*/
    void actionRedo();
    /*!
  Method cut.
   */
    void actionCut();
    /*!
  Method copy.
   */
    void actionCopy();
    /*!
  Method paste.
   */
    void actionPaste();

    /*!
  Display about.
   */
void about();
/*!
Method open text files.
*/
   void openFile();
   /*!
 Save text files.
  */
   void  saveFile();
   /*!
 Save as.
  */
   void saveAs();
   /*!
 Set color of the text.
  */
    void setColor();
    /*!

    * Highlight the text.
   */
    void changeBackgroundText();
    /*!
  change font of the text.
   */
    void changeFont();
    /*!
Note pad close event
   */
    void closeEvent(QCloseEvent *event);
    /*!
  Check if the note pad is not empty.
   */
    bool checkNotEmpty();
    /*!
     * @brief centered text.
     */
    void centerText();
    /*!
     * @brief push text right side.
     */
    void rightText();
    /*!
     * @brief push text left size.

     */
    void leftText();
    /*!
     * @brief text is aligned to neither the left nor right margin.
     */
    void justifyText();
    /*!
     * @brief Exit text editor.
     */
    void ExitText();

private:

    Ui::Notepad *ui;

     //!   A String variable.
     /*!    We use this when user save and open text files to store the name of the text file.
        */

    QString filename;
    //! QPrinter variable.
    /*! Declare variable printer of type QPrinter.
        */
    QPrinter printer;
    //! QColor varible textColor.
    /*!
      * text color of the text.
      */

QColor textColor;
/*!
  *  backgroundColoreditor for the text edit back ground color.
  */
QColor backgroundColoreditor;
//! Boolean variable approved.
bool approved;
//! Set up connection.
void setupConnections();


};

#endif // NOTEPAD_H
