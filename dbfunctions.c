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
*FILE: dbfunctions.c
*
*DESCRIPTION: Contains all functions for writing to and from a specified text file
*******************/
#include "headers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int debugMode;

/*****************
*
*Function name: addRecord
*
*DESCRIPTION: first checks to see if a linked list exists, otherwise it creates a had and fills in the first node
*
*Paramaters: start: a pointer to an array of record structures, 
*            name: the name field of the record, 
*            address: the address field of the record, 
*            yearofbirth: the year of birth of the record, 
*            telNumber: the telephone number of the record
*****************/
int addRecord(struct record ** start, char nameInput [], char addressInput [], int yearofbirthInput, char telnoInput[])
{
    struct record ** dtemp = start;

    struct record *temp;

    if (*dtemp ==  NULL)
    {
        *dtemp = (struct record *) malloc(sizeof(struct record));
        strcpy(((*dtemp)->name), nameInput);
	    strcpy(((*dtemp)->address), addressInput);
	    strcpy(((*dtemp)->telno), telnoInput);
	    (*dtemp)->yearofbirth = yearofbirthInput;
	    (*dtemp)->next = NULL;
        printf("Added a file to the linked list for the first time!\n");
    }
    else
    {
        printf("This was not my first time adding to the file\n");
    }

    temp = *dtemp;


    while ((temp)->next != NULL)
    {
        printf("one loop");
	    temp = (temp)->next;
    }

    (temp)->next = (struct record *) malloc(sizeof(struct record));
    temp = (temp)->next;

    strcpy((temp)->name, nameInput);
    printf("temp is about to get %s\n", nameInput);
    strcpy((temp)->address, addressInput);
    strcpy((temp)->telno, telnoInput);
    (temp)->yearofbirth = yearofbirthInput;

    (temp)->next = NULL;

    if (debugMode == 2)
    {
	printf("----------addRecord Parameters----------\n");
	printf("Name: %s, Address: %s, Year of Birth: %d, Telephone Number: %s\n", nameInput, addressInput, yearofbirthInput, telnoInput);
	printf("----------------------------------------\n\n");
    } 
    return 0;
}

/*****************
*
*Function name: printRecord
*
*DESCRIPTION: takes in a name and prints all of the records that match that name
*
*Paramaters: start: an array of record structures, and the name of the record to match
*
*****************/
int printRecord(struct record * start, char name [])
{
    struct record * temp = start;
    int printCount;
    printCount = 0;

    printf("Printing records that match the name: %s...\n\n", name);

    while (temp != NULL)
    {
        if (strcmp(name, (temp)->name)== 0)
        {
            printCount++;
            printf("Name: %s\nAddress: %s\nBirthyear: %d\nTelephone Number: %s\n\n", (temp)->name, (temp)->address, (temp)->yearofbirth, (temp)->telno);
        }
        temp = (temp)->next;
    }

    if (debugMode == 2)
    {
    	printf("----------printRecord Parameters--------\n");
    	printf("Name: %s\n", name);
    	printf("----------------------------------------\n\n");
    }
    return printCount;
}

/*****************
*Function name: modifyRecord
*
*DESCRIPTION: modifies all records that match the name of the input
*
*Paramaters: start: an array of record structures, 
*            name: the name of the record to modify,
*            address: the address of the newly modified record,
*            telno: the telephone number of the newly modified record,
*****************/
int modifyRecord (struct record * start, char name [],char address [], char telno[])
{
    int modCount;
    modCount = 0;

    if (debugMode == 2)
    {
	printf("--------modifyRecord Parameters---------\n");
	printf("Name: %s, Address: %s, Telephone Number:%s\n", name, address, telno);
	printf("----------------------------------------\n\n");    
    }

    return modCount;
}

/*****************
*
*Function name: printAllRecords
*
*DESCRIPTION: prints each element in the linked list record structure
*
*Paramaters: start: head of linked list
*
*****************/
void printAllRecords(struct record *start)
{
    struct record * temp = start;
    printf("Printing all records...\n\n");
    while (temp != NULL)
    {
        printf("Name: %s\nAddress: %s\nBirthyear: %d\nTelephone Number: %s\n\n", (temp)->name, (temp)->address, (temp)->yearofbirth, (temp)->telno);
	    temp = (temp)->next;
    }
}

/*****************
*Function name: deleteRecord
*
*DESCRIPTION: deletes all records that match the name
*
*Paramaters: start: head of the linked list and the name of the records to delete
*            name: name of the record to delete (including duplicates)
*
*****************/
int deleteRecord(struct record ** start, char name[])
{
    int deleteCount;
    deleteCount = 0;

    if (debugMode == 2)
    {	
    	printf("--------deleteRecord Parameters--------\n");
    	printf("Name: %s\n", name);
    	printf("---------------------------------------\n\n");
    }
    return deleteCount;
}

/*****************
*Function name: readfile
*
*DESCRIPTION: reads all files from a text file onto a linked list data structure (loading the program)
*
*Paramaters: recordArray: pointer to a head of the linked list
*            inputArray: the name of the file with the extension to be read from
*
*****************/
void readFile(struct record * recordArray, char inputArray [])
{

    struct record * temp = recordArray;
    char theString [100];
    char characterInput;
    int counter;
    counter  = 0;
    FILE * infile = fopen(inputArray, "r");

    char name [100];
    char address [100];
    int yearofbirth;
    char telno [20];

    /*If the file exists*/
    if (infile != NULL)
    { 
        /*Populate the string with characters from the infile*/
        while ((characterInput=fgetc(infile)) != EOF)
        {
            theString[counter] = characterInput;
            counter++;
        }
        char s[2] = "\n";
        char *token;
       
        /* get the first token */
        token = strtok(theString, s);
       
        /* walk through other tokens */
        while( token != NULL ) 
        {
            printf( "6Name: %s\n", token );
            strcpy(name, token);       
            
            token = strtok(NULL, s);
            printf( "6Address: %s\n", token );
            strcpy(address, token);       
            
            token = strtok(NULL, s);
            printf( "6Yob: %s\n", token );
            yearofbirth = atoi(token); 

            token = strtok(NULL, s);
            printf( "6Telno:%s\n", token ); 
            strcpy(telno, token);

            printf("Passing into add params: name: %s, address: %s, yearofbirth: %d, telno: %s\n", name, address, yearofbirth, telno);
            addRecord(&temp, name, address, yearofbirth, telno);

            token = strtok(NULL, s); 
        }
    }
    else
    {
        printf("Error: There has to be a file named: %s\n", inputArray);
    }
    fclose(infile);
}

/*****************
*Function name: writefile
*
*DESCRIPTION: writes content into a file
*
*Paramaters: myRecord: head of the linked list, 
*            nameOfFile: name of the file to be written to; with the extension
*
*****************/
void writeFile(struct record *myRecord, char nameOfFile [])
{
    FILE * outfile = fopen(nameOfFile, "w");
    struct record *temp = myRecord;

    /*If there is nothing in the structure*/
    if ((temp) ==  NULL)
    {
        printf("There was nothing to write to the '%s'\n", nameOfFile); 
	    return;
    }
    /*Iterate each record the linked list and print all member fields to output file*/
    while ((temp) != NULL)
    {
        fprintf(outfile, "%s\n", (temp)->name);
    	printf("%s is the name I am writing to the file\n", (temp)->name);	
    	fprintf(outfile, "%s\n", replaceChar((temp)->address, strlen((temp)->address), '\n', ' '));
    	fprintf(outfile, "%s\n", (temp)->telno);
    	fprintf(outfile, "%d\n", (temp)->yearofbirth);
    	temp = (temp)->next;
    }

    fclose(outfile);
}

/*****************
*
*Function name: cleanup
*
*DESCRIPTION: destroy all of the records in the linked list
*
*Paramaters: start: the pointer to the linked list that needs all elements deleted
*
*****************/
void cleanup(struct record **start)
{

}

/*****************
*Function name: replace with character
*
*DESCRIPTION: writes content into a file
*
*Paramaters: start: head of the linked list, 
*            name: name of the file to be written to; with the extension
*
*****************/
char * replaceChar (char inputString [], int length, char charToBeReplaced, char replacementChar)
{
    int i;

    /*Iterate through string and replace all new lines with spaces*/
    for (i = 0; i < length; i++)
    {
        if (inputString[i] == charToBeReplaced)
	    {
	        inputString[i] = replacementChar;	
        }
    	else if (inputString [i] == EOF)
    	{
    	    inputString [i] = replacementChar;
    	}
    }
    return inputString;
}


