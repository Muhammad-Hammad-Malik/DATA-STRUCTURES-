#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool ispair(char open,char close);
bool Balanced(string exp);

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
	T top()
	{
		T val=head->data;
		return val;
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
	bool flag=false;
	string expression="(())";
	if(Balanced(expression))
		flag=true;
	if(flag)
	{
		cout<<"the syntax is correct"<<endl;
	}
	else
	{
		cout<<"syntax is incorrect"<<endl;
	}
	flag =false;
	
	string anotherexpression="(({";
	if(Balanced(anotherexpression))
		flag=true;
	else flag =false;
	
	if(flag)
	{
		cout<<"the syntax is correct";
	}
	else
	{
		cout<<"syntax is incorrect";
	}
}

bool Balanced(string exp)
{
	stack<char>  obj;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			obj.push(exp[i]);
		}
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(obj.Isempty() || !ispair(obj.top(),exp[i]))
				return false;
			else
				obj.pop();
		}
	}
	return obj.Isempty();
}
bool ispair(char open,char close)
{
	if(open == '(' && close == ')') 
	{
	return true;
	}
	else if(open == '{' && close == '}')
	{
	 return true;
	}
	else if(open == '[' && close == ']')
	{
	  return true;
	}
	return false;
}

// time complexity is O(n)