#include <iostream>
#include "AbstractFile.h"

using namespace std;

class AbstractFileSystem {
public:
    virtual int addFile(string fileName, AbstractFile * file) = 0;
    virtual int createFile(string fileName) = 0;
    virtual int deleteFile(string fileName) = 0;
    virtual AbstractFile * openFile(string fileName) = 0;
    virtual int closeFile(AbstractFile * file) = 0;
};