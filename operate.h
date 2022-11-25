#ifndef OPERATE_H
#define OPERATE_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QFile>
#include <QDebug>
#include<QTextStream>
#include <QStringList>
#include <QPushButton>
#include <QMessageBox>

#include "union_find.h"
namespace Ui {
class operate;
}

class operate : public QMainWindow
{
    Q_OBJECT

public:
    explicit operate(QWidget *parent = nullptr);
    ~operate();
    void read_addr(QString addr);
private slots:
    void equalbtn();
    void inequalbtn();
    void unsure();

private:
    Ui::operate *ui;
    QVector<QString>pair;
    int index;
    union_find* map;
    void run();
    void Init();
};

#endif // OPERATE_H
