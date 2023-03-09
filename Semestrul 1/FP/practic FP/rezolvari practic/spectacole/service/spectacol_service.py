from domain.spectacol import Spectacol


class SpectacolService:
    def __init__(self, repo):
        self.__repo = repo

    def adaugare(self, titlu, artist, gen, durata):
        spectacol = Spectacol(titlu=titlu, artist=artist, gen=gen, durata=durata)
        self.__repo.add(spectacol)

    def modificare(self, titlu, artist, gen, durata):
        res = self.__repo.update(titlu, artist, gen, durata)
        return res

    def filtrare_fisier(self):
        lista = self.__repo.sortare()
        return lista

    def adaugare_random(self, titlu, artist, gen, durata):
        lista = []
        spectacol = Spectacol(titlu=titlu, artist=artist, gen=gen, durata=durata)
        lista.append(spectacol)
        self.__repo.add(spectacol)
        return lista
