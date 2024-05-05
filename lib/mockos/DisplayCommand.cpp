#include <iostream>
#include <sstream>
#include "mockos/Constants.h"
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/DisplayCommand.h"
#include "mockos/BasicDisplayVisitor.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem *fs) : fs(fs) {}

int DisplayCommand::execute(string s) {
    istringstream command(s);
    string fileName;
    string appendage;

    command >> fileName >> appendage;

    AbstractFile* file = fs->openFile(fileName);
    if (file == nullptr) {
        cerr << "Error: This file does not exist" << endl;
        return FILE_DOES_NOT_EXIST;
    }
    //reads in files info, and then displays the files contents
    if (appendage == "-d") {
        vector<char> fileInfo = file->read();

        for (int i = 0; i < fileInfo.size(); i ++) {
            cout << fileInfo[i];
        }
        cout << endl;
        fs->closeFile(file);
        return SUCCESS;
    }
    else {
        AbstractFileVisitor* BDVisitor = new BasicDisplayVisitor;
        file->accept(BDVisitor);
    }
    //close the file after execute finished
    fs->closeFile(file);
    return SUCCESS;
}

void DisplayCommand::displayInfo() {
    cout << "ds opens a file and displays its contents. Usage: ds <fileName> [-d]" << endl;
}