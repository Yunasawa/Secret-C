/*
Description
    Cần thống kê xem mỗi ngày có bao nhiêu lượt sinh viên làm trắc nghiệm.
Input
    Thông tin về sinh viên làm trắc nghiệm ôn tập được cho theo các dòng định dạng như sau:
    <yyyy-mm-dd> <hh:mm:ss> <user_id> <question_id>: trong đó sinh viên có mã <user_id> làm 
    câu hỏi <question_id> vào ngày giờ là <yyyy-mm-dd> <hh:mm:ss>. Kết thúc dữ liệu là 1 dòng 
    chứa dấu *
Output
    Mỗi dòng ghi <yyyy-mm-dd> <cnt>: trong đó <cnt> là số lượt sinh viên làm trắc nghiệm trong 
    ngày <yyyy-mm-dd> (chú ý: các dòng được sắp xếp theo thứ tự tăng dần của ngày thống kê, ngày 
    thống kê nào mà không có lượt sinh viên làm trắc nghiệm thì không in ra)

Example
Input
    2022-01-02 10:30:24 dungpq question1
    2022-01-03 11:30:24 dungpq question1
    2022-02-01 03:30:20 viettq question2
    2022-02-01 03:35:20 viettq question1
    2022-03-01 03:30:20 viettq question7
    2022-01-02 11:20:24 viettq question2
Output
    2022-01-02 2
    2022-01-03 1
    2022-02-01 2
    2022-03-01 1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node 
{
  char date[11];
  int count;
  struct node *next;
} node;

typedef struct stack
{
  node *top;
  int size;
} stack;

stack *create_stack() 
{
  stack *s = (stack *)malloc(sizeof(stack));
  s->top = NULL;
  s->size = 0;
  return s;
}

int is_empty(stack *s) 
{
  return s->size == 0;
}

void push(stack *s, char date[], int count) 
{
  node *n = (node *)malloc(sizeof(node));
  strcpy(n->date, date);
  n->count = count;
  n->next = s->top;
  s->top = n;
  s->size++;
}

node *pop(stack *s) 
{
  if (is_empty(s)) 
  {
    return NULL;
  }
  node *n = s->top;
  s->top = n->next; 
  s->size--; 
  return n;
}

node *search(stack *s, char date[]) 
{
  node *n = s->top;
  while (n != NULL) 
  { 
    if (strcmp(n->date, date) == 0) 
    {
      return n;
    }
    n = n->next;
  }
  return NULL;
}

void free_stack(stack *s) 
{
  while (!is_empty(s)) 
  {
    node *n = pop(s);
    free(n);
  }
  free(s);
}

int compare_date(char date1[], char date2[]) 
{
  int d1 = atoi(date1 + 8);
  int m1 = atoi(date1 + 5);
  int y1 = atoi(date1);
  int d2 = atoi(date2 + 8);
  int m2 = atoi(date2 + 5);
  int y2 = atoi(date2);
  if (y1 > y2) return -1;
  if (y1 < y2) return 1;
  if (m1 > m2) return -1;
  if (m1 < m2) return 1; 
  if (d1 > d2) return -1;
  if (d1 < d2) return 1;
  return 0;
}

void sort_stack(stack *s) 
{
  if (is_empty(s) || s->size == 1) 
  {
    return;
  }
  stack *temp = create_stack();
  while (!is_empty(s)) 
  {
    node *n = pop(s);
    while (!is_empty(temp) && compare_date(temp->top->date, n->date) < 0) 
    {
      node *noteTemp = pop(temp);
      push(s, noteTemp->date, noteTemp->count);
    }
    push(temp, n->date, n->count);
  }
  while (!is_empty(temp)) 
  {
    node *noteTemp = pop(temp);
    push(s, noteTemp->date, noteTemp->count);
  }
  free_stack(temp);
}


int main() 
{
  stack *s = create_stack();
  while (1) 
  {
    char data[20];
    scanf("%s", data);
    if (strcmp(data, "*") == 0) 
    {
      break;
    }

    char date[11];
    strncpy(date, data, 10);
    date[10] = '\0';
    if (date[4] == '-')
    {
        node *n = search(s, date);
        if (n == NULL) 
        { 
            push(s, date, 1);
        } 
        else 
        { 
        n->count++;
        }
    }
  }

  sort_stack(s);

  while (!is_empty(s)) 
  {
    node *n = pop(s);
    printf("%s %d\n", n->date, n->count);
    free(n);
  }

  free_stack(s);
  return 0;
}
