""" Идея задачи: вместо подсчета сумм в каждом запросе, посчитаем их сразу (префиксные суммы)
Будет два массива префиксных сумм: для первого запроса при упорядоченном порядке камней
и для второго запроса, где камни расположены по возрастанию стоимости (используем сортировку) """

n = int(input())
costs = list(map(int, input().split()))

# Префиксные суммы для первого запроса
pref_sum_costs = [0]
for i in range(n):
    pref_sum_costs.append(pref_sum_costs[i] + costs[i])

# Сортируем стоимости для составления префиксных сумм к второму запросу
costs.sort()
# Префиксные суммы для второго запроса
sorted_pref_sum_costs = [0]
for i in range(n):
    sorted_pref_sum_costs.append(sorted_pref_sum_costs[i] + costs[i])

q = int(input())
for _ in range(q):
    # Тип запроса, начало отрезка, конец отрезка
    request, left, right = map(int, input().split())

    """ Вобще формула выглядит следующим образом:
        prefSum[right + 1] - prefSum[left]

        Но нужно учесть, что left и right задаются с единицы, но индексация начинается с нуля,
        поэтому здесь:
        prefSum[right + 1 - 1] - prefSum[left - 1] -> prefSum[right] - prefSum[left - 1] """

    if request == 1:
        print(pref_sum_costs[right] - pref_sum_costs[left - 1])
    else:
        print(sorted_pref_sum_costs[right] - sorted_pref_sum_costs[left - 1])
