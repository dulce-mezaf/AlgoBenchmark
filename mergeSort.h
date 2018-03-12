#include "OrderedArray.h"
#include "tenArray.h"
#include "reverseArray.h" 

using namespace std; 

template <class T> 
class mergeSort{
	void mergeSort(T* arr, T* aux, int lo, int hi);
	void merge(T* arr, T* aux, int lo, int mid, int hi); 
};

/*
 NEEDS TIME ADDED SOMEHOW 
*/

//merge part of the sort 
template<typename T>
void merge(T* arr, T* aux, int lo, int mid, int hi) {

	for (int x = lo; x <= hi; ++x) {
		aux[x] = arr[x];
	}
	int i = lo;
	int j = mid + 1;

	for (int k = lo; k <= hi; ++k) {
		if (i > mid) {
			arr[k] = aux[j];
			++j;
		}
		else if (j > hi) {
			arr[k] = aux[i];
			++i;
		}
		else if (aux[i] < aux[j]) {
			arr[k] = aux[i];
			++i;
		}
		else {
			arr[k] = aux[j];
			++j;
		}
	}
}

/*here merge sort actually happens with
the assistance of the merge function above*/
template<typename T>
void mergeSort(T* arr, T* aux, int lo, int hi) {

	if (lo >= hi) {
		return;
	}
	//get middle
	int mid = (hi - lo) / 2 + lo;

	mergeSort(arr, aux, lo, mid);
	mergeSort(arr, aux, mid + 1, hi);
	merge(arr, aux, lo, mid, hi);

}
