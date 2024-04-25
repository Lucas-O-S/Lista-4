#include "Fila.cpp"
#include <iostream>

using namespace std;

//Inseri a fila o dado
void Inserir(Fila<string> &fila){
    int escolha;
    string nome, prioridade;
    cout << "Digite o nome do arquivo: ";
    cin >> nome;
    
    while(true){
        cout << "\nEscolha prioridade: \n - 1 = Baixa\n - 2 = Media\n - 3 = Alta\n";
        cout << "Escolha:";
        cin >>  escolha;
    
        switch (escolha)
        {
            case 1:
                prioridade = "1";
                fila.Inserir(nome,prioridade);

                return;
            break;
            
            case 2:
                prioridade = "2";
                fila.Inserir(nome,prioridade);

                return;

            break;

            case 3:
        
                prioridade = "3";
                fila.Inserir(nome,prioridade);

                return;
            break;

            default:
                cout << "\n Valor invalido \n";
            break;
        }

        fila.Inserir(nome,prioridade);
                
    }
}


//Retira da fila o dado
void imprimir(Fila<string> &fila){
    cout<< "\nArquivo: " << fila.Consulta() << " foi impresso" << endl;
    fila.Remover();
}

// Mostra o proximo da lista
void VerificarProximo(Fila<string> &fila){
    cout<< "\nArquivo: " << fila.Consulta() << " é o proximo da fila" << endl;
}

//Vê todos os dados da fila já concluidos
void VerConcluidos(Fila<string> &fila){
    fila.ListarConcluidos();
}


int main(){

    Fila<string> fila;
    string nome, prioridade;


    cout << "- Fila de Impressão:";

    int escolha;

    while (true)
    {
        cout << "\n    1 - inserir no elemento \n    2 - Imprimir elemento \n    3 - Verificar Proximo Elemento \n    4 - Ver elementos impressos \n    5 - finalizar" << endl;
        cout << "Escolha:";
        cin >> escolha;
        cout << "\n";
        switch (escolha)
        {
            case 1:
                Inserir(fila);
            break;

            case 2:
                imprimir(fila);

            break;

            case 3:

                 VerificarProximo(fila);

            break;

            case 4:
                VerConcluidos(fila);

            break;

            case 5:

                cout << "\n Programa finalizado" << endl;
                return 0;

            break;

            default:

                cout << "Escolha Invalida";
            break;
        }
    }
    


    return 0;
}