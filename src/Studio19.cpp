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

using namespace std;

int main() {
    TextFile newText("newText");
    newText.write({'h', 'e', 'l', 'l', 'o'});
    vector<char> readNewText = newText.read();
    cout << "Without visitor: " << readNewText.data() << endl;
    BasicDisplayVisitor bdv;
    cout << "With visitor: ";
    newText.accept(&bdv);
    readNewText[0] = 'y';
    newText.write(readNewText);
    cout << "Without visitor: " << newText.read().data() << endl;
    cout << "With visitor: ";
    newText.accept(&bdv);

    return SUCCESS;
}