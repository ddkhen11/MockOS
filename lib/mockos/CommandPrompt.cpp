#include <iostream>
#include <sstream>
#include <string>
#include "mockos/CommandPrompt.h"
#include "mockos/Constants.h"

using namespace std;

CommandPrompt::CommandPrompt() : fileSystemObject(nullptr), fileFactoryObject(nullptr){};

void CommandPrompt::setFileSystem(AbstractFileSystem * system) {
    fileSystemObject = system;
}

void CommandPrompt::setFileFactory(AbstractFileFactory * factory) {
    fileFactoryObject = factory;
}

int CommandPrompt::addCommand(std::string name, AbstractCommand * command) {
    pair<string, AbstractCommand *> commandPair = make_pair(name, command);
    auto result = commandObjects.insert(commandPair);
    if (result.second) {
        return SUCCESS;
    } else {
        return INSERTION_FAILED;
    }
}

void CommandPrompt::listCommands() {
    cout << "Available Commands: ";
    for (const auto& pair : commandObjects) {
        cout << pair.first << " ";
    }
    cout << endl;
}

string CommandPrompt::prompt() {
    cout << "Enter a command, q to quit, help for a list of commands, or\n"
            "help followed by a command name for more information about\n"
            "that command.\n";

    cout << "$  ";
    string input;
    getline(cin, input);
    return input;
}

int CommandPrompt::run() {
    while (true) {
        string input = prompt();

        if (input == "q") {
            cout << "Quitting Program." << endl;
            return USER_QUIT;
        }
        else if (input == "help") {
            listCommands();
            continue;
        }

        else if (input.find(' ') == string::npos){
            auto found = commandObjects.find(input);
            if (found == commandObjects.end()) {
                cout << "Command not found" << endl;
            }
            else {
                int returnCode = found->second->execute("");
                if (returnCode != SUCCESS) {
                    cerr << "This command failed and returned error: " << returnCode << endl;
                }
            }
        }
        else if (input.find(' ')) {
            istringstream iss(input);
            string first;
            iss >> first;
            if (first == "help") {
                string second;
                iss >> second;
                auto it = commandObjects.find(second);
                if (it == commandObjects.end()){
                    cout << "Command not found" << endl;
                }
                else {
                    it->second->displayInfo();
                }
            }
            else {
                auto it = commandObjects.find(first);
                if (it == commandObjects.end()) {
                    cout << "Command not found" << endl;
                }
                else {
                    string restOfInput = input.substr(input.find(' ') + 1);
                    int checkInput = it->second->execute(restOfInput);
                    if (checkInput != SUCCESS) {
                        cerr << "This command failed and returned error: " << checkInput << endl;
                    }
                }
            }
        }
    }
}
