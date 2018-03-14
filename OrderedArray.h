template<typename T>
class OrderedArray{
public:
	// need size 
	int size; 
	
	//need to know it is an array
	T* myarray; 
	
	//the size is chosen by the user
	void array(T s){
		//size input becomes the new size
		size = s; 
		//now that is the new size of the array
		myarray = new T[size];
	}
	
	//constructor for this class 
	//actually think that int elem is useless in this format
	OrderedArray(T val){
		//creating an array with cont numbers 
		for (int i =0; i<this->size; val = val+1){
				this ->myarray[i] = val; 
		}
	}
	
	//destructor for this class 
	~OrderedArray(){
		delete this->myarray; 
	}
	
	//for testing purposes I want to see this array
	void coutArray(){
		for (int i = 0; i<size, i++){
			cout << this->myarray[i] << endl; 
		}
		cout << "This is your ordered array." << endl; 
	}
};