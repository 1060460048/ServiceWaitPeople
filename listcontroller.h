#ifndef LISTCONTROLLER_H
#define LISTCONTROLLER_H

#include <QObject>
#include <QLIST>
class ListController : public QObject
{
    Q_OBJECT
public:
    explicit ListController(QObject *parent = 0);
    ~ListController();
private:
    QList<int> list;


signals:

public slots:

    void processNotBusy(int id);


};

#endif // LISTCONTROLLER_H
