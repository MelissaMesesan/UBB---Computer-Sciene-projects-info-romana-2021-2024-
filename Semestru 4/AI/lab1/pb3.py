"""
    3. Să se determine produsul scalar a doi vectori rari
       care conțin numere reale. Un vector este rar atunci
       când conține multe elemente nule. Vectorii pot avea
       oricâte dimensiuni. De ex. produsul scalar a 2 vectori unisimensionali
       [1,0,2,0,3] și [1,2,0,3,1] este 4.
"""


def produs_scalar(a, b):
    """
    Time complexity: O(n^2), where x is the number of dimensions of the rare vector
    :param a: vector
    :param b: vector
    :return: result
    """
    suma = 0
    for i in range(0, len(a)):
        suma = suma + a[i] * b[i]
    return suma


def test_produs_scalar():
    assert (produs_scalar([1, 0, 2, 0, 3], [1, 2, 0, 3, 1]) == 4)
    assert (produs_scalar([5, 0, 2, 0, 3], [5, 2, 0, 3, 1]) == 28)
    assert (produs_scalar([0], [0]) == 0)
    print("All tests are working :)")


if __name__ == '__main__':
    test_produs_scalar()
