

def main():
    numbers = dict()
    for _ in range(int(input())):
        number = int(input())
        numbers[number] = 1 if number not in numbers else numbers[number] + 1

    for number in numbers:
        for _ in range(numbers[number]):
            print(number)
        
        if numbers[number]:
            numbers[number // 3 * 4] -= numbers[number]
            

if __name__ == "__main__":
    main()