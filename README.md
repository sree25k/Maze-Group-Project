Team Members:

Jawaid Saifullah  (UID: 3036223309, GitHub: @saifho).

Mahatharadol Vie (UID: 3036270089, GitHub: @viecodes).

Muthukrishnan Sreedhar Kandavel (UID: 3035671420, GitHub: @sree25k).

Sakamoto Aoi (UID: 3036137196), GitHub: @aoicodes).

Yee Tsz Lok (UID: 3036223414, GitHub: @TLYEE).


Link to demonstration: https://drive.google.com/file/d/1ZykM96NhW1vvC0us8f-ASKW0w2yKe9TV/view?usp=share_link



Title: Labyrinth Solver



Description:

This is a text based maze solver where the player will have to figure out a way to get from the top left (the starting point) to the bottom right (the end of the maze). The precise rule will vary depending on what gamemode is being played. In general the player can move into free spaces by inputting (w/s/a/d, representing up, down, left, right respectively). 

Gamemode 1: Answer MCQ

This game mode will require the player to travel from the start to end, however certain paths are blocked by question marks “ ? “. If a player bumps into them, they will have to        answer a multiple choice question (of C++ or general knowledge questions) to remove the obstacle. 

Gamemode 2: Lock and Key

There will again be obstacles in this game mode which are different locks representing card suit symbols. The player will have to find the respective key to unlock the corresponding lock. The player is timed so they should aim to finish it as quickly as possible. There is also a dark mode in which only a small section of the maze surrounding the player will be visible, to add an extra challenge. 

Gamemode 3: Escape the Monster

The layout and concept of this map is similar to pacman, however, there is only one monster who can only start moving once the player has progressed to a depth of 11 on the map (the map is 21 by 21). That being said, the monster can jump over the blocks and move two blocks for a player’s single move. The monster always moves two blocks on the closest path to get to the player. A move count is displayed so the player should aim to escape the monster in as few moves as possible. Press ‘q’ to quit the game, and ‘r’ to restart.





Features:

File Input/Output: The player has up to 4 maps to choose from, each containing its own unique elements. All maps are read from external .txt file through file input and stored in vector (dynamic memory).

Overall the program is stored in a main file and the header for the main, with additional .cpp files representing different game modes such as Answer MCQ. Some of these gamemode cpp files like playMCQ also contain their own header files if they make use of additional .cpp files.

Struct to store multiple choice questions for the trivia part of game 1 (MCQ). The first struct member is the string type containing the question. The second struct member is the string array type of size 4, containing the choices. The third struct member is the char type containing the correct answer (either ‘a’, ‘b’, ‘c’ or ‘d’).

Linked lists to store the ‘MCQ’ struct types.

If-else statement that performs like a while-loop which will keep prompting MCQ’s to the player until the player answers correctly.

In game 2, Lock and Key, the status of each lock (locked/unlocked) is stored in STL maps. The status of the unlocked locks are then changed in the vectors representing the map to remove them from the maze map when printed. 

For gamemode 2, darkmode and timers are added so players are under additional pressure. This is a creative and fun element that provides an extra challenge.




Compilation and Execution Instructions:

i)Download the zip file. Unzip and move to desktop. cd into that directory.

ii)When in the working directory, type the terminal command ‘g++ *.cpp -o final’

iii)Then run the command ‘./final’ to play the game.

Basic Instruction: As instructed on the screen, enter 1 to play ‘Answer MCQ’, 2 to play ‘Lock and Key’, and 3 to play ‘Escape the Monster’.

Recommendations: Best played when the terminal is full screen. After compiling, close terminal, cd back into the directory and run command ‘./final’. Set terminal font to 9, adjust it more depending on the individual screen.




No non-standard C/C++ libraries were included.




