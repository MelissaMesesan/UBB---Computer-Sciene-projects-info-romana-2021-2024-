import datetime
import random


class UI:
    def __init__(self, repo, service):
        self.__repo = repo
        self.__service = service

    def menu(self):
        print("1. Modificare")
        print("2. Random")
        print("3. Export fisier")
        print("menu. Meniu")
        print("x. Exit")

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

    def get_artist(self):
        artist = input("Artist: ")
        ok = 1
        while ok:
            if artist == "":
                ok = 1
                print("Artistul nu poate sa fie vid!!!")
                artist = input("Artist: ")
            else:
                ok = 0
        return artist

    def get_gen(self):
        lista = ["rock", "pop", "jazz", "altele"]
        gen = input("Gen: ")
        ok = 1
        while ok:
            if gen not in lista:
                print("Genul nu este corect!!!")
                ok = 1
                gen = input("Gen: ")
            else:
                ok = 0
        return gen

    def get_data(self):
        zi = input("zi: ")
        ok = 1
        while ok:
            if not zi.isnumeric():
                ok = 1
                print("Trebuie sa fie un numar!!!")
                zi = input("zi: ")
            else:
                if int(zi) < 0 or int(zi) > 31:
                    ok = 1
                    print("Trebuie sa fie un numar pozitiv!!!")
                    zi = input("zi: ")
                else:
                    ok = 0
        luna = input("luna: ")
        ok = 1
        while ok:
            if not luna.isnumeric():
                ok = 1
                print("Trebuie sa fie un numar!!!")
                luna = input("luna: ")
            else:
                if int(luna) < 0 or int(luna) > 12:
                    ok = 1
                    print("Trebuie sa fie un numar pozitiv!!!")
                    luna = input("luna: ")
                else:
                    ok = 0
        an = input("an: ")
        ok = 1
        while ok:
            if not an.isnumeric():
                ok = 1
                print("Trebuie sa fie un numar!!!")
                an = input("an: ")
            else:
                if int(an) < 1900:
                    ok = 1
                    print("Trebuie sa fie un numar pozitiv!!!")
                    an = input("an: ")
                else:
                    ok = 0
        data = datetime.date(int(an), int(luna), int(zi))
        return data

    def adaugare_melodie(self):
        titlu = self.get_titlu()
        artist = self.get_artist()
        gen = self.get_gen()
        data = self.get_data()
        self.__service.adaugare(titlu, artist, gen, data)

    def modificare_melodie(self):
        print("Introdu datele de cautare: ")
        titlu = self.get_titlu()
        artist = self.get_artist()
        print("Introdu datele cu care sa se modifice genul si durata: ")
        gen = self.get_gen()
        data = self.get_data()
        res = self.__service.modificare(titlu, artist, gen, data)
        if res == True:
            print("Melodia a fost modificata cu succes!")
        else:
            print("Nu exista acesta melodie!")

    def sorare_lista(self):
        lista_fisiere = ["filtrare.txt", "filtrare1.txt", "filtrare2.txt"]
        print("Lista fisierelor existente: " + str(lista_fisiere))
        fisier = input("Numele fiserului in care se exporta: ")
        ok = 0
        while ok == 0:
            if fisier in lista_fisiere:
                ok = 1
            else:
                print("'" + fisier + "' nu este un fisier existent!")
                fisier = input("Numele fiserului in care se exporta: ")
                ok = 0
        lista = self.__service.filtrare_fisier()
        with open(fisier, 'w') as f:
            for melodie in lista:
                f.write(str(melodie) + '\n')
        print("Melodiile au fost exportate cu succes in '" + fisier + "'!")

    def print_all(self, lista):
        for i in lista:
            print(i)

    def primim_random(self):
        lista_tit = input("Lista cu titlurile: ")
        lista_titlu = lista_tit.split(",")
        lista_art = input("Lista cu artistii: ")
        lista_artisti = lista_art.split(",")
        x = int(input("Numarul de generari: "))
        for z in range(x):
            titlu = random.choice(lista_titlu)
            artist = random.choice(lista_artisti)
            gen = random.choice(["rock", "pop", "jazz", "altele"])
            zi = random.randint(1, 30)
            luna = random.randint(1, 12)
            an = random.randint(2000, 2022)
            data = datetime.date(an, luna, zi)
            lista = self.__service.adaugare_random(titlu, artist, gen, data)

            self.print_all(lista)
        print("In lista s-au adaugat " + str(x) + " melodii.")

    def start(self):

        self.menu()
        while True:
            option = input("Alege optiune: ")
            if option == "1":
                self.modificare_melodie()
            if option == "2":
                self.primim_random()
            if option == "3":
                self.sorare_lista()
            if option == "menu":
                self.menu()
            if option == "x":
                print("Exit!")
                break
