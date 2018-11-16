#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *hash = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));
  
  for (int i = 0; i < length; i++) {
    hash_table_insert(hash, tickets[i]->source, tickets[i]->destination);
    }

    // right track but not this
    route[0] = hash_table_retrieve(hash, "NONE");
    for(int i = 1; i < length; i++) {
    int start = 0;
    route[i] = hash_table_retrieve(hash, route[start]);
    if (strcmp(route[i], "NONE")) {
      break;
    }
    start += 1;

    }
    
  printf("%s\n", route);
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}