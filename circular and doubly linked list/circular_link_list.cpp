#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class circlelist
{
	private:
		node *head;
	public:
		circlelist()
		{
			head=NULL;
		}
		void insert(int a)
		{
			node *current=head;
			node *temp=new node;
			temp->data=a;
			if(head==NULL)
			{
				head=temp;
				head->next=head;
			}
			else
			{
				while(current->next!=head)
				{
					current=current->next;
				}
				current->next=temp;
				temp->next=head;
			}
		}
		void print()
		{
			node *current=head;
			while(current->next!=head)
			{
				cout<<current->data<<" ";
				current=current->next;
			}
			cout<<endl;
		}
		bool InsertBefore(int x, int y)
		{
		node *current;
		node *sub=new node;
		sub->data=y;
		current=head;
		while(current->next!=head)
		{
			if(current->next->data==x)
			{
					sub->next=current->next;
					current->next=sub;
					return true;
			}
			current=current->next;	
		}	
		return false;
	}
	void search(int a)
	{
		bool found=false;
		node* current=head;
		while(current->next!=head)
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
	void check()
	{
		node* current=head;
		bool IsCircle=false;
		while(current->next!=head)
		{
			if(current->next->next==head)
			{
				IsCircle=true;
			}
			current=current->next;
		}
		if(IsCircle)
			cout<<" it is circular"<<endl;
			else
			cout<<"it is not circular"<<endl;
	}
	void replace(int x,int y)
	{
		node *current=head;
		while(current->next!=head)
		{
			if(current->data==x)
				current->data=y;
			current=current->next;
		}
	}
};
int main()
{
	circlelist obj;
	obj.insert(1);
	obj.insert(12);
	obj.insert(13);
	obj.insert(17);
	obj.insert(14);
	obj.print();
	obj.InsertBefore(12,18);
	obj.print();
	obj.search(18);
	obj.check();
	obj.replace(12,14);
	obj.print();
}