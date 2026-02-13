#include<iostream>
using namespace std;
#include<deque>

struct linklist{
	linklist *next;
	linklist *prev;
	int data;
};

linklist*  push_back(struct linklist* &head, int data){
		if(head==nullptr){
			linklist* nn = new linklist;
			head=nn;
			head->prev = nullptr;
			head->next = nullptr;
			head->data = data;
		}
		else{
			linklist* temp = head;
			while(temp->next){
				temp = temp->next;
			}
			
			linklist *nn = new linklist();
			temp->next = nn;
			nn->next = nullptr;
			nn->prev = temp;
			nn->data = data; 
		}
		return head;
}

linklist* push_front(struct linklist* &head, int data){
        linklist* nn = new linklist;
        nn->data = data;
        nn->prev = nullptr;
        nn->next = head;

        if(head != nullptr){
                head->prev = nn;
        }

        head = nn;
        return head;
}

void print(linklist* head){
	while(head){
		cout<< head->data << " -> ";
		head=head->next;
	}
	cout<<endl;
}

int main() {

	struct linklist *head=nullptr;

	head = push_back(head,10);
	head = push_back(head,20);
	head = push_back(head,30);
	
	print(head);
	
	while(head){
		linklist* temp = head;
		head=head->next;
		delete temp;
	}
	return 0;
}

