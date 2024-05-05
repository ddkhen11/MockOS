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
#include "mockos/MacroCommand.h"
#include "mockos/RenameParsingStrategy.h"
#include "mockos/CopyCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/LSCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"

int main() {
    AbstractFileSystem* abstractSystem = new SimpleFileSystem();
    AbstractFileFactory* factory = new SimpleFileFactory();
    AbstractCommand* touch = new TouchCommand(abstractSystem, factory);
    AbstractCommand* ls = new LSCommand(abstractSystem);
    AbstractCommand* remove = new RemoveCommand(abstractSystem);
    AbstractCommand* cat = new CatCommand(abstractSystem);
    AbstractCommand* display = new DisplayCommand(abstractSystem);
    AbstractCommand* copy = new CopyCommand(abstractSystem);

    MacroCommand* rename = new MacroCommand(abstractSystem);
    rename->setParseStrategy(new RenameParsingStrategy());
    rename->addCommand(copy);
    rename->addCommand(remove);

    //Touch-Cat Macro-command
    MacroCommand* tc = new MacroCommand(abstractSystem);
    tc->addCommand(touch);
    tc->addCommand(cat);

    CommandPrompt* cp = new CommandPrompt();
    cp->setFileSystem(abstractSystem);
    cp->setFileFactory(factory);

    //commands
    cp->addCommand("touch", touch);
    cp->addCommand("ls", ls);
    cp->addCommand("rm", remove);
    cp->addCommand("cat", cat);
    cp->addCommand("dp", display);
    cp->addCommand("cp", copy);
    //macro commands
    cp->addCommand("rn", rename);
    cp->addCommand("tc", tc);

    cp->run();

}
