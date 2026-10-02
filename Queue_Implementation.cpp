// Queue implementation using Node Class (Implementation using LinkedList)
#include <iostream>
using namespace std;

class Node{
	public:
		int val;
		Node* next;
	Node(int val):val(val), next(nullptr){}	
};

class Queue{
	private:
		Node* front;
		Node* rear;
	public:
		Queue(){
			front=rear=nullptr;
		}
		void enqueue(int val){
			Node* newNode = new Node(val);
			if(front==nullptr){
				front=rear=newNode;
				return;
			}
			rear->next=newNode;
			rear=newNode;
			rear->next=nullptr;
		}
		void dequeue(){
			if(front==nullptr){
				cout << "queue is empty!" << endl;
				return;
			}
			if(front==rear){
				delete front;
				front=rear=nullptr;
				return;
			}
			Node* temp=front->next;
			delete front;
			front = temp;
		}
		bool isEmpty(){
			return front==nullptr;
		}
		int Peek(){
			if(isEmpty()){
				cout << "queue is empty!" << endl;
				return -1;
			}
			return front->val;
		}
		int size(){
			int count=0;
			Node* temp=front;
			while(temp!=nullptr){
				count++;
				temp=temp->next;
			}
			return count;
		}
		int Rear(){
			if(isEmpty()){
				cout << "queue is empty!" << endl;
				return -1;
			}
			return rear->val;
		}
		~Queue(){
			while(front!=nullptr){
				Node* temp=front;
				front=front->next;
				delete temp;
			}
			rear=nullptr;
		}
		void display(){
			if(isEmpty()){
				cout << "queue is empty!" << endl;
				return;
			}
			Node* temp = front;
			while(temp!=nullptr){
				cout << temp->val << "-";
				temp=temp->next;
			}
			cout << "(rear)" << endl;
		}
};

int main(){
}
