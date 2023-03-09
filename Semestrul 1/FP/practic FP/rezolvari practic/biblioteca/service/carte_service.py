from domain.carte import Carte


class CarteService:
    def __init__(self, repo):
        self.__repo = repo
        self.lista = []

    def add_carte(self, is_carte, titlu, autor, an_apaitie):
        carte = Carte(id_carte=is_carte, titlu=titlu, autor=autor, an_aparitie=an_apaitie)
        self.__repo.add(carte)

    def sterge_carte(self, numar):
        for carte in self.__repo.carti:
            # print(carte.get_an_aparitie())
            an_aparitie = carte.get_an_aparitie()
            ok = 0
            while an_aparitie > 0:
                uc = an_aparitie % 10
                if uc == numar:
                    ok = 1
                an_aparitie = an_aparitie / 10
            if ok == 1:
                self.lista.append(carte)
                res = self.__repo.stergere(carte.get_an_aparitie())
                if res == True:
                    print("Cartile au fost sterse cu succes!")

    def filtru(self, titlu, an):
        lista = []
        for carte in self.__repo.carti:
            if carte.get_titlu() == titlu and carte.get_an_aparitie() < an:
                lista.append(carte)
        if titlu == "" and an == -1:
            lista.append(self.__repo.carti)
        return lista
