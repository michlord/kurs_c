/* Michal Zimniak
258375
zadanie 1
lista 1
*/

/* w poprzedniej wersji uzylem komentarzy z c++ i nie podalem danych w naglowku, przepraszam
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846L



long double atanT(long double x)
{
    #define N 1000000
    /* abs(x)<1 */
    long double sum=0.0;
    int sign = 1;
    for(int i=0;i<N;++i)
    {
        /*sum+=powl(-1.0L,i)*powl(x,2.0L*i+1.0L)/(2.0L*i+1.0L);*/
        sum+=(long double)sign*powl(x,2.0L*i+1.0L)/(2.0L*i+1.0L);
        sign=(-1)*sign;
    }
    return sum;
}

int main()
{

    long double p3=4.0L*(12.0L*atanT(1.0L/49.0L)+32.0L*atanT(1.0L/57.0L)-5.0L*atanT(1.0L/239.0L)+12.0L*atanT(1.0L/110443.0L));
    printf("Pi z wikipedii (long double):\t ");
    printf("%21.19Lf\n",PI);
    printf("Pi z double:\t\t\t ");
    printf("%17.15f\n",(double)p3);
    printf("Pi z long double:\t\t ");
    printf("%21.19Lf\n",p3);


    return 0;
}
