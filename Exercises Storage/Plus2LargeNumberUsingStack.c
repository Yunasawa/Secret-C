/* Description:
  Input 2 numbers from keyboard. Return summary of them

  Example:
    Input: 
      1234
      5678
    Output:
      3912
*/

#include <stdio.h>
#include <stdlib.h>

#pragma region Structs
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    struct Node *node;
} Stack;
#pragma endregion

#pragma region Functions
void Push(Stack *stack, int data)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = stack->node;
    stack->node = new_node;
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

void PushFirst(Stack *stack, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = stack->node;
    stack->node = new_node;
}

Stack *Plus(Stack *stack1, Stack *stack2) 
{
    Stack *result = (Stack *) malloc(sizeof(Stack));
    result->node = NULL;
    int carry = 0, sum = 0;

    while (stack1->node != NULL || stack2->node != NULL || carry != 0) 
    {
        sum = carry;
        if (stack1->node != NULL) 
        {
            sum += Pop(stack1);
        }
        if (stack2->node != NULL) 
        {
            sum += Pop(stack2);
        }
        carry = sum / 10;
        sum %= 10;
        Push(result, sum);
    }

    return result;
}

void PrintStack(Stack* list) 
{
    Node* current = list->node;
    while (current != NULL) 
    {
        printf("%d", current->data);
        current = current->next;
    }
}

#pragma endregion

int main() 
{
  Stack num1 = {NULL};
  Stack num2 = {NULL};
  Stack result = {NULL};

  char input = ' ';

  input = getchar();
  while (input != '\n')
  {
    Push(&num1, atoi(&input));
    input = getchar();
  }

  input = getchar();
  while (input != '\n')
  {
    Push(&num2, atoi(&input));
    input = getchar();
  }

  PrintStack(Plus(&num1, &num2));

  return 0;
}