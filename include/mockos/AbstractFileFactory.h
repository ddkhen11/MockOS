#ifndef MOCKOS_ABSTRACTFILEFACTORY_H
#define MOCKOS_ABSTRACTFILEFACTORY_H

#include <iostream>
#include "mockos/AbstractFile.h"

using namespace std;

class AbstractFileFactory {
public:
    virtual AbstractFile * createFile(string fileName) = 0;
};

#endif //MOCKOS_ABSTRACTFILEFACTORY_H