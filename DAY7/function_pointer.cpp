#include<iostream>
using namespace std;

void LED(int pin){
	cout<<"LED is turned ON uisng pin: "<<pin<<endl;
}

void Motor(int pin){
	cout<<"Motor is turned ON using pin: "<<pin<<endl;
}

int main(){
	bool LedStatus=true;
	bool MotorStatus=true;
	int LedPin=02;
	int MotorPin=05;
	void (*fptr)(int);
	
	if(LedStatus){
		fptr=LED;
		fptr(LedPin);
	}
	if(MotorStatus){
		fptr=Motor;
		fptr(MotorPin);
	}
}



