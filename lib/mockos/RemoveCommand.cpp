#include "mockos/RemoveCommand.h"
#include "mockos/Constants.h"

RemoveCommand::RemoveCommand(AbstractFileSystem *fileSystem)
        : fileSystem(fileSystem) {}

void RemoveCommand::displayInfo() {
    cout << "Remove removes a file, remove can be invoked with the command: rm <filename>" << endl;
}

int RemoveCommand::execute(string s) {
    int deletion = fileSystem->deleteFile(s);
    if (deletion != SUCCESS){
        cout << "Deletion was unsuccessful" << endl;
        return DELETION_FAILED;
    }
    return SUCCESS;
}