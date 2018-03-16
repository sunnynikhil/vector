#include<stdio.h>
#include<stdlib.h>
typedef struct vector
{
    int *arr;
    int curLen;
    int totalSize;
} vector;

vector* createVector(int totalSize)
{
    vector* vec = (vector *)malloc(sizeof(vector));
    vec->arr = (int *)malloc(sizeof(int)*totalSize);
    vec->curLen = 0;
    vec->totalSize = totalSize;
    return vec;
}

void resize(vector *vec)
{
    vec->arr=(int*)realloc(vec->arr,sizeof(int)*(vec->curLen+1));
    return;
}
void insert(vector *vec,int key)
{

    resize(vec);
    vec->arr[vec->curLen]=key;
    vec->curLen=vec->curLen+1;
    return;
}

void display(vector *vec)
{
    int index;
    for(index=0; index<vec->curLen; index++)
    {
        printf("%d\t",vec->arr[index]);
    }
}


void delete(vector *vec,int key)
{
    int index,found=0,pos;
    for(index=0; index<vec->curLen; index++)
    {
        if(vec->arr[index]==key)
        {

            found=1;
            pos=index;
            break;
        }
    }
    if(found==1)
    {
        for(index=pos; index<vec->curLen-1; index++)
        {
            vec->arr[index]=vec->arr[index+1];
        }
        vec->curLen=vec->curLen-1;
    }
    else
    {
        printf("\n*key is not found*\n");
    }
}
int main()
{
    vector * vec = createVector(10);
   int value,value1,choice;
   while(1)
   {
       printf("\n1 for insertion\n");
       printf("\n2 for deletion\n");
       printf("\n3 for display\n");
       printf("\n4 for exit\n");
       printf("\nenter the choice\n");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
        printf("\n enter the value to insert\n");
        scanf("%d",&value);
        insert(vec,value);
        break;
       case 2:
        printf("\nenter the to delete\n");
        scanf("%d",&value1);
        delete(vec,value1);
        break;
       case 3:
        display(vec);
        break;
       case 4:
        exit(0);
       }
   }

}
