#ifndef UNION_FIND_H
#define UNION_FIND_H
#include <QString>
#include <iostream>
#include<QMap>
using namespace std;

class union_find
{
private:
    QMap<QString, QString> umap;
public:
    union_find();
    QString find(QString name);
    void merge(QString name1, QString name2);

};

#endif // UNION_FIND_H
