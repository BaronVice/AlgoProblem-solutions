''' Полагаю очевиден тот момент, что для получения результата произведения = 1 нужно свести все числа
либо к 1, либо к -1. Также нужно учесть, что в таком случае количество -1 должно быть четным
(минус на минус дает плюс). Нули будем обращать либо в 1, либо в -1''' 

n = int(input())

# Нам не важно количество положительных чисел, они не влияют на знак произведения
negative = 0
nills = 0

coins = 0

numbers = tuple(map(int, input().split()))
for number in numbers:
    # Если число положительное, то считаем сколько монет нужно для сведения к 1
    if number > 0:
        coins += number-1
    # Если число отрицательное, то считаем сколько монет нужно для сведения к -1
    elif number < 0:
        negative += 1
        coins -= number+1
    # Если 0, то его нужно привести либо к 1, либо к -1
    else:
        nills += 1
        coins += 1
# Если количество отрицательных четно, то все хорошо, выводим coins
# Если нечетно, но у нас есть хотя бы один 0 для сведения к -1, то опять же выводим coins
if negative % 2 == 0 or nills > 0:
    print(coins)
# Иначе придется привести одну из -1 к 1, на что уйдет еще 2 монеты
else:
    print(coins+2)
