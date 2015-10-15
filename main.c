/*******************
*NAME: Clay Nakamura
*
*HOMEWORK: Project 1
*
*CLASS: ICS212
*
*INSTRUCTOR: Ravi Narayan
*
*DATE: October 13th 2015
*
*FILE: main.c
*
*DESCRIPTION: A user interface, that gives the users a set of functions to interact with a linked list ADT
*******************/
#include "headers.h"
#include <stdio.h>
#include <string.h>

int debugMode;

int main(int argc, char * argv[])
{
    char input[100];
    struct record* start = NULL;
    char myIOFile [] = "accountInfo.txt";

    char telenumber[15];
    char name[25];
    char address[80];
    int yearofbirth;

    printf("Now reading file...%s\n", myIOFile);
    readFile(start,myIOFile);

    if(argc == 1)
    {
	debugMode = 1;
    } 
    else if (argc == 2)
    {
		if (strcmp(argv[1],"debug") == 0)
		{
		    debugMode = 2;
		    printf("-----DEBUG MODE-----\n");
		}
		else
		{
		    printf("Incorrect Arguments %d\n", argc);
		    printf("-debug\n");
		    return 0;
		}
    }
    else
    {
	    printf("Incorrect Arguments %d\n", argc);
	    printf("-debug\n");
	    return 0;
    }

    printf("Please enter a command:\n");
    address[0] = '\0';

    do
    {
	    scanf("%s", input);
		/*ADD RECORD*/
        if(strcmp("add", input) == 0)
        {
            address[0] = '\0';
		    printf("Enter record address (press enter x3 times):\n");
		    getField(address);

		    printf("Enter record name:\n");
		    fgets(name, 25, stdin);
		    strtok(name,"\n");

		    printf("Enter telephone number:\n");
		    fgets(telenumber, 15, stdin);
		    strtok(telenumber,"\n");

		    printf("Enter year of birth:\n");
		    scanf("%d", &yearofbirth);

	        addRecord(&start, name, address, yearofbirth, telenumber);
        } 
        else if(strcmp("print",input) == 0)
		{
		    printf("Enter name of record:\n");
		    scanf("%s", name);   
		    printRecord(start, name);
		}
		else if(strcmp("mod",input) == 0)
		{
		    printf("Enter record to modify: \n");
		    scanf("%s", name);

		    printf("Enter address(press enter x3 times): \n");
		    getField(address);

		    printf("Enter telephone number: \n");
		    scanf("%s", telenumber);

		    modifyRecord(start, name, address, telenumber);
		}
		else if(strcmp("printall",input) == 0)
		{
		    printAllRecords(start);
		}
	    else if(strcmp("delete",input) == 0)
		{
		    printf("Enter name of record to delete:\n");
		    scanf("%s",name);
		    deleteRecord(&start, name);
		}
		
		{
			printf("\n----------------COMMANDS----------------\nadd, print, mod, printall, delete, exit\n----------------------------------------\n");
		}
    }
    while(strcmp(input,"exit") != 0);

    /*WRITE TO FILE*/
    printf("now writing to file...\n");
    writeFile(start, myIOFile);

    return 0;
}

void fillArray(int size, char input[])
{
    char current;
    char previous;
    int counter;
    counter = 0;
    current = fgetc(stdin);

    while (counter != size)
    {
        previous = current;
    current = fgetc(stdin);
    input[counter] = current;
    if (previous == '\n')
    {
        if(current == previous)
        {
        break;
        }
    }
    }
}

void getField (char input [])
{
    int count  = 0;

    char temp[100];

    while (count < 2)
    {
    fgets(temp, 100, stdin);
    input[strlen(input)-1] = ' ';
    if (strcmp(temp, "\n") ==  0)
    {
        count++;
    }
    else
    {
        strcat(input,temp);
        count = 0;
    }
    }
    input[strlen(input)-1] = '\0';
}

