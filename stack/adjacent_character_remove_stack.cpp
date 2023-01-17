#include <iostream>
#include <string>
#include <cstring>
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
	
	T pop()
	{
		T tempp;
		if(!Isempty())
		{
			tempp=head->data;
			node <T>*temp= head;
			head = temp->next;
			delete temp;
		}
		return tempp;
	}
};

int main()
{
	stack <char> s1;
	stack <char> s2;
	char *caller="ABCDDDEFGH";
	int size=strlen(caller);
	for(int a=0;a<size;a++)
	{
		s1.push(caller[a]);
	}
	char *arr=new char[size];
	for(int a=0;a<size;a++)
	{ 
		arr[a]=s1.pop();
	}
	int k=0,i=0,j=0;
    char *B= new char[size];
    for ( i = 0; i < size; i++)
    {
        for ( j = 0; j < k; j++)
        {
            if (arr[i] == B[j])
                break;
        }
        if (j == k)
        {
            B[k] = arr[i];
            k++;
        }
    }
    size--;
	for(int a=0;a<size;a++)
	{
		s2.push(B[a]);
	}
	cout<<" NOW WE SEE THE OUTPUT"<<endl;
	for(int a=0; a<size;a++)
	{
		cout<<" "<<s2.pop();
	}
	
}
// time complexity is O(n*n)