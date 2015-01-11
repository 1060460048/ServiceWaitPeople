#include <QCoreApplication>
#include <QList>
#include <QDebug>

#include <iostream>

#include "worker.h"
#include "listcontroller.h"
using namespace std ;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   ListController *controller;

   controller =new ListController();

    QThread *thread;
    thread =new QThread();
    Worker *worker;
    worker = new Worker();
    worker->setId (11);


    QThread *thread2;
    thread2 =new QThread();
    Worker *worker2;
    worker2 = new Worker();
    worker2->setId (22);


    QThread *thread3;
    thread3 =new QThread();
    Worker *worker3;
    worker3 = new Worker();
    worker3->setId (33);

    worker->moveToThread(thread);
    QObject::connect(worker, SIGNAL(workRequested()), thread, SLOT(start()));
    QObject::connect(thread, SIGNAL(started()), worker, SLOT(doWork()));
    QObject::connect(worker, SIGNAL(finished()), thread, SLOT(quit()), Qt::DirectConnection);
    QObject::connect (worker,SIGNAL(notbusy(int)),controller,SLOT(processNotBusy(int)));



    worker2->moveToThread(thread2);
    QObject::connect(worker2, SIGNAL(workRequested()), thread2, SLOT(start()));
    QObject::connect(thread2, SIGNAL(started()), worker2, SLOT(doWork()));
    QObject::connect(worker2, SIGNAL(finished()), thread2, SLOT(quit()), Qt::DirectConnection);
    QObject::connect (worker2,SIGNAL(notbusy(int)),controller,SLOT(processNotBusy(int)));

    worker3->moveToThread(thread3);
    QObject::connect(worker3, SIGNAL(workRequested()), thread3, SLOT(start()));
    QObject::connect(thread3, SIGNAL(started()), worker3, SLOT(doWork()));
    QObject::connect(worker3, SIGNAL(finished()), thread3, SLOT(quit()), Qt::DirectConnection);
    QObject::connect (worker3,SIGNAL(notbusy(int)),controller,SLOT(processNotBusy(int)));



    worker->abort();
    thread->wait(); // If the thread is not running, this will immediately return.
    worker->requestWork();

    worker2->abort();
    thread2->wait(); // If the thread is not running, this will immediately return.
    worker2->requestWork();


    worker3->abort();
    thread3->wait(); // If the thread is not running, this will immediately return.
    worker3->requestWork();

//    qDebug()<<"in the main thread...";




    return a.exec();
}
