#include"array.h"
#include<iostream>
using namespace std;

//this is the shuffled array option
template<typename T>
class shuffledArray {
public:
	shuffledArray(int _size) {
		size = _size;
		//allocate memory for this array
		this->arr = (T*)malloc(sizeof(T) * size);
		for (int i = 0; i < size; i++) {
			this->arr[i] = rand() % 10 + 1;
		}
	}

	//destructor to delete array
	shuffledArray() {
		delete this->myarray;
	}

	//displays shuffled array
	void displayShuffledArray() {
		for (int i = 0; i < size; i++)
			cout << arr[i] << endl;
	}

	//public getter for the array's data
	T* getData() {
		return this->arr;
	}

private:
	T* arr;
	int size = 0;
};