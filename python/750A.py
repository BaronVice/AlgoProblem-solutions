
def main():
    n, k = map(int, input().split())
    time_left = 240 - k

    amount = 0
    while time_left >= 0:
        amount += 1
        time_left -= 5 * amount

    print(amount-1)


if __name__ == "__main__":
    main()
