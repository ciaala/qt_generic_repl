//
// Created by Francesco Fiduccia on 01.11.17.
//

#ifndef QT_GENERIC_REPL_REPL_H
#define QT_GENERIC_REPL_REPL_H

#include <string>
#include "InputHandlerInterface.hpp"
#include "OutputHandlerInterface.hpp"

class Repl {

public:
    Repl(InputHandlerInterface *inputHandler,
                  OutputHandlerInterface *outputHandler);

    InputHandlerInterface *getInputHandler() const;

    void consume_input(std::string input);
    const std::string getOutputText() const;

private:
    InputHandlerInterface *inputHandler;
    OutputHandlerInterface *outputHandler;

};


#endif //QT_GENERIC_REPL_REPL_H
