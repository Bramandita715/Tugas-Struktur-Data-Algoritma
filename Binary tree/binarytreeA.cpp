#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Node{
	public:
		Node *left;
		Node *right;
		int key;
		
		Node(){
			left = right = NULL;
		}
};

class BST {
	public:
		Node *root;
		
		BST(){
			root = NULL;
		}
		
		Node *insertRecursive(int inputKey, Node *currentRoot){
			
			if (currentRoot==NULL){
				Node *newNode = new Node();
				newNode->key = inputKey;
				return newNode;
			}
			if(inputKey < currentRoot->key){
				currentRoot->left = insertRecursive(inputKey, currentRoot->left);
			}
			else if (inputKey > currentRoot->key){
				currentRoot->right = insertRecursive(inputKey, currentRoot->right);
			}
			
			return currentRoot;
		}
		
		void insert(int inputKey){
			root = insertRecursive(inputKey, root);
		}
		
		void preOrderTraversal(Node *currentNode){
			if (currentNode!=NULL){
				cout << currentNode->key << " ";
				preOrderTraversal(currentNode->left);
				preOrderTraversal(currentNode->right);
			}
		}
		
		void postOrderTraversal(Node *currentNode){
			if (currentNode!=NULL){
				postOrderTraversal(currentNode->left);
				postOrderTraversal(currentNode->right);
				cout << currentNode->key << " ";
			}
		}
		
		void inOrderTraversal(Node *currentNode){
			if (currentNode!=NULL){
				inOrderTraversal(currentNode->left);
				cout << currentNode->key << " ";
				inOrderTraversal(currentNode->right);
			}
		}
		
		void findMax(Node *currentNode) {
        if (currentNode == NULL) {
            cout << "Pohon kosong" << endl;
            return;
        }
        while (currentNode != NULL && currentNode->right != NULL) {
            currentNode = currentNode->right;
        }
        cout << currentNode->key << " ";
    }
    
    	void findMin(Node *currentNode) {
        if (currentNode == NULL) {
            cout << "Pohon kosong" << endl;
            return;
        }
        while (currentNode != NULL && currentNode->left != NULL) {
            currentNode = currentNode->left;
        }
        cout << currentNode->key << " ";
    }
    
    	void search(int target, Node *currentNode) {
    		if (currentNode == NULL) {
        	cout << "Nilai " << target << " tidak ditemukan dalam pohon" << endl;
        	return;
    	}
    	if (target == currentNode->key) {
        	cout << "Nilai " << target << " ditemukan dalam pohon" << endl;
        	return;
    	}
    	if (target < currentNode->key) {
        	search(target, currentNode->left);
    	} 
		else {
        	search(target, currentNode->right);
    	}
}
		Node* remove(int key, Node* currentNode) {
    	if (currentNode == NULL) {
        	return currentNode;
    	}
    	if (key < currentNode->key) {
        	currentNode->left = remove(key, currentNode->left);
    	} else if (key > currentNode->key) {
        	currentNode->right = remove(key, currentNode->right);
    	} else{
        	if (currentNode->left == NULL) {
            	Node* temp = currentNode->right;
            	delete currentNode;
            	return temp;
        } else if (currentNode->right == NULL) {
            Node* temp = currentNode->left;
            delete currentNode;
            return temp;
    	}
        Node* successor = currentNode->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
        currentNode->key = successor->key;
		currentNode->right = remove(successor->key, currentNode->right);
    }
    return currentNode;
}
		void preOrder(){
			cout << "Pre Order Traversal: ";
			preOrderTraversal(root);
			cout << endl;
		}
		
		void postOrder(){
			cout << "Post Order Traversal: ";
			postOrderTraversal(root);
			cout << endl;
		}
		
		void inOrder(){
			cout << "In Order Traversal: ";
			inOrderTraversal(root);
			cout << endl;
		}
		
		void findMax(){
			cout << "Nilai terbesar: ";
			findMax(root);
			cout << endl;
		}
		
		void findMin(){
			cout << "Nilai terkecil: ";
			findMin(root);
			cout << endl;
		}
		
		void search(int target) {
    		search(target, root);
		}
		
		void remove(int key) {
    	root = remove(key, root);
    	}
};

int main(int argc, char** argv) {
	BST *bin1 = new BST();
	bin1->insert(6);
	bin1->insert(7);
	bin1->insert(4);
	bin1->insert(8);
	bin1->insert(5);
	bin1->insert(3);
	
	bin1->preOrder();
	bin1->inOrder();
	bin1->postOrder();
	bin1->findMax();
	bin1->findMin();
	int target = 7;
	bin1->search(target);
	int valueToRemove = 4;
    bin1->remove(valueToRemove);
	bin1->inOrder();
	
	return 0;
}