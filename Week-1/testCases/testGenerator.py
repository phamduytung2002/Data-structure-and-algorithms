import random
import os

MAX_ABS = 10**3

def gen(size, fileName):
    with open(f'Week-1/testCases/{fileName}', 'w') as f:
        f.write(str(size) + '\n')
        f.write(str(random.randint(-MAX_ABS, MAX_ABS)))
        for _ in range(size-1):
            f.write(' ' + str(random.randint(-MAX_ABS, MAX_ABS)))

os.makedirs('Week-1/testCases', exist_ok=True)
for i in range(4):
    gen(1000, f'1e3_{i}.txt')
    gen(10000, f'1e4_{i}.txt')
    gen(100000, f'1e5_{i}.txt')
    gen(1000000, f'1e6_{i}.txt')