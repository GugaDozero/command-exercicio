#ifndef UPPERCASECOMMAND_H
#define UPPERCASECOMMAND_H

#include "icommand.h"

#include <string>

class UppercaseCommand : public ICommand
{
public:
    UppercaseCommand(string *doc);

    virtual void undo();
    virtual void redo();

private:
    string *m_doc;
    string m_oldDoc;

    bool m_isDone;
};

#endif // UPPERCASECOMMAND_H
