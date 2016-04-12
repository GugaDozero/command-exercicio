#ifndef COMMANDSTACK_H
#define COMMANDSTACK_H

#include <vector>

using std::vector;

class ICommand;

class CommandStack
{
public:
    CommandStack() : m_currentIndex(-1) {}
	~CommandStack();

    void push(ICommand *cmd);
    void undo();
	void redo();

private:
    vector<ICommand *> m_cmdVector;
    signed m_currentIndex;
};

#endif // COMMANDSTACK_H
