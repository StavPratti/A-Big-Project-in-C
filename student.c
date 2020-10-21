#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include"student.h"
#define MAXSTRING 255

//έλεγχος αν υπάρχει ήδη το id
void check(student_t* head, int id)
{
	student_t* current = head;
	while (current->next->id != id)
	{
		if (current->next == NULL)
		{
			printf("Student does not exist.");
			//Αν δεν υπάρχει ο φοιτητής προς διαγραφή ΄γίνεται λήξη της συνάρτησης
			return 0;
		}
		else
		{
			current = current->next;
		}
	}
	if (current->next->id == id)
	{
		//Ο φοιτητής υπάρχει
		printf("%s, %d, student already exists \n", current->next->name, current->next->id);
		return 1;
	}
	else
	{
		//Ο αριθμός id είναι διαθέσημος προς καταχώρηση
		return 0;
	}
}