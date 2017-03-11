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

		void preorder(){
			preorder(pRoot);
		}

		void preorder(BinaryNode<T> *pNode){
			if (pNode){
				print(pNode);
				inorder(pNode->pLeft);
				inorder(pNode->pRight);
			}
		}

		void inorder(){
			inorder(pRoot);
		}

		void inorder(BinaryNode<T> *pNode){
			if (pNode){
				inorder(pNode->pLeft);
				print(pNode);
				inorder(pNode->pRight);
			}
		}

		void postorder(){
			postorder(pRoot);
		}

		void postorder(BinaryNode<T> *pNode){
			if (pNode){
				inorder(pNode->pLeft);
				inorder(pNode->pRight);
				print(pNode);
			}
		}

		void print(BinaryNode<T> *node){
			std::cout << node->pData << std::endl;
		}
	};
}


#endif /* __PTL_BINARY_TREE_HPP__ */

