#include "mockos/BasicDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>
#include <vector>

using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile *textFile) {
    for (char c: textFile->read()) {
        cout << c;
    }
    cout << endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile *imageFile) {
    unsigned int size = imageFile->getSize();
    vector<char> contents = imageFile->read();

    for (int y = 0; y < sqrt(size); ++y) {
        for (int x = 0; x < sqrt(size); ++x) {
            int index = imageFile->coordToIndex(x, y);
            cout << contents[index] << " ";
        }
        cout << endl;
    }

}
