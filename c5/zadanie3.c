/*
*Michal Zimniak
*Indeks: 258375
*Lista 5
*Zadanie 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*****************  OBLICZ: bardzo prosty kalkulator  **********************
 * Program czyta z wejscia ciag liczb calkowitych oddzielonych operacjami  *
 * arytmetycznymi: +, -, *, / i wykonuje je kolejno od lewej do prawej.    *
 * Koncem danych jest znak: =.                                             *
 ***************************************************************************/

static const int ARGUMENT=-1;
static int ost_wyraz;        // ostatni wyraz z wejścia
static int ost_znak=' ';    // ostatnio przeczytany znak z wejscia

/***************** PROTOTYPY FUNKCJI ********************/

static long long int wyrazenie(void);
static long long int wyrazenie_priorytet2(long long int arg1,int op);
static long long int czytaj_arg(void);
static int czytaj_op(void);
void blad(const char komunikat[]);

/***************** DEFINICJE FUNKCJI ********************/

static long long int wyrazenie(void)
{
    long long int arg1,arg2;
    int op;
	int op2;
    arg1=czytaj_arg();
    while ((op=czytaj_op()) == '+' || op == '-' || op == '*' || op == '/') {
        arg2=czytaj_arg();
		if(op!='*'&&op!='/')
		{
			/*sprawdz czy nastepny operator to * lub /*/
			while((op2=czytaj_op()) == '*' || op2 == '/')
			{
				arg2=wyrazenie_priorytet2(arg2,op2);
			}
			ungetc(ost_znak,stdin);
			ost_znak=op2;
		}
        switch (op) {
            case '+':
                arg1+=arg2; 
                break;
            case '-':
                arg1-=arg2; 
                break;
            case '*':
                arg1*=arg2; 
                break;
            case '/':
                arg1/=arg2;
                break;
        }
    }
    ost_wyraz=op;
    return arg1;
}

static long long int wyrazenie_priorytet2(long long int arg1,int op)
{
	long long int arg2=czytaj_arg();
	if(op == '*')
		return arg1*arg2;
	else if(op == '/')
		return arg1/arg2;
	return 0;
	
}

int main(void)
{
    long long int wartosc;

    wartosc=wyrazenie();
    if (ost_wyraz != '=' && ost_wyraz != EOF)
      blad("Brak znaku = na końcu wyrażenia");

    printf("%lld\n",wartosc);
    return 0;
}

static long long int czytaj_arg(void)
{
    long long int n=0;
    int znak;

    while (isspace(ost_znak) &&    (ost_znak=getchar()) != EOF) ;
    znak=(ost_znak == '-' ? -1 : 1);
    if (ost_znak == '+' || ost_znak == '-')
        ost_znak=getchar();
    if (isdigit(ost_znak))
        do {
	    n=10 * n + (ost_znak-'0');
	    ost_znak=getchar();
	} while (isdigit(ost_znak));
    else blad("brak argumentu");
    n*=znak;
    ost_wyraz=ARGUMENT;
    return n;
}


static int czytaj_op(void)
{
    while (isspace(ost_znak) &&    (ost_znak=getchar()) != EOF) ;
    ost_wyraz=ost_znak;
    if (ost_znak != EOF) 
        ost_znak=getchar();    
    return ost_wyraz;
}

void blad(const char komunikat[])
{
  printf("\nBŁĄD: %s\n\n",komunikat);
  exit(1);
}
