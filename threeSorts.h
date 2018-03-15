#include <iostream>

using namespace std; 

//3 sorts insert, selection and bubble
template <class T> 
class threeSorts{
public:
	virtual void bubbleSort(T* arr, int size); 
	void insertionSort(T* arr, int size);
	void selectionSort(T* arr, int size);
	void swap(T* arr, int i, int j);
};

//used for swapping elements in the array.
template<typename T>
void threeSorts<T>::swap(T* arr, int i, int j){
	T temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
	
//these functions all need to worry about time later
//bubbleSort
template <typename T> 
void threeSorts<T>::bubbleSort(T* arr, int size){
	int i,j;
	for (i=0; i<size-1; i++){
		for (j= 0; j<size-i-1; j++){
			if (arr[j]>arr[j+1]){
				swap(arr,j,j+1);
			}
		}
	
	}
}

//insertionSort 
template <typename T> 
void threeSorts<T>::insertionSort(T* arr, int size){
	int i, j, temp;
	for (i=0; i<size; i++){
		j = i;
		while (j>0 && arr[j]<arr[j-1]){
			//try doing swap here after it works
			temp = arr[j];
			arr[j] = arr[j-1];
			arr [j-1] = temp;
			j--; 
		}
	}
}


//selectionSort
template <typename T> 
void threeSorts<T>::selectionSort(T* arr, int size){
	int i,j, min; 
	
	for (i=0; i < (size-1); i++){
		min = i; 
		for (j = i+1; j < size ; j++){
			if (arr[j] < arr[min]){
				min = j;
			}
		//use a swap function
		swap(&arr[min], &arr[i]);
		}
	}
}

