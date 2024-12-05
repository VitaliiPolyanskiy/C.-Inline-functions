﻿#include <iostream>
#include "absolute.h"

using namespace std;

/*
	Как известно, при вызове функции происходит:
		- помещение аргументов в стек;
		- передача управления функции;
		- возврат из функции;
		- освобождение стека.
	Все это вносит издержки, которые немного влияют на скорость. 

	Механизм встраивания, который появился в С++ и в С99 предназначен для увеличения производительности кода.
	Встраивание (inline) - это техника, благодаря которой компилятор имеет возможность не генерировать код для вызова функции,
	со всеми вытекающими отсюда последствиями, а встроить (скопировать) код функции напрямую в место её вызова.

	Для того, чтобы сделать функцию встраиваемой, необходимо при определении функции указать ключевое слово inline.
	Если функция определена с ключевым словом inline - это значит, что компилятору рекомендуется не использовать привычный вызов функции,
	а встроить её код напрямую в место использования.

	Однако встраивание является РЕКОМЕНДАЦИЕЙ для компилятора и срабатывает не всегда.
	Встраивание проходит для очень простых функций, состоящих из нескольких инструкций, которые не содержат сложных конструкций.
	Если функция содержит сложные конструкции (конструкции управления потоком выполнения (циклы, if/else, switch), рекурсивные вызовы и т.д.)
	то компилятор может проигнорировать встраивание. В таком случае, inline функция ничем не будет отличаться от обычной.

		https://isocpp.org/wiki/faq/inline-functions
*/

int main ()
{
	int someValue = -5;
	// Используем обычную функцию. Компилятор генерирует код для вызова. Линковщик связывает вызов с конкретным определением функции.
	// На этапе выполнения происходит вызов функции (косвенное обращение в памяти к коду функции, стековые операции и т.д.), что
	//	влечет за собой некоторые издержки. В С/С++ механизм вызова функций довольно эффективен. Однако, при слишком частых вызовах
	//	функции (например, в цикле) эти издержки могут иметь значение.
	cout << "Using slowAbsolute: " << slowAbs (someValue) << endl;

	// Используем inline-функцию. Её код будет СКОПИРОВАН непосредственно в эту инструкцию. 
	// Соответственно никаких издержек на вызов функции не будет. 
	cout << "Using fastAbsolute: " << fastAbs (someValue) << endl;

	return 0;
}