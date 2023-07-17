#include <stdio.h>
#include <stdlib.h>

char place[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void print_board(){
  printf("\n       TIC TAC TOE GAME          \n");
  printf("  Player 1 (X) - Player 2 (O)\n\n");

  printf("\t    |   |   \n"
        "\t  %c | %c | %c \n"
        "\t ___|___|___\n"
        "\t    |   |   \n"
        "\t  %c | %c | %c \n"
        "\t ___|___|___\n"
        "\t    |   |   \n"
        "\t  %c | %c | %c \n"
        "\t    |   |   \n\n"
        , place[1], place[2],place[3],
        place[4], place[5], place[6],
        place[7], place[8], place[9]);
}

int player = 1;
int choice;

int mark_board(char mark){
  for (int i = 1; i < 10; i++) {
    if (choice == i && place[i] - '0' == i) {
      place[i] = mark;
      return 0;
    }
  }
  return 1;
}

void switch_turn() {
  printf(" Player %d turn, choose a number: ", player);
A:
  scanf("%d", &choice);
  if (choice < 1 || choice > 9) {
    printf("Invalid number! Please choose another number: ");
    goto A;
  }
  if (player == 1) {
    if (mark_board('X')) {
      player = 1;
    } else {
      player = 2;
    }
  }
  else if (player == 2){
    if (mark_board('O')) {
      player = 2;
    } else {
      player = 1;
    }
  }
}

int result_check() {
  for (int i = 1; i < 10; i += 3) {
    if (place[i] == place[i + 1] && place[i + 1] == place[i + 2]) {
      if (place[i] == 'X') {
        printf("\tPlayer 1 won!\n");
      } else if (place[i] == 'O') {
        printf("\tPlayer 2 won!\n");
      }
      return 1;
    }
  }

  for (int i = 1; i < 4; i++) {
    if (place[i] == place[i + 3] && place[i + 3] == place[i + 6]) {
      if (place[i] == 'X') {
        printf("\tPlayer 1 won!\n");
      } else if (place[i] == 'O') {
        printf("\tPlayer 2 won!\n");
      }
      return 1;
    }
  }

  if (place[1] == place[5] && place[5] == place[9]) {
    if (place[1] == 'X') {
      printf("\tPlayer 1 won!\n");
    } else if (place[1] == 'O') {
      printf("\tPlayer 2 won!\n");
    }
    return 1;
  }
  
  if (place[3] == place[5] && place[5] == place[7]) {
    if (place[3] == 'X') {
      printf("\tPlayer 1 won!\n");
    } else if (place[3] == 'O') {
      printf("\tPlayer 2 won!\n");
    }
    return 1;
  }

  int count = 0;
  for (int i = 1; i < 10; i++) {
    if (place[i] - '0' != i)
      count = count + 1;
  }
  if (count == 9){
    printf("\tDraw!\n");
    return 1;
  }

  return 0;
}

int main() {
  while (!result_check()){
    system("clear");
    print_board();
    switch_turn();
  }
  system("clear");
  print_board();
  result_check();

  return 0;
}