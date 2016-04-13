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
    vector<string> appendVec; // a solution for uppercasecommand's issue
    signed indiceVec = -1;

    CommandStack stack;

    int opcao;
    bool more = true;

    while(more)
    {
        cout << teste << "\n\n\n"
             << "1 para concatenar uma string na string digitada\n"
             << "2 para deixar a string maiuscula\n"
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

            appendVec.push_back(appendstr);
            indiceVec++;
			
			if(appendstr.empty())
			{
				cout << "\n\nErro: Nada foi digitado\n\n";
				continue;
			}

            stack.push(new AppendTextCommand(&teste, appendstr));
         }
        else if(opcao == 2)
        {
            stack.push(new UppercaseCommand(&teste, appendstr));
        }
        else if(opcao == 3)
        {
            stack.undo();

            if(!appendVec.empty())
			{
                if(indiceVec >= 0) appendstr = appendVec[indiceVec--];
			}

         }
        else if(opcao == 4)
        {
            stack.redo();

            if(!appendVec.empty())
			{
                if(indiceVec != appendVec.size() - 1) appendstr = appendVec[++indiceVec];
			}


         }
        else if(!opcao)
        {
            more = false;
        }

    } // while

	cin.get();
    return 0;
}
