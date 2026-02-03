#include<iostream>
using namespace std;
#include<atomic>
#include<thread>

atomic<int>counter={0};

void increment()
{
	for(int i=0;i<10000;i++)
	{
		counter++;
	}
}
void decrement()
{
	for(int i=0;i<1000;i++)
	{
		counter--;
	}
}

int main()
{
	thread t1(increment);
//	thread t2(increment);
	t1.join();
//	t2.join();
	
	thread t3(decrement);
	t3.join();

	cout<<"final counter value: "<<counter<<endl;
	return 0;

}
