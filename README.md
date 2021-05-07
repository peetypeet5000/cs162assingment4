# CS162 Assignment 4 - Hunt the Wumpus
This was a game created for CS162. The purpose was to practice polymorphism and inheritance.  
  
 ![Wumpus Title Screen](/wumpus.png)

## Usage
Clone folder and make executable with ```make```. Due to usage of ```stty raw```, it may only work correctly on linux (tested on Ubuntu).  
  
To run, do ```./wumpus <size of board [4-15]> <debug mode[true/false]>```. Debug mode dictates if the identities of the various rooms are revealed to the player.

## How to Play
The player starts in one square of the game board that is occupied by the rope. In order to win, the player must collect the gold from another room on the game board and return to the rope. The player must watch out for a number of obstacles including a bottomless pit, bats, and the wumpus. The wumpus will kill the player if you encounter it, but it can also be killed by pressing the spacebar to shoot your arrows. The player must naviagate around the gameboard by using the "percepts" - the little messages above the gameboard that give you hints on what events occupy the spaces around you.
