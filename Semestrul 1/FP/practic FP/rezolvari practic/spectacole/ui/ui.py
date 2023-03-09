import random


class UI:
    def __init__(self, repo, service):
        self.__repo = repo
        self.__service = service

    def menu(self):
        print("1. Adaugare")
        print("2. Modificare")
        print("3. Random")
        print("4. Export fisier")
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
        lista = ["comedie", "concert", "balet", "altele"]
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

    def get_durata(self):

        durata = input("Durata: ")
        ok = 1
        while ok:
            if not durata.isnumeric():
                ok = 1
                print("Trebuie sa fie un numar!!!")
                durata = input("Durata: ")
            else:
                if int(durata) < 0:
                    ok = 1
                    print("Trebuie sa fie un numar pozitiv!!!")
                    durata = input("Durata: ")
                else:
                    ok = 0
        return int(durata)

    def adaugare_spectacol(self):
        titlu = self.get_titlu()
        artist = self.get_artist()
        gen = self.get_gen()
        durata = self.get_durata()
        self.__service.adaugare(titlu, artist, gen, durata)

    def modificare_spectacol(self):
        print("Introdu datele de cautare: ")
        titlu = self.get_titlu()
        artist = self.get_artist()
        print("Introdu datele cu care sa se modifice genul si durata: ")
        gen = self.get_gen()
        durata = self.get_durata()
        res = self.__service.modificare(titlu, artist, gen, durata)
        if res == True:
            print("Spectacolul a fost modificat cu succes!")
        else:
            print("Nu exista acest spectacol!")

    def sorare_lista(self):
        lista_fisiere = ["filtrare.txt", "filtrare1.txt", "filtrare2.txt"]
        print("Lista fisierelor existente: "+str(lista_fisiere))
        fisier = input("Numele fiserului in care se exporta: ")
        ok = 0
        while ok == 0:
            if fisier in lista_fisiere:
                ok = 1
            else:
                print("'"+fisier+"' nu este un fisier existent!")
                fisier = input("Numele fiserului in care se exporta: ")
                ok = 0
        lista = self.__service.filtrare_fisier()
        with open(fisier, 'w') as f:
            for spectacol in lista:
                f.write(str(spectacol) + '\n')
        print("Spectacolele au fost exportate cu succes in '"+fisier+"'!")

    def print_all(self, lista):
        for i in lista:
            print(i)

    def primim_random(self):
        con = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's',
               't', 'v', 'w', 'x', 'y', 'z']
        vow = ['a', 'e', 'i', 'o', 'u']
        x = int(input("Numarul de generari: "))
        for z in range(x):
            i = 1
            titlu = ""
            artist = ""
            gen = random.choice(["comedie", "concert", "balet", "altele"])
            durata = random.randint(1, 10)
            while i < random.randint(9, 12):
                if i == 4:
                    titlu = titlu + " "
                elif i % 2 == 1:
                    titlu = titlu + random.choice(con)
                elif i % 2 == 0:
                    titlu = titlu + random.choice(vow)
                i += 1

            i = 1
            while i < random.randint(9, 12):
                if i == 4:
                    artist = artist + " "
                elif i % 2 == 0:
                    artist = artist + random.choice(con)
                elif i % 2 == 1:
                    artist = artist + random.choice(vow)
                i += 1

            lista = self.__service.adaugare_random(titlu, artist, gen, durata)

            self.print_all(lista)

    def start(self):

        self.menu()
        while True:
            option = input("Alege optiune: ")
            if option == "1":
                self.adaugare_spectacol()
            if option == "2":
                self.modificare_spectacol()
            if option == "3":
                self.primim_random()
            if option == "4":
                self.sorare_lista()
            if option == "menu":
                self.menu()
            if option == "x":
                print("Exit!")
                break
