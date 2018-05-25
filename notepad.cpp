#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{

 /*!
  *Set native menu bar false so in some OS like Ubantu the Menu bar would show.

  */
    ui->setupUi(this);
    menuBar()->setNativeMenuBar(false);
    setupConnections();
     this->setCentralWidget(ui->textEdit);



}

/*!
 * check if the file is empty if not aske the user if they want to save it or not.
   call openNew method.
*/
void Notepad::closeEvent(QCloseEvent *event){

   ExitText();


    event->accept();

}

Notepad::~Notepad()
{
    delete ui;
}
/*!
 * @brief Notepad::getFilename.
 * @return filename.
 * Getter method of the private variable filename.
 */
QString Notepad::getFilename() const
{
    return filename;
}
/*!
 * @brief Notepad::setFilename
 * @param value
 * Setter method of the private variable filename.
 */
void Notepad::setFilename(const QString &value)
{
    filename = value;
}
/*!
 * @brief Notepad::zoomIn
 * Zoom in method using textEdit->zoomIn().
 */
void Notepad::zoomIn()
{
    ui->textEdit->zoomIn(5);
}
/*!
 * @brief Notepad::zoomOut
 * Zoom Out method using textEdit->zoomOut().
 */
void Notepad::zoomOut()
{
    ui->textEdit->zoomOut(5);
}
/*!
 * @brief Notepad::Italic
 * Italic method using setFontItalic().
 */
void Notepad::Italic()
{
    ui->textEdit->setFontItalic(true);

}
/*!
 * @brief Notepad::Bold
 * Text bold using setFontWeight().
 */
void Notepad::Bold()
{
    ui->textEdit->setFontWeight(QFont::Bold);
}
/*!
 * @brief Notepad::underLine
 * Under line the text using setFontUnderline().
 */
void Notepad::underLine()
{
     ui->textEdit->setFontUnderline(true);
}
/*!
 * @brief Notepad::print_text_file
 * Print current textfile.
 */
void Notepad::print_text_file(){

  printer.setPrinterName("printer name");
QPrintDialog dialalog (&printer,this);
if(dialalog.exec()==QDialog::Rejected) return;
ui->textEdit->print(&printer);

}

/*!
 * @brief Notepad::checkNotEmpty
 * @return
 * Check if the textedit is not empty.
 * By converting textedit values to plain text and assign it to QString type variable and check if the
       value equal to "". If str not equal to "" then return true.

 */

bool Notepad::checkNotEmpty(){



  QString str = ui->textEdit->toPlainText();

        if(str!=""){
    return true;


    }


        return false;
}

/*!
 * @brief Notepad::openNew
 * Check if the checkNotEmpty() method return true if it is then ask the user if user want to save the work user did.
 * it it is then call the  saveAs() method and save the file then assign filename and chenge text edit text to "".
 *   If user reply as NO then assign filename and chenge text edit text to "".
 */
void Notepad:: openNew(){

if( checkNotEmpty()==true){

QMessageBox::StandardButton reply = QMessageBox::question(this,"Warning","Do you want to save this file",QMessageBox::Ok | QMessageBox::No);


if(reply==QMessageBox::Ok){

    saveAs();
filename="";
ui->textEdit->setPlainText("");


}
else if(reply==QMessageBox::No){
    filename="";
    ui->textEdit->setPlainText("");

}

    else{

    filename ="";
   ui->textEdit->setPlainText("");}
}
}
/*!
 * @brief Notepad::openFile.
 * Call openNew() to check and ask user to save the current file or not.
 * Assign file name to QString type variable and check if it is not empty.
 * Use QTextStream class to read the text sFile.
 * Use readAll() method to return the stream as QString.
 * Changes the text of the text edit to the string text.
 */
void Notepad::openFile(){

    openNew();


    QString file = QFileDialog::getOpenFileName(this,"Open file");
    if(!file.isEmpty()){

        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text)){
            filename = file;
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();
            ui->textEdit->setPlainText(text);
        }
else {
            QMessageBox::warning(this,"...","file not open");
            return;


        }

    }


}
/*!
 * @brief Notepad::changeFont.
 * Declare QFont type variable font and get the font using QFontDialog and assign it to the variable.
 *  If the font is approved SetFont().
 */
void Notepad::changeFont(){


    QFont font = QFontDialog::getFont(&approved,this);
    if(approved){

        ui->textEdit->setFont(font);

    }



}
/*!
 * @brief Notepad::saveFile.
 * Declare QFile type variable sFile and check if the fileaname is null or not.
 * if the file name is null then call the saveAs() method.
 */
void Notepad::saveFile(){

    QFile sFile(filename);
    if(filename!=nullptr){
       if(sFile.open(QFile::WriteOnly| QFile::Text)){

           QTextStream out(&sFile);
           out<<ui->textEdit->toPlainText();
           sFile.flush();
           sFile.close();

       }

}
    else{
        saveAs();

    }
}
/*!
 * @brief Notepad::changeBackgroundText.
 * Assign textColor variable to the color that user select from the QColorDialog.
 * default color is set to black.
 * if the color is valid color then set the background color of the text to selected color.
 */
void Notepad::changeBackgroundText(){
    textColor=QColorDialog::getColor(Qt::black,this,"Select any color");
    if(textColor.isValid()){
        ui->textEdit->setTextBackgroundColor(textColor);

    }

}

/**
 * @brief Notepad::saveAs
 *
 */
void Notepad::saveAs(){

    QString file = QFileDialog::getSaveFileName(this,"Open file ",".txt");
    //check the file
    if(!file.isEmpty()){

        filename= file;

   saveFile();

    }


}
/**
 * @brief Notepad::setColor
 * Assign textColor variable to the color that user select from the QColorDialog.
 * default color is set to black.
 * If the color is valid color then setTextColor of the text to selected color.
 */
void Notepad::setColor(){

    textColor=QColorDialog::getColor(Qt::black,this,"Select any color");
    if(textColor.isValid()){
        ui->textEdit->setTextColor(textColor);


    }


}
/*!
 * @brief The QPalette class contains color groups for each widget state.
 * Assign a palette.
 *Check if the color selected by the user is valid.
 */

void Notepad::setBackgroundcolorEditor(){

    QPalette pal = ui->textEdit->palette();

    backgroundColoreditor=QColorDialog::getColor(Qt::white,this,"Select any color");
    if(backgroundColoreditor.isValid()){
        pal.setColor(QPalette::Base,backgroundColoreditor);


             ui->textEdit->setPalette(pal);
    }



}

/*!
  *QTextEdit method undo(). Used to undo() the last action.

*/
void Notepad::actionUndo()
{

   ui->textEdit->undo();
}
/*!
      *QTextEdit method redo(). Used to Redo the last operation.

*/
void Notepad::actionRedo()
{
     ui->textEdit->redo();
}
/*!
      *QTextEdit method cut(). Used to copies the selected text to the clipboard and deletes it from the text edit.

*/
void Notepad::actionCut()
{
    ui->textEdit->cut();
}
/*!
      *QTextEdit method copy(). Used to copies any selected text to the clipboard.

*/
void Notepad::actionCopy()
{
      ui->textEdit->copy();
}
/*!
  *QTextEdit method paste(). Used to pastes the text from the clipboard into the text edit at the current cursor position.

*/
void Notepad::actionPaste()
{
    ui->textEdit->paste();
}

/*!
     *QMessageBox used to dispaly about the Notepad.

*/
void Notepad::about()
{

    QMessageBox::about(this,"About text editor","Author : Duvindu\n Date : 17/12/2017\n Name: Notepad\n");
}
/*!
 * @brief Notepad::setupConnections.
 * Creates a connection of the given type from the signal in the sender object to the method in the receiver object.
 * connect.
 */
void Notepad::setupConnections(){

connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(openNew()));
connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openFile()));
connect(ui->actionsave,SIGNAL(triggered()),this,SLOT(saveFile()));
connect(ui->actionCopy,SIGNAL(triggered()),this,SLOT(actionCopy()));
connect(ui->actionCut,SIGNAL(triggered()),this,SLOT(actionCut()));
connect(ui->actionPaste,SIGNAL(triggered()),this,SLOT(actionPaste()));
connect(ui->actionSave_As,SIGNAL(triggered()),this,SLOT(saveAs()));
connect(ui->actionRedo,SIGNAL(triggered()),this,SLOT(actionRedo()));
connect(ui->actionUndo,SIGNAL(triggered()),this,SLOT(actionUndo()));
connect(ui->actionPrint,SIGNAL(triggered()),this,SLOT(print_text_file()));
connect(ui->actionColor,SIGNAL(triggered()),this,SLOT(setColor()));
connect(ui->actionBackground_Color,SIGNAL(triggered()),this,SLOT(changeBackgroundText()));
connect(ui->actionBackground_Color_Editor,SIGNAL(triggered()),this,SLOT(setBackgroundcolorEditor()));
connect(ui->actionFont,SIGNAL(triggered()),this,SLOT(changeFont()));
connect(ui->actionAbout_Notepad,SIGNAL(triggered()),this,SLOT(about()));
connect(ui->actionZoom_in,SIGNAL(triggered()),this,SLOT(zoomIn()));
connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(ExitText()));
connect(ui->actionBold,SIGNAL(triggered()),this,SLOT(Bold()));
connect(ui->actionCenter,SIGNAL(triggered()),this,SLOT(centerText()));
connect(ui->actionItalic,SIGNAL(triggered()),this,SLOT(Italic()));
connect(ui->actionJustify,SIGNAL(triggered()),this,SLOT(justifyText()));
connect(ui->actionZoom_out,SIGNAL(triggered()),this,SLOT(zoomOut()));
connect(ui->actionLeft,SIGNAL(triggered()),this,SLOT(leftText()));
connect(ui->actionRight,SIGNAL(triggered()),this,SLOT(rightText()));
connect(ui->actionUnder_line,SIGNAL(triggered(bool)),this,SLOT(underLine()));
}


/*!
 * @brief Notepad::centerText .
 * allocate text in the textEdit to center.
 */

void Notepad::centerText()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}
/*!
 * @brief Notepad::rightText .
 *  allocate text in the textEdit to right side.
 */
void Notepad::rightText()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}
/*!
 * @brief Notepad::leftText .
 *  allocate text in the textEdit to rleft side.

*/
void Notepad::leftText()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}
/*!
 * @brief Notepad::justifyText .
 *
 */
void Notepad::justifyText()
{
    ui->textEdit->setAlignment(Qt::AlignJustify);
}
/*!
 * @brief Notepad::ExitText .
 * Exit text editor make sure user want to save the text.
 */
void Notepad::ExitText()
{

    checkNotEmpty();

    if(checkNotEmpty()==true){
    QMessageBox::StandardButton reply=  QMessageBox::question(this,"Warning","Do you want to save this file",QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes){

        saveAs();
       Notepad::close();


    }
    else{
       ui->textEdit->close();
     Notepad::close();

    }


    }
    else{
    ui->textEdit->close();
    Notepad::close();
    }



}
