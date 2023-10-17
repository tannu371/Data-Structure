#include <iostream>

class Queue {
    
}

void enqueue_ll(int x) {

}

int dequeue_ll() {
    return ;
}

int main() {
    int n;
    int x;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Elements to insert: ";
    for(int i=0; i<n; i++) {
        std::cin >> x;
        enqueue_ll(x);
    }
    return 0;
}