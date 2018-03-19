/**
This is the quicksort prototypes and implementations. Quick sort has a partition and a swap function in it 
This is a template of quicksort, it sorts each side of the pivot, it picks pivot to be the middle 
**/

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
//partition function
template <typename T>
int quickSort<T>::partition(T* myArray, int startIndex, int endIndex) {
	//pivot is the middle of the array 
	//int middle = (startIndex + endIndex) / 2;
	int pivot = myArray[startIndex + (endIndex - startIndex) / 2];
	//int pivot = myArray[endIndex];
	//int d = (startIndex - 1);
	for (int i = startIndex; i < endIndex; i++) {
		if (myArray[i] <= myArray[endIndex]) {
			
			swap(myArray, i, startIndex);
			startIndex++;
		}
	}
	swap(myArray, startIndex, endIndex);
	return startIndex;
}
//this one is called in main, takes in input from the partition 
template <typename T>
void quickSort<T>::quicksort(T* myArray, int left, int right) {
	//check to make sure we have more than one element 
	if (left < right) {
		int pivot = partition(myArray, left, right);
		//call quick sort 2 times:
		//sort before the pivot 
		quicksort(myArray, left, pivot - 1);
		//sort right after the pivot 
		quicksort(myArray, pivot + 1, right);
	}

}


 