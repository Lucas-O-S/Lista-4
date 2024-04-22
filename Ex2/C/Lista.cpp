#include "Node.cpp"
#include <iostream>

using namespace std;

template <typename T>

//Cria uma lista duplamente encadeada
class Lista{

    //Cria os nos da calda e cabeça mais o tamanho da lista
    private:
        Node<T>* cabeca;
        Node<T>* calda;
        int tamanho;

    ;

    public:

        //Da valores iniciais a eles
        Lista(){
            cabeca = nullptr;
            calda = nullptr;
            tamanho = 0;
        }

        //Inseri o valor a lista
        void Inserir(T elemento){

            //Cria um nó novo
            Node<T>* novoNode = new Node<T>(elemento);
            novoNode->dado = elemento;

            //Se não haver cabeça ele é a cabeça e calda
            if(!cabeca){
                cabeca = novoNode;
                calda = novoNode;
            }

            //Se não ele vira calda e recebe uma conexão a calda antiga
            else{
                calda->next = novoNode;
                novoNode->before = calda;
                calda = novoNode;
            }

            //Almente o tamanho da lista
            tamanho++;

        }

        //Remove um valor na lista
        void Remover(int indice){
            
            //Verifica se existe cabeça e se o indice buscado existe 
            if(cabeca && indice <= tamanho){
                int posicaoAtual = 0;
                Node<T>* nodeAtual = cabeca;

                //Enquanto tiver um node ele repete
                while(nodeAtual){
                    
                    //Se for achado o indice ele o retira
                    if(posicaoAtual = indice){
                        
                        //troca a conexão do proximo para o anterior ao atual
                        if(nodeAtual->next){
                            nodeAtual->next->before = nodeAtual->before;
                        }
                        //Se for a calda só muda a calda para o anterior
                        else{
                            calda = nodeAtual->before;
                        }

                        //Troca a conexão do anterior para o proximo ao atual
                        if(nodeAtual->before){
                            nodeAtual->before->next = nodeAtual->next;

                        }

                        //Se for a cabeça o proximo vira a cabeça
                        else{
                            cabeca = nodeAtual->next;
                        }

                        //Deleta o node atual
                        delete nodeAtual;

                        //Diminui o tamanho da lista e acaba
                        tamanho--;
                        return;
                    }

                    //Muda posição
                    posicaoAtual++;

                    //Segue para o proximo
                    nodeAtual = nodeAtual->next;
                }


            }
        }


        //Inverte a lista mudando as conexões de frente para traz e vice versa
        void Inverter(){

            if(cabeca){
                Node<T>* nodeAtual = cabeca;
                Node<T>* nodeTemporario = nullptr;

                
                calda = cabeca;

                while (nodeAtual != nullptr)
                {
                    nodeTemporario = nodeAtual->before;
                    nodeAtual->before = nodeAtual->next;
                    nodeAtual->next = nodeTemporario;
                    nodeAtual = nodeAtual->before;
                }
                if (nodeTemporario != nullptr)
                {
                    cabeca = nodeTemporario->before; 
                }
                
            
        }


            }

        //Devolve o tamanho
        int Tamanho(){
            return tamanho;
        }

        //Devolve o valor da cabeça
        T Cabeca(){
            return cabeca->dado;
        }

        //Devolve o valor da calda
        T Calda(){
            return calda->dado;
        }

        //Classe iterador, é util para mexer na lista
        class Iterador{

            //cria uma cabeça, calda e nó atual
            private:
                Node<T>* cabeca;
                Node<T>* calda;
                Node<T>* nodeAtual;

            ;

            public:

                //Construtor de Iterador
                Iterador(Node<T>* cabeca, Node<T>* calda){
                    this->cabeca = cabeca;
                    this->calda = calda;
                    nodeAtual = cabeca;
                }

                //Verifica se há um proximo
                void ExisteProximo(){
                    return nodeAtual.next != nullptr;
                }

                //Verifica se há um anterior
                void ExisteAntes(){
                    return nodeAtual.before != nullptr;
                }

                //coloca o nó atual como cabeça
                void ComecarCabeca(){
                    nodeAtual = cabeca;
                }

                //coloca o nó atual como calda
                void ComecarCalda(){
                    nodeAtual = calda;
                }

                //Segue para o proximo nó
                void Proximo(){
                    if(nodeAtual->next != nullptr){
                        nodeAtual = nodeAtual->next;
                    }               
                }

                //Mostra o dado do nó
                T MostrarDado(){
                    return nodeAtual->dado;
                }

                //Segue para o nó anterior
                void Anterior(){

                    if(nodeAtual->before != nullptr){
                        nodeAtual = nodeAtual->before;
                    }
                }

            
            ;
        };

        //Cria um iterador
        Iterador CriarIterador(){
            return Iterador(cabeca,calda);
        }

        //Lista todos o dados da lista
        void ListarDados(){

            //Cria um iterador
            Iterador it = CriarIterador();

            //começa da cabeça
            it.ComecarCabeca();

            //loop para mostrar todos os dados
            for(int i = 0; i < tamanho; i++)
            {
                cout << it.MostrarDado() << " ";
                
                //Segue para o proximo dados
                it.Proximo();

            };
            
        }

        //Mesma coisa do anterior só que começa da calda e vai para a cabeça
       void ListarDadosInverso(){
            Iterador it = CriarIterador();

            it.ComecarCalda();

            for(int i = 0; i < tamanho; i++)
            {
                cout << it.MostrarDado() << " ";

                it.Anterior();

            };
            
        }

        //busca dado em um indice
        T BuscarDado(int indice){

            //Verifica se o indice existe e a cabeça também
            if(cabeca && indice <= tamanho){
                int indiceAtual;
                
                //Cria um iterador
                Iterador it = CriarIterador();

                //Para acelerar a procura decidimos se iremos em ordem ou ordem oposta
                bool emOrdem;
                
                //Se indice é menor ou igual a metade do tamanho iremos em ordem
                if(indice <= tamanho/2 ){
                    emOrdem = true;
                    indiceAtual = 0;
                    it.ComecarCabeca();

                }
            
                else{
                    emOrdem = false;
                    indiceAtual = tamanho-1;
                    it.ComecarCalda();
                }

                //Loop de procura
                while (indiceAtual != indice){
                    
                    //Procura em ordem
                    if(emOrdem){
                        it.Proximo();
                        indiceAtual++;

                    }

                    //Procura em ordem oposta
                    else{
                         it.Anterior();
                        indiceAtual--;
                    }

                }
                return it.MostrarDado(); 
            }
            
            // Se der erro
            else{
                return T();
            }

        }

    ;


};

