s = input()

pref = [0]
for i in range(len(s)-1):
    if s[i] == s[i+1]:
        pref.append(pref[i] + 1)
    else:
        pref.append(pref[i])


m = int(input())
for _ in range(m):
    l, r = map(int, input().split())
    print(pref[r-1] - pref[l-1])