from domain.melodie import Melodie


class MelodieService:
    def __init__(self, repo):
        self.__repo = repo

    # def adaugare(self, titlu, artist, gen, durata):
    #     spectacol = Spectacol(titlu=titlu, artist=artist, gen=gen, durata=durata)
    #     self.__repo.add(spectacol)

    def modificare(self, titlu, artist, gen, data):
        res = self.__repo.update(titlu, artist, gen, data)
        return res

    def filtrare_fisier(self):
        lista = self.__repo.sortare()
        return lista

    def adaugare_random(self, titlu, artist, gen, data):
        lista = []
        melodie = Melodie(titlu=titlu, artist=artist, gen=gen, data=data)
        lista.append(melodie)
        self.__repo.add(melodie)
        return lista
