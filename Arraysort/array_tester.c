// Put your name(s) and PID(s) here and a quick summary of what this does here
//Peiran Li A92036065
//Ziang Jing A92010328
//This is a tester for arraysort.c file. It tests 8 methods in that file.
//It tests all cases in that file.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraysort.h"


void test_createlist(){
    //create an emptylist which maxSize is 5
    list* emptylist = createlist(5);
    //check the 3 properties of emptyList
    assert(emptylist->sortedList != NULL);
    assert(emptylist->size == 0);
    assert(emptylist->maxSize == 5);
    //free the list
    free(emptylist->sortedList);
    free(emptylist);
}

void test_insert(){
    //prepare a testlist
    list* testlist = createlist(3);
    assert(testlist->maxSize == 3);
    
    //check if the list is empty
    int index = insert(testlist,-2);
    assert(index==-1);
    assert(testlist->size == 0);
    assert(testlist->maxSize==3);
    
    //check common case of insert
    index = insert(testlist,3);
    assert(index==0);
    assert(*(testlist->sortedList) == 3);
    assert(testlist->size == 1);
    
    index = insert(testlist,4);
    assert(index==1);
    assert(*(testlist->sortedList+1) == 4);
    assert(testlist->size == 2);
    
    index = insert(testlist,2);
    assert(index==0);
    assert(*(testlist->sortedList) == 2);
    assert(*(testlist->sortedList+1) == 3);
    assert(*(testlist->sortedList+2) == 4);
    assert(testlist->size == 3);
    
    //check if the list is full
    index = insert(testlist,6);
    assert(index=3);
    assert(*(testlist->sortedList+3) == 6);
    assert(testlist->size == 4);
    assert(testlist->maxSize == 6);
    
    //free the list
    free(testlist->sortedList);
    free(testlist);
}

void test_remove_val(){
    //prepare a testlist
    list* testlist = createlist(6);
    insert(testlist,3);
    insert(testlist,2);
    insert(testlist,7);
    insert(testlist,7);
    insert(testlist,4);
    insert(testlist,9);
    
    //check if the list is created correctly
    assert(testlist->size==6);
    assert(*(testlist->sortedList) == 2);
    assert(*(testlist->sortedList+1) == 3);
    assert(*(testlist->sortedList+2) == 4);
    assert(*(testlist->sortedList+3) == 7);
    assert(*(testlist->sortedList+4) == 7);
    assert(*(testlist->sortedList+5) == 9);
    
    //test if try to remove an element in the list
    int removedNum = remove_val(testlist,7);
    assert(removedNum==2);
    assert(testlist->size==4);
    assert(*(testlist->sortedList) == 2);
    assert(*(testlist->sortedList+1) == 3);
    assert(*(testlist->sortedList+2) == 4);
    assert(*(testlist->sortedList+3) == 9);
    
    //test if try to remove an element not in the list
    removedNum = remove_val(testlist,100);
    assert(removedNum==0);
    assert(testlist->size==4);
    assert(*(testlist->sortedList) == 2);
    assert(*(testlist->sortedList+1) == 3);
    assert(*(testlist->sortedList+2) == 4);
    assert(*(testlist->sortedList+3) == 9);
    //free the list
    free(testlist->sortedList);
    free(testlist);
}

void test_get_max_value(){
    //prepare an emptylist
    list* testlist = createlist(6);
    
    //test if want to get max value from an empty list
    int max = get_max_value(testlist);
    assert(max==-1);
    
    //prepare a list with elements in it
    insert(testlist,3);
    insert(testlist,2);
    insert(testlist,7);
    insert(testlist,7);
    insert(testlist,4);
    insert(testlist,9);
    
    //test get max value when the list is not empty
    max = get_max_value(testlist);
    assert(max==9);
    
    //free the list
    free(testlist->sortedList);
    free(testlist);
}

void test_get_min_value(){
    //prepare an emptylist
    list* testlist = createlist(6);
    
    //test if want to get min value from an empty list
    int min = get_min_value(testlist);
    assert(min==-1);
    
    //prepare a list with elements in it
    insert(testlist,3);
    insert(testlist,2);
    insert(testlist,7);
    insert(testlist,7);
    insert(testlist,4);
    insert(testlist,9);
    //test get min value when the list is not empty
    min = get_min_value(testlist); 
    assert(min==2);
    
    //free the list
    free(testlist->sortedList);
    free(testlist);

}

void test_search(){
    //prepare a testlist
    list* testlist = createlist(6);
    insert(testlist,3);
    insert(testlist,2);
    insert(testlist,7);
    insert(testlist,7);
    insert(testlist,4);
    insert(testlist,9);
    
    //test when try to search an element in the list
    int index = search(testlist,7);
    assert(index==3);

    //test when tru to search an element not in the list
    index = search(testlist,100);
    assert(index==-1);

    //free the list
    free(testlist->sortedList);
    free(testlist);
}


void test_pop_min(){
    //prepare an empty list
    list* testlist = createlist(6);
    
    
    //test when try to pop min from an emptylist
    int minVal = pop_min(testlist);
    assert(minVal==-1);
    
    //prepare a list with elements
    insert(testlist,3);
    insert(testlist,2);
    insert(testlist,7);
    insert(testlist,7);
    insert(testlist,4);
    insert(testlist,9);
    
    //test pop min from a list with elements
    minVal = pop_min(testlist);
    assert(minVal == 2);
    
    minVal = pop_min(testlist);
    assert(minVal == 3);
    
    //free the list
    free(testlist->sortedList);
    free(testlist);
}

void test_print(){
    //prepare a testlist
    list* testlist = createlist(6);
    insert(testlist,3);
    insert(testlist,2);
    insert(testlist,7);
    insert(testlist,7);
    insert(testlist,4);
    insert(testlist,9);
   
    //compare the two lists printed out
    printf("The print() method prints: ");
    print(testlist);
    printf("It should print: ");
    printf("2 3 4 7 7 9 ");
    
    //free the list
    free(testlist->sortedList);
    free(testlist);
}





int main(void)
{
    //run all of the test cases
    test_createlist();
    test_insert();
    test_remove_val();
    test_get_max_value();
    test_get_min_value();
    test_search();
    test_pop_min();
    test_print();
    
    return 0;
}
