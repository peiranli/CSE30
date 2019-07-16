/* ********************************
 * CSE 30 - HW 3
 * ********************************/

#include <stdio.h>
#include "substring.h"
#include <assert.h>
int main() {
    // put your test code here
    assert(substring("CSE30","In hexspeak, CSE30 is 0xC5E30") == 1);
    assert(substring("raspberry","RASPBERRY PI") == 0);
    assert(substring("pi","ip") == 0);
    assert(substring("asasd","asd")== 1);
    assert(substring("caisfdb","caisfdb"));
    printf("all tests passed!\n");
    return 0;
}
