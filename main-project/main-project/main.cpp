#include <iostream>
#include <iomanip>
#include "bank_operations.h"
#include "file_reader.h"
#include "constants.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №8. GIT\n";
    cout << "Вариант №7. Банковские операции\n";
    cout << "Автор: Максим Лисов\n\n";
    bank_operation* operations[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("operations.txt", operations, size);
        cout << "***** Банковские операции *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод информации о банковской операции **********/
            cout << "Дата: " << setw(2) << setfill('0') << operations[i]->date.day << '.'
                << setw(2) << setfill('0') << operations[i]->date.month << '.'
                << setw(4) << setfill('0') << operations[i]->date.year << '\n';
            cout << "Время: " << setw(2) << setfill('0') << operations[i]->time.hours << ':'
                << setw(2) << setfill('0') << operations[i]->time.minutes << ':'
                << setw(2) << setfill('0') << operations[i]->time.seconds << '\n';
            cout << "Тип счета: " << operations[i]->account_type << '\n';
            cout << "Сумма: " << operations[i]->amount << '\n';
            cout << '\n';
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