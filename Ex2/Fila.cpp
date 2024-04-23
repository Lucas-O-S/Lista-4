#include "Pilha.cpp"
#include "Lista.cpp"

template <typename T>


class Fila{

    private:


        //Cria duas pilhas

        //Entrada serve para que o valor de topo seja o ultimo a entrar
        Pilha<T> entrada;

        //Saida serve para o primeira a entrar ficar no topo
        Pilha<T> saida;

        Lista<T> concluidos;
        
        //Pega os valores da entrada e adiciona a saida(O primeiro a entrar fica no topo)
        void Desenfileirar(){

            while(entrada.TopDado() != T()){
                
                saida.push(entrada.TopDado(), entrada.TopPrioridade());

                entrada.pop();

            }

        
        }

        //Pega os valores da saida e coloca no entrada(O ultimo a entrar fica no topo)
        void Enfileirar(){
            
            
            while(saida.TopDado() != T()){
    
                T prioridadeAtual = saida.TopDado();
                entrada.push(saida.TopDado(),saida.TopPrioridade());
                saida.pop();

            }

                
        }

        void Desenfileirar(T prioridade){
            
            
            while(entrada.TopDado() != T()){
                
                if(prioridade <= entrada.TopPrioridade()){
                    return;
                }
                T prioridadeAtual = saida.TopDado();
                saida.push(entrada.TopDado(),entrada.TopPrioridade());
                entrada.pop();

            }

                
        }


    ;

    public:


        //Coloca o ultimo do topo e adciona um novo elemento ao topo
        void Inserir(T elemento, T prioridade){

            if(entrada.TopDado() != T()){

                Desenfileirar(prioridade);

                
            }
            entrada.push(elemento,prioridade);

            Enfileirar();
            

        }

        //Coloca o primeiro a entrar no topo e tira ele
        void Remover(){
            Desenfileirar();
            concluidos.Inserir(saida.TopDado());
            saida.pop();

        }

        //Coloca o primeiro a entrar no topo e devolve o seu valor
        T Consulta(){
            Desenfileirar();

            return saida.TopDado();
        }

        void ListarConcluidos(){
            concluidos.ListarDados();
        }


    ;



};