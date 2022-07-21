/*
Asal Etaati, CS50X-Harvard Final Project
Color verification for front enders or learners who wanna know more about color codings
This Command Line Argument program is *just* made for CS50X-Harvard final project, not other aim!
This is a command line argument by using c, it's a Color verification
How to use it: run ./final color_type

KEYS:
1: validating a HEX code
2: validating a rgb code
3: validating a color name (in English)
*/

// libraries 
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>


// Function declaration
bool HEX();
bool RGB();
bool EN_WORD();




// COMMAND LINE ARGUMENT 
int main(int argc, string argv[])
{
    //Checking for every possible mistakes that users can do in data entry

    if (argc != 2) // If a user did'nt enter exactly 2 args, return 1
    {
        printf("./usage color_type\n(: Please enter exactly 2 args :)\n");
        return 1;
    }
    string s = argv[1];
    if (strlen(s) != 1) //for example even if user enters 23 it will return 1, just when user enters a single char it can pass
    {
        printf("The number that you enter must be 1 or 2 or 3\n 1-HEX CODE (like #FFFFFF) 2-rgb like rgb(255, 255, 255) 3-English name(like White) - \n");
        return 1;
    }

    if (!isdigit(s[0])) // now an other filter. if the char is'nt a digit return 1
    {
        printf("It must be an int\n");
        return 1;
    }

    int n = atoi(&s[0]); // converting argv[1] to an int
    if (n > 3 || n < 1) // check if it is 1 or 2 or 3 or not
    {
        printf("It could be 1 or 2 or 3\n");
        return 1;
    }
    //ending to check for every possible mistake that users can do in data entry




    if (atoi(&s[0]) == 1) // If user chose to verify a HEX code then implement this function
    {
        HEX();

    }
    else if (atoi(&s[0]) == 2) // If user chose to verify a rgb code then implement this function
    {
        RGB();
    }
    else // If user chose to verify a color name in En then implement this function
    {
        EN_WORD();
    }

    return 0;
}





// FUNCTIONS:


/*
bool HEX:

SOME SITUATIONS IN A HEX CODE, (To be sure this is a HEX code):

1- A HEX code includes exactly 6 chars

2- A HEX code can just consists of numbers or alphabetes

3 - NUMBERS IN A HEX CODE are:

1 2 3 4 5 6 7 8 9 A B C D E F,
SO WE CAN'T HAVE AN ALPHABETE GREATER THAN F
*/
bool HEX(void)
{
    string  x = get_string("Wanna verify a HEX code? Then enter your HEX code:\n #");
    for (int i = 0; i < strlen(x); i++)
    {
        if (strlen(x) != 6 || (!isalpha(x[i]) && !isdigit(x[i])) || (isalpha(x[i]) 
                && (toupper(x[i]) > 
                    'F'))) // A HEX code just can sonsists of alphabetes and digits also it includes exactly 6 charachters also if the char is an alphabete it can't be greater then f
        {
            printf("Sorry this is'nt a HEX code! :(\n");
            return false;
        }
    }
    printf("Yep! This is a HEX code :)\n");
    return true;
}


/*
a RGB code includes 3 elements (RED, GREEN, BLUE)
We can't have more than 255 amounts of each of them!
*/
bool RGB(void)
{
    printf("Wanna verify a rgb? Then enter your rgb code:) (Red, Green, Blue)\n");
    for (int i = 0; i < 3; i++)
    {
        string color[] = {"Red", "Green", "Blue"}; // A list of RGB colors
        unsigned int x = get_int("The %dth element of a RGB code (specify the amount of %s you wanna have):\n", i + 1, color[i]);
        if (x > 255)
        {
            printf("Sorry this is'nt a RGB :(\n");
            return false;
        }
    }
    printf("Yep! This is a RGB :)\n");
    return true;
}

/*
if the input is some words like Black or Blue
I created a FILE that includes a list of color names
Be careful I have'nt written all the colors those are exist in the world!
only the syntex and the code were matter
so this does'nt handel an eccentric color name! :)

This function searches the color that's given by you
If it exists in the file, it will return true and tell you that is an English color name!
If it does'nt exist in the file, it will return false and tell you that is'nt an English color name!
*/
bool EN_WORD(void)
{

    printf("Wanna varify an English color name? Then enter your considered color name: ");
    FILE *file = fopen("colors.txt", "r"); // open the file
    if (file == NULL) // If the file does not exist print this massage, close the file and return false
    {
        printf("The txt file is not found!\n");
        fclose(file);
        return false;
    }
    
    //!
    int buffer = 255; // the longest En word in the world has 255 chars
    char color[19]; // because there are 19 color names in my txt file
    scanf("%s", color); // asking for an input to start searching in the file
    char line[buffer];
    
    /*
    
    We give this variable the initial value of 1. Later, we will say that if the color name
    is found in the file, change this variable to 0. Therefore, after the While loop, 
    if the value of this variable is still 1, it means that this color name 
    is not found in the file.
    (Also, if the value of the variable has changed to 0, it means that it has been found in the file)
    
    */
    int  found_the_color_name = 1; 
    while (fgets(line, buffer, file)) 
    // search for the given name in the file
    {
        char *t = strstr(line, color);
        if (t != NULL) // if it's found:
        {
            found_the_color_name = 0;
            printf("This is an English color name! :)\n"); // if the color name is found in the file return true and print this massage
            fclose(file); //close the file
            break; // and break the while loop
            return true;
           
        }
    }
    if (found_the_color_name != 0) 
    {

        printf("sorry This is'nt an English color name! :(\n"); // But if the color name is'nt found in the file, print this massage,  close the file and return false
        fclose(file);
        return false;
    }
    //!
    /*
    !!!
    The only part of my code that I got help from a source, but I wrote it myself according to the 
    variables and conditions of my problem, but according to the copyright law, I have to name the source. so:
    https://www.efaculty.in/c-programs/check-whether-a-given-word-exists-in-a-file-or-not-program-in-c/
    !!!
    */
    return true;
}


/* You can refer to https://www.w3schools.com/colors/colors_names.asp
to see the color names but if you want to add new colors please change 
the line 167 to the total color names those are in colors.txt
The convention of writing colors in English is to write the first letters in capital letters and the rest in small letters. 
For example, green is wrong and Green is right.
Therefore, if you write it wrong, the function will automatically return false. 
Also, compound names such as GreenBlue must be written this way, and this is a convention.
*/
// This is cs50 and this is my final project
