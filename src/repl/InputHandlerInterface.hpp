//
// Created by Francesco Fiduccia on 01.11.17.
//

#ifndef QT_GENERIC_REPL_INPUTHANDLERINTERFACE_H
#define QT_GENERIC_REPL_INPUTHANDLERINTERFACE_H

#include <string>

class InputValidation {
public:
    static InputValidation OK;
    virtual std::string toString() {
        return "OK";
    }

};

class InputHandlerInterface {
public:
    virtual InputValidation onInput(std::string input) = 0;
};

#endif //QT_GENERIC_REPL_INPUTHANDLERINTERFACE_H
