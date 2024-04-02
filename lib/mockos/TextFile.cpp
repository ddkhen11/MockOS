#include <string>
#include "mockos/TextFile.h"

using namespace std;

TextFile::TextFile(string newName): name(newName){}

void TextFile::read() {
    for (char c : contents) {
        cout << c;
    }
    cout << endl;
}

int TextFile::write(vector<char> newVect) {
    contents = newVect;
    return 0;
}

int TextFile::append(vector<char> addtlVect){
    contents.insert(contents.end(), addtlVect.begin(), addtlVect.end());
    return 0;

}

unsigned int TextFile::getSize(){
    return contents.size();
}

string TextFile::getName(){
    return name;
}