//==============================================
// Name:           Yuankai Han
// Student Number: 154477194
// Email:          yhan77@myseneca.ca
// Section:        NOO
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

#include <stdio.h>
#include "contactHelpers.h"
#include <string.h>
#include <ctype.h>
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}


// getInt: Empty function definition goes here:
int getInt(void)
{
    char newline = 'x';
    int value;
    scanf("%d%c", &value, &newline);
    while (newline != '\n')
    {
        clearKeyboard();
        printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        scanf("%d%c", &value, &newline);
    }
    return value;
}


// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
    int integer;
    integer = getInt();
    while ((integer < min) || (integer > max))
    {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        integer = getInt();
    }
    return integer;

}


// yes: Empty function definition goes here:
int yes(void)
{
    char ch;
    char newline;
    int result;

    scanf("%c%c", &ch, &newline);
    while ((ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n') || (newline != '\n'))
    {
        clearKeyboard();
        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        scanf("%c%c", &ch, &newline);
    }
    if ((ch == 'Y') || (ch == 'y'))
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}


// menu: Empty function definition goes here:
int menu(void)
{
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Select an option:> ");

    return getIntInRange(0, 6);

}


// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
    struct Contact contacts[MAXCONTACTS] =
    { { { "Rick", {'\0'}, "Grimes" },
        { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
        { "4161112222", "4162223333", "4163334444" } },
      {
        { "Maggie", "R.", "Greene" },
        { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
        { "9051112222", "9052223333", "9053334444" } },
      {
        { "Morgan", "A.", "Jones" },
        { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
        { "7051112222", "7052223333", "7053334444" } },
      {
        { "Sasha", {'\0'}, "Williams" },
        { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
        { "9052223333", "9052223333", "9054445555" } },
    };

    int option;
    int done = 0;
    while (!done) {
        option = menu();
        printf("\n");
        switch (option) {
        case 1:
            displayContacts(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 2:
            addContact(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 3:
            updateContact(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 4:
            deleteContact(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 5:
            searchContacts(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        case 6:
            sortContacts(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;
        default:
            printf("Exit the program? (Y)es/(N)o: ");
            if (yes() == 1) {
                printf("\nContact Management System: terminated");
                done = 1;
            }
            printf("\n");
        }
    }

    /*int iSelection;
    int done = 0;
    while (!done)
    {
        iSelection = menu();
        printf("\n");
        switch (iSelection)
        {
        case 1:
            printf("<<< Feature 1 is unavailable >>>\n");
            printf("\n");
            pause();
            printf("\n");
            break;
        case 2:
            printf("<<< Feature 2 is unavailable >>>\n");
            printf("\n");
            pause();
            printf("\n");
            break;
        case 3:
            printf("<<< Feature 3 is unavailable >>>\n");
            printf("\n");
            pause();
            printf("\n");
            break;
        case 4:
            printf("<<< Feature 4 is unavailable >>>\n");
            printf("\n");
            pause();
            printf("\n");
            break;
        case 5:
            printf("<<< Feature 5 is unavailable >>>\n");
            printf("\n");
            pause();
            printf("\n");
            break;
        case 6:
            printf("<<< Feature 6 is unavailable >>>\n");
            printf("\n");
            pause();
            printf("\n");
            break;
        default:
            printf("Exit the program? (Y)es/(N)o: ");
            if (yes() == 1)
            {
                printf("\nContact Management System: terminated");
                done = 1;
            }
            printf("\n");
            break;
        }
    }*/


}

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+­n

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;

    while (needInput == 1)
    {
        scanf("%10s", phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10 && (strspn(phoneNum, "0123456789") == strlen(phoneNum)))
        {
            needInput = 0;
        }
        else
        {
            printf("Enter a 10-digit phone number: ");
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{

    int i;
    for (i = 0; i < size; ++i)
    {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
        {
            return i;
        }
    }

    return -1;

}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{
    if (strcmp(contact->name.middleInitial, "") == 0)
    {
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
    }
    else
    {
        printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    }
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if (contact->address.apartmentNumber > 0)
    {
        printf("Apt# %d, ", contact->address.apartmentNumber);
    }
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);


}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{

    int i;
    int count = 0;

    displayContactHeader();
    for (i = 0; i < size; i++) {
        if (strlen(contacts[i].name.firstName) != 0)
        {
            displayContact(&contacts[i]);
            count++;
        }
    }
    displayContactFooter(count);
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
    char celNum[11];
    int i = 0;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(celNum);

    i = findContactIndex(contacts, size, celNum);

    if (i != -1)
    {
        printf("\n");
        displayContact(&contacts[i]);
        printf("\n");
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n");
    }
}


// addContact:
// Put empty function definition below:
void addContact(const struct Contact contacts[], int size)
{
    int i;
    int available = -1;

    for (i = 0; i < size; i++)
    {
        if (strlen(contacts[i].numbers.cell) == 0)
        {
            available = i;
        }
    }
    if (available > -1)
    {
        getContact(&contacts[available]);
        printf("--- New contact added! ---\n\n");

    }
    else
    {
        printf("*** ERROR: The contact list is full! ***\n\n");

    }

}



// updateContact:
// Put empty function definition below:
void updateContact(const struct Contact contacts[], int size)
{

    char update_nums[11] = { '\0' };
    int update;


    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(update_nums);
    update = findContactIndex(contacts, size, update_nums);

    if (update != -1)
    {
        printf("\nContact found:\n");
        displayContact(&contacts[update]);
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        if (yes() == 1)
        {
            getName(&contacts[update].name);
        }

        printf("Do you want to update the address? (y or n): ");
        if (yes() == 1)
        {
            getAddress(&contacts[update].address);
        }

        printf("Do you want to update the numbers? (y or n): ");
        if (yes() == 1)
        {
            getNumbers(&contacts[update].numbers);
        }

        printf("--- Contact Updated! ---\n\n");
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n\n");
    }

}

// deleteContact:
// Put empty function definition below:
void deleteContact(const struct Contact contacts[], int size)
{
    /*struct Contact temp = {'\0'};
    char phoneNumber[11];
    int index;

    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(phoneNumber);
    index = findContactIndex(contacts, size, phoneNumber);
    if (index != -1)
    {
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");

        if (yes() == 1)
        {
            contacts[index].numbers = temp;

            printf("--- Contact deleted! ---\n");
        }
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n");
    }*/

    char phoneNum[11] = { 0 };
    int index = 0;
    int i = 0;

    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    index = findContactIndex(contacts, size, phoneNum);

    if (yes() == -1)
    {
        printf("*** Contact NOT FOUND ***\n");
    }
    else
    {
        for (index = i + 1; contacts[index].numbers; index++)
        {
            contacts[index].numbers = contacts[index + 1].numbers;

        }
        contacts[index].numbers--;
        printf("--- Contact deleted! ---\n");
    }
}


// sortContacts:
// Put empty function definition below:
void sortContacts(const struct Contact contacts[], int size)
{
    printf("<<< Feature to sort is unavailable >>>\n");
}



