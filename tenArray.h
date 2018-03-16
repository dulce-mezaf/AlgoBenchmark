#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "array.h"


template<typename T>
class tenArray{

	public:
		// Clone function for Prototype design pattern
		Array<T>* Clone()
		{
			return new tenArray<T>(size, choice, type);
		}

		// constructor for 10 array
		tenArray(int _size){
			size = _size;
			int newSize = 1;

			// 10% of the length
			double cap = size * 0.1; 
			T val = (T)0.0;

			for (int i = 0; i < size; i++, val++)
				// Initialize an ordered array first.
				this->myarray[i] = val;

			for (int i = 0; i < cap; i++)
			{
				// shuffle 10% of the array
				int randIndex = rand() % newSize;
				swap(i, randIndex);
			}
		}

		// destructor will delete array from memory
		~tenArray(){
			delete this->myarray;
		}

		// Outputs the contents of the array to the console.
		void displayArray(){
			for (int i = 0; i < size; i++)
				cout << this->myarray[i] << endl;
		}


		// Public Getter for the array's data
		T* getData(){
			return this->myarray;
		}

	private:
		// array's data
		T* myarray;

		int size = 0;

		// Swap function used for shuffling the array data
		void swap(int i, int j){
			T temp;
			temp = this->myarray[i];
			this->myarray[i] = this->myarray[j];
			this->myarray[j] = temp;
		}
};