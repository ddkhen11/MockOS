//
// Created by Malcolm Newmark on 5/6/24.
//

#ifndef MOCKOS_TCPARSINGSTRATEGY_H
#define MOCKOS_TCPARSINGSTRATEGY_H

#include "AbstractParsingStrategy.h"

class TCParsingStrategy : public AbstractParsingStrategy{
    virtual vector<string> parse (string) override;
};

#endif //MOCKOS_TCPARSINGSTRATEGY_H
