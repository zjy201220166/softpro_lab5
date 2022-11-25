#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operate.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Init()
{

    ui->lineEdit->setPlaceholderText("请输入程序等价对文件地址...");
    ui->lineEdit->setClearButtonEnabled(true);
connect(ui->pushButton,&QPushButton::clicked,[=](){

                operate *page=new operate(this);
                page->setFixedSize(800,600);
                page->setWindowTitle("confirmation");
                QString addr=ui->lineEdit->text();
                page->read_addr(addr);
                page->show();
                //this->hide();//当前页面隐藏
});
}
