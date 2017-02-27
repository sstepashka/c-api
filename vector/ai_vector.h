#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "object/ai_object.h"
#include <stdint.h>

typedef struct _ai_vector ai_vector;
typedef ai_vector* ai_vector_ref;

ai_vector_ref ai_create_vector();
void ai_vector_add(ai_vector_ref, void *);
size_t ai_vector_count(ai_vector_ref);

#endif // _VECTOR_H_
