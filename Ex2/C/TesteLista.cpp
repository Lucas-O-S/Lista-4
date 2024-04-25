#include "Lista.cpp"
#include <iostream>

using namespace std;

int main(){

    Lista<int> lista;

    lista.Inserir(0);
    lista.Inserir(1);
    lista.Inserir(2);
    lista.Inserir(3);

    cout << "Teste de inserção: \n";

    lista.ListarDados();

    cout << "Teste de inserção: \n";

    lista.ListarDadosInverso();

    cout << "\n Teste inversão de lista: \n";

    lista.Inverter();

    lista.Inserir(4);

    cout << "\nCabeca: " << lista.Cabeca() << endl;

    cout << "\nCalda: " << lista.Calda() << endl;

    cout << "\nListagem:" << endl;

    lista.ListarDados();

    cout << "\nBuscar dado especifico" << endl;

    cout << "\nBuscar segundo dado da lista: " << lista.BuscarDado(1) << endl;

    cout << "\nBuscar penultimo dado da lista: " << lista.BuscarDado(3) << endl;

    cout << "\n Teste remoção: " << endl;

    cout << "\n Tamanho antes: " << lista.Tamanho() << endl; 

    lista.Remover(4);

    cout << "\n Tamanho depois: " << lista.Tamanho() << endl; 

    cout << "\nListagem:" << endl;

    lista.Inverter();

    lista.ListarDados();

    cout << "\nCalda: " << lista.Calda() << endl;


    return 0;
}