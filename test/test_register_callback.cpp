//
// Created by Francesco Fiduccia on 01.11.17.
//


#include <gtest/gtest.h>
#include "../src/repl/Repl.hpp"
#include "../src/repl/InputHandlerInterface.hpp"

class BaseInputHandler : public InputHandlerInterface {
public:
    InputValidation onInput(std::string input) override {
        return InputValidation::OK;
    }
};

TEST(REPL, REGISTER_INPUT_HANDLER) {
    BaseInputHandler *handler = new BaseInputHandler();
    Repl repl(handler);
    EXPECT_EQ(repl.getInputHandler(), handler);
}