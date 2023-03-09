"""
    10. Considerându-se o matrice cu n x m elemente binare (0 sau 1)
        sortate crescător pe linii, să se identifice indexul liniei
        care conține cele mai multe elemente de 1.
"""


def line_with_max_ones(matrix):
    """
    Time complexity: O(nm), where n,m ar ethe dimension of the matrix
    :param matrix: matrix n*m dimension
    :return: the row with max ones
    """
    index_line = 0
    max_1 = 0
    for i, ln in enumerate(matrix):  # read the matrix
        nmb_1 = ln.count(1)  # counts the number of ones in the current row using the count method of the list object
        if nmb_1 > max_1:  # find the max row with ones
            max_1 = nmb_1
            index_line = i
    return index_line  # return the row


def test_line_with_max_ones():
    matrix = [[0, 0, 0, 1, 1],
              [0, 1, 1, 1, 1],
              [0, 0, 1, 1, 1]]
    assert (line_with_max_ones(matrix) == 1)
    matrix = [[1, 1, 1, 1, 1],
              [0, 1, 1, 1, 1],
              [0, 0, 1, 1, 1]]
    assert (line_with_max_ones(matrix) == 0)
    matrix = [[0, 0, 0, 1, 1],
              [0, 1, 1, 1, 1],
              [0, 1, 1, 1, 1],
              [1, 1, 1, 1, 1],
              [0, 0, 1, 1, 1]]
    assert (line_with_max_ones(matrix) == 3)
    matrix = [[0, 0, 0, 1, 1, 1, 1],
              [0, 1, 1, 1, 1, 0, 0],
              [0, 0, 1, 1, 1, 1, 1]]
    assert (line_with_max_ones(matrix) == 2)
    print("All tests are working :)")


if __name__ == "__main__":
    test_line_with_max_ones()
