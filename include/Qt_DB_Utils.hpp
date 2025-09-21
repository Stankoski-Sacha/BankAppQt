#ifndef BANKAPPQT_QT_DB_UTILS_HPP
#define BANKAPPQT_QT_DB_UTILS_HPP

#include "pch.hpp"

class DataBaseUtils {
private:
    QSqlDatabase db;
    void initSodium();
    enum class TransactionType {
        deposit,
        withdrawal,
        transfer
    };

public:
    // Constructor and out
    DataBaseUtils(QSqlDatabase db);
    ~DataBaseUtils();

    // DB utils
    void openDB();
    void addCustomerToDB(QString& name, QString& email, QString& passwd);
    void addTransactionToDB();

    // Hash passwd
    QString hashPassword(const QString& passwd);
    int getCustomerID(QString& email);
};

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

struct DBConfig {
    QString host;
    int port;
    QString name;
    QString user;
    QString pass;
};

inline DBConfig loadConfig(const QString& path = "../config.json") {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open config file:" << path;
        return {};
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) {
        qWarning() << "Invalid JSON in config file";
        return {};
    }

    QJsonObject obj = doc.object();
    DBConfig cfg;
    cfg.host = obj.value("DB_HOST").toString();
    cfg.port = obj.value("DB_PORT").toInt();
    cfg.name = obj.value("DB_NAME").toString();
    cfg.user = obj.value("DB_USER").toString();
    cfg.pass = obj.value("DB_PASS").toString();
    return cfg;
}



#endif //BANKAPPQT_QT_DB_UTILS_HPP