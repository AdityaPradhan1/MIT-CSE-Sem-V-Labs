
void initialize()
{

	FILE *fa, *fb;
	char filename[100];
	char c, c2;

	//printf("enter the source file \n");
	//scanf("%s", filename);

	fa = fopen("inp.c", "r");
	fb = fopen("op.c", "w+");
	

	//first we remove all the extra spaces
	while((c = fgetc(fa)) != EOF)
	{

		if(c ==' ')
		{
			putc(c ,fb);
			while(c == ' ')
				c = getc(fa);
		}
		if (c == '/')
		{
			c2 = getc(fa);
			if (c2 == '/')
			{
				while(c != '\n')
					c = getc(fa);
			}
			else if (c2 == '*')
			{
				do
				{
					while(c != '*')
						c = getc(fa);
					c = getc(fa);
				} while (c != '/');
			}
			else{
				putc(c,fb);
				putc(c2,fb);
			}
		}
		else 
		{
			putc(c,fb);
		}
	}
	close(fa);
	close(fb);

	// now we remove the header files
	fa = fopen("op.c", "r");
	fb = fopen("temp.c", "w+");
	while ((c = fgetc(fa)) != EOF)
    {
        if(c == '"')
        {
            putc(c,fb);
            c=getc(fa);
            while(c != '"')
            {
                putc(c,fb);
                c=getc(fa);
            }
        }
        else if(c=='#')
        {

            while(c!='\n')
            {

                c=getc(fa);

            }
            c=getc(fa);
        }
    	putc(c,fb);
    }

	fclose(fa);
	fclose(fb);
	
	fa = fopen("temp.c", "r");
	fb = fopen("op.c", "w");
	c = getc(fa);
	while(c != EOF){
		putc(c, fb);
		c = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	remove("temp.c");


}