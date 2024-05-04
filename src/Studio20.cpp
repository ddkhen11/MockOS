#include <iostream>
#include <vector>
#include <string>
#include "mockos/Constants.h"
#include "mockos/AbstractFile.h"
#include "mockos/TextFile.h"
#include "mockos/AbstractFileSystem.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/AbstractFileFactory.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/PasswordProxy.h"

using namespace std;

int main() {
    AbstractFile * text =  new TextFile("textFile");
    text->write({'p', 'r', 'i', 'z', 'e'});
    PasswordProxy proxy = PasswordProxy(text, "password");
    vector<char> readText = proxy.read();
    cout << readText.data() << endl;
    proxy.write({' ', 'p', 'r', 'o', 'z', 'e'});
    BasicDisplayVisitor bdv;
    proxy.accept(&bdv);

    return SUCCESS;
}