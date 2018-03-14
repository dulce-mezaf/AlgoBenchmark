#include<iostream>
using namespace std; 

class quickSort {
	//void quickSort() {

	//}
	//void quick();
	//void swap(T* arr, int i, int j);
};
//function prototypes --they are templates 
template <class T> 
T quickSort(T[], int, int);

template <class T>
T partition(T[], int, int);

template <class T>
T swap(T myArray, int, int);

//now we actually have the defenitions of the functions
template<class T>
T swap(T myArray, int i, int j) {
	int temp;
	temp = myArray[i];
	myArray[i] = myArray[j];
	myArray[j] = temp;
}

template <class T>
T quickSort(T myArray[], int left, int right) {
	if (left < right) {
		int pivot = parition(myArray, left, right);
		quickSort(myArray, left, pivot - 1);
		quickSort(myArray, pivot + 1, right);
	}
	return;
}

template <class T>
T partition(T myArray[], int startIndex, int endIndex) {
	for (int i = startIndex; i < endIndex; i++) {
		if (myArray[i] < = myArray[endIndex]) {
			swap(myArray, i, startIndex);
			startIndex;
		}
	}
	swap(myArray, startIndex, endIndex);
	return startIndex;
}



//used for swapping elements in the array.
//i already have a swap function somewhere so just use that in here somehow 