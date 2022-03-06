// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
    Node* merge(Node *left,Node *right){
        Node* head=new Node(0);
        Node* temp=head;
        
        while(left!=NULL and right!=NULL){
            if(left->data<right->data){
                temp->next=left;
                left=left->next;
                temp=temp->next;
            }else{
                temp->next=right;
                right=right->next;
                temp=temp->next;
            }
        }
        while(left){
            temp->next=left;
            left=left->next;
            temp=temp->next;
        }
        while(right){
            temp->next=right;
            right=right->next;
            temp=temp->next;
        }
        return head->next;
    }
    Node* getmid(Node *arr[],int left,int right){
        if(left==right)return arr[left];
        int mid=(left+right)/2;
        
        Node *l=getmid(arr,left,mid);
        Node *r=getmid(arr,mid+1,right);
        
        return merge(l,r);
    }
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           if(K==0)return NULL;
           return getmid(arr,0,K-1);
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends