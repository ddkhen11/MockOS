#ifndef MOCKOS_REMOVECOMMAND_H
#define MOCKOS_REMOVECOMMAND_H

#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

class RemoveCommand : public AbstractCommand {
public:
    RemoveCommand(AbstractFileSystem* fileSystem);
    ~RemoveCommand() override = default;
    void displayInfo() override;
    int execute(string s) override;

private:
    AbstractFileSystem * fileSystem;
};

#endif //MOCKOS_REMOVECOMMAND_H