#include <iostream>

int N = 100;

class Queue{
	private:
		int* array;
		int front;
		int rear;
		
	public:
		Queue() {
			array = new int[N];
			front = -1;
			rear = -1;
		}
		
		void enqueue(int x) {
			if(front == (rear + 1) % N) {
				std::cout << "Queue is full." << std::endl;
				return;
			} else if (front == -1) {
				rear = front = 0;
			} else {
				rear = (rear + 1) % N;
			}
			array[rear] = x;
		}
		
		int dequeue() {
			int a = array[front];
			if(front != -1) {
				a = array[front];
			}
			
			if(front == -1) {
				return -1;
			} else if (front == rear) {
				front = rear = -1;
			} else {
				front = (front + 1) % N;
			}
			return a;
		}
		
		void display() {
			int i=front;
			while(i != rear) {
				std::cout << array[i] << " ";
				i = (i+1) % N;
			}
            std::cout << array[i] << std::endl;
		}
};


int main() {
	int n, x;
	std::cout << "Enter the number of elements: ";
	std::cin >> n;
	Queue queue;
	Queue queue1;
	std::cout << "Enter the numbers: ";
	for(int i=0; i<n; i++) {
		std::cin >> x;
		queue.enqueue(x);
		queue1.enqueue(x);
	}
	
	int m = queue1.dequeue();
	int p;
	while(m!=-1) {
		p = m-1;
		if(p>0) {
		queue.enqueue(p);
		queue1.enqueue(p);	
		}
		m = queue1.dequeue();
	}
	
	queue.display();
		
	return 0;
}
