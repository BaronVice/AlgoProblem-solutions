from queue import PriorityQueue


def main():
    cities = {'Иркутск': [['Владивосток', 2000],
                          ['Магадан', 3000],
                          ['Красноярск', 1000],
                          ['Воронеж', 2000]],

              'Владивосток': [['Магадан', 500],
                              ['Иркутск', 2000]],

              'Магадан': [['Иркутск', 3000],
                          ['Владивосток', 500]],

              'Красноярск': [['Иркутск', 1000],
                             ['Воронеж', 600],
                             ['Москва', 200]],

              'Воронеж': [['Иркутск', 2000],
                          ['Красноярск', 600],
                          ['Москва', 300]],

              'Москва': [['Воронеж', 300],
                         ['Красноярск', 200],
                         ['С-П', 500]],

              'С-П': [['Москва', 500]]}

    visited = {'Иркутск': False,
               'Владивосток': False,
               'Магадан': False,
               'Красноярск': False,
               'Воронеж': False,
               'Москва': False,
               'С-П': False}

    weights = {'Иркутск': 10**18,
               'Владивосток': 10**18,
               'Магадан': 10**18,
               'Красноярск': 10**18,
               'Воронеж': 10**18,
               'Москва': 0,
               'С-П': 10**18}

    q = PriorityQueue()
    q.put((weights['Москва'], 'Москва'))
    while not q.empty():
        weight, city = q.get()
        for neighbour, distance in cities[city]:
            if weights[neighbour] > distance + weight:
                weights[neighbour] = distance + weight
                q.put((weights[neighbour], neighbour))

    print(weights)


if __name__ == "__main__":
    main()
