"""
    6. Pentru un șir cu n numere întregi care conține și duplicate,
       să se determine elementul majoritar (care apare de mai mult de n / 2 ori).
       De ex. 2 este elementul majoritar în șirul [2,8,7,2,2,5,2,3,1,2,2].
"""


def majorant_elem(length, lst):
    """
    Total complexity: O(n), where n is number of elements in arr
    :param length: length of lst = n
    :param lst: list of int
    :return: the keys from the result
    """
    count = {}  # the dict where the key is the number and value is the count, complexity O(n)
    arr = []  # the list where i put the results
    # cont how many times appears every number, complexity O(n)
    for word in lst:
        count[word] = count.get(word, 0) + 1
    # check what number appears length//2 times and add it to the result, complexity O(m),where m = nmb of unique nmb
    for key in count.keys():
        if count[key] == length // 2:
            arr.append(key)
    return arr


def test_majorant_elem():
    assert (majorant_elem(5, [1, 2, 2, 3, 4]) == [2])  # easy test
    assert (majorant_elem(6, [1, 1, 1, 2, 2, 2]) == [1, 2])  # medium test
    assert (majorant_elem(2, [1, 2]) == [1, 2])  # medium test
    assert (majorant_elem(2, [1, 1]) == [])  # hard test
    assert (majorant_elem(1, [1]) == [])  # hard test
    print("All tests are working :)")


if __name__ == '__main__':
    my_list = []
    n = int(input("n = "))
    for i in range(1, n + 1):
        number = int(input())
        my_list.append(number)
    print(majorant_elem(n, my_list))
    test_majorant_elem()
