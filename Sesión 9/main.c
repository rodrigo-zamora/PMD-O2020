#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// DeckEmulator  -> deck de cartas
struct DeckEmulator {
  char* deck;
  char card_in_hand;
  int card_count;
};

void printDeck(struct DeckEmulator* game);
void draw(struct DeckEmulator*);
void bottom(struct DeckEmulator*);
void top(struct DeckEmulator*);
void discard(struct DeckEmulator*);
void initiGame(struct DeckEmulator*);
void endGame(struct DeckEmulator*);

int main(void)
{
  struct DeckEmulator game;
  int gameRunning = 1;
  initiGame(&game);
  printDeck(&game);
  char respuesta;
  while(gameRunning == 1){
    printf("[p]ull\n  [t]op\n  [b]ottom\n  [d]iscard\n[e]xit\n");
    scanf("%c", &respuesta);
    if(respuesta == 'p'){
      draw(&game);
      printDeck(&game);
    }
    else if(respuesta == 't'){
      top(&game);
      printDeck(&game);
    }
    else if(respuesta == 'b'){
      bottom(&game);
      printDeck(&game);
    }
    else if(respuesta == 'd'){
      discard(&game);
      printDeck(&game);
    }
    else if(respuesta == 'e'){
      gameRunning = 0;
      break;
    }
  }
}
void initiGame(struct DeckEmulator* game)
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
void draw(struct DeckEmulator* game)
{
  if(game->card_in_hand == 0 && game->card_count > 0)
  { 
    game->card_in_hand = game->deck[game->card_count-1];
    game->card_count--;
  } else {
    printf("Error: ya tienes una carta en la mano O ya no hay cartas que robar :( \n");
  }
}
void discard(struct DeckEmulator* game)
{
  if(game->card_in_hand != 0)
    game->card_in_hand = 0;
}
void bottom(struct DeckEmulator* game)
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
}
void top(struct DeckEmulator* game)
{
  if(game->card_in_hand != 0)
    game->deck[game->card_count] = game->card_in_hand;
    game->card_in_hand = 0;
    game->card_count++;
}
void printDeck(struct DeckEmulator* game)
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
    printf(":: <%c> \n", game->card_in_hand);
}

void endGame(struct DeckEmulator* game){
  free(game->deck);
}