#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
template <typename T>
void print(queue <T> &obj)
{
	for(int a=0;a<obj.size();a++)
	{
		cout<<obj.front()<<"  ";
		obj.push(obj.front());
		obj.pop();
	}
	cout<<endl;
}
int digitcount(int num)
{
	int total=0;
	while(num>0)
   {
      total++;
      num = num/10;
   }
   return total;
}
int highestdigit(queue <int>&obj)
{
	int highest=digitcount(obj.front());
	int newsize;
	for(int a=0;a<obj.size();a++)
	{
		newsize=digitcount(obj.front());
		if(newsize>highest)
		{
			highest=newsize;
		}
		obj.push(obj.front());
		obj.pop();
	}
	return highest;
}
void intsort()
{
	queue <int> primary;
	queue <int> temp;
	queue <int> obj[10];
	primary.push(103);
	primary.push(365);
	primary.push(140);
	primary.push(1000);
	primary.push(371);
	primary.push(7);
	print(primary);
	int loopcontrol =highestdigit(primary);
	int equalizer=1;
	int sol;
	for(int a=0;a<loopcontrol;a++)
	{
		int zsize=primary.size();
		for(int b=0;b<zsize;b++)
		{
			
			sol=(primary.front()/equalizer)%10; // sol will calculate the the array index in which to insert
			obj[sol].push(primary.front());
			primary.pop();
		}
		for(int x=0;x<10;x++)
		{
			int xsize=obj[x].size();
			for(int y=0;y<xsize;y++)
			{
			temp.push(obj[x].front());
			obj[x].pop();
			}
		}
		int rsize=temp.size();
		
		for(int r=0;r<rsize;r++)
		{
			primary.push(temp.front());
			temp.pop();
		}
	
		print(primary);
		equalizer=equalizer*10;
		system("pause");
	}
}
void stringsort()
{
	queue <string> primary;
	queue <string> temp;
	queue <string> obj[256];
	string input;
	int maxsize;
	int sol;
	string tempo;
	cout<<"enter the exact size of string keep in mind you cant change it";
	cin>>maxsize;
	for(int a=0;a<5;a++)
	{
		cout<<"enter the string"<<endl;
		cin>>input;
		while(input.size()!=maxsize)
		{
			cout<<" length violated enter string again";
			cin>>input;
			
		}
		primary.push(input);
	}
	print(primary);
	for(int a=maxsize-1;a>=0;a--)
	{
		int zsize=primary.size();
		for(int b=0;b<zsize;b++)
		{
			
			tempo=primary.front();
			sol=tempo[a];
			obj[sol].push(primary.front());
			primary.pop();
		}
		for(int x=0;x<256;x++)
		{
			int xsize=obj[x].size();
			for(int y=0;y<xsize;y++)
			{
			temp.push(obj[x].front());
			obj[x].pop();
			}
		}
		int rsize=temp.size();
		
		for(int r=0;r<rsize;r++)
		{
			primary.push(temp.front());
			temp.pop();
		}
	
		print(primary);
		system("pause");
	}
}

int main()
{
	intsort();
	system("pause");
	system("cls");
	stringsort();
}

