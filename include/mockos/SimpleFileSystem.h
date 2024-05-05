#ifndef MOCKOS_SIMPLEFILESYSTEM_H
#define MOCKOS_SIMPLEFILESYSTEM_H

#include <iostream>
#include <map>
#include <set>
#include <string>
#include "AbstractFileSystem.h"

using namespace std;

class SimpleFileSystem: public AbstractFileSystem{
private:
    map<string, AbstractFile*> files;
    set<AbstractFile*> openFiles;
public:
    int addFile(string fileName, AbstractFile * file) override;
    int deleteFile(string fileName) override;
    AbstractFile * openFile(string fileName) override;
    int closeFile(AbstractFile * file) override;
    set<string> getFileNames() override;
};

#endif //MOCKOS_SIMPLEFILESYSTEM_H