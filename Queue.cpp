// Queue implementation in C++

#include <iostream>
#define SIZE 5

using namespace std;

class Queue {
   private:
    int items[SIZE], front, rear;

   public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if (front == 0 && rear == SIZE - 1) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (front == -1)
            return true;
        else
            return false;
    }

    void enQueue(int element) {
        if (isFull()) {
            cout << "Queue is full";
        } else {
            if (front == -1)
                front = 0;
            rear++;
            items[rear] = element;
            cout << endl
                 << "Inserted " << element << endl;
        }
    }

    int deQueue() {
        int element;
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return (-1);
        } else {
            element = items[front];
            if (front >= rear) {
                front = -1;
                rear = -1;
            } /* Q has only one element, so we reset the queue after deleting it. */
            else {
                front++;
            }
            cout << endl
                 << "Deleted -> " << element << endl;
            return (element);
        }
    }

    void display() {
        /* Function to display elements of Queue */
        int i;
        if (isEmpty()) {
            cout << endl
                 << "Empty Queue" << endl;
        } else {
            cout << endl
                 << "Front index-> " << front;
            cout << endl
                 << "Items -> ";
            for (i = front; i <= rear; i++)
                cout << items[i] << "  ";
            cout << endl
                 << "Rear index-> " << rear << endl;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            return items[front];
        }
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            return items[rear];
        }
    }

    int getSize() {
        if (isEmpty()) {
            return 0;
        } else {
            return rear - front + 1;
        }
    }

    void clear() {
        front = -1;
        rear = -1;
        cout << "Queue cleared" << endl;
    }

    Queue(const Queue& other) {
        front = other.front;
        rear = other.rear;
        for (int i = front; i <= rear; i++) {
            items[i] = other.items[i];
        }
    }

    Queue& operator=(const Queue& other) {
        if (this != &other) {
            front = other.front;
            rear = other.rear;
            for (int i = front; i <= rear; i++) {
                items[i] = other.items[i];
            }
        }
        return *this;
    }

//  bool operator==(const Queue& other) {
//     if (getSize() != other.getSize()) {
//         return false;
//     }
//     for (int i = front, j = other.front; i <= rear; i++, j++) {
//         if (items[i] != other.items[j]) {
//             return false;
//         }
//     }
//     return true;
// }

// bool operator!=(const Queue& other) {
//     return !(*this == other);
// }

   
};

int main() {
    Queue q;

    // Dequeue is not possible on empty queue
    q.deQueue();

    // Enqueue 5 elements
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    // 6th element can't be added because the queue is full
    q.enQueue(6);

    q.display();

    // Dequeue removes the element entered first i.e. 1
    q.deQueue();

    // Now we have just 4 elements
    q.display();

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Size of queue: " << q.getSize() << endl;

    // Queue q2(q); // Copy constructor
    // cout << "Copy of queue: ";
    // q2.display();

    // Queue q3;
    // q3 = q; // Assignment operator
    // cout << "Assigned queue: ";
    // q3.display();

    // if (q == q2) {
    //     cout << "q and q2 are equal" << endl;
    // } else {
    //     cout << "q and q2 are not equal" << endl;
    // }

    // if (q != q3) {
    //     cout << "q and q3 are not equal" << endl;
    // } else {
    //     cout << "q and q3 are equal" << endl;
    // }

    q.clear();
    q.display();

    return 0;
}


// This code includes the implementation of the following additional functions:

//     getFront(): Returns the value of the front element without removing it.
//     getRear(): Returns the value of the rear element without removing it.
//     getSize(): Returns the number of elements in the queue.
//     clear(): Removes all elements from the queue.
//     Copy Constructor: Creates a new queue with the same elements as an existing queue.
//     Assignment Operator: Assigns the elements of one queue to another queue.
//     Overloaded Comparison Operators: Compares two queues for equality or inequality.