#include <iostream>
#include <map>
#include <set>
#include "AbstractFileSystem.h"

using namespace std;

class SimpleFileSystem: public AbstractFileSystem{
private:
    map<string, AbstractFile*> files;
    set<AbstractFile*> openFiles;
public:
    int addFile(string fileName, AbstractFile * file) override;
    int createFile(string fileName) override;
    int deleteFile(string fileName) override;
    AbstractFile * openFile(string fileName) override;
    int closeFile(AbstractFile * file) override;
};