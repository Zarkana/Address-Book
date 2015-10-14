struct record
{
    char             name[25];
    char             address[80];
    int              yearofbirth;
    char             telno[15];
    struct record *  next;
};
void fillArray(int, char[]);
void getField(char[]);
void readFile(struct record [], char []);
void writeFile(struct record [], char []);
int addRecord(struct record **, char [], char [], int, char []);
int printRecord(struct record *, char []);
int modifyRecord(struct record *, char [], char [], char []);
void printAllRecords(struct record *);
int deleteRecord(struct record **, char []);
void cleanup(struct record **);
char * replaceChar (char [], int, char, char);

