#include <QApplication>
#include <memory>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Window
    auto window = std::make_unique<QWidget>();
    window->setWindowTitle("Hello World");

    // Buttons
    auto button = std::make_unique<QPushButton>("Hello World");
    auto button2 = std::make_unique<QPushButton>("Hello World2");
    auto button3 = std::make_unique<QPushButton>("Hello World3");
    auto button4 = std::make_unique<QPushButton>("Hello World4");
    auto button5 = std::make_unique<QPushButton>("Hello World5");

    auto edit = std::make_unique<QLineEdit>("Edit");
    auto edit2 = std::make_unique<QLineEdit>("Edit2");
    auto edit3 = std::make_unique<QLineEdit>("Edit3");
    auto edit4 = std::make_unique<QLineEdit>("Edit4");
    auto edit5 = std::make_unique<QLineEdit>("Edit5");


    // Layout
    auto layout = new QFormLayout(window.get());

    // Add buttons to window
    layout->addRow(button.get(), edit.get());
    layout->addRow(button2.get(), edit2.get());
    layout->addRow(button3.get(), edit3.get());
    layout->addRow(button4.get(), edit4.get());
    layout->addRow(button5.get(), edit5.get());

    // Show the window
    window->show();

    // Delete the pointer
    delete layout;

    return QApplication::exec();
}
