#include "ordenacoes.h"

/*
Selection Sort
Insertion-Sort
Bubble-Sort
Shell-Sort
Quick-Sort
Merge Sort
*/

// Função para trocar entre os tipos de ordenações
void switch_sort (int option_chosen, Node* head, Node* tail)
{

    cout << tail << endl;

    switch (option_chosen) 
    {
        case 3: //Mudar o lugar dessa função futuramente
            fill_list(head, tail, TAMANHO);
            break;
        case 5:
            selection_sort (head);
            break;
        case 6:
            insertion_sort ();
            break;
        case 7:
            //bubble_sort    ();
            break;
        case 8:
            //shell_sort     ();
            break;
        case 9:
            //quick_sort     ();
            break;
        case 10:
            //merge_sort     ();
            break;
        default:
            break;
    }
    print_list(head);
}

void selection_sort (Node* head) 
{
    if (head == nullptr || head->next == nullptr) 
    {
        return; // Para a recursão quando a lista estiver vazia ou no último nó
    }

    Node* min_value = head;
    Node* current = head;

    while(current != nullptr)
    {
        if(current->data < min_value->data)
        {
            min_value = current;
        }
        current = current->next;
    } 

    if(min_value != head)
    {
        int aux = head->data;
        head->data = min_value->data;
        min_value->data = aux;
    }

    selection_sort(head->next);
}

void insertion_sort (Node* head) // Verifica se o próximo é menor que o anterior
{
    if (head == nullptr || head->next == nullptr) 
    {
        return; // Lista vazia ou com um único elemento
    }

    Node *current = head->next, *trocar;

    while (current != nullptr)
    {
        int key = current->data;
        Node *previous = current->previous;

        while(previous->data > key && previous != nullptr) //Vai passando todos os números maiores para frente até achar a posição
        {
            previous->next->data = previous->data;
            previous = previous->previous;
        }

        if(previous == nullptr) // Se previous virou a última posição, quer dizer que Key é o menor número da lista
        {
            head->data = key;
        } else {
            previous->data = key;
        }
        
        current = current->next;
    }
}

void bubble_sort (Node* head)
{
    bool swaped = true;
    Node* current = head->next;
    Node* previous;
    int aux;

    while(swaped)
    {
        swaped = false;
        while(current != nullptr) 
        {
            previous = current->previous;

            if(previous->data > current->data)
            {
                aux = current->data;
                current->data = previous->data;
                previous->data = aux;
                swaped = true;
            }

            current = current->next;
        }

    }
}

int main () 
{
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    main_flux ();
    return 0;
}