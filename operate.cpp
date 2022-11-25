#include "operate.h"
#include "ui_operate.h"

operate::operate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::operate)
{
    ui->setupUi(this);
   Init();

}

operate::~operate()
{
    delete ui;
}
void operate::Init()
{
     index=0;
     connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(equalbtn()));
     connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(inequalbtn()));
     connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(unsure()));
     map=new union_find;//并查集

}
void operate::read_addr(QString addr)
{
    QFile file(addr);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"open failed!";
        return;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString str;
        in>>str;
        //qDebug()<<str;
        pair.push_back(str);
    }
    file.close();
    run();
    return;
}
void operate::equalbtn()
{
    if(QMessageBox::question(this,"提示","判断等价成功！",QMessageBox::Yes))
    {
        //点击确定
        QStringList str=pair[index].split(",");
        if(map->find(str[0])!=map->find(str[1]))
        map->merge(str[0],str[1]);//加入并查集
        index++;
        run();
    }
}
void operate::inequalbtn()
{
    if(QMessageBox::question(this,"提示","判断不等价成功！",QMessageBox::Yes))
    {
        //点击确定
        index++;
        run();
    }
}
void operate::unsure()
{
    if(QMessageBox::question(this,"提示","判断成功！",QMessageBox::Yes))
    {
        //点击确定
        index++;
        run();
    }
}
void operate::run()
{
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    if(index>=pair.size())
    {
        if(QMessageBox::question(this,"提示","所有程序对判断完成！",QMessageBox::Yes))
        {
            //点击确定
            this->hide();

        }
    }
    QStringList str=pair[index].split(",");
    while(map->find(str[0])==map->find(str[1]))//在同一并查集内
    {
        qDebug()<<"jump to next";

        index++;
        str=pair[index].split(",");
    }
    QFile p1(str[0]);
    QFile p2(str[1]);
    if(!p1.open(QIODevice::ReadOnly | QIODevice::Text)||!p2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"open failed!";
        return;
    }
    QTextStream in1(&p1);
    QTextStream in2(&p2);
    while(!in1.atEnd())
    {     QString msg;
          QString s;
          in1>>s;
          //qDebug()<<s;
          msg.append(s);
          ui->textEdit->append(msg);
    }
    while(!in2.atEnd())
    {
        QString msg;
        QString s;
        in2>>s;
        //qDebug()<<s;
        msg.append(s);
        ui->textEdit_2->append(msg);
    }
    p1.close();
    p2.close();

    return;
}
