"""
    7. Să se determine al k-lea cel mai mare element al unui șir
       de numere cu n elemente (k < n).
       De ex. al 2-lea cel mai mare element din șirul [7,4,6,3,9,1] este 7.
"""


def no_duplicates(list):
    """
    Total complexity is O(n^2), where n is number of elements in list
    :param list: list of int
    :return: list without duplicates
    """
    my_list = []  # empty list where i save the initial list without duplicates
    for number in list:
        if number not in my_list:
            my_list.append(number)
    return my_list  # return the list without duplicates


def quicksort_reverse(arr):
    """
    Total complexity: O(n*log n), where n is the length of arr
    :param arr: list of int
    :return: sorted reversed list
    """
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x > pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x < pivot]
    return quicksort_reverse(left) + middle + quicksort_reverse(right)


def the_k_greatest(arr, k):
    """
    Time complexity of O(N*logN) and a space complexity of O(N), where N is the length of the input list arr
    :param arr: list
    :param k: int
    :return: final result
    """
    my_list = quicksort_reverse(no_duplicates(arr))  # sort end eliminate the duplicates
    return my_list[k - 1]  # return the k biggest number of the list, that is the k position from the list


def test_the_k_greatest():
    assert (the_k_greatest([5, 4, 3, 2, 1], 2) == 4)  # easy test
    assert (the_k_greatest([1, 1, 2, 3, 2, 3, 4, 5], 2) == 4)  # medium test
    assert (the_k_greatest([1, 5, 6, 7, 3, 9, 1, 6], 4) == 5)  # medium test
    assert (the_k_greatest([1, 5, 2, 7, 3, 9, 1, 7, 8, 3, 7, 1, 4], 7) == 2)  # hard test
    print("All tests are working :)")


if __name__ == "__main__":
    test_the_k_greatest()
    my_list = []
    k = int(input("k = "))
    n = int(input("n = "))
    for i in range(1, n + 1):
        number = int(input())
        if number not in my_list:
            my_list.append(number)
    print(the_k_greatest(my_list, k))
