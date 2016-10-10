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

 // allocate memory for new Node
  struct LNode* newNode = malloc(sizeof(struct LNode));
 // fill data into new Node
  newNode->name = name;
  newNode->latitude = lat;
  newNode->longitude = lon;
  newNode->next = NULL;

  int index = 0;

  if(list->head == NULL) {
    list->head = newNode;
    return index;
  }

  else if (list->head != NULL) {
    struct LNode* currNode = malloc(sizeof(struct LNode));
    currNode = list->head;
    currNode->next = list->head->next;
    //step through list incrementing index each time through loop until we reach end
    while (currNode->next != NULL) {
      currNode = currNode->next;
      index++;
    }
    currNode->next = newNode;
    index++;
    //set last entry's next pointer = newNode
    return index;

  else 
    return -1;
  }
  
}


int remNode(struct LList *list, char* name)
{
  /*  Removes the element named "name" from the list, if it exists.
      Returns the index of the element removed.
  */
  if(list->head == NULL) {
    return -1;
  }
  else {
    struct LNode* currNode = malloc(sizeof(struct LNode));
    struct LNode* prevNode = malloc(sizeof(struct LNode));
    currNode = list->head;
    currNode->next = list->head->next;
    //step through list incrementing index each time through loop until we reach end
    int isValue; 
    int index = 0;
    isValue = strcmp(currNode->name, name);

    while (isValue != 0 && currNode!= NULL) {
      prevNode = currNode;
      currNode = currNode->next;
      isValue = strcmp(currNode->name, name);
      index++;
    }

    if (currNode == NULL) {
      return -1;
    }

    prevNode->next = currNode->next;
    free(currNode);

    return index;
  }

}

int addSortedNode(struct LList *list, char* name, double lat, double lon)
{
  /*  Add a point to the list, sorted by longitude in ascending order. 
      Returns the position of the new point.
  */

   // allocate memory for new Node
  struct LNode* newNode = malloc(sizeof(struct LNode));
 // fill data into new Node
  newNode->name = name;
  newNode->latitude = lat;
  newNode->longitude = lon;
  newNode->next = NULL;

  int index = 0;

  if(list->head == NULL) {
    list->head = newNode;
    return index;
  }

  else if (list->head != NULL) {
    struct LNode* currNode = malloc(sizeof(struct LNode));
    struct LNode* prevNode = malloc(sizeof(struct LNode));

    currNode = list->head;
    currNode->next = list->head->next;
    //step through list incrementing index each time through loop until we reach end
    while ((newNode->longitude > currNode->longitude) && currNode->next!= NULL) {
      printf("line 139: %s\n", currNode->name);
      prevNode = currNode;
      currNode = currNode->next;
      printf("line 142: %s\n", currNode->name);
      index++;
    }
    
    if (currNode == list->head) {
    
    list->head = newNode;
    newNode->next = currNode;
    printf("newNode: %s, currNode: %s, prevNode: %s\n", newNode->name, currNode->name, prevNode->name);
    printList(list);

    return index;
    }
    
    if (currNode->next == NULL) {
      if (currNode->longitude >= newNode->longitude) {
        prevNode->next = newNode;
        newNode->next = currNode;
      }
      else {
        currNode->next = newNode;
        newNode->next = NULL;
      }
    }
   
    else {
      prevNode->next = newNode;
      newNode->next = currNode;
      printf("newNode: %s, currNode: %s, prevNode: %s, prevNode->next: %s\n", newNode->name, currNode->name, prevNode->name, prevNode->next->name);

      return index;
    }
  }

  else 
    return -1;
  

}

int clearList(struct LList *list) 
{
  /* Delete list and free all of the memory associate with its LNodes. */
  return 0;
}
