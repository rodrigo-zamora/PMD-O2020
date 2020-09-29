#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deckLib.h"

void DE_startGame(DeckEmulatorRef game){
  int gameRunning = 1;
  char respuesta[3];
  while(gameRunning == 1){
    printf("[p]ull\n  [t]op\n  [b]ottom\n  [d]iscard\n[e]xit\n");
    fgets(respuesta, 3, stdin);
    if(respuesta[0] == 'p'){
      DE_draw(game);
      DE_printDeck(game);
    }
    else if(respuesta[0] == 't'){
      DE_top(game);
      DE_printDeck(game);
    }
    else if(respuesta[0] == 'b'){
      DE_bottom(game);
      DE_printDeck(game);
    }
    else if(respuesta[0] == 'd'){
      DE_discard(game);
      DE_printDeck(game);
    }
    else if(respuesta[0] == 'e'){
      gameRunning = 0;
      break;
    }
  }
}

void DE_initiGame(DeckEmulatorRef game)
{
  char* c_deck = calloc(6, sizeof(char));
  int countCardsInHand = 5;
  game->deck = c_deck;
  game->card_in_hand = 0;
  game->card_count = 5; // tenemos 5 cartas, indexadas del 0 al 4
  char* handPointer = c_deck + 4;
  srand(time(NULL));
  char toAssign[] = {'D', 'J', 'Q', 'R', 'A'};
  for(int i=0; i<5; i++)
  {
    // rand() regresa un valor entero de 0 a MAX_RANDOM
    int randIndex = rand() % 5; // randIndex [0, 5)
    while(toAssign[randIndex % 5] == 0)
      randIndex++;
    game->deck[i] = toAssign[randIndex % 5];
    toAssign[randIndex % 5] = 0;
  }
}
void DE_draw(DeckEmulatorRef game)
{
  if(game->card_in_hand == 0 && game->card_count > 0)
  { 
    game->card_in_hand = game->deck[game->card_count-1];
    game->card_count--;
  } else {
    if(game->card_count == 0){
      printf("Error: Ya no hay cartas en el deck para robar.\n");
    }
    else{
      printf("Error: Ya tienes una carta en la mano.\n");
    }
  }
}
void DE_discard(DeckEmulatorRef game)
{
  if(game->card_in_hand != 0)
    game->card_in_hand = 0;
}
void DE_bottom(DeckEmulatorRef game)
{
  if(game->card_in_hand != 0){
    int i;
    for(i = game->card_count; i >= 0; i--){
      game->deck[i+1] = game->deck[i];
    }
    game->deck[0] = game->card_in_hand;
    game->card_in_hand = 0;
    game->card_count++;
  }
  else{
    printf("Error: No tienes ninguna carta en tu mano.\n");
  }
}
void DE_top(DeckEmulatorRef game)
{
  if(game->card_in_hand != 0){
    game->deck[game->card_count] = game->card_in_hand;
    game->card_in_hand = 0;
    game->card_count++;
  }
  else{
    printf("Error: No tienes ninguna carta en tu mano.\n");
  }
}
void DE_printDeck(DeckEmulatorRef game)
{
  // como mostramos nuestro deck de cartas al usuario?
  printf("{ ");
  for(int i=0; i < game->card_count; i++)
  {
    if(game->deck[i] == 'D')
      printf("10 ");
    else
      printf("%c ", game->deck[i]);
  }
  printf("} ");
  if(game->card_in_hand == 'D')
    printf(":: <10> \n");
  else
    printf(":: <%c>\n", game->card_in_hand);
}

void DE_endGame(DeckEmulatorRef game){
  free(game->deck);
}