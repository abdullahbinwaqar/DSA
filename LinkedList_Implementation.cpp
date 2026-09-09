#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int val){
			data = val;
			next = NULL;
		}
};

class List{
	Node* head;
	Node* tail;
	
	public:
		List(){
			head = tail = NULL;
		}
		void push_front(int val){
			Node* newNode = new Node(val);
			if(head==NULL){
				head = tail = newNode;
			}else{
				newNode->next = head;
				head = newNode;
			}
		}
		void push_back(int val){
			Node* newNode = new Node(val);
			if(tail==NULL){
				head=tail=newNode;
			}else{
				tail->next = newNode;
				tail = newNode;
			}
		}
		void printll(){
			Node* temp = head;
			while(temp!=NULL){
				cout << temp->data << "->";
				temp = temp->next;
			}
			cout << endl << endl;
		}
		void pop_front(){
			if(head==NULL){
				cout << "Linked list is empty!" << endl;
			}else{
				Node* temp = head;
				head = head->next;
				delete temp;
			}
		}
		void pop_back(){
			if(head==NULL){
				cout << "Linked list is empty!" << endl;
				return;
			}else{
				Node* temp = head;
				while(temp->next != tail){
					temp = temp->next;
				}
				temp->next = NULL;
				delete tail;
				tail = temp;
			}
		}
		void insert(int pos, int val){
			if(pos<0){
				cout << "Invalid Position!" << endl;
				return;
			}
			if(pos==0){
				push_front(val);
				return;
			}
			
			Node* temp = head;
			for(int i=0; i<pos-1; i++){
				if(temp==NULL){
					cout << "Invalid Position!" << endl;
					return;
				}
				temp = temp->next;
			}
			Node* newNode = new Node(val);
			newNode->next = temp->next;
			temp->next = newNode;
		}
		
		void deleteNode(int key){
			Node* temp = head;
			Node* prev = NULL;
			
			if(temp!=NULL && temp->data==key){
				head = temp->next;
				delete temp;
			}
			while(temp!=NULL && temp->data!=key){
				prev = temp;
				temp = temp->next;
			}
			if(temp==NULL){
				cout << "Key Not Found!" << endl;
				return;
			}
			prev->next = temp->next;
			delete temp;
		}
		int search(int key){
			Node* temp = head;
			int idx=0;
			while(temp!=NULL){
				if(temp->data==key){
					return idx;
				}
				temp = temp->next;
				idx++;
			}
			return -1;
		}
};

int main(){
	List myList;
	myList.push_front(1);
	myList.push_front(2);
	myList.push_front(3);
	myList.push_front(4);
	myList.push_front(5);
	myList.push_back(5);
	myList.push_back(6);
	myList.push_back(7);
	myList.push_back(8);
	myList.push_back(9);
	myList.printll();
	myList.pop_back();
	myList.pop_back();
	myList.pop_front();
	myList.pop_front();
	myList.printll();
	myList.deleteNode(5);
	myList.printll();
	myList.deleteNode(78);
	cout << myList.search(7);
	return 0;
}
