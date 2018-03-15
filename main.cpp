#include "stdafx.h"
#include<iostream>
#include<chrono>
#include<ctime>
#include "threeSorts.h"
#include "OrderedArray.h"
#include "reverseArray.h"
#include "mergeSort.h"
#include "tenArray.h"
#include "shuffledArray.h"
#include "array.h"


/****
how to use chrono
#include <iostream>
#include <chrono>
#include <ctime>

// Fibonacci series
long fibonacci(unsigned n){
	if (n < 2) return n;
	return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
// Using time point and system_clock
std::chrono::time_point<std::chrono::system_clock> start, end;

start = std::chrono::system_clock::now();
std::cout << "f(42) = " << fibonacci(42) << '\n';
end = std::chrono::system_clock::now();

std::chrono::duration<double> elapsed_seconds = end - start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);

std::cout << "finished computation at " << std::ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n";
}
***/


/***
So that I know where I am at with my fixing, I have only gone back and checked the headers and I have two mistakes on
reverse array that I need to fix, but I am not sure what it is that it is asking me on array.h
****/

using namespace std;

int main() {
/******************************************************************	
	//clock 
	chrono::time_point<chrono::system_clock> start, end;


	//user input for menu 
	int choice;
	//to make sure user doesnt input an invalid array size 
	bool badSize = false;
	//greeting message
	cout << "Hello! Welcome to Zaira and Dulce's Project 1!" << endl;
	
	//repeat menu so long user doesnt enter -1 at the end 
	do {
		//lets the user see the main menu
		cout << endl;
		cout << "_________________________________________" << endl;
		cout << "               MAIN MENU" << endl;
		cout << endl;
		//first asks for array size
		int size;
		cout << "Enter the size of array you want to sort:" << endl;
		cout << "100 or 1000 or 10000 or 100000 or 1000000" << endl;
		cin >> size;
		//create array
		//Array<int>(size);
		cout << endl;

		/*if (size != 100 || size != 1000 || size != 10000 || size != 100000 || size != 1000000) {
		cout << "Invalid size!" << endl;
		badSize = true;

		}*/
	/*************
		//then asks for array type
		int arrayType;
		cout << "Select the type of array you want to sort:" << endl;
		cout << "already sorted --> 1" << endl;
		cout << "completely shuffled --> 2" << endl;
		cout << "reversed order --> 3" << endl;
		cout << "shuffled at 10% --> 4" << endl;
		cin >> arrayType;
		cout << endl;

		//now with that input it asks which sort you want 
		cout << "To run bubble sort --> 1" << endl;
		cout << "To run insertion sort --> 2" << endl;
		cout << "To run selection sort --> 3" << endl;
		cout << "To run merge sort --> 4" << endl;
		cout << "To run quick sort --> 5" << endl;
		cout << endl;
		cout << "Exit project --> -1" << endl;
		cout << "_________________________________________" << endl;
		cout << endl;

		//takes user input and goes into switch
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "*********BUBBLE SORT**********" << endl;

			cout << endl;
			//ordered array 
			if (arrayType == 1) {
				cout << size << arrayType << endl;
				
				//Array<int> myArray(size);
				//myArray.setArray(0, size);
				OrderedArray<int> oR(size);
				
				//start = chrono::system_clock::now();
				//template<typename T>
				//threeSorts<int>::bubbleSort(oR, size)
				//end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//cout << "finished Bubble Sort at " << put_time(&end_time)
				//	<< "elapsed time: " << elapsed_seconds.count() << "s\n";

			}
			//completely shuffled 
			else if (arrayType == 2) {
				cout << size << arrayType << endl;
				//start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(OrderedArray, size);
				//end = chrono::system_clock::now();
				//get time
			//	chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

			//	cout << "finished Bubble Sort at " << ctime(&end_time)
			//		<< "elapsed time: " << elapsed_seconds.count() << "s\n";


			}
			//reverse ordered
			else if (arrayType == 3) {
				cout << size << arrayType << endl;
				//reverseArray<int> rA(size);
				//	start = chrono::system_clock::now();
					//template<typename T>
					//void threeSorts::bubbleSort(reverseArray, size);
				//	end = chrono::system_clock::now();
					//get time
					//chrono::duration<double> elapsed_seconds = end - start;
					//time_t end_time = chrono::system_clock::to_time_t(end);

					//cout << "finished Bubble Sort at " << ctime(&end_time)
					//	<< "elapsed time: " << elapsed_seconds.count() << "s\n";

			}
			//shuffled at 10
			else if (arrayType == 4) {
				cout << size << arrayType << endl;
				//tenArray<int> tA(size);
				//start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(tenArray, size);
				//end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

			//	cout << "finished Bubble Sort at " << ctime(&end_time)
			//		<< "elapsed time: " << elapsed_seconds.count() << "s\n";


			}
			//void tenArray<T> ::tenArray(size);


			//statement for bubblesort
			//add a cout that will ask what size array 
			//what kind of array 
			//add timer and cout 
			break;
		case 2:
			cout << "*********INSERTION SORT**********" << endl;

			cout << endl;

			if (arrayType == 1) {
				cout << size << arrayType << endl;
				OrderedArray<int> oR(size);
				//start = chrono::system_clock::now();
				//template<typename T>
				//bubbleSort(OrderedArray, size);
				//end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//cout << "finished Bubble Sort at " << put_time(&end_time)
				//	<< "elapsed time: " << elapsed_seconds.count() << "s\n";

			}
			else if (arrayType == 2) {
				cout << size << arrayType << endl;
				//start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(OrderedArray, size);
				//end = chrono::system_clock::now();
				//get time
				//	chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//	cout << "finished Bubble Sort at " << ctime(&end_time)
				//		<< "elapsed time: " << elapsed_seconds.count() << "s\n";


			}
			else if (arrayType == 3) {
				cout << size << arrayType << endl;
				//	start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(reverseArray, size);
				//	end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//cout << "finished Bubble Sort at " << ctime(&end_time)
				//	<< "elapsed time: " << elapsed_seconds.count() << "s\n";

			}
			else if (arrayType == 4) {
				cout << size << arrayType << endl;
				//start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(tenArray, size);
				//end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//	cout << "finished Bubble Sort at " << ctime(&end_time)
				//		<< "elapsed time: " << elapsed_seconds.count() << "s\n";


			}
			//void tenArray<T> ::tenArray(size);



			break;
		case 3:
			cout << "*********SELECTION SORT**********" << endl;

			if (arrayType == 1) {
				cout << size << arrayType << endl;
				//start = chrono::system_clock::now();
				//template<typename T>
				//bubbleSort(OrderedArray, size);
				//end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//cout << "finished Bubble Sort at " << put_time(&end_time)
				//	<< "elapsed time: " << elapsed_seconds.count() << "s\n";

			}
			else if (arrayType == 2) {
				cout << size << arrayType << endl;
				//start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(OrderedArray, size);
				//end = chrono::system_clock::now();
				//get time
				//	chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//	cout << "finished Bubble Sort at " << ctime(&end_time)
				//		<< "elapsed time: " << elapsed_seconds.count() << "s\n";


			}
			else if (arrayType == 3) {
				cout << size << arrayType << endl;
				//	start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(reverseArray, size);
				//	end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//cout << "finished Bubble Sort at " << ctime(&end_time)
				//	<< "elapsed time: " << elapsed_seconds.count() << "s\n";

			}
			else if (arrayType == 4) {
				cout << size << arrayType << endl;
				//start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(tenArray, size);
				//end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//	cout << "finished Bubble Sort at " << ctime(&end_time)
				//		<< "elapsed time: " << elapsed_seconds.count() << "s\n";


			}
			//void tenArray<T> ::tenArray(size);
			break;
		case 4:
			cout << "*********MERGE SORT**********" << endl;

			if (arrayType == 1) {
				cout << size << arrayType << endl;
				//start = chrono::system_clock::now();
				//mergeSort<array, array 
				//template<typename T>
				//bubbleSort(OrderedArray, size);
				//end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//cout << "finished Bubble Sort at " << put_time(&end_time)
				//	<< "elapsed time: " << elapsed_seconds.count() << "s\n";

			}
			else if (arrayType == 2) {
				cout << size << arrayType << endl;
				//start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(OrderedArray, size);
				//end = chrono::system_clock::now();
				//get time
				//	chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//	cout << "finished Bubble Sort at " << ctime(&end_time)
				//		<< "elapsed time: " << elapsed_seconds.count() << "s\n";


			}
			else if (arrayType == 3) {
				cout << size << arrayType << endl;
				//	start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(reverseArray, size);
				//	end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//cout << "finished Bubble Sort at " << ctime(&end_time)
				//	<< "elapsed time: " << elapsed_seconds.count() << "s\n";

			}
			else if (arrayType == 4) {
				cout << size << arrayType << endl;
				//start = chrono::system_clock::now();
				//mergeSort<T>::mergesort(T* arr, T* aux, int lo, int hi);
				//template<typename T>
				//void threeSorts::bubbleSort(tenArray, size);
				//end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//	cout << "finished Bubble Sort at " << ctime(&end_time)
				//		<< "elapsed time: " << elapsed_seconds.count() << "s\n";


			}
			//void tenArray<T> ::tenArray(size);

			break;
		case 5:
			cout << "*********QUICK SORT**********" << endl;

			if (arrayType == 1) {
				cout << size << arrayType << endl;
				//start = chrono::system_clock::now();
				//quickSort(array, 0, size - 1);
				//template<typename T>
				//bubbleSort(OrderedArray, size);
				//end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//cout << "finished Bubble Sort at " << put_time(&end_time)
				//	<< "elapsed time: " << elapsed_seconds.count() << "s\n";

			}
			else if (arrayType == 2) {
				cout << size << arrayType << endl;
				//start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(OrderedArray, size);
				//end = chrono::system_clock::now();
				//get time
				//	chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//	cout << "finished Bubble Sort at " << ctime(&end_time)
				//		<< "elapsed time: " << elapsed_seconds.count() << "s\n";


			}
			else if (arrayType == 3) {
				cout << size << arrayType << endl;
				//	start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(reverseArray, size);
				//	end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//cout << "finished Bubble Sort at " << ctime(&end_time)
				//	<< "elapsed time: " << elapsed_seconds.count() << "s\n";

			}
			else if (arrayType == 4) {
				cout << size << arrayType << endl;
				//start = chrono::system_clock::now();
				//template<typename T>
				//void threeSorts::bubbleSort(tenArray, size);
				//end = chrono::system_clock::now();
				//get time
				//chrono::duration<double> elapsed_seconds = end - start;
				//time_t end_time = chrono::system_clock::to_time_t(end);

				//	cout << "finished Bubble Sort at " << ctime(&end_time)
				//		<< "elapsed time: " << elapsed_seconds.count() << "s\n";
			}
			//void tenArray<T> ::tenArray(size);
			break;
		case -1: //exit menu
			exit(0);
		default:
			cout << "Please enter one of the valid options..." << endl;
		}//end switch 
	} while (choice != -1 || badSize == true);
	****************************/

	
	//OrderedArray arrayCreation; 

//reverseArray<int> array2(10);
//reverseArray<int> displayArray(array2);


//threeSorts<int> *bubble = nullptr;
//bubble->bubbleSort(array2, 10);
//bubbleSort(array1, 100);

reverseArray<int> *revAr =  new reverseArray<int>(5);
cout << "reversed Array:"<<endl;
revAr->displayArray();

cout << "ordered Array:" <<endl;
OrderedArray<int> *ordAr = new OrderedArray<int>(5);
ordAr->coutArray();

cout << "shuffled Array:" << endl;
shuffledArray<int> *shuffAr = new shuffledArray<int>(5);
shuffAr->displayShuffledArray();

//cout << "Ten Array:" << endl;
//tenArray<int> *tenAr = new tenArray<int>(5);
//tenAr->displayArray();




threeSorts<int> *sorter = new threeSorts<int>();
sorter->bubbleSort(revAr->getData(), 5);

revAr->displayArray();
}