template<typename T>
class OrderedArray{
public:	
	OrderedArray(int _size) {
		size = _size;
		int val = 0;
		this->arr = (T*)malloc(sizeof(T) * size); // allocate memory for this array

												  // populate reverse array, which is just the same as ordered but backwards
		for (int i = 0; i < _size; i++,  val = val++) {
			this->arr[i] = val;
		}
	}
	//destructor for this class 
	~OrderedArray(){
		delete this->myarr; 
	}
	
	//for testing purposes I want to see this array
	void coutArray(){
		for (int i = 0; i < size; i++) {
			cout << arr[i];
			cout <<" "<< endl;
		}
		//cout << "This is your ordered array." << endl; 
	}
	// Public Getter for the array's data
	T* getData() {
		return this->arr;
	}

private:
	// array's data
	T* arr;
	int size = 0;
};