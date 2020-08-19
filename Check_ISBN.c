/*
  RMIT University Vietnam
  Course: EEET2448 Comp Eng/EEET2601 Eng Comp 1
  Semester: 2019C
  Assessment: Assessment 1
  Author: NGUYEN NGOC TRAM
  ID: 3789355
  Created  date: dd/mm/yyyy (e.g. 12/11/2019)
  Last modified: dd/mm/yyyy (e.g. 19/11/2019)
  Acknowledgement: If you use any resources, acknowledge here. Failure to do so will be considered as plagiarism.
*/

//input the libraries
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

//declare variables
  char isbn[17];
  bool isInvalid = true;
  bool isChar = true;
  int strln = 0;
  int count = 0;

  //star the while loop
  while(isInvalid)
    {
      int count_digits = 0;
      int count_hyphens = 0;

      //let the string has no characters in it
      isbn[0] = '\0';
      isChar = true;

      // let the user input isbn
      printf("Enter an ISBN: ");
      gets(isbn);

      //declare a variable which is called strln to represent the length of the string
      strln = strlen(isbn);

      //create if loop
      //if the string has only one digit and it is number 0, the program ends
      if((strlen(isbn) == 1) && (isbn[0] == '0'))
      {
        isInvalid=false;
        printf("Program exits. Goodbye!!!\n");
        break;
      }
      else
      {
        //create for loop
          for(int i = 0; i < strln; i++)
          {
            //if the digits in string isbn are the numbers from 0 to 9, digits and hyphens start counting from 0
            if(isbn[i] >= '0' && isbn[i] <= '9' )
              {
                  count_digits++;
              }
            else if(isbn[i] == '-')
              {
                  count_hyphens++;
              }
            else
            {
              isChar = false;
              break;
            }
          }
          //check if the string does not have have digits and hyphens
          //if the string isbn does not have numbers and hyphens, which is opposite to the condition in the if loop, the string is invalid isbn
          if(!isChar)
            {
              printf("Invalid ISBN. ISBN only contains digits and hyphens.\n");
              continue;
            }
          }
          //check if the string has more or less than 13 digits
          if(count_digits > 13)
          {
            printf("Invalid ISBN. More than 13 digits. \n");
            continue;
          }
          if (count_digits < 13)
          {
            printf("Invalid ISBN. Less than 13 digits.\n");
            continue;
          }
          //check if the fourth index in the string is not the hyphen
          if(count_hyphens != 4)
          {
            printf("Invalid ISBN. Input should have 5 elements separated by hyphens. \n");
            continue;
          }
          //check if the three first numbers are not 978 or 979
          if((isbn[0] == '9') && (isbn[1] == '7') && ((isbn[2]== '8') || (isbn[2] == '9')))
          {
            int sum =  0;
            int j = 0;
            int array_digit[12];
            //create a for loop
            for(int i =0; i<=strln;i++)
            {
              //if the digits in the string is from 0 to 9
              if(isbn[i] >= '0' && isbn[i] <= '9')
              {
                //if the orders of the string are divided by 2 and no remainders are left, sum all the digits of those orders
                  if(j % 2 == 0)
                  {
                    sum += (int)(isbn[i] ) ;
                  }
                  else
                  //if the order of the string are divided by 2 and there are remainders left, sum all the digits of those oders then multiple it with 3
                  {
                     sum += 3 * ((int)(isbn[i] ));
                  }
                  j++;
              }
            }
            //if sum is divided by 10 and no remainders are left, it is the valid isbn
            if(sum %10 == 0)
            {
              printf("Valid ISBN.\n");
              continue;
            }
            //if sum is divided by 10 and there are remainders, it is in valid isbn
            else
            {
              printf("Invalid ISBN. Failed validation test\n");
              continue;

            }
          }
          else
          {
            //if the conditons in if loop does not happen, the three first numbers are wrong
            printf("Invalid ISBN. Prefix element must be either 978 or 979. \n");
            continue;
          }


          //declare a variable for the sencond hyphen
          int second_hyphen=0;
          for (int i=4; i< strln; i++){
            //find the order of second hyphen in the string
            if(isbn[i] == '-'){
              second_hyphen = i;

            }
          }
          //check if registration group element must have 1 to 5 digits
          if( ( (second_hyphen - 4) > 5) || ( (second_hyphen - 4) < 1)){
            printf("Invalid ISBN. Registration group element must have 1 to 5 digits\n");

          }

          else{
            //declare a variable for the third hyphen
          int third_hyphen=0;
          for (int i= second_hyphen +1; i< strln; i++){
            //find the order of third hyphen in the string
            if (isbn[i] == '-'){
              third_hyphen = i;

            }
            }
            //check if registrant element must have 1 to 7 digits.
            if ( ((third_hyphen - second_hyphen -1) >7) || ((third_hyphen - second_hyphen -1) <1) ){
              printf("Invalid ISBN. Registrant element must have 1 to 7 digits\n" );

          }
          else {
        }
          //declare a variable for the fourth hyphen
          int fourth_hyphen=0;
          for (int i = third_hyphen+1; i < strln; i++ ){
            //find the order of fourth hyphen in the string
            if(isbn[i] == '-'){
              fourth_hyphen = i;

            }
          }
          // check if publication element must have 1 to 6 digits.
          if( ((fourth_hyphen- third_hyphen -1 ) >6) || ((fourth_hyphen - third_hyphen -1) <1 )){
            printf("Invalid ISBN. Publication element must have 1 to 6 digits\n");
          }
        }

        //check if the last group has exactly 1 digit.
          if( isbn[16] >= '1' && isbn[16] <= '9' && isbn[15] == '-'){

            true;
          }
          //check the last digit for the string

          else{
            printf("Invalid ISBN. Check digit must have exactly 1 digit\n");
          }

      }

  return 0;
}
