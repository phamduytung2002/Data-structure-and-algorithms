import copy
import time
from datetime import datetime
import os

TIME_LIMIT = 10

def bruteForce(listOfNumbers):
    print('Running brute force\n')
    startTime = time.time()
    n = len(listOfNumbers)
    res = -10**100
    summ = 0
    for i in range(n):
        for j in range(i, n):
            currentList = listOfNumbers[i:j+1]
            summ = sum(currentList)
            if summ > res:
                res = summ
            if time.time() > startTime + TIME_LIMIT:
                return (TIME_LIMIT, res)
    return (time.time() - startTime, res)

def bruteForceWithImprovement(listOfNumbers):
    print('Running brute force with improvement\n')
    startTime = time.time()
    n = len(listOfNumbers)
    res = -10**100
    for i in range(n):
        sum = 0
        for j in range(i,n):
            sum += listOfNumbers[j]
            if sum > res:
                res = sum
            if time.time() > startTime + TIME_LIMIT:
                return (TIME_LIMIT, res)
    return (time.time() - startTime, res)

def dynamicProgramming(listOfNumbers):
    print('Running dp\n')
    startTime = time.time()
    n = len(listOfNumbers)
    useLastElement = copy.deepcopy(listOfNumbers)
    notUseLastElement = [0 for _ in listOfNumbers]
    for i in range(1, n):
        notUseLastElement[i] = max(notUseLastElement[i-1], useLastElement[i-1])
        useLastElement[i] = max(useLastElement[i-1], 0) + listOfNumbers[i]
    return (time.time() - startTime, max(notUseLastElement[n-1], useLastElement[n-1]))

if __name__ == "__main__":
    resultFile = "Week-1/result/py37_result.txt"
    testDir = "Week-1/testCases"
    testCases = os.listdir(testDir)
    for i in range(len(testCases)):
        testCases[i] = testDir + '/' + testCases[i]

    with open(resultFile, 'a') as f:
        f.write(f'{datetime.now()}\n')
    
    for logSize in range(3,7):
        with open(resultFile, 'a') as f:
            f.write(f'\t1e{logSize}\n')
        for path in testCases:
            if f'1e{logSize}' in path:
                print(f"Running file {path.split('/')[-1]}\n")
                with open(resultFile, 'a') as f:
                    f.write(f"\t\t{path.split('/')[-1]}\n")
                testCase = []
                with open(path, 'r') as test:
                    n = next(test)
                    testCase = [int(x) for x in next(test).split()]
                bfRes = bruteForce(testCase)
                bfiRes = bruteForceWithImprovement(testCase)
                dpRes = dynamicProgramming(testCase)
                with open(resultFile, 'a') as f:
                    f.write(f"\t\t\tbrute force:                    {bfRes[0]}\n")
                    f.write(f"\t\t\tbrute force with imporvement:   {bfiRes[0]}\n")
                    f.write(f"\t\t\tdynamic programming:            {dpRes[0]}\n")
                    if bfRes[1]==bfiRes[1] and bfRes[1]==dpRes[1]:
                        f.write(f"\t\t\t\tconsistent result\n")