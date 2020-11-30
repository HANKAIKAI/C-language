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
// |        source code below...                     |
// +-------------------------------------------------+

#include <stdio.h>
#include <string.h>
// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
#include "contacts.h"
#include "contactHelpers.h"
#include <ctype.h>


// getName:
void getName(struct Name* name)
{

    //char yesNo;
    int yesNo;

    printf("Please enter the contact's first name: ");
    //scanf("%30[^\n]%*c", name->firstName);
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    yesNo = yes();

    if (yesNo == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        //scanf("%6[^\n]%*c", name->middleInitial);
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    else
    {
        *name->middleInitial = '\0';
    }

    printf("Please enter the contact's last name: ");
    //scanf("%35[^\n]%*c", name->lastName);
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();


}

// getAddress:
void getAddress(struct Address* address)
{

    int yesNo;

    do
    {
        printf("Please enter the contact's street number: ");
        //scanf("%d%*c", &address->streetNumber);
        address->streetNumber = getInt();
        //clearKeyboard();

        if (address->streetNumber < 1)
        {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
            address->streetNumber = getInt();

        }

    } while (address->streetNumber < 1);

    printf("Please enter the contact's street name: ");
    //scanf("%40[^\n]%*c", address->street);
    scanf("%40[^\n]", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");
    //scanf("%c%*c", &yesNo);
    yesNo = yes();


    if (yesNo == 1)
    {
        do
        {
            printf("Please enter the contact's apartment number: ");
            //scanf("%d%*c", &address->apartmentNumber);
            //scanf("%d", &address->apartmentNumber);
            address->apartmentNumber = getInt();

            //if (address->apartmentNumber < 1 || isdigit(address->apartmentNumber))
            if (address->apartmentNumber < 1)
            {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
                address->apartmentNumber = getInt();

            }

        } while (address->apartmentNumber < 1);
    }
    else
    {
        address->apartmentNumber = '\0';
    }

    printf("Please enter the contact's postal code: ");
    //scanf("%7[^\n]%*c", address->postalCode);
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    //scanf("%40[^\n]%*c", address->city);
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    char yesNo;

    //printf("Please enter the contact's cell phone number: ");
    ////scanf("%10[^\n]", numbers->cell);
    //getTenDigitPhone(numbers->cell);
    ////clearKeyboard();

    //printf("Do you want to enter a home phone number? (y or n): ");
    //yesNo = yes();

    //if (yesNo == 1)
    //{
    //    printf("Please enter the contact's home phone number: ");
    //    //scanf("%10[^\n]", numbers->home);
    //    getTenDigitPhone(numbers->home);
    //    //clearKeyboard();
    //}
    //else
    //{
    //    numbers->home[0] = '\0';
    //}

    //printf("Do you want to enter a business phone number? (y or n): ");
    //yesNo = yes();
    //if (yesNo == 1)
    //{
    //    printf("Please enter the contact's business phone number: ");
    //    //scanf("%10[^\n]", numbers->business);
    //    getTenDigitPhone(numbers->business);
    //    //clearKeyboard();
    //}
    //else
    //{
    //    numbers->home[0] = '\0';
    //}

    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    yesNo = yes();
    if (yesNo == 1)
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
    }
    else
    {
        strcpy(numbers->home, "\0");
    }
    printf("Do you want to enter a business phone number? (y or n): ");
    yesNo = yes();
    if (yesNo == 1)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }
    else
    {
        strcpy(numbers->business, "\0");
    }

}


// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}


