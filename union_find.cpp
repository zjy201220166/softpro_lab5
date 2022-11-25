#include "union_find.h"
#include<QDebug>
union_find::union_find()
{
umap.clear();
}
QString union_find::find(QString name) {
        if (umap.count(name) == 0)//如果umap中没有这个键值对，要添加进去。
            return umap[name] = name;

        if (umap[name] != name) {
            umap[name] = find(umap[name]);
        }
        return umap[name];
    }
    //合并两个节点
    void union_find::merge(QString name1, QString name2) {
        QString rootname1 = find(name1), rootname2 = find(name2);
        if (rootname1 < rootname2)umap[rootname2] = rootname1;
        else umap[rootname1] = umap[rootname2];
    }
