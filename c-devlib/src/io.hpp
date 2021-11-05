/*
    This contains helper functions used across app/bsp/libraries to debug and test aplication

*/

#pragma once
#include "stdint.h"
#include "stdio.h"

inline static void Error_Handler_(const char *file, int line)
{
    printf("Error: file %s on line %d\r\n", file, line);
}

inline char Debug_getchar(void)
{
    char input;
    scanf(" %c", &input);

    return input;
}

inline uint32_t Debug_gethex(void)
{
    int input;
    scanf(" %x", &input);

    return input;
}

#define PRINT_LVL1(fmt, ...)                   \
    do                                         \
    {                                          \
        if (USE_DEVLIB_PRINT && PRINT_LVL1_ON) \
        {                                      \
            printf("LVL1:");                   \
            printf(fmt, __VA_ARGS__);          \
            fflush(stdout);                    \
        }                                      \
    } while (0)

#define PRINT_LVL2(fmt, ...)                   \
    do                                         \
    {                                          \
        if (USE_DEVLIB_PRINT && PRINT_LVL2_ON) \
        {                                      \
            printf("LVL2:");                   \
            printf(fmt, __VA_ARGS__);          \
            fflush(stdout);                    \
        }                                      \
    } while (0)

#define PRINT_LVL3(fmt, ...)                   \
    do                                         \
    {                                          \
        if (USE_DEVLIB_PRINT && PRINT_LVL3_ON) \
        {                                      \
            printf("LVL3:");                   \
            printf(fmt, __VA_ARGS__);          \
            fflush(stdout);                    \
        }                                      \
    } while (0)

#define ERROR_HANDLER()                         \
    do                                          \
    {                                           \
        if (USE_DEVLIB_PRINT)                   \
        {                                       \
            Error_Handler_(__FILE__, __LINE__); \
        }                                       \
    } while (0)
