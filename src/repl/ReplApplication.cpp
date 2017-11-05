//
// Created by Francesco Fiduccia on 04.11.17.
//

#include "ReplApplication.hpp"
#include "ReplWindow.hpp"

ReplApplication::ReplApplication(int argc, char **argv) :
        QApplication(argc, argv),
        window("Hello, world"),
        repl(nullptr) {
}

ReplWindow &ReplApplication::getReplWindow() {
    return window;
}

void ReplApplication::sendInput(const std::string input) {
    for (char c : input) {
        QKeyEvent press(QEvent::Type::KeyRelease, (int) c, Qt::KeyboardModifier::NoModifier);

        QKeyEvent release(QEvent::Type::KeyRelease, (int) c, Qt::KeyboardModifier::NoModifier);
        this->sendEvent(this->window.getInput(), &press);
        this->sendEvent(this->window.getInput(), &release);
    }
}

void ReplApplication::setInputHandler(InputHandlerInterface *inputHandler) {
    this->repl = new Repl(inputHandler, &(this->window));
    this->window.setRepl(repl);
}
