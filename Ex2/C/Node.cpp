//Classes nós com o dado e o ponteiro do anterios e proximo

//T é um elemento generico, ou seja a variavel aceita qualque tipo de dado
template <typename T>
class Node{
    public:

        T dado;

        //Antes e Depois derivam da mesma classe, logo também tem um antes e depois e podem ser utilizados para guardar nós
        Node* before;
        Node* next;

        Node(T elemento){
            dado = elemento;
            before = nullptr;
            next = nullptr;
        }
    ;
};