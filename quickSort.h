#include "OrderedArray.h"
#include "tenArray.h"
#include "reverseArray.h" 

using namespace std; 

template <class t> 
class quickSort{
	void quickSort();
	void quick(); 
	void swap(T* arr, int i, int j);
};

//used for swapping elements in the array.
template<typename T>
void swap(T* arr, int i, int j){
	T temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}