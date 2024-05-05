#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile *text) {
    cout << left << setw(20) << text->getName()
         << left << setw(10) << "text"
         << right << setw(3) << text->getSize() << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile *image) {
    cout << left << setw(20) << image->getName()
         << left << setw(10) << "image"
         << right << setw(3) << image->getSize() << endl;
}

//void MetadataDisplayVisitor::visit_TextFile(TextFile *text) {
//    cout << "Name: " << text->getName() << endl;
//    cout << "Size: " << text->getSize() << endl;
//    cout << "Type: text" << endl;
//}
//
//void MetadataDisplayVisitor::visit_ImageFile(ImageFile *image) {
//    cout << "Name: " << image->getName() << endl;
//    cout << "Size: " << image->getSize() << endl;
//    cout << "Type: image" << endl;
//}
