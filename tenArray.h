#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "array.h"


template<typename T>
class tenArray : public Array<T>
	{

	public:

		// Clone function for Prototype design pattern
		Array<T>* Clone()
		{
			return new tenArray<T>(size, choice, type);
		}

		// constructor for 10 array
		tenArray(int size){
			//seed to be used with time
			srand(time(NULL)); 

			// 10% of the length
			int cap = size * 0.1; 
			T val = (T)0.0;

			for (int i = 0; i < size; i++, val++)
				// Initialize an ordered array first.
				this->arr[i] = value;

			for (int i = 0; i < cap; i++)
			{
				// shuffle 10% of the array
				int randIndex = rand() % newSize;
				Swap(i, randIndex);
			}
		}

		// destructor will delete array from memory
		~tenArray(){
			delete this->arr;
		}

		// Outputs the contents of the array to the console.
		void displayArray(){
			for (int i = 0; i < size; i++)
				std::cout << this->arr[i] << std::endl;
		}


		// Public Getter for the array's data
		T* getData(){
			return this->arr;
		}

	private:
		// array's data
		T* arr;

		// Swap function used for shuffling the array data
		void swap(int i, int j){
			T temp;
			temp = this->arr[i];
			this->arr[i] = this->arr[j];
			this->arr[j] = temp;
		}
};