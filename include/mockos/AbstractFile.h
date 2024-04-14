#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum error_code {
    SUCCESS,
    INVALID_IMAGE,
    SIZE_MISMATCH,
    APPEND_NOT_SUPPORTED,
    FILE_ALREADY_EXISTS,
    FILE_IS_NULL,
    INVALID_FILE_TYPE
};

class AbstractFile {
public:
    virtual void read() = 0;
    virtual int write(vector<char> writeage) = 0;
    virtual int append(vector<char> appendage) = 0;
    virtual unsigned int getSize() = 0;
    virtual string getName() = 0;
};