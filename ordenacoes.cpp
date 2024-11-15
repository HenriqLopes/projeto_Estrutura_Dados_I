#include "ordenacoes.h"

/*
Selection Sort
Insertion-Sort
Bubble-Sort
Shell-Sort
Quick-Sort
Merge Sort
*/

void print_list(Node* head) {
    /*Node* aux = head;
    cout << aux->data;
    print_list(aux);*/
    for(int i = 0; i < TAMANHO; i++){
        cout << head->data;
        head = head->next;
    }
}

// Função para trocar entre os tipos de ordenações
void switch_sort (int option_chosen, Node* head, Node* tail)
{

    switch (option_chosen) 
    {
        case 3:
            selection_sort (head);
            break;
        case 4:
            //insertion_sort ();
            break;
        case 5:
            //bubble_sort    ();
            break;
        case 6:
            //shell_sort     ();
            break;
        case 7:
            //quick_sort     ();
            break;
        case 8:
            //merge_sort     ();
            break;
        default:
            break;
    }
    print_list(head);
}


void selection_sort (Node* head) 
{
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
        int aux;
        aux = head->data;
        head->data = min_value->data;
        min_value->data = aux;
    }

    selection_sort(head->next);
}


int main () 
{
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    main_flux ();
    return 0;
}