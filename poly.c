#include<stdio.h>
#include<stdlib.h>

struct node{
    int ord;
    float cff;
    struct node *next;
};

typedef struct node NODE;

void display(NODE *start){
	printf("\nPOLYNOMIAL : \n");
	while(start->next!=NULL)
	{
		printf("%dX^%d + ",(int)start->cff,start->ord);
		start = start->next;
	}
	printf("%dX^%d ",(int)start->cff,start->ord);
}

void sort(NODE *start){
	NODE *temp2 = NULL,*temp = NULL;
	int t,sm;
	float f;
	while(start !=  NULL)
	{
		temp2 = start->next;
		sm = start->ord;
		temp = start;
        while(temp2!=NULL)
        {
        	if(temp2->ord > sm)
        	{
        		sm = temp2->ord;
        		temp = temp2;
        	}
        	temp2 = temp2->next;
        }
		t = start->ord;
		f = start->cff;
		start->ord = temp->ord;
		start->cff = temp->cff;
		temp->ord = t;
		temp->cff = f;
		start = start->next;
	}
	printf("\n SORTED!");

}

NODE *create(NODE *start){
	int n=1;
	NODE *newnode = NULL,*prev = NULL;
	while(n!=0){
		newnode = (NODE*)malloc(sizeof(NODE));
		printf("\nEnter Order...");
		scanf("%d", &(newnode->ord));
        	printf("\nEnter Coeff...");
		scanf("%f", &(newnode->cff));
		
		newnode->next = NULL;

		if(start==NULL)
			start = newnode;
		else
			prev->next = newnode;
		prev = newnode;

		printf("\nDo you want to continue...");
		scanf("%d",&n);
	}
	display(start);
	return start;
}


NODE *ADD(NODE *start1, NODE *start2)
{
	NODE *temp = NULL,*temp1 = NULL;
	if(start1->ord < start2->ord)
	{
		temp = start1;
		start1 = start2;
		start2 = temp;
	}
	temp1 = start1;
		
		while(start2!=NULL)
		{
			if(start1->ord == start2->ord)
			{
				start1->cff = start1->cff + start2->cff;
				start2 = start2->next;
				start1 = start1->next;
			}
			else if(start1->ord > start2->ord)
			{
				
				temp = start1->next;
				if(temp==NULL)
				{	start1->next = start2;
					start1 = start2;
				}
				else if( temp->ord < start2->ord )
				{
					start1->next = start2;
					start1 = start2;
					start1->next = temp;
				}
			}
			else
				start1 = start1->next;
			if(start1 == NULL)
				start1->next = start2;
			
		}
	return temp1;

}



void main()
{
	NODE *s1 = NULL,*s2 = NULL;
	
	s1 = create(s1);
	s2 = create(s2);
	sort(s1);
	sort(s1);
	sort(s2);
	s1 = ADD(s1,s2);
	display(s1);
	
	
}


















