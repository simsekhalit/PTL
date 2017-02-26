#include "binary_tree.hpp"
#include <algorithm>
#include <iostream>
using namespace std;


template <typename T>
void print (T pArray[], size_t pSize){
	for (size_t i = 0; i < pSize; ++i){
		cout << pArray[i] << " ";
	}
	cout << endl;
}

int main (){
	ptl::binary_tree<int> tree;
	tree.insert(16);
	tree.insert(20);
	tree.insert(8);
	cout << tree.search(16) << endl;
	tree.postorder();
	return 0;
}

