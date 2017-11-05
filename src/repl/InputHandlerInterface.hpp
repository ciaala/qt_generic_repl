//
// Created by Francesco Fiduccia on 01.11.17.
//

#ifndef QT_GENERIC_REPL_INPUTHANDLERINTERFACE_H
#define QT_GENERIC_REPL_INPUTHANDLERINTERFACE_H

#include <string>

class InputValidation {
public:
    static const InputValidation OK;

    virtual std::string toString() const {
        return "OK";
    }

    bool operator==(const InputValidation &other) const {
        return this->toString() == other.toString();
    }
};

class InputHandlerInterface {
public:

    virtual const InputValidation onInput(std::string input) = 0;

    virtual const std::string onInputResult() const =0;
};

#endif //QT_GENERIC_REPL_INPUTHANDLERINTERFACE_H
