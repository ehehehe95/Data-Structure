#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Company.h"

Company* MakeCompany(char* name,char *mem1, char *mem2)			//Make a new NameCard
{
	Company* newCompany=(Company*)malloc(sizeof(Company));
	strcpy(newCompany->name,name);
	strcpy(newCompany->mem1,mem1);
	strcpy(newCompany->mem2,mem2);
	return newCompany;
}


void ShowCompanyStatus(Company *pcom)
{
	printf("%d company\n member1: %s, memeber2: %s", pcom->name, pcom->mem1, pcom->mem2);
}
