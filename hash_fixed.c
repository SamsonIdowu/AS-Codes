/**
*
* @Name : hash_fixed.c
*
**/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_fixed.h"

int main(){

unsigned HashIndex(const char* key) {
    unsigned sum = 0;
    // corrected the variable type of `c` to `const char*` so as to  tch the type of argument 'key'
    for (const char* c = key; *c; c++){
        sum += *c;
    }
    
    return sum;
}

HashMap* HashInit() {
    // created a variable to hold the returned pointer and initialize the 'data' field
    HashMap* map = malloc(sizeof(HashMap));
    if (!map) {
        // handle error: malloc failed
    }
    // zero out the memory
    memset(map, 0, sizeof(HashMap)); 
    return map;
}

void HashAdd(HashMap *map,PairValue *value) {
    unsigned idx = HashIndex(value->KeyName);
    
    // Set value->Next to map->data[idx] instead of map->data[idx]->Next to add the value
    // This initializes the HashMap struct
    value->Next = map->data[idx];
    map->data[idx] = value;	
}

PairValue* HashFind(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    for( PairValue* val = map->data[idx]; val != NULL; val = val->Next ) {
        // used `strcmp` to compare strings instead of `strcpy`
        // 'strcmp' will compare both strings and return 0 if they are equal.
        if (!strcmp(val->KeyName, key))
            return val;
    }
    
    return NULL; 
}

void HashDelete(HashMap *map, const char* key) {
    unsigned idx = HashIndex(key);
    
    PairValue* prev = NULL;
    for( PairValue* val = map->data[idx]; val != NULL; prev = val, val = val->Next ) {
        // used `strcmp` to compare strings instead of `strcpy`
        // 'strcmp' will compare both strings and return 0 if they are equal.
        if (!strcmp(val->KeyName, key)) {
            if (prev)
                prev->Next = val->Next;
            else
                map->data[idx] = val->Next;
        }
    }
}

void HashDump(HashMap *map) {
    for( unsigned i = 0; i < MAP_MAX; i++ ) {
        for( PairValue* val = map->data[i]; val != NULL; val = val->Next ) {
            // added format specifier for `printf`
            // The printf will be able to interpret the content of the string since a format is now specified
            printf("%s\n", val->KeyName);
        }
    }
}
}