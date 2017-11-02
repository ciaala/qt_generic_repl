#include <iostream>
#include <QApplication>
#include "../repl/Repl.hpp"
#include "../repl/ReplWindow.hpp"

int main(int argc, char **argv) {
    std::cout << "Hello, World!" << std::endl;


    QApplication app(argc, argv);
    ReplWindow window("Hello, world");
    window.show();
    app.exec();
    return 0;
}