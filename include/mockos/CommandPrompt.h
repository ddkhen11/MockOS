#ifndef MOCKOS_COMMANDPROMPT_H
#define MOCKOS_COMMANDPROMPT_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/AbstractFileFactory.h"

using namespace std;

class CommandPrompt{
public:
    CommandPrompt();
    void setFileSystem(AbstractFileSystem * system);
    void setFileFactory(AbstractFileFactory * factory);
    int addCommand(string name, AbstractCommand * command);
    int run();

protected:
    void listCommands();
    string prompt();

private:
    map<string, AbstractCommand *> commandObjects;
    AbstractFileSystem * fileSystemObject;
    AbstractFileFactory * fileFactoryObject;
};

#endif //MOCKOS_COMMANDPROMPT_H