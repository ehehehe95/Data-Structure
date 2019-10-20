#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Namecard.h"

NameCard* MakeNameCard(char *name, char *phone)			//Make a new NameCard
{
	NameCard *NewCard=(NameCard*)malloc(sizeof(NameCard));
	strcpy(NewCard->name,name);
	strcpy(NewCard->phone,phone);
	return NewCard;
}

void ShowNameCardInfo(NameCard *pcard)
{
	printf("Name: %s \n", pcard->name);
	printf("Phone Number: %s \n", pcard->phone);
}

int NameCompare(NameCard *pcard, char *name) //compare the name and return 0 if same, if not return 1 or -1
{
	
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard *pcard, char *phone)
{
	strcpy(pcard->phone,phone);
}