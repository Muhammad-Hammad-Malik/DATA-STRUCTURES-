#include <iostream>
using namespace std;
template <class T>
struct node
{
node *next;
T data;	
};
template <class T>
class SortedSet
{
	private:
		node<T>* head;
		node<T>* tail;
	public:
		
	SortedSet()
	{
		head=NULL;
	}	
	void InsertData(T const value)
	{
		node<T>*utility=new node<T>;
		utility->data=value;
		utility->next=NULL;
		node <T>*current;
		current=head;
		if(head==NULL)
		{
			head=utility;
			head->next=NULL;
		}
		else 
		{
			if(utility->data>current->data)
			{
				while(current->next!=NULL&& (current->next->data<=utility->data))
				{
					current=current->next;				
				}
				if (current->data != utility->data)
				{
					utility->next = current->next;
					current->next = utility;
				}
			}
			else
			{
				if (current->data != utility->data)
				{
					utility->next = head;
					head = utility;
				}
			}
				
			}
		}
	void print()
	{
		node<T> *current;
		current=head;
		while(current!=NULL)
		{
			cout<<current->data<<" ";
			current=current->next;
		}
		cout<<endl;
	}
	int sizegetter()
	{
		int count;
		node<T>* current;
		current=head;
		while(current!=NULL)
		{
			count++;
			current=current->next;
		}
		return count;
	}

	void rotation(int index)
	{
		node<T>*temp= new node<T>;
		temp->data=0;
		temp->next=head;
		node<T>*current;
		node<T>*current2;
		current=head;
		for(int a=0;a<index;a++)
		{
			current=current->next;
		}
		head=current;   // this will separate the second half of list
		
		current2=temp;

		for(int a=0;a<index;a++)
		{
			current2=current2->next;
		}
		current2->next=NULL; // to point it to NULL to avoid infinite loop
		
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=temp->next; // as temp is infact an empty node behind head
		
	}

};

int main()
{
	int size;
	int index;
	SortedSet<int> obj;
	obj.InsertData(10);
	obj.InsertData(20);
	obj.InsertData(30);
	obj.InsertData(40);
	obj.InsertData(50);
	obj.InsertData(60);
	obj.print();
	size=obj.sizegetter();
	size--;
	cout<<"Enter the index you want to rotate from max size is "<<size<<" ";
	cin>>index;
	while((index<=0)||(index>size))
	{
			cout<<"enter the index you want to rotate from maxsize is "<<size<<" ";
			cin>>index;
	}
	obj.rotation(index);
	obj.print();

}
