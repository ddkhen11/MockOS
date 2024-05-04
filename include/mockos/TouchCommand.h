#ifndef MOCKOS_TOUCHCOMMAND_H
#define MOCKOS_TOUCHCOMMAND_H

#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

using namespace std;

class TouchCommand : public AbstractCommand {
public:
    TouchCommand(AbstractFileSystem* fileSystem, AbstractFileFactory* fileFactory);
    virtual ~TouchCommand() = default;
    void displayInfo() override;
    int execute(string s) override;

private:
    AbstractFileSystem * fileSystem;
    AbstractFileFactory * fileFactory;
};

#endif //MOCKOS_TOUCHCOMMAND_H