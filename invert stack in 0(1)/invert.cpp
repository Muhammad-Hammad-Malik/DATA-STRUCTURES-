#include <iostream>
using namespace std;
template <typename T>
class stack
{
private:	
	bool invert; // it will indicate whether invert is called or not
	int size; // will indicate how many elements are pushed in it
	int capacity; // capacity will indicate the size of array it can change 
	T *arr;
	int top; 
	int start; // start will indicate how many times inverted pop is called
public:
	stack(int isize=0)
	{
		invert=false;
		start=0;
		if(size >= 0)
		{
			arr= new T[isize];
			size=0;
			capacity=isize;
			top=-1;
		}
		else
		{
			arr = nullptr;
			top=-1;
			size=0;
			capacity=0;
		}
	}
	bool Isempty()
	{
		return(size==0);
	}
	bool Isfull()
	{
		return(size!=0);
	}
	void inversion()
	{
		if(invert==true)
		{
			invert=false;// will invert if already inverted to restore orignal way
		}
		else if(invert==false)
		{
			invert=true; // will invert stack
		}
	}
	void push(T value)
	{
		if(size<capacity)
		{
		arr[++top]=value;
		size++;
		}
		else if(capacity==0)
		{
			arr = new T[1];
			arr[0]=value;
			top=0;
			size=1;
			capacity=1;
		}
		else
		{
			T* temp = new T[capacity * 2];
			for (int i = 0; i < size; i++) 
			{
			temp[i] = arr[i];
			}
			capacity=capacity*2;
			size++;
			temp[++top]=value;
			arr=temp;
		}
	}

	T pop()
	{
		T temp;
		if(invert) // if invert is called then pop will happen from beginning 
		{
			top=start;
			temp=arr[top];
			top++;
			start++;
		}
		else // regular way of popping will be done
		{
			top=size-1;
			temp=arr[top];
			top--;
			size--;
		}
		if(size<capacity/2) // memory effeciency is increased
		{
			T *temp= new T[capacity/2];
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}

			capacity = capacity / 2; 
			arr=temp;
			
		}
		return temp;
	}
	void print()
	{
		for(int a=start;a<size;a++)
		{
			cout<<arr[a] <<" ";
		}
		cout<<endl;
	}
	~stack()
	{
		delete []arr;
	}
};
int main()
{
	stack <int> obj1;
	for(int a=0;a<10;a++)
	{
		obj1.push(a);
	}
	cout<<" THE INITAL PUSHED STACK IS "<<endl;
	obj1.print();
	cout<<" BEFORE INVERSION THE POP WILL BE "<<endl;
	cout<<obj1.pop()<<endl;
	cout<<"THE MODIFIED STACK WOULD BE"<<endl;
	obj1.print();
	cout<<" AFTER INVERSION THE POP WOULD BECOME "<<endl;
	obj1.inversion();
	cout<<obj1.pop()<<endl;
	obj1.print();
	cout<<"THE STACK WOULD NOW BECOME "<<endl;
	obj1.print();
	//obj1.inversion(); // REMOVE THIS COMMENT TO RETURN TO UNINVERTED
	cout<<" NOW IF WE VIEW THE POPPED RESULTS OF ENTIRE REMANINIG STACK(inverted)"<<endl;
	obj1.inversion();
	obj1.print();
	for(int a=0;a<8;a++)
	{
		cout<<obj1.pop()<<endl;
	}
}