"""
    MAI TREBUIE TESTE SI SPECIFICATII + verificare daca exista in fisier spectacolulla modificare
"""

class Spectacol:
    def __init__(self, titlu, artist, gen, durata):
        self.__titlu = titlu
        self.__artist = artist
        self.__gen = gen
        self.__durata = durata

    def __str__(self):
        return f'{self.__titlu};{self.__artist};{self.__gen};{self.__durata}'

    def __repr__(self):
        return f'{self.__titlu};{self.__artist};{self.__gen};{self.__durata}'

    def get_titlu(self):
        return self.__titlu

    def get_artist(self):
        return self.__artist

    def set_gen(self, gen):
        self.__gen = gen

    def set_durata(self, durata):
        self.__durata = durata
