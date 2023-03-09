"""
    1. Să se determine ultimul (din punct de vedere alfabetic) cuvânt care
       poate apărea într-un text care conține mai multe cuvinte separate prin ” ” (spațiu).
       De ex. ultimul (dpdv alfabetic) cuvânt din ”Ana are mere rosii si galbene”
       este cuvântul "si".
"""


def last_word(text):
    """
    The function determines the alphabetically last word in a text
    :param text: a text of words
    :return: the first element of a sorted reversed list
    Total time complexity: O(n log n)
    """
    # put into a list every word transformed in lower caps
    words = [word.lower() for word in text.split()]     # time complexity: O(n), where n is the number of words

    # sort the list reversed to get the first position
    my_list = sorted(words, reverse=True)   # time complexity: O(n log n), where n is the length of the list

    # return the first position, witch is the highest word
    return my_list[0]   # time complexity: O(1)


def test_last_word():
    assert (last_word("Ana are mere") == "mere")  # easy test
    assert (last_word("Ana") == "ana")  # medium test
    assert (last_word("ax az ay") == "az")  # hard test
    print("Tests are working :)")


if __name__ == '__main__':
    line = input("Give the text: ")
    print(last_word(line))
    test_last_word()
