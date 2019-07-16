#include <stdio.h>
#include <stdlib.h>

#include "arraysort.h"
/**
 * This function creates an empty list, with space allocated for an array of
 * maxElements ints (pointed to by int *sortedList) and returns a pointer to the
 * list.
 */
list* createlist(int maxElements)
{
   //create a list struct
   list* emptyList = (list*)malloc(sizeof(list));
   //determine if pointer is null
   if(emptyList == NULL){
      printf("list allocate failed\n");
      return NULL;
   }
   //allocate for sortedList
   emptyList->sortedList = (int*)malloc(sizeof(int)*maxElements); 
   if(emptyList->sortedList == NULL){
     printf("sortedList allocate failed\n");
     return NULL;
   } 
   //initialize
   emptyList->size = 0;
   emptyList->maxSize = maxElements;
   return emptyList;
}

/**
 * This function takes a pointer to the list and an integer value as input. It
 * should insert the value 'val' into sortedList, update the number of elements
 * in the list and return the index where the element was inserted. If the list
 * is full before inserting the element, it should increase the size of the list
 * to double its previous size and then insert the element. If the result of the
 * insert was not successful it should return -1. Note that the resulting list
 * should be sorted and there should be no information loss. The function should
 * return -1 if no valid list was passed to it..
 */
int insert(list *ls, int val)
{ 
   //if value is negative, return -1
   if(val < 0)
     return -1;
   //if list is null, return -1
   if(ls == NULL)
     return -1;
    //if list is full, increase the size
   if(ls->size == ls->maxSize)
   {
    //increase the size
       int *p = ls->sortedList;
       ls->sortedList = (int*)realloc(ls->sortedList,sizeof(int)*2*(ls->maxSize));
       if(ls->sortedList == p)
          p = NULL;
       if(ls->sortedList == NULL){
          printf("reallocate failed\n");
          return -1;
       }
       ls->maxSize*=2;  
   } 
   int i;
   //find the right index to insert
   for(i=0; i < ls->size; i++){
      if(val <=  *(ls->sortedList+i))
        break;
   }      
   int index = i;
   //move every element backwards
   for(i = ls->size-1; i >= index; i--){
      *(ls->sortedList+i+1) = *(ls->sortedList+i);
   }
   //insert value
   *(ls->sortedList+index) = val;
   ls->size++;
   return index;
}


/**
 * This function takes a pointer to the list and an integer value as input. It
 * should delete all instances of elements in the sortedList with value 'val',
 * update the number of elements remaining in the list and return the number of
 * elements that were deleted. Once again the resulting list should be sorted.
 */
int remove_val(list *ls, int val)
{
    int i;
    int endIndex;
    int startIndex;
    int count = 0;
    //find the first value's index
    for(i = 0; i < ls->size; i++){
        if(*(ls->sortedList+i) == val){
            startIndex = i;
            endIndex = i;
            count++;
            break; 
        } 
    }
   //if not fount, return zero
    if(count == 0)
        return 0;
    //find last index of value
    for(i = startIndex+1; i < ls->size; i++){
        if(*(ls->sortedList+i) == val){
            endIndex = i;
            count++;
        }
    }
    int j;
    //move every element forwards
    for(i = endIndex+1, j=startIndex; i < ls->size; i++, j++){
        *(ls->sortedList+j) = *(ls->sortedList+i);
    }   
    ls->size -= count;
    return count; 
    
}

/**
 * This function takes a pointer to the the list as input and returns the
 * maximum value in the list OR -1 if the list is empty.
 */
int get_max_value(list *ls)
{
    //if list is empty, return -1
    if(ls->size == 0)
        return -1;
    return *(ls->sortedList+ls->size-1);
}

/**
 * This function takes a pointer to the list and returns the minimum value in
 * the list OR -1 if the list is empty.
 */
int get_min_value(list *ls){
   //if list is empty, return -1
   if(ls->size == 0)
        return -1;
   return *(ls->sortedList);
}

/**
 * This function returns the index of the first occurrence of 'val' in the
 * list. It returns -1 if the value 'val' is not present in the list.
 */
int search(list *ls, int val){
   int i;
   //search the index
   for(i = 0; i < ls->size; i++){
        if(val == *(ls->sortedList+i)){
             return i;   
        }        
   }
   
   return -1;

}

/**
 * This function returns the minimum value from the list and removes it from the
 * list. It returns -1 if the list is empty.
 */
int pop_min(list *ls){
   //if list is empty, return -1
   if(ls->size == 0)
       return -1;
   int min = *(ls->sortedList);
   int i;
   //move forwards
   for(i = 0; i < ls->size-1;i++){
       *(ls->sortedList+i) = *(ls->sortedList+i+1);
   }
   ls->size--;
   return min;

}

/**
 * This function print the contents of the sorted list on a single line as follows:
 * 1 4 6 7 8
 */
void print(list *ls){
   int i;
   //print out all the elements
   for(i = 0; i < ls->size; i++){
       printf("%d ",*(ls->sortedList+i));
  
   }
   printf("\n");

}


/**
 * Identical to get_min_value(), but implemented in ARM assembly
 * (use given file get_min_ARM.s)
 */
int get_min_ARM(list *ls);

/**
 * Identical to get_max_value(), but implemented in ARM assembly
 * (use given file get_max_ARM.s)
 */
int get_max_ARM(list *ls);
