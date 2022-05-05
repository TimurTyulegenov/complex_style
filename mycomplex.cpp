/*!
    @file
    @brief Файл с описанием методов класса Complex
*/

#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/*!
    @brief Конструктор класса
    @param aRe Действительная составляющая
    @param aIm Мнимая составляющая
*/
Complex :: Complex ( double aRe, double aIm )
{
    Re = aRe;
    Im = aIm;
}

/*!
    @brief Конструктор класса
    @param aRval Комплексное число
*/
Complex :: Complex ( const Complex & aRval )
{
    Re = aRval.Re;
    Im = aRval.Im;
}

/*!
    @brief Деструктор класса
*/
Complex :: ~Complex()
{
    Re = 0.0;
    Im = 0.0;
}

/*!
    @brief Конструктор класса Complex
    @param aRe Действительная составляющая
    @param aIm Мнимая составляющая
*/
void Complex :: set ( double aRe, double aIm )
{
    //сеттер, устанавливает комплексное число
    Re = aRe;
    Im = aIm;
}

/*!
    @brief Возращает модуль комплексного числа
    @return Модуль комплексного числа
*/
Complex :: operator double()
{
    return abs();
}

/*!
    @brief Возращает модуль комплексного числа
    @return Модуль комплексного числа
*/
double Complex :: abs()
{
    return sqrt ( Re * Re + Im * Im );
}

/*!
    @brief Оператор сложения
    @param aRval Комплексное число
    @return Сумму комплексных чисел
*/
Complex Complex :: operator+ ( const Complex& aRval )
{
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

/*!
    @brief Оператор вычитания
    @param aRval Комплексное число
    @return Разность комплексных чисел
*/
Complex Complex :: operator- ( const Complex& aRval )
{
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/*!
    @brief Оператор сложения
    @param aRval Вещественное число
    @return Сумму комплексных чисел
*/
Complex Complex :: operator+ ( const double& aRval )
{
    Complex Result;
    Result.Re = Re + aRval;
    Result.Im = Im;
    return Result;
}

/*!
    @brief Оператор вычитания
    @param aRval Вещественное число
    @return Сумму комплексных чисел
*/
Complex Complex :: operator- ( const  double& aRval )
{
    Complex Result ( *this );
    Result.Re = Re - aRval;
    return Result;
}

/*!
    @brief Оператор умножения
    @param aRval Комплексное число
    @return Произведение комплексных чисел
*/
Complex Complex :: operator* ( const Complex & aRval )
{
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/*!
    @brief Оператор умножения
    @param aRval Вещественное число
    @return Произведение комплексных чисел
*/
Complex Complex :: operator* ( const double& aRval )
{
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}

/*!
    @brief Оператор деления
    @param aRval Вещественное число
    @return Частное комплексных чисел
*/
Complex Complex :: operator/ ( const double& aRval )
{
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

/*!
    @brief Оператор сложения с присваиванием
    @param aRval Комплексное число
    @return Сумму комплексных чисел
*/
Complex& Complex :: operator+=  ( const Complex&  aRval )
{
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}

/*!
    @brief Оператор вычитания с присваиванием
    @param aRval Комплексное число
    @return Разность комплексных чисел
*/
Complex& Complex :: operator-= ( const Complex& aRval )
{
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/*!
    @brief Оператор умножения с присваиванием
    @param aRval Комплексное число
    @return Произведение комплексных чисел
*/
Complex& Complex :: operator*= ( const Complex& aRval )
{
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

/*!
    @brief Оператор сложения с присваиванием
    @param aRval Вещественное число
    @return Сумму комплексных чисел
*/
Complex& Complex :: operator+= ( const double& aRval )
{
    Re += aRval;
    return *this;
}

/*!
    @brief Оператор вычитания с присваиванием
    @param aRval Вещественное число
    @return Разность комплексных чисел
*/
Complex& Complex :: operator-= ( const double& aRval )
{
    Re -= aRval;
    return *this;
}

/*!
    @brief Оператор умножения с присваиванием
    @param aRval Вещественное число
    @return Произведение комплексных чисел
*/
Complex& Complex :: operator*= ( const double& aRval )
{
    Re *= aRval;
    Im *= aRval;
    return *this;
}

/*!
    @brief Оператор деления с присваиванием
    @param aRval Вещественное число
    @return Частное комплексных чисел
*/
Complex& Complex :: operator/= ( const double& aRval )
{
    Re /= aRval;
    Im /= aRval;
    return *this;
}

/*!
    @brief Оператор присваивания
    @param aRval Комплексное число
    @return Ссылку на объект
*/
Complex& Complex :: operator= ( const Complex& aRval )
{
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/*!
    @brief Оператор присваивания
    @param aRval Вещественное число
    @return Ссылку на объект
*/
Complex& Complex :: operator= ( const double& aRval )
{
    Re = aRval;
    Im = 0.0;
    return *this;
}

/*!
    @brief Оператор сдвига вправо
    @param stream Поток ввода
    @param aRval Комплексное число
    @return IO поток
*/
istream& operator >> ( istream& Stream, Complex& aRval )
{
    char tmp[256];
    Stream >> aRval.Re >> aRval.Im >> tmp;
    return Stream;
}

/*!
    @brief Оператор сдвига вправо
    @param stream Поток вывода
    @param aRval Комплексное число
    @return IO поток
*/
ostream& operator << ( ostream& Stream, Complex& aRval )
{
    Stream << aRval.Re;
    if ( !( aRval.Im < 0 ) )
        Stream << '+';
    Stream << aRval.Im << 'i';
    return Stream;
}

/*!
    @brief Оператор сложения
    @param aLval Вещественное число
    @param aRval Комплексное число
    @return Сумму чисел
*/
Complex operator+ ( const double& aLval, const Complex& aRval )
{
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im = aRval.Im;
    return Result;
}

/*!
    @brief Оператор вычитания
    @param aLval Вещественное число
    @param aRval Комплексное число
    @return Разность чисел
*/
Complex operator- ( const double& aLval, const Complex& aRval )
{
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im =- aRval.Im;
    return Result;
}

/*!
    @brief Оператор умножения
    @param aLval Вещественное число
    @param aRval Комплексное число
    @return Произведение чисел
*/
Complex operator* ( const double& aLval, const Complex& aRval)
{
    Complex Result;
    Result.Re = aLval * aRval.Re;
    Result.Im = aLval / aRval.Im;
    Result.Im = aLval * aRval.Im;
    return Result;
}
