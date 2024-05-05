#include <iostream>
#include <sstream>
#include <vector>
#include "mockos/Constants.h"
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/MacroCommand.h"
#include "mockos/BasicDisplayVisitor.h"

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* fs) : fs(fs), parser(nullptr){};

int MacroCommand::execute(string s) {
    vector<string> parsedInfo = parser->parse(s);

    if(parsedInfo.size() != commands.size()) {
        cerr << "Error: Number of commands and number of inputs do not match" << endl;
        return COMMAND_INPUT_MISMATCH;
    }
    for (int i = 0; i < commands.size(); ++i) {
        int output = commands[i]->execute(parsedInfo[i]);
        if (output != SUCCESS) {
            return output;
        }
    }
    return SUCCESS;

}

void MacroCommand::displayInfo() {
    cout << "MacroCommand constructs commands out of other commands" << endl;
}

void MacroCommand::addCommand(AbstractCommand* addedCommand){
    commands.push_back(addedCommand);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* parseStrategy){
    parser = parseStrategy;
}