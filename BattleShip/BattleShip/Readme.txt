******************************************************
*  Name      : Sharvita Paithankar         
*  Student ID:      108172438           
*  Class:  OOP          
*  HW#       :  Final Project              
*  Due Date:  12 September 2017 



*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program "BattleShip" allows the user to play the 
game battleship against the computer. The program allows
the user to input a file to enter ship locations. After
generating a random position for the computer ships, it asks
the user where they want to shoot the torpedo. It notifies 
if it was a hit or a miss.
 
*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program. This is the driver program that makes
objects of user and computer class and calls functions 
to run the game.

Name: Grid.h
   Contains the definition for the class Grid.

Name: Grid.cpp
   Defines and implements the grid class for implementing grids.
   This class provides routines to construct and get the grids, 
   contains info about the placement of ships, randomly shoots 
   torpedos for a computer, allows checking for placement of ship,
   prints grids and contains the vector. 
Name:  Player.h
   Virtual class for the two players: Computer and user
Name:  Computer.h
   Contains the definition for the class Computer.
Name:  Computer.cpp
   Randomly generates a number so that the ships can be 
   placed and sends info to grid class to see if the 
   water vehicles that are in the class can be placed.
Name:  Player.h
   Contains the definition for the class Player.h
Name:  Player.cpp
   Takes in information about the ships from a file 
   and sends this info to the grid to see if ships are playable.
   Allows the user to attack the computer grid and check if
   the ship has been hit. 
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The battleship game allows the user to input files but
does not place all the ships properly. The computer generates 
ships randomly and allows the user to hit as long as their column
and row are in bounds and valid. The game does not necessarily 
check if all the ships are hit and which player won. The program 
does not fully function for the user to play battleship. The program
was tested on cse grid but does not compile.

*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [Battleship.zip]

   Now you should see a directory named homework with the files:
        main.cpp
        Grid.h
        Grid.cpp
        Player.h
        User.h
        User.cpp
	Computer.h
	Computer.cpp
	WaterVehicle.h
	WaterVehicle.cpp
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [BattleShip]

    Compile the program by:
    % make

3. Run the program by:
   % ./[battleship]

4. Delete the obj files, executables, and core dump by
   %./make clean