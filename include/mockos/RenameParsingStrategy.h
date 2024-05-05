#include "mockos/MacroCommand.h"

using namespace std;

class RenameParsingStrategy : public AbstractParsingStrategy{
public:
    vector<string> parse(string s) override;
};