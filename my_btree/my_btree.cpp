//
//  my_btree.cpp
//  ranystephan.rcs04.asst2
//
//  Created by Rany STEPHAN
//

#include "my_btree.hpp"
#include <iostream>



template <class T>
class BinaryTree
{

	struct node{
		T *data;
		struct node* right;
		struct node* left;
	};

public:
	BinaryTree();
	~BinaryTree();
	void addNode(T val);
	void preOrderPrint();
	void inOrderPrint();
	void postOrderPrint();
	int size();
	bool lookup(T val);

private:
	struct node* root;
	int treeSize;
	void addNode(struct node** node, T val);
	bool lookup(struct node* node, T val);
	void preOrderPrint(struct node* node);
	void inOrderPrint(struct node* node);
	void postOrderPrint(struct node* node);
	void deleteTree(struct node* node);
};

template <class T>
BinaryTree<T>::BinaryTree(){
	this->root = NULL;
	this->treeSize = 0;
}

template <class T>
BinaryTree<T>::~BinaryTree(){
	deleteTree(this->root);
}

template <class T>
int BinaryTree<T>::size(){
	return this->treeSize;
}

template <class T>
void BinaryTree<T>::addNode(T val){
	addNode(&(this->root), val);
}

template <class T>
void BinaryTree<T>::addNode(struct node** node, T val){

	if(*node == NULL)	{
		struct node* tmp = new struct node;
		tmp->data = val;
		tmp->left=NULL;
		tmp->right = NULL;
		*node = tmp;

		this->treeSize++;
	}else{
		if(val > (*node)->data){
			addNode(&(*node)->right, val);
		}else{
			addNode(&(*node)->left, val);
		}
	}
}

template <class T>
void BinaryTree<T>::inOrderPrint(){
	inOrderPrint(this->root);
	std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::inOrderPrint(struct node* node){
	if(node != NULL){
		inOrderPrint(node->left);
		std::cout << node->data << ", ";
		inOrderPrint(node->right);
	}
}

template <class T>
void BinaryTree<T>::preOrderPrint(){
	preOrderPrint(this->root);
	std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::preOrderPrint(struct node* node){
	if(node != NULL)	{
		std::cout << node->data << ", ";
		inOrderPrint(node->left);
		inOrderPrint(node->right);
	}
}

template <class T>
void BinaryTree<T>::postOrderPrint(){
	postOrderPrint(this->root);
	std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::postOrderPrint(struct node* node){
	if(node != NULL){
		inOrderPrint(node->left);
		inOrderPrint(node->right);
		std::cout << node->data << ", ";
	}
}


template <class T>
void BinaryTree<T>::deleteTree(struct node* node){
	if(node != NULL){
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

template <class T>
bool BinaryTree<T>::lookup(T val){
	return lookup(this->root, val);
}

template <class T>
bool BinaryTree<T>::lookup(struct node* node, T val){
	if(node == NULL){
		return false;
	}else{
		if(val == node->data){
			return true;
		}

		if(val > node->data){
			return lookup(node->right, val);
		}else{
			return lookup(node->left, val);
		}
	}

}

int main(){
    BinaryTree<int> a;
    
    a.addNode(1);
    a.addNode(2);
    a.addNode(3);
    
    a.preOrderPrint();
}
