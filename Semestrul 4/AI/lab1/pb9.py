"""
    9. Considerându-se o matrice cu n x m elemente întregi
       și o listă cu perechi formate din coordonatele a 2 căsuțe
       din matrice ((p,q) și (r,s)), să se calculeze suma elementelor
       din sub-matricile identificate de fieare pereche.
"""


def sum_submatrix(matrix, pairs):
    """
    The time complexity of this code is O(nm * k * (r-p+1)(s-q+1)),
    where n and m are the dimensions of the original matrix and k is the length of the pairs list,
    submatrix has dimensions r-p+1 by s-q+1.
    :param matrix: n*m dimension
    :param pairs: ((p,q) and (r,s))
    :return: the sum of submatrix
    """
    results = []  # empty list where we store the result
    for pair in pairs:
        p, q = pair[0]  # assigns the first element of the current pair to p and the second element to q
        r, s = pair[1]  # assigns the third element of the current pair to r and the fourth element to s
        submatrix = [row[q:s + 1] for row in matrix[p:r + 1]]  # extracts the submatrix
        # => each row in the p:r+1 range, starting at q and ending at s+1
        submatrix_sum = sum(sum(submatrix, []))  # the inner sum function flattens the list of lists into a single list,
        # and the outer sum function calculates the sum of all the elements in that list.
        results.append(submatrix_sum)
    return results


def test_sum_submatrix():
    matrix = [[0, 2, 5, 4, 1],
              [4, 8, 2, 3, 7],
              [6, 3, 4, 6, 2],
              [7, 3, 1, 8, 3],
              [1, 5, 7, 9, 4]]
    pairs1 = [((1, 1), (3, 3)), ((2, 2), (4, 4))]
    assert (sum_submatrix(matrix, pairs1) == [38, 44])
    pairs2 = [((1, 1), (2, 2)), ((3, 3), (4, 4))]
    assert (sum_submatrix(matrix, pairs2) == [17, 24])
    pairs3 = [((1, 1), (1, 1)), ((1, 1), (1, 1)), ((1, 1), (1, 1))]
    assert (sum_submatrix(matrix, pairs3) == [8, 8, 8])
    pairs4 = [((1, 1), (5, 5))]
    assert (sum_submatrix(matrix, pairs4) == [75])
    print("All tests are working :)")


if __name__ == "__main__":
    matrix = [[0, 2, 5, 4, 1],
              [4, 8, 2, 3, 7],
              [6, 3, 4, 6, 2],
              [7, 3, 1, 8, 3],
              [1, 5, 7, 9, 4]]
    pairs = [((2, 2), (5, 5))]
    print(sum_submatrix(matrix, pairs))
    test_sum_submatrix()
