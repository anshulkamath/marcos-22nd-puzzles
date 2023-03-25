#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>

#include "names.h"

#define GUESS_SIZE 20
#define IS_PIPED (!isatty(fileno(stdin)))

int prev_streak = 0;
int streak = 1;

void read_guess(char *src) {
  char curr;
  int i;

  for (i = 0; i < GUESS_SIZE; i++) {
    fread(&curr, 1, 1, stdin);
    if (curr == '\n' || curr == '\0') {
      src[i] = '\0';
      break;
    }

    src[i] = curr;
  }
}

int get_guess(char *guess) {
  int is_piped = !isatty(fileno(stdin));

  if (!is_piped) {
    printf("Please enter your guess: ");
  }

  read_guess(guess);

  return 0;
}

void print_message(const char *message) {
  const int CHARACTERS_PER_LINE = 120;
  int line_index = 0, i = 0;

  do {
    if ((line_index++ >= CHARACTERS_PER_LINE) && message[i] == ' ') {
      line_index = 0;
      printf("\n");
      continue;
    }

    printf("%c", message[i]);
  } while (message[i++]);
}

void print_incorrect_guess(const char *guess) {
  printf("Are you serious? Why would `%s` be the answer?\nResetting your streak.\n", guess);
}

int validate_guess(const char *guess, const char *sol_pattern) {
  regex_t regex;
  int return_code;

  if (regcomp(&regex, sol_pattern, REG_EXTENDED | REG_ICASE)) {
    fprintf(stderr, "Unable to compile regex: %s\n", sol_pattern);
    return -1;
  }

  return_code = regexec(&regex, guess, 0, NULL, 0);
  if (return_code == REG_NOMATCH) {
    return 1;
  }

  if (return_code) {
    fprintf(stderr, "An error occurred while validating %s against regex %s\n", guess, sol_pattern);
  }

  return return_code;
}

int ask_question(const char *message, const char *sol_pattern) {
  char guess[GUESS_SIZE] = { 0 };

  print_message(message);
  printf("\n");

  get_guess(guess);

  if (IS_PIPED) {
    printf("Please enter your guess: %s\n", guess);
  }

  int valid_guess = validate_guess(guess, sol_pattern);
  if (valid_guess) {
    print_incorrect_guess(guess);
  }

  int temp = streak;
  streak = !valid_guess ? streak + prev_streak : 1;
  prev_streak = !valid_guess ? temp : 0;

  return !valid_guess * prev_streak;
}

int main() {
  question_t current = questions[0];

  print_message(
    "Welcome to your next task, Paco (if that's even your real name). "
    "Luckily for you, this game is not technical at all (other than running this executable, I guess...). "
    "You will be given a series of prompts, and your job is to either 1) finish the meme or 2) enter who said the quote. "
    "There is an understanding that you will not cheat by looking at the quotes list. "
    "Points will be awarded via a Fibonacci sequence conditioned on consecutive right answers. "
    "Additionally, I reserve the right to zero your score out at any point in the game. "
    "The criterion for game termination is a secret, so maybe just try being right.\n\n"
  );

  if (!IS_PIPED) {
    print_message("Press ENTER to start.");
    getchar();
    printf("\n");
  }

  int score = 0;
  for (int i = 0; questions[i].question; current = questions[++i]) {
    if (!current.solution) {
      print_message(current.question);
      continue;
    }

    score += ask_question(current.question, current.solution);
    printf("Your score is: %d\n\n", score);

    if (streak > 40) {
      print_message(
        "Woah there, slow your roll. "
        "You're going way too fast... this is a marathon not a sprint. "
        "Resetting your score and streak."
        "\n\n"
      );

      score = 0;
      streak = 1;
      prev_streak = 0;
    }

    if (score > 500) {
      print_message("\nYour score is way too high - let's fix that. Resetting your score and streak.");
      score = 0;
      streak = 1;
      prev_streak = 0;
    }
  }

  win_message(score);

  return 0;
}
