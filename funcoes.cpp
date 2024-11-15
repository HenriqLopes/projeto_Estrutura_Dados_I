#include "ordenacoes.h"

// Limpa o terminal, levando em consideração o sistema operacional sendo utilizado 
void clear () 
{
    //Verifica qual é o S.O. para limpar o terminal com o comando compatível
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux && mac
    #endif
}

// Cria um nó da struct e o preenche com um número aleatório
void createNode(Node** head, Node** tail) 
{
    Node* newNode = new Node;
    newNode->data = gen_random();
    newNode->next = nullptr;
    
    if(*tail == nullptr) // Se for o primeiro, preenche o início e fim com o novo nó
    { 
        newNode->previous = nullptr;
        *head = newNode;
        *tail = newNode;
    }
    else 
    {
        newNode->previous = *tail; // Se não for o primeiro, a cauda vira o novo nó criado
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

// Gera número aleatório entre 1 e 10
int gen_random() 
{
    return (1 + rand() % 10);
}

// Recebe escolha de ordenação que o usuário deseja fazer
void receive_choice (int* option_chosen) 
{ 
    cout << "1 - Inserir um elemento novo"     << endl;
    cout << "2 - Remover um elemento da lista" << endl;
    cout << "3 - Selection Sort" << endl;
    cout << "4 - Insertion-Sort" << endl;
    cout << "5 - Bubble-Sort"    << endl;
    cout << "6 - Shell-Sort"     << endl;
    cout << "7 - Quick-Sort"     << endl;
    cout << "8 - Merge-Sort"     << endl;
    cout << "9 - Finalizar"      << endl;
    cin >> *option_chosen;
    
    while(*option_chosen < 1 || *option_chosen > 9)
    {
        cout << "Opção inválida!" << endl;
        cout << "Escolha um valor entre 1 e 9!" << endl;
        cin >> *option_chosen;
        clear();
    }
}

void main_flux () 
{ 
    int option_chosen = -1;
    Node* head = nullptr;
    Node* tail = nullptr;
    
    while(option_chosen != 9)
    {
        receive_choice (&option_chosen);
        switch_sort (option_chosen, head, tail);
    }
}