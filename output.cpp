#include "output.h"

Output::Output()
{
ans.clear();
}
void Output::addans(QString s)
{
    ans.push_back(s);
}
void Output::writeinfile()
{
    QFile file("output_equal.csv");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug()<<"write open failed!";
        return;
    }
    QTextStream out(&file);
    for(int i=0;i<ans.size();i++)
    {
        out<<ans[i]<<endl;
    }
    file.close();
    return;


}
