#include "ai_vector.h"
#include "object/ai_object_internal.h"

#include <stdlib.h>
#include <stddef.h>

struct _ai_vector {
    AI_OBJECT_DECLARE;

    ai_object_ref *objects;

    size_t count;
    size_t capacity;
};

static void ai_vector_resize(ai_vector_ref vector, size_t capacity) {
    ai_object_ref *objects = malloc(sizeof(ai_object_ref) * capacity);

    for (size_t i = 0; i < capacity; ++i) {
        objects[i] = vector->objects[i];
    }

    free(vector->objects);
    vector->objects = objects;
    vector->capacity = capacity;
}

static void ai_vector_destructor(void *_vector) {
    ai_vector_ref vector = _vector;

    for (size_t i = 0; i < vector->count; ++i) {
        ai_release(vector->objects[i]);
    }
}

ai_vector_ref ai_create_vector() {
    ai_vector_ref vector = ai_create_object(sizeof(ai_vector), ai_vector_destructor);

    vector->count = 0;
    vector->capacity = 16;
    vector->objects = malloc(sizeof(ai_object_ref) * vector->capacity);

    return vector;
}

void ai_vector_add(ai_vector_ref vector, void *_object) {
    ai_object_ref object = _object;

    ai_retain(object);
    vector->objects[vector->count++] = object;

    if (vector->count == vector->capacity) {
        ai_vector_resize(vector, vector->capacity * 2);
    }
}

size_t ai_vector_count(ai_vector_ref vector) {
    return vector->count;
}
