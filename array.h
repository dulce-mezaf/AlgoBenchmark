//creating an array class, all our declarations are here
#include<iostream> 
using namespace std; 

template<typename T>
class Array{
public:
    Array(T arr[], int data);
	~Array();
	
	//will get size of array from user
	int getSize(int x){
	}
	
private:
	//array data should be private
   T* arr; 
   
   //size of the array 
   int size; 
};

//constructing the array 
template <typename T> 
Array<T>::Array(T arr[], int data){
	arr = new T[size];
	for (int i = 0; i<size; i++){
		//want a random population 
		
	}
}