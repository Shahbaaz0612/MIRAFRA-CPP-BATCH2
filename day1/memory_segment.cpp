#include <iostream>
using namespace std;


int a = 10;         
int b;               
static int c = 20;   
const int d = 30;    

void fun() {}        

int main()
{
    int i = 5;              
    static int j = 15;     
    const int k = 25;      
    int* p = new int(40);   
 //global
    cout << "fun : " << (void*)&fun << endl;
    cout << "a: " << &a<<endl;
    cout << "b: " << &b<<endl;
    cout << "c: " << &c<<endl;
    cout << "d: " << &d<<endl;
//local
    cout << "i: " << &i<< endl;
    cout << "j: " << &j<< endl;
    cout << "k: " << &k<< endl;
    cout << "p: " << p<< endl;

    delete p;
    return 0;
}


