#include "mockos/RenameParsingStrategy.h"
#include <sstream>

using namespace std;

vector<string> RenameParsingStrategy::parse(string s) {
    istringstream iss(s);
    string existingFile;
    string newName;
    iss >> existingFile >> newName;
    vector<string> inputs = {s, existingFile};
    return inputs;
}
