
t = int(input())

for _ in range(t):

    n = input()
    pos_zero = n.rfind('0')
    pos_five = n.rfind('5')
    next_zero, next_five, next_two, next_seven = -1, -1, -1, -1

    reslut_for_zero = 100000
    reslut_for_five = 100000

    if pos_zero != -1:
        next_zero = n.rfind('0', 0, pos_zero)
        next_five = n.rfind('5', 0, pos_zero)
        if next_zero != -1 or next_five != -1:
            reslut_for_zero = len(n)-1-pos_zero + pos_zero-1 - max(next_zero, next_five)
    
    if pos_five != -1:
        next_two = n.rfind('2', 0, pos_five)
        next_seven = n.rfind('7', 0, pos_five)
        if next_two != -1 or next_seven != -1:
            reslut_for_five = len(n)-1-pos_five + pos_five-1 - max(next_two, next_seven)


    print(min(reslut_for_zero, reslut_for_five))

    