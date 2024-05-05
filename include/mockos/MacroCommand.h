#ifndef MOCKOS_MACROCOMMAND_H
#define MOCKOS_MACROCOMMAND_H

#include <iostream>
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/AbstractParsingStrategy.h"

using namespace std;

class MacroCommand : public AbstractCommand {
public:
    MacroCommand(AbstractFileSystem* fs);

    ~MacroCommand() override = default;

    int execute(string s) override;

    void displayInfo() override;

    void addCommand(AbstractCommand* );

    void setParseStrategy(AbstractParsingStrategy* );


private:
    vector<AbstractCommand* > commands;

    AbstractParsingStrategy* parser;

    AbstractFileSystem* fs;
};

#endif