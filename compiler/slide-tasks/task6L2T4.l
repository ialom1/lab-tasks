%{
int countA=0,countB=0,countC=0;
%}

%option yylineno
%option noyywrap
%%
^\n fprintf(yyout,"%d.\n", yylineno-1);
a countA++;
b countB++;
c countC++;

\n {
    fprintf(yyout,"%d.\tA:%d\tB:%d\tC:%d\n",yylineno-1,countA,countB,countC);
    countA=0;
    countB=0;
    countC=0;
}
<<EOF>> {
    fprintf(yyout,"%d.\tA:%d\tB:%d\tC:%d\n",yylineno,countA,countB,countC);
    yyterminate();
}
%%
int main(){
    yyin = fopen("t.c","r");
    yyout = fopen("t2.txt","w");
    yylex();
    fclose(yyin);
    fclose(yyout);
}
