"""
    8. Să se genereze toate numerele (în reprezentare binară) cuprinse între 1 și n.
       De ex. dacă n = 4, numerele sunt: 1, 10, 11, 100.
"""


def DecimalToBinary(num):
    """
    Time complexity: O(k * log(num)), where k is the number of digits in the binary representation of num
    :param num: int
    """
    if num >= 1:
        DecimalToBinary(num // 2)   # division by 2
    print(num % 2, end='')  # the rest that is print in reverse order because of the stack


def result(n):
    """
    Time complexity: O(n * k * log(n)),
    where k is the maximum number of digits in the binary representation of any number from 1 to n
    :param n: int
    """
    # calling function for every number from the decimal interval [1,n] and print it
    for i in range(1, n + 1):
        DecimalToBinary(i)
        if i < n:
            print(", ", end='')


def test_result():
    print("\nPt n = 1: ", end='')
    result(1)  # easy test
    print("\nPt n = 2: ", end='')
    result(2)  # medium test
    print("\nPt n = 3: ", end='')
    result(3)  # medium test
    print("\nPt n = 100 ", end='')
    result(100)  # hard test


if __name__ == '__main__':
    # the highest number of the decimal interval
    n = int(input("n = "))
    result(n)
    test_result()
