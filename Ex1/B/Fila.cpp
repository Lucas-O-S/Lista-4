#include "Pilha.cpp"

template <typename T>


class Fila{

    private:

        //Cria duas pilhas

        //Entrada serve para que o valor de topo seja o ultimo a entrar
        Pilha<T> entrada;

        //Saida serve para o primeira a entrar ficar no topo
        Pilha<T> saida;
        
        //Pega os valores da entrada e adiciona a saida(O primeiro a entrar fica no topo)
        void Desenfileirar(){

            while(entrada.Top() != T()){
                saida.push(entrada.Top());

                entrada.pop();

            }

        
        }

        //Pega os valores da saida e coloca no entrada(O ultimo a entrar fica no topo)
        void Enfileirar(){
            
            
            while(saida.Top() != T()){
        
                entrada.push(saida.Top());
                saida.pop();

            }

                
        }


    ;

    public:


        //Coloca o ultimo do topo e adciona um novo elemento ao topo
        void Inserir(T elemento){
            
            Enfileirar();
            
            entrada.push(elemento);

        }

        //Coloca o primeiro a entrar no topo e tira ele
        void Remover(){
            Desenfileirar();
            saida.pop();

        }

        //Coloca o primeiro a entrar no topo e devolve o seu valor
        T Consulta(){
            Desenfileirar();

            return saida.Top();
        }


    ;



};