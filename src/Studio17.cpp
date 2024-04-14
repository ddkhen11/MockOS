#include <iostream>
#include <vector>
#include <string>
#include "mockos/ImageFile.h"

using namespace std;

int main () {
    cout << "Call methods by derived class" << endl;
    ImageFile imageFile1("test1");
    vector<char> test1 = {'X', 'X', ' ', 'X', '2'};
    vector<char> test2 = {'0'};
    vector<char> test3 = {'X', 'O', 'X', ' ', '2'};
    imageFile1.write(test1);
    imageFile1.read();
    if (imageFile1.append(test2) != SUCCESS) {
        cout << "Append operation not supported" << endl;
    }
    cout << imageFile1.getSize() << endl;
    cout << imageFile1.getName() << endl;
    ImageFile imageFile2("test2");
    imageFile2.write(test2);
    cout << imageFile2.getSize() << endl;
    cout << imageFile2.getName() << endl;
    ImageFile imageFile3("test3");
    if (imageFile3.write(test3) != SUCCESS) {
        cout << "Failed to write inputted image" << endl;
    }

    cout << endl;
    cout << "Call methods by aliased abstract class" << endl;
    AbstractFile* p1;
    p1 = &imageFile1;
    p1->read();
    if (p1->append(test2) != SUCCESS) {
        cout << "Append operation not supported" << endl;
    }
    cout << p1->getSize() << endl;
    cout << p1->getName() << endl;
    AbstractFile* p2;
    p2 = &imageFile2;
    cout << p2->getSize() << endl;
    cout << p2->getName() << endl;
    AbstractFile* p3;
    p3 = &imageFile3;
    if (p3->write(test3) != SUCCESS) {
        cout << "Failed to write inputted image" << endl;
    }

    return 0;
}