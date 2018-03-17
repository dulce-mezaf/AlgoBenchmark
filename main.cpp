#include "stdafx.h"
#include<iostream>
#include<chrono>
#include "threeSorts.h"
#include "OrderedArray.h"
#include "reverseArray.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "tenArray.h"
#include "shuffledArray.h"
#include "array.h"


using namespace std;
using namespace std::chrono;

int main() {
	threeSorts<int> *sorter = new threeSorts<int>();
	quickSort<int> *qSorter = new quickSort<int>();
	mergeSort<int> *mSorter = new mergeSort<int>();

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
		
		//asks for array size
		int size;
		cout << "Enter the size of array you want to sort:" << endl;
		cout << "100 or 1000 or 10000 or 100000 or 1000000" << endl;
		cin >> size;
		//ordered arrays -all sizes
		OrderedArray<int> *ordAr = new OrderedArray<int>(size);
	

		//reversed array-- all sizes 
		reverseArray<int> *revAr = new reverseArray<int>(size);
		

		//shuffled array -- all sizes
		shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
	

		cout << endl;

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
			/*******************************************************bubble sort*************************************************************/
		case 1:
			cout << "*********BUBBLE SORT**********" << endl;

			cout << endl;
			//ordered array
			if (arrayType == 1) {



				cout << "time start" << endl;
				//clock
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				sorter->bubbleSort(ordAr->getData(), size);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();

				//get time
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				cout << "BS Time: " << duration << "ms" << endl;


			}
			//completely shuffled
			else if (arrayType == 2) {
				cout << "shuffled array" << endl;
				cout << "time start" << endl;
				//clock
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				sorter->bubbleSort(shuffAr->getData(), size);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();

				//get time
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				cout << "BS Time: " << duration << "ms" << endl;

			}
			//reverse ordered
			else if (arrayType == 3) {
				cout << "reverse array " << endl;
				cout << "time start" << endl;
				//clock
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				sorter->bubbleSort(revAr->getData(), size);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();

				//get time
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				cout << "BS Time: " << duration << "ms" << endl;

			}
			//shuffled at 10
			else if (arrayType == 4) {
				cout << size << arrayType << endl;

			}

			break;
			/*******************************************************insertion sort*************************************************************/
		case 2:
			cout << "*********INSERTION SORT**********" << endl;

			cout << endl;
			//ordered array
			if (arrayType == 1) {



				cout << "time start" << endl;
				//clock
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				sorter->insertionSort(ordAr->getData(), size);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();

				//get time
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				cout << "IS Time: " << duration << "ms" << endl;


			}
			//completely shuffled
			else if (arrayType == 2) {
				cout << "shuffled array" << endl;
				cout << "time start" << endl;
				//clock
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				sorter->insertionSort(shuffAr->getData(), size);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();

				//get time
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				cout << "IS Time: " << duration << "ms" << endl;

			}
			//reverse ordered
			else if (arrayType == 3) {
				cout << "reverse array " << endl;
				cout << "time start" << endl;
				//clock
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				sorter->insertionSort(revAr->getData(), size);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();

				//get time
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				cout << "IS Time: " << duration << "ms" << endl;

			}
			//shuffled at 10
			else if (arrayType == 4) {
				cout << size << arrayType << endl;


			}

			break;
			/*******************************************************selection sort*************************************************************/
		case 3:
			cout << "*********SELECTION SORT**********" << endl;

			if (arrayType == 1) {
				cout << endl;
				//ordered array
				if (arrayType == 1) {

					cout << "time start" << endl;
					//clock
					high_resolution_clock::time_point t1 = high_resolution_clock::now();
					sorter->selectionSort(ordAr->getData(), size);
					high_resolution_clock::time_point t2 = high_resolution_clock::now();

					//get time
					auto duration = duration_cast<microseconds>(t2 - t1).count();

					cout << "SS Time: " << duration << "ms" << endl;


				}
				//completely shuffled
				else if (arrayType == 2) {
					cout << "shuffled array" << endl;
					cout << "time start" << endl;
					//clock
					high_resolution_clock::time_point t1 = high_resolution_clock::now();
					sorter->selectionSort(shuffAr->getData(), size);
					high_resolution_clock::time_point t2 = high_resolution_clock::now();

					//get time
					auto duration = duration_cast<microseconds>(t2 - t1).count();

					cout << "SS Time: " << duration << "ms" << endl;

				}
				//reverse ordered
				else if (arrayType == 3) {
					cout << "reverse array " << endl;
					cout << "time start" << endl;
					//clock
					high_resolution_clock::time_point t1 = high_resolution_clock::now();
					sorter->selectionSort(revAr->getData(), size);
					high_resolution_clock::time_point t2 = high_resolution_clock::now();

					//get time
					auto duration = duration_cast<microseconds>(t2 - t1).count();

					cout << "SS Time: " << duration << "ms" << endl;

				}
				//shuffled at 10
				else if (arrayType == 4) {
					cout << size << arrayType << endl;


				}
				break;
				/*******************************************************merge sort*************************************************************/
		case 4:
			cout << "*********MERGE SORT**********" << endl;

			cout << endl;
			//ordered array
			if (arrayType == 1) {

				cout << "time start" << endl;
				//clock
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				mSorter->mergesort(ordAr->getData(), 0, size - 1);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();

				//get time
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				cout << "MS Time: " << duration << "ms" << endl;


			}
			//completely shuffled
			else if (arrayType == 2) {
				cout << "shuffled array" << endl;
				cout << "time start" << endl;
				//clock
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				mSorter->mergesort(shuffAr->getData(), 0, size - 1);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();

				//get time
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				cout << "MS Time: " << duration << "ms" << endl;

			}
			//reverse ordered
			else if (arrayType == 3) {
				cout << "reverse array " << endl;
				cout << "time start" << endl;
				//clock
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				mSorter->mergesort(revAr->getData(), 0, size - 1);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();

				//get time
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				cout << "MS Time: " << duration << "ms" << endl;

			}
			//shuffled at 10
			else if (arrayType == 4) {
				cout << size << arrayType << endl;

			}

			break;
			/*******************************************************quick sort*************************************************************/
		case 5:
			cout << "*********QUICK SORT**********" << endl;

			cout << endl;
			//ordered array
			if (arrayType == 1) {
				cout << "ordered array" << endl;

				cout << "time start" << endl;
				//clock
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				qSorter->quicksort(ordAr->getData(), 0, size - 1);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();

				//get time
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				cout << "QS Time: " << duration << " ms" << endl;


			}
			//completely shuffled
			else if (arrayType == 2) {
				cout << "shuffled array" << endl;
				cout << "time start" << endl;
				//clock
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				qSorter->quicksort(shuffAr->getData(), 0, size - 1);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();

				//get time
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				cout << "QS Time: " << duration << "ms" << endl;

			}
			//reverse ordered
			else if (arrayType == 3) {
				cout << "reverse array " << endl;
				cout << "time start" << endl;
				//clock
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				qSorter->quicksort(revAr->getData(), 0, size - 1);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();

				//get time
				auto duration = duration_cast<microseconds>(t2 - t1).count();

				cout << "QS Time: " << duration << "ms" << endl;

			}
			//shuffled at 10
			else if (arrayType == 4) {
				cout << size << arrayType << endl;
			}
			break;

		case -1: //exit menu
			exit(0);

		default:
			cout << "Please enter one of the valid options..." << endl;
		}//end switch
		}
	}//end do 
		while (choice != -1 || badSize == true);



	}
		//OrderedArray arrayCreation;

	//reverseArray<int> array2(10);
	//reverseArray<int> displayArray(array2);


	//threeSorts<int> *bubble = nullptr;
	//bubble->bubbleSort(array2, 10);
	//bubbleSort(array1, 100);

	//reverseArray<int> *revAr =  new reverseArray<int>(5);
	//cout << "reversed Array:"<<endl;
	//revAr->displayArray();

	//cout << "ordered Array:" <<endl;
	//OrderedArray<int> *ordAr = new OrderedArray<int>(5);
	//ordAr->coutArray();

	//cout << "shuffled Array:" << endl;
	//shuffledArray<int> *shuffAr = new shuffledArray<int>(5);
	//shuffAr->displayShuffledArray();

	//cout << "Ten Array:" << endl;
	//tenArray<int> *tenAr = new tenArray<int>(5);
	//tenAr->displayArray();

	//cout << "bubble sort" << endl;
	//threeSorts<int> *sorter = new threeSorts<int>();
	//sorter->bubbleSort(revAr->getData(), 5);
	//revAr->displayArray();

	//cout << "selec sort" << endl;
	//sorter->selectionSort(revAr->getData(), 5);
	//revAr->displayArray();


	//cout << "quick sort" << endl;
	//quickSort<int> *qSort = new quickSort<int>();
	//qSort->quicksort(revAr->getData(), 0, 4);
	//revAr->displayArray();
	

