#include <stdarg.h>
#include <stdio.h>

#define sg_debug(...) {\
        do {\
                printf("[%s:%s:%d] ", __FILE__, __func__, __LINE__); \
                printf(__VA_ARGS__);    \
        } while(0); \
}

