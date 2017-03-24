#define SIZE 50            /* Size of Stack */
#include<string.h>
#include<ctype.h>
#include<stdio.h>
char s[SIZE];
int top=-1;       /* Global declarations */

void push(char elem)
{                       /* Function for PUSH operation */
    s[++top]=elem;
}

char pop()
{                      /* Function for POP operation */
    return(s[top--]);
}

int pr(char elem)
{                 /* Function for precedence */
    switch(elem)
    {
    case ')': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    }
}

int main()
{                         /* Main Program */
    char infx[50],prfx[50],ch,elem;
    int i=0,k=0;
    printf("\n\nRead the Infix Expression ? ");
    scanf("%s",infx);
     strrev(infx);
     ch=infx[0];
    while( ch != '\0')
    {
        if( ch == ')') push(ch);
        else
            if(isalnum(ch)) {prfx[k++]=ch;
            printf("%c",prfx[k]);}
            else
                if( ch == '(')
                {
                    while( s[top] != ')')
                        prfx[k++]=pop();
                    elem=pop(); /* Remove ) */
                }
                else  /* operator*/
                {


                    while( pr(s[top]) >= pr(ch) )
                        prfx[k++]=pop();
                    push(ch);
                }
                ch=infx[++i];
    }
    while(top != '-1')     /* Pop from stack till empty */
        prfx[k++]=pop();

    strrev(prfx);
    strrev(infx);
    printf("\n\nGiven Infix Expn: %s  Prefix Expn: %s\n",infx,prfx);
}

