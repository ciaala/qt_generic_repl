//
// Created by Francesco Fiduccia on 02.11.17.
//

#include <iostream>
#include "ReplWindow.hpp"
#include "Repl.hpp"

ReplWindow::ReplWindow(std::string title)
        : console(new QTextEdit),
          customSize(false),
          input(new QLineEdit) {
    setWindowTitle(tr(title.c_str()));


    auto *panel = new QWidget;


    auto *gridLayout = new QGridLayout();
    gridLayout->setRowStretch(0, 100);
    panel->setLayout(gridLayout);
    gridLayout->addWidget(console, 0, 0);
    gridLayout->addWidget(input, 1, 0);
    console->setText("Console Area");

    input->setText("Input Field");
    input->connect(input,
                   &QLineEdit::returnPressed,
                   [=] { this->OnInput(input->text()); });
    this->setCentralWidget(panel);
    this->setUnifiedTitleAndToolBarOnMac(true);
}

void ReplWindow::showEvent(QShowEvent *event) {
    if (!this->customSize) {
        const QRect &qRect = QApplication::desktop()->screenGeometry(this);
        this->setBaseSize(qRect.width() / 2, qRect.height() / 2);
    }
    QWidget::showEvent(event);
}

std::string ReplWindow::getOutputText() {
    return console->toPlainText().toStdString();
}

QLineEdit *ReplWindow::getInput() {
    return this->input;
}

const std::string ReplWindow::getOutputText() const {
    return console->toPlainText().toStdString();
}

void ReplWindow::errorMessage(const char *string) {
    this->console->insertHtml("<p style='color: red; font-weight: bold;'>"
                              + QString(string)
                              + "</p>");
}

void ReplWindow::message(const char *string) {

    this->console->insertHtml("<p style='color: green; font-weight: bold;'>"
                              + QString(string)
                              + "</p><br/>");

}

void ReplWindow::OnInput(QString text) {
    if (repl != nullptr) repl->consume_input(text.toStdString());
}

void ReplWindow::setRepl(Repl *repl) {
    this->repl = repl;
}

