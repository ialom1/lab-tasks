%option noyywrap

digit [0-9]
letter_ [A-Za-z_]
ID [_a-z][_a-z0-9]*
op [+*/-]
dot [.]
%%
if printf("IF\n");
 
{op} printf("OP\n");

{digit}+ printf("N\n");

{ID} printf("ID\n");

CSE printf("Computer Science & Engineering\n");


. ;
\n ;
%%

int main(){
	yylex();
	return 0;
}