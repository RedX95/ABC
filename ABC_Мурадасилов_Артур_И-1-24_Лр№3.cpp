#include <iostream>
#include <bitset>
using namespace std;

// Функция перевода числа в двоичную систему (12 бит)
string toBinary(int num, int bits = 12) {
    return bitset<12>(num).to_string();
}

// Функция перевода из обратного кода в десятичное число
int fromBinary(string bin) {
    return bitset<12>(bin).to_ulong();
}

// Выполнение арифметических операций
void performOperations() {
    int num1 = 3535, num2 = 2534;
    int sum1 = 2350, sum2 = 3464;
    int hex1 = 0xB1A2, hex2 = 0x0133;
    int base51 = 4 * 25 + 2 * 5 + 1; // 421 в пятеричной -> десятичное
    int base52 = 2 * 25 + 1 * 5 + 1; // 211 в пятеричной -> десятичное
    int div1 = 120, div2 = 4;
    
    cout << "3535 - 2534:" << endl;
    cout << "Двоичный код: " << toBinary(num1) << " - " << toBinary(num2) << endl;
    cout << "Результат: " << num1 - num2 << " (" << toBinary(num1 - num2) << ")" << endl << endl;
    
    cout << "2350 + 3464:" << endl;
    cout << "Двоичный код: " << toBinary(sum1) << " + " << toBinary(sum2) << endl;
    cout << "Результат: " << sum1 + sum2 << " (" << toBinary(sum1 + sum2) << ")" << endl << endl;
    
    cout << "B1A2 - 133:" << endl;
    cout << "Двоичный код: " << toBinary(hex1, 16) << " - " << toBinary(hex2, 16) << endl;
    cout << "Результат: " << hex1 - hex2 << " (" << toBinary(hex1 - hex2, 16) << ")" << endl << endl;
    
    cout << "421₅ - 211₅:" << endl;
    cout << "Десятичный код: " << base51 << " - " << base52 << " = " << base51 - base52 << endl;
    
    cout << "120 / 4:" << endl;
    cout << "Результат: " << div1 / div2 << " (" << toBinary(div1 / div2) << ")" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    performOperations();
    return 0;
}
