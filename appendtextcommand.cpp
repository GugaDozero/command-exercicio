#include "appendtextcommand.h"

AppendTextCommand::AppendTextCommand(string *doc, const string &text) :
    m_document(doc),
    m_text(text)
{
}

void AppendTextCommand::redo()
{
    this->m_document->append(this->m_text);
}

void AppendTextCommand::undo()
{
    this->m_document->erase(this->m_document->length() - this->m_text.length(), this->m_text.length());
}
