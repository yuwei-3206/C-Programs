#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/**
 @mainpage Numerology
 @section Description

 This program takes a string name as input, and then computes the 3 numbers based on the specified algorithm. 
 The program includes additional rules: limiting names to 50 characters and printing 0 for all values if there are no letters in the entered name.
*/

/**
  @file
  @author Yuwei Wu <yw829@drexel.edu>
  @date January 17, 2024
  @section DESCRIPTION

  This file contains the main program that interacts with the user and utilizes the string input to generates 3 numbers.
*/

void calculatesNumbers(char name[]);

int main(){
    //Declare variable for the name
    char name[51];

    //Ask user to enter their name
    printf("Enter Your Name:\n");
    scanf("%50s", name);

    //Calculate and print the numbers
    calculatesNumbers(name);

    return 0;
}

/**
 @brief Get the single digit number when the number is over 9.

 This function calculates the sum of digits until it becomes a single digit.

 @param number The calculated number from calculatesNumbers function.
 @return The single-digit result.
*/

int digSum(int number){
    int sum = 0;

    // Loop to do sum while sum is not less than or equal to 9
    while(number > 0 || sum > 9){
        if(number == 0){
            number = sum;
            sum = 0;
        }
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

/**
 @brief Check if a character is one of the 5 vowels.

 This function checks if a character is a vowel (a, e, i, o, u).

 @param ch The character to check.
 @return 0 for sucess and 1 for failure
*/
bool fiveVowel(char ch){
    //Lower all the characters for consistency
    ch = tolower(ch);
    return(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

/**
 @brief Check if 'y' is a vowel.

 This function checks if 'y' is considered a vowel based on its position in the string.

 @param str The input string.
 @return 1 for if 'y' is a vowel and 0 for not a vowel.
*/
bool checkYAsVowel(const char *str){
    int length = strlen(str);

    //Loop through all input characters
    for(int i = 0; i < length; i++){

        //Lower all the characters for consistency
        char currentChar = tolower(str[i]);

        //Check if there's a 'y' in the string
        if(currentChar == 'y'){
            //Check if 'y' is next to a vowel
              if(i + 1 < length && fiveVowel(tolower(str[i + 1]))){
                return 0;  //'y' followed by a vowel, so considered not a vowel
            }else{
              return 1;
            }
        }
    }
    return 1;  //'y' is not followed by a vowel, so considered a vowel
}

/**
 @brief Generate 3 numbers based on the user's input name and print out the results.

 This function calculates Heart's Desire, Personality Number, and Power Number and print them out as output.

 @param name The input name.
*/
void calculatesNumbers(char name[]){
    int heartsDesire = 0, personalityNumber = 0, powerNumber = 0;

    //Make constrain of a name with no more than 50 characters
    for(int i = 0; name[i] != '\0' && i < 50; i++){

        //Lower all the characters for consistency
        char c = tolower(name[i]);
        int value;

        //Set values for the letters
        switch(c){
            case 'a': case 'j': case 's':
                value = 1;
                break;
            case 'b': case 'k': case 't':
                value = 2;
                break;
            case 'c': case 'l': case 'u':
                value = 3;
                break;
            case 'd': case 'm': case 'v':
                value = 4;
                break;
            case 'e': case 'n': case 'w':
                value = 5;
                break;
            case 'f': case 'o': case 'x':
                value = 6;
                break;
            case 'g': case 'p': case 'y':
                value = 7;
                break;
            case 'h': case 'q': case 'z':
                value = 8;
                break;
            case 'i': case 'r':
                value = 9;
                break;

            //Set Unknown character as default and values 0
            default:
                value = 0; 
                break;
      }

      //Get the 3 numbers based on the user's input
      //If 'y' consideres as a vowel, count in the hearts desire
      if(checkYAsVowel(&name[i]) == 1){
          if(fiveVowel(c) || c == 'y'){
            heartsDesire += value;
          }else{
            personalityNumber += value;
          }

        //If 'y' is not a vowel, count in the personality number 
      }else if(checkYAsVowel(&name[i]) == 0){
        if(fiveVowel(c)){
          heartsDesire += value;
        }else{
          personalityNumber += value;
        }
      }

      //Counts all characters in power number
      powerNumber += value;
    }

    //Print all numbers out and their names
    printf("Heart's Desire Number: %d\n", digSum(heartsDesire));
    printf("Personality Number: %d\n", digSum(personalityNumber));
    printf("Power Number: %d\n", digSum(powerNumber));
  }
