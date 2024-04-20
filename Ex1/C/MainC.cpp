#include <iostream>
#include "Pilha.cpp"

using namespace std;


int main(){

    Pilha<int> pilha;

    pilha.push(20);
    pilha.push(19);
    pilha.push(24);
    pilha.push(19);
    pilha.push(1);
    pilha.push(2);

    cout << pilha.Top() << endl;
    
    cout << pilha.Mim() << endl;

    pilha.pop();
    pilha.pop();
    pilha.pop();


    cout << pilha.Top() << endl;
    
    cout << pilha.Mim() << endl;

    return 0;
}