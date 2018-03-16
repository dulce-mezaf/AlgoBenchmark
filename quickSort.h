#include<iostream>
using namespace std; 
template <class T >
class quickSort {
//private by default so we need it to be public
public:
	//these are the function prototypes 
	virtual void quicksort(T*, int left, int right);
	virtual int partition(T* arr, int start, int end);
	virtual void swap(T* arr, int i, int j);
};

//now all those prototypes are defined here
template<typename T>
void quickSort<T>::swap(T* myArray, int i, int j) {
	int temp;
	temp = myArray[i];
	myArray[i] = myArray[j];
	myArray[j] = temp;
}
//this one is called in main, takes in input from the partition 
template <typename T>
void quickSort<T>::quicksort(T* myArray, int left, int right) {
	if (left < right) {

		int pivot = partition(myArray, left, right);
		quicksort(myArray, left, pivot - 1);
		quicksort(myArray, pivot + 1, right);
	}
	return;
}

template <typename T>
int quickSort<T>::partition(T* myArray, int startIndex, int endIndex) {
	for (int i = startIndex; i < endIndex; i++) {
		if (myArray[i] <= myArray[endIndex]) {
			swap(myArray, i, startIndex);
			startIndex;
		}
	}
	swap(myArray, startIndex, endIndex);
	return startIndex;
}
 