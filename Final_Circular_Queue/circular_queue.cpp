#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

class Queue {
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        // Updated condition to check if front is one position behind rear in a circular manner
        return (front == (rear + 1) % MAX_SIZE) || (front > rear);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = value;
        cout << value << " enqueued to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        int removedValue = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }

        cout << removedValue << " dequeued from the queue." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Elements in the queue: ";
        int i = front;

        do {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);

        cout << endl;
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);

    myQueue.display();

    myQueue.dequeue();
    myQueue.display();

    myQueue.enqueue(7);
    myQueue.display();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.enqueue(11);
    myQueue.display();

    return 0;
}
