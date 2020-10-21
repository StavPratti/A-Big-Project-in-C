#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"
#define MAXSTRING 255



int main(char filename[])
{
	//Η main δέχεται ΄σαν όρισμα το όνομα του αρχείου
	const char* extension = ".txt";
	//Γίνεται ένωση των 2 strings (του ονόματος που δόθηκε και της κατάληξης του αρχείου)
	char* name_with_extension;
	name_with_extension = malloc(strlen(filename) + 1 + 4);
	strcpy(name_with_extension, filename);
	strcat(name_with_extension, extension);
	
	//Δέσμευση χώρου για τη κεφαλή του στρακτ
	student_t* head = malloc(sizeof(student_t));

	//
	FILE* file;
	file = fopen(name_with_extension, "r");
	//Έλεγχος αν το αρχείο .txt υπάρχει
	if (file)
	{
		printf("Database (txt file) found.\n");
	}
	//To αρχείο δεν βρέθηκε
	else
	{
		printf("Database (txt file) doesn't exist.\n");
		//Δημιουργία του αρχείου db.txt
		FILE* fp = NULL;
		fp = fopen(name_with_extension, "a");
		printf("New database created.\n");
	}
	//Φορτώνεται από το αρχείο στη συνδεδεμένη λίστα, ο κατάλογος των φοιτητών
	load(filename, head);
	//Ατέρμωνη λούπα για την εκτέλεση του προγράμματος
	while(1)
	{
		printMenu(name_with_extension, head);
	}

	return 0;
}