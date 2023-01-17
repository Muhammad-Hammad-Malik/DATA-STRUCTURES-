#include <iostream>
using namespace std;
struct node
{
	node *left;
	node *right;
	int data;	
	node(int value)
	{
		left=NULL;
		right=NULL;
		data=value;
	}
};
template <class T>
class BST
{
	private:
		node *root;
	public:
		BST()
		{
			root=NULL;
		}
		
		
		
	void insert(int datax)
	{
		if (root == NULL)
		{
			node* newnode = new node(datax);
			root = newnode;
			cout<<endl<<"value is inserted"<<endl;
		}
		else
		{
			bool flag=insertion(root,datax);
			if(flag==true)
			cout<<"val is inserted"<<endl;
			else
			cout<<"already existing"<<endl;
		}
	}	
	
	
	
	
	bool insertion(node* &root,int datax)
	{
		if(root==NULL)
		{
				node* newnode = new node(datax);
				root = newnode;
		}
		if (datax > root->data)
		{
		
		insertion(root->right, datax);
			
		}
		else if (datax < root->data)
		{
				insertion(root->left, datax);
		}
		else
		{
			return false;
		}
		return true;
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
		
		
		void preorder(node *root)
		{	
		if(root==NULL)
		{
			return;
		}
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
		}
		
		
		
		void printpreorder()
		{
		preorder(root);	
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
		

		void lengthget(node *head, int& count)
		{
		if (head != NULL) {
			lengthget(head->left,count);
			count++;
			lengthget(head->right,count);
		}
		}
		int total()
		{
		int count = 0;
		lengthget(root,count);
		return count;
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
		
		node* searching(int key,node *root)
		{
		if(!root==NULL)
			{
				searching(key,root->left);
				searching(key,root->right);
				if(root->data==key)
				{
					return root;
				}
			}
		}
		
		void search(int key)
		{
			node *found;
			found = searching( key, root);
			cout<<"the node found is "<<found->data;
						
		}
		
		
		~BST()
		{
			cout<<endl<<endl<<"destructor called"<<endl;
			destructorx(root);
		}			
};
int main()
{
	BST <int> obj;
	obj.insert(10);
	obj.insert(4);
	obj.insert(73);
	obj.insert(14);
	obj.insert(15);
	obj.insert(19);
	obj.insert(7);
	obj.printinorder();
	cout<<endl;
	obj.printpreorder();
	cout<<endl;
	obj.printpostorder();
	cout<<endl<<"the number of total nodes is "<<obj.total();
	
	obj.search(15);
	
}
