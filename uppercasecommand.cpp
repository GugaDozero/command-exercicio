#include "uppercasecommand.h"

#include <cctype>
#include <cstdlib>

UppercaseCommand::UppercaseCommand(string *doc) :
    m_doc(doc),
    m_isDone(false)
{

}

void UppercaseCommand::redo()
{
    /* before long ago, nothing related to the actual code, please, dont mix these codes */

    /*for (auto iter = m_text.begin(); iter != m_text.end(); ++iter)
    {
        *iter = toupper(*iter);
    }

    int shift = abs((int)(this->m_doc->length() - this->m_text.length()));

    this->m_doc->erase(shift, this->m_text.length());
    this->m_doc->replace(shift, this->m_text.length(), this->m_text);*/


    /* dont mix, nothing related, arbitrary implementation */

    if(m_isDone)
    {
        m_oldDoc.swap(*m_doc);
        return;
    }

    unsigned count = 0;

    for(unsigned i = 0; i < m_doc->length(); ++i)
    {
        char ch = m_doc->operator [](i);
        if(!((ch >> 5) & 1) || (ch == 0x20)) ++count; // 0x20 can either a space char or an upper/lower cases flag, we treat both
    }

    if(count == m_doc->length()) return;


    m_oldDoc = *m_doc;

    for (auto iter = m_doc->begin(); iter != m_doc->end(); ++iter)
    {
            if(*iter != 0x20) *iter &= ~(0x20); // 0x20 can either a space char or an upper/lower cases flag, we treat both
    }

    m_isDone = true;
}

void UppercaseCommand::undo()
{

    /* same as above */
    /*
    for (auto iter = m_text.begin(); iter != m_text.end(); ++iter)
    {
        *iter = tolower(*iter);
    }

    int shift = abs((int)(this->m_doc->length() - this->m_text.length()));

    this->m_doc->erase(shift, this->m_text.length());
    this->m_doc->replace(shift, this->m_text.length(), this->m_text);*/

    if(m_isDone) m_oldDoc.swap(*m_doc);
}


