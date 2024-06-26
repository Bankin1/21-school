# s21_math

Реализация собственной версии математической библиотеки math.h.

## Contents

0. [Preamble](#preamble)  
1. [Chapter I](#chapter-i) \
    1.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
    2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
    3.1. [Part 1](#part-1-реализация-функций-библиотеки-mathh)  


## Preamble  

![s21_math](misc/rus/s21_math.png)

Планета Земля, 1956 год.

По утрам я обычно читаю новости и завтракаю хрустящим тостом и яичницей с сосисками.Это весеннее утро должно было ничем не отличаться от остальных, но я заметил в газете небольшую колонку от профессора Стэндфордского университета. Знаменитый в узких кругах физического научного общества Уильям Шокли, изобретатель транзистора, разместил вакансию о работе в лаборатории для массового производства новейших транзисторов и динисторов. \
Недолго думая, я позвонил по номеру, указанному в газете:

*- Добрый вечер, Уильям, я по поводу оставленной вами вакансии, вам удобно говорить?*

*-- Да, конечно, я очень рад, что хоть кто-то откликнулся! Должен сразу обозначить все особенности нашего будущего сотрудничества, производство будет вестись на нашей площадке в Маунтин-Вью, близ Пало-Альто, это почти что деревня, без изысков, но, надеюсь, вас это не смутит, я правильно полагаю, мистер?..*

*- Ласт, мистер Джей Ласт из MIT. Да, я осведомлен об этом, и меня это ни капельки не смущает, когда я смогу прийти на собеседование?*

*-- Хорошо, очень хорошо! У меня сейчас нет времени быть постоянно на связи и собеседовать людей из других городов, поэтому пришлите мне на оставленный в газете адрес результат вашей работы, которую я сейчас дам...*

*- Внимательно вас слушаю.*

*-- Для нашего дела нужны мощные математические инструменты, которые можно было бы описать на машинном языке программирования - всевозможные математические операции и функции: тригонометрические, логарифмические, показательные и другие на ваш выбор. Абсолютно не важно как, но вы должны это сделать...* \
*На этом вынужден с вами попрощаться, у меня вторая линия, жду ваш ответ! Спасибо!*

*- Удачного дня!*

Что же, я обязан это сделать - я прямо чувствую, что грядет транзисторная революция в математических вычислениях, и я обязан быть в первых рядах!

## Chapter I

## Introduction

В данном проекте тебе предстоит разработать свою версию стандартной библиотеки math.h на языке программирования С. Эта библиотека реализует базовые математические операции, которые затем используются в различных алгоритмах. В рамках выполнения этого проекта предполагается знакомство с основами вычислительных методов и закрепление подходов структурного программирования.   


## Chapter II

## Information

Математические операции на языке С представляют собой группу функций в стандартной библиотеке языка программирования С, реализующих основные математические функции. Все функции так или иначе используют числа с плавающей запятой. Различные стандарты C предоставляют разнообразные, хотя и обратно совместимые, наборы функций. Любые функции, которые работают с углами, используют радианы в качестве единицы измерения угла.  

### Обзор некоторых функций «math.h»

| No. | Function | Description |
| --- | -------- | ----------- |
| 1 | `int abs(int x)` | вычисляет абсолютное значение целого числа |
| 2 | `long double acos(double x)` | вычисляет арккосинус |
| 3 | `long double asin(double x)` | вычисляет арксинус |
| 4 | `long double atan(double x)` | вычисляет арктангенс |
| 5 | `long double ceil(double x)` | возвращает ближайшее целое число, не меньшее заданного значения |
| 6 | `long double cos(double x)` | вычисляет косинус |
| 7 | `long double exp(double x)` | возвращает значение e, возведенное в заданную степень |
| 8 | `long double fabs(double x)` | вычисляет абсолютное значение числа с плавающей точкой |
| 9 | `long double floor(double x)` | возвращает ближайшее целое число, не превышающее заданное значение |
| 10 | `long double fmod(double x, double y)` | остаток операции деления с плавающей точкой |
| 11 | `long double log(double x)` | вычисляет натуральный логарифм |
| 12 | `long double pow(double base, double exp)` | возводит число в заданную степень |
| 13 | `long double sin(double x)` | вычисляет синус |
| 14 | `long double sqrt(double x)` | вычисляет квадратный корень |
| 15 | `long double tan(double x)` | вычисляет тангенс |  


## Chapter III

## Part 1. Реализация функций библиотеки math.h

Необходимо реализовать функции библиотеки math.h (только те, что непосредственно описаны [выше](#обзор-некоторых-функций-mathh)):

- Библиотека должна быть разработана на языке С стандарта C11 с использованием компиятора gcc;
- Код библиотеки должен находиться в папке src в ветке develop;  
- Не используй устаревшие и выведенные из употребления конструкции языка и библиотечные функции. Обращай внимания на пометки legacy и obsolete в официальной документации по языку и используемым библиотекам. Ориентируйся на стандарт POSIX.1-2017;
- При написании кода необходимо придерживаться Google Style;
- Оформи решение как статическую библиотеку с названием *s21_math.a* (с заголовочным файлом s21_math.h);
- Библиотека должна быть разработана в соответствии с принципами структурного программирования, должно быть исключено дублирование кода;
- Перед каждой функцией используй префикс s21_;
- Подготовь полное покрытие unit-тестами функций библиотеки c помощью библиотеки Check;
- Unit-тесты должны проверять результаты работы твоей реализации путём сравнения ее с реализацией стандартной библиотеки math.h;
- Unit-тесты должны покрывать не менее 80% каждой функции;
- В цели gcov_report должен формироваться отчёт gcov в виде html страницы. Для этого unit-тесты должны запускаться с флагами gcov;
- Предусмотри Makefile для сборки библиотеки и тестов (с целями all, clean, test, s21_math.a, gcov_report);
- Запрещено копирование реализации и использование стандартной библиотеки math.h везде, кроме unit-тестов;
- Необходимо соблюсти логику работы стандартной библиотеки (в части проверок, работы с памятью и поведения в нештатных ситуациях - здесь помогут тесты);
- Общая проверяемая точность - 16 значащих цифр;
- Проверяемая точность дробной части - максимум 6 знаков после запятой.

💡 [Нажми сюда](https://forms.yandex.ru/cloud/64181327c769f101564293de/)**, чтобы поделиться с нами обратной связью на этот проект**. Это анонимно и поможет команде Продукта сделать твоё обучение лучше.
