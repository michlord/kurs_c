/*
Lista:2ver2
Zadanie:3
Indeks:258375
Michal Zimniak
*/
#include <stdio.h>
#include <stdbool.h>

static bool wystapil(char wzor[], char buf[], int pozycja)
{
    int i,j; 
    for (i=0,j=pozycja; wzor[i]==buf[j]; ++i,++j)
        if (wzor[i] == '\0') return true;
    return (wzor[i]=='\0');
}

static int dlugosc(char tekst[])
{
    int i=0;
    while (tekst[i] != '\0') ++i;
    return i;
}

static int liczOdcisk(char *tekst)
{
	int odcisk=0;
	while(*tekst)
	{
		odcisk+=*tekst;
		++tekst;
	}
	return odcisk;
}

int main(int argc, char *argv[])
{
    char bufor[1000];
    int dlugosc_wzorca,dlugosc_wiersza;
	int odcisk_wzorca,odcisk_fragmentu;
	int liczba_trafien_odcisku=0,liczba_trafien_wzorca=0;
    if (argc <= 1) 
	{
        printf("Prawidlowe wywolanie programu:\n\t%s wzorzec\n",argv[0]);
		return 1;
    }
    dlugosc_wzorca=dlugosc(argv[1]);
	odcisk_wzorca=liczOdcisk(argv[1]);
	
    while (fgets(bufor,sizeof(bufor),stdin) != NULL) 
	{
        dlugosc_wiersza=dlugosc(bufor);
		odcisk_fragmentu=liczOdcisk(bufor+dlugosc_wiersza-dlugosc_wzorca);
		for (int i=dlugosc_wiersza-dlugosc_wzorca; i >= 0; --i)
		{
			if(odcisk_wzorca==odcisk_fragmentu)
			{
				++liczba_trafien_odcisku;
				if (wystapil(argv[1],bufor,i)) 
				{
					/*fputs(bufor,stdout);*/
					++liczba_trafien_wzorca;
					/*break;*/
				}
			}		
			if(i>0)
				odcisk_fragmentu=odcisk_fragmentu-bufor[i+dlugosc_wzorca-1]+bufor[i-1];
		}
    }
	printf("Odcisk:%d\n",odcisk_wzorca);
	printf("Liczba trafien odcisku:%d\nLiczba trafien wzorca:%d",liczba_trafien_odcisku,liczba_trafien_wzorca);
    return 0;
}
