//NAME-Omkar Temgire
//DIV-D(4)
//ROLL NO-203463

#include<stdio.h>
#include<string.h>

char stack [20][20];          //2D stack for storing strings 
int top=-1;                   //pointer 
char* pop()                                       //pop function
{
 
 char *temp;
 temp=stack[top];
 top--;
 return(temp);
}
  


void pretoin(char exp[20])
{
 char str[20],str1[40];
 char op1[20],op2[20];
int i,l;
l=strlen(exp);
for (i=l;i>=0;i--)
  {
    if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')              //for operator
       {
         //pop 2 element  from stack 
         
         int l;
        								// temp = pop();
        								// temp1=pop();
 	strcpy(str, " ");
         strcpy(op1,pop());
         strcpy(op2,pop());
          str[0]='(';                 // bracket ( start
          str[1]='\0';
          strcat(str,op1);           //1nd operand copy
            l=strlen(str);
            str[l]=exp[i];           //operator copy              (2nd-oprand operator  1st oprand)
            str[l+1]='\0';
          strcat(str,op2);          //1st operand copy 
            l=strlen(str);
            str[l]=')';            // bracket ) close
            str[l+1]='\0';
            top++;
            strcpy(stack[top],str);
        }
   
      else                                                                     //for operand
         {
           
           top++;
           char st[20];
           strcpy(st, " ");
           st[0]=exp[i];
           st[1]='\0';
           strcpy(stack[top],st);
         }
   }
    
      strcpy(str1,pop());
      printf("%s",str1);                                  //displaying infix expression
}
 
   
int main()
{
 char exp[20];
printf("enter the expression:\n");
scanf("%s",exp);                              //accepting postfix expression

pretoin(exp);


return 0;
}

