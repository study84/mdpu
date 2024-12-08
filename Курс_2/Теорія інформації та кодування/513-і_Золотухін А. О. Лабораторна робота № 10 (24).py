# 513-і Золотухін Андрій
# Теорія інформації та кодування
# Laba - 10

def coding(value_str):
  def find_check_bits(k):
      r = 0  # Изначально предполагаем, что проверочных битов нет
      while True:
          # Вычисляем левую часть неравенства
          if 2**r >= k + r + 1:
              return r
          r += 1

  print(value_str)
  value = list(map(int, value_str))
  print(value)
  
  k = len(value_str)
  r = find_check_bits(k)
  print(f"k =  {k}, r = {r}")
  for i in range(r):
    value.insert((2 ** i) - 1, 0)
  print(value)
  
  indexes = [(2 ** i, (2 ** i) - 1, i) for i in range(r)]
  print(indexes)
  
  for i, ia, p in indexes:
    print(' ', i, ia, p, 2 ** (p + 1), range(ia, k + r, 2 ** (p + 1)))
    for j in range(ia, k + r, 2 ** (p + 1)):
      print('  ', j, i, j + i, value[j:j + i])
      value[ia] = sum(value[j:j + i])
    value[ia] = value[ia] % 2
      
  print(f'Coding: {value_str} >> {value}')
  


def checking(value_str):
  print(value_str)
  value = list(map(int, value_str))
  print(value)
  
  k = len(value_str)
  p = 0
  while (2 ** p - 1) <= len(value):
    p += 1
    
  print(p, [i for i in range(p)])
  
  indexes = [(2 ** i, (2 ** i) - 1, i) for i in range(p)]
  print(indexes)
  
  check = dict()
  for i, ia, p in indexes:
    check[ia] = (ia, value[ia], [])
    print(' ', i, ia, p, 2 ** (p + 1), range(ia, k + p, 2 ** (p + 1)))
    for j in range(ia, k + p, 2 ** (p + 1)):
      print('  ', j, i, j + i, value[j:j + i])
      check[ia][2].append(sum(value[j:j + i]))
    print('  ', check[ia])
    
  result = []
  for c in check:
    ia, v, vs = check[c]
    #print(ia, v, vs, sum(vs) - v, v == (sum(vs) - v) % 2)
    result.append((ia, v, vs, sum(vs) - v, v == (sum(vs) - v) % 2))
  
  error, pos = None, 0
  for r in result:
    print(r)
    if not r[4]:
       error = True
       pos += r[0] + 1
  
  print(f'{value_str}, error: {error}, position: {pos}')



print('############################################')

data = ['1111101', '1010', '010110110101', '10110101']
#coding(data[-1])

data = ['1100000011101', '1111000111111', '000011111101', '1111101', '1111100011', '00010001101', '110000001', '00111100111', '0011111001101']
#coding(data[-1])


data = ['011101100101', '001101100111']
data = ['1010011', '111111111', '110000', '110111110', '110100000', '11000000', '110110100', '111010011110', '101011111111', '10111110001111011101', '0111111110101010011101']
checking(data[-1])

  
  
  
