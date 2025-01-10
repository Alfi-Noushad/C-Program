#include<stdio.h>                   //DOUBLY LINKED LIST
#include<stdlib.h>
struct node
{
    int data;
    struct node*llink;
    struct node*rlink;
    
}*start=NULL;

int main()
{
    int ch,x,item;
    struct node*tmp,*p;
    while(1)
    {
        printf("MENU");
        printf("\n1  insertion at beg");
        printf("\n2  insertion at end");
        printf("\n3  insertion in between");
        printf("\n4  deletion at beg");
        printf("\n5  deletion at end");
        printf("\n6  deletion in between");
        printf("\n7  display");
        printf("\n8  exit");
        
        printf("\nenter the choice");
        scanf("%d",&ch);
        
        switch(ch)
        {
          case 1: printf("enter the element to insert");
                  scanf("%d",&item);
                  tmp=(struct node*)malloc(sizeof(struct node));
                  tmp->data=item;
                  if(start==NULL)
                  {
                      tmp->rlink=NULL;
                      tmp->llink=NULL;
                      
                  }
                  else
                  {
                      tmp->rlink=start;
                      tmp->llink=NULL;
                      tmp->rlink->llink=tmp;
                  }
                  start=tmp;
                  break;
                  
                  
          case 2:  printf("enter the element to insert");
                  scanf("%d",&item);
                  tmp=(struct node*)malloc(sizeof(struct node));
                  tmp->data=item;
                  tmp->rlink=NULL;
                  if(start==NULL)
                  {
                      start=tmp;
                      tmp->llink=NULL;
                  }
                  else
                  {
                      p=start;
                      while(p->rlink!=NULL)
                      {
                          p=p->rlink;
                      }
                      p->rlink=tmp;
                      tmp->llink=p;
                  }
                  break;
                  
          case 3:   printf("enter the element to insert");
                  scanf("%d",&item);
                  tmp=(struct node*)malloc(sizeof(struct node));
                  tmp->data=item;
                  if(start==NULL)
                  {
                      start=tmp;
                      tmp->rlink=start;
                      tmp->llink=NULL;
                  }
                  else
                  {
                      printf("enter the element after to delete");
                      scanf("%d",&x);
                      p=start;
                      while(p->data!=x&&p!=NULL)
                      {
                           p=p->rlink;
                      }
                      if(p->data==x)
                      {
                          tmp->rlink=p->rlink;
                          tmp->llink=p;
                          p->rlink=tmp;
                          tmp->rlink->llink=tmp;
                      }
                      else
                      {
                          printf("search element not found");
                          free(tmp);
                      }
                  }
                  break;
                  
          case 4: if(start==NULL)    //doubt
                  {
                      printf("underflow");
                  }
                  else
                  {
                      if(start->rlink==NULL)
                      {
                          tmp=start;
                          printf("the deleted element is %d",tmp->data);
                          start=tmp->rlink;
                          free(tmp);
                      }
                      else
                      {
                           tmp=start;
                          printf("the deleted element is %d",tmp->data);
                          start=tmp->rlink;
                          tmp->rlink->llink=start;
                          free(tmp);
                      }
                  }
                  break;
                  
                  
          case 5: if(start==NULL)    
                  {
                      printf("underflow");
                  }
                  else
                  {
                      if(start->rlink==NULL)   //when it has only one node
                      {
                          tmp=start;
                          start=tmp->rlink;
                          printf("the deleted element is %d",tmp->data);
                          free(tmp);
                      }
                      else
                      {
                          p=start;
                          while(p->rlink->rlink!=NULL)
                          {
                              p=p->rlink;
                          }
                          tmp=p->rlink;
                          
                          p->rlink=NULL;
                          printf("the deleted element is %d",tmp->data); 
                          free(tmp);
                      }
                  }
                  break;
                  
                  
          case 6: if(start==NULL)    
                  {
                      printf("underflow");
                  }
                  else
                  {
                      printf("enter the element after to delete");
                      scanf("%d",&x);
                      p=start;
                      while(p->data!=x&&p!=NULL)
                      {
                          p=p->rlink;
                      }
                      if(p->data==x)
                      {
                          tmp=p->rlink;
                          p->rlink=tmp->rlink;
                          tmp->rlink->llink=p;
                          printf("the deleted element is %d",tmp->data); 
                          free(tmp);
                      }
                      else
                      {
                          printf("element not found to delete");
                      }
                     
                  }
                  break;
                  
                  
          case 7: if(start==NULL)    
                  {
                      printf("empty set");
                  }
                  else
                  {
                      p=start;
                      while(p!=NULL)
                      {
                          printf("%d",p->data);
                           p=p->rlink;
                      }
                  }
                  break;
                  
                  
          case 8: exit(1);
          
          
          default:printf("invalid choice");
          
        }
        
    }
return 0;
    
}
