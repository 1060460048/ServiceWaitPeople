#include "listcontroller.h"
#include <QDebug>
ListController::ListController(QObject *parent) : QObject(parent)
{
    for (int var = 0; var < 100; ++var) {
        list.push_back (var);
    }
    qDebug()<<"init 100 person list finished...";

}

ListController::~ListController()
{

}

void ListController::processNotBusy(int id)
{
    if(list.empty ()){
        qDebug()<<"today'work is over now  ,every body could go home now!!!";
        return;
    }
    int client =list.first ();
    qDebug()<<"client:"<<client <<"plea come to the :"<<id <<"server you";
    list.removeFirst ();
}

