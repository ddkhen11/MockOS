#include "mockos/BasicDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile *textFile) {
    for (char c: textFile->read()) {
        cout << c;
    }
    cout << endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile *imageFile) {
    vector<char> contents = imageFile->read();

    int n = sqrt(imageFile->getSize());

    if (n * n != contents.size()) {
        cerr << "Error: invalid size" << endl;
        return;
    }

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            int index = imageFile->coordToIndex(x, y);
            cout << contents[index];
        }
        cout << endl;
    }
}
