/*
	Name: Tree data structure
	Copyright: 2023
	Author: Randy Chauarria
	Date: 06/11/23 23:14
	Description: Unordered, complete binary tree. Able to be searched 
	through either BFS or an in-order implementation of DFS
*/

#include <iostream>
#include <queue>
using namespace std;

// Template for a binary tree
template <class T>
class myBinaryTree{
	private:
		struct Node{
			T value;
			Node* l_child;
			Node* r_child;	
		};
	public:
		Node* root; 
		myBinaryTree(){
			root = nullptr;
		}
		void addNewItem(T);
		void printDepthFirstTraversal(Node*);
		void printBreadthFirstTraversal();		
};

// Main test driver
int main(int argc, char *argv[]){
	myBinaryTree<int> tester;
	tester.addNewItem(15); 
	tester.addNewItem(7);
	tester.addNewItem(18);  
	tester.addNewItem(20);
	tester.addNewItem(25); 
	tester.addNewItem(34);
	tester.addNewItem(54); 
	tester.addNewItem(55); 
	tester.addNewItem(67); 
	cout << "Printing an In-order Depth First Search:\n";
	tester.printDepthFirstTraversal(tester.root);
	cout << "\n\nNow printing a Breadth First Search:\n";
	tester.printBreadthFirstTraversal();
	return 0;
}

// Adds to a tree structure from left to right, keeping structure complete but unordered
template <class T>
void myBinaryTree<T>::addNewItem(T newItem){
	if (root == nullptr){
		root = new Node;
		root->value = newItem;
		root->l_child = nullptr;
		root->r_child = nullptr;
	}
	else{
		queue<Node*> treeNode;
		treeNode.push(root);
		while (!treeNode.empty()){
			Node* curPtr = treeNode.front();
			treeNode.pop();
			if (curPtr->l_child == nullptr){
				Node* newNode = new Node;
				newNode->value = newItem;
				newNode->l_child = nullptr;
				newNode->r_child = nullptr; 
				curPtr->l_child = newNode;
				while (!treeNode.empty())
					treeNode.pop();
			}
			else if (curPtr->r_child == nullptr){
				Node* newNode = new Node;
				newNode->value = newItem;
				newNode->l_child = nullptr;
				newNode->r_child = nullptr;
				curPtr->r_child = newNode;
				while (!treeNode.empty())
					treeNode.pop();
			}
			else{
				treeNode.push(curPtr->l_child);
				treeNode.push(curPtr->r_child);  
			}
		} 
	}
} 

// Prints values of a tree through a breadth first search 
template <class T>
void myBinaryTree<T>::printBreadthFirstTraversal(){
	queue<Node*> treeQ;
	treeQ.push(root);
	while (!treeQ.empty()){
		Node* curPtr = treeQ.front();
		treeQ.pop();
		cout << curPtr->value << " ";
		if (curPtr->l_child != nullptr)
			treeQ.push(curPtr->l_child);
		if (curPtr->r_child != nullptr)
			treeQ.push(curPtr->r_child);  
	} 
} 

// Does an in-order search of a tree
template <class T>
void myBinaryTree<T>::printDepthFirstTraversal(Node* curPtr){
	if (curPtr == nullptr) 
		return;
	else
		{
			printDepthFirstTraversal(curPtr->l_child);
			cout << curPtr->value << " ";
			printDepthFirstTraversal(curPtr->r_child);
		}
}
