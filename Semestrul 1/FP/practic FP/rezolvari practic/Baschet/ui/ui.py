class UI:
    def __init__(self, repo, service):
        self.__repo = repo
        self.__service = service

    def menu(self):
        print("1. Adaugare")
        print("2. Modificare")
        print("3. Echipa cu inaltimea medie cea mai mare")
        print("4. Importa din fisier jucatorii care nu sunt in lista + random")
        print("menu. menu")
        print("x. Exit")
        print()

    def get_nume(self):
        nume = input("Nume: ")
        ok = 1
        while ok:
            if nume == "":
                ok = 1
                print("Numele nu poate sa fie vid!!!")
                nume = input("Nume: ")
            else:
                ok = 0
        return nume

    def get_prenume(self):
        prenume = input("Prenume: ")
        ok = 1
        while ok:
            if prenume == "":
                ok = 1
                print("Prenumele nu poate sa fie vid!!!")
                nume = input("Preume: ")
            else:
                ok = 0
        return prenume

    def get_inaltime(self):

        inaltime = input("Inaltime: ")
        ok = 1
        while ok:
            if not inaltime.isnumeric():
                ok = 1
                print("Trebuie sa fie un numar in cm!!!")
                inaltime = input("Inaltime: ")
            else:
                if int(inaltime) < 0:
                    ok = 1
                    print("Trebuie sa fie un numar pozitiv!!!")
                    inaltime = input("Inaltime: ")
                else:
                    ok = 0

        return int(inaltime)

    def get_post(self):
        lista = ["fundas", "pivot", "estrema"]
        post = input("Post: ")
        ok = 1
        while ok:
            if post not in lista:
                print("Postul nu este corect!!!")
                ok = 1
                post = input("Post: ")
            else:
                ok = 0
        return post

    def adaugare(self):
        nume = self.get_nume()
        prenume = self.get_prenume()
        inaltime = self.get_inaltime()
        post = self.get_post()
        self.__service.add_jucator(nume, prenume, inaltime, post)

    def modificare(self):
        nume = self.get_nume()
        prenume = self.get_prenume()
        inaltime = self.get_inaltime()
        self.__service.modifica(nume, prenume, inaltime)

    def get_echipa(self):
        print(self.__service.echipa())

    def importa_random(self):
        filename = input("Introduceti numele fisierului de unde vreti sa extrageti date: ")
        fisiere = ["citire.txt", "citire1.txt", "citire2.txt"]
        ok = 1
        while ok:
            if filename not in fisiere:
                ok = 1
                print("Acesta nu este nu fisier existent!")
                filename = input("Introduceti numele fisierului de unde vreti sa extrageti date: ")
            else:
                ok = 0

        self.__service.importa(1, filename)
        print("In total sunt", self.__service.nr_total(), "jucatori")

    def start(self):

        self.menu()
        while True:
            option = input("Alege optiune: ")
            if option == "1":
                self.adaugare()
            if option == "2":
                self.modificare()
            if option == "3":
                self.get_echipa()
            if option == "4":
                self.importa_random()
            if option == "menu":
                self.menu()
            if option == "x":
                print("Exit!")
                break
