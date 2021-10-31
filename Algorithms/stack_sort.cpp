#include<bits/stdc++.h>
#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *top;

void push(int data){

    struct Node *temp;
    temp=new Node(); //malloc(sizeof(struct Node));
    
    if(!temp){
        cout<<"Heap Overflow"<<endl;
        exit(1);
    }
    temp->data=data;
    temp->next=top;
    top=temp;
}

int isEmpty(){
    return top==NULL;
}

int peek(){
    if(!isEmpty())
        return top->data;
    else
        exit(1);
}

void pop(){
    struct Node *temp;

    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }
    else{
        temp=top;
        top=top->next;
        temp->next=NULL;
        //delete temp node
        free(temp);
    }
}

void display(){
    struct Node *temp;

    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        exit(1);
    }
    else{
        temp=top;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
}

int main(){
    push(11);
    push(12);
    push(13);
    push(14);
    push(15);

    display();

    cout<<"/nTop element of stack : "<<peek();

    pop();
    pop();

    display();

    cout<<"\nTop element of stack : "<<peek()<<endl;

    return 0;
}
