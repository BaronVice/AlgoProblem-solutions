""" Идея задачи: мы знаем, что гарантированно можно закрасить n * min_el квадратов,
где n - количество банок с краской, min_el - минимальный объем из этих банок.
Чтобы закрасить больше квадратов, нужно начинать с элемента правее минимума.
Тогда в случае с одним элементом можно закрасить на n-1 больше квадратов и получить
максимальный результат. Но когда минимумов больше одного, то среди них предстоит найти участок
наибольшей длины и прибавить его к количеству гарантированно закрашенных квадратов (n * min_el) """


# Функция поиска максимальной длины сегмента 
def longest_segment(array: tuple, n: int, el: int):

    # Изначально самый длинный сегмент равен нулю
    longest_segment = 0
    # Запоминаем первое вхождение, чтобы знать откуда начинать
    first_occurence = array.index(el)
    # Также для вычисления отрезка будем хранить его начало
    previously_found = first_occurence

    # От следующего элемента первого вхождения и до конца
    for i in range(first_occurence + 1, n):
        # Если нашли еще один минимум
        if array[i] == el:
            # То вычисляем его длину
            current_length = i - previously_found - 1
            # И если его длина больше текущего максимального, то мы нашли новую наибольшую длину
            longest_segment = max(current_length, longest_segment)
            # Теперь i будет последним втреченным минимумом
            previously_found = i
    
    # Считаем длину отрезка от последнего элемента до первого встреченного
    # (т.е. количество элементов от начала отрезка до первого встреченного минимума
    # и от последнего встреченного минимума до конца отрезка. Так в случае с одним минимумом
    # это и будет ответом, который можно представить как n-1)
    last_to_first_case = first_occurence + n - previously_found - 1

    # В зависимости от того, какой отрезок длинее, выводим его
    return max(last_to_first_case, longest_segment)


n = int(input())
cans = tuple(map(int, input().split()))

# Минимальный элемент определяет максимальное количество обходов
min_el = min(cans)
# Считаем количество закрашенных квадратов исходя из:
# Количества обходов и максимальной длины сегмента между минимальными элементами
print(n * min_el + longest_segment(cans, n, min_el))