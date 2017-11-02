//
// Created by Francesco Fiduccia on 02.11.17.
//

#ifndef QT_GENERIC_REPL_REPLWINDOW_HPP
#define QT_GENERIC_REPL_REPLWINDOW_HPP

#include "QtWidgets"

class ReplWindow
        : public QMainWindow {
Q_OBJECT

public:
    explicit ReplWindow(std::string title);
};


#endif //QT_GENERIC_REPL_REPLWINDOW_HPP
