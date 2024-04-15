#ifndef MOCKOS_IMAGEFILE_H
#define MOCKOS_IMAGEFILE_H

#include <iostream>
#include <string>
#include "AbstractFile.h"

using namespace std;

class ImageFile: public AbstractFile {
private:
    string name;
    vector<char> contents;
    char size;
    int coordToIndex(int x, int y);
public:
    ImageFile(string newName);
    unsigned int getSize() override;
    string getName() override ;
    int write(vector<char> image) override;
    int append(vector<char> newVect) override;
    void read() override;
};

#endif //MOCKOS_IMAGEFILE_H