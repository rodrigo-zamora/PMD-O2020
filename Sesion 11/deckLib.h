#ifndef _DECK_EMULATOR_GUARD_H
#define _DECK_EMULATOR_GUARD_H

struct DeckEmulator {
  char* deck;
  char card_in_hand;
  int card_count;
};

typedef struct DeckEmulator* DeckEmulatorRef;

void DE_printDeck(DeckEmulatorRef);
void DE_draw(DeckEmulatorRef);
void DE_bottom(DeckEmulatorRef);
void DE_top(DeckEmulatorRef);
void DE_discard(DeckEmulatorRef);
void DE_initiGame(DeckEmulatorRef);
void DE_endGame(DeckEmulatorRef);
void DE_startGame(DeckEmulatorRef);

#endif