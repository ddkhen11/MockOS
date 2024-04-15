#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <sstream>

using namespace std;

int SimpleFileSystem::addFile(string fileName, AbstractFile *file) {
    if (files.find(fileName) != files.end()) {
        return FILE_ALREADY_EXISTS;
    }

    if (file == nullptr) {
        return FILE_IS_NULL;
    }

    pair<string, AbstractFile*> filePair = make_pair(fileName, file);
    files.insert(filePair);

    return SUCCESS;
}

int SimpleFileSystem::createFile(string fileName) {
    if (files.find(fileName) != files.end()) {
        return FILE_ALREADY_EXISTS;
    }

    istringstream iss(fileName);
    string fileExt;
    getline(iss, fileExt, '.');
    getline(iss, fileExt);

    if (fileExt == "txt") {
        auto* file = new TextFile(fileName);
        pair<string, AbstractFile*> filePair = make_pair(fileName, file);
        files.insert(filePair);
        return SUCCESS;
    } else if (fileExt == "img") {
        auto* file = new ImageFile(fileName);
        pair<string, AbstractFile*> filePair = make_pair(fileName, file);
        files.insert(filePair);
        return SUCCESS;
    } else {
        return INVALID_FILE_TYPE;
    }
}
