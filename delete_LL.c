
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}node;

void display(node *);


node * insert_end(node *);

node * delete_beg(node *);
node * delete_end(node *);
node * delete_at(node *);
node * delete_before(node *);
node * delete_after(node *);

int main()
{
    int i;
	struct node * start= NULL;
	int ch;
	printf("Enter values for 10 nodes: \n");
	
	for(i=0;i<10;i++)
	{
	   start=insert_end(start);
	}
	while(1)
	{
	  printf("\nMenu:\n1.Delete_Beg\n2.Delete_End\n3.Delete_at\n4.Delete_Before\n5.Delete_after\n6.Display\n7.Exit\n");
	  printf("Enter your choice: ");
	  scanf("%d",&ch);
	  switch(ch)
	  {
	      case 1:start=delete_beg(start);break;
		  case 2:start=delete_end(start);break;
		  case 3:start=delete_at(start);break;
		  case 4:start=delete_before(start);break;
		  case 5:start=delete_after(start);break;
		  case 6:display(start);break;
		  case 7:exit(0);
		  case 8:start=insert_end(start);break;
	  }
	}
}

void display(node* start)
{
  node * ptr;
  ptr=start;
  if(ptr==NULL)
  {
     printf("Empty List!!");
  }
     ptr=start;
     printf("\nElements in the list are: ");
	 while(ptr!=NULL)
	 {
	    printf("%d\t",ptr->data);
	    ptr=ptr->next;
	 }	   
}

node * delete_beg(node * start)
{
    node *ptr;
	if(start==NULL)
	     printf("List Empty!! Can't Delete");
    else
	{
 	 ptr=start;
 	 start=start->next;
	
 	 free(ptr);
	}
	return start;
}


node * delete_end(node * start)
{
  node *ptr;
  
  if(start==NULL)
  {
     printf("List Empty!!");
  }
  else
  {
     ptr=start;
	 while(ptr->next->next!=NULL)
	 {
	    
		ptr= ptr->next;
	 }
	 free(ptr->next);
	 ptr->next=NULL;
  }
  return start;
}

node * delete_at(node * start)
{
   node *ptr1,*ptr2;
   int pos,count=1;
   printf("Enter the position from which to delete: ");
   scanf("%d",&pos);
   
   if(start==NULL)
       printf("List empty!!Can't delete anything.");
	   
   if(pos==1)
   {
     ptr1=start;
	 start=start->next;
	 free(ptr1);
   }
   else
   {
     ptr1=start;
	 ptr2=start;
	 while(ptr2!=NULL && count<pos)
	 {
	   count=count++;
	   ptr1=ptr2;
	   ptr2=ptr2->next;
	 }
	 if(count==pos)
	 {
	  ptr1->next=ptr2->next;
	  free(ptr2);
	 }
	 else
	 {
	    printf("Position doesn't exist!!");
	 }
   }
   return start;
}

node * delete_before(node * start)
{
   node *ptr1,*ptr2;
   int val;
   printf("Enter the position before which to delete: ");
   scanf("%d",&val);
   
   if(start==NULL)
   {
       printf("List empty!!Can't delete anything.");
   }
   else
   { 
      ptr1=ptr2=start;
	  if(ptr2->data==val)
	  {
	    printf("This is the first node!!Nothing to delete before it.");
		return start;
	  }   
	  while(ptr2!=NULL && ptr2->next->data!=val)
	 {
	   ptr1=ptr2;
	   ptr2=ptr2->next;
	 }
	 if(ptr2==start)
	 {
	   start=ptr2->next;
	   free(ptr2);
	 }
	 if(ptr2->next==NULL)
	 {
	  printf("Value not found!!");
	 }
	 else
	 {
	    ptr1->next=ptr2->next;
		free(ptr2);
	 }
   }
   return start;

}


node * delete_after(node * start)

{
   node *ptr1,*ptr2;
   int v;
   printf("Enter the position after which to delete: ");
   scanf("%d",&v);
   
   ptr1=start;
   ptr2=ptr1;
   while(ptr2->data!=v)
   {
		      ptr2=ptr1;
	  ptr1=ptr1->next;
   }
   ptr2->next=ptr1->next;
   free(ptr1);
   return start;  
}

node * insert_end(node * start)
{
  node *ptr;
  node *newnode=(node *)malloc(sizeof(node));
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(start==NULL)
  {
    start=newnode;
  }
  else
  {
    ptr=start;
	while(ptr->next!=NULL)
	{
	  ptr=ptr->next;
	}
	ptr->next=newnode;
  }
  return start;    
} 

