"""
    MAI TREBUIE FACUTE TESTE SI SPECIFICATII + modificat la 3) sa nu fie identic cu exemplul :)
"""


class Emisiune:
    def __init__(self, nume, tip, durata, descriere):
        self.__nume = nume
        self.__tip = tip
        self.__durata = durata
        self.__descriere = descriere

    def __str__(self):
        return f'{self.__nume};{self.__tip};{self.__durata};{self.__descriere}'

    def __repr__(self):
        return f'{self.__nume};{self.__tip};{self.__durata};{self.__descriere}'

    def get_nume(self):
        return self.__nume

    def get_tip(self):
        return self.__tip

    def set_durata(self, durata):
        self.__durata = durata

    def set_descriere(self, descriere):
        self.__descriere = descriere
