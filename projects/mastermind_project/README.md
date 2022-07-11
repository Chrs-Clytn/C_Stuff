## Task

## Description
This is the famous mastermind game!
I have created it to emulate the game, you will need to guess the order of 4 numbers. These numbers will represent the 8 colours from the game.

## Installation
In order to play, use the makefile. Simply run make in the terminal.

## Usage
Once mastermind is created, you can add additional arguments:

-c (Choose)  Use this flag if you want your next argument to be the number you try to guess!

-t (Tries)   Use this flag if you want your next argument to change the number of tries you get to guess. Default is set at 10.

e.g: mastermind -c 1234
    This will set the number you need to guess, to 1234.

e.g: mastermind -t 4
    This will set your number of tries to 4

e.g: mastermind -c 1234 -t 4
    This will set the number you need to guess to 1234, and your number of tries to 4.

I have coded it to also accept the flags combined as -ct

if using -ct enter your secret code followed by the number of tries.

e.g: mastermind -ct 1234 3

Good Luck masterminders!

## Contributors
Chris Clayton
