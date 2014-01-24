/******************************************************************************
*File		: Horspool.c
*Description	: Program to find a matching sub string in a given text using
			Horspool's Algorithm
*Author		: Prabodh C P
*Compiler	: gcc compiler 4.6.3, Ubuntu 12.04
*Date		: 21 Nov 2013
******************************************************************************/
#include <stdio.h>
#include <string.h>

const int MAX = 256;

int fnHorspool(char string[], char pattern[],int []);
void fnGenShiftTable(char *,int []);

/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/
int main(void)
{
	char text[MAX];
	char pattern[MAX];
    	int shiftTable[MAX];
	int found;
	puts("Enter the source string : ");
	gets(text);
	puts("Enter the pattern string : ");
	gets(pattern);
	
	fnGenShiftTable(pattern,shiftTable);
	found = fnHorspool(text,pattern,shiftTable);

	if(found==-1)
		puts("\nMatching Substring not found.\n");
	else
		printf("\nMatching Substring found at position: %d\n",found+1);

	return 0;
}
/******************************************************************************
*Function	: fnGenShiftTable
*Description	: Function to generate the shift table
*Input parameters:
*	char p[] - pattern to be searched for
*	int t[]	- shift table containing shift values for each alphabet
*RETURNS	: no value
******************************************************************************/
void fnGenShiftTable(char p[], int t[])
{
	int m, i, j;

	m = strlen(p);

	for(i=0; i<MAX; i++)
	{
		t[i]=m;
	}

	for(j=0; j<m-1; j++)
	{
		t[p[j]] = m-1-j;
	}
}

/******************************************************************************
*Function	: fnHorspool
*Description	: Function to search for a matching substring for a given 
			pattern in the text
*Input parameters:
*	char s[] - text string
*	char p[] - pattern to be searched for
*	int t[]	- shift table containing shift values for each alphabet
*RETURNS	: no value
******************************************************************************/
int fnHorspool(char s[],char p[],int t[])
{
	int i, n, m, k;

	n = strlen(s);
	m = strlen(p);
	i = m-1;
	while(i<n)
	{
		k = 0;
		while((k<m)&&(p[m-1-k]==s[i-k]))
			k++;

		if (k == m)
			return i-m+1;
		else
			i = i+t[s[i]];
	}

	return -1;
}
/********************************************************************************
Sample 1:
Enter the source string : 
I want you to rebel!        
Enter the pattern string : 
you

Matching Substring found at position: 8

Sample 2:
Enter the source string : 
Be a rebel!
Enter the pattern string : 
coward

Matching Substring not found.

********************************************************************************/


