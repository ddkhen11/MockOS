#ifndef MOCKOS_PASSWORDPROXY_H
#define MOCKOS_PASSWORDPROXY_H

#include <iostream>
#include "AbstractFile.h"

using namespace std;

class PasswordProxy : AbstractFile {
public:
    PasswordProxy(AbstractFile * _file, string _password);
    ~PasswordProxy() override;
    vector<char> read() override;
    int write(vector<char> writeage) override;
    int append(vector<char> appendage) override;
    unsigned int getSize() override;
    string getName() override;
    void accept(AbstractFileVisitor *afv) override;
private:
    AbstractFile * file;
    string password;
protected:
    string passwordPrompt();
    bool passwordChecker(string password);

};

#endif //MOCKOS_PASSWORDPROXY_H