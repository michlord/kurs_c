/*
*Michal Zimniak
*Lista 9
*Zadanie 1
*indeks258375
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RES_OK 0
#define RES_FILE_NOT_EXIST 1
#define RES_FILE_CANT_SAVE 2

void changeFileNumber(char* str,int len,int num)
{
    char *p = strrchr(str,'.');
    char tmp[FILENAME_MAX];
    strncpy(tmp,p,FILENAME_MAX);
    tmp[FILENAME_MAX-1]=0;
    sprintf(p,"-%0*d",3,num);
    strncat(p,tmp,FILENAME_MAX-len);
}

long getFileSizeBin(FILE *fh)
{
    fseek(fh, 0L, SEEK_END);
    long file_size_b=ftell(fh);
    rewind(fh);
    return file_size_b;
}

int splitBinaryFile(const char* file_name,int file_name_len,int parts)
{
    char new_file_name[FILENAME_MAX];
    FILE* fhandle_in=fopen(file_name,"rb");
    if(fhandle_in==0)
        return RES_FILE_NOT_EXIST;

    long file_size_b=getFileSizeBin(fhandle_in);

    char *buffer=(char*)malloc(sizeof(char)*file_size_b);

    fread(buffer,sizeof(char),file_size_b,fhandle_in);

    if(file_size_b<parts)
    {
        strncpy(new_file_name,file_name,FILENAME_MAX);
        changeFileNumber(new_file_name,file_name_len,1);
        FILE *fhandle_out=fopen(new_file_name,"wb");
        if(fhandle_out==0)
            return RES_FILE_CANT_SAVE;
        fwrite(buffer,sizeof(char),file_size_b,fhandle_out);
        fclose(fhandle_out);
    }
    else
    {
        int buffp=0;
        int new_size = file_size_b/parts;
        int extra_1 = file_size_b%parts;
        for(int i=0;i<new_size;++i)
        {
            int save_size=new_size;
            if(extra_1>0)
            {
                extra_1-=1;
                save_size+=1;
            }

            printf("Size %d\n",save_size);

            strncpy(new_file_name,file_name,FILENAME_MAX);
            changeFileNumber(new_file_name,file_name_len,i+1);
            FILE *fhandle_out=fopen(new_file_name,"wb");
            if(fhandle_out==0)
                return RES_FILE_CANT_SAVE;
            fwrite(buffer+buffp,sizeof(char),save_size,fhandle_out);
            fclose(fhandle_out);
            buffp+=save_size;
        }
    }
    free(buffer);
    fclose(fhandle_in);
    return RES_OK;
}
int amountOfRows(const char* str,int len)
{
    int counter=0;
    for(int i=0;i<len;++i)
    {
        if(str[i]=='\n')
            ++counter;
    }
    return counter+1;
}
int splitTextFile(const char* file_name, int file_name_len,int parts)
{
    char new_file_name[FILENAME_MAX];
    FILE* fhandle_in=fopen(file_name,"r");
    if(fhandle_in==0)
        return RES_FILE_NOT_EXIST;

    long file_size_b=getFileSizeBin(fhandle_in);
    char *buffer=(char*)malloc(sizeof(char)*file_size_b);
    fread(buffer,sizeof(char),file_size_b,fhandle_in);
    int len = strlen(buffer);
    int rows_amt = amountOfRows(buffer,len);
    printf("Rows amount: %d\n",rows_amt);
    if(rows_amt<parts)
    {
        strncpy(new_file_name,file_name,FILENAME_MAX);
        changeFileNumber(new_file_name,file_name_len,1);
        FILE *fhandle_out=fopen(new_file_name,"w");
        if(fhandle_out==0)
            return RES_FILE_CANT_SAVE;
        fwrite(buffer,sizeof(char),file_size_b,fhandle_out);
        fclose(fhandle_out);
    }
    else
    {
        int last_file_number=1;
        strncpy(new_file_name,file_name,FILENAME_MAX);
        changeFileNumber(new_file_name,file_name_len,last_file_number++);
        FILE *fhandle_out=fopen(new_file_name,"w");

        int counter=0;

        int new_size = rows_amt/parts;
        int extra_1 = rows_amt%parts;
        for(int i=0;i<len;++i)
        {
            char c=buffer[i];
            if(c=='\n')
                ++counter;
            fputc(c,fhandle_out);
            if(extra_1>0 && counter==new_size+1)
            {
                extra_1-=1;
                fclose(fhandle_out);
                strncpy(new_file_name,file_name,FILENAME_MAX);
                changeFileNumber(new_file_name,file_name_len,last_file_number++);
                fhandle_out=fopen(new_file_name,"w");
                counter=0;
            }
            else if(extra_1==0 && counter==new_size)
            {
                fclose(fhandle_out);
                strncpy(new_file_name,file_name,FILENAME_MAX);
                changeFileNumber(new_file_name,file_name_len,last_file_number++);
                fhandle_out=fopen(new_file_name,"w");
                counter=0;
            }

        }
        fclose(fhandle_out);
    }
    free(buffer);
    fclose(fhandle_in);
    return 0;
}

int main(int argc,char **argv)
{
    int text_mode=0;
    char file_name[FILENAME_MAX];
    int file_name_len;
    int parts_amt;
    if(argc==4 || argc==3)
    {
        int a=2,b=3;
        text_mode=(strncmp(argv[1],"-t",2)==0);
        if(text_mode==0)
            {a-=1;b-=1;}
        strncpy(file_name,argv[a],FILENAME_MAX);
        file_name[FILENAME_MAX-1]=0;
        file_name_len=strlen(file_name);
        sscanf(argv[b],"%d",&parts_amt);
        printf("File name: %s, Text mode: %d, Parts amount: %d\n",file_name,text_mode,parts_amt);
    }
    else
    {
        printf("Usage: %s [-t] filename.txt parts_amount\n",argv[0]);
    }
    int res=RES_OK;
    if(text_mode==1)
    {
        res=splitTextFile(file_name,file_name_len,parts_amt);
    }
    else
    {
        res=splitBinaryFile(file_name,file_name_len,parts_amt);
    }
    if(res==RES_OK)
        return RES_OK;
    if(res==RES_FILE_NOT_EXIST)
    {
        printf("%s does not exist\n",file_name);
    }
    if(res==RES_FILE_CANT_SAVE)
    {
        printf("Cannot save new files\n");
    }
}
