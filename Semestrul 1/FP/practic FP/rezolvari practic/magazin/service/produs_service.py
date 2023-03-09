from domain.produs import Produs


class ProdusService:
    def __init__(self, repo):
        self.__repo = repo
        self.lista = []

    def add_produs(self, id_produs, denumire, pret):
        produs = Produs(id_produs=id_produs, denumire=denumire, pret=pret)
        self.__repo.add(produs)

    def sterge_produs(self, numar):
        for produs in self.__repo.produse:
            # print(carte.get_an_aparitie())
            id_produs = produs.get_id_produs()
            ok = 0
            while id_produs > 0:
                uc = id_produs % 10
                if uc == numar:
                    ok = 1
                id_produs = id_produs / 10
            if ok == 1:
                self.lista.append(produs)
                res = self.__repo.stergere(produs.get_id_produs())
                if res == True:
                    print("Cartile au fost sterse cu succes!")

    def filtru(self, denumire, pret):
        lista = []
        for produs in self.__repo.produse:
            if produs.get_denumire() == denumire and produs.get_pret() < pret:
                lista.append(produs)
        if denumire == "" and pret == -1:
            lista.append(self.__repo.produse)
        return lista
