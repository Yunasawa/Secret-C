#include <stdio.h>
#include <stdlib.h>

#pragma region Structs
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct List
{
    struct Node *node;
} List;
#pragma endregion

#pragma region Functions
void AddLast(List *list, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->node == NULL) 
    {
        list->node = new_node;
    } 
    else 
    {
        Node* current = list->node;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = new_node;
    }
}
void AddFirst(List *list, int data)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->node;
    list->node = new_node;
}
void Remove(List *list, int data) 
{
    Node *current = list->node;
    Node *previous = NULL;

    while (current != NULL) 
    {
        if (current->data == data) 
        {
            if (previous == NULL) 
            {
                list->node = current->next;
            } 
            else 
            {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

int Count(List *list)
{
    int count = 0;
    Node *temp = list->node;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void Reverse(List *list)
{
    if (list->node == NULL)
        return;
    Node *temp = list->node;
    list->node = list->node->next;
    Reverse(list);
    AddLast(list, temp->data);
}
void Distinct(List* list) 
{
    Node* current = list->node;
    while (current != NULL) 
    {
        Node* runner = current;
        while (runner->next != NULL) 
        {
            if (runner->next->data == current->data) 
            {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } 
            else 
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}
void Sort(List* list)
{
    Node *i, *j, *temp;
    for (i = list->node; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = (Node*)malloc(sizeof(Node));
                temp->data = i->data;
                i->data = j->data;
                j->data = temp->data;
                free(temp);
            }
        }
    }
}
int Get(List* list, int index) 
{
    Node* current = list->node;
    int count = 0;
    while (current != NULL) 
    {
        if (count == index) 
        {
            return current->data;
        }
        count++;
        current = current->next;
    }
    return -1;
}
int Contains(List* list, int value) 
{
    Node* current = list->node;
    while (current != NULL) 
    {
        if (current->data == value) 
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
int IndexOf(List* list, int value) 
{
    Node* current = list->node;
    int index = 0;
    while (current != NULL) 
    {
        if (current->data == value) 
        {
            return index;
        }
        index++;
        current = current->next;
    }
    return -1; // Value not found
}
int Find(List* list, int (*condition)(int)) 
{
    Node* current = list->node;
    int index = 0;
    while (current != NULL) 
    {
        if (condition(current->data)) 
        {
            return index;
        }
        index++;
        current = current->next;
    }
    return -1; // Value not found
}

void PrintList(List* list) 
{
    Node* current = list->node;
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
}
void FreeList(List* list) 
{
    Node* current = list->node;
    while (current != NULL) 
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

#pragma endregion