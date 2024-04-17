#include <iostream>
#include <vector>
#include <string>
#include "mockos/Constants.h"
#include "mockos/AbstractFile.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/SimpleFileFactory.h"

using namespace std;

int main() {
    AbstractFileSystem *afs = new SimpleFileSystem;
    AbstractFileFactory *aff = new SimpleFileFactory;
    AbstractFile *textFile = aff->createFile("textFile.txt");
    AbstractFile *imageFile = aff->createFile("imageFile.img");
    afs->addFile(aff->createFile("textFile.txt")->getName(), textFile);
    afs->addFile(imageFile->getName(), imageFile);
    AbstractFile *openTextFile = afs->openFile("textFile.txt");
    openTextFile->write({'p', 'r', 'i', 'z', 'e'});
    openTextFile->read();
    AbstractFile *openImageFile = afs->openFile("imageFile.img");
    openImageFile->write({'X', 'X', ' ', 'X', '2'});
    openImageFile->read();
    afs->closeFile(openTextFile);
    afs->closeFile(openImageFile);
    return SUCCESS;
}