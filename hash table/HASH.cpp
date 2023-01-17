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
};
template <class v>
class hash
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
	
	hash()
	{
		capacity=23;
		arr = new hashitem <v>[capacity];
		size=0;	
	}	
	hash(int x)
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
			int h=0;
			int a=0;
			if (arr[i].status != 0 && arr[i].status != 1)
			{
				int index = arr[i].key % capacity;
				while (temp[index].status != 0 && temp[index].status != 1)
				{
					index = arr[i].key%capacity;
					a=getindex(arr[i].key,h);
					index=index+a;
					index= index%capacity;
				}
				
					temp[index].key = arr[i].key;
					temp[index].value = arr[i].value;
					temp[index].status = arr[i].status;

				
			}
		}
		delete[] arr;
		arr = temp;
		capacity = capacity*2;
	}

	void insert(int k, v val)
	{
		float loadfactor=size/capacity;
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
			cout<<arr[a].key<<","<<arr[a].value<<"   ";
			else
			cout<<"$"<<"   ";
		}
		cout<<endl;
	}
	
	bool deleteit(int k)
	{
		int index=k%capacity;
		int i=0;
		int a=0;
		while(arr[index].key!=k)
		{
			index=k%capacity;
			a=getindex(k,i);
			index=index+a;
			index=index%capacity;
		}
		if(arr[index].key==k)
		{
			arr[index].status=2;
			size--;
			return true;
		}
		return false;
	}
	
	v* get(int k)
	{
		v* h;
		int index=k%capacity;
		int i=0;
		int a=0;
		while((arr[index].key!=k)&&(arr[index].status==1))
		{
			index=k%capacity;
			a=getindex(k,i);
			index=index+a;
			index=index%capacity;
		}
		if((arr[index].key==k)&&(arr[index].status==1))
		{
			h= &arr[index].value;
			return h;
		}
		cout<<"IT DOES NOT EXIST"<<endl;

		return NULL;
	}
	virtual ~hash()
	{
	cout<<endl<<"DESTRUCOR CALLED         "<<endl;	
	}
	
};
template <class v>
class  qhash : public hash <v>
{
private:
	int getindex(int key, int &i)
	{
		i++;
		int a=i*i;
		return a;
	}
public:
	qhash()
	{
		cout<<endl<<"                    QHASH CONSTRUCTOR"<<endl;
	}
	virtual ~qhash()
	{
		cout<<endl<<"                    QHASH DESTTRUCTOR"<<endl;
	}
};
template <class v>
class dhash : public hash <v>
{
private:
	int getindex(int key, int &i)
	{
		i++;
		int second_value=7-(key%7);
		int a=second_value*i;
		return a;
	}
public:
	dhash()
	{
		cout<<endl<<"                    DHASH CONSTRUCTOR"<<endl;
	}
	virtual ~dhash()
	{
		cout<<endl<<"                    DHASH DESTTRUCTOR"<<endl;
	}
};

void populate(string aname ,hash <string> *obj)
{
	ifstream file;
	file.open("students.txt");
	int size;
	int roll;
	string name;
	file>>size;
	for(int a=0;a<size;a++)
	{
		file >>roll;
		file >>name;
		obj->insert(roll,name);
	}
}
int main()
{
	hash <string> *obj;
	obj= new hash <string>;
	populate("student.txt",obj);
	obj->print();
	cout<<endl;
	cout<<*obj->get(153)<<endl;
	obj->deleteit(153);
	//assert(obj->get(9)==NULL);
	delete obj;
	
	obj= new qhash <string>;
	populate("student.txt",obj);
	obj->print();
	cout<<endl;
	cout<<*obj->get(153)<<endl;
	obj->deleteit(153);
	delete obj;
	
	obj= new dhash <string>;
	populate("student.txt",obj);
	obj->print();
	cout<<endl;
	cout<<*obj->get(153)<<endl;
	obj->deleteit(153);
	//assert(obj->get(9)==NULL);
	delete obj;
	system("pause");
	system("pause");
	return 0;
	
}

