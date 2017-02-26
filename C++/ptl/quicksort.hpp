#ifndef __PTL_QUICKSORT_HPP__
#define __PTL_QUICKSORT_HPP__
#include <algorithm>
#include <cstddef>


namespace ptl {
	template <typename T>
	void quicksort(T[], int, int);

	template <typename T>
	void quicksort(T pArray[], size_t pSize){
		quicksort(pArray, 0, pSize - 1);
	}

	template <typename T>
	void quicksort(T pArray[], int pLeft, int pRight){
		int i = pLeft;
		int j = pRight;
		int pPivot = pArray[(pLeft + pRight) / 2];

		/* partition */
		while (i <= j){
			while (pArray[i] < pPivot){
				++i;
			}
			while (pArray[j] > pPivot){
				--j;
			}
			if (i <= j){
				std::swap(pArray[i], pArray[j]);
				++i;
				--j;
			}
		}

		/* recursion */
		if (pLeft < j){
			quicksort(pArray, pLeft, j);
		}
		if (i < pRight){
			quicksort(pArray, i, pRight);
		}
	}
}


#endif /* __PTL_QUICKSORT_HPP__ */

