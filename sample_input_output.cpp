//Initial interface
//output:


    ____________________   _____    __________    ______________________________________.____        ________    _____      _____  ___________
   /   _____/\_   _____/  /  _  \   \______   \  /  _  \__    ___/\__    ___/\_   _____/|    |      /  _____/   /  _  \    /     \ \_   _____/
   \_____  \  |    __)_  /  /_\  \   |    |  _/ /  /_\  \|    |     |    |    |    __)_ |    |     /   \  ___  /  /_\  \  /  \ /  \ |    __)_
   /        \ |        \/    |    \  |    |   \/    |    \    |     |    |    |        \|    |___  \    \_\  \/    |    \/    Y    \|        \
  /_______  //_______  /\____|__  /  |______  /\____|__  /____|     |____|   /_______  /|_______ \  \______  /\____|__  /\____|__  /_______  /
          \/         \/         \/          \/         \/                            \/         \/         \/         \/         \/        \/






                                        Welcome to the Seabattle game (Author: Tu Yuanyang & He Jiachuan)

                                                        1: Play!
                                                        2: Instruction
                                                        3: Quit
//input:
2
//The Instruction is showed below
//output:
Battleship game is a strategy type gussing game.

It is typically played on square and ruled grids on which each player's fleet of battleships are marked.
The locations of the fleets are concealed from the other player.
Players alternate turns calling attacks at the grid which marks the other player's ships, and the objective of the game is to destroy the opposing player's fleet.

This game has 2 modes:
  Mode 1: Play Against AI
  Mode 2: Challenge Mode

Detailed machenisms of each mode will be introduced befor the game start.

ENJOY AND GET READY FOR THE WAR CAPITAN!

Enter anything except 3 to Play, or enter 3 to if you want quit.

//input anything except 3 and it will go back to the menu
//output:


    ____________________   _____    __________    ______________________________________.____        ________    _____      _____  ___________
   /   _____/\_   _____/  /  _  \   \______   \  /  _  \__    ___/\__    ___/\_   _____/|    |      /  _____/   /  _  \    /     \ \_   _____/
   \_____  \  |    __)_  /  /_\  \   |    |  _/ /  /_\  \|    |     |    |    |    __)_ |    |     /   \  ___  /  /_\  \  /  \ /  \ |    __)_
   /        \ |        \/    |    \  |    |   \/    |    \    |     |    |    |        \|    |___  \    \_\  \/    |    \/    Y    \|        \
  /_______  //_______  /\____|__  /  |______  /\____|__  /____|     |____|   /_______  /|_______ \  \______  /\____|__  /\____|__  /_______  /
          \/         \/         \/          \/         \/                            \/         \/         \/         \/         \/        \/







                                                        Choosing Mode:

                                                        1: Fight Against AI
                                                        2: Challenge Mode
                                                        3: Quit
//input:
1
//output:

  This is the typical game play of Battleship game.

  In this mode, player's opponent is a computer, with difficulty **Easy, Normal, Hard, Impossible.**

  Player randomly generate (either horizontally or vertically and at random spots) his ships on a 10 x 10 board

  Types of ships avaliable for the player (with allowed amount):
    - Aircraft Carrier, 6 units  (0~3)
    - Battleship, 5 units        (0~3)
    - Cruiser, 4 units           (0~5)
    - Destroyer, 3 units         (0~5)
    - Submarine, 2 units         (0~5)

  Your win goal is to defeat the enemy fleet, otherwise you lose.

  Choosing Difficulty:

    1: EASY
    2: NORMAL
    3: HARD
    4: IMPOSSIBLE
//input:
4
//output:
    YOU CHOOSE 4: IMPOSSIBLE MODE

    Please choose the number of ships ( both yours and AI's )
    1.Default ( 1 for each type of ship )
    2.Customize
//input:
2
//output: 
//Then, the battle start
//output:
The enemy fleet was found! Destroy them or we will die!

    Your Fleet:                                                   Enemy's Fleet:

         1   2   3   4   5   6   7   8   9  10 (x)                   1   2   3   4   5   6   7   8   9  10 (x)
    1  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                1  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    2  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                2  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | 2 | 2 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                3  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    4  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                4  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    5  | ~ | ~ | ~ | ~ | ~ | 3 | 3 | 3 | 3 | ~ |                5  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | 3 | ~ |                6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    7  | 4 | 4 | 4 | 4 | ~ | ~ | ~ | ~ | 3 | ~ |                7  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | 6 | 6 | 6 | 6 | 6 | 6 | ~ | ~ |                9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)                                                         (y)

    Your  fleet:  Submarine(2) = 1 Destoryer(3) = 2 Cruiser(4) = 1 Battleship(5) = 0 Carrier(6) = 1


    Enemy fleet:  Submarine(2) = 1 Destoryer(3) = 2 Cruiser(4) = 1 Battleship(5) = 0 Carrier(6) = 1


    Choose position to attack (x y):
//input:
1 5
//output:
    Missed! ( 1 , 5 )

    Your ship has been shot! ( 3 , 1 )

    Your Fleet:                                                   Enemy's Fleet:

         1   2   3   4   5   6   7   8   9  10 (x)                   1   2   3   4   5   6   7   8   9  10 (x)
    1  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                1  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    2  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                2  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | X | 2 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                3  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    4  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                4  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    5  | ~ | ~ | ~ | ~ | ~ | 3 | 3 | 3 | 3 | ~ |                5  | O | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | 3 | ~ |                6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    7  | 4 | 4 | 4 | 4 | ~ | ~ | ~ | ~ | 3 | ~ |                7  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | 6 | 6 | 6 | 6 | 6 | 6 | ~ | ~ |                9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)                                                         (y)

    Your  fleet:  Submarine(2) = 1 Destoryer(3) = 2 Cruiser(4) = 1 Battleship(5) = 0 Carrier(6) = 1


    Enemy fleet:  Submarine(2) = 1 Destoryer(3) = 2 Cruiser(4) = 1 Battleship(5) = 0 Carrier(6) = 1


    Choose position to attack (x y):
//input:
2 4
//output:
    Missed! ( 2 , 4 )

    Your ship has been shot! ( 5 , 6 )

    Your Fleet:                                                   Enemy's Fleet:

         1   2   3   4   5   6   7   8   9  10 (x)                   1   2   3   4   5   6   7   8   9  10 (x)
    1  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                1  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    2  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                2  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | X | 2 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                3  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    4  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                4  | ~ | O | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    5  | ~ | ~ | ~ | ~ | ~ | X | 3 | 3 | 3 | ~ |                5  | O | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | 3 | ~ |                6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    7  | 4 | 4 | 4 | 4 | ~ | ~ | ~ | ~ | 3 | ~ |                7  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | 6 | 6 | 6 | 6 | 6 | 6 | ~ | ~ |                9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)                                                         (y)

    Your  fleet:  Submarine(2) = 1 Destoryer(3) = 2 Cruiser(4) = 1 Battleship(5) = 0 Carrier(6) = 1


    Enemy fleet:  Submarine(2) = 1 Destoryer(3) = 2 Cruiser(4) = 1 Battleship(5) = 0 Carrier(6) = 1


    Choose position to attack (x y):
//after 8 shots, we first shot an enmy ship
//output:
    Right on Target! ( 8 , 5 )

    Your ship has been shot! ( 5 , 9 )

    Your Fleet:                                                   Enemy's Fleet:

         1   2   3   4   5   6   7   8   9  10 (x)                   1   2   3   4   5   6   7   8   9  10 (x)
    1  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                1  | ~ | ~ | ~ | ~ | O | ~ | ~ | ~ | ~ | ~ |
    2  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                2  | ~ | ~ | ~ | O | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | X | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                3  | ~ | ~ | O | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    4  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                4  | ~ | O | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    5  | ~ | ~ | ~ | ~ | ~ | X | X | X | X | ~ |                5  | O | ~ | ~ | ~ | ~ | ~ | ~ | X | ~ | ~ |
    6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | X | ~ |                6  | ~ | ~ | ~ | ~ | ~ | ~ | O | ~ | ~ | ~ |
    7  | 4 | X | 4 | 4 | ~ | ~ | ~ | ~ | 3 | ~ |                7  | ~ | ~ | ~ | ~ | ~ | O | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | 6 | 6 | 6 | 6 | 6 | 6 | ~ | ~ |                9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)                                                         (y)

    Your  fleet:  Submarine(2) = 0 Destoryer(3) = 1 Cruiser(4) = 1 Battleship(5) = 0 Carrier(6) = 1


    Enemy fleet:  Submarine(2) = 1 Destoryer(3) = 2 Cruiser(4) = 1 Battleship(5) = 0 Carrier(6) = 1


    Choose position to attack (x y):
//A few shots later, we sunk an enmy destroyer
//output:
    Right on Target! ( 6 , 5 )

    Your ship has been shot! ( 9 , 7 )

    You sank an enemy Destoryer !

    Your Fleet:                                                   Enemy's Fleet:

         1   2   3   4   5   6   7   8   9  10 (x)                   1   2   3   4   5   6   7   8   9  10 (x)
    1  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                1  | ~ | ~ | ~ | ~ | O | ~ | ~ | ~ | ~ | ~ |
    2  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                2  | ~ | ~ | ~ | O | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | X | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                3  | ~ | ~ | O | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    4  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                4  | ~ | O | ~ | ~ | ~ | ~ | ~ | O | ~ | ~ |
    5  | ~ | ~ | ~ | ~ | ~ | X | X | X | X | ~ |                5  | O | ~ | ~ | ~ | ~ | X | X | X | X | O |
    6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | X | ~ |                6  | ~ | ~ | ~ | ~ | ~ | ~ | O | O | ~ | ~ |
    7  | X | X | X | X | ~ | ~ | ~ | ~ | X | ~ |                7  | ~ | ~ | ~ | ~ | ~ | O | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | 6 | 6 | X | X | X | 6 | ~ | ~ |                9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | O | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)                                                         (y)

    Your  fleet:  Submarine(2) = 0 Destoryer(3) = 0 Cruiser(4) = 0 Battleship(5) = 0 Carrier(6) = 1


    Enemy fleet:  Submarine(2) = 1 Destoryer(3) = 1 Cruiser(4) = 1 Battleship(5) = 0 Carrier(6) = 1


    Choose position to attack (x y):
//we shot a position that shot before
//input:
2 4
//outpt:
    Denied, The Position Has been Shot.


    Your Fleet:                                                   Enemy's Fleet:

         1   2   3   4   5   6   7   8   9  10 (x)                   1   2   3   4   5   6   7   8   9  10 (x)
    1  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                1  | ~ | ~ | ~ | ~ | O | ~ | ~ | ~ | ~ | ~ |
    2  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                2  | ~ | ~ | ~ | O | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | X | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                3  | ~ | ~ | O | ~ | ~ | ~ | O | ~ | ~ | ~ |
    4  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                4  | ~ | O | ~ | ~ | ~ | ~ | ~ | O | ~ | ~ |
    5  | ~ | ~ | ~ | ~ | ~ | X | X | X | X | ~ |                5  | O | ~ | ~ | ~ | ~ | X | X | X | X | O |
    6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | X | ~ |                6  | ~ | ~ | ~ | ~ | ~ | ~ | O | O | ~ | ~ |
    7  | X | X | X | X | ~ | ~ | ~ | ~ | X | ~ |                7  | ~ | ~ | ~ | ~ | ~ | O | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | 6 | 6 | X | X | X | X | ~ | ~ |                9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | O | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)                                                         (y)

    Your  fleet:  Submarine(2) = 0 Destoryer(3) = 0 Cruiser(4) = 0 Battleship(5) = 0 Carrier(6) = 1


    Enemy fleet:  Submarine(2) = 1 Destoryer(3) = 1 Cruiser(4) = 1 Battleship(5) = 0 Carrier(6) = 1


    Choose position to attack (x y):
//after two shots, our fleet is sunk by the "IMPOSSIBLE MODE" AI
//output:
    Missed! ( 1 , 2 )

    Your ship has been shot! ( 9 , 4 )

    Your Fleet:                                                   Enemy's Fleet:

         1   2   3   4   5   6   7   8   9  10 (x)                   1   2   3   4   5   6   7   8   9  10 (x)
    1  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                1  | ~ | ~ | ~ | ~ | O | ~ | ~ | ~ | ~ | ~ |
    2  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                2  | O | O | ~ | O | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | X | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                3  | ~ | ~ | O | ~ | ~ | ~ | O | ~ | ~ | ~ |
    4  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                4  | ~ | O | ~ | ~ | ~ | ~ | ~ | O | ~ | ~ |
    5  | ~ | ~ | ~ | ~ | ~ | X | X | X | X | ~ |                5  | O | ~ | ~ | ~ | ~ | X | X | X | X | O |
    6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | X | ~ |                6  | ~ | ~ | ~ | ~ | ~ | ~ | O | O | ~ | ~ |
    7  | X | X | X | X | ~ | ~ | ~ | ~ | X | ~ |                7  | ~ | ~ | ~ | ~ | ~ | O | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | X | X | X | X | X | X | ~ | ~ |                9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | O | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |                10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)                                                         (y)

    Your Fleet is Defeated
    You lost.



    Choose an option:
    1. Go Back to menu
    2. Quit
//Then, we want to go back to menu to play challenge mode
//input:
1
//output:


    ____________________   _____    __________    ______________________________________.____        ________    _____      _____  ___________
   /   _____/\_   _____/  /  _  \   \______   \  /  _  \__    ___/\__    ___/\_   _____/|    |      /  _____/   /  _  \    /     \ \_   _____/
   \_____  \  |    __)_  /  /_\  \   |    |  _/ /  /_\  \|    |     |    |    |    __)_ |    |     /   \  ___  /  /_\  \  /  \ /  \ |    __)_
   /        \ |        \/    |    \  |    |   \/    |    \    |     |    |    |        \|    |___  \    \_\  \/    |    \/    Y    \|        \
  /_______  //_______  /\____|__  /  |______  /\____|__  /____|     |____|   /_______  /|_______ \  \______  /\____|__  /\____|__  /_______  /
          \/         \/         \/          \/         \/                            \/         \/         \/         \/         \/        \/







                                                        Choosing Mode:

                                                        1: Fight Against AI
                                                        2: Challenge Mode
                                                        3: Quit
//input:
2
//output:


  Challenge mode is an alternative game play of Seabattle game we came up

  In challenge mode, you only have limited amount of shells (60) to defeat the enemy fleet
  You don't have a fleet, instead, you are defending your base from enemy's attack
  The enemy fleet contains only one of the each type of ship

  They are:
      1 Submarine: 2 units
      1 Destoryer: 3 units
      1 Cruiser: 4 units
      1 Battleship: 5 units
      1 Carrier: 6 units

  If you defeat the enemy fleet within the limited shells, you win!
  Otherwise, if you are ran out of shells and there are still enemy ships left, the game failed :(

  Each of the winning game play will be recorded, and your record will be ranked by the amount of shells you use.
  The record will be stored in a txt file and you can call/read it in the game.



  Choose an option:
    1. Enter 1 to start
    2. Enter anything else to see your local record
//We want to see the record (but there are no records before on the server)
//input: 
2
//output:
Ranking (shells consumed)    Date
1. empty
2. empty
3. empty
4. empty
5. empty
6. empty
7. empty
8. empty
9. empty
10.empty

  Choose an option:
    1. Enter 1 to start
    2. Enter anything else to see your local record
//we input 1 to start this mode
//input:
1
//output:
Destroy The Enemy Fleet and Protect Our Base!


         1   2   3   4   5   6   7   8   9  10 (x)

    1  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    2  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    4  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    5  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    7  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)

    Enemy fleet:  Submarine(2) = 1 Destoryer(3) = 1 Cruiser(4) = 1 Battleship(5) = 1 Carrier(6) = 1

    60 shells left,   0 hit.

    Choose position to attack (x y):
//input:
2 1
//output:
    Missed!


         1   2   3   4   5   6   7   8   9  10 (x)

    1  | ~ | O | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    2  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    4  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    5  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    7  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)

    Enemy fleet:  Submarine(2) = 1 Destoryer(3) = 1 Cruiser(4) = 1 Battleship(5) = 1 Carrier(6) = 1

    59 shells left,   0 hit.

    Choose position to attack (x y):
//input:
3 2
//output:
    Right on Target!


         1   2   3   4   5   6   7   8   9  10 (x)

    1  | ~ | O | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    2  | ~ | ~ | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    4  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    5  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    7  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)

    Enemy fleet:  Submarine(2) = 1 Destoryer(3) = 1 Cruiser(4) = 1 Battleship(5) = 1 Carrier(6) = 1

    58 shells left,   1 hit.

    Choose position to attack (x y):
//We sunk an enemy battleship in 8 shots!
//output:
    Right on Target!

    Good job capitan, you have sank an Battleship !

         1   2   3   4   5   6   7   8   9  10 (x)

    1  | ~ | O | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    2  | ~ | O | X | O | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | ~ | ~ | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    4  | ~ | ~ | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    5  | ~ | ~ | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    7  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)

    Enemy fleet:  Submarine(2) = 1 Destoryer(3) = 1 Cruiser(4) = 1 Battleship(5) = 0 Carrier(6) = 1

    52 shells left,   5 hit.

    Choose position to attack (x y):
//output:
    Right on Target!

    Good job capitan, you have sank an Cruiser !

         1   2   3   4   5   6   7   8   9  10 (x)

    1  | ~ | O | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    2  | O | O | X | O | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | ~ | O | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    4  | O | ~ | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    5  | O | ~ | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    6  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    7  | X | X | X | X | ~ | ~ | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)

    Enemy fleet:  Submarine(2) = 1 Destoryer(3) = 1 Cruiser(4) = 0 Battleship(5) = 0 Carrier(6) = 1

    44 shells left,   9 hit.

    Choose position to attack (x y):
//output:
    Right on Target!

    Good job capitan, you have sank an Submarine !

         1   2   3   4   5   6   7   8   9  10 (x)

    1  | ~ | O | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    2  | O | O | X | O | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | ~ | O | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    4  | O | X | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    5  | O | X | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    6  | ~ | O | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    7  | X | X | X | X | ~ | ~ | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    9  | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    10 | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    (y)

    Enemy fleet:  Submarine(2) = 0 Destoryer(3) = 1 Cruiser(4) = 0 Battleship(5) = 0 Carrier(6) = 1

    41 shells left,   11 hit.

    Choose position to attack (x y):
//output:
    Right on Target!

    Good job capitan, you have sank an Carrier !

         1   2   3   4   5   6   7   8   9  10 (x)

    1  | ~ | O | X | X | X | X | X | X | X | X |
    2  | O | O | X | O | ~ | ~ | ~ | ~ | ~ | ~ |
    3  | ~ | O | X | ~ | O | O | ~ | ~ | ~ | ~ |
    4  | O | X | X | O | ~ | ~ | ~ | ~ | ~ | ~ |
    5  | O | X | X | ~ | ~ | ~ | ~ | ~ | ~ | ~ |
    6  | ~ | O | ~ | O | O | O | ~ | ~ | ~ | ~ |
    7  | X | X | X | X | ~ | ~ | ~ | ~ | ~ | ~ |
    8  | ~ | ~ | O | ~ | O | ~ | ~ | O | ~ | ~ |
    9  | O | ~ | ~ | O | ~ | ~ | O | ~ | ~ | O |
    10 | ~ | ~ | O | ~ | ~ | O | ~ | ~ | O | ~ |
    (y)

    Enemy fleet:  Submarine(2) = 0 Destoryer(3) = 1 Cruiser(4) = 0 Battleship(5) = 0 Carrier(6) = 0

    18 shells left,   18 hit.

    Choose position to attack (x y):
//Finally, we sunk the enemy fleet in 42 shots
//output:
    Right on Target!

    You Have Sanked Enemy Fleet!
    The Victory is Yours!


The order you sunk the Enemy ships is:
Battleship
Cruiser
Destroyer
Submarine
Carrier



    Choose an option:
    1. Play Against the AI
    2. Play Challenge Mode Again!
    3. Quit
    4. Enter Anything Else to See the Local Record
//Then, we quit the game
//input:
3
//output:


 /$$   /$$  /$$$$$$  /$$    /$$ /$$$$$$$$        /$$$$$$        /$$   /$$ /$$$$$$  /$$$$$$  /$$$$$$$$       /$$$$$$$   /$$$$$$  /$$     /$$                 /$$$
| $$  | $$ /$$__  $$| $$   | $$| $$_____/       /$$__  $$      | $$$ | $$|_  $$_/ /$$__  $$| $$_____/      | $$__  $$ /$$__  $$|  $$   /$$/                |_  $$
| $$  | $$| $$  \ $$| $$   | $$| $$            | $$  \ $$      | $$$$| $$  | $$  | $$  \__/| $$            | $$  \ $$| $$  \ $$ \  $$ /$$/        /$$        \  $$
| $$$$$$$$| $$$$$$$$|  $$ / $$/| $$$$$         | $$$$$$$$      | $$ $$ $$  | $$  | $$      | $$$$$         | $$  | $$| $$$$$$$$  \  $$$$/        |__/         | $$
| $$__  $$| $$__  $$ \  $$ $$/ | $$__/         | $$__  $$      | $$  $$$$  | $$  | $$      | $$__/         | $$  | $$| $$__  $$   \  $$/                      | $$
| $$  | $$| $$  | $$  \  $$$/  | $$            | $$  | $$      | $$\  $$$  | $$  | $$    $$| $$            | $$  | $$| $$  | $$    | $$           /$$         /$$/
| $$  | $$| $$  | $$   \  $/   | $$$$$$$$      | $$  | $$      | $$ \  $$ /$$$$$$|  $$$$$$/| $$$$$$$$      | $$$$$$$/| $$  | $$    | $$          |__/       /$$$/
|__/  |__/|__/  |__/    \_/    |________/      |__/  |__/      |__/  \__/|______/ \______/ |________/      |_______/ |__/  |__/    |__/                    |___/
