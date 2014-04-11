/*
Lista:2ver2
Zadanie:1
Indeks:258375
Mam nieparzysty numer indeksu. Moj program zmienia windows-1250 na iso-8859-2
Michal Zimniak
*/

#include <stdio.h>
#include <stdlib.h>

char cp_1250_to_iso_8859_2[256];

int main()
{
    /*roznice sa pomiedzy A,a,S,s,Z,z*/
    /* [cp] = iso */

    cp_1250_to_iso_8859_2[0xA5]=0xA1;
    cp_1250_to_iso_8859_2[0xB9]=0xB1;
    cp_1250_to_iso_8859_2[0x8C]=0xA6;
    cp_1250_to_iso_8859_2[0x9C]=0xB6;
    cp_1250_to_iso_8859_2[0x8F]=0xAC;
    cp_1250_to_iso_8859_2[0x9F]=0xBC;

    /* a tutaj jest tablica odwrotna
    cp_1250_to_iso_8859_2[0xA1]=0xA5;
    cp_1250_to_iso_8859_2[0xB1]=0xB9;
    cp_1250_to_iso_8859_2[0xA6]=0x8C;
    cp_1250_to_iso_8859_2[0xB6]=0x9C;
    cp_1250_to_iso_8859_2[0xAC]=0x8F;
    cp_1250_to_iso_8859_2[0xBC]=0x9F;
    */
    int c;
    while((c=getchar())!=EOF)
    {
        if(cp_1250_to_iso_8859_2[c]==0)
            putchar(c);
        else
            putchar(cp_1250_to_iso_8859_2[c]);
    }
    return 0;
}
