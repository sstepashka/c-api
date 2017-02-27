#include "ai_object.h"
#include "ai_object_internal.h"

#include <stdlib.h>

void* default_ai_retain(void* _object) {
    ai_object_ref object = (ai_object_ref)_object;

    #if ATOMIC_AVAILABLE
        atomic_fetch_add((_Atomic ai_counter_type *)&object->counter, 1);
    #else
        __sync_add_and_fetch((ai_counter_type *)&object->counter, 1);
    #endif

    return object;
}

void default_ai_release(void* _object) {
    ai_object_ref object = (ai_object_ref)_object;

    #if ATOMIC_AVAILABLE
        if (atomic_fetch_sub((_Atomic ai_counter_type *)&object->counter, 1) == 1) {
    #else
        if (__sync_sub_and_fetch((ai_counter_type *)&object->counter, 1) == 0) {
    #endif
            if (object->destructor) {
                object->destructor(object);
            }

            free(object);
    }
}

void* ai_create_object(size_t size, ai_destructor destructor) {
    ai_object_ref object = malloc(size);

    object->counter = 1;

    object->retain = default_ai_retain;
    object->release = default_ai_release;

    object->destructor = destructor;

    return object;
}

void* ai_retain(void* _object) {
    ai_object_ref object = (ai_object_ref)_object;
    return object->retain(object);
}

void ai_release(void* _object) {
    ai_object_ref object = (ai_object_ref)_object;
    object->release(object);
}
