#include <stdio.h>
#include <string.h>

// Функция для перевода числа в "троичное представление" с цифрами 0, 1 и -1
void convertToTernary(int n, char* ternary) {
    int i = 0;
    while (n > 0) {
        if (n % 3 == 2) { // Если остаток равен 2, ставим -1 и переносим единичку вперед
            ternary[i++] = '-';
            n += 3;       // Прибавляем 3, чтобы следующий разряд стал единицей
        } else {
            ternary[i++] = '0' + (n % 3); // Иначе просто записываем текущий разряд
        }
        n /= 3;
    }
    ternary[i] = '\0'; // Завершаем строку нулевым символом

    // Разворачиваем строку, потому что она получилась в обратном порядке
    strrev(ternary);
}

int main() {
    int mass;
    scanf("%d", &mass);
    
    char ternary[32]; // Массив для хранения троичного представления
    memset(ternary, 0, sizeof(ternary));
    
    convertToTernary(mass, ternary);
    
    int count = 0;
    for (int i = 0; ternary[i]; ++i) {
        if (ternary[i] != '0') {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
