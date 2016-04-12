#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>

using std::string;

class ICommand
{
public:
    virtual ~ICommand() {};

    virtual void undo() = 0;
    virtual void redo() = 0;
};

#endif // ICOMMAND_H
