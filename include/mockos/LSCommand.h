#ifndef MOCKOS_LSCOMMAND_H
#define MOCKOS_LSCOMMAND_H

#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/AbstractFileSystem.h"

using namespace std;

class LSCommand : public AbstractCommand {
public:
    LSCommand(AbstractFileSystem* fileSystem);
    ~LSCommand() override = default;
    void displayInfo() override;
    int execute(string s) override;

private:
    AbstractFileSystem * fileSystem;
};

#endif //MOCKOS_LSCOMMAND_H