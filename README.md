 Color Validator
#### Video Demo:  <https://youtu.be/wZSrUutOZ_o>
#### Description:
TODO
My name's Asal Etaati and This is my Final Project
Color verification for front enders or learners who wanna know more about color codings
This Command Line Argument program is just made for the CS50X-Harvard final project, not another aim!
This is a command line argument by using c, it's a Color verification
How to use it: run ./final color_type
KEYS:
1: validating a HEX code
2: validating an RGB code
3: validating a color name (in English)
This Command Line Argument consists of 3 functions:
1: HEX
2: RGB
3: EN_WORD
At first, we have to check for every possible mistake that users can do in data entry
For example, If a user didn't enter exactly 2 args, the program must return 1
Or even if a user enters 23 it will return 1, just when a user enters a single char it can pass
or if the char isn't a digit return 1
Only 1,2,3 are possible to pass
Then I wrote 3 Fuc
FUNCTION 1 IS BASED ON THESE FACTS:
bool HEX:
SOME SITUATIONS IN A HEX CODE, (To be sure this is a HEX code):
1- A HEX code includes exactly 6 chars
2- A HEX code can just consist of numbers or alphabets
3 - NUMBERS IN A HEX CODE are:
1 2 3 4 5 6 7 8 9 A B C D E F,
SO WE CAN'T HAVE AN ALPHABET GREATER THAN F
FUNCTION 2 IS BASED ON THESE FACTS:
an RGB code includes 3 elements (RED, GREEN, BLUE)
We can't have more than 255 amounts of each of them!
FUNCTION 3 IS BASED ON THESE FACTS:
if the input is some words like Black or Blue
