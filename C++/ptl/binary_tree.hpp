#ifndef __PTL_BINARY_TREE_HPP__
#define __PTL_BINARY_TREE_HPP__
#include <cstddef>
#include <iostream>


namespace ptl {
	template <class T>
	class binary_node {
	public:
		binary_node(T pData) : pData(pData), pLeft(NULL), pRight(NULL) {}
		T pData;
		binary_node *pLeft, *pRight;
	};

	template <class T>
	class binary_tree
	{
	private:
		binary_node<T> *pRoot;
	public:
		binary_tree() : pRoot(NULL) {}

		void insert(T pData){
			if (pRoot == NULL){
				pRoot = new binary_node<T>(pData);
				return;
			}
			binary_node<T> *pNode = pRoot;
			while (true){
				if (pData < pNode->pData){
					if (pNode->pLeft == NULL){
						pNode->pLeft = new binary_node<T>(pData);
						return;
					}
					pNode = pNode->pLeft;
				}
				else {
					if (pNode->pRight == NULL){
						pNode->pRight = new binary_node<T>(pData);
						return;
					}
					pNode = pNode->pRight;
				}
			}
		}

		binary_node<T>* search(T pData){
			binary_node<T>* pNode = pRoot;
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

		void preorder(){
			preorder(pRoot);
		}

		void preorder(binary_node<T> *pNode){
			if (pNode){
				print(pNode);
				inorder(pNode->pLeft);
				inorder(pNode->pRight);
			}
		}

		void inorder(){
			inorder(pRoot);
		}

		void inorder(binary_node<T> *pNode){
			if (pNode){
				inorder(pNode->pLeft);
				print(pNode);
				inorder(pNode->pRight);
			}
		}

		void postorder(){
			postorder(pRoot);
		}

		void postorder(binary_node<T> *pNode){
			if (pNode){
				inorder(pNode->pLeft);
				inorder(pNode->pRight);
				print(pNode);
			}
		}

		void print(binary_node<T> *node){
			std::cout << node->pData << std::endl;
		}
	};
}


#endif /* __PTL_BINARY_TREE_HPP__ */

