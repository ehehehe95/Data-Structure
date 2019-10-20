#ifndef __namecard
#define __namecard

#define NAME_LEN	30
#define PHONE_LEN	30


typedef struct __namecard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
} NameCard;

// make a NameCard by the data given by user
NameCard *MakeNameCard(char *name, char *phone);

// show the datas inside the NameCard
void ShowNameCardInfo(NameCard *pcard);

// compare weather the NameCard contains the same name, if it does return 0, if not return 1
int NameCompare(NameCard *pcard, char *name);

//change the phone number in the card
void ChangePhoneNum(NameCard *pcard, char *phone);

#endif
