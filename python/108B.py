# Идея задачи: если число умещаетя в n-бит памяти, то его квадрат поместится 2n-бит памяти

n = int(input())
# Размеры некоторых типов данных могут совпадать, но нам нужны уникальные значения - используем set
nums = list(set(map(int, input().split())))
# Сортируем, чтобы рассматривать последовательные пары
nums.sort()

java_is_weird = False
for i in range(len(nums)-1):
    # Если текущий тип больше следующего по величине, деленого на два, то не поместится
    if nums[i] > nums[i+1] // 2:
        java_is_weird = True
        break

print("YES") if java_is_weird else print("NO")
