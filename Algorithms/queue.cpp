/*
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Queue{
    int rear,front;

    int size;
    int *arr;

    Queue q(int s){
        front = rear = -1;
        size=s;
        arr=new int[s];
    }
    void enqueue(int value);
    int dequeue();
    void display();
};

void Queue::enqueue(int value){
    if(front==0 && rear==size-1 || (rear==(front-1)%(size-1))){
        cout<<"Queue is Full"<<endl;
        return;
    }
    else if(front==-1){
        fornt=rear=0;
        arr[rear]=value;
    }
    else if(rear==size-1 && front!=0){
        rear=0;
        arr[rear]=value;
    }
    else{
        rear++;
        arr[rear]=value;
    }
}

void Queue::dequeue(){
    if(front==-1){
        cout<<"Queue is empty"<<endl;
        return INT_MIN;
    }

    int data=arr[front];
    arr[front]=-1;

    if(front==rear){
        front=rear=-1;
    }
    else if(front==size-1)
        front=0;
    else
        front++;

    return data;
}

void Queue::display(){
    if(front==-1){
        cout<<"Empty"<<endl;
        return;
    }
    
    cout<<"Elements in Circular Queue is:";

    if(rear>=front){
        for(int i=front;i<=rear;i++)
            cout<<arr[i]<<endl;
    }
    else{
        for(int i=front;i<size;i++)
            cout<<arr[i]<<endl;
        for(int i=0;rear>=i;i++)
            cout<<arr[i]<<endl;
    }
}

*/



// C++ program to implement a queue using an array
#include <bits/stdc++.h>
using namespace std;

struct Queue {
	int front, rear, capacity;
	int* queue;
	Queue(int c)
	{
		front = rear = 0;
		capacity = c;
		queue = new int;
	}

	~Queue() { delete[] queue; }

	// function to insert an element
	// at the rear of the queue
	void queueEnqueue(int data)
	{
		// check queue is full or not
		if (capacity == rear) {
			printf("\nQueue is full\n");
			return;
		}

		// insert element at the rear
		else {
			queue[rear] = data;
			rear++;
		}
		return;
	}

	// function to delete an element
	// from the front of the queue
	void queueDequeue()
	{
		// if queue is empty
		if (front == rear) {
			printf("\nQueue is empty\n");
			return;
		}

		// shift all the elements from index 2 till rear
		// to the left by one
		else {
			for (int i = 0; i < rear - 1; i++) {
				queue[i] = queue[i + 1];
			}

			// decrement rear
			rear--;
		}
		return;
	}

	// print queue elements
	void queueDisplay()
	{
		int i;
		if (front == rear) {
			printf("\nQueue is Empty\n");
			return;
		}

		// traverse front to rear and print elements
		for (i = front; i < rear; i++) {
			printf(" %d <-- ", queue[i]);
		}
		return;
	}

	// print front of queue
	void queueFront()
	{
		if (front == rear) {
			printf("\nQueue is Empty\n");
			return;
		}
		printf("\nFront Element is: %d", queue[front]);
		return;
	}
};

// Driver code
int main(void)
{
	// Create a queue of capacity 4
	Queue q(4);

	// print Queue elements
	q.queueDisplay();

	// inserting elements in the queue
	q.queueEnqueue(20);
	q.queueEnqueue(30);
	q.queueEnqueue(40);
	q.queueEnqueue(50);

	// print Queue elements
	q.queueDisplay();

	// insert element in the queue
	q.queueEnqueue(60);

	// print Queue elements
	q.queueDisplay();

	q.queueDequeue();
	q.queueDequeue();

	printf("\n\nafter two node deletion\n\n");

	// print Queue elements
	q.queueDisplay();

	// print front of the queue
	q.queueFront();

	return 0;
}
