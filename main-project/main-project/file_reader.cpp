#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

date convert(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

void read(const char* file_name, bank_operation* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            bank_operation* item = new bank_operation;
            file >> tmp_buffer;
            item->operation_date = convert(tmp_buffer);
            file >> item->operation_hour;
            file >> item->operation_minute;
            file >> item->account_type;
            file >> item->amount;
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}