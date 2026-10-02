#include <iostream>
using namespace std;

class Node{
	public:
		int val;
		Node* next;
	Node(int val):val(val), next(nullptr){}	
};

class circularQueue{
	private:
		Node* front;
		Node* rear;
	public:
		circularQueue(){
			front=rear=nullptr;
		}
		bool isEmpty(){
			return front==nullptr;
		}
		void enqueue(int val){
			Node* newNode = new Node(val);
			if(isEmpty()){
				front=rear=newNode;
				rear->next=front;
				return;
			}
			rear->next=newNode;
			rear = newNode;
			rear->next=front;
		}
		void dequeue(){
			if(isEmpty()){
				cout << "circular queue is empty!" << endl;
				return;
			}
			if(front==rear){
				delete front;
				front=rear=nullptr;
				return;
			}
			Node* temp=front;
			front=front->next;
			rear->next=front;
			delete temp;
		}
		int size(){
			if(isEmpty()){
				return 0;
			}
			Node* temp=front;
			int count=0;
			do{
				count++;
				temp=temp->next;
			}while(temp!=front);
			return count;
		}
		int Peek(){
			if(isEmpty()){
				cout << "circular queue is empty!" << endl;
				return -1;
			}
			return front->val;
		}
		int Rear(){
			if(isEmpty()){
				cout << "circular queue is empty!" << endl;
				return -1;
			}
			return rear->val;
		}
		~circularQueue(){
			if(isEmpty()){
				return;
			}
			while(!isEmpty()){
				dequeue();
			}
		}
		void display(){
			if(isEmpty()){
				cout << "circular queue is empty!" << endl;
				return;
			}
			Node* temp=front;
			do{
				cout << temp->val << "-";
				temp=temp->next;
			}while(temp!=front);
			cout << "(rear)" << endl;
		}
};

int main(){
}
