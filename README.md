# Color Validater
#### Video Demo:  <https://youtu.be/wZSrUutOZ_o>
#### Description:
TODO
My name's Asal Etaati and This is my Final Project
Color verification for front enders or learners who wanna know more about color codings
This Command Line Argument program is just made for CS50X-Harvard final project, not other aim!
This is a command line argument by using c, it's a Color verification
How to use it: run ./final color_type
KEYS:
1: validating a HEX code
2: validating a rgb code
3: validating a color name (in English)
This Command Line Argument consists of 3 functions:
1: HEX
2: RGB
3: EN_WORD
At first we have to check for every possible mistakes that users can do in data entry
For example If a user did'nt enter exactly 2 args, the program must return 1
Or even if user enters 23 it will return 1, just when user enters a single char it can pass
or if the char is'nt a digit return 1
Only 1,2,3 are possoble to pass
Then I wrote 3 Fuc
FUNCTION 1 IS BASED ON THESE FACTS:
bool HEX:
SOME SITUATIONS IN A HEX CODE, (To be sure this is a HEX code):
1- A HEX code includes exactly 6 chars
2- A HEX code can just consists of numbers or alphabetes
3 - NUMBERS IN A HEX CODE are:
1 2 3 4 5 6 7 8 9 A B C D E F,
SO WE CAN'T HAVE AN ALPHABETE GREATER THAN F
FUNCTION 2 IS BASED ON THESE FACTS:
a RGB code includes 3 elements (RED, GREEN, BLUE)
We can't have more than 255 amounts of each of them!
FUNCTION 3 IS BASED ON THESE FACTS:
if the input is some words like Black or Blue
I created a FILE that includes a list of color names
Be careful I have'nt written all the colors those are exist in the world!
only the syntex and the code were matter
so this does'nt handel an eccentric color name! :)
This function searches the color that's given by you
If it exists in the file, it will return true and tell you that is an English color name!
If it does'nt exist in the file, it will return false and tell you that is'nt an English color name
Also the convention of writing colors in English is to write the first letters in capital letters and the rest in small letters. 
For example, green is wrong and Green is right.
Therefore, if you write it wrong, the function will automatically return false. 
Also, compound names such as GreenBlue must be written this way, and this is a convention.
You can add more colors:
You can refer to https://www.w3schools.com/colors/colors_names.asp
to see the color names but if you want to add new colors please change 
the line 167 to the total color names those are in colors.txt
Also please read the comments in my code