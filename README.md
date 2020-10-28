# Task

Please submit the complete C++ source code for a program that counts the number of distinct unique words read from the standard input.

For example, given the input "a horse and a dog" the program must output "4" (the word 'a' appears twice but only accounts for one distinct unique occurrence).

The input text is guaranteed to contain only 'a'..'z' and space characters in ASCII encoding.

The program should be able to handle large inputs (e.g. 32 GiB)

You can assume that all unique words fit into memory when using the data structure of your choice.

# Attempts to solve.

## Naїve solution:

Прога в рантаймі хаває 24мб для 370000 різних слів і інпуті майже в 800мб.
Працює очевидно довго — це мінус. Оскільки в std::unordered_set доступ і вставка в середньому за O(1) це не повиноо бути ботлнеком. Висновок — оптимізовуємо IO.

## Читаємо все зразу (не включений в гіт)

Вилітаємо в пам’ять ~ об'єм входу. Відпадає зразу.

## Читаємо буфером

Беремо буфер у 256 байт і пробуємо прочитати. Далі вже обробляємо його.
По об'єму пам'яті не сильно більше наївного рішення, але на 20-25% швидше.
Можлива оптимізація – додаємо потоки.

## Багатопотокове рішення

Основну роботу зі стрічками виносимо в окремий потік, і дані отримуємо в кінці через проміс.
Загалом, працює так само як і попреднє рішення, проте його ще можна оптимізувати.