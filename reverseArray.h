#include"array.h"
#include<iostream>

using namespace std; 

//This is the reverse array option
template<typename T>
class reverseArray{
	public:
		reverseArray(int _size) {
			size = _size;
			int val = 0;
			this->arr = (T*)malloc(sizeof(T) * size); // allocate memory for this array

													  // populate reverse array, which is just the same as ordered but backwards
			for (int i = size - 1; i > -1; i--, val++)
				this->arr[i] = val;
		}

		// destructor will delete array 
		~reverseArray(){
			delete this->myarray;
		}

		// Outputs the contents of the array to the console.
		void displayArray(){
			for (int i = 0; i < size; i++)
				cout << arr[i];
			cout <<" "<< endl;
		}

		// Public Getter for the array's data
		T* getData(){
			return this->arr;
		}

	private:
		// array's data
		T* arr;
		int size = 0;
};
