#include <iostream>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
	int height;	
};

class AVL
{
private:
	node *root;
public:
	AVL()
	{
		root=NULL;
	}
	
	int factor(node *temp)
	{
		int fx;
		if(temp->left && temp->right)
		{
			fx=temp->left->height - temp->right->height;
			return fx;
		}
		else if(temp->left && temp->right==NULL)
		{
			fx=temp->left->height;
			return fx;
		}
		else if(temp->left==NULL && temp->right)
		{
			fx=-1*(temp->right->height);
			return fx;
		}
			return fx;
	}
	
	
	int getheight(node *temp)
	{
		if(temp==NULL)
		{
			return 0;
		}
		if((temp->left!=NULL)&&(temp->right!=NULL))
		{
			if(temp->left->height < temp->right->height)
				return temp->right->height+1;
			else if(temp->left->height > temp->right->height)
				return temp->left->height+1;	
		}
		else if((temp->left!=NULL) && (temp->right == NULL))
			return temp->left->height+1;
		else if((temp->left == NULL) &&( temp->right!=NULL))
			return temp->right->height+1;
		else
		return 0;	
	}
	node *L(node *temp)
	{
		node *first;            
		node *second;             
		first=temp;             
		second=first->left;          
		first->left=second->right;   
		second->right=first;          
		return second;            
	}
	node *R(node *temp)
	{
		node *first;             
		node *second;           
		first=temp;             
		second=first->right;        
		first->right=second->left;  
        second->left=first;
		return second;
	}
	node *RL(node *temp)
	{
		node *first;             
		node *second;             
		node *third;             
		first=temp;              
		second=first->right;          
		third=first->right->left;    
		first->right=third->left;    
		second->left=third->right;    
		third->left=first;
		third->right=second;
		return third;
	}
	node *LR(node *temp)
	{
		node *first;            
		node *second;            
		node *third;            
		first=temp;             
		second=first->left;          
		third=first->left->right;   
		first->left=third->right;   
		second->right=third->left;   
		third->right=first;
		third->left=second;
		return third;
	}
	
	node *insert(node *temp,int val)
	{
		if(temp==NULL)
		{
			node *NewNode= new node;
			NewNode->data=val;
			temp=NewNode;
			temp->left = temp->right =NULL;
			temp->height=1;
			return temp;
		}
		else
		{
			if(val<temp->data)
				temp->left=insert(temp->left,val);
			else if(val>temp->data)
				temp->right=insert(temp->right,val);
		}
		temp->height=getheight(temp);
		if(factor(temp)==2 && factor(temp->left)==1)
			temp=L(temp);
		else if(factor(temp)==2 && factor(temp->right)==1)
			temp=R(temp);
		else if(factor(temp)==-2 && factor(temp->right)==1)
			temp= RL(temp);
		else if(factor(temp)==2 && factor(temp->right)==-1)
			temp=LR(temp);
		else
		return temp;
	}
	
	void insertion(int data)
	{
		root=insert(root,data);
	}
	
	void preorderprint(node *temp)
	{
		if(temp!=NULL)
		{
			cout<<temp->data<<",";
			preorderprint(temp->left);
			preorderprint(temp->right);
		}
	}
	void print()
	{
		preorderprint(root);
	}
	
	bool search(node *temp,int key)
	{
		if(!temp==NULL)
		{
			search(temp->left,key);
			search(temp->right,key);
			if(key==temp->data)
			{
				return true;
			}
		}
		else
		{
			return false;
		}	
	}
	void searching(int key)
	{
		if(search(root,key))
		{
			cout<<endl<<"FOUND"<<endl;
		}
		else
		{
			cout<<endl<<"NOT FOUND"<<endl;
		}
	}
	
	int findmin(node *temp)
	{
		while (temp->left != NULL) 
		{
        temp = temp->left;
    	}
    	return (temp->data);
	}
	
	int secondmin(node *temp,int &x)
	{
		secondmin(temp->left,x);
		x++;
		if(x==2)
		return temp->data;
		secondmin(temp->right,x);
		
	} 
	void min()
	{
		int a=0;
		cout<<endl<<endl<<"THE Minimum value is "<<findmin(root);
	//	cout<<endl<<endl<<"THE 2nd Minimum value is "<<secondmin(root,a);
	}
	
	int max(int x, int y)
	{ 
  		 if(x>y)
  		 return x;
  		 else
  		 return y;
	}
	int height(node* temp)
	{ 
	   if(temp == NULL)
	      return 0;
	   return 1 + max(height(temp->left), height(temp->right));
	}
	bool isAVL(node *root) {
	   int h1;
	   int h2;
	   if(root == NULL)
	   {
	      return 1;
	   }
	   h1 = height(root->left); 
	   h2 = height(root->right); 
	   if(abs(h1-h2) <= 1 && isAVL(root->left) && isAVL(root->right)) 
		{
		   return 1;
		}
	   return 0;
	}
	void avlcheck()
	{
		if(isAVL(root))
		{
			cout<<endl<<"IT IS AVL" <<endl;
		}
		else
		{
			cout<<endl<<"IT IS NOT AVL"<<endl;
		}
	}
	
		void inorder(node *root)
		{	
		if(root==NULL)
		{
			return;
		}
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
		}
		
		
		void printinorder()
		{
		inorder(root);	
		}
		
		void postorder(node *root)
		{	
		if(root==NULL)
		{
			return;
		}	
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
		}
		
		
		
		void printpostorder()
		{
		postorder(root);	
		}
		
		~AVL()
		{
			cout<<endl<<endl<<"destructor called"<<endl;
			destructorx(root);
		}	
		
		void destructorx(node *root)
		{
			if (!root==NULL)
			{
				destructorx(root->left);
				destructorx(root->right);
				delete root;
			}
		}
};

int main()
{
	AVL obj;
	obj.insertion(13);
	obj.insertion(10);
	obj.insertion(24);
	obj.insertion(7);
	obj.insertion(20);
	obj.insertion(30);
	obj.insertion(15);
	obj.insertion(25);
	obj.insertion(36);
	cout<<"pre order print "<<endl;
	obj.print();
	cout<<endl<<endl<<endl<<"Searchimg for something we inserted";
	obj.searching(15);
	cout<<endl<<endl<<"Searching for minimum value";
	obj.min();
	cout<<endl<<endl;
	cout<<"checking if the tree is AVL or not";
	obj.avlcheck();
	cout<<endl<<endl;
	cout<<"printing in pre order"<<endl;
	obj.printinorder();
	cout<<endl<<endl<<endl;
	cout<<"In post order notation"<<endl;
	obj.printpostorder();
	
}