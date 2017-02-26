#ifndef __PTL_RADIX_SORT_HPP__
#define __PTL_RADIX_SORT_HPP__
#include <cstddef>


namespace ptl {
	template <typename T>
	int radix_sort_get_max (T[], size_t);

	template <typename T>
	void radix_sort_counting (T[], size_t, size_t);

	// Please note that type T must be integral
	template <typename T>
	void radix_sort (T pArray[], size_t pSize){

		// Find the maximum number to determine range of digits
		int pMax = radix_sort_get_max (pArray, pSize);

		// Do counting sort for every digit. Note that instead
		// of passing digit number, exp is passed. exp is 10^i
		// where i is current digit number
		for (int pExp = 1; pMax/pExp > 0; pExp *= 10){
			radix_sort_counting (pArray, pSize, pExp);
		}
	}

	// A utility function to get maximum value in pArray[]
	template <typename T>
	int radix_sort_get_max (T pArray[], size_t pSize){
		T pMax = pArray[0];
		for (size_t i = 1; i < pSize; ++i){
			if (pArray[i] > pMax){
				pMax = pArray[i];
			}
		}
		return pMax;
	}

	// Counting sort for each digit
	template <typename T>
	void radix_sort_counting (T pArray[], size_t pSize, size_t pExp){
		T pOutput[pSize]; // Output array
		T pCount[10] = {0};
	 
		// Store count of occurrences in pCount[]
		for (size_t i = 0; i < pSize; i++){
			pCount[(pArray[i] / pExp) % 10]++;
		}
	 
		// Change pCount[i] so that pCount[i] now contains actual
		// position of this digit in pOutput[]
		for (size_t i = 1; i < 10; i++){
			pCount[i] += pCount[i - 1];
		}
	 
		// Build the output array
		for (int i = pSize - 1; i >= 0; i--){
			pOutput[pCount[(pArray[i] / pExp) % 10] - 1] = pArray[i];
			pCount[(pArray[i] / pExp) % 10]--;
		}
	 
		// Copy the output array to pArray[], so that pArray[] now
		// contains sorted numbers according to current digit
		for (size_t i = 0; i < pSize; i++){
			pArray[i] = pOutput[i];
		}
	}
}


#endif /* __PTL_RADIX_SORT_HPP__ */

