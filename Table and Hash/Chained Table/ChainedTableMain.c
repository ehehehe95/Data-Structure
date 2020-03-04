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

	np = MakePersonData(951031, "Young", "Korea");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(000121, "Chan","HongKong");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(980121, "Leo", "Israel");
	TBLInsert(&myTbl, GetSSN(np), np);

	sp = TBLSearch(&myTbl, 951031);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 000121);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 980121);
	if (sp != NULL)
		ShowPerInfo(sp);

	rp = TBLDelete(&myTbl, 951031);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 000121);
	if (rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 980121);
	if (rp != NULL)
		free(rp);

	return 0;

}