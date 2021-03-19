## Sea-Battle-Game

**Group 96:**

_He Jiangchuan 3035771945_

_Tu Yuanyang 3035832476_


**Battleship Game**

Battleship game is a strategy type gussing game. It is typically played on square and ruled grids on which each player's fleet of battleships are marked. The locations of the fleets are concealed from the other player. Players alternate turns calling attacks at the grid which marks the other player's ships, and the objective of the game is to destroy the opposing player's fleet.

According to the encyclopedia:
>Battleship is known worldwide as a pencil and paper game which dates from World War I. It was published by various companies as a pad-and-pencil game in the 1930s, and was released as a plastic board game by Milton Bradley in 1967. The game has spawned electronic versions, video games, smart device apps and a film.

Before play begins, each player secretly arranges their ships on their primary grid. Each ship occupies a number of consecutive squares on the grid, arranged **either horizontally or vertically**. The number of squares for each ship is determined by the type of the ship. The ships cannot overlap (i.e., only one ship can occupy any given square in the grid). The types and numbers of ships allowed are the same for each player. These may vary depending on the rules.


**This game has 3 modes.**


- **Mode 1:  Two players**


Two players are invloved in this moded. Each player places their ships on a "N * N" board.  (6<=N<=10)

Each player's fleet has several types of vessels. By default, each following type of ship has one. Additionally, setting the numbers of each type of ship within limits is available. (e.g. Each player can set 3 submarines maximum)

- 1 Aircraft Carrier, 6 spots  (number range: 0~1)
- 1 Battleship, 5 spots        (number range: 0~1)
- 1 Cruiser, 4 spots           (number range: 0~2)
- 1 Destroyer, 3 spots         (number range: 0~2)
- 1 Submarine, 2 spots         (number range: 0~3)

Each player can attack by fire cannon ball to a specified position of the opponent's board. 

Each player attack just once a turn, then pass the turn to the opponent.

Each player have one super missile which can cause damage in an 3x3 square.

Attack effects will be fed back after each attack. Both sides get the result of whether a ship has been hit, and the position has been attacked would be shown on the board.

When a player’s whole fleets is sunk, the game ends.


- **Mode 2: Single player.**

In this mode, the rules are the same as mode 1, except player’s opponent is a computer.

There are three levels of computer difficulty. **Normal, Hard, Impossible.**


- **Mode 3: Challenge mode.**

The player is provided with limited number of attacks (50) to sink the computer’s fleet. 

The player just need to consider how to sink the computers fleet, and don’t need to set their own fleet.

In this mode, computer’s fleet is generated randomly. By default, each type of vessel mentioned above has one.

When computer’s whole fleets is sunk or the chances of attacks is used up, the game ends.

When game ends, an ranking list would be generated, which records the number of attacks conducted in one play round and ranks them from the least.



**The following features are planed to be implemented:**

1. Random is used to generate the arrangement of player’s fleet (can also be arranged manually) and the enemy’s fleet.

2. An 2D array that represents the whole game board with NxN dimension would be created, and the dimension should be at least 8 and at most 16.

3. The players are able to set their own size of the game board by inputing its dimension, so dynamic memory management would be used to allocate the array which represents the game board with specific size.

4. A file that stores the current situation of the game board and the round would be created if player input save, the player can then load the saved file to continue gaming. In addition, a file that ranks the best record of player in mode 3 (challenging mode) would be generated/outputed and then it would also be inputed back into the program each time the players finish a game round in mode 3.

5. Codes is in multiple files according to their functions. For example, a file named main.cop is the main body of the program, comp.cpp would be the program of the AI opponent, a file named printboard.cpp would be the program to print the 2D array into a game board, and a header file would also be created to declare different functions being used in the whole program.
