#ifndef OUTPUT_H
#define OUTPUT_H
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QVector>
#include<QDebug>
class Output
{
private:
    QVector<QString>ans;
public:
    Output();
    void addans(QString s);
    void writeinfile();
};

#endif // OUTPUT_H
