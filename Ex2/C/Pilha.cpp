#include "Node.cpp"
#include <iostream>

//template <typename T>  é um elemento generico, ou seja a variavel aceita qualque tipo de dado podendo ser classes
template <typename T>

class Pilha{

    /* nesse codigo utilizamos dois tipos de nós um para todos os valores e outra para os menores
        isso é feito para a função mim ser a mais rapida possivel e devolver o menor valor da pilha
        então apesar de ser uma pilha na verdade funciona como duas, pois quando toda vez que um novo 
        valor for o novo menor ele será o novo "Mim" e o seu proximo será o antigo e só será deletado
        o topo de mim quando topo do total for igual ao topo de todos
    */


    //Cria dois nós um para topo e outra para o topo dos menores
    private:
        Node<T>* top;
        Node<T>* mim;
        int tamanho;

    ;


    public:

       Pilha(){
            top = nullptr;
            mim = nullptr;
            tamanho = 0;
    

       } 
        // Adiciona dado ao topo da pilha
       void Push(T elemento){

            //Cria um novo nó 
            Node<T>* novoNode = new Node<T>(elemento);

            //O novo nó recebe o Topo como proximo
            novoNode->next = top;
            
            //O novo nó vira o topo
            top = novoNode;
            
            tamanho++;

            //Se não houver um menor ou se o menor for maior cria-se um novo nó para os menores
            if(mim == nullptr || mim->dado >= elemento){
                    
                    Node<T>* novoMenor = new Node<T>(elemento);
                    novoMenor->next = mim;
                    mim = novoMenor;

            }
  
            
       }

        //Deleta o nó do topo
       void Pop(){

            //Verifica se existe um topo
            if(top){

                //Verifica se o valor do topo é igual ao menor e o deletará pois significa que o menor é o topo são iguais logo será deletado
                if( mim->dado == top->dado){
                    
                    //Cria uma copia para mudar o mim para o seu proximo e deletar o antigo
                    Node<T>* temporario = mim;
                    mim = mim->next;
                    delete temporario;
                }

                Node<T>* temporario = top;
                top = top->next;
                delete temporario;

                tamanho--;

            }
 
       }

        //Devolve o valor de Top
       T Top(){
            if(top){
                return top->dado;
            }
            else{
                return T();
            }
            
      
       }

        //Devolve o valor de Mim(Menor valor)
       T Mim(){
            if(mim != nullptr){
                return mim->dado;
            }
            else{
                return T();
            }
       }

        //Mostra o tamanho da pilha
        int Tamanho(){
            return tamanho;
        }
        
        //Verifica se está vazia a pilha;
        //vazio = verdadeiro
        //não vazio = falso
        bool Vazio(){
            return tamanho == 0;
        }

    ;


};