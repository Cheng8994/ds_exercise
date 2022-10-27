#include "my_stack.cpp"
#include <string.h>
using namespace std;
inline float c2f(char c){return (float)(c-'0');} 

void postfix_operate(char *s)
{
    my_stack<float> a;
    for(int i = 0;i<strlen(s);i++)
    {
        switch (s[i])
        {
        case '*':
            a.push(a.pop()*a.pop());
            break;
        case '/':
            a.push(1/(a.pop()/a.pop()));
            break;
        case '+':
            a.push(a.pop()+a.pop());
            break;
        case '-':
            a.push((a.pop()-a.pop()));
            break;
        default:
            a.push(c2f(s[i]));
            break;
        }
    }
    printf("%.0f ",a.pop());
}

char* infix_2_postfix(char *s)
{
    my_stack<char> a;
    char temp;
    int count = 0;
    char out[80];
    for(int i = 0;i<strlen(s);i++)
    {
        if(s[i] == '*' || s[i] ==  '/')
        {
            if (a.is_empty())
                a.push(s[i]);
            else
            {
                temp = a.pop(); 
                if(temp == '+' || temp =='-')
                    out[count++] = s[i+1],out[count++]=s[i++],a.push(temp);
                else
                    a.push(temp),a.push(s[i]);
            }

        }
        else if(s[i] == '+' || s[i] ==  '-')
        {
            if (a.is_empty())
                a.push(s[i]);
            else
            {
                temp = a.pop(); 
                if(temp == '+' || temp =='-')
                    a.push(temp),a.push(s[i]);
                else
                    out[count++]=temp,a.push(s[i]);
            }
        }
        else
            out[count++]=s[i];
    }
    while(!a.is_empty())
        out[count++]=a.pop();
    out[count]='\0';
    strcpy(s,out);
    return s;
}
    
int main()
{
    char s[80] = "5*3+7-6+3+5"; //shoube be 763*+
    char *sp; 
    sp = infix_2_postfix(s);
    printf("%s\n",sp);
    postfix_operate(sp);
}
