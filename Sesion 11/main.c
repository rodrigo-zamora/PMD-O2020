#include <stdio.h>
#include <stdlib.h>
#include "deckLib.h"

int main(void)
{
  struct DeckEmulator game;
  DE_initiGame(&game);
  DE_printDeck(&game);
  DE_startGame(&game);
}