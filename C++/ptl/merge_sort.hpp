#ifndef __PTL_MERGE_SORT_HPP__
#define __PTL_MERGE_SORT_HPP__
#include <cstddef>


namespace ptl {
	template <typename T>
	void mergeSort(T[], size_t, size_t);
	
	template <typename T>
	void mergeSortMerge(T[], size_t, size_t, size_t);

	// This algorithm takes advantage of the easiness of merging 2 sorted arrays that will result a new sorted array
	template <typename T>
	void mergeSort(T pArray[], size_t pSize) {
		mergeSort(pArray, 0, pSize - 1);
	}

	template <typename T>
	void mergeSort(T pArray[], size_t pLeft, size_t pRight){
		if (pLeft < pRight){
			size_t pMid = (pLeft + pRight) / 2;

			// Sorting first and second halves
			mergeSort (pArray, pLeft, pMid);
			mergeSort (pArray, pMid + 1, pRight);

			// Merging them afterwards
			mergeSortMerge (pArray, pLeft, pMid, pRight);
		}
	}

	template <typename T>
	void mergeSortMerge(T pArray[], size_t pLeft, size_t pMid, size_t pRight){
		size_t pSize1 = pMid - pLeft + 1;
		size_t pSize2 = pRight - pMid;

		// Temp Arrays
		T pLeftArr[pSize1], pRightArr[pSize2];

		// Saving original data to temp arrays
		for (size_t i = 0; i < pSize1; i++){
			pLeftArr[i] = pArray[pLeft + i];
		}
		for (size_t i = 0; i < pSize2; i++){
			pRightArr[i] = pArray[pMid + 1 + i];
		}

		// Merging
		size_t i = 0; // Initial index of first subarray
		size_t j = 0; // Initial index of second subarray
		size_t k = pLeft; // Initial index of merged subarray
		while (i < pSize1 && j < pSize2){
			if (pLeftArr[i] < pRightArr[j]){
				pArray[k] = pLeftArr[i];
				i++;
			}
			else {
				pArray[k] = pRightArr[j];
				j++;
			}
			k++;
		}

		// Copy the remaining elements if there are any
		while (i < pSize1){
			pArray[k] = pLeftArr[i];
			i++;
			k++;
		}
		while (j < pSize2){
			pArray[k] = pRightArr[j];
			j++;
			k++;
		}
	}
}


#endif /* __PTL_MERGE_SORT_HPP__ */

