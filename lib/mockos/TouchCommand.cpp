#include <iostream>
#include <sstream>
#include <string>
#include "mockos/TouchCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/Constants.h"
#include "mockos/PasswordProxy.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem *fileSystem, AbstractFileFactory *fileFactory)
        : fileSystem(fileSystem), fileFactory(fileFactory) {}

void TouchCommand::displayInfo() {
    cout << "touch creates a file. touch can be invoked with the command: touch <filename> \n touch <filename> -p "
            "will create a password protected file and prompt you to make your password." <<
         endl;
}

int TouchCommand::execute(string s) {
    istringstream iss(s);
    string fileName;
    string option;

    iss >> fileName;
    iss >> option;

    AbstractFile *file = fileFactory->createFile(fileName);
    if (file == nullptr) {
        cerr << "Error: Failed creating a new file." << endl;
        return FAILED_TO_CREATE_FILE;
    }

    AbstractFile *fileToAdd = file;

    if (option == "-p") {
        cout << "What is the password?" << endl;
        string password;
        getline(cin, password);
        AbstractFile *proxy = new PasswordProxy(file, password);
        fileToAdd = proxy;
    } else if (!option.empty()) {
        delete file;
        cerr << "Error: option not supported for touch command" << endl;
        return COMMAND_FAILED;
    }

    if (fileSystem->addFile(fileName, fileToAdd) != SUCCESS) {
        cerr << "Error: Failed to add the new file to the file system." << endl;
        return FAILED_TO_ADD_FILE_TO_FS;
    }

    return SUCCESS;
}
