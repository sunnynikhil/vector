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
    vec->arr=(int*)realloc(vec->arr,sizeof(int)*(vec->totalSize)*2);
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

void delete(vector *vec,void *key,int (*vp)(void*,void*))
{
    int index,found=0,pos,foo=0;

    for(index=0; index<vec->curLen; index++)
    {
        foo=(*vp)(vec->arr[index],key);
        if(foo==1)
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
int compareInt(void *dataAddr1,void *dataAddr2)
{
    int *d1 =(int *)dataAddr1;
    int *d2 =(int *)dataAddr2;
    if (*d1 == *d2 )
    {
        return 1;
    }
    return 0;
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
            delete(vec,&value1,compareInt);
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
