#include "stack.h"
#include <getopt.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define OPTIONS "srn:"
#define DEFAULT_SIZE 5

void TOH_recursive(int n, int *count, char cbegin, char cfinal, char chelper);
void TOH_stack(int n, char cbegin, char cfinal, char chelper);
void move_disks(Stack *src, Stack *dest);
void print_move(int n, char csrc, char cdest);

int main(int argc, char **argv) {
  int c = 0, num_disks = DEFAULT_SIZE;
  bool run_stack = false, run_recurs = false;

  if (argc == 1) {
    puts("Error: no arguments supplied!");
    return -1;
  }

  while ((c = getopt(argc, argv, OPTIONS)) != -1) {
    switch (c) {
    case 's':
      run_stack = true;
      break;
    case 'r':
      run_recurs = true;
      break;
    case 'n':
      num_disks = atoi(optarg);
      break;
    }
  }

  if (!run_stack && !run_recurs) {
    puts("Error: must supply a print type!");
    return -1;
  }

  if (run_stack) {
    TOH_stack(num_disks, 'A', 'B', 'C');
  }

  if (run_recurs) {
    puts("================================");
    puts("--------   RECURSION   ---------");
    puts("================================");

    int recurs_count = 0;
    TOH_recursive(num_disks, &recurs_count, 'A', 'B', 'C');

    printf("\nNumber of moves: %d\n\n", recurs_count);
  }

  return 0;
}

void TOH_recursive(int n, int *count, char cbegin, char cfinal, char chelper) {
  if (n == 1) {
    (*count)++;
    print_move(n, cbegin, cfinal);
    return;
  }

  (*count)++;
  TOH_recursive(n - 1, count, cbegin, chelper, cfinal);
  print_move(n, cbegin, cfinal);
  TOH_recursive(n - 1, count, chelper, cfinal, cbegin);
}

void TOH_stack(int n, char cbegin, char cfinal, char chelper) {
  puts("================================");
  puts("----------   STACKS   ----------");
  puts("================================");

  Stack *begin, *final, *helper;
  begin = stack_create(n, cbegin);
  final = stack_create(n, cfinal);
  helper = stack_create(n, chelper);

  if (n % 2 == 0) {
    Stack *temp = final;
    final = helper;
    helper = temp;
  }

  for (int i = n; i >= 1; i--) {
    stack_push(begin, i);
  }

  int moves = ((int)pow(2, n)) - 1, count = 0;

  for (int i = 1; i <= moves; i++) {
    if (i % 3 == 0) {
      move_disks(helper, final);
      count++;
    } else if (i % 3 == 1) {
      move_disks(begin, final);
      count++;
    } else if (i % 3 == 2) {
      move_disks(begin, helper);
      count++;
    }
  }

  printf("\nNumber of moves: %d\n\n", count);

  stack_delete(begin);
  stack_delete(final);
  stack_delete(helper);
}

void move_disks(Stack *src, Stack *dest) {
  int disk1 = stack_peek(src);
  int disk2 = stack_peek(dest);

  if (stack_empty(src)) { // Pop from dest, move to src if src is empty
    stack_push(src, stack_pop(dest));
    print_move(disk2, dest->name, src->name);
  } else if (stack_empty(dest)) { // Pop from src, move to dest if dest empty
    stack_push(dest, stack_pop(src));
    print_move(disk1, src->name, dest->name);
  } else if (disk1 > disk2) { // If src has bigger disk, move disk dest -> src
    stack_push(src, stack_pop(dest));
    print_move(disk2, dest->name, src->name);
  } else { // If dest has bigger disk, move disk src -> dest
    stack_push(dest, stack_pop(src));
    print_move(disk1, src->name, dest->name);
  }
}

void print_move(int n, char csrc, char cdest) {
  printf("Move disk %d from peg %c to peg %c\n", n, csrc, cdest);
}
