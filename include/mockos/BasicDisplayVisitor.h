#ifndef MOCKOS_BASICDISPLAYVISITOR_H
#define MOCKOS_BASICDISPLAYVISITOR_H

#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
    void visit_TextFile(TextFile *textFile) override;
    void visit_ImageFile(ImageFile *imageFile) override;
};

#endif //MOCKOS_BASICDISPLAYVISITOR_H