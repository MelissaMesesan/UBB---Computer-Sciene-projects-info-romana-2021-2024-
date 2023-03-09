"""
    MAI TREBUIE TESTE, SPECIFICATII SI REVIZUITA STERGEREA
"""

class Carte:
    def __init__(self, id_carte, titlu, autor, an_aparitie):
        self.__id_carte = id_carte
        self.__titlu = titlu
        self.__autor = autor
        self.__an_aparitie = an_aparitie

    def __str__(self):
        return f'{self.__id_carte};{self.__titlu};{self.__autor};{self.__an_aparitie}\n'

    def __repr__(self):
        return f'{self.__id_carte};{self.__titlu};{self.__autor};{self.__an_aparitie}\n'

    def get_id_carte(self):
        return self.__id_carte

    def get_titlu(self):
        return self.__titlu

    def get_autor(self):
        return self.__autor

    def get_an_aparitie(self):
        return int(self.__an_aparitie)