#include "stdlib.h"
#include "stdio.h"
#include "BigInteger.h"
struct BigInteger{
    struct BigInteger*l;
    int length;
};
struct node{
    struct node*next;
    int data;
};
struct node *reverse(struct node **head){
    struct node *prev=NULL;
    struct node *next=NULL;
    struct node *cur=*head;
    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    *head=prev;
    return *head;
}

//struct node*new(int data)


struct BigInteger sub(struct BigInteger a,struct BigInteger b){
    struct node *bigA=a.l;
    struct node *bigB=b.l;
    struct node *result=NULL;
    int n1=0,n2=0,n3;
    struct node*itr=bigA;
    struct node*ptr=bigB;
    while (itr){
        n1=n1*10+itr->data;
        itr=itr->next;
    }
    while (ptr){
        n2=n2*10+ptr->data;
        ptr=ptr->next;
    }
    if (n1>n2){
        n3=n1-n2;
        while (n3>0){
            createnode(&result,n3%10);
            n3=n3/10;
        }
    }else{
        n3=n2-n1;
        while (n3>0){
            createnode(&result,n3%10);
            n3=n3/10;
        }
    }
struct node*res= reverse(&result);
    struct BigInteger c;
    c.l=res;
    printf("\nthe substraction is\t");
    return  c;

}
struct node * createnode(struct node **head,int data){
    struct node * temp=(struct node*)malloc( sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(*head==NULL){
        *head=temp;

    }else{
        struct node *cur=*head;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=temp;
    }
    return temp;

}
struct BigInteger initialize(char *s){
    struct BigInteger a;
    struct node *node=NULL;
    int i,len=0;
    for(i=0;s[i]!='\0';i++){
        int digit=s[i]-'0';
        len++;
        createnode(&node,digit);//if assign to node that will only be storing one node

    }
    a.l=node;
    a.length=len;
    return a;
}
struct BigInteger add( struct BigInteger a,struct BigInteger b){

    struct node *bigA= reverse(&a.l);
    struct node *bigB= reverse(&b.l);
    struct node*result=NULL;
    int sum=0,carry=0;
    while(bigA || bigB){
        sum=0;
        if(bigA){
            sum=sum+bigA->data;
        }
        if(bigB){
            sum=sum+bigB->data;
        }
        sum=sum+carry;
        carry=sum/10;
        sum=sum%10;
        createnode(&result,sum);
        if(bigA){
            bigA=bigA->next;
        }
        if(bigB){
            bigB=bigB->next;
        }

    }
    if(carry)
        result= createnode(&result,carry);
    result= reverse(&result);
    struct BigInteger c;
    c.l=result;
    printf("\nthe addition is \t");
    return c;

}

struct BigInteger mul(struct BigInteger a,struct BigInteger b){
    struct  node*bigA=a.l;
    struct node*bigB=b.l;
    struct node* result=NULL;
    struct node * res=NULL;
    struct node*itr=bigA;
    struct node*ptr=bigB;
    long n1=0,n2=0,n3;
    while(itr){
        n1=n1*10+itr->data;
        itr=itr->next;
    }
    while(ptr){
        n2=n2*10+ptr->data;
        ptr=ptr->next;
    }
    n3=n1*n2;
    while (n3>0){
        createnode( &res,n3%10);
        n3=n3/10;
    }
    result= reverse(&res);
    struct BigInteger c;
    c.l=result;
    printf("\nthe multification is \t");
    return c;
}

struct BigInteger div1(struct BigInteger a,struct BigInteger b){
    struct node *bigA=a.l;
    struct node *bigB=b.l;
    struct node *result=NULL;
    int n1=0,n2=0,n3;
    struct node*itr=bigA;
    struct node*ptr=bigB;
    while (itr){
        n1=n1*10+itr->data;
        itr=itr->next;
    }
    while (ptr){
        n2=n2*10+ptr->data;
        ptr=ptr->next;
    }
    if (n1>n2){
        n3=n1/n2;
        while (n3>0){
            createnode(&result,n3%10);
            n3=n3/10;
        }
    } else{
        n3=n2/n1;
        while(n3>0){
            createnode(&result,n3%10);
            n3=n3/10;
        }

    }
   /* n3=n1/n2;
    while (n3>0){
        createnode(&result,n3%10);
        n3=n3/10;
    }*/
    struct node*res= reverse(&result);
    struct BigInteger c;
    c.l=res;
    printf("\nthe division is\t");
    return  c;
}
struct BigInteger display(struct BigInteger a){
   struct node*itr=a.l ;


    while(itr){
        printf("%d",itr->data);
        itr=itr->next;
     //   a.length++;
    }
    printf("\n");
   // printf("\nlength of big integer=%d \n",a.length);
    return a;

}

