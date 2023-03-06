from math import log2


class Tree:

    def __init__(self, n, elements, neutral):
        self.neutral = neutral
        self.tree_size = 2**(int(log2(n-1))+1) * 2
        self.tree = [0 for _ in range(self.tree_size)]
        self.lazy = [self.neutral for _ in range(self.tree_size)]
        self.mid = self.tree_size//2

        for i in range(self.mid, self.mid + n):
            self.tree[i] = elements[i-self.mid]
        for i in range(self.mid - 1, 0, -1):
            self.tree[i] = self.tree[i*2] + self.tree[i*2 + 1]      


    def propagate(self, i):
        if i * 2 <= self.tree_size:
            self.tree[i * 2] *= self.lazy[i]
            self.lazy[i * 2] *= self.lazy[i]
        if i * 2 + 1 <= self.tree_size:
            self.tree[i * 2 + 1] *= self.lazy[i]
            self.lazy[i * 2 + 1] *= self.lazy[i]
        
        self.lazy[i] = self.neutral


    def get_result(self, left, right):
        left += self.mid - 1
        right += self.mid - 1

        result = 0
        while left <= right:
            if left % 2 != 0:
                result += self.tree[left].value
            if right % 2 == 0:
                result += self.tree[right].value
            left = (left + 1) // 2
            right = (right - 1) // 2
    
        return result
    

    def __str__(self):
        return str(list(el.value for el in self.tree))


def main():
    n = int(input())
    tree = Tree(n, list(map(int, input().split())), 1)
    print(tree)
    print(tree.get_result(1, 5))
    print(tree.get_result(2, 7))



if __name__ == "__main__":
    main()