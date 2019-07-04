#include<stdio.h>
#include<string.h>

void main()
{
    char str[100],str1[10],str2[10],l[10],r[100],r1[100],r2[100];


    FILE *file_in,*file_out;

    file_in=fopen("left_rec.txt","r");
    file_out=fopen("left_fect.txt","w");

    while (fgets(str,1000, file_in)!=NULL)
    {

        int i,j=0,k,n1,n2,flag=0;

        for(i=0; str[i]!='\0'; i++)
            if(str[i]=='|')
            {
                flag=1;
                break;
            }

        for(i=0; str[i]!='-'&&str[i+1]!='>'; i++)
            l[i]=str[i];
        l[i]='\0';


        i+=2;
        for( ; str[i]!='|'&&str[i]!='\n'; i++,j++){
            str1[j]=str[i];
        }
        str1[j]='\0';


        for(j=++i,i=0; str[j]!='\n'&&j<strlen(str)-1; j++,i++)
            str2[i]=str[j];
        str2[i]='\0';

        if(flag==1)
        {
            if(str1[0]==str2[0])
            {

                k=0,n1=0,n2=0;

                for(i=0; i<strlen(str1)||i<strlen(str2); i++)
                {
                    if(str1[i]==str2[i])
                    {
                        r[k]=str1[i];
                        k++;
                    }
                    else
                    {
                        if(i<strlen(str1))
                        {
                            r1[n1]=str1[i];
                            n1++;
                        }
                        if(i<strlen(str2))
                        {
                            r2[n2]=str2[i];
                            n2++;
                        }
                    }
                }

                r[k]='\0';
                r1[n1]='\0';
                r2[n2]='\0';

                //printf("%s:%d %s:%d\n",r1,strlen(r1),r2,strlen(r2));

                fprintf(file_out,"%s->%s%s'",l,r,l);
                fprintf(file_out,"\n%s'->",l);

                if(strlen(r1)>0 && strlen(r2)>0)
                    fprintf(file_out,"%s|%s\n",r1,r2);
                else
                {
                    strcat(r1,r2);
                    fprintf(file_out,"%s|\u03B5\n",r1);

                   // printf("%s|\356",r1);
                }
            }
            else
            {
                fprintf(file_out,"%s",str);
            }
        }
        else
        {
            fprintf(file_out,"%s",str);
        }
    }

    fclose(file_in);
    fclose(file_out);

}

