#include "Pilha.cpp"
#include <iostream>

using namespace std;


//Filtro que deixa somente delimitadores passarem
string FiltrarDelimitadores(string texto){
    string textoFIltrado = "";

    //Enquanto haver char na string ele fara rodar o loop
    for(char c: texto){
        //se o c for um delimitador ele adicionará a o resultado
        if(c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}'){
            textoFIltrado += c;
        }
    }


    return textoFIltrado;
}

//Devolve se a expressão é valida
bool Validar(string texto){

    //Filtra os delimitadores
    texto = FiltrarDelimitadores(texto);

    //Cria uma pilha
    Pilha<char> pilha;

    //Roda o loop até terminar o tamanho do texto
    for(char c: texto){

        //Se tiver um abrir delimitador ele adiciona a pilha
        if(c == '(' || c == '[' || c == '{'){
            pilha.Push(c);

        }

        //Se for um fechar delimitador
        else{
            
            //Se o fechar delimitador não tiver alguem para comparar da erro
            if(pilha.Vazio()){

               return false; 
            }
            else{
                
                //Se haver o fechar delimitador não tiver o seu correspondente de abrir na pilha da erro
                if(pilha.Top() == '(' && c != ')'){
                    return false;
                }
                if(pilha.Top() == '[' && c != ']'){
                    return false;
                }
               if(pilha.Top() == '{' && c != '}'){
                    return false;
                }
            }

            //Se passar no teste tira o topo da pilha
            pilha.Pop();

        }
    }

    //Ao terminar o loop verifica se está vazio e devolve true
    return pilha.Vazio();

}


