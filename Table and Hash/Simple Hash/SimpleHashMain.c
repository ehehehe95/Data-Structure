#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{

	Table myTbl;
	Person* np;
	Person* sp;
	Person* rp;

	TBLInit(&myTbl, MyHashFunc);

	np = MakePersonData(20140588, "Cho", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20200103, "Ho", "Beijing");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20182132, "Jane", "Huston");
	TBLInsert(&myTbl, GetSSN(np), np);

	sp = TBLSearch(&myTbl, 20140588);
	if (sp != NULL)
		ShowPerInfo(sp);

	rp = TBLDelete(&myTbl, 20140588);
	if(rp!=NULL)
		free(rp);

	return 0;

}