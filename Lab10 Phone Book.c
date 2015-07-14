/* 
 * File:   Lab10.c
 * Author: yiransunjunyi
 *
 * Created on November 24, 2014, 1:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
//**********************************************************************
// Support Function Declarations
//

void safegets(char s[], int arraySize); // gets without buffer overflow
void familyNameDuplicate(char familyName[]); // marker/tester friendly 
void familyNameFound(char familyName[]); //   functions to print
void familyNameNotFound(char familyName[]); //     messages to user
void familyNameDeleted(char familyName[]);
void phoneNumberFound(char phoneNumber[]);
void phoneNumberNotFound(char phoneNumber[]);
void printPhoneBookEmpty(void);
void printPhoneBookTitle(void);

//**********************************************************************
// Program-wide Constants
//

const int MAX_LENGTH = 1023;
const char NULL_CHAR = '\0';
const char NEWLINE = '\n';
//**********************************************************************
// Linked List Definitions 
//  Define your linked list node and pointer types
//  here for use throughout the file.

typedef struct book {
    char familyName[50];
    char firstName[50];
    char address[50];
    char phoneNumber[50];
    struct book *link;
} Book;

Book *listHead = NULL;
//**********************************************************************
// Support Function Definitions

// Function to get a line of input without overflowing target char array.

void safegets(char s[], int arraySize) {
    int i = 0, maxIndex = arraySize - 1;
    char c;
    while (i < maxIndex && (c = getchar()) != NEWLINE) {
        s[i] = c;
        i = i + 1;
    }
    s[i] = NULL_CHAR;
}

// Function to call when user is trying to insert a family name 
// that is already in the book.

void familyNameDuplicate(char familyName[]) {
    printf("\nAn entry for <%s> is already in the phone book!\n"
            "New entry not entered.\n", familyName);
}

// Function to call when a family name was found in the phone book.

void familyNameFound(char familyName[]) {
    printf("\nThe family name <%s> was found in the phone book.\n",
            familyName);
}

// Function to call when a family name was not found in the phone book.

void familyNameNotFound(char familyName[]) {
    printf("\nThe family name <%s> is not in the phone book.\n",
            familyName);
}

// Function to call when a family name that is to be deleted
// was found in the phone book.

void familyNameDeleted(char familyName[]) {
    printf("\nDeleting entry for family name <%s> from the phone book.\n",
            familyName);
}

// Function to call when a phone number was found in the phone book.

void phoneNumberFound(char phoneNumber[]) {
    printf("\nThe phone number <%s> was found in the phone book.\n",
            phoneNumber);
}

// Function to call when a phone number was not found in the phone book.

void phoneNumberNotFound(char phoneNumber[]) {
    printf("\nThe phone number <%s> is not in the phone book.\n",
            phoneNumber);
}

// Function to call when printing an empty phone book.

void printPhoneBookEmpty(void) {
    printf("\nThe phone book is empty.\n");
}

// Function to call to print title when whole phone book being printed.

void printPhoneBookTitle(void) {
    printf("\n  My Personal Phone Book: \n\n");
}

//**********************************************************************
// Add your functions below this line.

Book *createNewNode() {
    Book *newNode = (Book *) malloc(sizeof (Book));
    if (newNode == NULL)
        printf("Out of Memory\n");
    else {
        printf("  family name: ");
        safegets(newNode->familyName, 50);
        printf("  first name: ");
        safegets(newNode->firstName, 50);
        printf("  address: ");
        safegets(newNode->address, 50);
        printf("  phone number: ");
        safegets(newNode->phoneNumber, 50);
    }
    return newNode;
}

Book *insertNode(Book *listHead) {
    Book *insertItem = createNewNode();
    Book *temp = listHead;
    bool duplicate = false;
    Book *current = listHead;
    Book *previous = NULL;
    bool located = false;
    if (listHead == NULL) {
        insertItem->link = listHead;
        listHead = insertItem;
    } else {
        for (; temp != NULL && duplicate == false; temp = temp->link)
            if ((strcmp(temp->familyName, insertItem->familyName) == 0)) {
                familyNameDuplicate(insertItem->familyName);
                duplicate = true;
                return listHead;
            }
        while (duplicate == false && located == false && current != NULL) {
            if (strcmp(current->familyName, insertItem->familyName) > 0)
                located = true;
            else {
                previous = current;
                current = current->link;
            }
        }

        if (current == listHead)
            listHead = insertItem; //where is the listHead then?
        else
            previous->link = insertItem;
        insertItem->link = current;
    }
    return listHead;
}

Book *deleteNode(Book *listHead, char familyName[]) {
    Book *current = listHead;
    Book *previous = NULL;
    bool found = false;
    while (current != NULL && found == false) {
        if (strcmp(current->familyName, familyName) == 0)
            found = true;
        else {
            previous = current;
            current = current->link;
        }
    }
    if (found == true) {
        familyNameDeleted(familyName);
        if (current == listHead)
            listHead = listHead->link;
        else
            previous->link = current->link;
        //free(current);
    } else
        familyNameNotFound(familyName);
    return listHead;
}

void print(Book *listHead) {
    Book *temp = listHead;
    if (temp == NULL)
        printPhoneBookEmpty();
    else {
        printf("%s\n", temp->familyName);
        printf("%s\n", temp->firstName);
        printf("%s\n", temp->address);
        printf("%s\n", temp->phoneNumber);
    }
}

void printAll(Book *listHead) {
    Book *temp = listHead;
    if (temp == NULL) {
        printPhoneBookEmpty();
        return;
    }
    printPhoneBookTitle();
    for (; temp != NULL; temp = temp->link) {
        printf("%s\n", temp->familyName);
        printf("%s\n", temp->firstName);
        printf("%s\n", temp->address);
        printf("%s\n", temp->phoneNumber);
        printf("\n");
    }
}

void searchFamilyName(Book *listHead, char familyName[]) {
    Book *temp;
    Book *result;
    bool found = false;
    for (temp = listHead; temp != NULL && found == false; temp = temp->link) {
        if (strcmp(temp->familyName, familyName) == 0){
            found = true;
            result=temp;
        }
    }
    if (found == true) {
        familyNameFound(familyName);
        print(result);
    } else
        familyNameNotFound(familyName);
}

void searchPhoneNumber(Book *listHead, char phoneNumber[]) {
    Book *temp;
    Book *result;
    bool found = false;
    for (temp = listHead; temp != NULL && found == false; temp = temp->link) {
        if (strcmp(temp->phoneNumber, phoneNumber) == 0){
            found = true;
            result=temp;
        }
    }
    if (found == true) {
        phoneNumberFound(phoneNumber);
        print(result);
    } else
        phoneNumberNotFound(phoneNumber);
}

Book *deleteAll(Book *listHead) {
    Book *temp= (Book *) malloc(sizeof (Book));
    for (temp = listHead; temp != NULL; temp = temp->link) //temp or head?
        free(temp);
    return NULL; //must return NULL?  
}
//**********************************************************************
// Main Program

int main(void) {
    const char bannerString[]
            = "Personal Phone Book Maintenance Program.\n\n";
    const char commandList[]
            = "Commands are I (insert), D (delete), S (search by name),\n"
            "  R (reverse search by phone #), P (print), Q (quit).\n";

    // Declare linked list head.


    // announce start of program
    printf("%s", bannerString);
    printf("%s", commandList);

    char response;
    char input[MAX_LENGTH + 1];
    do {
        printf("\nCommand?: ");
        safegets(input, MAX_LENGTH + 1);
        // Response is first char entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if (response == 'I') {
            // Insert an phone book entry into the linked list. Maintain the list in alphabetical order by family name. 
            listHead = insertNode(listHead);

        } else if (response == 'D') {
            // Delete an phone book entry from the list.
            char familyNameD[50];
            printf("\nEnter family name for entry to delete: ");
            safegets(familyNameD, 50);
            listHead = deleteNode(listHead, familyNameD);


        } else if (response == 'S') {
            // Search for an phone book entry by family name.
            char familyName[50];
            printf("\nEnter family name to search for: ");
            safegets(familyName, 50);
            searchFamilyName(listHead, familyName);



        } else if (response == 'R') {
            // Search for an phone book entry by phone number.
            char phoneNumber[50];
            printf("\nEnter phone number to search for: ");
            safegets(phoneNumber, 50);
            searchPhoneNumber(listHead, phoneNumber);


        } else if (response == 'P') {
            // Print the phone book.
            printAll(listHead);

        } else if (response == 'Q') {
            ; // do nothing, we'll catch this below
        } else {
            // do this if no command matched ...
            printf("\nInvalid command.\n%s\n", commandList);
        }
    } while (response != 'Q');

    // Delete the whole phone book linked list.
    listHead=deleteAll(listHead);
    // Print the linked list to confirm deletion.
    print(listHead);

    return 0;
}




