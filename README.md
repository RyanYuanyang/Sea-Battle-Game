## Sea-Battle-Game

**Group 96:**

_He Jiangchuan 3035771945_

_Tu Yuanyang 3035832476_


This battleship game has 2 modes.

- **Mode 1:  Two players.**

This mode played by two players. Players each place their ships on a "N * N" board. The objective of this mode is to sink the opponent’s whole fleet.

Each player's fleet has several types of vessels. By default, each following type of ship has one. Additionally, setting the numbers of each type of ship within limits is available. (e.g. You can set 3 battleship for each player)

- 1 Aircraft Carrier, 6 spots   (number range: 0~1)
- 1 Battleship, 5 spots        (number range: 0~3)
- 1 Cruiser, 4 spots           (number range: 0~3)
- 1 Destroyer, 3 spots         (number range: 0~3)
- 1 Submarine, 2 spots         (number range: 0~5)

Each player can attack by fire cannon ball to a specified position of the opponent's board. 

Each player attack just once a turn, then pass the turn to the opponent.

Attack effects will be fed back after each attack. Both sides get the result of whether a ship has been hit, and the position has been attacked would be shown on the board.

When a player’s whole fleets is sunk, the game ends.


- **Mode 2: Single player.**

In this mode, the rules are the same as mode 1, except player’s opponent is a computer.

There are three levels of computer difficulty. **Normal, Hard, Impossible.**


- **Mode 3: Challenge mode.**

The player is provided with limited number of attacks to sink the computer’s fleet. 

The player just need to consider how to sink the computers fleet, and don’t need to launch the fleet.

In this mode, computer’s fleet is generated randomly. By default, each type of vessel mentioned above has one. Setting the numbers of computer’s vessels and players attack chances is also available.

When computer’s whole fleets is sunk or the chances of attacks is used up, the game ends.


**The following features are planed to be implemented:**

1. Random is used to generate the arrangement of player’s fleet (can also be arranged manually) and the enemy’s fleet.

2. An 2D array that represents the whole game board with nxn dimension would be created, and the dimension should be at least 8 and at most 16.

3. The players are able to set their own size of the game board by inputing its dimension, so dynamic memory management would be used to allocate the array which represents the game board with specific size.

4. A file that stores the current situation of the game board and the round would be created if player input save, the player can then load the saved file to continue gaming. In addition, a file that ranks the best record of player in mode 3 would be generated and then being outputted as a readable text for readers.

5. Codes is in multiple files according to their functions. For example, a file named main.cop is the main body of the program, comp.cpp would be the program of the AI opponent, a file named printboard.cpp would be the program to print the 2D array into a game board, and a header file would also be created to declare different functions
