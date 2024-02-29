#include <iostream>
#include <vector>
#include <algorithm> // �������� ������������ ���� <algorithm> ��� std::sort

// ��������� ������ ��� �������� ���������� � ���������� ��������
struct BankOperation {
    std::string date;
    std::string time;
    std::string type;
    std::string account;
    double amount;
    std::string purpose;
};

// ������� ��� ���������� ������
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

// ������� ��� �������� ������� ������
bool checkBankOperation(BankOperation* element) {
    // ������ ������� ������: �������� ������ ��������� ��������
    return element->type == "������";
}

// ������� ��� ���������� ������ �� ����������� ���������� �������
void sortByPurpose(std::vector<BankOperation*>& data) {
    std::sort(data.begin(), data.end(), [](BankOperation* a, BankOperation* b) {
        return a->purpose < b->purpose;
        });
}

// ������� ��� ���������� ������ �� ����������� ������ �����, ������ ����� �� ����������� ���� ��������,
// � ������ ���� �������� �� �������� ����� ��������
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
    // ������ ������������� ������� filterBankOperations � ����������

    // ������� ������ � ��������� �������
    BankOperation op1 = { "01.11.21", "08:30", "������", "123456", 500.00, "���������� ��������" };
    BankOperation op2 = { "03.11.21", "14:15", "������", "789012", 200.00, "������ ������������ ��������" };
    BankOperation op3 = { "05.11.21", "10:00", "������", "345678", 1000.00, "������� �� ������� �����" };
    BankOperation* operations[] = { &op1, &op2, &op3 };
    int size = sizeof(operations) / sizeof(operations[0]);

    int resultSize;
    std::vector<BankOperation*> filteredData = filterBankOperations(operations, size, checkBankOperation, resultSize);

    // ���������� ������ �� ����������� ���������� �������
    sortByPurpose(filteredData);

    // ����� �����������
    std::cout << "���������� ���������� � ���������� �� ����������� ���������� �������:\n";
    for (BankOperation* operation : filteredData) {
        std::cout << "����: " << operation->date << ", �����: " << operation->time
            << ", ���: " << operation->type << ", ����: " << operation->account
            << ", �����: " << operation->amount << ", ����������: " << operation->purpose << "\n";
    }

    // ���������� ������ �� ����������� ������ �����, ������ ����� �� ����������� ���� ��������,
    // � ������ ���� �������� �� �������� ����� ��������
    �������� �� ��������.������, ������� �� ���������, ����� ����������, ���� �� �� ���������� ������������ ���� `<algorithm > `, ������� �������� ���������� ������� `std::sort`. ��� ����������� ������ :

    ```cpp
#include <iostream>
#include <vector>
#include <algorithm> // �������� ������������ ���� <algorithm> ��� std::sort

        // ��������� ������ ��� �������� ���������� � ���������� ��������
        struct BankOperation {
        std::string date;
        std::string time;
        std::string type;
        std::string account;
        double amount;
        std::string purpose;
    };

    // ������� ��� ���������� ������
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

    // ������� ��� �������� ������� ������
    bool checkBankOperation(BankOperation * element) {
        // ������ ������� ������: �������� ������ ��������� ��������
        return element->type == "������";
    }

    // ������� ��� ���������� ������ �� ����������� ���������� �������
    void sortByPurpose(std::vector<BankOperation*>&data) {
        std::sort(data.begin(), data.end(), [](BankOperation* a, BankOperation* b) {
            return a->purpose < b->purpose;
            });
    }

    // ������� ��� ���������� ������ �� ����������� ������ �����, ������ ����� �� ����������� ���� ��������,
    // � ������ ���� �������� �� �������� ����� ��������
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
        // ������ ������������� ������� filterBankOperations � ����������

        // ������� ������ � ��������� �������
        BankOperation op1 = { "01.11.21", "08:30", "������", "123456", 500.00, "���������� ��������" };
        BankOperation op2 = { "03.11.21", "14:15", "������", "789012", 200.00, "������ ������������ ��������" };
        BankOperation op3 = { "05.11.21", "10:00", "������", "345678", 1000.00, "������� �� ������� �����" };
        BankOperation* operations[] = { &op1, &op2, &op3 };
        int size = sizeof(operations) / sizeof(operations[0]);

        int resultSize;
        std::vector<BankOperation*> filteredData = filterBankOperations(operations, size, checkBankOperation, resultSize);

        // ���������� ������ �� ����������� ���������� �������
        sortByPurpose(filteredData);

        // ����� �����������
        std::cout << "���������� ���������� � ���������� �� ����������� ���������� �������:\n";
        for (BankOperation* operation : filteredData) {
            std::cout << "����: " << operation->date << ", �����: " << operation->time
                << ", ���: " << operation->type << ", ����: " << operation->account
                << ", �����: " << operation->amount << ", ����������: " << operation->purpose << "\n";
        }

        // ���������� ������ �� ����������� ������ �����, ������ ����� �� ����������� ���� ��������,
        // � ������ ���� �������� �� �������� ���