#include <stdio.h>
typedef long long int FRACTION;
FRACTION getFractionFromStream(FILE *stream);
void writeFractionToStream(FILE *stream,FRACTION a);
FRACTION makeFractionFromInt(int numerator,int denominator);
int getFractionNumerator(FRACTION a);
int getFractionDenominator(FRACTION a);
FRACTION addFraction(FRACTION a,FRACTION b);
FRACTION subFraction(FRACTION a,FRACTION b);
FRACTION mulFraction(FRACTION a,FRACTION b);
FRACTION divFraction(FRACTION a,FRACTION b);