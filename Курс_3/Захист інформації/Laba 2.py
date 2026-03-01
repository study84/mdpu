"""
513-і, Золотухін Андрій
Захист інформації. Лабораторна робота 2. Дослідження складності підбору пароля
Варіант 1
"""

import string
import random
from datetime import datetime
import itertools

#chars = list(string.ascii_letters) + list(string.digits)
chars = list(string.ascii_lowercase)


class TestPasswd:
    def __init__(self, length):
        self.passwd = {
            'length': length,
            'passwd': "".join(random.choice(chars) for _ in range(length)),
            'attempt': 0,
            'start': datetime.now(),
            'end': None,
            'time': None
        }
        #print(self.passwd)

    def hack(self):
        def brute_force(chars, length):
            for combo in itertools.product(chars, repeat=length):
                yield "".join(combo)

        for test in brute_force(chars, self.passwd['length']):

            if self.passwd['passwd'] == test:
                self.passwd['end'] = datetime.now()
                self.passwd['time'] = self.passwd['end'] - self.passwd['start']
                break
            else:
                self.passwd['attempt'] += 1

        print(self.passwd)




print("513-і, Золотухін Андрій. Захист інформації. Лабораторна робота 2. Дослідження складності підбору пароля. Варіант 1")


for size in [3, 5, 5, 5, 7]:
    p = TestPasswd(size)
    p.hack()
    
    