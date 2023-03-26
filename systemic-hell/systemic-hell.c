#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "puzzle-1.h"
#include "puzzle-2.h"
#include "puzzle-3.h"

#define GUESS_SIZE 20

const char *keyword_1 = "bitches.";
const char *keyword_2 = "smash";

mystery_struct_t l6 = { NULL, "keyword: smash" };
mystery_struct_t l5 = { &l6, "you've proven that you know what you're doing. the key is the next message" };
mystery_struct_t l4 = { &l5, "okay... so you might know what's happening right now" };
mystery_struct_t l3 = { &l4, "" };
mystery_struct_t l2 = { &l3, "so you found this message, huh? you must think you're so cool." };
mystery_struct_t l1 = { &l2, "fine. I'll give you a hint here." };

void interrupt_handler(int signo) {
  printf("\nHaven't I taught you anything? Did you really think I would let you kill this process?\n");
  sleep(5);
  printf("Well... I suppose I'll let you leave. But I'm not happy about it >:(\n");
  exit(1);
}

int print_failure_message(char *guess) {
  printf(
    "You absolute buffoon! Did you really think `%s` was the correct keyphrase?\n"
    "God, I can't believe that you have friends. Try again.\n\n"
  , guess);

  return 1;
}

void read_guess(char *src) {
  for (int i = 0; i < GUESS_SIZE; i++) {
    char curr;
    fread(&curr, 1, 1, stdin);
    if (curr == '\n' || curr == '\0') {
      return;
    }
  
    src[i] = curr;
  }
}

int get_guess(char *guess, int is_piped) {
  if (!is_piped) {
    printf("Please enter your guess: ");
  }

  read_guess(guess);

  if (!is_piped) {
    printf("\n");
  }

  return 0;
}

int main() {
  signal(SIGINT, interrupt_handler);
  const int is_piped = !isatty(fileno(stdin));

  printf(
    "Welcome to your worst nightmare. It is I, Dr. Evil, back with a challenge I have dubbed `Systemic Hell.`\n"
    "In this challenge, you will have to jump through hoops like a C-show-pony. I hope you remember your GDB \n"
    "skills, because you'll need them here. I can't wait to watch you spectacularly FAIL.\n\n"
  );

  if (is_piped) {
    printf(
      "Ah, I see you're piping your text into me. If you thought of me as person instead of a woman you would\n"
      "not pipe text into me without feeling bad about it.\n\n"
    );
  }

  // Part 1
  mystery_function_1(keyword_1);

  char *guess = calloc(1, GUESS_SIZE + 1);
  get_guess(guess, is_piped);

  if (strcmp(guess, keyword_1)) {
    return print_failure_message(guess);
  }

  // Part 2
  printf(
    "Wow, congratulations on finishing my first puzzle. I admittedly made that one pretty easy for you, so don't\n"
    "go feeling too good about yourself now. A literal infant could have solved that puzzle. Let's see how you \n"
    "fare on the next one. Ta-ta.\n\n"
  );
  
  mystery_function_2(&l1);

  get_guess(guess, is_piped);
  if (strcmp(guess, keyword_2)) {
    return print_failure_message(guess);
  }

  // Part 3
  printf(
    "*starts sweating*\n"
    "That was also supposed to be an easy puzzle... don't get falsely confident now. I've got plenty of tough problems\n"
    "here for you. Just you wait... give me a second. I'm going to pull out something incredibly diabolical now... ah!\n"
    "Yes! Here it is! I think I'll make you debug a few segfaults. Haha! You're fucked! Good luck, sucker.\n\n"
  );

  const char *KEYPRHASE = "pogo.";
  uint8_t hash[32] = { 0 };
  sha256(hash, KEYPRHASE, 6);
  

  return 0;
}
