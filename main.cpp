#include <iostream>
#include <limits>

#include "icommand.h"
#include "appendtextcommand.h"
#include "commandstack.h"
#include "uppercasecommand.h"

using namespace std;

int main()
{
    string teste;
    string appended;



    CommandStack stack;

    int opcao;
    bool more = true;

    do
    {
        cout << teste << "\n\n\n"
             << "1 para concatenar uma string na string digitada\n"
             << "2 para deixar a string maiuscula\n"
             << "3 para dar << undo no command atual\n"
             << "4 para dar redo >> no command atual\n"
             << "qualquer coisa para sair\n";

        cin >> opcao;
        switch(opcao)
        {
        case 1:
            cout << "Digite uma string a ser concatenada: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, appended);
            stack.push(new AppendTextCommand(&teste, appended));
            break;
        case 2:
            stack.push(new UppercaseCommand(&teste, appended));
            break;
        case 3:
            stack.undo();
            break;
        case 4:
            stack.redo();
            break;
        default:
            more = false;
            break;
        }
    }
    while(more);

	cin.get();
    return 0;
}
