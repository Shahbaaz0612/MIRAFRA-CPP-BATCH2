#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<cstring>
using namespace std;

class File
{
	int fd;
	public:
	File(const char* path){

		fd=open(path,O_WRONLY);
		cout<<fd<<endl;
	}

	void write_data(const string& s){	
		write(fd,s.c_str(),s.size());
	}

	~File(){
		if(fd>0){
			close(fd);
		}
	}
};

int main()
{
	File f1("data.txt");
	File f2("ABC.txt");
	cout<<"Doing some work..."<<endl;
	string data1="In file 1";
	string data2="In file 2";
	f1.write_data(data1);
	f2.write_data(data2);
	return 0;

}
