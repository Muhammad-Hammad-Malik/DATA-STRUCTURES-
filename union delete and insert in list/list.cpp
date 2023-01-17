	#include <iostream>
	using namespace std;
	template <class T>
	struct node
	{
	node *next;
	T data;	
	};
	template <class T>
	class SortedSet
	{
		private:
			node<T>* head;
			node<T>* tail;
		public:
			
		SortedSet()
		{
			head=NULL;
		}	
		void InsertData(T const value)
		{
			node<T>*utility=new node<T>;
			utility->data=value;
			utility->next=NULL;
			node <T>*current;
			current=head;
			if(head==NULL)
			{
				head=utility;
				head->next=NULL;
			}
			else 
			{
				if(utility->data>current->data)
				{
					while(current->next!=NULL&& (current->next->data<=utility->data))
					{
						current=current->next;				
					}
					if (current->data != utility->data) // to prevent the repition of same data
					{
						utility->next = current->next;
						current->next = utility;
					}
				}
				else
				{
					if (current->data != utility->data)
					{
						utility->next = head;
						head = utility;
					}
				}
					
				}
			}
		void print()
		{
			node<T> *current;
			current=head;
			while(current!=NULL)
			{
				cout<<current->data<<" ";
				current=current->next;
			}
			cout<<endl;
		}
		int sizegetter()
		{
			int count;
			node<T>* current;
			current=head;
			while(current!=NULL)
			{
				count++;
				current=current->next;
			}
			return count;
		}
		void DeleteIt(int size)
		{
			node <T>*previous;
			node <T>*current;
			current=head;
			if(size==1)
			{
				head=head->next;
			}
			else{
			for(int a=1;a<size;a++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
			}
			delete current;
			
		}
		void Union(SortedSet<T> *obj)
	    {
	        if(obj->head!=NULL)
	        {
	            node<T>* current1=head;
	            node<T>* previous=NULL;
	            node<T>* current2=obj->head;
	            if(current1==NULL||current2->data<current1->data)//root condition that checks if the element has to be inserted at first
	            {
	                node<T>* temp=new node<T>; // create a new temporary node
	                temp->data=current2->data; // copy the data 
	                temp->next=current1;    // join the temp node to start of the Orignal array
	                head=temp;   
	                current2=current2->next; // move the current index in  2nd array
	                previous=head;
	            }
	            while(current2!=NULL)
	            {
	                if(current1==NULL||current2->data<current1->data)//inserts in the middle
	                {
	                    node<T>* temp=new node<T>;
	                    temp->data=current2->data;
	                    temp->next=current1;
	                    previous->next=temp;
	                    current2=current2->next; 
	                    previous=temp;
	                }
	                else if(current2->data==current1->data)//if similar ignore both values and move on
	                {
	                    previous=current1;
	                    current1=current1->next;
	                    current2=current2->next;            
	                }
	                else//right place for the value in second list is not found in first so insert at end
	                {
	                    previous=current1;
	                    current1=current1->next;
	                }
	            }
	        }    
	    }
	
		
	};
	int main()
	{
		int size1;
		SortedSet<int> obj;
		obj.InsertData(13);
		obj.InsertData(25);
		obj.InsertData(34);
		obj.InsertData(25);
		obj.InsertData(34);
		obj.InsertData(15);
		cout<<" THE PRINT FUNCIION IS CALLED HERE "<<endl;
		obj.print();
		cout<<"THE DELETE FUNCTION IS CALLED HERE" <<endl;
		size1=obj.sizegetter();
		int reqsize=0;
		cout<<"enter the index you want to delete the size is "<<size1<<" ";
		cin>>reqsize;
		while((reqsize<=0)||(reqsize>size1))
		{
				cout<<"enter the index you want to delete the size is "<<size1<<" ";
				cin>>reqsize;
		}
		obj.DeleteIt(reqsize);
		obj.print();
		cout<<" NOW THE UNION FUNCTION IS CALLED"<<endl;
		SortedSet<int> *obj1= new SortedSet<int>;
		obj1->InsertData(10);
		obj1->InsertData(70);
		obj1->InsertData(80);
		obj1->InsertData(34);
		cout<<"the second array is "<<endl;
		obj1->print();
		cout<<"THE UNION OF TWO LINKS LISTS IS "<<endl;
		obj.Union(obj1);
		obj.print();
	
		return 0;
	
	}
