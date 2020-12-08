#include "LexicalAnalyzer.c"
struct token tkn;
FILE *f1;
int main()
{
	f1=fopen("Input.c","r");
	if(f1==NULL)
	  {
	  	printf("Error! File cannot be opened!\n");
	  	return 0;
	  }
	  tkn = getNextToken(f1);
	  Program();
	  printf("Program parsed successfully\n");
    fclose(f1);
}

void match(char * t)
{
	if(strcmp(tkn.lexeme,t)==0)
{
	// printf("Matched:%s\n",tkn.lexeme);
	tkn=getNextToken(f1);
}
else
{
	printf("Error parsing, Found:%s Expected:%s\n",tkn.lexeme,t);
	exit(0);
}
}

void Program()
{
	// printf("%s",tkn.lexeme);
	if(strcmp(tkn.lexeme,"main")==0)
	{
		match("main");
		match("(");
		match(")");
		match("{");
		declarations();
		statement_list();
		match("}");
	}
	else
		match("main");
}
void declarations()
{
	if(strcmp(tkn.lexeme,"int")==0 || strcmp(tkn.lexeme,"char")==0)
	{
	match(tkn.lexeme);
	identifier_list();
	if(strcmp(tkn.lexeme,";")==0)
	{
		match(";");
		declarations();
	}
	}
	else
	{
		return;
	}

}
void statement_list()
{
	if(strcmp(tkn.lexeme,"id")==0 || strcmp(tkn.lexeme,"if")==0 || strcmp(tkn.lexeme,"while")==0 ||strcmp(tkn.lexeme,"for")==0 )
	{
		statement();
		statement_list();
	}
	else
		return;
}

void data_type()
{
	if(strcmp(tkn.lexeme,"int")==0)
		match("int");
	else if(strcmp(tkn.lexeme,"char")==0)
		match("char");
	else
	{
		printf("Error parsing, Found:%s Expected:int or char\n",tkn.lexeme);
		exit(0);
	}
	
}

void identifier_list()
{
	if(strcmp(tkn.lexeme,"id")==0)
	{
		match("id");
		identifier_listd();
	}
}
void identifier_listd()
{
	if(strcmp(tkn.lexeme,",")==0)
	{
		match(",");
		identifier_list();
	}
	else if(strcmp(tkn.lexeme,"[")==0)
	{
		match("[");
		match("number");
		match("]");
		identifier_listdd();
	}
	else
		return;
}
void identifier_listdd()
{
	if(strcmp(tkn.lexeme,",")==0)
	{
		match(",");
		identifier_list();
	}
	else 
		return;
}
void statement()
{
	if(strcmp(tkn.lexeme,"id")==0)
	{
		assign_stat();
		match(";");
	}
	else if(strcmp(tkn.lexeme,"if")==0)
	{
		decision_stat();
	}
	else if(strcmp(tkn.lexeme,"while")==0 || strcmp(tkn.lexeme,"for")==0)
	{
		looping_stat();
	}
}
void assign_stat()
{
	if(strcmp(tkn.lexeme,"id")==0)
	{
		match("id");
		match("=");
		expn();
	}
}
void expn()
{
	simple_expn();
	eprime();
}
void eprime()
{
	if(strcmp(tkn.lexeme,"==")==0 || strcmp(tkn.lexeme,"!=")==0
		|| strcmp(tkn.lexeme,"<=")==0 || strcmp(tkn.lexeme,">=")==0
		||strcmp(tkn.lexeme,">")==0 || strcmp(tkn.lexeme,"<")==0)
	{
		relop();
		simple_expn();
	}
	else
		return;
}
void simple_expn()
{
	term();
	seprime();
}
void seprime()
{
	if(strcmp(tkn.lexeme,"+")==0 || strcmp(tkn.lexeme,"-")==0)
	{
		addop();
		term();
		seprime();
	}
	else 
		return;
}
void term()
{
	factor();
	tprime();
}
void tprime()
{
	if(strcmp(tkn.lexeme,"*")==0 || strcmp(tkn.lexeme,"/")==0 ||
		strcmp(tkn.lexeme,"%")==0)
	{
		mulop();
		factor();
		tprime();
	}
	else 
		return;
}
void factor()
{
	if(strcmp(tkn.lexeme,"id")==0)
		match("id");
	else if(strcmp(tkn.lexeme,"number")==0)
		match("number");
	else
	{
		printf("Error parsing, Found:%s Expected:id or number\n",tkn.lexeme);
		exit(0);		
	}
		
}
void decision_stat()
{
	if(strcmp(tkn.lexeme,"if")==0)
	{
		match("if");
		match("(");
		expn();
		match(")");
		match("{");
		statement_list();
		match("}");
		dprime();
	}
}
void dprime()
{
	if(strcmp(tkn.lexeme,"else")==0)
	{
		match("else");
		match("{");
		statement_list();
		match("}");
	}
	else
		return;
}
void relop()
{
	if(strcmp(tkn.lexeme,"==")==0 || strcmp(tkn.lexeme,"!=")==0
		|| strcmp(tkn.lexeme,"<=")==0 || strcmp(tkn.lexeme,">=")==0
		||strcmp(tkn.lexeme,">")==0 || strcmp(tkn.lexeme,"<")==0)
		match(tkn.lexeme);
	else
	{
		printf("Error parsing, Found:%s Expected:relop\n",tkn.lexeme);
		exit(0);
	}
}
void addop()
{
	if(strcmp(tkn.lexeme,"+")==0 || strcmp(tkn.lexeme,"-")==0)
		match(tkn.lexeme);
	else
	{
		printf("Error parsing, Found:%s Expected:addop\n",tkn.lexeme);
		exit(0);
	}
}
void mulop()
{
	if(strcmp(tkn.lexeme,"*")==0 || strcmp(tkn.lexeme,"/")==0 ||
		strcmp(tkn.lexeme,"%")==0)
		match(tkn.lexeme);
	else
	{
		printf("Error parsing, Found:%s Expected:mulop\n",tkn.lexeme);
		exit(0);
	}	
}
void looping_stat()
{
	if(strcmp(tkn.lexeme,"while")==0 )
	{
		match("while");
		match("(");
		expn();
		match(")");
		match("{");
		statement_list();
		match("}");

	}
	else if(strcmp(tkn.lexeme,"for")==0 )
	{
		match("for");
		match("(");
		assign_stat();
		match(";");
		expn();
		match(";");
		assign_stat();
		match(")");
		match("{");
		statement_list();
		match("}");
	}
}




