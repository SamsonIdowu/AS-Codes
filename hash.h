/**
*
* @Name : hash.h
*
**/
#ifndef __HASH__
#define __HASH__

    typedef struct {
        #define KEY_STRING_MAX 255
		char KeyName[KEY_STRING_MAX];
		int  ValueCount;
        // error: struct 'PairValue*' has not been defined yet. This can lead to a compile error.
        // This can cause undefined behavior and potential crashes.
        // Category = Availability
        struct PairValue* Next;
	} PairValue;

	typedef struct {
        #define MAP_MAX 128
        // error: the data array not initialized, so accessing the elements of the array will result in undefined behavior.
		// This can cause arbitrary code execution.
        // Category - Configdentiality, Integrity & Availability
        PairValue* data[MAP_MAX];
	} HashMap;

    // error: missing return type and argument types in below Hash functions which can lead to a compile error.
    // This can lead to type mismatches and unexpected behavior and can be further exploited for arbitrary code execution.
    // Category - Configdentiality, Integrity & Availability
    HashMap* HashInit();
    void HashAdd(HashMap *map, PairValue *value);
    void HashDelete(HashMap *map, const char* key);
    PairValue* HashFind(HashMap *map, const char* key);
    void HashDump(HashMap *map);
#endif
