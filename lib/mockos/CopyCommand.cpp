#include <iostream>
#include <sstream>
#include "mockos/CopyCommand.h"
#include "mockos/Constants.h"
#include "mockos/AbstractFile.h"

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem *fileSystem)
        : fileSystem(fileSystem) {}

int CopyCommand::execute(string s) {
    istringstream iss(s);
    string fileToCopyName;
    string newName;
    if (!(iss >> fileToCopyName >> newName)) {
        cerr << "Error: option not supported for cp command" << endl;
        return COMMAND_FAILED;
    }

    AbstractFile *fileToCopy = fileSystem->openFile(fileToCopyName);
    fileSystem->closeFile(fileToCopy);
    if (fileToCopy == nullptr) {
        cerr << "Error: file to copy does not exist in file system" << endl;
        return FILE_DOES_NOT_EXIST;
    }

    AbstractFile *fileCopy = nullptr;
    try {
        fileCopy = fileToCopy->clone(newName);
    } catch (...) {
        cerr << "Error making copy of file" << endl;
        return COPY_ERROR;
    }

    if (fileSystem->addFile(fileCopy->getName(), fileCopy) != SUCCESS) {
        cerr << "Error adding copy to file system" << endl;
        return FAILED_TO_ADD_FILE_TO_FS;
    }

    return SUCCESS;
}

void CopyCommand::displayInfo() {
    cout << "cp will copy a file that exists in the file system and add the copy to the file\n"
            "system with a different name. It is invoked with the following command structure:\n"
            "cp <file_to_copy> <new_name_with_no_extension>" << endl;
}