#include <string>
#include <vector>
#include "mockos/TextFile.h"
#include "mockos/Constants.h"

using namespace std;

TextFile::TextFile(string newName) : name(newName) {}

vector<char> TextFile::read() {
//    for (char c : contents) {
//        cout << c;
//    }
//    cout << endl;

    return contents;
}

int TextFile::write(vector<char> newVect) {
    contents = newVect;
    return SUCCESS;
}

int TextFile::append(vector<char> addtlVect) {
    contents.insert(contents.end(), addtlVect.begin(), addtlVect.end());
    return SUCCESS;

}

unsigned int TextFile::getSize() {
    return contents.size();
}

string TextFile::getName() {
    return name;
}

void TextFile::accept(AbstractFileVisitor *afv) {
    afv->visit_TextFile(this);
}

AbstractFile *TextFile::clone(string newName) {
    auto* newFile = new TextFile(newName + ".txt");
    newFile->contents = this->contents;
    return newFile;
}
