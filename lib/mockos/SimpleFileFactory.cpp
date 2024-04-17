#include "mockos/SimpleFileFactory.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/Constants.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <sstream>


using namespace std;

AbstractFile * SimpleFileFactory::createFile(string fileName) {
    istringstream iss(fileName);
    string fileExt;
    getline(iss, fileExt, '.');
    getline(iss, fileExt);
    AbstractFile *file;
    if (fileExt == "txt") {
        file = new TextFile(fileName);
    } else if (fileExt == "img") {
        file = new ImageFile(fileName);
    } else {
        file = nullptr;
    }
    return file;
}