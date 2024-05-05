#include <iostream>
#include <sstream>
#include "mockos/Constants.h"
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/CatCommand.h"
#include "mockos/BasicDisplayVisitor.h"

using namespace std;

CatCommand::CatCommand(AbstractFileSystem *fs) : fs(fs) {}

int CatCommand::execute(string s){
    istringstream command(s);
    string fileName;
    string appendage;

    command >> fileName >> appendage;

    AbstractFile* file = fs->openFile(fileName);
    fs->closeFile(file);
    if (file == nullptr) {
        cerr << "Error: This file does not exist" << endl;
        return FILE_DOES_NOT_EXIST;
    }
    if (appendage == "-a") {
        BasicDisplayVisitor BDVisitor;
        file->accept(&BDVisitor);
        cout << endl;
    }

    //read in the input from the User
    string input;
    string userInput;
    while (getline(cin, input)) {
        if (input == ":wq") {
            break;
        }
        else if (input == ":q") {
            fs->closeFile(file);
            return SUCCESS;
        }
        userInput += input;
        userInput += '\n';
    }

    //getting rid of the last new line added to the read-in input
    if(userInput.back() == '\n' && !userInput.empty()) {
        userInput.pop_back();
    }

    vector<char> inputUser(userInput.begin(), userInput.end());
    int output = SUCCESS;

    if (appendage == "-a") {
        output = file->append(inputUser);
    }
    else {
        output = file->write(inputUser);
    }

    fs->closeFile(file);
    return output;
}

void CatCommand::displayInfo() {
    cout << "cat both displays and then appends content to a file. Usage: cat <fileName> [-a]" << endl;
}