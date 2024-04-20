#include <iostream>
#include "Pilha.cpp"

using namespace std;

//Teste de pilha
int main(){

    //Teste para criar pilha de int
    Pilha<int> pilha;

    //teste de push
    pilha.push(20);
    pilha.push(19);
    pilha.push(24);
    pilha.push(19);
    pilha.push(1);
    pilha.push(2);

    //teste para ver se topo equivale ao ultimo valor adicionado
    cout << pilha.Top() << endl;

    //Teste para ver se é recuperado o menor valor
    cout << pilha.Mim() << endl;

    //Teste Pop
    pilha.pop();
    pilha.pop();
    pilha.pop();

    //Verificar se o topo foi alterado
    cout << pilha.Top() << endl;

    //Verifica se o menor valor está correto segundo a logica
    cout << pilha.Mim() << endl;

    return 0;
}
