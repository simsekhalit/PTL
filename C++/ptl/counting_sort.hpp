#ifndef __PTL_COUNTING_SORT_HPP__
#define __PTL_COUNTING_SORT_HPP__
#include <cstddef>


namespace ptl {

	// Stable version of Counting Sort
	// Please note that type T must be an Integer type
	template <typename T>
	void countingSort(T pArray[], size_t pSize, size_t pRange){

		// Create Counting Array and initialize all members to zero
		T pCount[pRange + 1], pOutput[pSize];
		for (size_t i = 0; i <= pRange; ++i){
			pCount[i] = 0;
		}
		
		// Count input array to counting array
		for (size_t i = 0; i < pSize; ++i){
			pCount[pArray[i]]++;
		}

		// Change pCount[i] so that pCount[i] now contains actual
		// position of this digit in pOutput[]
		for (size_t i = 1; i <= pRange; ++i){
			pCount[i] += pCount[i - 1];
		}

		// Build the output array
		for (int i = pSize - 1; i >= 0; --i){
			pOutput[pCount[pArray[i]] - 1] = pArray[i];
			pCount[pArray[i]]--;
		}

		// Copy from pOutput to pArray to finalize the sorting
		for (size_t i = 0; i < pSize; ++i){
			pArray[i] = pOutput[i];
		}
	}

	// Unstable version of Counting Sort
	// Please note that type T must be an Integer type
	template <typename T>
	void unstableCountingSort(T pArray[], size_t pSize, size_t pRange){

		// Create Counting Array and initialize all members to zero
		T pCount[pRange + 1];
		for (size_t i = 0; i <= pRange; ++i){
			pCount[i] = 0;
		}

		// Count input array to counting array
		for (size_t i = 0; i < pSize; ++i){
			pCount[pArray[i]]++;
		}

		// Modify input array to sorted array
		for (size_t i = 0, j = 0; i <= pRange; ++i){
			for (; pCount[i]; pCount[i]--){
				pArray[j++] = i;
			}
		}
	}
}


#endif /* __PTL_COUNTING_SORT_HPP__ */

