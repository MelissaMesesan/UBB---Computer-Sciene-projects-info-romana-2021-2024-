"""
    4. Să se determine cuvintele unui text care apar exact o singură dată în acel text.
       De ex. cuvintele care apar o singură dată în ”ana are ana are mere rosii ana"
       sunt: 'mere' și 'rosii'.
"""


def word_just_one_time(text):
    """
    Total complexity: O(n), where n is the number of words in text
    :param text: text line
    :return: list with the result
    """
    count = {}  # the dict where the key is the word and value is the count, complexity O(n)
    my_list = []  # list with the result
    list_of_words = text.split()  # put every word is a position of the list
    # cont how many times appears every word, complexity O(n)
    for word in list_of_words:
        count[word] = count.get(word, 0) + 1
    # check what word appears one time and put it in the result list, complexity O(m), where m = number of unique words
    for key in count.keys():
        if count[key] == 1:
            my_list.append(key)
    return my_list  # return the result list


def test_word_just_one_time():
    assert (word_just_one_time("Ana are are") == ["Ana"])  # easy test
    assert (word_just_one_time("Ana ana") == ["Ana", "ana"])  # medium test
    assert (word_just_one_time("an") == ["an"])  # hard test
    assert (word_just_one_time("aa aa") == [])  # hard test
    print("All tests are working :)")


if __name__ == '__main__':
    input_line = input("Enter a Line : ")
    print(word_just_one_time(input_line))
    test_word_just_one_time()
