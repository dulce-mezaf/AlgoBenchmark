/*
This is the template of the shuffled array. You are allowed to display the array. It uses a seed to generate
random values each time it runs. 

*/
#include"array.h"
#include<iostream>
#include<time.h>
using namespace std;

//this is the shuffled array option
template<typename T>
class shuffledArray {
public:
	shuffledArray(int _size) {
		size = _size;
		//allocate memory for this array
		this->arr = (T*)malloc(sizeof(T) * size);
		//we want a random array each time
		srand((unsigned)time(NULL));
		for (int i = 0; i < size; i++) {
			//give each value a random number all the way up to 
			this->arr[i] = rand() % (size + 1);
		}
	}

	//destructor to delete array
	shuffledArray() {
		delete this->myarray;
	}

	//displays shuffled array
	void displayShuffledArray() {
		for (int i = 0; i < size; i++)
			cout << arr[i];
		cout << " "<<endl;
	}

	//public getter for the array's data
	T* getData() {
		return this->arr;
	}

private:
	T* arr;
	int size = 0;
};