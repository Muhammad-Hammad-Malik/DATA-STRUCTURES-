#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>
#include <fstream>
using namespace std;
template <class v>
struct hashitem
{
	int key;
	v value;
	short status;
	hashitem()
	{
		status=0;
	}
	void operator =(const hashitem& obj)
	{
		key=obj.key;
		value=obj.value;
		status=obj.status;
	}
};
template <class v>
class hashmap
{
protected:
	hashitem <v>*arr;
	int capacity;
	int size;
	virtual int getindex(int key, int &i)
	{
		i++;
		int a=i;
		return a;
	}
	public:
	
	hashmap()
	{
		capacity=10;
		arr = new hashitem <v>[capacity];
		size=0;	
	}	
	hashmap(int x)
	{
		capacity=x;
		assert(capacity>1);
		arr = new hashitem <v>[capacity];
		size=0;
	}
	void doublecapacity()
	{
		hashitem <v>* temp = new hashitem <v>[capacity*2];
		for (int i = 0; i < capacity; i++)
		{
			if (arr[i].status==1)
			{
				temp[i] = arr[i];
			}
		}
		delete[] arr;
		int c2 = capacity*2;
		arr = new hashitem<v>[c2];
		for(int i=0; i<c2; i++)
		{
			if(temp[i].status==1)
			{
				int index=temp[i].key%c2;
				int r=0;
				int a=0;
				while(arr[index].status==1)
				{
					index=arr[index].key%c2;
					a=getindex(arr[index].key,r);
					index=index+a;
					index=index%c2;	
				}
				arr[index]=temp[i];	

			}
		}
		capacity = capacity*2;
	}

	void insert(int k, v val)
	{
		float loadfactor = size;
		loadfactor/=capacity;
		if(loadfactor>=0.75)
		{
			doublecapacity();
		}
		int index=k%capacity;
		int i=0;
		int a=0;
		while(arr[index].status==1)
		{
			index=k%capacity;
			a=getindex(k,i);
			index=index+a;
			index=index%capacity;
		}
		if(arr[index].status!=1)
		{
			arr[index].key=k;
			arr[index].value=val;
			arr[index].status=1;
			size++;
		}
	}
	void print()
	{
		for(int a=0;a<capacity;a++)
		{
			if(arr[a].status==1)
			{
			cout<<arr[a].key<<" , "<<arr[a].value<<"   "<<endl;
			}
			else
			cout<<"$"<<"   "<<endl;
		}
		cout<<endl;
	}
	

	int sizeget()
	{
		return size;
	}
	int getcapacity()
	{
		return capacity;
	}
	virtual ~hashmap()
	{
	for(int a=0;a<capacity;a++)
	{
		arr[a].status=0;	
	}	
	cout<<endl<<"DESTRUCOR CALLED         "<<endl;	
	}
	
};


int main()
{
	hashmap <bool> *obj;
	obj= new hashmap <bool>;
	obj->insert(1,0);
	obj->insert(1,1);
	obj->print();

}

