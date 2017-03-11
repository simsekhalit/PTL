#ifndef __PTL_INSERTION_SORT_HPP__
#define __PTL_INSERTION_SORT_HPP__
#include <algorithm>
#include <cstddef>


namespace ptl {
	template <typename T>
	void insertionSort(T pArray[], size_t pSize){
		for (size_t i = 1; i < pSize; ++i){
			for (size_t pIndex = i; pIndex > 0 && pArray[pIndex] < pArray[pIndex - 1]; --pIndex){
				std::swap(pArray[pIndex], pArray[pIndex - 1]);
			}
		}
	}
}


#endif /* __PTL_COUNTING_SORT_HPP__ */

