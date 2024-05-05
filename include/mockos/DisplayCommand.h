#include <iostream>
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"

using namespace std;

class DisplayCommand : public AbstractCommand{
public:
    DisplayCommand(AbstractFileSystem* fs);

    ~DisplayCommand() override = default;

    int execute(string s) override;

    void displayInfo() override;

private:
    AbstractFileSystem* fs;
};