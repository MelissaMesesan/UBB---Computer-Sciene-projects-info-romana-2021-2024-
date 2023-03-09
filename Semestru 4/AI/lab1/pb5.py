"""
    5. Pentru un șir cu n elemente care conține valori din mulțimea
       {1, 2, ..., n - 1} astfel încât o singură valoare se repetă
       de două ori, să se identifice acea valoare care se repetă.
       De ex. în șirul [1,2,3,4,2] valoarea 2 apare de două ori.
"""


def value_two_times(arr):
    """
    Total complexity: O(n), where n is number of elements in arr
    :param arr: list of int
    :return: the result key or False if there isn't any
    """
    count = {}  # the dict where the key is the number and value is the count, complexity O(n)
    list_of_numbers = arr.split()   # put every number is a position of the list
    # cont how many times appears every number, complexity O(n)
    for nmb in list_of_numbers:
        count[nmb] = count.get(nmb, 0) + 1
    # check what number appears one time and return it, complexity O(m), where m = number of unique numbers
    for key in count.keys():
        if count[key] == 2:
            return key
    return False    # there isn't any duplicates


def test_value_two_times():
    assert (value_two_times("1 2 3 4 2") == "2")  # where n = 5
    assert (value_two_times("1 2 3 4 5 6 6 7 8 9") == "6")  # where n = 10
    print("All tests are working :)")


if __name__ == '__main__':
    input_line = input("Enter a list of numbers: ")
    print(value_two_times(input_line))
    test_value_two_times()
