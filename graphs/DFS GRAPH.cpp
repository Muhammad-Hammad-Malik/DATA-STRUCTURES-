#include <iostream>
#include <list>
#include <queue>
using namespace std;
queue <int> obj1;
queue <int> obj2;

class graph
{
private:
int total;
list <int> *arr;
bool *flag;
public:
graph(int value)
{
	total = value;
	arr = new list <int> [value];
	flag = new bool [value];
	for(int i=0; i<value ; i++)
	{
		flag[i]=false;	
	}	
}	

void input(int x , int y)
{
	arr[x].push_back(y);
}

void resetflag()
{
	for(int a=0;a<total;a++)
	{
		flag[a]=false;
	}
}

void printlist()
{
	for(int a=0 ;a<total;a++)
	{
		cout<<"THE EGDE IS "<<a<<" AND THE ADJACENT VERTEXES ARE ";
		for(int iter:arr[a])
		{	
			cout<<iter<<" , ";
		}
		cout<<endl;
	}	
}

void resetqueue()
{
	while(!obj1.empty())
	{
		obj1.pop();
	}
	while(!obj2.empty())
	{
		obj2.pop();
	}
}	

void explore(int v)
{
    flag[v] = true;
    cout << v << " "<<endl;
    obj1.push(v);
    list <int>::iterator i;
    for (i = arr[v].begin(); i != arr[v].end();i++)
        {
            if (!flag[*i])
            {
            while (!obj1.empty())
                {
                    cout << obj1.front()<<" ";
                    obj2.push(obj1.front());
                    obj1.pop();
                }
                while (!obj2.empty())
                {
                    obj1.push(obj2.front());
                    obj2.pop();
                }
            	explore(*i);
        	}
        	
        }
}
	
};


int main()
{
	int size;
	size=4;
	graph obj(size);
	obj.input(0,1);
	obj.input(0,2);
	obj.input(1,2);
	obj.input(2,0);
	obj.input(2,3);
	obj.input(3,3);
	cout<<"INSERTION IS DONE ACCORDING TO THE VALUES IN THE MANUAL"<<endl;
	cout<<"A PRINT FUNCTION IS BEING CALLED TO SHOW HOW IT IS DONE"<<endl;
	obj.printlist();
	cout<<endl<<endl<<endl<<" 			NOW WE WILL USE BFS TO EXPLORE IT "<<endl;
	
	cout<<"THE FIRST TRAVERSAL IS DONE FOR VALUE 2 as instructed THE RESULT IS "<<endl;
	obj.explore(2);
	obj.resetflag(); // reset  visited flags for second time use
	obj.resetqueue();// reset queue for second time use
	cout<<" SECOND TRAVERSAL IS FOR VALUE 1 as instructed THE RESULT IS "<<endl;
	obj.explore(1);
	

}