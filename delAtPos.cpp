#include <iostream>
using namespace std;
class node
{
public:
 int data;
 node *next;
};

void delAtPos(node **head)
{
 int pos;
 cout << "Enter The Position You want to delete\n";
 cin >> pos;
 node *current = *head;
 node *prev = *head;
 if (head == NULL)
 {
  cout << "List is already empty\n";
  return;
 }
 else if (pos == 1)
 {
  *head = current->next;
  free(current);
  current = NULL;
  cout << "Delete SuccessFully\n";
  return;
 }
 else
 {
  while (pos != 1)
  {
   prev = current;
   current = current->next;
   pos--;
  }
  prev->next = current->next;
  free(current);
  current = NULL;
  cout << "Delete SuccessFully\n";
 }
}

void print(node *head)
{
 if (head == NULL)
 {
  cout << "List is empty\n";
  return;
 }
 node *temp = NULL;
 temp = head;
 while (temp != NULL)
 {
  cout << temp->data << " ";
  temp = temp->next;
 }
 cout << endl;
}

void menu(node *head)
{
 int choice = 1;
 while (choice != 0)
 {
  cout << "Press 1:To Delete at Specific position\n";
  cout << "Press 2:To display\n";
  cout << "Press 0:To Exit\n";
  cin >> choice;
  switch (choice)
  {
  case 1:
   delAtPos(&head);
   break;
  case 2:
   print(head);
   break;
  case 0:
   exit(0);
   break;
  default:
   cout << "Plz Enter The right command\n";
   break;
  }
 }
}

void create()
{
 node *head = NULL;
 head = (node *)malloc(sizeof(node)); // allocate memory
 head->data = 15;
 head->next = NULL;

 node *second = (node *)malloc(sizeof(node));
 second->data = 20;
 second->next = NULL;

 head->next = second;

 node *third = (node *)malloc(sizeof(node));
 third->data = 35;
 third->next = NULL;

 second->next = third;

 menu(head);
}

int main()
{
 create();
}
