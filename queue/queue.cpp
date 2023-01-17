#include <iostream>
using namespace std;
template <typename T>
struct node
{
	T data;
	node *next;
};
template <typename T>
class queue
{
	private:
		int size;
		node <T>*head;
		node <T>*back;
	public:
		queue()
		{
			size=0;
			head=NULL;
			back=NULL;
		}
		bool Isempty()
		{
			if(back==NULL)
			{
				return true;
			}
			return false;
		}
	    bool Isfull()
	    {
	    	if(back!=NULL)
	    	{
	    		return true;
			}
			return false;
		}
		void enqueue(T val)
		{
			size++;
			node <T>*temp=new node<T>;
			temp->data=val;
			if(Isempty())
			{
				head=temp;
				back=temp;
			}
			else
			{
				back->next=temp;
				back=temp;
			}
		}
		T front()
		{
			return head->data;
		}
		T rear()
		{
			return back->data;
		}
		int sizeget()
		{
			return size;
		}
		void dequeue()
		{
			size--;
			if(!Isempty())
			{
				node <T>*temp=new node<T>;
				temp=head;
				head=head->next;
				delete []temp;
			}
		}
};
int main()
{
	queue<int> obj;
	for(int a=0;a<5;a++)
	{
		obj.enqueue(a);
	}
	cout<<obj.front();
	obj.dequeue();
	cout<<endl<<obj.front();
	cout<<endl<<obj.rear();
	obj.dequeue();
	cout<<endl<<obj.sizeget();
	
}