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

int main(){
    struct BigInteger a= initialize("7500350");
    struct BigInteger b= initialize("3534");
    struct BigInteger c= mul(a,b);
    display(c);
    struct BigInteger d= sub(a,b);
    display(d);
    d= add(a,b);
    display(d);
    d= div1(a,b);
    display(d);



}