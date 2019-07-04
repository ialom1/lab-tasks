#include<stdio.h>
#include<string.h>

void main()
{
    char str[100],ter[100][10],nonter[100][10];
    int i,t=0,nt=0,tt=0,j;

    FILE *file_in,*file_out;

    file_in=fopen("left_rec.txt","r");
    file_out=fopen("ter_nonter.txt","w");

    while (fgets(str,1000, file_in)!=NULL)
    {

        if(strlen(str)==1)
        {
            int flag=0;

            fprintf(file_out,"Terminal:\n");

            for(i=0; i<t; i++)
            {
                if(strlen(ter[i])>0)
                {
                    if(flag==0)
                    {
                        fprintf(file_out,"%s",ter[i]);
                        flag=1;
                    }
                    else
                        fprintf(file_out,",%s",ter[i]);
                }
            }

            fprintf(file_out,"%s",str);

            flag=0;
            fprintf(file_out,"Non-Terminal:\n");

            for(i=0; i<nt; i++)
            {
                if(flag==0)
                {
                    fprintf(file_out,"%s",nonter[i]);
                    flag=1;
                }
                else
                    fprintf(file_out,",%s",nonter[i]);
            }

            fprintf(file_out,"%s",str);

            t=0,nt=0,tt=0;

            fprintf(file_out,"%s",str);
        }
        else
        {

            for(i=0; i<strlen(str)-1; i++)
            {

                if(str[i]>=65 && str[i]<=90)
                {
                    if(str[i]>=65 && str[i]<=90)
                    {

                        nonter[nt][0]=str[i];
                        nonter[nt][1]='\0';

                        if(str[i+1]=='\'')
                        {
                            nonter[nt][1]=str[i+1];
                            nonter[nt][2]='\0';
                            i++;
                        }

                        for(j=0; j<nt; j++)
                        {
                            if(strcmp(nonter[nt],nonter[j])==0)
                            {
                                nt--;
                                break;
                            }
                        }

                        nt++;

                        ter[t][tt]='\0';


                        for(j=0; j<t; j++)
                        {
                            if(strcmp(ter[t],ter[j])==0)
                            {
                                t--;
                                break;
                            }
                        }

                        t++,tt=0;

                    }

                }
                else if((str[i]=='-'&&str[i+1]=='>')||str[i]=='|'||i==strlen(str)-2)
                {
                    if(str[i+1]=='>')
                        i++;

                    if(i==strlen(str)-2)
                        ter[t][tt++]=str[i];

                    ter[t][tt]='\0';

                    for(j=0; j<t; j++)
                    {
                        if(strcmp(ter[t],ter[j])==0)
                        {
                            t--;
                            break;
                        }
                    }
                    t++,tt=0;

                }
                else
                {
                    ter[t][tt++]=str[i];
                }

            }

        }

    }

    fclose(file_in);
    fclose(file_out);

}

