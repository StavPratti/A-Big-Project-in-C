#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#define MAXSTRING 255


typedef struct student
{
	char name[MAXSTRING];
	int id;

	struct student* next;
}student_t;

void printMenu(char filename, student_t * head)
{
	printf("Press\n1: To add a student \n2: To delete a student \n3: To print all students \n4: To search a student \n0: To exit  ");
	int answer;
	scanf("%d", answer);

	switch (answer)
	{
	case 1:
		//Έλεγχος αν υπάρχει ο φοιτητής
		if( add(head, filename) == 0)
		{ 
			save(filename, head);
		}
		break;
	case 2:
		//Διαγραφή φοιτητή
		printf("Give student id for deletion: ");
		int id;
		scanf("%d", id);
		deleteStudent(id, head);
		break;
	case 3:
		//Εκτύπωση όλων των φοιτητών
		print(head, filename);
		break;
	default:
		//Σώζει τους φοιτητές στη βάση πριν κλείσει η εφαρμογή
		updateStudent(filename, head);
		//Έξοδος από το πρόγραμμα
		exit(EXIT_SUCCESS);
		break;
	}
}

//Η συνάρτηση αναζητά και τυπώνει τα στοιχεία ενός φοιητητή
int findStudent(int id, student_t * head)
{
	student_t* current = head;
	while (current->next->id != id)
	{
		if (current->next == NULL)
		{
			printf("Student does not exist.");
		}
		else
		{
			current = current->next;
		}
	}
	if (current->id == id)
	{
		printf("Student found, %d, %s", current->id, current->name);
	}
	return 0;
}

int load(char filename, student_t* head)
{
	FILE* fptr;
	fptr = fopen(filename, "r");
	char c;
	c = fgetc(fptr);

	student_t* current = head;
	current->next = malloc(sizeof(student_t));
	
	char str[MAXSTRING];
	
	while (c != EOF)
	{
		//Η γραμμή διαβάζεται χαρακτήρα ανά χαρακτήρα και γίνονται ένα string 
		strncat(str, &c, 1);
		current->next->name = str;
		//printf("%c ", c);
		c = fgetc(fptr);
		current->next->id = c;
	}
	fclose(fptr);

	return 0;
}

//Σώζει το struct στο txt 
void updateStudent(char filename, student_t* head)
{
	FILE* f = fopen(filename, "w");
	student_t* current = head;
	while(current->next != NULL)
	{
		//Καταγραφή του ονόματος (αλλαγή γραμμής) καταγραφή του id
		fprintf(f,"\n", current->name);
		fprintf(f, "\n", "\n");
		fprintf(f, "\n", current->id);
	}
}

int deleteStudent(int id, student_t * head)
{
	student_t* current = head;
	student_t* temp = NULL;
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
	if (current->next->next != NULL)
	{
		temp = current->next->next;
	}
	free(current->next);
	current->next = temp;
	free(temp);
	return 0;
}

void print(student_t * head, char filename)
{
	//Print everything in linked list
	student_t* current = head;
	while (current->next != NULL)
	{
		printf("%d, %s", current->id, current->name);
	}
	printf("%d, %s", current->id, current->name);

	/*
	//Print txt
	FILE* fptr;
	fptr = fopen(filename, "r"); 
	char c;
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c \n", c);
		c = fgetc(fptr);
	}
	fclose(fptr);
	*/
}

