#include <iostream>
#include "file_reader.h"
#include "constants.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №8. GIT\n";
    cout << "Вариант №7. Банковские операции\n";
    cout << "Автор: Лисов Максим\n\n";
    bank_operation* operations[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", operations, size);
        for (int i = 0; i < size; i++)
        {
            cout << operations[i]->operation_date.day << '.';
            cout << operations[i]->operation_date.month << '.';
            cout << operations[i]->operation_date.year << ' ';
            cout << operations[i]->operation_hour << ':';
            cout << operations[i]->operation_minute << ' ';
            cout << operations[i]->account_type << ' ';
            cout << operations[i]->amount << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete operations[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}