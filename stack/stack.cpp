#include <iostream>
using namespace std;
template <typename T>
struct node
{
	node<T>*next;	
	T data;	
};
template <typename T>
class stack
{
	private:
		
	node<T>*head;
	
	public:
		
	stack()
	{
		head=NULL;
	}
	bool Isempty()
	{
		if(head==NULL)
			return true;
		else
			return false;
	}
	void push(T &val)
	{
		node <T> *temp= new node <T>;
		temp->data=val;
		if(Isempty())
		{
			temp->next=NULL;
			head=temp;
		}
		else
		{
			temp->next=head;
			head=temp;
		}
	}
	int getcurrentsize()
	{
		int size;

		if(Isempty())
		{
		size=0;
		}
		else
		{
		node <T>*current;
		current=head;
		while(current!=NULL)
		{
			size++;	
			current=current->next;
		}
		}
		return size;
	}
	void top(T &val)
	{
		val=head->data;
	}
	void pop()
	{
		if(!Isempty())
		{
			node <T>*temp= head;
			head = temp->next;
			delete temp;
		}
	}
};
int main()
{
	int a;
	stack <int> s1;
	for(int x=0;x<10;x++)
	{
		s1.push(x);
	}
	int size= s1.getcurrentsize();
	for(int y=0;y<size;y++)
	{
		s1.top(a);
		s1.pop();
		cout<<" "<<a;
	}
	
}
// TIME COMPLEXITY IS O(n)