/*
 * Sudoku Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, Ryan Goulding, Francis Hackenberger, Ryan Schuette, Justin Estaris
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sudoku.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256  

//TODO:
//A thread to check that each column contains the digits 1 through 9
//A thread to check that each row contains the digits 1 through 9
//Nine threads to check that each of the 3 × 3 subgrids contains the digits 1 through 9
//this would result in eleven seperate threads for validating a sudoku puzzle

int main()
{
    //clear the screen
    system("clear");
    //tell the user the solver has started
    printf("Sudoku solver started...\n");

    char ch;    //variable to hold single character of puzzle file
    FILE *fp;   //variable to hold the opened puzzle file

    if ((fp = fopen("puzzle.txt", "r")) == NULL){
        //display error message
        fprintf(stderr, "ERROR OPENING PUZZLE FILE\n");

        //program exits with an error
        return 1;     
    }else{
        //get the first character of the file
        ch = getc(fp);
        //print puzzle contents until there's nothing left
        while(ch != EOF){
            //if the characters not a new line character
            //TODO: store sudoku puzzle in local variable
            if(ch != "\n"){
                //print the character
                printf("%c",ch);
            }else{
                //go to the next line
                printf("\n");
            }

            //get the next character of the file
            ch = getc(fp);
        }
        //close the file once were done
        fclose(fp);
    }

    //begin solving the puzzle

    //display the solved puzzle

    //save the solved puzzle to a seperate file with the same name plus "_solved"

    //exit
    return 0;
}
