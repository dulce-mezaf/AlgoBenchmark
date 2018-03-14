#include<iostream>
#include<chrono>
#include<ctime>
#include "array.h"
#include "threeSorts.h"
#include "OrderedArray.h"
#include "reverseArray.h"
#include "mergeSort.h"
#include "tenArray.h"

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

int main(){
	//user input for menu 
	int choice; 

	//lets the user see the menu
	cout << "Hello! Welcome to our Project 1 menu" << endl; 
	cout << "To see how bubble sort works enter 1" << endl; 
	//will need several couts to see how it works 

	//takes user input 
	cin >> choice;

	//maybe add -1 to exit 
	switch(choice) { 
    case 1: 
        //statement for bubblesort
		//add a cout that will ask what size array 
		//what kind of array 
		//add timer and cout 
        break; 
    case 2: 
		//statement for insertion
		//add a statement that will ask what size array 
		//what kind of array 
		//add timer and cout 
		break; 
	case 3: 
		//statement for selection
		//add a statement that will ask what size array 
		//what kind of array 
		//add timer and cout 
		break; 
	case 4: 
		//statement for merge
		//add a statement that will ask what size array 
		//what kind of array 
		//add timer and cout 
	case 5: 
		//statement for quicksort 
		//add a statement that will ask what size array 
		//what kind of array 
		//add timer and cout 
	default:
	    cout << "Please enter one of the valid options..." << endl;
    }//end switch 
}