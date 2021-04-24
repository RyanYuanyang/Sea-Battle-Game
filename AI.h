#ifndef AI_H
#define AI_H

int IMPOSSIBLE(int a[11][11], int n);
int EASY(int a[11][11], int n);
int HARD(int a[11][11], int n);
int NORMAL(int a[11][11], int n);
int Count_ships_left_AI(int board[][11], int ships[]);
int AI(int diff);

#endif
