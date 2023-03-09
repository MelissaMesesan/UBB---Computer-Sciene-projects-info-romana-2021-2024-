class UI:
    def __init__(self, repo, service):
        self.__repo = repo
        self.__service = service

    def menu(self):
        print("1. Adauga carte")
        print("2. Sterge carte")
        print("3. Filtrare")
        print("4. Undo stergere")
        print("menu. Meniu")
        print("x. Exit")

    def get_id(self):
        id_carte = input("Id carte: ")
        ok = 1
        while ok:
            if not id_carte.isnumeric():
                ok = 1
                print("Trebuie sa fie un numar!!!")
                id_carte = input("Id carte: ")
            else:
                if int(id_carte) < 0:
                    ok = 1
                    print("Trebuie sa fie un numar pozitiv!!!")
                    id_carte = input("Id carte: ")
                else:
                    ok = 0

        return int(id_carte)

    def get_titlu(self):
        titlu = input("Titlu: ")
        ok = 1
        while ok:
            if titlu == "":
                ok = 1
                print("Titlul nu poate sa fie vid!!!")
                titlu = input("Titlu: ")
            else:
                ok = 0
        return titlu

    def get_autor(self):
        autor = input("Autor: ")
        ok = 1
        while ok:
            if autor == "":
                ok = 1
                print("Autorul nu poate sa fie vid!!!")
                autor = input("Autor: ")
            else:
                ok = 0
        return autor

    def get_an_aparitie(self):
        an = input("An aparitie: ")
        ok = 1
        while ok:
            if not an.isnumeric():
                ok = 1
                print("Trebuie sa fie un numar!!!")
                an = input("An aparitie: ")
            else:
                if int(an) < 0:
                    ok = 1
                    print("Trebuie sa fie un numar pozitiv!!!")
                    an = input("An aparitie: ")
                else:
                    ok = 0
        return int(an)

    def adaugare(self):
        id_carte = self.get_id()
        titlu = self.get_titlu()
        autor = self.get_autor()
        an = self.get_an_aparitie()
        self.__service.add_carte(id_carte, titlu, autor, an)

    def sterge_dupa_an(self):
        numar = int(input("Numarul pe care sa il contina anul aparitiei: "))
        self.__service.sterge_carte(numar)

    def undo(self):
        for i in self.__service.lista:
            self.__repo.add(i)

    def mesaj_filtrare(self, titlu, an):
        print("Filtrul curest este titlu: "+titlu+" si anul aparitiei: "+str(an))

    def filtru(self):
        print(self.__service.filtru("",-1))
        self.mesaj_filtrare("", -1)
        titlu = input("Titlul: ")
        an = int(input("Anul aparitiei: "))
        print(self.__service.filtru(titlu, an))
        self.mesaj_filtrare(titlu, an)


    def start(self):
        self.menu()
        while True:
            option = input("Alege optiune: ")
            if option == "1":
                self.adaugare()
            if option == "2":
                self.sterge_dupa_an()
            if option == "3":
                self.filtru()
            if option == "4":
                self.undo()
            if option == "menu":
                self.menu()
            if option == "x":
                print("Exit!")
                break
