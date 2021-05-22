#include <stdint.h>

uint64_t microseconds = 0;
uint32_t milliseconds = 0;

uint64_t currentMicroseconds(void)
{
    return microseconds;
}

uint32_t currentMilliseconds(void)
{
    return milliseconds;
}