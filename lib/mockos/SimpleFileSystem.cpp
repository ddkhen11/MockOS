#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/Constants.h"
#include <sstream>
#include <string>

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

set<string> SimpleFileSystem::getFileNames() {
    set<string> fileNames;
    for (const auto& filePair : files) {
        fileNames.insert(filePair.first);
    }
    return fileNames;
}

