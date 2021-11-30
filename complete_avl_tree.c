#include<stdio.h>
#include<stdlib.h>
int choice,ele,bf,minim,maxim,search_ele;
struct node
{
	struct node*left;
	int data;
	struct node*right;
	int height;
}*root;
struct node* create(int);
int height(struct node*);
int balance_factor(struct node*);
int max(int,int);
struct node* right_rotate(struct node*);
struct node* left_rotate(struct node*);
struct node* insert(struct node*,int);
int search(struct node*,int);
int find_min(struct node*root);
int find_max(struct node*root);
void print(struct node*);
int isempty(struct node*);
int main()
{
	do
	{
       printf("press1 to insert  |\npress2 to delete  |\npress3 to search  |\npress4 to find_min|\npress5 to find_max|\npress6 to display |\npress7 to exit    |\n");
       printf("-------------------\n");
       scanf("%d",&choice);
       switch(choice)
       {
       	case 1:
       		printf("enter the element:\n");
       		scanf("%d",&ele);
       		root=insert(root,ele);
       	break;
       	case 2:
       		
       	break;
        case 3:
       		if(isempty(root))
    		{
			printf("avl tree is empty :(\n");
    	    }
    		else
    		{
			printf("enter the element to search:\n");
    	    scanf("%d",&search_ele);
    		ele=search(root,search_ele);
    		if(ele==-1)
    		{
    		printf("!!%d was not present in binary search tree!!\n",search_ele);
    	    }
			else
			{
    		  printf("%d was  present in avl tree\n",ele);
    	    }
			}		
       	break;
       	case 4:
       		if(!isempty(root))
    		{
    		minim=find_min(root);	
    		  printf("smallest element present in avl tree is %d\n",minim);
    	    }
    		else
			printf("avl tree is empty :(\n");
       	break;
       	case 5:
       		if(!isempty(root))
    		{
    		maxim=find_max(root);	
    		  printf("largest element present in avl tree is %d\n",maxim);
    	    }
    		else
			printf("avl tree is empty :(\n");
       	break;
       	case 6:
       		if(isempty(root))
       		{
       			printf("avl tree is empty :(\n");
			}
			else
			{
       		printf("avl tree:\n");
       		print(root);
            }
       	break;
       	case 7:
       		printf("!!exited!!\n");
       	break;
       	default:
       	printf("!!invalid entry!!\n");	
       	break;
	   }
	   printf("-------------------\n");
   }while(choice!=7);
	return 0;
}

 struct node* create(int ele)
 {
 	struct node*new;
 	new=(struct node*)malloc(sizeof(struct node));
 	new->data=ele;
 	new->right=NULL;
 	new->left=NULL;
 	new->height=1;
 	return new;
 }
 int height(struct node*r)
 { 
   if(r==NULL)
   {
   	return 0;
   }
   return r->height;	
 }
 int max(int a,int b)
 {
 	if(a>b)
 	return a;
 	else 
 	return b;
 }
 int balance_factor(struct node*r)
 {
 	if(r==NULL)
    return 0;
    else
 	return height(r->left)-height(r->right);
 }
 struct node* right_rotate(struct node*r)
 {
 	struct node *a=r->left;
 	struct node *y=a->right;
 	
 	a->right=r;
 	r->left=y;
 	
 	r->height=1+max(height(r->left),height(r->right));
 	a->height=1+max(height(a->left),height(a->right));
 
 	return a;
 }
struct node* left_rotate(struct node*r)
{
	struct node *a=r->right;
 	struct node *y=a->left;
 	
     a->left=r;
     r->right=y;
     
    r->height=1+max(height(r->left),height(r->right));
 	a->height=1+max(height(a->left),height(a->right));
	
	return a;
}

 struct node* insert(struct node*r,int ele)
 {
 	if(r==NULL)
 	{
 		return create(ele);
	}
	else if(ele<r->data)
	 {
	 	r->left=insert(r->left,ele);
	 }
	 else if(ele>r->data)
	 {
	 	r->right=insert(r->right,ele);
	 }
	 else
	 {
	 	return r;
	 }
	 //recursion half
	 r->height=1+max(height(r->left),height(r->right));//height function return the height of current right and left child node,and we should check the max and
     bf=balance_factor(r);     //add 1 so that we get height height of current node(just we are updating common factor of current node). 
     //left-left
	 if(bf>1&&ele<r->left->data)
	 {
	 	return right_rotate(r);
	 }
	 //left-right
     else if(bf>1&&ele>r->left->data)
     {
     	r->left=left_rotate(r->left);
     	return right_rotate(r);
	 }
	 //right-right
	 else if(bf<-1&&ele>r->right->data)
	 {
	 	return left_rotate(r);
	 }
	 //right-left
	 else if(bf<-1&&ele<r->right->data)
	 {
	 	r->right=right_rotate(r->right);
	 	return left_rotate(r);
	 }
    return r;
 }
 
 int search(struct node*r,int ele)
 {  if(r!=NULL)
   {

	if(ele<r->data)
	{ 
		ele=search(r->left,ele);
		return ele;
	}
	else if(ele>r->data)
	{ 
		ele=search(r->right,ele);
			return ele;
	}
	else if(ele==r->data)
	{
		return r->data;
	}
   }
		return -1;	 
    
}

 int find_min(struct node*root)
{
	if(root->left==NULL)
	{
		return root->data;
	}
	else
	{
		find_min(root->left);
	}
}
int find_max(struct node*root)
{
	if(root->right==NULL)
	{
		return root->data;
	}
	else
	{
		find_max(root->right);
	}
}

void print(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->data);
		print(root->left);
		print(root->right);
	}
	
}
int isempty(struct node *root)
{
	if(root==NULL)
	return 1;
	return 0;
 } 
