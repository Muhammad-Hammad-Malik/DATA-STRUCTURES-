#include <iostream>
using namespace std;
struct node
{
	node *next;
	node *previous;
	int data;
};
class doublelinked
{
	private:
	node *head;
	public:
	doublelinked()
	{
		head=NULL;
	}
	void insert(int a)
	{
		node *current=head;
		node* temp=new node;
		temp->data=a;
		temp->next=NULL;
		temp->previous=NULL;
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			while(current->next!=NULL)
			{
				current=current->next;
			}
			current->next=temp;
			temp->previous=current;
		}
		
	}
	void print()
	{
		node *current=head;
		while(current!=NULL)
		{
			cout<<current->data<<" ";
			current=current->next;
		}
		cout<<endl;
	}
	void insertsorted(int a)
	{
		node* temp;
		temp->data=a;
		temp->next=NULL;
		temp->previous=NULL;
		node* current=head;
		if(current->data>=temp->data)
		{
			temp->next=head;
			temp->next->previous=temp;
			head=temp;
		}
		else
		{
			while((current->next!=NULL)&&(current->next->data<temp->data))
			{
				current=current->next;
			}
			temp->next=current->next;
			current->next=temp;
		
			current->next=temp;
			temp->previous=current;
		}
	}
	void search(int a)
	{
		bool found=false;
		node* current=head;
		while(current!=NULL)
		{
			if(current->data==a)
				found=true;
			current=current->next;	
		}
		if(found)
			cout<<a<<" found"<<endl;
		else
			cout<<a<<" not found"<<endl;
	}
};
int main()
{
 	doublelinked obj;
 	obj.insert(10);
 	obj.insert(20);
 	obj.insert(30);
 	obj.insert(40);
 	obj.print();
 	obj.search(30);
}