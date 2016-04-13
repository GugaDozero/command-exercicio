#include "uppercasecommand.h"

#include <cctype>
#include <cstdlib>

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

    int shift = abs((int)(this->m_doc->length() - this->m_text.length()));

    this->m_doc->erase(shift, this->m_text.length());
    this->m_doc->replace(shift, this->m_text.length(), this->m_text);
}

void UppercaseCommand::undo()
{
    for (auto iter = m_text.begin(); iter != m_text.end(); ++iter)
    {
        *iter = tolower(*iter);
    }

    int shift = abs((int)(this->m_doc->length() - this->m_text.length()));

    this->m_doc->erase(shift, this->m_text.length());
    this->m_doc->replace(shift, this->m_text.length(), this->m_text);
}


