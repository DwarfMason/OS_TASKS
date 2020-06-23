# Лабораторная работа #13

>Разработать план  (что, зачем и как тестируется)  для трех вариантов кода и прокомментировать результаты тестирования для



>    queue. c  - наивный вариант

>    queue_mutex. c  - с использованием mutex

>    queue_cond. c  - с использованием условных переменных для ситуаций с пустой и полной очередями


Так как единственный тест в прилагаемом коде проверяет базовую работоспособность кода, но не проверяет особые случаи было разработано 2 теста:

- Потокоустойчовость
- Получение элемента при пустой очереди

*empty_queue_test* При правильной работе программы при исполнении данного теста должен выполниться push элемента, после чего его извлечение, но в случае с выполнением queue.c  получаем ошибку, указывающую на то, что pop пытается выполниться на пустой очереди.

*thread_safe_test* пытается в пустую очередь писать одновременно из двух потоков числа. Мы проверяем количество полученных пустых ячеек, и если оно превышает ноль, то получается, что произошло небезопасное исполнение записи(например дважды сдвинут указатель на ячейку при параллельной записи или произошла перезапись поля). Данный тест проваливается для queue.c и для queue_mutex.c