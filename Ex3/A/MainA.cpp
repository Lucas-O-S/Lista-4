#include <iostream>
#include "NPR.cpp"

using namespace std;

int main(){

    cout << "Digite um operacao: ";

    string operacao;

    getline(cin, operacao);

    if(NPR::ValidarDelimitadores(operacao)){
        operacao = NPR::ConverterNPR(operacao);
        cout <<"\n Operacao em NPR: " << operacao;
        cout << "\n O resultado da operacao foi: " << NPR::CalcularNPR(operacao);
    }

    else{
        cout << "\nInvalido"<< endl;
        return -1;
    }




    return 0;
}