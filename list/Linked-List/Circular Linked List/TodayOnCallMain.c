#include <stdio.h>
#include "CLinkedList.h"
#include "Company.h"
#include <time.h>

int main(void)
{
	char InputN[NAME_LEN];
	char InputM1[MEM_LEN], InputM2[MEM_LEN];

	List list;
	Company* pcom;

	puts("Write down the company and member, if finished just enter");

	while(TRUE)
	{
		puts("input company name!");
		gets(InputN);
		if(InputN[0]==NULL)
			break;
		puts("input first member's name");
		gets(InputM1);
		if(InputM1[0]==NULL)
			break;
		gets(InputM2);
		if(InputM2[0]==NULL)
			break;
		
		pcom=MakeCompany(InputN,InputM1,InputM2); //MakeNameCard use Malloc function so the datas are saved in the heap
		
		LInsert(&list,pcom);
	}
