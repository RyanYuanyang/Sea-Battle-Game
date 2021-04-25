## Sea Battle Game

**Group 96:**

_He Jiangchuan 3035771945_

_Tu Yuanyang 3035832476_

**Quick Start**

After downloading all the files into a repo in linux, go to the repo that stores all the files in shell, type in the command $ make, and then $ ./Seabattle.
The program will then start.


**Introduction**

Sea battle game is a strategy type gussing game. It is typically played on square and ruled grids on which each player's fleet of battleships are marked. **The locations of the fleets are concealed from the other player.** Players alternate turns calling attacks at the grid which marks the other player's ships, and the objective of the game is to destroy the opposing player's fleet.

According to the encyclopedia:
>Sea battle is known worldwide as a pencil and paper game which dates from World War I. It was published by various companies as a pad-and-pencil game in the 1930s, and was released as a plastic board game by Milton Bradley in 1967. The game has spawned electronic versions, video games, smart device apps and a film.

Before play begins, each player secretly arranges their ships on their primary grid. Each ship occupies a number of consecutive squares on the grid, arranged **either horizontally or vertically**. The number of squares for each ship is determined by the type of the ship. The ships cannot overlap (i.e., only one ship can occupy any given square in the grid). The types and numbers of ships allowed are the same for each player. These may vary depending on the rules.


**This game has 2 modes.**


- **Mode 1:  Play Against Computer**

In this mode, player’s opponent is a computer.

There are four levels of computer difficulty. **Easy, Normal, Hard, Impossible.**

Player places ships on a 10 x 10 board.

Player's fleet has several types of ships. By default, each following type of ship has one. Additionally, setting the numbers of each type of ship within limits is available. (e.g. Each player can set 3 submarines maximum)

- 1 Aircraft Carrier, 6 spots  (number range: 0~3)
- 1 Battleship, 5 spots        (number range: 0~3)
- 1 Cruiser, 4 spots           (number range: 0~5)
- 1 Destroyer, 3 spots         (number range: 0~5)
- 1 Submarine, 2 spots         (number range: 0~5)

Player can attack by fire cannon ball to a specified position of the opponent's board. 

Player can attack just once a turn, then pass the turn to the opponent.

Attack effects will be reported after each attack. Both sides get the result of whether a ship has been hit, and the position has been attacked would be shown on the board.

When player’s or computer's whole fleet is sunk, the game ends.


- **Mode 2: Challenge mode.**

Player has no fleet in this mode, instead, player is provided with limited number of attacks (60) to sink the computer’s fleet. 

Computer's fleet is randomly generated as normal, but fixed to one for one type of ship.

The player just need to consider how to sink the computers fleet to defend his/her base.

When computer’s whole fleets is eliminated, the game wins.

If the chances of attacks is used up, enemy destroy your base, the game loses.

When game ends, an ranking record would be generated in the repo that store the game as "record.txt".

the record rank the number of attacks conducted in one play round and ranks them from the least, with the date of the play round also being recorded.

Player can access the record before the challenge mode/ after the challenge mode end.

**Player is not recommanded to manipulate the record by directly accessing the file.**


**The following features are implemented:**

1. Random is used to generate the arrangement of player’s fleet and the enemy’s fleet. Also, random is heavily relied in mode 1 to control the action of the computer.

2. 2D array that represents the game board with 10 x 10 dimension is widely used to store the game status. Vector data type is used to store the record and the order that player sunk the enemy's ships in challenge mode.

3. Vector is used in function printRecord() , so dynamic memory management would be used to store the record of challenge mode. Vector is also used in challenge mode to store the order that player sunk the enemy's ships.

4. A file named "record.txt" that ranks the best record of player in challenging mode (with the date when each play round is conducted) would be generated/outputed and then it would also be inputed back into the program each time the players call the record.

6. Codes is in multiple files according to their functions. For example, a file named main.cpp is the main body of the program, AI.cpp would be the program of the AI opponent, a file named printBoard.cpp would be the program to print the 2D array into a game board, and multiple header files would be created to declare different functions being used in the whole program.


**We use academy11 server for testing**
