//
// Created by Francesco Fiduccia on 01.11.17.
//

#include "Repl.hpp"

Repl::Repl(InputHandlerInterface *pHandler) {
    this->pHandler = pHandler;
}

InputHandlerInterface *Repl::getInputHandler() {
    return pHandler;
}
