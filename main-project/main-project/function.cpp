#include <iostream>
#include <vector>
#include <algorithm> // Добавлен заголовочный файл <algorithm> для std::sort

// Структура данных для хранения информации о банковской операции
struct BankOperation {
    std::string date;
    std::string time;
    std::string type;
    std::string account;
    double amount;
    std::string purpose;
};

// Функция для фильтрации данных
std::vector<BankOperation*> filterBankOperations(
    BankOperation* array[],
    int size,
    bool (*check)(BankOperation* element),
    int& result_size
) {
    std::vector<BankOperation*> result;
    result_size = 0;

    for (int i = 0; i < size; i++) {
        if (check(array[i])) {
            result.push_back(array[i]);
            result_size++;
        }
    }

    return result;
}

// Функция для проверки условия отбора
bool checkBankOperation(BankOperation* element) {
    // Пример условия отбора: выбираем только расходные операции
    return element->type == "расход";
}

// Функция для сортировки данных по возрастанию назначения платежа
void sortByPurpose(std::vector<BankOperation*>& data) {
    std::sort(data.begin(), data.end(), [](BankOperation* a, BankOperation* b) {
        return a->purpose < b->purpose;
        });
}

// Функция для сортировки данных по возрастанию номера счёта, внутри счёта по возрастанию вида операции,
// а внутри вида операции по убыванию суммы операции
void sortByAccountTypeAmount(std::vector<BankOperation*>& data) {
    std::sort(data.begin(), data.end(), [](BankOperation* a, BankOperation* b) {
        if (a->account != b->account) {
            return a->account < b->account;
        }
        else if (a->type != b->type) {
            return a->type < b->type;
        }
        else {
            return a->amount > b->amount;
        }
        });
}

int main() {
    // Пример использования функций filterBankOperations и сортировки

    // Создаем массив с исходными данными
    BankOperation op1 = { "01.11.21", "08:30", "приход", "123456", 500.00, "Зачисление зарплаты" };
    BankOperation op2 = { "03.11.21", "14:15", "расход", "789012", 200.00, "Оплата коммунальных платежей" };
    BankOperation op3 = { "05.11.21", "10:00", "приход", "345678", 1000.00, "Перевод от другого банка" };
    BankOperation* operations[] = { &op1, &op2, &op3 };
    int size = sizeof(operations) / sizeof(operations[0]);

    int resultSize;
    std::vector<BankOperation*> filteredData = filterBankOperations(operations, size, checkBankOperation, resultSize);

    // Сортировка данных по возрастанию назначения платежа
    sortByPurpose(filteredData);

    // Вывод результатов
    std::cout << "Результаты фильтрации и сортировки по возрастанию назначения платежа:\n";
    for (BankOperation* operation : filteredData) {
        std::cout << "Дата: " << operation->date << ", Время: " << operation->time
            << ", Вид: " << operation->type << ", Счёт: " << operation->account
            << ", Сумма: " << operation->amount << ", Назначение: " << operation->purpose << "\n";
    }

    // Сортировка данных по возрастанию номера счёта, внутри счёта по возрастанию вида операции,
    // а внутри вида операции по убыванию суммы операции
    Извините за путаницу.Ошибка, которую вы получаете, может возникнуть, если вы не подключили заголовочный файл `<algorithm > `, который содержит объявление функции `std::sort`. Вот обновленный пример :

    ```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Добавлен заголовочный файл <algorithm> для std::sort

        // Структура данных для хранения информации о банковской операции
        struct BankOperation {
        std::string date;
        std::string time;
        std::string type;
        std::string account;
        double amount;
        std::string purpose;
    };

    // Функция для фильтрации данных
    std::vector<BankOperation*> filterBankOperations(
        BankOperation * array[],
        int size,
        bool (*check)(BankOperation * element),
        int& result_size
    ) {
        std::vector<BankOperation*> result;
        result_size = 0;

        for (int i = 0; i < size; i++) {
            if (check(array[i])) {
                result.push_back(array[i]);
                result_size++;
            }
        }

        return result;
    }

    // Функция для проверки условия отбора
    bool checkBankOperation(BankOperation * element) {
        // Пример условия отбора: выбираем только расходные операции
        return element->type == "расход";
    }

    // Функция для сортировки данных по возрастанию назначения платежа
    void sortByPurpose(std::vector<BankOperation*>&data) {
        std::sort(data.begin(), data.end(), [](BankOperation* a, BankOperation* b) {
            return a->purpose < b->purpose;
            });
    }

    // Функция для сортировки данных по возрастанию номера счёта, внутри счёта по возрастанию вида операции,
    // а внутри вида операции по убыванию суммы операции
    void sortByAccountTypeAmount(std::vector<BankOperation*>&data) {
        std::sort(data.begin(), data.end(), [](BankOperation* a, BankOperation* b) {
            if (a->account != b->account) {
                return a->account < b->account;
            }
            else if (a->type != b->type) {
                return a->type < b->type;
            }
            else {
                return a->amount > b->amount;
            }
            });
    }

    int main() {
        // Пример использования функций filterBankOperations и сортировки

        // Создаем массив с исходными данными
        BankOperation op1 = { "01.11.21", "08:30", "приход", "123456", 500.00, "Зачисление зарплаты" };
        BankOperation op2 = { "03.11.21", "14:15", "расход", "789012", 200.00, "Оплата коммунальных платежей" };
        BankOperation op3 = { "05.11.21", "10:00", "приход", "345678", 1000.00, "Перевод от другого банка" };
        BankOperation* operations[] = { &op1, &op2, &op3 };
        int size = sizeof(operations) / sizeof(operations[0]);

        int resultSize;
        std::vector<BankOperation*> filteredData = filterBankOperations(operations, size, checkBankOperation, resultSize);

        // Сортировка данных по возрастанию назначения платежа
        sortByPurpose(filteredData);

        // Вывод результатов
        std::cout << "Результаты фильтрации и сортировки по возрастанию назначения платежа:\n";
        for (BankOperation* operation : filteredData) {
            std::cout << "Дата: " << operation->date << ", Время: " << operation->time
                << ", Вид: " << operation->type << ", Счёт: " << operation->account
                << ", Сумма: " << operation->amount << ", Назначение: " << operation->purpose << "\n";
        }

        // Сортировка данных по возрастанию номера счёта, внутри счёта по возрастанию вида операции,
        // а внутри вида операции по убыванию сум