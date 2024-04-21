#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>
#include <vector>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile *text) {
    cout << "Name: " << text->getName() << endl;
    cout << "Size: " << text->getSize() << endl;
    cout << "Type: text" << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile *image) {
    cout << "Name: " << image->getName() << endl;
    cout << "Size: " << image->getSize() << endl;
    cout << "Type: image" << endl;
}
