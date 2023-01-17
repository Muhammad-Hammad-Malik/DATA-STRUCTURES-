#include <iostream>
using namespace std;
class Xheap
{
private:
	
int **heap;
int capacity;
int size;

void MINUP(int R, int B)
{
		int P;
		if (B > R)
		{
			P = (B - 1) / 2;
			if (heap[0][P] > heap[0][B])
			{
				swap(heap[0][P], heap[0][B]);
				MINUP(R, P);
			}
		}
}


void MAXUP(int R, int B)
{
		int P;
		if (B > R)
		{
			P = (B - 1) / 2;
			if (heap[1][P] <= heap[1][B])
			{
				swap(heap[1][P], heap[1][B]);
				MAXUP(R, P);
			}
		}
}


void MINDOWN(int R, int B)
{
		int min, right, left;
		left = 2*R+1;
		right = 2*R+ 2;
		if (left <= B)
		{
			if (left == B)
			{
				min = left;
			}
			else 
			{
				if (heap[0][left] >= heap[0][right])
				{
					min = right;
				}
				else
				{
					min = left;
				}
			}
			if (heap[0][R] > heap[0][min]) 
			{
				swap(heap[0][R], heap[0][min]);
				MINDOWN(min, B);
			}
		}
}



void MAXDOWN(int R, int B)
{
		int max, right, left;
		left = 2 * R + 1;
		right = 2 * R + 2;
		if (left <= B)
		{
			if (left == B)
			{
				max = left;
			}
			else
			{
				if (heap[1][left] < heap[1][right])
				{
					max = right;
				}
				else
				{
					max = left;
				}
			}
			if (heap[1][R] <= heap[1][max])
			{
				swap(heap[1][R], heap[1][max]);
				MAXDOWN(max, B);
			}
		}
}



public:
	
Xheap()
{
		heap=NULL;
		capacity=0;
		size=0;
}
Xheap(int x)
{
		heap = new int*[2];
		heap[0]=new int[x];
		heap[1]=new int[x];
		capacity=x;
		size=0;
}

bool IsEmpty()
{
		if(size==0)
		{
			return true;
		}
		else
		{
			return false;
		}
}

int mingetter()
{
		return heap[0][0];
}


int maxgetter()
{
		return heap[1][0];
}


void print()
{
		for(int a=0;a<size/2;a++)
		{
			cout<<"("<<heap[0][a]<<","<<heap[1][a]<<") ";
		}
		if(size%2!=0)
		{
			cout<<"("<<heap[0][size/2]<<", $) ";
		}
		cout<<endl;

}
void insertion(int val)
{
		if (size>=capacity)
		{
			
			cout<<"INVALID HEAP"<<endl;
			return;
			
		}
		if (size%2==0)              //  check by even odd to see insertion
		{
			
			heap[0][(size/2)] = val;
			int p = ((size/2) - 1) / 2;
			if (size > 0)                  // boundary condition
			{
				
				if (heap[1][p] < heap[0][size/2])      // check if swapping needs to be done 
				{
					
					swap(heap[1][p], heap[0][size/2]);
					MAXUP(0, p);                       // max heap conversion
				}
				
			}
			
			int xsize=size/2;
			MINUP(0,xsize);             // min heap conversion
			size++;
			
		}
		else
		
		{
			if (val >= heap[0][size/2])
			{
				
				heap[1][size/2] = val;
				MAXUP(0,size/2);
				
			}
			else
			{
				
				heap[1][size/2] = heap[0][size/2];  // swapping 
				heap[0][size/2] = val;
				MINUP(0, size/2);
				MAXUP(0, size/2);  //  heapify both heaps
				
			}
			size++;
		}
		//print();
		//cout<<endl<<endl;
		
}	

void balancing()
{
		for (int i = 0; i < size / 2; i++)
		{
			if (heap[0][i] > heap[1][i])
			{
				swap(heap[0][i], heap[1][i]);
			}
		}
		MAXDOWN(0, size / 2 - 1);
		if(size%2==0)
		{
			MINDOWN(0, size / 2 - 1);
		}
		else
		{
			MINDOWN(0, size / 2);	
		}
}

void searching(int element, bool& flag , int& IX, int &HX)
{
		if (size % 2 != 0)
		{
			if (heap[0][size / 2] == element)
			{
				flag = true;
				IX = size / 2;
				HX = 0;
			}
		}
		for (int a = 0; a < size / 2 && !flag; a++)
		{
			if ((element == heap[0][a])|| (element == heap[1][a]))
			{
				flag = true;
				if (element == heap[0][a])
					HX = 0;
				if (element == heap[1][a])
					HX = 1;
				IX = a;
			}
		}
}


void update(int x, int y)
{
		int IX = -1;
		int HX = -1;
		bool flag=false;
		searching(x, flag, IX, HX);
		if (IX != -1)
		{
			swap(heap[HX][IX], y);
			if (size % 2 == 0)
			{
				MAXUP(0, size / 2 - 1); // to check as index are 1 less
				MINUP(0, size / 2 - 1);
			}
			else
			{
				MAXUP(0, size / 2 - 1); // 
				MINUP(0, size / 2); // as it has one extra
			}
			balancing();
		}
}


void maximum_delete()
{
		if (size % 2 == 0)
		{
			swap(heap[1][0], heap[1][(size / 2) - 1] );
			size--;
			MAXDOWN(0, size / 2);
			balancing();
		}
		else
		{
			swap(heap[1][0], heap[1][(size / 2) - 1]);
			swap(heap[0][size / 2], heap[1][size / 2 - 1]);
			MAXDOWN(0, size / 2 - 1);
			size--;
			balancing();
		}
}


void minimum_delete()
{
		if (size % 2 == 0)
		{
			swap(heap[0][0], heap[0][(size / 2) - 1]);
			size--;
			swap(heap[1][size / 2], heap[0][size/2]);
			MINDOWN(0, size / 2);
		}
		else
		{
			swap(heap[0][0], heap[0][(size / 2)]);
			size--;
			MINDOWN(0, size / 2 - 1 );
		}
		balancing();
}

};

int main()
{
	Xheap obj(100);
	obj.insertion(9);
	obj.insertion(1);
	obj.insertion(13);
	obj.insertion(2);
	obj.insertion(15);
	obj.insertion(19);
	obj.insertion(6);	
	obj.insertion(0);
	obj.insertion(20);
	obj.print();
	cout<<endl<<endl;
	obj.update(2,12);
	obj.print();
	obj.minimum_delete();
	obj.maximum_delete();
	obj.print();
}
