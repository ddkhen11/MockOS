#include <iostream>
#include "mockos/TouchCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/Constants.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem *fileSystem, AbstractFileFactory *fileFactory)
: fileSystem(fileSystem), fileFactory(fileFactory) {}

void TouchCommand::displayInfo() {
    cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}

int TouchCommand::execute(string s) {
    AbstractFile* file = fileFactory->createFile(s);
    if (file == nullptr) {
        cerr << "Error: Failed creating a new file." << endl;
        return FAILED_TO_CREATE_FILE;
    }

    if(fileSystem->addFile(s, file) != SUCCESS) {
        delete file;
        cerr << "Error: Failed to add the new file to the file system." << endl;
        return FAILED_TO_ADD_FILE_TO_FS;
    }

    return SUCCESS;
}