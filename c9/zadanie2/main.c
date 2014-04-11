/*
*Michal Zimniak
*Indeks 258375
*Lista 9
*Zadanie 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define RES_IDENT 1
#define RES_BLANK 2
#define RES_DIFF 4

char res_messages[3][256] = {"Pliki sa identyczne\n","Pliki roznia sie tylko bialymi znakami\n","Pliki roznia sie trescia\n"};

int fileCmp(const char* fname1, const char* fname2)
{
	FILE *fp1;
	FILE *fp2;
	fp1=fopen(fname1,"r");
	if(fp1==0)
	{
		fprintf(stderr,"Unable to open %s\n",fname1);
		return 1;
	}
	fp2=fopen(fname2,"r");
	if(fp2==0)
	{
		fprintf(stderr,"Unable to open %s\n",fname2);
		return 1;
	}
	
	int res=RES_IDENT;
	int row_counter=1;
	int ch1=0,ch2=0;
	while(ch1!=EOF)
	{
		ch1=fgetc(fp1);
		ch2=fgetc(fp2);
		
		if(isblank(ch1)||isblank(ch2))
		{
			if(isblank(ch1)&&isblank(ch2))
			{
			}
			else
			{
				res|=RES_BLANK;
				if(isblank(ch1))
				{
					while(isblank(ch1=fgetc(fp1)))
						;
				}
				else if(isblank(ch2))
				{
					while(isblank(ch2=fgetc(fp2)))
						;
				}
			}
		}
		
		if(ch1!=ch2)
		{
			res|=RES_DIFF;
			break;
		}
		
		if(ch1=='\n')
			row_counter+=1;		
	}
	
	if(res&RES_DIFF)
	{
		fprintf(stdout,"%s",res_messages[2]);
		fprintf(stdout,"%d:\n",row_counter);
		
		rewind(fp1);
		rewind(fp2);
		int cnt=1;
		while(cnt<row_counter && ((ch1=fgetc(fp1))!=EOF) )
			if(ch1=='\n')
				cnt+=1;
		cnt=1;
		while(cnt<row_counter && ((ch2=fgetc(fp2))!=EOF) )
			if(ch2=='\n')
				cnt+=1;
		fprintf(stdout,"%s:\n",fname1);		
		while((ch1=fgetc(fp1))!=EOF && ch1!='\n')
			putchar(ch1);
		putchar('\n');
		fprintf(stdout,"%s:\n",fname2);
		while((ch2=fgetc(fp2))!=EOF && ch2!='\n')
			putchar(ch2);
		putchar('\n');
		
	}
	else if(res&RES_BLANK)
	{
		fprintf(stdout,"%s",res_messages[1]);
	}
	else
	{
		fprintf(stdout,"%s",res_messages[0]);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

int main(int argc, char **argv)
{
	char fname1[FILENAME_MAX];
	char fname2[FILENAME_MAX];
	if(argc==3)
	{
		strncpy(fname1,argv[1],FILENAME_MAX);
		strncpy(fname2,argv[2],FILENAME_MAX);
		fname1[FILENAME_MAX-1]=0;
		fname2[FILENAME_MAX-1]=0;
	}
	else
	{
		fprintf(stderr,"Usage: %s [file name 1] [file name 2]\n",argv[0]);
	}
	return fileCmp(fname1,fname2);	
}