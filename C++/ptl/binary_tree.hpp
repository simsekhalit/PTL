#ifndef __PTL_BINARY_TREE_HPP__
#define __PTL_BINARY_TREE_HPP__
#include <cstddef>
#include <iostream>


namespace ptl {
	template <class T>
	class BinaryNode {
	public:
		BinaryNode(T pData) : pData(pData), pLeft(NULL), pRight(NULL) {}
		T pData;
		BinaryNode *pLeft, *pRight;
	};

	template <class T>
	class BinaryTree
	{
	private:
		BinaryNode<T> *pRoot;
	public:
		BinaryTree() : pRoot(NULL) {}

		void insert(T pData){
			if (pRoot == NULL){
				pRoot = new BinaryNode<T>(pData);
				return;
			}
			BinaryNode<T> *pNode = pRoot;
			while (true){
				if (pData < pNode->pData){
					if (pNode->pLeft == NULL){
						pNode->pLeft = new BinaryNode<T>(pData);
						return;
					}
					pNode = pNode->pLeft;
				}
				else {
					if (pNode->pRight == NULL){
						pNode->pRight = new BinaryNode<T>(pData);
						return;
					}
					pNode = pNode->pRight;
				}
			}
		}

		BinaryNode<T>* search(T pData){
			BinaryNode<T>* pNode = pRoot;
			while (pNode != NULL) {
				if (pNode->pData == pData){
					return pNode;
				}
				if (pData < pNode->pData){
					pNode = pNode->pLeft;
				}
				else {
					pNode = pNode->pRight;
				}
			}
			return NULL;
		}

		void printPreorder(){
			printPreorder(pRoot);
			print();
		}

		void printPreorder(BinaryNode<T> *pNode){
			if (pNode){
				print(pNode);
				printPreorder(pNode->pLeft);
				printPreorder(pNode->pRight);
			}
		}

		void printInorder(){
			printInorder(pRoot);
			print();
		}

		void printInorder(BinaryNode<T> *pNode){
			if (pNode){
				printInorder(pNode->pLeft);
				print(pNode);
				printInorder(pNode->pRight);
			}
		}

		void printPostorder(){
			printPostorder(pRoot);
			print();
		}

		void printPostorder(BinaryNode<T> *pNode){
			if (pNode){
				printPostorder(pNode->pLeft);
				printPostorder(pNode->pRight);
				print(pNode);
			}
		}

		void print(){
			std::cout << std::endl;
		}

		void print(BinaryNode<T> *node){
			std::cout << node->pData << ' ';
		}
	};
}


#endif /* __PTL_BINARY_TREE_HPP__ */

