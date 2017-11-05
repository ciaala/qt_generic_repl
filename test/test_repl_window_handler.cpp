//
// Created by Francesco Fiduccia on 04.11.17.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/repl/ReplWindow.hpp"
#include "../src/repl/ReplApplication.hpp"
#include "EchoLastInput.hpp"
using namespace testing;
void microWait(int micro) {
    QThread::currentThread()->msleep(micro);
}
template <class T=void> struct FlushEvents {
    FlushEvents() {
        int n = 0;
        while(++n<20 &&  qApp->hasPendingEvents() ) {
            QApplication::sendPostedEvents();
            QApplication::processEvents(QEventLoop::AllEvents);
            microWait(100);
        }
        microWait(1000);
    } };



class MockEcho : public EchoLastInput {
public:
    MOCK_CONST_METHOD1(onInput, InputValidation(std::string input));
};
TEST(REPL_WINDOW, CAN_SHOW_THE_REPL_WINDOW) {
    ReplApplication app(0, nullptr);
    ReplWindow &window = app.getReplWindow();
    EXPECT_TRUE(window.isHidden());
    window.show();
    EXPECT_FALSE(window.isHidden());
}

TEST(REPL_WINDOW, CAN_SHOW_THE_REPL_WINDOW_2) {
    //StrictMock<MockEcho> echo;
    ReplApplication app(0, nullptr);
    //app.setInputHandler(&echo);
    ReplWindow &window = app.getReplWindow();
    window.show();
    EchoLastInput lastInput;
    app.setInputHandler(&lastInput);
    app.sendInput("Ada");
    //app.quit();
    //app.exec();
    FlushEvents<>();
    //EXPECT_CALL(echo, onInput("Ada")).Times(1);
    EXPECT_EQ(app.getReplWindow().getOutputText(), "Ada");
}