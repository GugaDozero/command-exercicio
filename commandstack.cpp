#include "commandstack.h"

#include "icommand.h"

CommandStack::~CommandStack()
{
    for(auto iter = m_cmdVector.begin(); iter != m_cmdVector.end(); ++iter)
	{
		delete *iter;
	}

	m_cmdVector.clear();
}

void CommandStack::push(ICommand *cmd)
{
    if(!m_cmdVector.empty() && m_currentIndex != (unsigned)m_cmdVector.size() - 1)
	{
		unsigned currentPos = m_currentIndex;
		m_currentIndex = m_cmdVector.size() - 1;
		do
		{
			delete m_cmdVector[m_currentIndex--];
			m_cmdVector.pop_back();
		}
		while(m_currentIndex != currentPos);
	}

    m_cmdVector.push_back(cmd);
    m_currentIndex++;
    cmd->redo();
}

void CommandStack::redo()
{
    if(m_cmdVector.empty() || m_currentIndex == (unsigned)m_cmdVector.size() - 1) return;

	m_cmdVector[++m_currentIndex]->redo();
}

void CommandStack::undo()
{
	if(m_cmdVector.empty() || m_currentIndex < 0) return;

 	m_cmdVector[m_currentIndex--]->undo();
}
