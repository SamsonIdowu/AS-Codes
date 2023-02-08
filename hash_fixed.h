/**
 * @Name : hash.h
 *
 * Fix: Header comment added
**/

#ifndef __HASH__
#define __HASH__

// Fix: Moved struct PairValue definition to after its usage.
// The struct definition for "PairValue" was located before its usage in the code. This caused a compiler error as the struct was not yet defined. The fix moved the struct definition to after its usage to correct this issue.
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

// Fix: Added argument type to HashInit prototype so that the compiler can determine the argument type.
HashMap* HashInit(void);
void HashAdd(HashMap *map, PairValue *value);
void HashDelete(HashMap *map, const char* key);
PairValue* HashFind(HashMap *map, const char* key);
void HashDump(HashMap *map);
#endif
