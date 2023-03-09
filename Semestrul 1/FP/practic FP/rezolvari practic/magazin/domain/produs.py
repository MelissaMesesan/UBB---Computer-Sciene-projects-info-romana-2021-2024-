"""
    MAI TREBUIE TESTE,
    SPECIFICATII,
    REVIZUITA STERGEREA SI
    DE INTREBAT CAND TREBUIE SA FIE AFISATA FILTRAREA (MEREU SAU LA SB 4?)
"""


class Produs:
    def __init__(self, id_produs, denumire, pret):
        self.__id_produs = id_produs
        self.__denumire = denumire
        self.__pret = pret

    def __str__(self):
        return f'{self.__id_produs};{self.__denumire};{self.__pret}\n'

    def __repr__(self):
        return f'{self.__id_produs};{self.__denumire};{self.__pret}\n'

    def get_id_produs(self):
        return self.__id_produs

    def get_denumire(self):
        return self.__denumire

    def get_pret(self):
        return int(self.__pret)
