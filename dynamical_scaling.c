#include<stdio.h>
#include<stdlib.h>
typedef struct vector
{
    void **arr;
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
void insert(vector *vec,void *key,size_t size)
{

    resize(vec);
    vec->arr[vec->curLen]=malloc(size);
    memcpy(vec->arr[vec->curLen],key,size);
    vec->curLen=vec->curLen+1;
    return;
}

void display(vector *vec,void (*vp)(void*))
{
    int index;
    for(index=0; index<vec->curLen; index++)
    {
       (*vp)(vec->arr[index]);
    }
}
void display_n(void *n)
{
    printf("      %d  ",*(int *)n);
}

void delete(vector *vec,void *key,size_t size)
{
    int index,found=0,pos;
    for(index=0; index<vec->curLen; index++)
    {

        if(convert(vec->arr[index],size)==convert(key,size))
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
int convert(void *data,size_t size)
{
    if (size == 4)
    {
        int idx = *(int*)data;
        return idx;
    }
    else
    {
        printf("here\n");
        int value = *(int*)data;
        printf("%d\n",value);
        return value;
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
        printf("\nenter the value to insert\n");
        scanf("%d",&value);
        insert(vec,&value,sizeof(int));
        break;
       case 2:
        printf("\nenter the to delete\n");
        scanf("%d",&value1);
        delete(vec,&value1,sizeof(int));
        break;
       case 3:
        display(vec,display_n);
        break;
       case 4:
        exit(0);
       }
   }
return 0;
}
