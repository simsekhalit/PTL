#ifndef __PTL_SELECTION_SORT_H__
#define __PTL_SELECTION_SORT_H__
#include <algorithm>
#include <cstddef>


namespace ptl {
	template <typename T>
	void selection_sort(T pArray[], size_t pSize){
		for (size_t i = 0; i < pSize - 1; ++i){
			size_t pIndex = i;
			for (size_t j = i + 1; j < pSize; ++j){
				if (pArray[j] < pArray[pIndex]){
					pIndex = j;
				}
			}
			if (pIndex != i){
				std::swap(pArray[i], pArray[pIndex]);
			}
		}
	}
}


#endif /* __PTL_SELECTION_SORT_H__ */

