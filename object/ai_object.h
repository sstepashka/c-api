#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <stdint.h>
#include <stddef.h>

typedef uint32_t ai_counter_type;

typedef struct _ai_object ai_object;
typedef ai_object* ai_object_ref;

typedef void (*ai_destructor)(void*);

void* ai_create_object(size_t size, ai_destructor);

void* ai_retain(void* object);
void ai_release(void* object);

#endif // _OBJECT_H_
