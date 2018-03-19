/*Allows user to collect times of each variation of the sort in a text file for statistical analysis OR they can
simply just run each variation one at a time. */
#include "stdafx.h"
#include<iostream>
#include<fstream>
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
	//allows me to access each sort from the different templates in this project
	threeSorts<int> *sorter = new threeSorts<int>();
	quickSort<int> *qSorter = new quickSort<int>();
	mergeSort<int> *mSorter = new mergeSort<int>();

	//user input for main menu in case 2 for runType switch (line 39)
	int choice;
	
	//user can choose if they want to run sort one by one or if they want
	//to run each sort with each type of array with the a choosen size all at once 
	//and output to a text file 
	int runType;
	//initialization of my file if case 2 is choosen 
	ofstream myfile;
	//greeting message
	cout << "Hello! Welcome to Zaira and Dulce's Project 1!\n" << endl;

	//ask user which run type they want
	cout << "Do you want to collect times of each sort for data analysis or run a sort 100 times at a time?" << endl;
	cout << "Data Collection please! -> 1" << endl;
	cout << "Run sort 100 times for each variation, works best right now! -> 2" << endl;
	cin >> runType;
	switch (runType) {
	case 1: //user wants to collect data!
		myfile.open("DataCollection.txt", ofstream::out); //opens file
		if (myfile.is_open()) {
			int size, sort;
			do {
				//asks for array size
				cout << "Which Sort:" << endl;
				cout << "To run bubble sort --> 1" << endl;
				cout << "To run insertion sort --> 2" << endl;
				cout << "To run selection sort --> 3" << endl;
				cout << "To run merge sort --> 4" << endl;
				cout << "To run quick sort --> 5" << endl;
				cin >> sort;

				cout << "Enter the size of array you want to sort:" << endl;
				cout << "10 or 1000 or 10000 or 100000 or 1000000" << endl;
				cout << "to exit enter -1" << endl;
				cin >> size;
			
				switch (sort) {
				case 1: //bubble sort
					switch (size) {
					case 10:
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;

					case 1000:
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					case 10000:
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					case 100000:
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";

						}
						myfile.close();
						break;
					case 1000000:
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************BS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					default:
						cout << "wrong input-inner" << endl;
						break;
					}


				case 2://insertion sort
					switch (size) {
					case 10:
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;

					case 1000:
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					case 10000:
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					case 100000:
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";

						}
						myfile.close();
						break;
					case 1000000:
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************IS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					default:
						cout << "wrong input-inner" << endl;
						break;
					}

				case 3://selection sort
					switch (size) {
					case 10:
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;

					case 1000:
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					case 10000:
						myfile << "****************SSTimes in miliseconds*******************************\n";
						myfile << "****************10000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							//shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
						//	revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
						//	revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							//ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							//tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					case 100000:
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							//shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							//revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************100,000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							//ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							//tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//tenAr->displayArray();
							myfile << duration << "\n";

						}
						myfile.close();
						break;
					case 1000000:
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							//shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							//revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							//ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************SS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							//tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->selectionSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					default:
						cout << "wrong input-inner" << endl;
						break;
					}

				case 4://merge sort 
					switch (size) {
					case 10:
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(shuffAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(revAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(ordAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(tenAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							tenAr->displayArray();
							myfile << duration << "\n";


						}
						//myfile.close();
						break;

					case 1000:
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							//shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(shuffAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							//revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(revAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							//ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(ordAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							//tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(tenAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					case 10000:
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							//shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(shuffAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
						//	shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							//revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(revAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							//ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(ordAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							//tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(tenAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					case 100000:
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							//shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(shuffAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							//revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(revAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							//ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(ordAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							//tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(tenAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//tenAr->displayArray();
							myfile << duration << "\n";

						}
						myfile.close();
						break;
					case 1000000:
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							//shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(shuffAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							//revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(revAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							//ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(ordAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************MS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							//tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(tenAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					default:
						cout << "wrong input-inner" << endl;
						break;
					}

				case 5://quick sort
					switch (size) {
					case 10:
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(shuffAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(revAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							//ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(ordAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************10 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							//tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(tenAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;

					case 1000:
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							//shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(shuffAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							//revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(revAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							//ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(ordAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************1000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							//tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(tenAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					case 10000:
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							//shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(shuffAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							//revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(revAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							//ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(ordAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************10000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							//tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(tenAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					case 100000:
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							//shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(shuffAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							//revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(revAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							//ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(ordAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************100000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							//tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(tenAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//tenAr->displayArray();
							myfile << duration << "\n";

						}
						myfile.close();
						break;
					case 1000000:
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--SHUFFLED******************************************\n";
						cout << "shuffled" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "not sorted" << endl;
							//shuffAr->displayShuffledArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(shuffAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//shuffAr->displayShuffledArray();
							myfile << duration << "\n";


						}

						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--REVERSED******************************************\n";
						cout << "reversed" << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "not sorted" << endl;
							//revAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(revAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//revAr->displayArray();
							myfile << duration << "\n";


						}
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--ORDERED******************************************\n";
						cout << "ordered" << endl;
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "not sorted" << endl;
							//ordAr->coutArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(ordAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//ordAr->coutArray();
							myfile << duration << "\n";


						}
						myfile << "****************QS Times in miliseconds*******************************\n";
						myfile << "****************1000000 elements--TEN ARRAY******************************************\n";
						cout << "ten" << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "not sorted" << endl;
							//tenAr->displayArray();
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(tenAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							cout << "sorted" << endl;
							//tenAr->displayArray();
							myfile << duration << "\n";


						}
						myfile.close();
						break;
					default:
						cout << "wrong input-inner" << endl;
						break;
					}
				default:
					cout << "wrong input-outer" << endl;
					break;
				}//end of first case of outer switch (sort)

			} while (size != -1);
			myfile.close();
		}
		else
			cout << "unable to open file";
		return 0;
	

		break; //end of case 1 (run sorts to collect data)



	case 2://user wants to run one sort at a time
		myfile.open("DataCollection.txt", ofstream::out); //opens file
		if (myfile.is_open()) {
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
				cout << "10 or 1000 or 10000 or 100000 or 1000000" << endl;
				cin >> size;
				//ordered arrays -all sizes
				OrderedArray<int> *ordAr = new OrderedArray<int>(size);
				//reversed array-- all sizes 
				reverseArray<int> *revAr = new reverseArray<int>(size);
				//shuffled array -- all sizes
				shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
				//Ten array -- all sizes
				tenArray<int> *tenAr = new tenArray<int>(size);


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

						myfile << "**************************bubble Sort time in MicroSec*************************\n";
						myfile << "*********************************ordered Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "time start" << endl;
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile << duration << endl;
						}
						myfile.close();

					}
					//completely shuffled
					else if (arrayType == 2) {
						cout << "shuffled array" << endl;
						myfile << "**************************bubble Sort time in MicroSec*************************\n";
						myfile << "*********************************shuffled Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "time start" << endl;
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile  << duration << endl;
						}
						myfile.close();

					}
					//reverse ordered
					else if (arrayType == 3) {
						cout << "reverse array " << endl;
						myfile << "**************************bubble Sort time in MicroSec*************************\n";
						myfile << "*********************************reversed Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "time start" << endl;
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile << duration << endl;
						}
						myfile.close();

					}
					//shuffled at 10
					else if (arrayType == 4) {
						cout << "ten array " << endl;
						myfile << "**************************bubble Sort time in MicroSec*************************\n";
						myfile << "*********************************ten Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "time start" << endl;
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->bubbleSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile << duration << endl;
						}
						myfile.close();

					}

					break;
					/*******************************************************insertion sort*************************************************************/
				case 2:
					cout << "*********INSERTION SORT**********" << endl;

					cout << endl;
					//ordered array
					if (arrayType == 1) {
						myfile << "**************************insertion Sort time in MicroSec*************************\n";
						myfile << "*********************************ordered Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "time start" << endl;
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(ordAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile << duration << endl;
						}
						myfile.close();
					}

					//completely shuffled
					else if (arrayType == 2) {
						cout << "shuffled array" << endl;
						myfile << "**************************insertion Sort time in MicroSec*************************\n";
						myfile << "*********************************shuffled Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "time start" << endl;
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(shuffAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();


							myfile << duration << endl;
						}
						myfile.close();
					}
					//reverse ordered
					else if (arrayType == 3) {
						cout << "reverse array " << endl;
						myfile << "**************************insertion Sort time in MicroSec*************************\n";
						myfile << "*********************************reversed Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "time start" << endl;
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(revAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile << duration << endl;
						}
						myfile.close();

					}
					//shuffled at 10
					else if (arrayType == 4) {
						cout << "ten array " << endl;
						myfile << "**************************insertion Sort time in MicroSec*************************\n";
						myfile << "*********************************ten Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							cout << "time start" << endl;
							tenArray<int> *tenAr = new tenArray<int>(size);
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							sorter->insertionSort(tenAr->getData(), size);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile << duration << endl;

						}
						myfile.close();

					}

					break;
					/*******************************************************selection sort*************************************************************/
				case 3:
					cout << "*********SELECTION SORT**********" << endl;

					if (arrayType == 1) {
						cout << endl;
						//ordered array
						myfile << "**************************selection Sort time in MicroSec*************************\n";
						myfile << "*********************************ordered Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
								cout << "time start" << endl;
								//clock
								high_resolution_clock::time_point t1 = high_resolution_clock::now();
								sorter->selectionSort(ordAr->getData(), size);
								high_resolution_clock::time_point t2 = high_resolution_clock::now();

								//get time
								auto duration = duration_cast<microseconds>(t2 - t1).count();

								myfile << duration << endl;
							}
							myfile.close();

						}
						//completely shuffled
						else if (arrayType == 2) {
							cout << "shuffled array" << endl;
							myfile << "**************************selection Sort time in MicroSec*************************\n";
							myfile << "*********************************shuffled Array***********************\n";
							myfile << "**************************" << size << " elements*********************************\n";
							for (int i = 0; i < 100; i++) {
								cout << "time start" << endl;
								shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
								//clock
								high_resolution_clock::time_point t1 = high_resolution_clock::now();
								sorter->selectionSort(shuffAr->getData(), size);
								high_resolution_clock::time_point t2 = high_resolution_clock::now();

								//get time
								auto duration = duration_cast<microseconds>(t2 - t1).count();


								myfile << duration << endl;
							}
							myfile.close();

						}
						//reverse ordered
						else if (arrayType == 3) {
							cout << "reverse array " << endl;
							myfile << "**************************selection Sort time in MicroSec*************************\n";
							myfile << "*********************************reversed Array***********************\n";
							myfile << "**************************" << size << " elements*********************************\n";
							for (int i = 0; i < 100; i++) {
								cout << "time start" << endl;
								reverseArray<int> *revAr = new reverseArray<int>(size);
								//clock
								high_resolution_clock::time_point t1 = high_resolution_clock::now();
								sorter->selectionSort(revAr->getData(), size);
								high_resolution_clock::time_point t2 = high_resolution_clock::now();

								//get time
								auto duration = duration_cast<microseconds>(t2 - t1).count();

								myfile << duration << endl;
							}
							myfile.close();

						}
						//shuffled at 10
						else if (arrayType == 4) {
							cout << "ten array " << endl;
							myfile << "**************************selection Sort time in MicroSec*************************\n";
							myfile << "*********************************ten Array***********************\n";
							myfile << "**************************" << size << " elements*********************************\n";
							for (int i = 0; i < 100; i++) {
								cout << "time start" << endl;
								tenArray<int> *tenAr = new tenArray<int>(size);
								//clock
								high_resolution_clock::time_point t1 = high_resolution_clock::now();
								sorter->selectionSort(tenAr->getData(), size);
								high_resolution_clock::time_point t2 = high_resolution_clock::now();

								//get time
								auto duration = duration_cast<microseconds>(t2 - t1).count();

								myfile << duration << endl;
							}
							myfile.close();


						}
						break;
						/*******************************************************merge sort*************************************************************/
				case 4:
					cout << "*********MERGE SORT**********" << endl;

					cout << endl;
					//ordered array
					if (arrayType == 1) {
						myfile << "**************************Merge Sort time in MicroSec*************************\n";
						myfile << "*********************************ordered Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "time start" << endl;
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(ordAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile << duration << endl;
						} myfile.close();

					}
					//completely shuffled
					else if (arrayType == 2) {
						myfile << "**************************Merge Sort time in MicroSec*************************\n";
						myfile << "*********************************shuffled Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						cout << "shuffled array" << endl;
						for (int i = 0; i < 100; i++) {
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							cout << "time start" << endl;
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(shuffAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile << duration << endl;
						} myfile.close();

					}
					//reverse ordered
					else if (arrayType == 3) {
						myfile << "**************************Merge Sort time in MicroSec*************************\n";
						myfile << "*********************************reverse Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						cout << "reverse array " << endl;
						for (int i = 0; i < 100; i++) {
							reverseArray<int> *revAr = new reverseArray<int>(size);
							cout << "time start" << endl;
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(revAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile << duration << endl;
						}
						myfile.close();

					}
					//shuffled at 10
					else if (arrayType == 4) {
						myfile << "**************************Merge Sort time in MicroSec*************************\n";
						myfile << "*********************************ten Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						cout << "ten array " << endl;
						for (int i = 0; i < 100; i++) {
							tenArray<int> *tenAr = new tenArray<int>(size);
							cout << "time start" << endl;
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							mSorter->mergesort(tenAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile << duration << endl;

						}

						myfile.close();
					}
						break;
						/*******************************************************quick sort*************************************************************/
				case 5:
					cout << "*********QUICK SORT**********" << endl;

					cout << endl;
					//ordered array
					if (arrayType == 1) {
						cout << "ordered array" << endl;
						myfile << "**************************quick Sort time in MicroSec*************************\n";
						myfile << "*********************************ordered Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							OrderedArray<int> *ordAr = new OrderedArray<int>(size);
							cout << "time start" << endl;
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(ordAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile << duration << endl;
						}
						myfile.close();

					}
					//completely shuffled
					else if (arrayType == 2) {
						cout << "shuffled array:\n" << endl;
						myfile << "**************************quick Sort time in MicroSec*************************\n";
						myfile << "*********************************shuffled Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							//shuffAr->displayShuffledArray();
							cout << "time start" << endl;
							shuffledArray<int> *shuffAr = new shuffledArray<int>(size);
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(shuffAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();
							//shuffAr->displayShuffledArray();

							myfile << duration << endl;
						}
						myfile.close();

					}
					//reverse ordered
					else if (arrayType == 3) {
						cout << "reverse array " << endl;
						myfile << "**************************quick Sort time in MicroSec*************************\n";
						myfile << "*********************************reversed Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							cout << "time start" << endl;
							reverseArray<int> *revAr = new reverseArray<int>(size);
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(revAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							cout << duration << endl;
						}
						myfile.close();

					}
					//shuffled at 10
					else if (arrayType == 4) {
						cout << "ten array " << endl;
						myfile << "**************************quick Sort time in MicroSec*************************\n";
						myfile << "*********************************ten Array***********************\n";
						myfile << "**************************" << size << " elements*********************************\n";
						for (int i = 0; i < 100; i++) {
							cout << "time start" << endl;
							tenArray<int> *tenAr = new tenArray<int>(size);
							//clock
							high_resolution_clock::time_point t1 = high_resolution_clock::now();
							qSorter->quicksort(tenAr->getData(), 0, size - 1);
							high_resolution_clock::time_point t2 = high_resolution_clock::now();

							//get time
							auto duration = duration_cast<microseconds>(t2 - t1).count();

							myfile << duration << endl;
						}
						myfile.close();
					}
					break;

				case -1: //exit menu
					exit(0);

				default:
					cout << "Please enter one of the valid options..." << endl;
					}//end switch
					}
 
				while (choice != -1);

			}
		
		else
			cout << "UNABLE TO OPEN FILE.";
			return 0;
		break; //end of case 2 (run sort one at a time)

	}//end of runType switch



	}




