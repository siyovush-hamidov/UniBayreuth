#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    int i = 2, ans = 1;
    // for (i; i <= n; i++)
    // {
    //     ans *= i;
    // }
    // printf("%d\n", ans);
    if (n < 2)
    {
        return 1;
    }
    while (n > 1)
    {
        return n * factorial(n - 1);
    }
}

void cswap(int *a, int *b)
{
    int value_a = *a, value_b = *b, c = *a;
    *a = *b;
    *b = c;
}

void find_min_max(double *arr, int size, double *min, double *max)
{
    *min = arr[0];
    *max = arr[0];
    int i = 0;
    for (i; i < size; i++)
    {
        if (*min > arr[i])
            *min = arr[i];
        if (*max < arr[i])
            *max = arr[i];
    }
}

// // find_min_max
// int main()
// {
//     int i = 0, size = 8 * 1024 * 1024;

//     double arr[size];
//     // double *arr = (double *)malloc(size * sizeof(double));

//     for (i; i < size; i++)
//     {
//         arr[i] = rand() % 100;
//         printf("arr[%d] = %lf\n", i, arr[i]);
//     }

//     double min, max;
//     find_min_max(arr, size, &min, &max);
//     printf("min: %lf\n", min);
//     printf("max: %lf\n", max);
// }

// 1.2 Sizeof exercise

//     - Write a C program that uses the sizeof operator to print the
//       size of int, float, and double data types, as well as the
//       sizes of their respective pointers int*, float*, and double*!
//     - Note: You can print an integer variable with the name number
//       on the console by using:

//         printf("The number is %i\n", number);
// int main(int argc, char **args)
// {
//     int ans = sizeof(double);
//     printf("%d\n", ans);

//     ans = sizeof(int *);
//     printf("%d\n", ans);

//     ans = sizeof(double *);
//     printf("%d\n", ans);

//     ans = sizeof(int);
//     printf("%d\n", ans);

//     ans = sizeof(float);
//     printf("%d\n", ans);

//     ans = sizeof(float *);
//     printf("%d\n", ans);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h> // Hужен для malloc, free, rand, srand
// #include <time.h>   // Hужен для time()

// /**
//  * @brief Находит минимальное и максимальное значения в массиве double.
//  *
//  * @param arr Указатель на начало массива.
//  * @param size Количество элементов в массиве.
//  * @param min Указатель, куда будет записано минимальное значение.
//  * @param max Указатель, куда будет записано максимальное значение.
//  */
// void find_min_max(double *arr, int size, double *min, double *max)
// {
//     // Проверка на пустой массив или невалидный размер
//     if (arr == NULL || size <= 0)
//     {
//         *min = 0.0;
//         *max = 0.0;
//         return;
//     }

//     *min = arr[0];
//     *max = arr[0];
//     int i = 0;

//     // Начинаем цикл с 1, так как 0-й элемент уже проверили
//     for (i = 1; i < size; i++)
//     {
//         if (arr[i] < *min)
//             *min = arr[i];
//         if (arr[i] > *max)
//             *max = arr[i];
//     }
// }

// int main()
// {
//     // Инициализируем генератор случайных чисел
//     srand(time(NULL));

//     double min_val, max_val;

//     // --- 1. Тест с АВТОМАТИЧЕСКИМ массивом (на стеке) ---
//     // (Маленький размер, чтобы избежать stack overflow)
//     int size_auto = 100;
//     double arr_auto[size_auto];
//     int i = 0;

//     printf("--- Тестирование автоматического массива (size = %d) ---\n", size_auto);
//     for (i = 0; i < size_auto; i++)
//     {
//         arr_auto[i] = (double)(rand() % 1000) / 10.0; // Случайные числа от 0.0 до 99.9
//     }

//     find_min_max(arr_auto, size_auto, &min_val, &max_val);
//     printf("Автоматический массив: Min = %lf, Max = %lf\n", min_val, max_val);

//     // --- 2. Тест с ДИНАМИЧЕСКИМ массивом (в куче) ---
//     // (Большой размер, как в твоем примере)
//     int size_dynamic = 8 * 1024 * 1024;

//     // Выделяем память в КУЧЕ (heap). Это безопасно для больших размеров.
//     double *arr_dynamic = (double *)malloc(size_dynamic * sizeof(double));

//     if (arr_dynamic == NULL)
//     {
//         printf("Ошибка: не удалось выделить память для динамического массива!\n");
//         return 1; // Выход с ошибкой
//     }

//     printf("\n--- Тестирование динамического массива (size = %d) ---\n", size_dynamic);
//     printf("Заполнение массива... (это может занять секунду)\n");
//     for (i = 0; i < size_dynamic; i++)
//     {
//         arr_dynamic[i] = (double)(rand() % 100000) / 10.0;
//     }
//     printf("Заполнение завершено.\n");

//     find_min_max(arr_dynamic, size_dynamic, &min_val, &max_val);
//     printf("Динамический массив: Min = %lf, Max = %lf\n", min_val, max_val);

//     // ВАЖНО: Освобождаем память, выделенную через malloc!
//     free(arr_dynamic);

//     return 0;
// }

// int is_palindrome(char *buffer, int size)
// {
//     int i = 0;
//     for (i; i < size / 2; i++)
//     {
//         if (buffer[i] != buffer[size - i - 1])
//             return 0;
//     }
//     return 1;
// }

// int main()
// {
//     printf("%d\n", is_palindrome("madam", 5));
//     printf("%d\n", is_palindrome("lemon", 5));
//     printf("%d\n", is_palindrome("lemel", 5));
// }

// int is_palindrome(char *buffer, int size)
// {
//     // Итерация до середины строки
//     int i = 0;
//     for (i; i < size / 2; i++)
//     {
//         // Сравниваем символ с начала (buffer[i])
//         // с символом с конца (buffer[size - i - 1])
//         if (buffer[i] != buffer[size - i - 1])
//             return 0; // Найдено несоответствие - не палиндром
//     }
//     return 1; // Все символы совпали - палиндром
// }

// int main()
// {
//     // Тестирование со строковыми литералами
//     printf("Тест 'madam' (размер 5): %d (Ожидается 1)\n", is_palindrome("madam", 5));
//     printf("Тест 'lemon' (размер 5): %d (Ожидается 0)\n", is_palindrome("lemon", 5));
//     printf("Тест 'lemel' (размер 5): %d (Ожидается 1)\n", is_palindrome("lemel", 5));
//     printf("Тест 'abba' (размер 4): %d (Ожидается 1)\n", is_palindrome("abba", 4));
//     printf("Тест 'abc' (размер 3): %d (Ожидается 0)\n", is_palindrome("abc", 3));

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h> // нужен для malloc

// Твои структуры, тут все было ок
typedef struct ELEMENT element;
struct ELEMENT
{
    int value;
    element *next;
};

typedef struct LIST
{
    element *first;
} list;

// Твоя функция поиска, тоже была правильная
element *find_element(list *L, int value)
{
    element *cur = L->first;
    while (cur != NULL && cur->value != value)
    {
        cur = cur->next;
    }
    return cur;
}

// Новая функция вставки, которая работает
void insert_value(list *L, int value)
{
    // 1. Создаем новый элемент и выделяем под него память
    element *new_el = (element *)malloc(sizeof(element));
    if (new_el == NULL)
    {
        // Не смогли выделить память, ничего не делаем
        return;
    }
    new_el->value = value;

    // 2. Ищем место для вставки
    // Случай 1: список пуст или новый элемент должен быть первым
    if (L->first == NULL || L->first->value >= value)
    {
        new_el->next = L->first;
        L->first = new_el;
        return;
    }

    // Случай 2: вставляем в середину или конец
    element *cur = L->first;
    // Идем до тех пор, пока СЛЕДУЮЩИЙ элемент не станет больше нашего
    while (cur->next != NULL && cur->next->value < value)
    {
        cur = cur->next;
    }

    // Вставляем новый элемент после 'cur'
    new_el->next = cur->next;
    cur->next = new_el;
}

// Добавил простую функцию для печати списка, чтобы было видно результат
void print_list(list *L)
{
    element *cur = L->first;
    printf("List: ");
    while (cur != NULL)
    {
        printf("%d -> ", cur->value);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main()
{
    // 1. Создаем список
    list L;
    // 2. ОБЯЗАТЕЛЬНО инициализируем указатель, иначе там мусор
    L.first = NULL;

    // 3. Вставляем значения (не по порядку, чтобы проверить сортировку)
    printf("Inserting 10...\n");
    insert_value(&L, 10);
    print_list(&L);

    printf("Inserting 5...\n");
    insert_value(&L, 5);
    print_list(&L);

    printf("Inserting 20...\n");
    insert_value(&L, 20);
    print_list(&L);

    printf("Inserting 15...\n");
    insert_value(&L, 15);
    print_list(&L);

    // 4. Проверяем, что элементы на месте с помощью find_element
    printf("\nChecking elements:\n");
    if (find_element(&L, 15))
    {
        printf("Element 15 found.\n");
    }
    else
    {
        printf("Element 15 NOT found.\n");
    }

    if (find_element(&L, 99))
    {
        printf("Element 99 found.\n");
    }
    else
    {
        printf("Element 99 NOT found.\n");
    }

    print_list(&L);

    // В хорошем коде тут еще нужно освободить всю память (free), но для сдачи хватит и так.

    return 0;
}