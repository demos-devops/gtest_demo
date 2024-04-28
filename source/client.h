// Client.h
#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "printer.h"

class Client {
public:
    void sendMessage(const std::string& message) {
        printer_.print(message);
    }

private:
    printer printer_;
};

class Calculator {
public:
    virtual int add(int a, int b) = 0;
};

#endif // CLIENT_H
