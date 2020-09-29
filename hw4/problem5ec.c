#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NAME_SIZE 20 // size of names 
#define LIST 50 // size of arrays

typedef struct // struct for records in newmast.dat
{
    unsigned int accountNum;
    char firstName[NAME_SIZE];
    char lastName[NAME_SIZE];
    double balance;
} Record;

typedef struct // struct for transaction in trans.dat
{
    unsigned int accountNum;
    double amount;
} Transaction;


// problem5 is the same as this problem due to the implementation
void hw4p5ec(void)
{
    FILE* oldfPtr; // file pointer for oldmast.dat

    if ((oldfPtr = fopen("oldmast.dat", "r")) == NULL) // open oldmast.dat for reading
        puts("Could not open 'oldmast.dat'."); // if can't open, prints error message and skips the rest of the code
    else
    {
        Record oldmastRec[LIST]; // holds all oldmast.dat records
        unsigned int oldmastCount = 0; // track number of records in the record list

        Record oldRecord = { 0, "", "", 0.0 }; // create record to store new values

        fscanf(oldfPtr, "%u %s %s %lf", &oldRecord.accountNum, oldRecord.firstName, oldRecord.lastName, &oldRecord.balance); // scan in line
        while (!feof(oldfPtr)) // if not at end of file
        {
            oldmastRec[oldmastCount] = oldRecord; // add entry to list of entries
            oldmastCount++; // increment counter
            fscanf(oldfPtr, "%u %s %s %lf", &oldRecord.accountNum, oldRecord.firstName, oldRecord.lastName, &oldRecord.balance); // scan in next line
        }

        fclose(oldfPtr); // done with oldmast.dat, so close the file pointer

        // follow same approach as oldmast.dat record handling for trans.dat transactions
        FILE* transfPtr; // file pointer for trans.dat

        if ((transfPtr = fopen("trans.dat", "r")) == NULL) // open trans.dat for reading
            puts("Could not open 'trans.dat'."); // if can't open, prints error skips the rest of the code
        else
        {
            Transaction transactions[LIST]; // list of transaction
            unsigned int transCount = 0; // counter for number of transactions in transaction list

            Transaction transaction = { 0, 0.0 }; // transaction to store new values

            // same as oldmast.dat record handling; keep scanning and adding transactions to list
            fscanf(transfPtr, "%u %lf", &transaction.accountNum, &transaction.amount);
            while (!feof(transfPtr))
            {
                transactions[transCount] = transaction;
                transCount++;
                fscanf(transfPtr, "%u %lf", &transaction.accountNum, &transaction.amount);
            }

            fclose(transfPtr); // done with trans.dat

            for (int i = 0; i < transCount; i++) // loop through all transactions
            {
                bool match = false; // bool for if the transaction has found a match
                for (int j = 0; j < oldmastCount; j++) // loop through all oldmast.dat records
                    if (transactions[i].accountNum == oldmastRec[j].accountNum) // if the account numbers match
                    {
                        match = true; // set match to true
                        oldmastRec[j].balance += transactions[i].amount; // set new balance as old balance plus new value from transaction
                    }

                if (!match) // if no account number match, print message
                    printf("Unmatched transaction record for account number %d\n", transactions[i].accountNum);
            }

            FILE* newfPtr; // file pointer for newmast.dat

            if ((newfPtr = fopen("newmast.dat", "w")) == NULL) // open newmast.dat for overwriting
                puts("Could not open/create 'newmast.dat'."); // if could not open or create, prints error message and skips rests of the code
            else
            {
                for (int i = 0; i < oldmastCount; i++) // loop through newly updated list of oldmast.dat records
                    // print each new record into newmast.dat with originally given formatting
                    fprintf(newfPtr, "%-5u%s %s  %.2lf\n", oldmastRec[i].accountNum, oldmastRec[i].firstName, oldmastRec[i].lastName, oldmastRec[i].balance);

                fclose(newfPtr); // done with newmast.dat
            }

            // prints confirmation message if the code runs all the way to the end
            printf("\n%s\n", "Master record updated. Check 'newmast.dat' for current records.");
        }
    }

    /*
        no sample cases
    */
}

int main(void)
{
    hw4p5ec();
    return 0;
}