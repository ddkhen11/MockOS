#ifndef MOCKOS_COPYCOMMAND_H
#define MOCKOS_COPYCOMMAND_H

#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

using namespace std;

class CopyCommand : public AbstractCommand {
public:
    CopyCommand(AbstractFileSystem* fileSystem);
    ~CopyCommand() override = default;
    void displayInfo() override;
    int execute(string s) override;

private:
    AbstractFileSystem * fileSystem;
};

#endif //MOCKOS_COPYCOMMAND_H