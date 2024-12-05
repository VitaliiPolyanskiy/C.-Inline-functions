﻿// Обычная функция 
int slowAbs (int number);


// inline функция
// ВНИМАНИЕ! По требованию компилятора, код inline-функции должен быть ОПРЕДЕЛЕН в каждой единице трансляции (.cpp), 
// где она используется. Это вполне логично, ведь он компилирует каждый файл по отдельности, а при встраивании должен 
// копировать код функции на место использования. Поэтому типичной практикой является определение inline-функций в 
// заголовочных файлах. Это позволяет включить определение во все единицы трансляции, где оно необходимо.
// ВАЖНО! Помните, что определить функцию можно только 1 раз. inline-функции являются исключением из этого правила.
// Если определения обычных функций помещать в заголовочный файл, то это повлечет ошибку на этапе компоновки (линковки), 
// т.к. будет переопределение (redefinition).


		inline int fastAbs (int number)
		{
			return number < 0 ? -number : number;
		}
