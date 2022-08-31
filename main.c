#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printGame(char *);
void play(char *,char);
int checkWinner(char *);

int main(){
  char a[9]={'1','2','3','4','5','6','7','8','9'};

  while (1){
    printGame(a);
    play(a, 'X');
    if(checkWinner(a)){
      printf("X WON!!!\n");
      return EXIT_SUCCESS;
    }
    
    printGame(a);
    play(a, 'O');
    if(checkWinner(a)){\
      printf("Y WON!!!\n");
      return EXIT_SUCCESS;
    }
  }
}

void printGame(char *a){
  for (int i = 0;i < 9;i += 3)
    printf("%c | %c | %c\n",a[i],a[i+1],a[i+2]);
}

void play(char *a, char player){
  char choice;
  
  printf("\r%c => ", player);
  scanf("%c", &choice);
  choice -= '0';

  if(choice > 0 && choice <= 9){
    if(isdigit(a[choice-1])){
      a[choice - 1] = player;
      return;
    }else{
      printf("Invalid, Place is already taken!\n");
      return play(a,player);
    }
  }

  return play(a,player);
}

int checkWinner(char *a){
  for(int i = 0;i < 3;i++){
    if(a[i] == a[i+1] && a[i+1] == a[i+2]) return 1;
    if(a[i] == a[i+3] && a[i+3] == a[i+6]) return 1;
  }

  if(a[0] == a[4] && a[4] == a[8]) return 1;
  if(a[2] == a[4] && a[4] == a[6]) return 1;

  return 0;
}
