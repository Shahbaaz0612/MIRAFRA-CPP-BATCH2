#include<iostream>
using namespace std;

int main(){

	int *temp_sensor = new int[4]{2, 4, 30, 20};
	int *A_D_sensor = new int[4]{21, 32, 3, 45};
	
	int **p = new int* [2]{temp_sensor, A_D_sensor};
	
	for(int i=0; i<2; i++){
		for(int j=0; j<4; j++){
			cout << *(p[i])++ << " ";
		} cout<<endl;
	}
	return 0;
}

