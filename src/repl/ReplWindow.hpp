//
// Created by Francesco Fiduccia on 02.11.17.
//

#ifndef QT_GENERIC_REPL_REPLWINDOW_HPP
#define QT_GENERIC_REPL_REPLWINDOW_HPP

#include "QtWidgets"
#include "Repl.hpp"

class ReplWindow
        : public QMainWindow,
          public OutputHandlerInterface {


public:
    explicit ReplWindow(std::string title);

    std::string getOutputText();

    QLineEdit *getInput();

    const std::string getOutputText() const override;

    void errorMessage(const char *string) override;

    void message(const char *string) override;

    void setRepl(Repl *repl);

protected:
    void showEvent(QShowEvent *event) override;

    bool customSize;

    // SLOT
    void OnInput(QString text);

private:
    QTextEdit *console;
    QLineEdit *input;
    Repl *repl;

Q_OBJECT

};


#endif //QT_GENERIC_REPL_REPLWINDOW_HPP
