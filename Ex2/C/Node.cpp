//Classes nós com o dado e o ponteiro do anterios e proximo

//T é um elemento generico, ou seja a variavel aceita qualque tipo de dado
template <typename T>
class Node{
    public:

        T dado;
        T prioridade;

        //Antes e Depois derivam da mesma classe, logo também tem um antes e depois e podem ser utilizados para guardar nós
        Node* before;
        Node* next;

        

        Node(T elemento){
            dado = elemento;
            before = nullptr;
            next = nullptr;
        }

        Node(T elemento, T prioridade){
            dado = elemento;
            this->prioridade = prioridade;
            before = nullptr;
            next = nullptr;
        }
    ;
};