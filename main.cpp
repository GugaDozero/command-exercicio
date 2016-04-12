#include <iostream>

#include "icommand.h"
#include "appendtextcommand.h"
#include "commandstack.h"

using namespace std;

int main()
{
    string teste = "ola";

    CommandStack stack;

    AppendTextCommand *cmd1 = new AppendTextCommand(&teste, " tudo ");
    AppendTextCommand *cmd2 = new AppendTextCommand(&teste, "bem?");
	AppendTextCommand *cmd3 = new AppendTextCommand(&teste, "ok?");
    AppendTextCommand *cmd4 = new AppendTextCommand(&teste, "bom?");
	AppendTextCommand *cmd5 = new AppendTextCommand(&teste, "nice?");

    stack.push(cmd1); 
    stack.push(cmd2); 

	// undo and redo and undo again cmd2 command
	stack.undo(); 
	stack.redo(); 
	stack.undo(); 

	// notice that the last instruction has called undo(), so I am going to replace cmd2 by cmd3, removing (delete) cmd2 in the process
	stack.push(cmd3); // cmd2 gets deleted, replaced by cmd3
	
	
	stack.undo(); // undo cmd3
	
	stack.push(cmd4); // cmd3 gets deleted, replaced by cmd4

	stack.undo(); // undo cmd4
	stack.undo(); // undo cmd1

	stack.redo(); // redo cmd1
	stack.redo(); // redo cmd4;

	stack.redo(); // calling redo() once again does nothing to cmd4 as expected
	stack.undo();
	
	stack.push(cmd5); // cmd4 gets deleted, replaced by cmd5

	// show result
    cout << teste; // expected: "olá tudo nice?"

	cin.get();
    return 0;
}
