#include <iostream>

class Queue {
public:
    int* array;
    int rear;
    int front;
    int capacity;

public:
    Queue(int n) {
        array = new int[n];
        front = rear = -1;
        capacity = n;
    }

    void insert_cir(int x) {
        if(front == (rear + 1) % capacity) {
            std::cout << "Queue is full." << std::endl;
            return;
        } else if (front == -1) {
            rear = front = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        array[rear] = x;
    }

    int delete_cir() {
        int a;
        if(front != -1) {
            a = array[front];
        }
        if(front == -1) {
            std::cout << "No elements in queue." << std::endl;
            return -1;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return a;
    }

    int get_front_cir() {
        return this->array[front] ;
    }

    int get_rear_cir() {
        return this->array[rear];
    }

    int size_cir() {
        int size;
        if(rear == front) {
            size = 1;
        } else if (rear > front ) {
            size = rear - front + 1;
        } else {
            size = capacity - (front - rear) + 1;
        }
        return size;
    }

    void display() {
        std::cout << "\nElements of queue: ";
        int i=front;
        while(i != rear) {
            std::cout << array[i] << " ";
            i = (i+1) % capacity;
        }
        std::cout << array[rear];
        std::cout << "\n" << std::endl;
    }
};





int main () {
    int n;
    int x;
    std::cout << "\nEnter the size (k): ";
    std::cin >> n;
    Queue queue(n);
    std::cout << "\nElements to insert: ";
    for(int i=0; i<n; i++) {
        std::cin >> x;
        queue.insert_cir(x);
    }

    queue.display();

    int a = queue.delete_cir();
    std::cout << "Removed element: " << a << std::endl;

    queue.display();

    std::cout << "Front element of queue: " << queue.get_front_cir() << "\n" << std::endl;
    std::cout << "Rear element of queue: " << queue.get_rear_cir() << "\n" << std::endl;
    std::cout << "Size of the circular queue: " << queue.size_cir() << "\n" << std::endl;

    return 0;
}