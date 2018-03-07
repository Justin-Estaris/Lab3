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

//define the array to hold the puzzle
int sudokuPuzzle[9][9];

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
    printf("Sudoku solver started...\n\n");

    char *validity = "test";
    char ch;    //variable to hold single character of puzzle file
    FILE *fp;   //variable to hold the opened puzzle file

    int rowCount = 0;
    int columnCount = 0;

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
            if(ch != '\n'){
                if(ch != ' '){
                    //print the character
                    printf("%c ", ch);
                    
                    //store it in the array if its not a space
                    sudokuPuzzle[columnCount][rowCount] = ch;
                    
                    if(columnCount != 8){
                        //if not the end of the row
                        //increment the column counter
                        columnCount++;
                    }else{
                        //if end of row
                        //reset the column back to the start
                        //increment the row count
                        columnCount = 0;
                        rowCount++;
                    }
                }
            }else{
                //go to the next line
                printf("\n");
            }

            //get the next character of the file
            ch = getc(fp);
        }
        //close the file once were done
        fclose(fp);

        //give some space for following messages
        printf("\n");
    }

    //begin to verify the puzzle

    //display the result of the verify

    //exit
    return 0;
}
