

def digit_sum(number):
    result = 0
    while number > 0:
        result += number % 10
        number //= 10
    return result


k = int(input())
number = 0

while k != 0:
    number += 1
    if digit_sum(number) == 10:
        k -= 1

print(number)
