//
// Created by Francesco Fiduccia on 04.11.17.
//

#ifndef QT_GENERIC_REPL_ECHOLASTINPUT_HPP
#define QT_GENERIC_REPL_ECHOLASTINPUT_HPP

class EchoLastInput : public InputHandlerInterface {
    std::__1::string last_input;
public:
    const InputValidation onInput(std::__1::string input) override {
        this->last_input = input;
        return InputValidation::OK;
    }

    const std::__1::string onInputResult() const override {
        return last_input;
    }

    std::__1::string getLastInput() {
        return last_input;
    }
};

#endif //QT_GENERIC_REPL_ECHOLASTINPUT_HPP
