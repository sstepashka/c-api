#include "vector/ai_vector.h"
#include "any_object/ai_any_object.h"

#define UNUSED(x) (void)x;

int main(int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    ai_vector_ref vector = ai_create_vector();

    for (size_t i = 0; i < 100; ++i) {
        ai_any_object_ref any_object = ai_create_any_object((void*)i, false);
        ai_vector_add(vector, any_object);
        ai_release(any_object);
    }

    ai_release(vector);

    return 0;
}
