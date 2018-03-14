#ifndef ARRAY_H_
#define ARRAY_H_ 

//creating an array class, all our declarations are here
#include<iostream> 
using namespace std; 

template<typename T>
class Array{
private: 
	//for size and creation of array name 
	int size;
	T *myarray;
public: 
//constructor which is sizing it up 
	Array(int s) {
		size = s; 
		myarray = new T[size];
	}

	//fill the array up 
	void setArray(int elem, T val) {
		myarray[elem] = val; 
	}

	//array display 
	void getArray() {
		for (int i = 0; i < size; j++) {
			cout << myarray[i] << endl; 
		}
	}

	//check if array is in order, bool 
	bool ascendingOrder() {
		bool check;
		for (int i = 0; i < size; i++) {
			if (myarray[i + 1] > myarray[i]) {
				check = true;
			}
		}
		if (check == true) {
			cout << "Your array is in order" << endl;
		}
		else {
			cout << "This array is not in order." << endl; 
		}
	}//end of ascending order bool check
};

#endif