#ifndef MOCKOS_IMAGEFILE_H
#define MOCKOS_IMAGEFILE_H

#include <iostream>
#include <string>
#include "AbstractFile.h"

using namespace std;


class ImageFile : public AbstractFile {
private:
    string name;
    vector<char> contents;
    char size;

public:
    ImageFile(string newName);

    unsigned int getSize() override;

    string getName() override;

    int write(vector<char> image) override;

    int append(vector<char> newVect) override;

    vector<char> read() override;

    int coordToIndex(int x, int y);

    void accept(AbstractFileVisitor *afv) override;
};

#include "AbstractFileVisitor.h"

#endif //MOCKOS_IMAGEFILE_H