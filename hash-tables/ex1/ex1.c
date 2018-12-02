#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  // YOUR CODE HERE
  Answer *sum = malloc(sizeof(Answer));
  for (int i = 0; i < length; i++)
  {
    hash_table_insert(ht, weights[i], i);
    // printf("loop at %d\n", i);
  }
  for (int i = 0; i < length; i++)
  {
    // printf("last loop at %d\n", i);
    int weight2 = hash_table_retrieve(ht, limit - weights[i]);
    if (weight2 != -1)
    {
    // printf("index of first %d, index of second %d\n", i, weight2);
      if (weights[i] <= weights[weight2])
      {
        sum->index_1 = weight2;
        sum->index_2 = i;
        return sum;
      }
      else
      {
      // printf("index of first %d, index of second %d\n", i, weight2);
        sum->index_1 = i;
        sum->index_2 = weight2;
        return sum;
      }
    }
  }
    return NULL;
}

// {
// printf("weight at index:  %d\n %d\n", weights[weight2], weights[j]);
//   if (weights[j] < weights[weight2])
//   {
//     sum->index_1 = weight2;
//     sum->index_2 = j;
//     return sum;
//   }
//   else
//   {
//     sum->index_1 = j;
//     sum->index_2 = weight2;
//     return sum;
//   }
// }
// }

// for (int i = 0; i > length - 1; i++)
// {
//   for (int j = 1; j > length; j++)
//   {
//     int solution = (weights[i] + weights[j]);
//     if (solution == limit)
//     {
//       if (weights[i] < weights[j])
//       {
//         sum->index_1 = hash_table_retrieve(ht, weights[j]);
//         sum->index_2 = hash_table_retrieve(ht, weights[i]);
//         printf("%d\n", sum->index_1);
//       }
//       else
//       {
//         sum->index_1 = hash_table_retrieve(ht, weights[i]);
//         sum->index_2 = hash_table_retrieve(ht, weights[j]);
//         printf("%d\n", sum->index_1);
//       }
//     }
//   }
// }

// int running = 1;
//   int sum = 0;
//   int i=1;
//   int insum= hash_table_retrive(ht, weights[sum]);
//   int ini= hash_table_retrive(ht, weights[i]);
// while(running) {
//   if ((weights[sum] += weights[i]) == limit) {

//       if (insum < ini) {
//         Answer *answers;
//         answers->index_1 =
//       }
// //       answer->index_1 =

//       }
//   } else if (i > limit) {
//     sum+=1;
//     i=sum+1;
//   } else

// }

// if ht->storage[i]
void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1); // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer *answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2); // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer *answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3); // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer *answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4); // {6, 2}

  return 0;
}
#endif

// #include <stdio.h>
// #include <stdlib.h>
// #include "hashtable.h"
// #include "ex1.h"

// Answer *get_indices_of_item_weights(int *weights, int length, int limit)
// {
//   HashTable *ht = create_hash_table(16);

//   // typedef struct Answer {  //struct meant to contain pairs of weights
//   //   int value1;
//   //   int value2;
//   // } Answer;
//     Answer *combo = malloc(sizeof(Answer)); // create instance of Key
//      printf("=Answer malloc'd\n");
//   int first = 0;
//   for (int i=1; i < length; i++) {
//     int sum = weights[first] + weights[i];
//     printf("===insertion at i:%d OK\nsum:%d OK\n", i, sum);
//     combo->index_1 = first > i ? first : i;
//     combo->index_2 = first < i ? first : i;
//     printf("=index_1: %d, index_2: %d\n", combo->index_1, combo->index_2);
//     /*
//     [1, 2, 3]
//     First loop
//     1 = 1, 1 < 3 - 1
//     sum = 1 + 2
//     value1 = 1
//     value2 = 2
//     insert { 3, { 1, 2 }}
//     Second loop
//     i = 2, 2 < 3
//     sum = 1 + 3
//     value1 = 1
//     value2 = 3
//     insert { 4, {1, 3} }
//     ---
//     first = 1
//     i = 2
//     ---
//     Third loop
//     i = 2, 2 < 3
//     sum = 2 + 3
//     value1 = 2
//     value2 = 3
//     insert { 5, {2, 3}}
//     ---
//     first = 2
//     i = 3
//     ---
//     Fourth loop
//     i = 3, 3 < 3
//     Done
//     */
//     hash_table_insert(ht, sum, combo);
//     printf("=insertion successful @ i:%d\n", i);
//     if (i == length-1) {
//       first += 1;
//       i = first + 1;
//       printf("=we in this if-statement\n==first: %d i: %d\n", first, i);
//     }
//     printf("reached end of loop @ i:%d\n", i);
//   }
//   // int searchedSum = hash_table_retrieve(ht,limit);
//   // if (searchedSum != NULL) {
//   //   if (ht->storage[limit]->key->value1 < ht->storage[limit]->key->value2) {
//   //     int temp = 0;
//   //     temp = ht->storage[limit]->key->value1;
//   //     ht->storage[limit]->key->value1 = ht->storage[limit]->key->value2;
//   //     ht->storage[limit]->key->value2 = temp;
//   //   }

//   // } else {
//   //   return NULL;
//   // }
//     printf("about to return! limit is %d\n", limit);
//     print_answer(hash_table_retrieve(ht, limit));
//     return hash_table_retrieve(ht, limit);

// }

// void print_answer(Answer *answer)
// {
//   if (answer != NULL) {
//     printf("%d %d\n", answer->index_1, answer->index_2);
//   } else {
//     printf("NULL\n");
//   }
// }