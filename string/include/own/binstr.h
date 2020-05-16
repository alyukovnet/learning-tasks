/*!
\file
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения производного
от "Строка" класса "Битовая строка"
*/
#ifndef STRING_MODULE_BINSTR_H
#define STRING_MODULE_BINSTR_H

#include "string.h"

namespace own {

/*!
	\brief Производный от "Строка" класс "Битовая строка"

	Строки данного класса могут содержать только символы '0' или '1'. Если
	в составе инициализирующей строки будут встречены любые символы, отличные
	от допустимых, "Битовая строка" принимает нулевое значение.
	Содержимое данных строк рассматривается как двоичное число.
	Отрицательные числа хранятся в дополнительном коде. 
*/
enum SIGN {
	PLUS = 1,
	MINUS = 0
};

class BinStr : public String
{
public:
    /*!
    Конструктор без параметров (длина строки = 0) или принимающий длину строки
    \param[in] len Длина строки (по умолчанию 0)
    */
    BinStr(int = 0);

    /*!
    Конструктор, принимающий в качестве параметра символ (char)
    \param[in] ch Символ
    */
    BinStr(char);

    /*!
    Конструктор, принимающий в качестве параметра Си-строку (заканчивается нулевым байтом)
    \param[in] s Си-строка
    */
    BinStr(const char*);
    
    /*!
    Конструктор копирования
    \param[in] from Исходный объект
    */
    BinStr(const String&);
    
    /*!
    Деструктор
    */
    ~BinStr();

    /*!
    Оператор присваивания
    */
	BinStr& operator=(const BinStr&);

	/*!
	Получение знака двоичного числа
	\return Знак числа SIGN::PLUS или SIGN::MINUS
	*/
	int getSign();

	/*!
	Операция "исключающее или"
	\return Сумма по модулю 2
	*/
	friend BinStr operator^(const BinStr&, const BinStr&);

	/*!
	Операция "исключающее или"
	*/
	BinStr& operator^=(const BinStr&);

	/*!
	Проверка равенства строк как бинарных чисел
	*/
    friend int operator==(const String&, const String&);
};

}
#endif // STRING_MODULE_BINSTR_H
