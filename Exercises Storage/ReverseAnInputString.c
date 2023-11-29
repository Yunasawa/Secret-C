/* Description:
    Input a string from keyboard.
    If string is empty => Output: 1
    If string length if = 500 => Output: 2
    Else => Output: Reverse of that string

    Example: Input: Hello world => Output: dlrow olleH
*/

#include <stdio.h>
#include <stdlib.h>

#pragma region Structs
typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct Stack
{
    struct Node *node;
} Stack;
#pragma endregion

#pragma region Functions
void PushFirst(Stack *stack, char data)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = stack->node;
    stack->node = new_node;
}
void PushLast(Stack *list, char data)
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
int Pop(Stack *stack)
{
    if (stack->node == NULL) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    int data = stack->node->data;
    Node *temp = stack->node;
    stack->node = stack->node->next;
    free(temp);
    return data;
}

void InsertLast(Stack *stack, Node *item)
{
    if (stack->node == NULL)
    {
        stack->node = item;
        return;
    }
    Node *temp = stack->node;
    while (temp->next != NULL) temp = temp->next;
    temp->next = item;
}
void Reverse(Stack *stack)
{
    if (stack->node == NULL)
        return;
    Node *temp = stack->node;
    stack->node = stack->node->next;
    Reverse(stack);
    PushLast(stack, temp->data);
}
int Count(Stack *stack)
{
    int count = 0;
    Node *temp = stack->node;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}


void PrintStack(Stack* list) 
{
    Node* current = list->node;
    while (current != NULL) 
    {
        printf("%c", current->data);
        current = current->next;
    }
}

#pragma endregion

int main() 
{
  Stack string1 = {NULL};

  char input = ' ';

  input = getchar();
  while (input != '\n')
  {
    PushLast(&string1, input);
    input = getchar();
  }

  Reverse(&string1);

  if (Count(&string1) == 0) printf("1");
  if (Count(&string1) >= 500) printf("2");
  else PrintStack(&string1);
  
  return 0;
}