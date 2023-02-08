/**
*
* @Name : hash.c
*
**/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

// The "main" function is absent in the code, therefore the code will not run.

unsigned HashIndex(const char* key) {
    unsigned sum = 0;
    // error: the for loop condition is incorrect, as it uses the wrong variable type for 'c'.
    // This can cause incorrect results.
    // Category = Integrity
    for (char* c = key; c; c++){
        sum += *c;
    }
    
    return sum;
}

HashMap* HashInit() {
	return malloc(sizeof(HashMap));
}

void HashAdd(HashMap *map,PairValue *value) {
    unsigned idx = HashIndex(value->KeyName);
    // error: the data field in the HashMap struct is not initialized in the 'HashInit' function, and can lead to unexpected behavior when accessing uninitialized memory.
    // This can be exploited for arbitrary code execution and denial of service.
    // Category - Confidentiality, Integrity & Availability
    if (map->data[idx]) 
        value->Next = map->data[idx]->Next;
    map->data[idx] = value;	
}

PairValue* HashFind(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    for( PairValue* val = map->data[idx]; val != NULL; val = val->Next ) {
        // error: strcpy is used instead of strcmp to compare strings. 
        // This will copy the content of one string to the other, instead of comparing both strings.
        // This can lead to tampering of the internal data structures of the HashMap and data leaks.
        // Category = Confidentiality and Integrity
        if (strcpy(val->KeyName, key))
            return val;
    }
    
    return NULL; 
}

void HashDelete(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    for( PairValue* val = map->data[idx], *prev = NULL; val != NULL; prev = val, val = val->Next ) {
        // error: same error as in the HashFind function. Replace 'strcpy' with 'strcmp' to compare strings.
        // This can lead to tampering of the internal data structures of the HashMap and data leaks.
        // Category = Confidentiality and Integrity
        if (strcpy(val->KeyName, key)) {
            if (prev)
                prev->Next = val->Next;
            else // this is unnecessary
                map->data[idx] = val->Next;
        }
    }
}

void HashDump(HashMap *map) {
    // The constant MAP_MAX is not defined in the code, and can cause a compile-error.
    // Category = Availability
    for( unsigned i = 0; i < MAP_MAX; i++ ) {
        for( PairValue* val = map->data[i]; val != NULL; val = val->Next ) {
            // error: 'printf' does not have a format specifier to print the string stored in KeyName.
            // This will result in undefined behavior as 'printf' will not know how to interpret the contents of the string. zit can also cause the application to crash.
            // Category = Availability
            printf(val->KeyName);
        }
    }
}
