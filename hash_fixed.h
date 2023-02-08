/**
 * @Name : hash.h
 *
 * Fix: Header comment added
**/

#ifndef __HASH__
#define __HASH__

// Fix: Moved struct PairValue definition to after its usage
typedef struct PairValue PairValue;
struct PairValue {
    #define KEY_STRING_MAX 255
    char KeyName[KEY_STRING_MAX];
    int  ValueCount;
    PairValue* Next;
};

typedef struct {
    #define MAP_MAX 128
    PairValue* data[MAP_MAX];
} HashMap;

// Fix: Added argument types to HashInit prototype
HashMap* HashInit(void);
void HashAdd(HashMap *map, PairValue *value);
void HashDelete(HashMap *map, const char* key);
PairValue* HashFind(HashMap *map, const char* key);
void HashDump(HashMap *map);
#endif
