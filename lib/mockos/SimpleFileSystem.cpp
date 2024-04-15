#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/Constants.h"
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

AbstractFile * SimpleFileSystem::openFile(string fileName) {
    auto fileIterator = files.find(fileName);
    if (fileIterator != files.end()) {
        AbstractFile * second = fileIterator->second;
        if (openFiles.find(second) == openFiles.end()) {
            openFiles.insert(second);
            return second;
        }
    }
    return nullptr;
}

int SimpleFileSystem::closeFile(AbstractFile * file) {
    if (openFiles.find(file) != openFiles.end()) {
        openFiles.erase(file);
        return SUCCESS;
    } else {
        return FILE_NOT_OPEN;
    }
}

int SimpleFileSystem::deleteFile(string fileName) {
    auto it = files.find(fileName);
    if (it == files.end()) {
        return FILE_DOES_NOT_EXIST;
    }
    if (openFiles.find(it->second) != openFiles.end()) {
        return FILE_IS_OPEN;
    }

    files.erase(it);
    delete it->second;

    return SUCCESS;
}

