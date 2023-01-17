	#include <iostream>
	#include <cstdlib>
	#include <fstream>
	using namespace std;
	template <typename k,typename v>
	struct node
	{
		k key;
		v val;	
	};
	template <typename k,typename v>
	class minheap
	{
		private:
		node <k,v> *arr;
		int capacity;
		int total;
		
		public:
		minheap()
		{
			capacity=0;
			total=0;
			arr = NULL;	
		}	
		minheap(int x)
		{
			capacity=x;
			arr = new node <k,v> [capacity];
			total=0;
		}
		bool isEmpty()
		{
			if(total==0)
			{
				cout<<endl<<"IT IS EMPTY"<<endl;
				return true;
			}
			else
			{
				cout<<endl<<"IT IS NOT EMPTY"<<endl;
				return false;
			}
		}
		k getmin()
		{
			return arr[0].key;	
		}
	

		void ReheapDown(int root, int bottom)
		{
			int min, R, L;
			L = 2*root+1;
			R = 2*root+2;
			if(L <= bottom)
			{ 
				if(L == bottom)
					min = L;
				else 
				{
					if(arr[L].key >= arr[R].key)
					{
					min = R;
					}
					else
					{
					min = L;
					}
				}
				if(arr[root].key > arr[min].key) 
				{
					swap(arr[root], arr[min]);
					ReheapDown(min, bottom);
				}
			}
		}
		void insertion(k key1,v val1)
		{
			arr[total].key=key1;
			arr[total].val=val1;
			ReheapUp(0,total);
			total++;
		}	
		

		void print()
		{
			for(int a=0; a< total; a++)
			{
				cout<<arr[a].key<<endl;
				cout<<arr[a].val<<endl;
			}
			cout<<endl;
		}
		void ReheapUp(int root, int bottom)
		{
			int parent;
			if(bottom > root) 
			{ 
				parent = (bottom-1)/2;
				if(arr[parent].key > arr[bottom].key)
				{	
				swap(arr[parent],arr[bottom]);
				ReheapUp(root, parent);
				}
			}
		}
		int findmin()
		{
			int min =arr[0].key;
			int minindex=0;
			for(int a=0;a<total;a++)
			{
				if(arr[a].key<min)
				{
					min=arr[a].key;
					minindex=a;
				}
			}
			return minindex;
		}
		
		void deleteMin()
		{
			int a=findmin();
			swap(arr[total-1],arr[a]);
			total--;
			ReheapDown(0,total-1);
		}
	
};
class student
{
private:
	string name;
	float gpa;
public:
	student()
	{
		name=" ";
		gpa=0;
	}
	void setter(string xname,float xgpa)
	{
		name=xname;
		gpa=xgpa;
	}	
	
	friend ostream& operator << (ostream& out, student obj)
	{
	out<<obj.name<<endl;
	out<<obj.gpa<<endl;
	return out;
	}
	
};
void buildheap(minheap <int,student> &obj)
{
	ifstream file;
	file.open("students.txt");
	int total;
	file>>total;
	student onj[total];
	int roll;
	string name;
	float gpa;
	for(int a=0; a<total; a++)
	{
		file>>roll;
		file>>name;
		file>>gpa;
		onj[a].setter(name,gpa);
		obj.insertion(roll,onj[a]);
	}
}
int main()
{
	minheap <int,student> obj(20);
	buildheap(obj);
	obj.print();
	system("pause");
	cout<<endl<<"			PRESS ANY KEY TO GO FORWARD "<<endl;
	while(!obj.isEmpty())
	{
		cout<<obj.getmin()<<endl;
		obj.deleteMin();
	}
	system("pause");
	return 0;

}

