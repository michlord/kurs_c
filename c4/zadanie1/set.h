#define SIZE_LIMIT 1000 /*LIMIT is equal to size of an array but this array will hold only LIMIT-1 elements*/
typedef int SET[SIZE_LIMIT];
typedef int ELEMENT;


void clearSet(SET s);
void unionSets(const SET s1,const SET s2,SET outcome);
void intersectSets(const SET s1,const SET s2,SET outcome);
void addElement(SET s,ELEMENT e);
void deleteElement(SET s,ELEMENT e);
