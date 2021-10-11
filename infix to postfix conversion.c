
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
/*struct Stack {
    int size;
    int top;
    char *s;
}*/
#define max 100
char a[max];
int top=-1;
void push(char ch[],char c){
    if(top == max-1)
    printf("overflow");
    else
    {
        top++;
        ch[top]= c;
    }
}
char pop(char ch[]){
    char val=' ';
    if(top==-1)
    printf("Underfow");
    else
    {
        val = ch[top];
        top--;
    }
    return val;
}
int what(char ch){
    switch(ch)
    {
        case '+':
        case '-':
        case '/':
        case '*':
        case '%':
        case '^':
            return 0;
    }
    return 1;
}
int priority(char ch){
    switch(ch)
    {
        case '+': 
        case '-': 
            return 1; 
      
        case '*': 
        case '/': 
            return 2; 
      
        case '^': 
            return 3; 
    } 
    return -1; 
   
}
void convert(char inf[],char pof[]){
    int i=0,j=0;
    char temp;
    strcpy(pof," ");
    while(inf[i] != '\0')
    {
        if (inf[i]=='(')
        {
            push(a,inf[i]);
            i++;
        }
        else if(inf[i]==')')
        {
            while(top !=-1 && a[top] !='(')
            {
                pof[j]=pop(a);
                j++;
            }
            temp= pop(a);
            i++;
        }
        else if(what(inf[i])==1)
        {
            pof[j]=inf[i];
            j++;
            i++;
        }
        else if(what(inf[i])==0)
        {
            while(top!=-1 && a[top]!='(' && priority(inf[top])> priority(inf[i]))
            {
                pof[j]=pop(a);
                j++;
            }
            push(a,inf[i]);
            i++;
        }
        else
        {
            printf("INCORRCT EXPRESSION \n");
        }
    }
        while(top!=-1 && a[top]!= '(')
        {
            pof[j]=pop(a);
            j++;
        }
        pof[j]='\0';
   
    puts(pof);
   
}
int main()
{
    char inf[max],pof[max];
    printf("Enter the expression \n");
    gets(inf);
    strcpy(pof,"");
    convert(inf,pof);
    getch();
    return 0;
}
