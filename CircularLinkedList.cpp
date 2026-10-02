#include <iostream>
using namespace std;

class Node{
	public:
		int val;
		Node* next;
	Node(int val):val(val), next(nullptr){}	
};

class CircularLinkedList{
	private:
		Node* head;
		Node* tail;
	public:
		CircularLinkedList(){
			head=tail=nullptr;
		}
		void insertAtHead(int val){
			Node* newNode = new Node(val);
			if(head==nullptr){
				head=tail=newNode;
				tail->next = head;
				return;
			}
			newNode->next=tail->next;
			tail->next=newNode;
			head=tail->next;
		}
		void insertAtTail(int val){
			Node* newNode = new Node(val);
			if(head==nullptr){
				head=tail=newNode;
				tail->next=head;
				return;
			}
			newNode->next = tail->next;
			tail->next=newNode;
			tail=newNode;
		}
		void deleteAtHead(){
			if(head==nullptr){return;}
			if(head==tail){
				delete head;
				head=tail=nullptr;
			}else{
				Node* temp=head;
				head=head->next;
				tail->next=head;
				delete temp;
				
			}
		}
		void deleteAtTail(){
			if(head==nullptr){return;}
			if(head==tail){
				delete head;
				head=tail=nullptr;
			}else{
				Node* temp=head;
				
				while(temp->next!=tail){
					temp=temp->next;
				}
				delete tail;
				tail=temp;
				tail->next=head;
			}
		}
		void display(){
			if(head==nullptr){
				cout << "List is empty!" << endl;
				return;
			}
			Node* temp=head;
			
			do{
				cout << temp->val << "->";
				temp=temp->next;
			}while(temp!=head);
			
			cout << "(head)" << endl;
			
		}
		~CircularLinkedList(){
			if(head==nullptr){
				return;
			}
			Node* curr = head->next;
			while(curr!=head){
				Node* temp = curr;
				curr = curr->next;
				delete temp;
			}
			delete head;
			head=tail=nullptr;
		}
};

int main(){
}
