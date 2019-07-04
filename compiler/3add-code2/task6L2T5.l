%option noyywrap

digit [0-9]
letter_ [A-Za-z_]
op [+\-*/]
dot [\.]
%%
[ \n\t] ;
if|else|for|switch|while|case fprintf(yyout,"Key: %s\n",yytext);
{digit}+ fprintf(yyout,"INT: %s\n",yytext);
{digit}+[.]{digit}+(e[+-]?{digit}+)? fprintf(yyout,"Flt: %s\n",yytext);
{letter_}({letter_}|{digit})* fprintf(yyout,"ID: %s\n",yytext);
{op} fprintf(yyout,"OP: %s\n",yytext);
. fprintf(yyout,"NOT_RECOGNIZED\n");
%%

int main(int argc, char *argv[]){
    yyin = fopen("t.c","r");
    yyout = fopen("t2.txt","w");
    yylex();
    fclose(yyin);
    fclose(yyout);
}
