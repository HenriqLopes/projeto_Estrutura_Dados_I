#ifndef ORDENACOES_H
#define ORDENACOES_H

#include <iostream>
#include <cstdlib>
#include <ctime>

const int TAMANHO = 10;

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* previous;
};

// Funções
void print_list(Node* head);
void clear();
int gen_random();
void createNode(Node*& head, Node*& tail);
void fill_list(Node*& head, Node*& tail, int size_list);
void free_list(Node* head);
void insertNode(Node** head, Node** tail);

void main_flux();
void receive_choice(int* option_chosen);
void switch_sort(int option_chosen, Node*& head, Node*& tail);

// Ordenações
void selection_sort(Node* head);

#endif
