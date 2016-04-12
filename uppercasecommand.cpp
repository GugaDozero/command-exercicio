#include "uppercasecommand.h"

#include <cctype>

UppercaseCommand::UppercaseCommand(string *doc, const string &text) :
    m_doc(doc),
    m_text(text)
{

}

void UppercaseCommand::redo()
{
    for (auto iter = m_text.begin(); iter != m_text.end(); ++iter)
    {
        *iter = toupper(*iter);
    }

    this->m_doc->erase(this->m_doc->length() - this->m_text.length(), this->m_text.length());
    this->m_doc->insert(this->m_doc->length() + this->m_text.length() - 1, this->m_text);
}

void UppercaseCommand::undo()
{
    for (auto iter = m_text.begin(); iter != m_text.end(); ++iter)
    {
        *iter = tolower(*iter);
    }

    this->m_doc->erase(this->m_doc->length() - this->m_text.length(), this->m_text.length());
    this->m_doc->insert(this->m_doc->length() + this->m_text.length() - 1, this->m_text);
}


