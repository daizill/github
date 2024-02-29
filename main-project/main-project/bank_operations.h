#ifndef BANK_OPERATION_H
#define BANK_OPERATION_H

#include "constants.h"

struct date
{
    int day;
    int month;
    int year;
};

struct bank_operation
{
    date operation_date;
    int operation_hour;
    int operation_minute;
    char account_type[MAX_STRING_SIZE];
    float amount;
};

#endif