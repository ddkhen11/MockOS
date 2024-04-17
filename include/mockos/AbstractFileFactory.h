#include <iostream>
#include "mockos/AbstractFile.h"

using namespace std;

class AbstractFileFactory {
    virtual AbstractFile * createFile(string fileName) = 0;
};