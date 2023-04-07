// Define a type for single node of Queue
type QueueNode = {
  val: number;
  next: QueueNode | null;
};

// Define a Queue class
class Queue {
  // Initialize front and rear pointers to null
  front: QueueNode | null = null;
  rear: QueueNode | null = null;

  // Method to add an element to the rear of the queue
  enqueue(val: number): void {
    // Create a new node with given value and null next pointer
    const temp: QueueNode = {
      val: val,
      next: null,
    };

    // If queue is empty, set front and rear pointers to the new node
    if (this.front === null && this.rear === null) {
      this.front = temp;
      this.rear = temp;
      return;
    }
    // Otherwise, add new node to the rear of the queue
    else if (this.front !== null && this.rear !== null) {
      this.rear.next = temp;
      this.rear = temp;
    }
  }

  // Method to remove an element from the front of the queue
  dequeue(): void {
    // If queue is empty, print message and return
    if (this.front === null && this.rear === null) {
      console.log("Queue is already empty");
      return;
    }

    // If there is only one element in the queue, set front and rear pointers to null
    if (this.front === this.rear) {
      this.front = null;
      this.rear = null;
      return;
    }

    // Otherwise, remove the front element and update front pointer to the next element
    if (this.front) this.front = this.front.next;
  }

  // Method to display the elements of the queue
  display(): void {
    // If queue is empty, print message and return
    if (this.front === null) {
      console.log("Queue is empty");
      return;
    }

    // Iterate over the queue and create a string representation of the elements
    let temp: QueueNode | null = this.front;
    let outputString: string = "";

    while (temp !== null) {
      outputString += temp.val;

      if (temp.next !== null) {
        outputString += " -> ";
      }

      temp = temp.next;
    }

    // Print the string representation of the queue
    console.log(outputString);
  }
}

// Create a new Queue object
const Q1 = new Queue();

// Add elements to the queue and display the queue after each operation
Q1.enqueue(10);
Q1.display();

Q1.enqueue(20);
Q1.display();

Q1.enqueue(30);
Q1.display();

Q1.dequeue();
Q1.display();

Q1.dequeue();
Q1.display();

Q1.enqueue(10);
Q1.display();

Q1.dequeue();
Q1.display();

Q1.enqueue(20);
Q1.display();

Q1.dequeue();
Q1.display();

Q1.dequeue();
Q1.display();

Q1.dequeue();
Q1.display();
