#include<iostream>
using namespace std;
#include<array>

class int_array{
	int *data;
	size_t size;

	public:
	size_t operator[](size_t index)
    	{
        	return data[index];
    	}

	size_t size() const
    	{
       	 	return size;
    	}

	T* begin(){ 
		return data; 
	}

    	T* end(){ 
		return data + size;
       	}

	int_array(const int_array& other){
		if(other.size)size=other.size;
		if(data)data=other.data;
		for(auto i=0; i<size; i++) {
			data[i]=other.data[i];
		}
	}

	void fill(const T& value)
	{
    		for (auto i=0; i<size; ++i){
        		data[i] = value;
		}
	}
	
	T& at(size_t index)
	{
    		if (index >= size_)
        		throw out_of_range("Array index out of range");
   		 return data[index];
	}
	


int main(){
	int_array<int, 5>arr;
	for(auto i:arr){
		cin>>i;
	}

	for(auto i:int_array){
		cout<<i<<" ";
	}cout<<endl;

	cout<<arr.at(6)<<endl;
}

