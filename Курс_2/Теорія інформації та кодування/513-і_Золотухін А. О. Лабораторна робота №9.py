# 513-і Золотухін Андрій
# Лабораторна робота №9
# ДВІЙКОВІ  КОДИ, ЩО ВИЯВЛЯЮТЬ ПОМИЛКИ

import copy
from random import randrange as rnd

def checking_for_parity(value):
  print("ПРП - перевіркою на парність:", value)
  A = [int(v) for v in value]
  print('A =', A)
  A01 = copy.copy(A) + [sum(A) % 2]
  print('A01 =', A01)
  E = [0] * len(A01)
  E[rnd(0, len(A01))] = 1
  print('E =', E)
  A01E = [(A01[i] + E[i]) % 2 for i in range(len(A01))]
  print('A01E =', A01E)
  print('A01E Status:', [True, False][(sum(A01E) % 2)])


def simple_repetition(value):
  print("ПП - простим повторенням:", value)
  A = [int(v) for v in value]
  print('A =', A)
  A01 = copy.copy(A) + copy.copy(A)
  print('A01 =', A01)
  E = [0] * len(A01)
  E[rnd(0, len(A01))] = 1
  #E = [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0]
  print('E =', E)
  A01E = [(A01[i] + E[i]) % 2 for i in range(len(A01))] ## ПОМИЛКА В PYTON ПРИ СКЛАДАННІ 5 пара: (0 + 1) % 2 = 0 !!!
  print('A01E =', A01)
  A01E1 = A01E[:len(A01E) // 2]
  A01E2 = A01E[len(A01E) // 2:]
  print('A01E1 =', A01E1)
  print('A01E2 =', A01E2)
  A01E1A01E2 = [(A01E1[i] + A01E2[i]) % 2 for i in range(len(A01E1))]
  print('A01E1A01E2 =', A01E1A01E2)
  print('A01E1A01E2 Status', [True, False][(sum(A01E1A01E2) > 0)])


def a_multiple_of_three (value):
  print("ОК3 – з числом одиниць, кратним трьом", value)
  A = [int(v) for v in value]
  print('A =', A)
  A01 = copy.copy(A) + [1] * [0,2,1][(sum(A) % 3)]
  print('A01 = ', A01)
  E = [0] * len(A01)
  E[rnd(0, len(A01))] = 1
  #E = [0, 0, 0, 0, 1, 0, 0]
  print('E =', E)
  A01E = [(A01[i] + E[i]) % 2 for i in range(len(A01))]
  print('A01E = ', A01E)
  print('A01E Status', sum(A01E) == 3)


def inverse(value):
  print('ІК - інверсним (Бауера)', value)
  A = [int(v) for v in value]
  print('A =', A)
  A01 = copy.copy(A) + [[1,0][i] for i in A]
  print('A01 = ', A01)
  E = [0] * len(A01)
  E[rnd(0, len(A01))] = 1
  #E = [0, 0, 0, 0, 1, 0, 0, 0, 0, 0]
  print('E = ', E)
  A01E = [(A01[i] + E[i]) % 2 for i in range(len(A01))]
  print('A01E = ', A01E)
  print('A01E Status', sum(A01E[:len(A01E)]) == sum(A01E[len(A01E):]))



def checking_for_oddness(value):
  print('ПРН - перевіркою на непарність', value)
  A = [int(v) for v in value]
  print('A =', A)
  A01 = copy.copy(A) + [[1,0][sum(A) % 2]]
  print('A01 = ', A01)
  E = [0] * len(A01)
  E[rnd(0, len(A01))] = 1
  #E = [0, 0, 0, 0, 1, 0, 0]
  print('E = ', E)
  A01E = [(A01[i] + E[i]) % 2 for i in range(len(A01))]
  print('A01E', A01E)
  print('A01E Status', bool(sum(A01E) % 2))


def correlation(value):
  print('КК - кореляційний', value)
  #A = [v1 for v in value for v1 in [int(v)] * 2]
  A01 = [int(value[0])] + [v1 for v in value[1:] for v1 in [int(v)] * 2] + [int(value[0])]
  print('A =', A01)
  E = [0] * len(A01)
  E[rnd(0, len(A01))] = 1
  #E = [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0]
  print('E =', E)
  A01E = [(A01[i] + E[i]) % 2 for i in range(len(A01))]
  print('A01E =', A01E)
  #print('A01E Status', [(A01E[i], A01E[i + 1]) for i in range(0, len(A01E), 2)])
  #print('A01E Status', [A01E[i] != A01E[i + 1] for i in range(0, len(A01E), 2)])
  print('A01E Status', all([A01E[i] != A01E[i + 1] for i in range(0, len(A01E), 2)]))


################################################################################


code = {
    'ПРП': checking_for_parity,
    'ПП': simple_repetition,
    'ОК3': a_multiple_of_three,
    'ІК': inverse,
    'ПРН': checking_for_oddness,
    'КК': correlation
}


tasks = [
    ('100101010100', ('ПРП', 'КБ')),
    ('11101101101', ('ПРН', 'ПП')),
    ('11011010', ('КК', 'КБ')),
    ('0000011100', ('ПВ(4)', 'ПП')),
    ('0000011000', ('ПВ(3)', 'ОК3')),
    ('10111101011', ('ІК', 'КБ')),
    ('11101010101', ('ІК', 'ПП')),
    ('0011101100', ('ІК', 'КК')),
    ('11000010100', ('ІК', 'ПВ(5)')),
    ('00101010100', ('ПВ(6)', 'ПРП')),
    ('100101010100', ('ПВ(5)', 'ПРН')),
    ('101111010', ('КК', 'ПП')),
    ('1110010111', ('КК', 'КБ')),
    ('100101011110', ('ПРП', 'ПП')),
    ('100101010100', ('ПРН', 'ОК3')),
    ('110000101011', ('ІК', 'КБ')),
    ('010101010101', ('ІК', 'ПП')),
    ('1011101101', ('ІК', 'КБ')),
    ('1100001011', ('ІК', 'ПВ(5)')),
    ('1000000101', ('ПВ(4)', 'ПРП')),
    ('1001010101', ('ПВ(7)', 'ПРН')),
    ('10111', ('КК', 'ПП')),
    ('11100101', ('КК', 'ОК3')),
    ('100101011110', ('ПРП', 'ПП')),
    ('100101010100', ('ПРН', 'ОК3'))
]




for i, (c, (c1, c2)) in enumerate(tasks, 1):
    if 'КБ' in [c1, c2] or 'ПВ(' in c1 + c2:
        continue
    print('Завдання', i)
    code[c1](c)
    code[c2](c)
    print('')
    #exit()



#test = [[0,0], [1,1], [1,0], [0, 1]]
#for t in test:
  #print(t, sum(t) % 2)