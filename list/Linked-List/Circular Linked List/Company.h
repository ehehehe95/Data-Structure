#ifndef __COMPANY_H__
#define __COMPANY_H__

#define NAME_LEN	30
#define MEM_LEN		30

typedef struct _company
{
	char name[NAME_LEN]; //  the name of the company
	char mem1[MEM_LEN], mem2[MEM_LEN];// member of the company

} Company;

Company* MakeCompany(char *name, char *mem1, char *mem2)

//void ShowCompanyStatus(Company *pcom);

//void ShowTodayOnCall(Company *pcom);


#endif
