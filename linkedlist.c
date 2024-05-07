#include "linkedlist.h"

void insertAtBeginning(address *head_ref, address *tail, char new_data)
{
    address newNode = (address)malloc(sizeof(Linked));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->info = new_data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        *tail = newNode; // Perbaikan: ganti - menjadi =
        return;
    }

    (*head_ref)->prev = newNode; // Perbaikan: tetapkan prev dari node berikutnya
    newNode->next = *head_ref;
    *head_ref = newNode;
}

//void insertAtBeginning(address *head_ref, char new_data) {
//    address new_node = (address)malloc(sizeof(Linked));
//    new_node->info = new_data;
//    new_node->next = *head_ref;
//    *head_ref = new_node;
//}
// Fungsi untuk menambahkan node baru di tengah linked list
void insertAfter(address prev_node, char new_data)
{
    if (prev_node == NULL)
    {
        printf("Node sebelumnya tidak boleh NULL");
        return;
    }
    address new_node = (address)malloc(sizeof(Linked));
    new_node->info = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// Fungsi untuk menambahkan node baru di akhir linked list
void insertAtEnd(address *head_ref, address *tail, char new_data) {
    // Alokasi memori untuk node baru
    address newNode = (address)malloc(sizeof(Linked));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Mengatur data node baru
    newNode->info = new_data;
    newNode->next = NULL;

    // Jika linked list kosong, node baru menjadi head dan tail
    if (*head_ref == NULL) {
        newNode->prev = NULL;
        *head_ref = newNode;
        *tail = newNode; // Perbarui tail untuk menunjuk ke node baru
        return;
    }

    // Jika tidak, cari node terakhir dan tambahkan node baru setelahnya
    address lastNode = *head_ref;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
    *tail = newNode; // Perbarui tail untuk menunjuk ke node baru
}


void printList(address node)
{
    while (node != NULL)
    {
        printf("%c ", node->info);
        node = node->next;
    }
}

char *convertLinkedToString(address head_ref)
{
    address pNode;
    char *Result;
    int i;

    i = 0;
    pNode = head_ref;
    while (pNode != NULL)
    {
        Result[i] = pNode->info;
        pNode = pNode->next;
        i++;
    }

    return *Result;
}
