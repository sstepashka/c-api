#include "ai_any_object.h"
#include "object/ai_object_internal.h"

#include <stdio.h>
#include <stdlib.h>

struct _ai_any_object {
    AI_OBJECT_DECLARE;

    void* pointer;
    bool free_on_release;
};

static void ai_any_object_destructor(void *_any_object) {
    ai_any_object_ref any_object = _any_object;

    if (any_object->free_on_release) {
        free(any_object->pointer);
    }

    (void)any_object;
}

ai_any_object_ref ai_create_any_object(void* _pointer, bool free_on_release) {
    ai_any_object_ref any_object = ai_create_object(sizeof(ai_any_object), ai_any_object_destructor);

    any_object->pointer = _pointer;
    any_object->free_on_release = free_on_release;

    return any_object;
}

void* ai_any_object_get(ai_any_object_ref any_object) {
    return any_object->pointer;
}
