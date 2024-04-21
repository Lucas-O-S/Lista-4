#include <iostream>
#include "Validador.cpp"

using namespace std;

//Teste validador
int main(){

    string text = "(3{2+3})";

    if(Validar(text)){
        cout << "Correto";

    }

    else{
        cout << "Incorreto";

    }
}