#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *hash = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));
  printf("=route malloc'd\n");
  for (int i = 0; i < length; i++) 
  {
    hash_table_insert(hash, tickets[i]->source, tickets[i]->destination);
    printf("=insertion at i:%d OK\n", i);
  }
  int start = 0;
  route[0] = hash_table_retrieve(hash, "NONE"); 
  printf("=origin retrieval successful\n");
  for(int i = 1; i < length ; i++) 
  {
    route[i] = hash_table_retrieve(hash, route[start]);
    printf("=retrieval at i:%d OK\n", i);
    if (strcmp(route[i], "NONE") == 0) 
    {
      printf("=aww shiieet strcmp condition TRUE at i:%d\n", i);
      break;
    }
    printf("=strcmp at i:%d OK\n", i);
    start += 1;
  }
  printf("%s\n", route);
  printf("printing this route shiiet OK\n");
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}

