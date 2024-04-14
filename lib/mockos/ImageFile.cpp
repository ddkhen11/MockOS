#include "mockos/ImageFile.h"

ImageFile::ImageFile(string newName): name(newName), size(0) {}

unsigned int ImageFile::getSize() {
    return size;
}

string ImageFile::getName(){
    return name;
}

int ImageFile::write(vector<char> image) {
    size = image.back() - 48;
    image.pop_back();

    if (image.size() != size * size) {
        return SIZE_MISMATCH;
    }

    for (auto pixel : image) {
        if (pixel != 'X' && pixel != ' ') {
            return INVALID_IMAGE;
        }
        contents.push_back(pixel);
    }

    return SUCCESS;
}

int ImageFile::append(vector<char> newVect) {
    return APPEND_NOT_SUPPORTED;
}

int ImageFile::coordToIndex(int x, int y) {
    return y * size + x;
}

void ImageFile::read() {
    for (int y = 0; y < size; ++y){
        for (int x = 0; x < size; ++x) {
            int index = coordToIndex(x, y);
            cout << contents[index] << " ";
        }
        cout << endl;
    }
}

