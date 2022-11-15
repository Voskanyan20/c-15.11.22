#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;
void push(int val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = val;
   newnode->next = head;
   head = newnode;
}
void pop() {
   if(head==NULL)
            cout<<"Slack datark e"<<endl;
   else {

      head = head->next;
   }
}
void display() {
   struct Node* ptr;
   if(head==NULL)
   cout<<"stack datark e !!! ";
   else {
      ptr = head;
      cout<<"Stack elementner = : ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}
int main() {
   int ch, val;
   cout<<"1) Pushing"<<endl;
   do {
      cout<<"choiceing: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"pusheing value:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"sxal"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}