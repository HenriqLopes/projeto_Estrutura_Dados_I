// Arquivo de cabeçalho para as funções e constantes

#ifndef ORDENACOES_H
#define ORDENACOES_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Declaração da quantidade de pauzinhos que podem ser retirados
const int TAMANHO = 10;

struct Node {
    int data;
    Node* next;
    Node* previous;
};

// Funções
void print_list(Node* head);
void clear ();
void createNode (Node** head, Node** tail);
int gen_random ();
void insertNode (Node** head, Node** tail);

void main_flux ();
void receive_choice (int* option_chosen);
void switch_sort (int option_chosen, Node* head, Node* tail);

// Ordenações
void selection_sort (Node* head);

#endif 