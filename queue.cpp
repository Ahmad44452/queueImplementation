#include <iostream>
using namespace std;

struct Node{
   int val;
   struct Node* next;
};

class Queue{
   struct Node* front = NULL;
   struct Node* rear = NULL;

   public:
      void enqueue(int val){
         struct Node* temp = new Node;
         temp->val = val;
         temp->next = NULL;

         if(front == NULL && rear == NULL){
            front = temp;
            rear = temp;
         }else{
            rear->next = temp;
            rear = temp;
         }
      }

      void dequeue(){
         if(front == NULL && rear == NULL){
            cout << "Queue is empty" << endl;
            return;
         }
      
         if(front == rear){
            delete front;
            front = NULL;
            rear = NULL;
         }else{
            struct Node* temp = front;
            front = front->next;
            delete temp;
         }
      }


      void display(){
         if(front == NULL && rear == NULL){
            cout << "Queue is empty" << endl;
            return;
         }

         struct Node* temp = front;

         while(temp != NULL){
            cout << temp->val;

            if(temp->next != NULL){
               cout << " -> ";
            }

            temp = temp->next;
         } 
         cout << endl;
      }
};

int main(){
   Queue q1;
   
   q1.dequeue();
   q1.display();

   q1.enqueue(10);
   q1.display();

   q1.enqueue(20);
   q1.display();

   q1.enqueue(30);
   q1.display();

   q1.enqueue(40);
   q1.display();

   q1.dequeue();
   q1.display();

   q1.enqueue(20);
   q1.display();

   q1.enqueue(100);
   q1.display();


   return 0;
}