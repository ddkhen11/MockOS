#include <iostream>
#include "mockos/CommandPrompt.h"
#include "mockos/Constants.h"
#include "mockos/TouchCommand.h"
#include "mockos/AbstractCommand.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/AbstractFile.h"

using namespace std;

int main() {
    AbstractFileSystem * simpleSystem = new SimpleFileSystem();
    AbstractFileFactory * simpleFactory = new SimpleFileFactory();
    AbstractCommand * touch = new TouchCommand(simpleSystem, simpleFactory);

    CommandPrompt commandPrompt;
    commandPrompt.setFileSystem(simpleSystem);
    commandPrompt.setFileFactory(simpleFactory);
    commandPrompt.addCommand("touch", touch);

    commandPrompt.run();

    AbstractFile * file = simpleSystem->openFile("file.txt");
    if (file != nullptr) {
        cout << "File successfully opened" << endl;
    }

    return SUCCESS;
}