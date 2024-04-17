#ifndef MOCKOS_SIMPLEFILEFACTORY_H
#define MOCKOS_SIMPLEFILEFACTORY_H

#include <iostream>
#include "AbstractFileFactory.h"
#include "mockos/AbstractFile.h"

using namespace std;

class SimpleFileFactory: public AbstractFileFactory {
public:
    AbstractFile * createFile(string fileName) override;
};

#endif //MOCKOS_SIMPLEFILEFACTORY_H