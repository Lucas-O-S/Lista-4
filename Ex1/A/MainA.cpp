#include <iostream>
#include "Lista2Encadeada.cpp"

using namespace std;

//Mostra Lista da cabeça a calda
void MostrarLista(ListaDuplamenteEncadeada lista){
    
    ListaDuplamenteEncadeada::Iterador it = lista.iterador();

    //Iterador
    it.IniciarInicioParaFIm();

    while (it.VerifcarProximo())
    {
        cout << it.Proximo() << " ";
    }
}

//Mostra a lista ao contrario
void MostrarListaOposto(ListaDuplamenteEncadeada lista){
    
    ListaDuplamenteEncadeada::Iterador it = lista.iterador();

    //Iterador
    it.IniciarFimParainicio();

    while (it.VerificarAntes())
    {
        cout << it.Anterior() << " ";
    }
}

//Teste Lista duplamente encadeada
int main(){

    //Criação
    ListaDuplamenteEncadeada lista;

    //Adição
    lista.inserirElementos(2);
    lista.inserirElementos(32);
    lista.inserirElementos(30);

    //Teste iterador
    MostrarLista(lista);
    
    //Teste Remover
    lista.Remover(1);

    cout << endl;
    
    //Teste iterador Mostrar lista da calda para cabeça
    MostrarListaOposto(lista);
    
    cout << endl;

    //Teste inverter Lista
    lista.InverterLista();

    //Verificar se lista foi invertida(Se for igual ao iterador invertido deu certo)
    MostrarLista(lista);



    return 0;
}
