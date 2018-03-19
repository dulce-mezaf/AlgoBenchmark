#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "array.h"

using namespace std;

template<typename T>
class tenArray{

	public:
		// constructor for 10 array
		tenArray(long long _size) {
			srand((unsigned)time(NULL));
			size = _size;

			// 10% of the length
			double shuf = _size * 0.1;
			T val = 0;
			this->myarray = (T*)malloc(sizeof(T) * size); // allocate memory for this array

			// Initialize an ordered array first.
			for (int i = 0; i < size; i++, val++) {
				this->myarray[i] = val;
			}

			//cout << "Created an ordered array." << endl;

			//swap randindex swapping 
			for (int i = 0; i <= shuf; i++) {
				int randIndex = rand() % _size;
				int randIndex2 = rand() % _size;
				swap(randIndex, randIndex2);
				//cout << "Did some swapping" << endl;
			}
		}


		// destructor will delete array from memory
		~tenArray(){
			delete this->myarray;
		}

		// Outputs the contents of the array to the console.
		void displayArray(){
			//cout << "You are in the display function." << endl;
			for (int i = 0; i < size; i++)
				cout << this->myarray[i];
			cout << " " << endl;
		}


		// Public Getter for the array's data
		T* getData(){
			return this->myarray;
		}

	private:
		// array's data
		T* myarray;
		long long size;

		// Swap function used for shuffling the array data
		void swap(int i, int j){
			T temp;
			temp = this->myarray[i];
			this->myarray[i] = this->myarray[j];
			this->myarray[j] = temp;
		}
};
