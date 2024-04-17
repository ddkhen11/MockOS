#include <iostream>
#include "AbstractFileFactory.h"
#include "mockos/AbstractFile.h"

using namespace std;

class SimpleFileFactory: public AbstractFileFactory {
public:
    AbstractFile * createFile(string fileName);
};