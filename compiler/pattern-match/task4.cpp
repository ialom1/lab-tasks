#include<iostream>
#include<cstring>
#include<string>
#include <algorithm>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string input_str;

    getline(cin,input_str);

    int len = input_str.size();

    for(int i = 0; i<len; i++)
    {
        input_str[i] = toupper(input_str[i]);
    }
    cout<<input_str<<'\n';

    string Dept_code[]= {"CSE","EEE","IPE","FET","ARC","CEE","CEP","MEE","PME","SWE", "GEB","BMB", "PHY", "MAT","STA","CHE","GEE","OCG","ANP","BNG","ECO","ENG","PSS","PAD","SOC","SCW"};
    bool check[50]= {0};
    //vector<int> found_pos[50];
    for(int i=0; i<25 ; i++)
    {
        //printf("%%%% %d\n",i);
        int pos = 0,cur = 0;
        bool b1 = 0;
        while(cur <= len)
        {
            //printf("-> %d\n",cur);
            pos = input_str.find(Dept_code[i],cur);
            if(pos == -1)
                break ;
            else
            {
                if(pos==0 || input_str[pos-1]==' ')
                {
                    if(pos == len-3 || input_str[pos+3]==' ')
                    {
                        check[i]=1;
                        b1 = 1;

                    }
                    else cur = pos+1;
                }
                else cur = pos+1;

            }

            if(b1==1)
                break;

        }

    }

    for(int j=0; j<25; j++)
    {
        if(check[j]==1)
            cout<<Dept_code[j]<<'\t';
    }
    /*
    for(int i=0; i<25; i++)
    {
        cout<<Dept_code[i]<<" -> ";
        for(int j=0; j<found_pos[i].size(); j++)
        {
            printf("%d ",found_pos[i][j]);
        }
        printf("\n");
    }
    */

    return 0;
}
