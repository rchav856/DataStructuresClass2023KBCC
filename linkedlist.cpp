// Randy Chauarria Linked List
#include <iostream>
using namespace std;


// Start of a Linked List.
class myLinkedList{
	private:
		struct Node{
			int mydata;
			Node* next;	
		};
	public:
		Node* root;
		myLinkedList(){
			root = nullptr;
		}
		~myLinkedList(){
		}	
		void push_back(int);
		void deleteNode(int);
		void printList();
};

int main(){
	myLinkedList start;
	cout << "Adding values into a linked list...\n";
	start.push_back(5);
	start.push_back(10);
	start.push_back(15);
	start.push_back(20);
	cout << "Contents of the list: ";
	start.printList();
	start.push_back(25);
	cout << "Adding 25 to list, new list below.\n";
	start.printList();  
	start.deleteNode(20);
	cout << "Deleted 20 from list, new list below.\n";
	start.printList(); 
	start.deleteNode(10);
	cout << "Deleted 10 from list, new list below.\n";
	start.printList(); 
	return 0;
}

// Adds integers to a linked list, pushed to back of list.
void myLinkedList::push_back(int val){
	if (root == nullptr){
		root = new Node;
		root->mydata = val;
		root->next = nullptr;
	}
	else{
		Node* newNode = new Node;
		newNode->mydata = val;
		newNode->next = nullptr;
		Node* curPtr = root;
		while (curPtr != nullptr){
			if (curPtr->next == nullptr){
				curPtr->next = newNode;
				curPtr = nullptr;
			}
			else
				curPtr = curPtr->next;
		}
	}
}

// Deletes a node containing integer of value in list.
void myLinkedList::deleteNode(int value){
	Node* frontPtr = root;
	Node* backPtr = root;
	while (frontPtr != nullptr){
		if (frontPtr->mydata == value){
			backPtr->next = frontPtr->next;
			frontPtr->next = nullptr;
		}
		backPtr = frontPtr;
		frontPtr = frontPtr->next;
	}
}


// Iterates through list and prints out values in nodes.
void myLinkedList::printList(){
	Node* curPtr = root;
	while (curPtr != nullptr){
		cout << curPtr->mydata << " ";
		curPtr = curPtr->next;
	}
	cout << endl;
}

