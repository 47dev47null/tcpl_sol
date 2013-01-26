/* Exercise 1-24
 * Write a program to check a C program for rudimentary
 * syntax errors like unbalanced parentheses, brackets
 * and braces. Don't forget about quotes, both single and
 * double, escape sequences, and comments. (This program
 * is hard if you do it in full generality.)
 */


/* This is a shameless copy of Rick Dearman's solution, 
 * which check the syntax of a C program for matching
 * {}, [], (), "", ''
 */

#include <stdio.h>

#define MAXLINE 1000

int obtenirline(char s[], int lim);

int main(void)
{
	int len;
	char line[MAXLINE];
	int brace, bracket, parenthesis;
	int s_quote, d_quote;
	int t;

	brace = bracket = parenthesis = 0;
	s_quote = d_quote = 1;
  	while ((len = obtenirline(line, MAXLINE)) > 0 )
    {
    	for (t = 0; t < len; ++t)
    	{
    		if( line[t] == '[')
		  	{
		  	  	brace++;
		  	}
			if( line[t] == ']')
		  	{
		  	  	brace--;
		  	}
			if( line[t] == '(')
		  	{
		    	parenthesis++;
		  	}
			if( line[t] == ')')
		  	{
		    	parenthesis--;
		  	}
			if( line[t] == '\'')
		  	{
		    	s_quote *= -1;
		  	}
			if( line[t] == '"')
			{
		    	d_quote *= -1;
		  	}
    	}
    }
  	if(d_quote != 1)
  	  	printf("Mismatching double quote mark\n");
  	if(s_quote != 1)
  	  	printf("Mismatching single quote mark\n");
  	if(parenthesis != 0)
  	  	printf("Mismatching parenthesis\n");
  	if(brace != 0)
  	  	printf("Mismatching brace mark\n");
  	if(bracket != 0)
  	  	printf("Mismatching bracket mark\n");
  	if(bracket==0 && brace==0 && parenthesis==0 && s_quote == 1 && d_quote == 1)
  	    printf ("Syntax appears to be correct.\n");

  	return 0;
}


int obtenirline(char s[], int lim)
{
	int i, c;

	for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;
	if (c == '\n')
		s[i++] = '\n';
	s[i] = '\0';

	return i;
}