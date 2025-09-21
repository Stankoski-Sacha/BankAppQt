#include "../include/pch.hpp"
#include "../include/Qt_DB_Utils.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    DataBaseUtils dbUtils(db);

    dbUtils.openDB();

    QSqlQuery query;
    query.exec("DELETE FROM customer");
    query.exec("DELETE FROM account");

    QString name = "John";
    QString email = "John@John.com";
    QString passwd = "SuperStronk69420@";

    dbUtils.addCustomerToDB(name, email, passwd);



    auto window = std::make_unique<QMainWindow>();
    window->setWindowTitle("Welcome");
    window->resize(500, 700);

    // Menu bar (parented to the window)
    auto bar = std::make_unique<QMenuBar>(window.get());

    // Add a menu to the bar -> returns a QMenu*
    QMenu* fileMenu = bar->addMenu(QObject::tr("&File"));

    // Add an action directly
    QAction* openAction = fileMenu->addAction(QObject::tr("&Open"));

    QObject::connect(openAction, &QAction::triggered, []() {
        QMessageBox::information(nullptr, "Open", "Open");
    });

    window->setMenuBar(bar.get());
    window->show();

    return QApplication::exec();
}

