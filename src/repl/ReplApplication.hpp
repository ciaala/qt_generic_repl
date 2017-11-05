//
// Created by Francesco Fiduccia on 04.11.17.
//

#ifndef QT_GENERIC_REPL_REPLAPPLICATION_HPP
#define QT_GENERIC_REPL_REPLAPPLICATION_HPP


#include <QApplication>
#include "ReplWindow.hpp"
#include "InputHandlerInterface.hpp"
#include "Repl.hpp"

class ReplApplication : public QApplication {
private:
    ReplWindow window;
    Repl *repl;

public:
    ReplApplication(int argc, char **argv);

    ReplWindow &getReplWindow();
    void sendInput(std::string input);

    void setInputHandler(InputHandlerInterface *inputHandler);
};


#endif //QT_GENERIC_REPL_REPLAPPLICATION_HPP
