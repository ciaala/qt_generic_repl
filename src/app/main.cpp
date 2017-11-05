#include <iostream>
#include <QApplication>
#include "../repl/Repl.hpp"
#include "../repl/ReplWindow.hpp"
#include "../repl/ReplApplication.hpp"
#include "../../test/EchoLastInput.hpp"

int main(int argc, char **argv) {
    std::cout << "Hello, World!" << std::endl;

    ReplApplication app(argc, argv);
    app.getReplWindow().show();
    EchoLastInput input;
    app.setInputHandler(&input);
    return app.exec();
}