#include <iostream>
#include <limits>
#include <vector>

#include "icommand.h"
#include "appendtextcommand.h"
#include "commandstack.h"
#include "uppercasecommand.h"

using namespace std;

int main()
{
    string teste;
	string appendstr;

    CommandStack stack;

    int opcao;

    while(true)
    {
        cout << teste << "\n\n\n"
             << "1 para concatenar uma string na string digitada\n"
             << "2 para deixar a string inteira maiuscula\n"
             << "3 para dar << undo no command atual\n"
             << "4 para dar redo >> no command atual\n"
             << "0 para sair\n";


        cin >> opcao;


        if(opcao == 1)
        {
            cout << "Digite uma string a ser concatenada: ";

            // purging keyboard buffer
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            getline(cin, appendstr);
			
			if(appendstr.empty())
			{
				cout << "\n\nErro: Nada foi digitado\n\n";
				continue;
			}

            stack.push(new AppendTextCommand(&teste, appendstr));
         }
        else if(opcao == 2)
        {
            stack.push(new UppercaseCommand(&teste));
        }
        else if(opcao == 3)
        {
            stack.undo();

         }
        else if(opcao == 4)
        {
            stack.redo();


         }
        else if(!opcao)
        {
            break;
        }

    } // while

    return 0;
}
