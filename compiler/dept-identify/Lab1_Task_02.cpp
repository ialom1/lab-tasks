#include<iostream>
#include<cstring>
#include<string>
#include <algorithm>
#include <vector>
#include <locale>
#include<bits/stdc++.h>
using namespace std;

string tokens[100];


int tokenizer(string input_str, int len)
{
    int count = 0;
    string tk1="";
    for(int i = 0; i<=len; i++)
    {
        input_str[i] = toupper(input_str[i]);
        if(input_str[i]==' ' || i==len )
        {
            //cout<<tk1<<'\n';
            tokens[count++]=tk1;
            tk1 = "";
        }
        else
        {
            tk1 = tk1 + input_str[i];
        }
    }
    printf("=> %d\n",count);
    return count;
}

bool isnumeric(string s,int len)
{
    bool x = 0;
    for(int i=0;i<len;i++)
    {
        if(s[i]<'0' || s[i]>'9')
        {
            x = 1;
            break;
        }
    }
    if (x == 1)
        return 0;
    else return 1;
}

bool isID(string s,int len)
{
    bool x = 1;
    if(s[0]=='_'|| isalpha(s[0]))
    {
        for(int i=1;i<len;i++)
        {
            if(s[i]=='_'|| isalpha(s[i])||isdigit(s[i]))
            {

            }
            else
            {
                x = 0;
                break;
            }
        }


    }
    else x = 0;
    if(x == 0)
        return 0;
    else return 1;
}

bool isoperator(string s,int len)
{
    if(len == 1 && (s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/'||s[0]=='='))
    {
        return 1;
    }
    else return 0;
}

string deduct(string s)
{
    int len = s.size();

    if(s == "IF")
    return "IF";

    if(s == "CSE")
    return "Computer Science & Engineering";

    bool bul = isnumeric(s,len);
    //printf("%d\n",bul);
    if(bul == 1)
        return "Numeric";

    bool bul2 = isID(s,len);
    //printf("%d\n",bul2);
    if(bul2 == 1)
        return "ID";

    bool bul3 = isoperator(s,len);
    //printf("%d\n",bul3);
    if(bul3 == 1)
        return "OP";

    if(bul ==0 && bul2 ==0 && bul3 == 0)
        return "Unidentified";

}

int main()
{
    string input_str;

    getline(cin,input_str);

    int len = input_str.size();

    for(int i = 0; i<len; i++)
    {
        input_str[i] = toupper(input_str[i]);
    }

    int count = tokenizer(input_str,len);

    for(int i=0;i<count;i++)
    {
        string ans = deduct(tokens[i]);
        cout<<tokens[i]<<'\t'<<ans<<'\n';
    }




    return 0;
}
