
# Считаю сумму цифр заданного числа
def digit_sum(number):
    result = 0

    while number:
        result += number % 10
        number //= 10

    return result


k = int(input())
number = 10
while k != 0:
    number += 9
    if digit_sum(number) == 10:
        k -= 1
    
print(number)