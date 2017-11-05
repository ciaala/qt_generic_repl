//
// Created by Francesco Fiduccia on 01.11.17.
//

#include "Repl.hpp"
#include <sstream>

Repl::Repl(InputHandlerInterface *inputHandler,
           OutputHandlerInterface *outputHandler) {
    this->inputHandler = inputHandler;
    this->outputHandler = outputHandler;
}

InputHandlerInterface *Repl::getInputHandler() const {
    return inputHandler;
}

void Repl::consume_input(const std::string input) {
    const InputValidation &validation = this->inputHandler->onInput(input);
    if (InputValidation::OK == validation) {
        outputHandler->message(this->inputHandler->onInputResult().c_str());
    } else {
        char buf[4096];
        int length = std::snprintf(buf, 4096, "Unable to parse the input: '%s'", input.c_str());
        outputHandler->errorMessage(buf);

    }
}

const std::string Repl::getOutputText() const {
    return outputHandler->getOutputText();
}
