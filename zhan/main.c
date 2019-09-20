#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct SNode
{
    int data;
    int n;
    struct SNode *next;
};
typedef enum { false, true } bool;
typedef struct SNode * Stack;
struct SNode *create()
{
    Stack s;
    s=(Stack)malloc(sizeof(struct SNode));
    s->next=NULL;
    s->n =0;
    return s;
}
bool push(Stack s,int x)
{
    Stack ptr;
    ptr=(Stack)malloc(sizeof(struct SNode));
    ptr->data=x;
    ptr->next=s->next;
    s->next=ptr;
    s->n++;
    return true;
}
int pop(Stack s)
{
    if(s->next==NULL)
    {
        return -1;
    }
    else
    {
        Stack ptr;
        int re=0;
        ptr=(Stack)malloc(sizeof(struct SNode));
        ptr=s->next;
        re=ptr->data;
        s->next=ptr->next;
        s->n--;
        free(ptr);
        return re;
    }
}
int peekMedian(Stack s)
{
    if(s->next==NULL)
    {
        return -1;
    }
    else
    {
        find(s);
        return 0;
    }
}
int find(Stack s)
{
    s=s->next;
    while(s!=NULL)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    return 0;
}
int main()
{
    Stack s;
    s=(Stack)malloc(sizeof(struct SNode));
    s=create();
    int n;
    scanf("%d",&n);
    getchar();
    int i;
    for(i=0;i<n;i++)
    {
        char a[20];
        scanf("%s",&a);
        if(strcmp(a,"Pop")==0)
        {
            int a=pop(s);
            if(a==-1)
            {
                printf("Invalid\n");
            }
            else
            {
                printf("%d\n",a);
            }
        }
        if(strcmp(a,"Push")==0)
        {
            int num;
            scanf("%d",&num);
            push(s,num);
        }
        if(strcmp(a,"PeekMedian")==0)
        {
            int b=peekMedian(s);
            if(b==-1)
            {
                printf("Invalid\n");
            }
            else
            {
                printf("%d\n",b);
            }
        }
    }
    return 0;
}
