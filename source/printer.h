// Printer.h
#ifndef PRINTER_H
#define PRINTER_H

#include <string>
#include <iostream>

class printer {
public:
    virtual void print(const std::string& message) {
        std::cout << message << std::endl;
    }
};

#endif // PRINTER_H
