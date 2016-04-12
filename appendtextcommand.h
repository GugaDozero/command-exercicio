#ifndef APPENDTEXTCOMMAND_H
#define APPENDTEXTCOMMAND_H

#include "icommand.h"

class AppendTextCommand : public ICommand
{
public:
    AppendTextCommand(string *doc, const string &text);

    virtual void redo();
    virtual void undo();

private:
    string *m_document;
    string m_text;
};

#endif // APPENDTEXTCOMMAND_H
