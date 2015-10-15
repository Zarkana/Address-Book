/*******************
*
*NAME: Joseph Campbell
*
*PROJECT: 1
*
*CLASS: ICS212
*
*INSTRUCTOR: Ravi Narayan
*
*DATE: October 6th 2015
*
*FILE: storage.c
*
*DESCRIPTION: Contains the storage functions for project 1
*
*******************/

#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
extern int DEBUGMODE;

/*****************
*
*Function name: addRecord
*
*DESCRIPTION: create a record even if it already exists with the same name
*
*Paramaters: start: a pointer to an array of record structures storing friends, name: the name of friend, address: the address of friend,
*            yearofbirth: the friends year of birth, telNumber: the number of the friend 
*
*****************/
int addRecord(struct record **start, char uname[], char uaddr[], int uyob, char utelno[])
{
    if(DEBUGMODE == 0)
    {
        printf("***DEBUG INFORMATION***\n");
        printf("Called Function: addRecord(struct record **, char[], char[], int, char[])\n");
        printf("struct record **: %x ", start);
        printf("char[]:name =  %s \n", uname);
        printf("char[]:address = %s \n", uaddr);
        printf("int:yearofbirth = %d \n", uyob);
        printf("char[]:telNumber = %s \n", utelno);
        printf("\n***END DEBUG***\n");
    }

    /*struct record ** dtemp = start;*/

    struct record *temp;
    temp = *start;

    if (*start ==  NULL)
    {
        *start = (struct record *) malloc(sizeof(struct record));
        strcpy(((*(*start)).name), uname);
        strcpy(((*(*start)).address), uaddr);
        (*(*start)).yearofbirth = uyob;        
        strcpy(((*(*start)).telno), utelno);

        (*(*start)).next = NULL;
    }
    else
    {
        while ((*temp).next != NULL)
        {
            temp = (*temp).next;
        }

        (*temp).next = (struct record *) malloc(sizeof(struct record));
        temp = (*temp).next;

        strcpy((*temp).name, uname);
        strcpy((*temp).address, uaddr);
        (*temp).yearofbirth = uyob;        
        strcpy((*temp).telno, utelno);

        (*temp).next = NULL;
    }

    return 0;
}

/*****************
*
*Function name: printRecord
*
*DESCRIPTION: print on the screen information for all records with the name specified
*
*Paramaters: start: an array of record structures storing friends, name: the name of friend 
*
*****************/
int printRecord(struct record *start, char uname[])
{
    if(DEBUGMODE == 0)
    {
   	    printf("***DEBUG INFORMATION***\n");
        printf("Called Function: printRecord(struct record *, char[])\n");
        printf("struct record *: %x \n", start);
        printf("char[]:uname = %s \n", uname);
   	    printf("\n***END DEBUG***\n");
    }   
    
    /*struct record * temp = start;*/
    int count;
    count = 0;

    printf("Records with name: %s\n", uname);

    while (start != NULL)
    {
        if (strcmp(uname, (*start).name)== 0)
        {
            count++;
            printf("Name: %s\nAddress: %s\nBirthyear: %d\nTel Number: %s\n\n", (*start).name, (*start).address, (*start).yearofbirth, (*start).telno);
        }
        start = (*start).next;
    }

    return count;
    
    return 0;
}


/*****************
*
*Function name: modifyRecord
*
*DESCRIPTION: modify only all records with the same name
*
*Paramaters: start: an array of record structures storing friends, name: the name of friend, address: the address of friend,
*            telNumber: the number of the friend 
*
*****************/
int modifyRecord(struct record *start, char uname[],char uaddr[], char utelno[])
{
    if(DEBUGMODE == 0)
    {
        printf("***DEBUG INFORMATION***\n");
        printf("Called Function: modifyRecord(struct record *, char[], char[], char[])\n");
        printf("struct record **: %x, \n", start);
        printf("char[]:name = %s \n", uname);
        printf("char[]:address = %s \n", uaddr);
        printf("char[]:telNumber = %s ", utelno);
        printf("\n***END DEBUG***\n");
    }
    int count;
    count = 0;

    return count;
}


/*****************
*
*Function name: printAllRecords
*
*DESCRIPTION: print the entire address book on the screen
*
*Paramaters: start: an array of record structures storing friends
*
*****************/
void printAllRecords(struct record *start)
{
    if(DEBUGMODE == 0)
    {
        printf("***DEBUG INFORMATION***\n");
        printf("Called Function: printAllRecords(struct record *)\n");
        printf("struct record *: %x \n", start); 
        printf("\n***END DEBUG***\n");
    }
        
    /*struct record * temp = start;*/
    printf("All records: \n\n");
    while (start != NULL)
    {
        printf("Name: %s\nAddress: %s\nBirthyear: %d\nTel Number: %s\n\n", (*start).name, (*start).address, (*start).yearofbirth, (*start).telno);
        start = (*start).next;
    }
}


/*****************
*
*Function name: deleteRecord
*
*DESCRIPTION: delete all records, including duplicates based on the name 
*
*Paramaters: start: an array of record structures storing friends, name: the name of friend 
*
*****************/
int deleteRecord(struct record **start, char uname[])
{
    if(DEBUGMODE == 0)
    {
        printf("***DEBUG INFORMATION***\n");
        printf("Called Function: deleteRecord(struct record **, char[])\n");
        printf("struct record *: %x \n", start);
        printf("char[]:name = %s \n", uname);
        printf("\n***END DEBUG***\n");
   }
   
    struct record *temp = *start;
    struct record *home = *start;
    int count = 0;

    if ((*start) ==  NULL)
    {
        printf("No items to traverse\n");
        /*return 0;*/
    }
    else
    {
        printf("There are items in the linked list\n");
        while ((*(*start)).next != NULL)
        {
            printf("traversing items...\n");
            *start = (*(*start)).next;

            printf("Comparing '%s' and '%s'\n", (*(*start)).name, uname);
            
            if (strcmp((*(*start)).name, uname) == 0)
            {
                printf("'%s' and '%s' match!\n", (*(*start)).name, uname);
                free(*start);
                (*start) = (*temp).next;
            }
            else
            {
                printf("'%s' and '%s' do not match\n", (*(*start)).name, uname);
                (*start) = (*(*start)).next;
            }
        }
        printf("(*(*start)).next is now equal to NULL");
    }

    *start = home;

    return count;
}


/*****************
*
*Function name: cleanup
*
*DESCRIPTION: destroy all of the records in the linked list and reset the start of the list to NULL
*
*Paramaters: start: an array of record structures storing friends, name: the name of the file to be written
*
*****************/
void cleanup(struct record **start)
{
    struct record **temp = NULL;
    int i = 0;
    if(DEBUGMODE == 0)
    {
        printf("***DEBUG INFORMATION***\n");
        printf("Called Function: cleanup(struct record **friend)\n");
        printf("struct record **: %x, \n", start);
    }

    printf("Clean all records: \n\n");
    while (start != NULL)
    {
        temp = (*start).next;
        /*Get the ADRESS of the next one*/
        i++;
        printf("Cleaned the linked node at position %d\n", i);
        free(start);
        start = temp;
    }  
}


/*****************
*
*Function name: readfile
*
*DESCRIPTION: reads a files contents into a program
*
*Paramaters: start: pointer to an array of record structures storing friends, filename: the name of the file to be read
*
*****************/
int readfile(struct record **records, char filename[])
{
    if(DEBUGMODE == 0)
    {
        printf("***DEBUG INFORMATION***\n");
        printf("Called Function: readfile(struct record **friend, char filename[])\n");
        printf("struct record **: %x \n", records);
        printf("char[]:filename = %s \n", filename);
        printf("\n***END DEBUG***\n");
   }    
    /*struct record ** temp = records;*/
    FILE *input;
    char *mode = "r";

    char string [100];
    char charInput;
    int i = 0;    

    input = fopen(filename, mode);

    char name [100];
    char address [100];
    int yearofbirth;
    char telno [20];

    int currVar = 0;

    if (input != NULL)
    { 
       while (charInput != EOF)
       {
            charInput = fgetc(input);
            if (charInput == '\n')
            {
                string[i] = '\0';
                if (currVar == 0)
                {
                    strcpy(name, string);
                    i = 0;
                    currVar++;
                }
                else if (currVar == 1)
                {
                    strcpy(address, string);
                    i = 0;
                    currVar++;
                }
                else if (currVar == 2)
                {
                    yearofbirth = atoi(string);
                    i = 0;
                    currVar++;
                }
                else if (currVar == 3)
                {
                    strcpy(telno, string);
                    i = 0;
                    currVar = 0;
                    addRecord(records, name, address, yearofbirth, telno);
                }
            }
            else
            {
              string[i] = charInput;  
              i++;   
            }
       } 
    }
    fclose(input);
    return 0;
}


/*****************
*
*Function name: writefile
*
*DESCRIPTION: writes content into a file
*
*Paramaters: start: an array of record structures storing friends, name: the name of the file to be written
*
*****************/
void writefile(struct record *records, char filename[])
{
    if(DEBUGMODE == 0)
    {
        printf("***DEBUG INFORMATION***\n");
        printf("Called Function: writefile(struct record *friend, char filename[])\n");
        printf("struct record *: %s \n", records);
        printf("char[]:filename = %s \n", filename);
        printf("\n***END DEBUG***\n");
   }    
   
    FILE *output;
    char *mode = "w"; 

    output = fopen(filename, mode);

    struct record *temp = records;

    if (temp ==  NULL)
    {
        printf("No linked list.\n"); 
        return;
    }
    while (temp != NULL)
    {

        fprintf(output, "%s\n", (*temp).name);
        fprintf(output, "%s\n", replaceChar((*temp).address, strlen((*temp).address), '\n', ' '));
        fprintf(output, "%d\n", (*temp).yearofbirth);
        fprintf(output, "%s\n", (*temp).telno);        
        temp = (*temp).next;

    }

    fclose(output);

}

char * replaceChar (char string[], int length, char charToBeReplaced, char replacementChar)
{
    int i;

    /*Iterate through string and replace all new lines with spaces*/
    for (i = 0; i < length; i++)
    {
        if (string[i] == charToBeReplaced)
        {
            string[i] = replacementChar;   
        }
        else if (string [i] == EOF)
        {
            string [i] = replacementChar;
        }
    }
    return string;
}
