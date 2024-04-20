#include <iostream>
#include "Fila.cpp"

using namespace std;


int main(){

    //Cria a fila
    Fila<int> fila;

    //Insere os valores
    fila.Inserir(20);
    fila.Inserir(19);
    fila.Inserir(24);
    fila.Inserir(19);
    fila.Inserir(1);
    fila.Inserir(2);

    //mostra o falor da frente da fila e retira ele para testar se a fila está correto

    cout << fila.Consulta() << endl;
    
    fila.Remover();
        
    cout << fila.Consulta() << endl;

    fila.Remover();
        
    cout << fila.Consulta() << endl;

    fila.Remover();
        
    cout << fila.Consulta() << endl;

    return 0;
}