#include <iostream>
using namespace std;
class node
{
	public:
	int data;
	node *next;	
};
class list
{
	node *head;
	
	public:
	list()
	{
		head = NULL;
	}
	void InsertAtStart(int x)
	{
		node *temp = new node;
		temp->data = x;
		if (head == NULL)
		{
			head = temp;
			head->next = NULL;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
		
	}
	void InsertAtEnd(int x)
	{
		node *temp = new node;
		temp->data = x;
		temp->next = NULL;
		node *current;
		current = head;
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = temp;
		}
	}
	void print()
	{
		node *current;
		current = head;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	bool IsEmpty()
	{
		if(head==NULL)
		{
			return true;
		}
		else
		return false;
	}
	bool search(int x)
	{
		node* temp;
		temp=head;
		while(temp!=NULL)
		{
			if(temp->data==x)
			{
				return true;
			}
			temp=temp->next;
		}
		return false;
	}
	bool InsertBefore(int x, int y)
	{
		node *current;
		node *sub=new node;
		sub->data=y;
		sub->next=NULL;
		current=head;
		while(current->next!=NULL)
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
	void DeleteAll(int x)
	{
		node *current;
		current=head;
		while(current->next!=NULL)
		{
			if(current->next->data==x)
			{
				current->next=current->next->next;
			}
			current=current->next;
		}
	}
	void deletefromstart()
	{
		node *current;
		current=head->next;
		node *temp;
		temp=head;
		delete temp;
		head=current;
	}
	void unioni(const list obj1,const  list obj2)
	{
		node *temp1=obj1.head;
		node *temp2=obj2.head;
		list ref;
		while(temp1!=NULL)
		{
			ref.InsertAtEnd(temp1->data);
			temp1=temp1->next;
		}
		while(temp2!=NULL)
		{
			ref.InsertAtEnd(temp2->data);
			temp2=temp2->next;
		}
		ref.print();
	}
	~list()	
	{
		delete head;
	}      
};


int main()
{
	list obj1;
	cout<<"the values will be stored in linklist as  mentioned on manual "<<endl;
	obj1.InsertAtStart(2);
	obj1.InsertAtStart(6);
	obj1.InsertAtStart(7);
	obj1.InsertAtEnd(9);
	obj1.InsertAtStart(7);
	obj1.InsertAtStart(8);
	obj1.InsertAtStart(9);
	cout<<"now the insert before function will demonstrate as well by inserting 6 before 8"<<endl;
	obj1.InsertBefore(8,6);
	cout<<"printing the linked list"<<endl;
	obj1.print();
	cout<<"we will now search for 2 , 9 ,10"<<endl;
	if(obj1.search(2))
		cout<<"2 found"<<endl;
	else
		cout<<"2 not found"<<endl;
	if(obj1.search(9))
		cout<<"9 found"<<endl;
	else
		cout<<"9 not found"<<endl;
	if(obj1.search(10))
		cout<<"10 found"<<endl;
	else
		cout<<"10 not found"<<endl;
		
	cout<<"now we demonstrate delete from start "<<endl;
	obj1.deletefromstart();
	cout<<" NOW we print it again to review it"<<endl;
	obj1.print();
	cout<<"now we want to view union "<<endl;
	list obj2;
	obj2.InsertAtEnd(20);
	obj2.InsertAtEnd(23);
	obj2.InsertAtEnd(26);
	obj1.unioni(obj1,obj2);

}