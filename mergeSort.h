/**
This has the prototypes and implementation of mergesort. We only have mergesort and merge function in here.
Mergesort is what is being called initially and then we have merge that put the merged arrays together. 
Remember that this is a template. 
**/
#include<iostream>
using namespace std; 

template <class T> 
class mergeSort{
//private by default so we need it to be public
public:
	//these are the function prototypes
	virtual void mergesort(T* arr, int left, int right);
	virtual void merge(T* arr, int leftLo, int leftHi, int rightLo, int rightHi);
	
};
//now all those prototypes are defined here
//merge part of the sort 
template<typename T>
void mergeSort<T>::merge(T* arr, int leftLo, int leftHi, int rightLo, int rightHi) {
	int length = rightHi - leftLo + 1;
	int* temp = new int[length];
	int left = leftLo;
	int right = rightLo;

	for (int i = 0; i <= length; ++i) {
		if (left > leftHi)
			temp[i] = arr[right++];
		else if (right > rightHi)
			temp[i] = arr[left++];
		else if (arr[left] <= arr[right])
			temp[i] = arr[left++];
		else
			temp[i] = arr[right++];
	}
	for (int i = 0; i < length; ++i)
		arr[leftLo++] = temp[i];
}

/*here merge sort actually happens with
the assistance of the merge function above*/
template<typename T>
void mergeSort<T>::mergesort(T* arr, int left, int right) {

	if (left >= right) {
		return; //not enough elems to sort
	}
	else {
		int middle = (left + right) / 2;
		mergesort(arr, left, middle);
		mergesort(arr, middle + 1, right);
		merge(arr, left, middle, middle + 1, right);
	}
}