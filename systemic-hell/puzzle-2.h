#ifndef PUZZLE_2_H
#define PUZZLE_2_H

typedef struct mystery_struct_s {
  struct mystery_struct_s *unknown;
  char *message;
} mystery_struct_t;

int mystery_function_2(const mystery_struct_t *m);

#endif
