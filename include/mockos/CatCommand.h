#ifndef MOCKOS_CATCOMMAND_H
#define MOCKOS_CATCOMMAND_H

#include <iostream>
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"

using namespace std;

class CatCommand : public AbstractCommand{
public:
    CatCommand(AbstractFileSystem* fs);

    ~CatCommand() override = default;

    int execute(string s) override;

    void displayInfo() override;

private:
    AbstractFileSystem* fs;
};

#endif