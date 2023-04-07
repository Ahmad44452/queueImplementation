#include <iostream>
using namespace std;

// Node struct represents a single node
struct Node{
   int val;         // Value of the node
   struct Node* next;  // Pointer to the next node
};

// Queue class represents the queue data structure
class Queue{
   struct Node* front = NULL;  // Pointer to the front of the queue
   struct Node* rear = NULL;   // Pointer to the rear of the queue

   public:
      // Enqueue method adds a new element to the rear of the queue
      void enqueue(int val){
         struct Node* temp = new Node;   // Allocate a new node
         temp->val = val;               // Set the value of the node
         temp->next = NULL;             // Set the next pointer to NULL

         // If the queue is empty, set both front and rear pointers to the new node
         if(front == NULL && rear == NULL){
            front = temp;
            rear = temp;
         }
         // Otherwise, add the new node to the rear of the list
         else{
            rear->next = temp;
            rear = temp;
         }
      }

      // Dequeue method removes the element from the front of the queue
      void dequeue(){
         // If the queue is empty, print an error message and return
         if(front == NULL && rear == NULL){
            cout << "Queue is already empty" << endl;
            return;
         }
         
         // If there's only one element in the queue, delete it and set both pointers to NULL
         if(front == rear){
            delete front;
            front = NULL;
            rear = NULL;
         }
         // Otherwise, delete the first element and update the front pointer
         else{
            struct Node* temp = front;
            front = front->next;
            delete temp;
         }
      }

      // Display method prints the contents of the queue
      void display(){
         // If the queue is empty, print an error message and return
         if(front == NULL && rear == NULL){
            cout << "Queue is empty" << endl;
            return;
         }

         // Traverse the queue and print the values of each node
         struct Node* temp = front;
         while(temp != NULL){
            cout << temp->val;

            // If this is not the last node, print an arrow "->"
            if(temp->next != NULL){
               cout << " -> ";
            }

            // Move to the next node
            temp = temp->next;
         }
		 // Move cursor to next line after whole queue has been printed
         cout << endl;
      }
};

int main(){
   Queue q1;
   
   // Try to dequeue an empty queue
   q1.dequeue();

   // Try to display the contents of an empty queue
   q1.display();

   // Enqueue several elements onto the queue and display the contents after each addition
   q1.enqueue(10);
   q1.display();

   q1.enqueue(20);
   q1.display();

   q1.enqueue(30);
   q1.display();

   q1.enqueue(40);
   q1.display();

   // Dequeue an element and display the updated contents of the queue
   q1.dequeue();
   q1.display();

   // Enqueue more elements and display the updated contents of the queue after each addition
   q1.enqueue(20);
   q1.display();

   q1.enqueue(100);
   q1.display();

   return 0;
}
