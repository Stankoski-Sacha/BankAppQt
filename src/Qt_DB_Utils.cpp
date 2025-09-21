#include "../include/pch.hpp"
#include "../include/Qt_DB_Utils.hpp"
#include <sodium.h>

DataBaseUtils::DataBaseUtils(QSqlDatabase db) : db(db) {
     std::cout << "DB Class Created!" << std::endl;
     initSodium();
}

DataBaseUtils::~DataBaseUtils() {
     db.close();
     std::cout << "DB Class Destroyed!" << std::endl;
}

void DataBaseUtils::openDB() {
     DBConfig cfg = loadConfig();

     std::cout << "Opening DB..." << std::endl;
     db.setHostName(cfg.host);
     db.setPort(cfg.port);
     db.setDatabaseName(cfg.name);
     db.setUserName(cfg.user);
     db.setPassword(cfg.pass);

     if (!db.open()) {
          std::cerr << "Error connecting to DB" << std::endl;
          exit(1);
     }

     std::cout << "Connected to DB" << std::endl;
}

void DataBaseUtils::addCustomerToDB(QString& name, QString& email, QString& passwd) {
     QSqlQuery query;

     // Security protocol
     QString hashedPasswd = hashPassword(passwd);

     // Add customer to customer table in DB
     query.prepare("INSERT INTO customer (name, email, passwd) VALUES (:name, :email, :passwd)");
     query.bindValue(":name", name);
     query.bindValue(":email", email);
     query.bindValue(":passwd", hashedPasswd);

     if (!query.exec()) {
          std::cerr << "Error adding customer to DB" << std::endl;
          return;
     } else {
          std::cout << "Customer added to DB" << std::endl;
          int customer_id = getCustomerID(email);

          query.prepare("INSERT INTO account (customer_id, balance) VALUES (:customer_id, :balance)");
          query.bindValue(":customer_id", customer_id);
          query.bindValue(":balance", 0);
          if (!query.exec()) {
               std::cerr << "Error adding account to DB" << std::endl;
               return;
          } else {
               std::cout << "Account added to DB" << std::endl;
          }
     }

     getCustomerID(email);
}

void DataBaseUtils::addTransactionToDB() {

}

void DataBaseUtils::initSodium() {
     if (sodium_init() < 0) {
          qDebug() << "Failed to initialize libsodium";
          throw std::runtime_error("Libsodium initialization failed");
     }
}

QString DataBaseUtils::hashPassword(const QString& passwd) {
     // Convert to string
     std::string strpass = passwd.toStdString();

     char hashed [crypto_pwhash_STRBYTES];

     if (crypto_pwhash_str(
          hashed,
          strpass.c_str(),
          strpass.length(),
          crypto_pwhash_OPSLIMIT_MODERATE,
          crypto_pwhash_MEMLIMIT_MODERATE
     ) != 0) {
          std::cerr << "Error hashing password" << std::endl;
          return QString();
     }

     return QString(hashed);
}

int DataBaseUtils::getCustomerID(QString &email) {
     QSqlQuery query;
     int id = -1;  // default if not found

     query.prepare("SELECT id FROM customer WHERE email = :email");
     query.bindValue(":email", email);

     if (!query.exec()) {
          std::cerr << "Error getting customer ID: "
                    << query.lastError().text().toStdString() << std::endl;
          return -1;
     }

     if (query.next()) {  // move to the first row
          id = query.value(0).toInt();
     } else {
          std::cerr << "No customer found with email " << email.toStdString() << std::endl;
     }

     return id;
}


