#include <QtCore/QCoreApplication>
#include <QtCore/QtDebug>

#include "task.hpp"

bool find () {
    static int i = 0;
    static bool ok = false;
    if (i >= 5) {
        ok = true;
    }
    qDebug() << i << ok;
    ++i;
    return ok;
}

void click () {
    qDebug() << "click";
}

int main (int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Task * b = new Task([](const Task::Yield & yield)->void {
        bool ok = find();
        while (!ok) {
            // yield for 1000 ms
            yield(1000);
            ok = find();
        }
        click();
    });
    b->connect(b, SIGNAL(finished()), SLOT(deleteLater()));
    QCoreApplication::instance()->connect(b, SIGNAL(finished()), SLOT(quit()));
    b->start();

    return a.exec();
}