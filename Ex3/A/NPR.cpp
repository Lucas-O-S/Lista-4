#include "Pilha.cpp"
#include <iostream>
#include <cctype>
#include <string>
#include <math.h>
using namespace std;

class NPR{
    private:

        //Recebe o valor do topo( valor A mas que é o segundo) e o segundo depois(valor B mas é o primeiro da operação) mais o operador
        static string Calcular(string valorA, string ValorB, char operador){
            
            //Converte para double
            double doubleA = stod(valorA);
            double doubleB = stod(ValorB);

            //Verifica o operador  e devolve o resultado da operação
            if(operador == '+'){

                //Devido ao topo ser o segundo valor invertemos o A e B
                return to_string(doubleB+doubleA);
            }
            else if(operador == '-'){
                return to_string(doubleB-doubleA);

            }
            else if(operador == '*'){
                return to_string(doubleB*doubleA);

            }
            else if(operador == '/'){
                return to_string(doubleB/doubleA);
            }
            else{
                return to_string(pow(doubleB, doubleA));

            }
        }


        //Verifica se o char é um operador
        static bool VerificarOperador(char operador){

            return operador == '+' || operador == '-' || operador == '*' || operador == '/';

        }

        //Devolve o nivel de importancia do operador
        static int NivelOperador(char operador){
            switch(operador){
                case '+':
                case '-': return 1;
                case '*':
                case '/': return 2;
                case '^': return 3;
                default: return -1;
            }

        }

        //Devolve se é um delimitador o char
        static bool VerificarDelimitador(char c){
            return c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
        }


        //Filtro que deixa somente delimitadores passarem
        static string FiltrarDelimitadores(string texto){
            string textoFIltrado = "";

            //Enquanto haver char na string ele fara rodar o loop
            for(char c: texto){
                //se o c for um delimitador ele adicionará a o resultado
                if(VerificarDelimitador(c)){
                    textoFIltrado += c;
                }
            }


            return textoFIltrado;
        }
    ;

    public:

        //Metodo para calcular o resultados



        //Calcula e valida a expreção NPR
        static double CalcularNPR(string exprecao){

            //Cria pilha
            Pilha<string> pilha;

            //Variavel que guarda um numero em string
            string valor = "";

            //Loop que lê a expreção
            for(char c: exprecao){
                
                // Verifica se o char é um espaço(Pois acabou o numero) ou se é um operador(Mesmo motivo)
                if(c == ' ' || VerificarOperador(c)){

                    // Se tiver nada no valor não adiciona a pilha(Evita adicionar espeços) caso sim adiciona o valor a pilha e o limpa 
                if(valor != ""){
                    
                        pilha.Push(valor);
                        valor = "";

                }
                    
                }

                //Se não for um espaço ou operador verifica se é um numero
                else{
                    
                    //Se for numero soma a valor
                    if(isdigit(c)){
                        valor += c;

                    }

                    //se não verifica se é espaço, caso não seja numero ou espaço tá errada a expreção
                    else{
                        if(c == ' '){
                            continue;
                        }
                        cout << "Operacao invalida, ha caracteres errados" << endl;
                        return -1;
                    }
                }

                //Verifica se é um operador char atual
                if(VerificarOperador(c)){
                    
                    //Se pilha tiver numeros suficientes para a operação segue normalmente
                    if(pilha.Tamanho() >= 2){

                        //Para calcular NPR tiramos os dois numeros do topo da pilha e fazemos a primeira operação pedida antes dos numero
                        string valorA = pilha.Top();
                        pilha.Pop();

                        string valorB = pilha.Top();
                        pilha.Pop();

                        //E colocamos de volta o resultado no topo
                        pilha.Push(Calcular(valorA, valorB, c));

                    }

                    //Se não tiver no minimo 2 numeros na pilha não pode ser feita a operação
                    else{
                        cout << "Operacao invalida, ha mais operadores do que numeros" << endl;
                        return -1;

                    }
                }


            }

            // no final da operação deve haver apenas o resultado no topo se não há algo errado
            if(pilha.Tamanho() == 1){
                return stod(pilha.Top());

            }
            else{
                cout << "Operacao invalida, Quantidade insuficiente" << endl;

                return -1;
            }
        }





        //Devolve se a expressão é valida em relação aos delimitadores
        static bool ValidarDelimitadores(string texto){

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

        //Converte infixo para pós fixo
        static string ConverterNPR(string expressao){
            Pilha<char> pilha;

            //Reusltado
            string resposta = "";

            //Loop de repetição
            for(char c: expressao){
                

                //Se for digito adiciona a respota
                if(isdigit(c)){
                    resposta += c;

                }

                //Se for delimitador de abertura adiciona a fila se for de fechar adiciona a respota todos os digitos a resposta
                else if(VerificarDelimitador(c)){

                    if(c == ')'|| c == ']' || c== '}' ){
                        while(isdigit(pilha.Top())){
                            resposta += pilha.Top();
                            pilha.Pop();
                        }
                    }
                    else{
                        pilha.Push(c);

                    }
                }

                //Se for um operador descarrega a pilha na resposta até acabar ou encontrar um delimitador de abertura ou encontrar um operador de maior valor
                else if(VerificarOperador(c)){

                    resposta += " ";

                    while (true )
                    {

                        if(pilha.Vazio() || VerificarDelimitador(pilha.Top())  || NivelOperador(pilha.Top() < NivelOperador(c))){
                            
               
                            break;
                        }

                         if(!VerificarDelimitador(pilha.Top())){

                                resposta += pilha.Top();

                         }
                        pilha.Pop();




                    }                            
                    pilha.Push(c);

                    

                }

                else{
                    return "Erro, expressão invalida";
                }


            }

            while (!pilha.Vazio()) {
                if(VerificarDelimitador(pilha.Top())){
                    pilha.Pop();
                    continue;

                }
                resposta += pilha.Top();
                pilha.Pop();
            }


            return resposta;

        }
    ;
};
