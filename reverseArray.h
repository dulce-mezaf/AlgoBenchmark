#include<iostream>

using namespace std; 

//This is the reverse array option
template<typename T>
class reverseArray : public Array<T>{
	public:
		// constructor for ReverseArray
		reverseArray(int size){
			int val; 
			// populate reverse array, which is just the same as ordered but backwards
			for (int i = size - 1; i > -1; i--, val++)
				this->arr[i] = val; 
		}

		// destructor will delete array 
		~reverseArray(){
			delete this->arr;
		}

		// Outputs the contents of the array to the console.
		void displayArray(){
			for (int i = 0; i < size; i++)
				std::cout << arr[i] << std::endl;
		}

		// Public Getter for the array's data
		T* getData(){
			return this->arr;
		}

	private:
		// array's data
		T* arr;
};
