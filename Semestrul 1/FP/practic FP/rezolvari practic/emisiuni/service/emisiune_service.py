from domain.emisiune import Emisiune


class EmisiuneService:
    def __init__(self, repo):
        self.__repo = repo

    def modificare(self, nume, tip, durata, descriere, tip_blocare):
        res = self.__repo.update(nume, tip, durata, descriere, tip_blocare)
        return res

    def stergere(self, nume, tip, tip_blocare):
        res = self.__repo.delete(nume, tip, tip_blocare)
        return res

