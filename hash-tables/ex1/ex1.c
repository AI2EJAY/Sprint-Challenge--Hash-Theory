#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  typedef struct Answer {  //struct meant to contain pairs of weights
    int value1;
    int value2;
  } Answer;

  for (int i=1; i > length-1; i++) {
    int first = 0; 
    int sum = weights[first] + weights[i];

    Answer *combo = malloc(sizeof(Answer)); // create instance of Key
    combo->value1 = weights[first];
    combo->value2 = weights[i];
    hash_table_insert(ht, sum, combo);

    if (i == length-1) {
      first += 1;
      i = first + 1;
    }

  }
  if (hash_table_retrieve(ht, limit) != NULL) {
    if (ht->storage->limit->value1 < ht->storage->limit->value2) {
      int temp = 0;
      temp = ht->storage->limit->value1;
      ht->storage->limit->value1 = ht->storage->limit->value2;
      ht->storage->limit->value2 = temp;
    }
  } else {
    return NULL;
  }
    return hash_table_retrieve(ht, limit)

}



void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}