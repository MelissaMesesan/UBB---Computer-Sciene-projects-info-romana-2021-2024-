"""
    2. Să se determine distanța Euclideană între două locații identificate
       prin perechi de numere. De ex. distanța între (1,5) și (4,1) este 5.0
"""

import math


def euclid(p1, p2):
    """
    Complexity is O(1)
    :param p1: int
    :param p2: int
    :return: euclid distance
    """
    # points on the axes
    x1, y1 = p1
    x2, y2 = p2
    # euclid equation
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)


def test_euclid():
    assert (euclid((1, 5), (4, 1)) == 5.0)  # easy test
    assert (euclid((0, 5), (0, -1)) == 6.0)  # medium test
    assert (euclid((100, 1), (0, 80)) == 127.4401820463232)  # hard test
    assert (euclid((-123, 123), (999, -999)) == 1586.7476169826127)  # hard test
    print("Tests are working :)")


if __name__ == '__main__':
    point1 = (1, 5)
    point2 = (4, 1)
    print(euclid(point1, point2))
    test_euclid()
