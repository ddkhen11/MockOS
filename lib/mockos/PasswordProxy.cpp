#include "mockos/PasswordProxy.h"
#include "mockos/Constants.h"
#include <string>

PasswordProxy::PasswordProxy(AbstractFile *_file, string _password) : file(_file), password(_password) {}

PasswordProxy::~PasswordProxy() {
    delete file;
}

string PasswordProxy::passwordPrompt() {
    string inputtedPassword;
    cout << "Enter your password: " << endl;
    cin >> inputtedPassword;
    return inputtedPassword;
}

bool PasswordProxy::passwordChecker(string checkPassword) {
    if (password == checkPassword) {
        return true;
    } else {
        return false;
    }
}

vector<char> PasswordProxy::read() {
    if (passwordChecker(passwordPrompt())) {
        return file->read();
    } else {
        return {};
    }
}

int PasswordProxy::write(vector<char> writeage) {
    bool correct = passwordChecker(passwordPrompt());
    if (correct) {
        return file->write(writeage);
    } else {
        return PASSWORDS_DONT_MATCH;
    }
}

int PasswordProxy::append(vector<char> appendage) {
    bool correct = passwordChecker(passwordPrompt());
    if (correct) {
        return file->append(appendage);
    } else {
        return PASSWORDS_DONT_MATCH;
    }
}

unsigned int PasswordProxy::getSize() {
    return file->getSize();
}

string PasswordProxy::getName() {
    return file->getName();
}

void PasswordProxy::accept(AbstractFileVisitor *afv) {
    if (passwordChecker(passwordPrompt())) {
        file->accept(afv);
    }
}

AbstractFile *PasswordProxy::clone(string newName) {
    auto* newFile = this->file->clone(newName);
    auto* newProxy = new PasswordProxy(newFile, this->password);
    return newProxy;
}