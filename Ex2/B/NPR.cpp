#include "Pilha.cpp"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

//Metodo para calcular o resultados

//Recebe o valor do topo( valor A mas que é o segundo) e o segundo depois(valor B mas é o primeiro da operação) mais o operador
string Calcular(string valorA, string ValorB, char operador){
    
    //Converte para double
    double doubleA = stod(valorA);
    double doubleB = stod(ValorB);

    //Verifica o operador  e devolve o resultado da operação
    if(operador == '+'){

        //Devido ao topo ser o segundo valor invertemos o A e B
        return to_string(doubleB+doubleA);
    }
    if(operador == '-'){
        return to_string(doubleB-doubleA);

    }
    if(operador == '*'){
        return to_string(doubleB*doubleA);

    }
    else{
        return to_string(doubleB/doubleA);

    }
}

//Verifica se o char é um operador
bool VerificarOperador(char operador){

    return operador == '+' || operador == '-' || operador == '*' || operador == '/';

}

//Calcula e valida a expreção NPR
double CalcularNPR(string exprecao){

    //Cria pilha
    Pilha<string> pilha;

    //Variavel que guarda um numero em string
    string valor = "";

    //Loop que lê a expreção
    for(char c: exprecao){
        
        // Verifica se o char é um espaço(Pois acabou o numero) ou se é um operador(Mesmo motivo)
        if(c == ' ' || VerificarOperador(c)){

            // Se tiver nada
           if(valor != ""){
            
                pilha.Push(valor);
                valor = "";

           }
            
        }

        else{
            if(isdigit(c)){
                valor += c;

            }
            else{
                if(c == ' '){
                    continue;
                }
                cout << "Operacao invalida, ha caracteres errados" << endl;
                return -1;
            }
        }

        if(VerificarOperador(c)){
            char operador = c;
            if(pilha.Tamanho() >= 2){

                string valorA = pilha.Top();
                pilha.Pop();

                string valorB = pilha.Top();
                pilha.Pop();

                pilha.Push(Calcular(valorA, valorB, operador));

            }
            else{
                cout << "Operacao invalida, ha mais operadores do que numeros" << endl;
                return -1;

            }
        }


    }

    if(pilha.Tamanho() == 1){
        return stod(pilha.Top());

    }
    else{
        cout << "Operacao invalida, muitos numeros mas poucos operadores" << endl;

        return -1;
    }
}


