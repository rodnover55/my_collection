#include "fcollection.h"
#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "my_collection");

    // TODO: Hardcoded path
    db.setDatabaseName("/home/rodnover/workspace/Projects/QT/my_collection/db.sqlite");
    db.open();

    FCollection w;
    w.show();
    
    return a.exec();
}
