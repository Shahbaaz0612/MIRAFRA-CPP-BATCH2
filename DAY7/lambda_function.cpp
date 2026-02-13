#include<iostream>
using namespace std;

int main(){
	int threshold=50;
	int offset=10;
	bool enable_alarm=true;
	
	void fun(){
		cout<< offset <<endl;
	}


	auto sensor = [threshold, &enable_alarm] (int value) { 

		//passing threshold by value - can't modify, 
		 //enable_alarm by reference can modify it...
										
	};

	auto check_value = [&](int value) {  //passing reference, can modify all local values
			cout<<"threshold: "<<threshold<<endl;
			cout<<"threshold: "<<threshold<<endl;
			cout<<"offset: "<<offset<<endl;
			cout<<"enable_alarm: "<<enable_alarm<<endl;
			if(value<20){
				threshold=100;
				enable_alarm=false;
				offset=20;
			}
	};
	
	auto display = [=]( ) {

		//passing = operator, cannot modify all local values
		//just use the variables but can't modify it	
		
	};

	auto Display = [&] (int value) noexcept { 
		//
		//
		offset=value;
		if(offset < value){
			throw std::runtime_error("value modified\n");
		}
	};

	auto alter = [offset] () mutable {
		// offset is by value cant modify it 
                // but here we can modify as we used mutable keyword.
                offset = 20;
                cout<<"offset after mutable: "<<endl;
	};

		//check_value(55);
		Display(20);
}
