class UI:
    def __init__(self, repo, service):
        self.__repo = repo
        self.__service = service

    def menu(self):
        print("1. Adauga produs")
        print("2. Sterge produs")
        print("3. Filtrare")
        print("4. Undo stergere")
        print("menu. Meniu")
        print("x. Exit")

    def get_id(self):
        id_produs = input("Id produs: ")
        ok = 1
        while ok:
            if not id_produs.isnumeric():
                ok = 1
                print("Trebuie sa fie un numar!!!")
                id_carte = input("Id produs: ")
            else:
                if int(id_produs) < 0:
                    ok = 1
                    print("Trebuie sa fie un numar pozitiv!!!")
                    id_carte = input("Id produs: ")
                else:
                    ok = 0

        return int(id_produs)

    def get_denumire(self):
        denumire = input("Denumire: ")
        ok = 1
        while ok:
            if denumire == "":
                ok = 1
                print("Denumirea nu poate sa fie vid!!!")
                titlu = input("Denumire: ")
            else:
                ok = 0
        return denumire

    def get_pret(self):
        pret = input("Pret: ")
        ok = 1
        while ok:
            if not pret.isnumeric():
                ok = 1
                print("Trebuie sa fie un numar!!!")
                pret = input("Pret: ")
            else:
                if int(pret) < 0:
                    ok = 1
                    print("Trebuie sa fie un numar pozitiv!!!")
                    pret = input("Pret: ")
                else:
                    ok = 0
        return int(pret)

    def adaugare(self):
        id_produs = self.get_id()
        denumire = self.get_denumire()
        pret = self.get_pret()
        self.__service.add_produs(id_produs, denumire, pret)

    def sterge_dupa_pret(self):
        numar = int(input("Numarul pe care sa il contina id'ul: "))
        self.__service.sterge_produs(numar)

    def undo(self):
        for i in self.__service.lista:
            self.__repo.add(i)

    def mesaj_filtrare(self, denumire, pret):
        print("Filtrul curest este titlu: "+denumire+" si anul aparitiei: "+str(pret))

    def filtru(self):
        print(self.__service.filtru("",-1))
        self.mesaj_filtrare("", -1)
        denumire = input("Denumire: ")
        pret = int(input("Pret: "))
        print(self.__service.filtru(denumire, pret))
        self.mesaj_filtrare(denumire, pret)


    def start(self):
        self.menu()
        while True:
            option = input("Alege optiune: ")
            if option == "1":
                self.adaugare()
            if option == "2":
                self.sterge_dupa_pret()
            if option == "3":
                self.filtru()
            if option == "4":
                self.undo()
            if option == "menu":
                self.menu()
            if option == "x":
                print("Exit!")
                break
