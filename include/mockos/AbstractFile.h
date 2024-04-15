#ifndef MOCKOS_ABSTRACTFILE_H
#define MOCKOS_ABSTRACTFILE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AbstractFile {
public:
    virtual void read() = 0;
    virtual int write(vector<char> writeage) = 0;
    virtual int append(vector<char> appendage) = 0;
    virtual unsigned int getSize() = 0;
    virtual string getName() = 0;
    virtual ~AbstractFile() = default;
};

#endif //MOCKOS_ABSTRACTFILE_H