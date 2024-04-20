#include <iostream>

using namespace std;

//Classes nós com o dado e o ponteiro do anterios e proximo
class Nos{
    public:

        int dado;

        //Antes e Depois derivam da mesma classe, logo também tem um antes e depois e podem ser utilizados para guardar nós
        Nos* antes;
        Nos* depois;

        Nos(int elemento){
            dado = elemento;
            antes = nullptr;
            depois = nullptr;
        }
    ;
};




class ListaDuplamenteEncadeada{

    private:

        //Cria a cabeça e a calda da lista
        Nos* cabeca;
        Nos* calda;

    ;

    public:

        ListaDuplamenteEncadeada(){
            cabeca = nullptr;
            calda = nullptr;
        }

        void inserirElementos(int elemento){
            Nos* novoNo = new Nos(elemento);

            //Quando a lista tá vazia o primeiro elemento(Novo Nó) vira a cabeça e a calda
            if(!cabeca){
                cabeca = novoNo;
                calda = novoNo;
            }

            //
            else{
                
                //O ultimo elemento da lista que é a calda recebe o novo nó como proximo
                calda->depois = novoNo;
                
                //O novo elemento recebe a calda antiga como anterior
                novoNo->antes = calda;
                
                //o novo elemento é a calda agora
                calda = novoNo;            
            }
        }


        void Remover(int indice){
            
            //A partir da cabeça procura o indice escolhido
            int posicaoAtual = 0;

            Nos* noAtual = cabeca;

            //Verifica se em cada iteração o pontero do nó do indice atual é nulo, para se for
            //Enquanto ponteiro não nulo não parar
            while(noAtual){

                //Verifica se achou o nó do indice
                if(indice == posicaoAtual ){
                    
                    //VÊ de há um no antes do atual
                    if(noAtual->antes){

                        //Pegamos nó anterior ao atual e colocamos o seu proximo como o proximo do atual assim pulando o atual
                        noAtual->antes->depois = noAtual->depois;
                    }

                    //Se não há nada antes do nó atual ele é a cabeça, então o proximo ao atual vira a cabeça
                    else{
                        cabeca = noAtual->depois;
                    }

                    //Verifica se há um nó anterior
                    if(noAtual->depois){

                        //Pega o nó seguinte ao atual e troca o ponteiro do anterior do proximo para o anterior do nó atual ignorando o atual
                        noAtual->depois->antes = noAtual->antes;
                    }
                    
                    //Se há ninguem depois ele é a calda, logo é só trocar o atual(calda antiga) para o anterior ao atual(calda nova)
                    else{
                        calda = noAtual->antes;
                    }

                    //Deleta completamente nó atual
                    delete noAtual;

                    //Finaliza algoritmo
                    return;

                }   

                //Indice atualizado e o nó atual vira o proximo
                posicaoAtual++;
                noAtual = noAtual->depois;
            }
        }

        void InverterLista(){
            Nos* noAtual = cabeca;
            Nos* noTemporario = nullptr;
            
            //Para inverter uma lista basta inverter a direção dos ponteiros então head vira tail e vice verça
            // Exemplo em lista encadeada:
            //     1(Head) -> 2 -> 3 -> 4(Tail)

            //     1(Tail) <- 2 <- 3 <- 4(Head) 

            //if(noAtual){
              //  calda = noAtual;
            //}

            while(noAtual != nullptr){
                noTemporario = noAtual->antes;
                noAtual->antes = noAtual->depois;          
                noAtual->depois = noTemporario;
                noAtual = noAtual->antes;      
            }

            if(noTemporario != nullptr){
                cabeca = noTemporario->antes;
            }
        }
        
        ////////////////////////////////////////////////////////////////////////////
        //Cria classe iterador dentro da classe lista
        
        //Serve para buscar dados dentro de uma lista de maneira indireta
        class Iterador{

            //Salva os dados do nó atual, cabeça e calda da lista
            private:
                Nos* noAtual;
                Nos* cabeca;
                Nos* calda;

            ;

            //Construtor do iterador
            public:
                Iterador(Nos* cabeca, Nos* calda){
                    noAtual = cabeca;
                    this->cabeca = cabeca;
                    this->calda = calda;
                }

                //Verifica se há um valor depois;
                bool VerifcarProximo(){
                    return noAtual != nullptr;
                }

                //Verifica se há valor antes
                bool VerificarAntes(){
                    return noAtual != nullptr;

                }

                //prepara o nó atual para começar da cabeça
                void IniciarInicioParaFIm(){
                    noAtual = cabeca;
                }

                //Prepara o nó atual para começar da calda
                void IniciarFimParainicio(){
                    noAtual = calda;
                }

                //Segue para o proximo nó e devolve o seu valor
                int Proximo(){
                    //Retorna o valor do nó atual e avança ele
                    int valor = noAtual->dado;
                    noAtual = noAtual->depois;
                    return valor;

                }

                //Segue para o nó anterior e devolve o seu valor
                int Anterior(){
                    int valor = noAtual->dado;
                    noAtual = noAtual->antes;
                    return valor;
                }


            ;
        };

        //Cria um iterador para a lista
        Iterador iterador(){
            return Iterador(cabeca,calda);
        }
    ;


};

