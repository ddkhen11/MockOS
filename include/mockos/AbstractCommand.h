#ifndef MOCKOS_ABSTRACTCOMMAND_H
#define MOCKOS_ABSTRACTCOMMAND_H

#include <iostream>
#include "mockos/AbstractFile.h"

using namespace std;

class AbstractCommand {
public:
    ~AbstractCommand() = default;
    virtual int execute(string s) = 0;
    virtual void displayInfo() = 0;
};

#endif //MOCKOS_ABSTRACTCOMMAND_H