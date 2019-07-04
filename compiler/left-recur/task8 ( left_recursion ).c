#include<stdio.h>
#include<string.h>
int main()
{
    char input[100],*l,*r,*temp,tempprod[20],productions[25][50],str[100];

    FILE *file_in,*file_out;

    file_in=fopen("grammer.txt","r");
    file_out=fopen("left_rec.txt","w");

    while (fgets(str,1000, file_in)!=NULL)
    {
        int flag=0,j;

        strcpy(input,str);

        l = strtok(input,"->");
        r = strtok(NULL,"->");
        temp = strtok(r,"|");

        while(temp)
        {

            if(temp[0] == l[0])
            {
                flag = 1;
                sprintf(productions[1],"%s'->%s%s'|\u03B5\0",l,temp+1,l);
            }
            else
                sprintf(productions[0],"%s->%c%s'\0",l,temp[0],l);


            temp = strtok(NULL,"|");

        }

        // sprintf(productions[2],"%s'->\u3B5\0",l);
        if(flag == 0)
            fprintf(file_out,"%s",str);
        else
            for(j=0; j<2; j++)
                fprintf(file_out,"%s\n",productions[j]);

    }

    fclose(file_in);
    fclose(file_out);

}
