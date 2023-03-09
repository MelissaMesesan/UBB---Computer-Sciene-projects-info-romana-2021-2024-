"""
    MAI TREBUIE FACUTE TESTE SI CATEVA SPECIFICATII :)
"""
class Jucator:
    def __init__(self, nume, prenume, inaltime, post):
        """
        Initializarea clasei jucator
        :param nume: numele jucatorului -str
        :param prenume: prenumele jucatorului -str
        :param inaltime: inaltimea jucatorului -int
        :param post: postul jucatorului -str
        """
        self.__nume = nume
        self.__prenume = prenume
        self.__inaltime = inaltime
        self.__post = post

    def __str__(self):
        return f'{self.__nume};{self.__prenume};{self.__inaltime};{self.__post}\n'

    def __repr__(self):
        return f'{self.__nume};{self.__prenume};{self.__inaltime};{self.__post}\n'

    def get_nume(self):
        """
        extrage entittatea nume
        :return: numele jucatorului -str
        """
        return self.__nume

    def get_prenume(self):
        return self.__prenume

    def get_inaltime(self):
        return self.__inaltime

    def get_post(self):
        return self.__post

    def set_inaltime(self, inaltime):
        """
        seteaza entitiatea inaltime
        :param inaltime: inaltimea jucatorului -int
        :return:
        """
        self.__inaltime = inaltime

    def set_post(self, post):
        self.__post = post
