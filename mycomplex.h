/*!
    @file
    @brief Заголовочный файл класса Complex
*/

#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>

using namespace std;

/*!
    @brief Класс комплексного числа
*/
class Complex
{
    /*!
        @brief Действительная составляющая
    */
        double Re;
    /*!
        @brief Мнимая составляющая
    */
        double Im;
    public:
        Complex ( double aRe = 0, double aIm = 0 );
        Complex ( const Complex& );
        ~Complex ();
        void set ( double aRe, double aIm = 0 );
        operator double ();
        double abs ();
        //Переопределение операторов  сдвига
        friend istream& operator >> ( istream& , Complex& );
        friend ostream& operator << ( ostream&, Complex& );
        //Переопределение операторов  сложения
        Complex operator+ ( const Complex& );
        Complex operator+ ( const double& );
        friend Complex operator+ ( const double&, const Complex& );
        //Переопределение операторов  вычитания
        Complex operator- ( const Complex& );
        Complex operator- ( const double& );
        friend Complex operator- ( const double&, const Complex& );
        //Переопределение операторов  умножения
        Complex operator* ( const Complex& );
        Complex operator* ( const double& );
        friend Complex operator* ( const double&, const Complex& );
        //Переопределение операторов  деления
        Complex operator/ ( const double& );
        //Переопределение операторов  присваивания комплексных чисел
        Complex& operator+= ( const Complex& );
        Complex& operator-= ( const Complex& );
        Complex& operator*= ( const Complex& );
        Complex& operator= ( const Complex& );
        //Переопределение операторов  присваивания вещественных чисел
        Complex& operator+= ( const double& );
        Complex& operator-= ( const double& );
        Complex& operator*= ( const double& );
        Complex& operator/= ( const double& );
        Complex& operator= ( const double& );
};
#endif
