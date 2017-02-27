#ifndef _OBJECT_INTERNAL_H_
#define _OBJECT_INTERNAL_H_

#define ATOMIC_AVAILABLE __has_include(<stdatomic.h>)

#if ATOMIC_AVAILABLE
    #include <stdatomic.h>
    #define ATOMIC_ATTRIBUTE _Atomic
#else
    #define ATOMIC_ATTRIBUTE
#endif

typedef void* (*ai_retain_func)(void*);
typedef void (*ai_release_func)(void*);

struct _ai_object {
    ai_retain_func retain;
    ai_release_func release;

    ai_destructor destructor;

    ATOMIC_ATTRIBUTE ai_counter_type counter;
};

#define AI_OBJECT_DECLARE struct _ai_object object

#endif // _OBJECT_INTERNAL_H_
