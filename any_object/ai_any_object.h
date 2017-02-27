#ifndef _ANY_OBJECT_CONTAINER_H_
#define _ANY_OBJECT_CONTAINER_H_

#include "object/ai_object.h"
#include <stdbool.h>

typedef struct _ai_any_object ai_any_object;
typedef ai_any_object* ai_any_object_ref;

ai_any_object_ref ai_create_any_object(void*, bool);
void* ai_any_object_get(ai_any_object_ref);

#endif // _ANY_OBJECT_CONTAINER_H_
