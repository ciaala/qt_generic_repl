//
// Created by Francesco Fiduccia on 04.11.17.
//

#ifndef QT_GENERIC_REPL_OUTPUTHANDLERINTERFACE_HPP
#define QT_GENERIC_REPL_OUTPUTHANDLERINTERFACE_HPP

#include <string>

class OutputHandlerInterface {
public:
    virtual const std::string getOutputText() const = 0;

    virtual void errorMessage(const char *string) = 0;

    virtual void message(const char *string) = 0;
};


#endif //QT_GENERIC_REPL_OUTPUTHANDLERINTERFACE_HPP
