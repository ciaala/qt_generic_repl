//
// Created by Francesco Fiduccia on 01.11.17.
//

#ifndef QT_GENERIC_REPL_REPL_H
#define QT_GENERIC_REPL_REPL_H


#include "InputHandlerInterface.hpp"

class Repl {
public:
    explicit Repl(InputHandlerInterface *pHandler);

    InputHandlerInterface *getInputHandler();

private:
    InputHandlerInterface *pHandler;
};


#endif //QT_GENERIC_REPL_REPL_H
