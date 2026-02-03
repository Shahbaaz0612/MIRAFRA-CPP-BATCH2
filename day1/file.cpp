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
	File f("data.txt");
	cout<<"Doing some work..."<<endl;
	string data="Hello_World";
	f.write_data(data);
	return 0;

}
