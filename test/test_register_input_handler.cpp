//
// Created by Francesco Fiduccia on 01.11.17.
//


#include <gtest/gtest.h>
#include "../src/repl/Repl.hpp"
#include "EchoLastInput.hpp"
class BaseOutputHandler : public OutputHandlerInterface {
private:
    std::string lastMessage ;
public:
    const std::string getOutputText() const override {
        return lastMessage;
    }

    void message(const char *string) override {
        lastMessage = string;
    }

    void errorMessage(const char *string) override {
        lastMessage = string;
    }
};

TEST(REPL, REGISTER_INPUT_HANDLER) {
    EchoLastInput inputHandler;
    BaseOutputHandler outputHandler;
    Repl repl(&inputHandler, &outputHandler);
    EXPECT_EQ(repl.getInputHandler(), &inputHandler);
}


TEST(REPL, INPUT_HANDLER_RECEIVE) {
    EchoLastInput inputHandler;
    BaseOutputHandler outputHandler;
    Repl repl(&inputHandler, &outputHandler);
    repl.consume_input("TEXT_MESSAGE");
    EXPECT_EQ( inputHandler.getLastInput(), "TEXT_MESSAGE" );
}

TEST(REPL, INPUT_HANDLER_RESPONSE_IS_SHOWN) {
    EchoLastInput inputHandler;
    BaseOutputHandler outputHandler;
    Repl repl(&inputHandler, &outputHandler);

    repl.consume_input("Ada");
    std::string response = repl.getOutputText();
    EXPECT_EQ(std::string("Ada"), response);
}

