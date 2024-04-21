#include <iostream>
#include "NPR.cpp"

using namespace std;

//Teste de usuario para o NPR
int main(){

 

    cout << "Digite um operacao em NPR: ";

    string operacao;

    getline(cin, operacao);

    double resultado = CalcularNPR(operacao);

    cout << "Resultado: " << resultado << endl;

    return 0;


}