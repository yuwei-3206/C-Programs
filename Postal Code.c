#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
 @mainpage Postal Code
 @section Description

 This program takes a 5-digit zip code as input, calculates the check digit, and generates the corresponding bar code.
*/

/**
  @file
  @author Yuwei Wu <yw829@drexel.edu>
  @date January 16, 2024
  @section DESCRIPTION

  This file contains the main program that interacts with the user and utilizes the Zip Code to Bar Code Converter functions.
*/

/**
@brief Calculate the checksum for a 5-digit zip code
@param zipCode The 5-digit zip code
@return The calculated check digit
*/
int calculateChecksum(int zipCode);

/**
@brief Generate the bar code for a given zip code
@param zipCode The 5-digit zip code
@return 0 for success and 1 for failure
*/
int generateBarCode(int zipCode);

int main() {
    //Get user input
    char zipCodeStr[6];
    int zipCode;

    //Ask user for a 5-digit zip code
    printf("Enter Zip Code:\n");
    scanf("%5s", zipCodeStr);

    //Check if the input is a valid 5-digit zip code and convert it to an integer
    if(sscanf(zipCodeStr, "%5d", &zipCode) != 1 || strlen(zipCodeStr) != 5){
        printf("Bad Zip Code\n");
        return 1;
    }

    //Generate and print the bar code
    if (generateBarCode(zipCode) == 1) {
        printf("Error\n");
        return 1;
        }

    return 0;
}

/**
@brief Calculate the check digit for a 5-digit zip code.
@param zipCode The 5-digit zip code.
@return The calculated check digit.
*/
int calculateCheckDigit(int zipCode) {
    int digit, total = 0;

    //Sum the digits of the zip code
    for (int i = 0; i < 5; ++i) {
        digit = zipCode % 10;
        total += digit;
        zipCode /= 10;
        }

    //Calculate the check digit needed to reach the next multiple of ten
    return (total % 10 == 0) ? 0 : (10 - total % 10);
}

/**
@brief Generate the bar code for a given zip code.
@param zipCode The 5-digit zip code.
@return 0 for success, 1 for failure.
*/
int generateBarCode(int zipCode) {
    int digit, checkDigit;

    // Calculate checksum
    checkDigit = calculateCheckDigit(zipCode);

    // Print starting "|"
    printf("|");

    // Print the bar code
    for (int i = 10000; i > 0; i /= 10) {
      int digit = zipCode / i;
       zipCode %= i;

      // Print bar code for the zip digit
      switch (digit) {
        case 1:
            printf("...||");
            break;
        case 2:
            printf("..|.|");
            break;
        case 3:
            printf("..||.");
            break;
        case 4:
            printf(".|..|");
            break;
        case 5:
            printf(".|.|.");
            break;
        case 6:
            printf(".||..");
            break;
        case 7:
            printf("|...|");
            break;
        case 8:
            printf("|..|.");
            break;
        case 9:
            printf("|.|..");
            break;
        case 0:
            printf("||...");
            break;
      }
    }

    // Print the bar code for the check digit
    switch (checkDigit) {
      case 1:
        printf("...||");
        break;
      case 2:
        printf("..|.|");
        break;
      case 3:
        printf("..||.");
        break;
      case 4:
        printf(".|..|");
        break;
      case 5:
        printf(".|.|.");
        break;
      case 6:
        printf(".||..");
        break;
      case 7:
        printf("|...|");
        break;
      case 8:
        printf("|..|.");
        break;
      case 9:
        printf("|.|..");
        break;
      case 0:
        printf("||...");
        break;

    }

    // Print ending "|"
    printf("|\n");

    return 0;
}
