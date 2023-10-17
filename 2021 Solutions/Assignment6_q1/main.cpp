#include <iostream>

class Queue {
private: 
    int* array;
    int front;
    int rear;
    int capacity;

public:
    Queue(int n) {
        array = new int[n];
        front = rear = -1;
        capacity = n;
    }

    void enqueue_arr(int x) {
        if(rear == capacity-1) {
            std::cout << "Reached end of the queue." << std::endl;
        } else if(boolean_empty_arr()) {
            front = rear = 0;
        } else {
            rear += 1; 
        }
        array[rear] = x;
    }

    int deueue_arr() {
        int a;
        if(front != -1) {
            a = array[front];
        }
        if(boolean_empty_arr()) {
            std::cout << "There is no element in the queue" << std::endl;
            return -1;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front += 1;
        }
        return a;
    }

    int front_arr() {
        return this->array[front];
    }

    bool boolean_empty_arr() {
        if(front == -1) {
            return true;
        }
        return false;
    }

    void display() {
        std::cout << "\nElements in queue: ";
        for(int i=front; i<=rear; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << "\n" << std::endl;
    }

};

int main() {

    int n;
    int x;
    std::cout << "\nEnter the number of elements: ";
    std::cin >> n;
    Queue queue(n);

    std::cout << "\nElements to insert: ";
    for(int i=0; i<n; i++) {
        std::cin >> x;
        queue.enqueue_arr(x);
    }

    queue.display();

    int a = queue.deueue_arr();
    std::cout << "Removed element: " << a << std::endl;

    queue.display();

    int b = queue.front_arr();
    std::cout << "Front element: " << b << std::endl;

    std::cout << std::boolalpha;
    std::cout << "\n" << queue.boolean_empty_arr() << std::endl;

    return 0;
}