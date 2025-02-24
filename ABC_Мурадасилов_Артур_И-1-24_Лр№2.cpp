#include <iostream>
#include <cmath>
#include <bitset>
#include <sstream>  // Для использования stringstream
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    double ch;
    cout << "Введите число (десятичное): ";
    cin >> ch;

    // Шаг 1: Определяем знак
    int sign = (ch < 0) ? 1 : 0;
    if (ch < 0) ch = -ch;  // Берем модуль числа

    // Шаг 2: Разделяем число на целую и дробную части
    int sel = static_cast<int>(ch);
    double drob = ch - sel;

    // Шаг 3: Перевод целой части в двоичный формат
    string intPartBin = "";
    if (sel == 0) {
        intPartBin = "0";
    }
    else {
        while (sel > 0) {
            intPartBin = (sel % 2 == 0 ? "0" : "1") + intPartBin;
            sel = sel / 2;
        }
    }

    // Шаг 4: Переводим дробную часть в двоичный формат (до 23 знаков)
    string fracPartBin = "";
    for (int i = 0; i < 23; i++) {
        drob *= 2;
        if (drob >= 1) {
            fracPartBin += "1";
            drob -= 1;
        }
        else {
            fracPartBin += "0";
        }
    }

    // Шаг 5: Нормализация
    int exponent = 0;
    string mantissa = "";
    if (intPartBin != "0") {
        exponent = intPartBin.length() - 1;  // Порядок сдвига
        mantissa = intPartBin.substr(1) + fracPartBin;  // Мантисса без первой 1
    }
    else {
        size_t firstOne = fracPartBin.find('1');
        if (firstOne != string::npos) {
            exponent = -(static_cast<int>(firstOne) + 1);  // Отрицательный порядок
            mantissa = fracPartBin.substr(firstOne + 1);
        }
        else {
            exponent = 0; // Если не найдено 1, это означает, что число 0
            mantissa = "0";
        }
    }

    // Шаг 6: Экспонента (смещение на 127)
    int ieeeExponent = exponent + 127;

    // Шаг 7: Дополняем мантиссу до 23 бит
    if (mantissa.length() < 23) {
        mantissa.append(23 - mantissa.length(), '0');  // Дополняем нулями
    }
    else if (mantissa.length() > 23) {
        mantissa = mantissa.substr(0, 23);  // Обрезаем до 23 знаков
    }

    // Формируем 32-битное представление
    unsigned int result = (sign << 31) | (ieeeExponent << 23) | stoi(mantissa.substr(0, 23), nullptr, 2);

    // Переводим результат в строку в двоичном формате с ведущими нулями
    bitset<32> binary(result);

    // Шаг 8: Выводим результат
    cout << "IEEE 754 представление:\n";
    cout << "Знак: " << sign << endl;
    cout << "Экспонента (смещённая): " << ieeeExponent << endl;
    cout << "Мантисса: " << mantissa << endl;
    cout << "Полное 32-битное представление: " << binary.to_string() << endl;

    return 0;
}
