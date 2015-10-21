#include <stdio.h>
#include<iostream>
#include<string.h>
void select(char* str, int len, char* result, int start, int curr, int dest)
{
    char c=' ';
    if (curr == dest) printf("%s%c",result,c);
    else
    {
        int i;
        for (i = start; curr + len - i >= dest; ++i)
        {
            result[curr] = str[i];
            select(str, len, result, i+1, curr+1, dest);
        }
    }
}

bool check(char *str)
{
    char *s=str;
    int checkstr[1000]={0};
    while(*s!='\0')
    {
        if (checkstr[*s]>0)
        return false;
        else
        {
            checkstr[*s]++;
            s++;
            return true;
        }
    }
}

int main()
{
    char str[52];
    int m;
    char result[1000] = {0};
    scanf("%s %i",&str,&m);
    if(!check(str))
    {
        printf("%s","error input.");
        return 0;
    }
    int n=strlen(str);
    if (m==0 || m>n)
    {
         printf("%s","ERROR");
    }
    else
        select(str, n, result, 0, 0, m);
    return 0;
}
