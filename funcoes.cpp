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

void free_list(Node* head) 
{
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Gera número aleatório entre 1 e 30
int gen_random() 
{
    return (1 + rand() % 30);
}

// Cria um nó da struct e o preenche com um número aleatório
void createNode(Node* head, Node* tail) 
{
    Node* newNode = new Node;
    newNode->data = gen_random();
    newNode->next = nullptr;

    if (tail == nullptr) // Se a lista estiver vazia
    {
        newNode->previous = nullptr;
        head = newNode;
        tail = newNode;
    }
    else // Insere no final
    {
        newNode->previous = tail;
        (tail)->next = newNode;
        tail = newNode;
    }
}

/*void createNode(Node** head, Node** tail) 
{
    Node* newNode = new Node;
    newNode->data = gen_random();
    newNode->next = nullptr;

    if (*tail == nullptr) // Se a lista estiver vazia
    {
        newNode->previous = nullptr;
        *head = newNode;
        *tail = newNode;
    }
    else // Insere no final
    {
        newNode->previous = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}*/

void fill_list(Node* head, Node* tail, int size_list)
{

    for(int i = 0; i < size_list; i++) 
    {
        createNode(&head, &tail);
    }

}

void print_list(Node* head) 
{
    if (head == nullptr) 
    {
        cout << "Lista vazia." << endl;
        return;
    }

    for (int i = 0; i < TAMANHO && head != nullptr; i++) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Recebe escolha de ordenação que o usuário deseja fazer
void receive_choice (int* option_chosen) 
{ 
    cout << "1 - Abrir um arquivo" << endl; 
    cout << "2 - Digitar e inserir um elemento novo"     << endl;
    cout << "3 - Preencher a lista com valores aleatórios" << endl;
    cout << "4 - Remover um elemento da lista" << endl;
    cout << "5 - Selection Sort" << endl;
    cout << "6 - Insertion-Sort" << endl;
    cout << "7 - Bubble-Sort"    << endl;
    cout << "8 - Shell-Sort"     << endl;
    cout << "9 - Quick-Sort"     << endl;
    cout << "10 - Merge-Sort"     << endl;
    cout << "11 - Finalizar"      << endl;
    cin >> *option_chosen;
    
    while(*option_chosen < 1 || *option_chosen > 11)
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
    
    while(option_chosen != 11)
    {
        receive_choice (&option_chosen);
        switch_sort (option_chosen, head, tail);
    }

    free_list(head);
}