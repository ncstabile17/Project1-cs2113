#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

struct LList* createLList() {
  /* Create an empty linked list. */
  /* DO NOT MODIFY THIS CODE */
  struct LList* list = malloc(sizeof(struct LList));
  list->head = NULL;
  return list;
}

void printList(struct LList *list)
{
  /* Print a list from head to tail. */
  /* DO NOT MODIFY THIS CODE */
  struct LNode *entry;
  if(list == NULL) {
    printf("List has not been initialized!\n");
    return;
  }
  entry = list->head;
  printf("List Contents:\n");
  while(entry != NULL)
  {
    printf("  %s is at %f, %f\n", entry->name, entry->latitude, entry->longitude);
    entry = entry->next;
  }
}


int addNode(struct LList *list, char* name, double lat, double lon) {
  /*  Add a new entry to the linked list. 
      Return the index number of the new entry 
  */

  return 0;
}


int remNode(struct LList *list, char* name)
{
  /*  Removes the element named "name" from the list, if it exists.
      Returns the index of the element removed.
  */
  return 0;
}

int addSortedNode(struct LList *list, char* name, double lat, double lon)
{
  /*  Add a point to the list, sorted by longitude in ascending order. 
      Returns the position of the new point.
  */
  return 0;
}

int clearList(struct LList *list) 
{
  /* Delete list and free all of the memory associate with its LNodes. */
  return 0;
}
