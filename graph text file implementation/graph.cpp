#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;
string *strarr;
ifstream file;
int ssize;

	template <typename k,typename v>
	struct nodes
	{
		k key;
		v val;	
	};
	template <typename k,typename v>
	class minheap
	{
		private:
		nodes <k,v> *arr;
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
			arr = new nodes <k,v> [capacity];
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

struct node
{
	int id;
	int weight;
	string location;
	node()
	{
		id=0;
		weight=0;
		location=" ";	
	}
	
	void get(int& a,int &b)
	{
		a=this->id;
		b=this->weight;
	}
	friend ostream& operator<<(ostream&, node& c)
    {
        cout <<"I= "<<c.id<<" L= "<<c.location<<" W= "<<c.weight<<" ";
        return cout;
    }
		
};

class graph
{
 private:
	int total;
	list <node> *arr;
	bool *flag;	
	int insertcount;
 public:
graph()
{
	total=0;
	arr = NULL;
	flag= NULL;
		 	
}
graph(int value)	
{
	insertcount=0;
	total = value;
	arr = new list <node> [value];
	flag = new bool [value];
	for(int i=0; i<value ; i++)
	{
		flag[i]=false;	
	}	
}	

int get_total()
{
	return total;
}
void addVertex()
{
	int oldtotal=total;
	total++;
	list <node> *temp;
	temp = new list <node> [total];
	for(int a=0;a<oldtotal;a++)
	{
		temp[a]=arr[a];
	}
	arr=temp;
	bool *tempflag;
	tempflag = new bool[total];
	for(int x=0;x<oldtotal;x++)
	{
		tempflag[x]=flag[x];
	}
	flag=tempflag;
}

void input(int n1,int n2,int wgt,string s1,string s2)
{
	insertcount++;
	node temp1;
	node temp2;
	temp1.id=n1;
	temp2.id=n2;
	temp1.weight=wgt;
	temp2.weight=wgt;
	temp1.location=s1;
	temp2.location=s2;
	arr[n1].push_back(temp2);
	arr[n2].push_back(temp1);
}

void printlist()
{
	for(int a=1 ;a<total;a++)
	{
		cout<<"EGDE:"<<a<<" 	ADJACENT: ";
		for(node iter:arr[a])
		{	
			cout<<iter<<" , ";
		}
		cout<<endl;
	}	
}

void save()
{
	file.close();
	bool **check= new bool *[total];
	for (int i=0;i<total;i++)
	{
		check[i] = new bool[total];
		for (int j= 0;j<total;j++)
		{
			check[i][j] = false;
		}
	}
	ofstream fin;
	fin.open("abc.txt");
	fin << total-1 <<endl;
	for(int a=0;a<ssize;a++)
	{
		fin<< a+1 <<" "<<strarr[a] <<endl;	
	}
	fin<< insertcount+1 <<endl;
	int x1,x2;
	for(int i=0;i<total;i++)
	{
		for (node iterator : arr[i])
		{
			iterator.get(x1,x2);
			if((!check[i][x1])&&(!check[x1][i]))
			{
				fin << i << " " <<x1 <<" "<<x2<<endl;
				check[i][x1]=true;
				check[x1][i]=true;
			}			
		}
	}
	fin.close();
}
	~graph()
	{
		delete arr;
		delete flag;
	}
};

void stringset()
{
	file.open("abc.txt");
	int size;
	file>>size;
	ssize=size;
	strarr =new string[size];
	int x1;
	for(int a=0;a<size;a++)
	{
		file>>x1;
		file>>strarr[a];
	}
}
bool pcheck=false;
void populate(graph &obj)
{
	
	if(pcheck)
	{
		cout<<"IT IS ALREADY POPULATED !!! ONLY ONE POPULATION PER EXECUTION"<<endl;
		return;
	}
	int size2;
	file>>size2;
	int id1;
	int id2;
	int wt;	
	for(int a=0;a<size2-1;a++)
	{
		file>>id1>>id2>>wt;
		obj.input(id1,id2,wt,strarr[id1-1],strarr[id2-1]);
	}
	file.close();
}

void insert_edge(graph &obj)
{
	int v1,v2;
	int max=obj.get_total();
	cout<<"enter the vertex from where relation is started limit is 1 to "<<max-1<<endl;
	cin>>v1;
	while(v1<=0||v1>=max)
	{
		cout<<"wrong input enter again"<<endl;
		cin>>v1;
	}
	cout<<"enter the vertex from where relation is ended limit is 1 to "<<max-1<<endl;
	cin>>v2;
	while(v2<=0||v2>=max||v2==v1)
	{
		cout<<"wrong input enter again"<<endl;
		cin>>v2;
	}
	int weight;
	cout<<"ENTER THE WEIGHT"<<endl;	
	cin>>weight;
	obj.input(v1,v2,weight,strarr[v1-1],strarr[v2-1]);
} 
void vertex(graph &obj)
{
	int oldsize=ssize;
	ssize++;
	string *tempo = new string[ssize];
	for(int a=0;a<oldsize;a++)
	{
		tempo[a]=strarr[a];
	}
	string loc;
	cout<<"enter the name of location "<<endl;
	cin>>loc;
	tempo[ssize-1]=loc;
	strarr=tempo;
	obj.addVertex();
}


void display()
{
		cout<<"			enter what you want to do in the graph !!!!"<<endl;
	cout<<"1 for populating it with the text file "<<endl;
	cout<<"2 for adding a vertex in graph "<<endl;
	cout<<"3 for adding an edge between 2 vertexes "<<endl;
	cout<<"4 for prinitng the graph "<<endl;
	cout<<"5 for saving the graph in a text file "<<endl;
	cout<<"0 to exit "<<endl;
}
int main()
{
	stringset();
	int size3;
	ifstream afile;
	afile.open("abc.txt");
	afile>>size3;	
	afile.close();
	graph obj(size3+1);
	int choice=9;
	display();
	system("cls");
	//populate(obj);
	while(choice!=0)
	{
		display();
		cout<<"enter choice ";
		cin>>choice;
		if(choice==1)
		{
			populate(obj);
			pcheck=true;
			system("pause");
			system("cls");		
		}
		else if(choice==2)
		{
			vertex(obj);
			system("pause");
			system("cls");
		}
		else if(choice==3)
		{
			insert_edge(obj);
			system("pause");
			system("cls");
		}
		else if(choice==4)
		{
			obj.printlist();
			system("pause");
			system("cls");
		}
		else if(choice==5)
		{
			obj.save();
			stringset();
		}

		else if(choice==0)
		{
			cout<<"				TERMINATION"<<endl;
		}
		else
		{
			system("cls");
			cout<<"WRONG INPUT ENTER AGAIN"<<endl;
			cin>>choice;
			system("cls");
		}
	}
	
    //vertex(obj);
	//obj.printlist();
	//insert_edge(obj);
	//obj.printlist();
}