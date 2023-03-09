"""
    MAI TREBUIE TESTE SI SPECIFICATII
"""


class Melodie:
    def __init__(self, titlu, artist, gen, data):
        self.__titlu = titlu
        self.__artist = artist
        self.__gen = gen
        self.__data = data

    def __str__(self):
        return f'{self.__titlu};{self.__artist};{self.__gen};{self.__data}'

    def __repr__(self):
        return f'{self.__titlu};{self.__artist};{self.__gen};{self.__data}'

    def get_titlu(self):
        return self.__titlu

    def get_artist(self):
        return self.__artist

    def get_data(self):
        return str(self.__data)

    def set_gen(self, gen):
        self.__gen = gen

    def set_data(self, data):
        self.__data = data
