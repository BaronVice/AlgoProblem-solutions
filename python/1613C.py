

def damage(k, attacks, n):
    total_damage = k
    for i in range(1, n):
        total_damage += min(attacks[i] - attacks[i-1], k)
    return total_damage


def get_result():
    n, h = map(int, input().split())
    attacks = list(map(int, input().split()))

    left, right = 0, h
    while right - left > 1:
        k = (right + left) // 2
        if damage(k, attacks, n) >= h:
            right = k
        else:
            left = k

    return right


def main():
    for _ in range(int(input())):
        print(get_result())


if __name__ == "__main__":
    main()