#include <iostream>
#include <iomanip>
#include <set>
#include <string>
#include "mockos/LSCommand.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/Constants.h"
#include "mockos/MetadataDisplayVisitor.h"

using namespace std;

LSCommand::LSCommand(AbstractFileSystem *fileSystem)
        : fileSystem(fileSystem) {}

void LSCommand::displayInfo() {
    cout << "ls outputs the names of all files currently in the file system. ls can be invoked with the command: ls "
            "\n ls -m will display the metadata for each file as well." << endl;
}

int LSCommand::execute(string s) {
    set<string> fileNames = fileSystem->getFileNames();

    if (s.empty()) {
        int count = 0;
        for (const auto &fileName: fileNames) {
            cout << left << setw(20) << fileName;
            count++;
            if (count % 2 == 0) {
                cout << endl;
            }
        }
        if (count % 2 != 0) {
            cout << endl;
        }
    } else if (s == "-m") {
        MetadataDisplayVisitor mdv;
        for (const string &fileName: fileNames) {
            AbstractFile *file = fileSystem->openFile(fileName);
            file->accept(&mdv);
            fileSystem->closeFile(file);
        }
    } else {
        cerr << "Error: option not supported for ls command" << endl;
        return COMMAND_FAILED;
    }

    return SUCCESS;
}

