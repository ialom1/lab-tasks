#include<iostream>
#include<cstring>
#include<string>
#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#include <vector>
#include<map>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ,count = 0;
    string input_str,temp="";
    vector <string> arg[50],op[50],res;
    map<string,int>mp;
    printf("Press number of 3 address codes :\n");
    scanf("%d",&n);
    getchar();
    for(int i=0; i<n; i++)
    {
        getline(cin,input_str);
        int len = input_str.size();

        for(int j = 0; j<len; j++)
        {
            char c = input_str[j];
            if(isalpha(c) || isdigit(c) )
                temp = temp + c ;
            else if(c == '=' || c == '+' || c == '-' || c == '*' || c == '/')
            {
                string t = "";
                t = t+c;
                //cout<<"=>"<<t<<"\n";
                op[i].push_back(t) ;
            }

            if(c ==' ' || j == len-1)
            {
                if(temp.size()!=0)
                {
                    //cout<<"->"<<temp<<"$\n";
                    arg[i].push_back(temp);
                    temp = "";
                }


            }
        }
    }
    //Quadruple
    printf("Quadruple :\n\n");
    printf("Op\targ1\targ2\tRes\n");
    for(int i=0; i<n; i++)
    {
        res.push_back(arg[i][0]);
        mp[res[i]]=i+1; //mapping Tripple er jonno
        //cout<<res[i]<<" "<<mp[res[i]]<<"\n";
        int op_size = op[i].size();

        if(op_size == 1)
            cout<<"=\t";
        else if (op_size == 2 && arg[i].size() == 2)
            printf("uminus\t");
        else if (op_size == 2 && arg[i].size() == 3)
            cout<<op[i][1]<<"\t";


        for(int j=1; j<arg[i].size(); j++)
        {
            cout<<arg[i][j]<<"\t";
        }
        if(arg[i].size() == 3)
            cout<<res[i]<<"\t";
        else if(arg[i].size() == 2)
            cout<<"\t"<<res[i]<<"\t";
        cout<<"\n";
    }
    printf("\n\n");
    //Triple
    printf("Triple :\n\n");
    printf("\tOp\targ1\targ2\n");
    for(int i=0; i<n; i++)
    {
        cout<<"["<<mp[res[i]]-1<<"]\t";
        int op_size = op[i].size();

        if(op_size == 1)
            cout<<"=\t";
        else if (op_size == 2 && arg[i].size() == 2)
            printf("uminus\t");
        else if (op_size == 2 && arg[i].size() == 3)
            cout<<op[i][1]<<"\t";


        for(int j=1; j<arg[i].size(); j++)
        {
            if(mp[arg[i][j]]==0)
                cout<<arg[i][j]<<"\t";
            else cout<<"["<<mp[arg[i][j]]-1<<"]"<<"\t";
        }


        cout<<"\n";
    }


    return 0;
}
