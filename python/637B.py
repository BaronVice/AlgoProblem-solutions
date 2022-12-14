# Через кровь, пот и слезы оно прошло все 100 кем-то написанных тестов...
# Идея задачи: используем словарь (хранит уникальные ключи с их значениями)

n = int(input())
# Ключ - имя, значение - i
chat = dict()

# Будем ориентироватся на i, как на порядок в чате: чем больше у ключа значение i,
# тем выше оно будет стоять.   
for i in range(n):
    name = input()
    # Если имя еще не записано, то оно будет добавлено в словарь как в начало чата,
    # Иначе перезапишем значение имени на более высокое, тем самым подняв его в начало чата 
    chat[name] = i

# Не вздумайте писать такое в реальных проектах (вспоминается мем про лямбда выражение)
# На самом деле здесь все просто: сортируем словарь по значениям, значения сортируются по
# убыванию - т.е. чем больше значение тем первее будет стоять имя. Выводим имена используя
# распаковку "*" и шаг на новую линию "\n"
print(*(name for name, value in sorted(chat.items(), key = lambda item: item[1], reverse=True)), sep = "\n")        

