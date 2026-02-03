#include<iostream>
using namespace std;

class LED
{
	public:
		bool led_status=false;
		void led_init()
		{
			cout<<"initialising the LED"<<endl;
		}

		bool toggle_led()
		{
			if(led_status)
			led_status=false;
			else led_status=true;
			return led_status;
		}
		void display()
		{
			cout<<"led status: "<<led_status<<endl;
		}
};

int main()
{
	LED lobj;
	lobj.led_init();
	lobj.toggle_led();
	lobj.display();
}
	
			


