/* Make a program that
	1: get the data from the user, and save the data in the list
	2: search the name and show the phone number
	3: search the name and change the phone number
	4: search the name and delete the data from list
	5: print all the phone number saved in the list	*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	char InputN[NAME_LEN];
	char InputP[PHONE_LEN];
	char SearchN[NAME_LEN];
	char ChangeN[PHONE_LEN];
	List list;
	NameCard *pcard;
	ListInit(&list);

	//1: get the data from the user, and save the data in the list
	while(1)
	{
		puts("input user name!");
		gets(InputN);
		if(InputN[0]==NULL)
			break;
		puts("input phone number!");
		gets(InputP);
		if(InputP[0]==NULL)
			break;
		pcard=MakeNameCard(InputN,InputP); //MakeNameCard use Malloc function so the datas are saved in the heap
		Linsert(&list,pcard);
	}

	// 2: search the name and show the phone number
	puts("write the name you want to find");
	gets(SearchN);
	//printf("data saved %s \n",SearchN);
	
	if(LFirst(&list,&pcard)) /*LFirst(&list,pcard) is wrong because the list contains a address of the structures.
							  Use If function since LFirst returns true when succeed*/
	{	
		//printf("if code starts \n");
		if(!NameCompare(pcard,SearchN)) //NameCompare returns 0 when they are same,so !(not)is used
		{
			//printf("this thing works atlease");
			puts("The name and phone number you were looking for is:\n");
			ShowNameCardInfo(pcard);
		}
	
		else
		{	
			//printf("else code starts \n");
			while(LNext(&list,&pcard))
			{
				if(!NameCompare(pcard,SearchN)) 
				{
				
					//printf("this thing works atlease----else\n");
					puts("The name and phone number you were looking for is:");
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}
	//3: search the name and change the phone number
	puts("write the name you want to change phone number");
	gets(SearchN);
	puts("write the number you want to input");
	gets(ChangeN);
	if(LFirst(&list,&pcard))
	{
		if(!NameCompare(pcard,SearchN))
		{
			ChangePhoneNum(pcard,ChangeN);
			puts("change succeed!");
		}
		else
		{

			while(LNext(&list,&pcard))
			{
				if(!NameCompare(pcard,SearchN))
				{
					ChangePhoneNum(pcard,ChangeN);
					puts("change succeed!");
					break;
				}
			}
		}
	}

	//4: search the name and delete the data from list
	puts("write the name you want delete from list");
	gets(SearchN);
	if(LFirst(&list,&pcard))
	{
		if(!NameCompare(pcard,SearchN))
		{
			pcard=LRemove(&list);
			free(pcard);
			puts("Remove Succeed!");
		}
		else
		{
			while(LNext(&list,&pcard))
			{
				if(!NameCompare(pcard,SearchN))
				{
					pcard=LRemove(&list);
					free(pcard);
					puts("Remove Succeed!");
				}
			}
		}
	}



	//5: print all the phone number saved in the list
	LFirst(&list,&pcard);
	ShowNameCardInfo(pcard);
	while(LNext(&list,&pcard))
		{
			
				ShowNameCardInfo(pcard);
	
		}
	system ("pause");
	return 0;
}
