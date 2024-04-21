#include "mockos/ImageFile.h"
#include "mockos/Constants.h"
#include <cmath>
#include <vector>

ImageFile::ImageFile(string newName): name(newName), size(0) {}

unsigned int ImageFile::getSize() {
    return size;
}

string ImageFile::getName(){
    return name;
}

int ImageFile::write(vector<char> image) {
    int imgSize = image.back() - 48;
    image.pop_back();

    if (image.size() != imgSize * imgSize) {
        return SIZE_MISMATCH;
    }

    for (auto pixel : image) {
        if (pixel != 'X' && pixel != ' ') {
            return INVALID_IMAGE;
        }
        contents.push_back(pixel);
    }

    size = imgSize * imgSize;

    return SUCCESS;
}

int ImageFile::append(vector<char> newVect) {
    return APPEND_NOT_SUPPORTED;
}

int ImageFile::coordToIndex(int x, int y) {
    return y * sqrt(size) + x;
}

vector<char> ImageFile::read() {
//    for (int y = 0; y < sqrt(size); ++y){
//        for (int x = 0; x <  sqrt(size); ++x) {
//            int index = coordToIndex(x, y);
//            cout << contents[index] << " ";
//        }
//        cout << endl;
//    }

    return contents;
}

void ImageFile::accept(AbstractFileVisitor *afv) {
    afv->visit_ImageFile(this);
}

