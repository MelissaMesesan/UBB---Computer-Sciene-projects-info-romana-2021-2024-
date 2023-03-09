import random


class UI:
    def __init__(self, repo, service):
        self.__repo = repo
        self.__service = service
        self.tip_blocat = ""

    def menu(self):
        print("1. Stergere")
        print("2. Modificare")
        print("3. Generare program")
        print("4. Blocheaza o emisiune")
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

    def get_tip(self):
        tip = input("Tip: ")
        ok = 1
        while ok:
            if tip == "":
                ok = 1
                print("Tipul nu poate sa fie vid!!!")
                tip = input("Tip: ")
            else:
                ok = 0
        return tip

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

    def get_descriere(self):
        descriere = input("Descriere: ")
        ok = 1
        while ok:
            if descriere == "":
                ok = 1
                print("Descrierea nu poate sa fie vida!!!")
                descriere = input("Descriere: ")
            else:
                ok = 0
        return descriere

    def sterge_emisiune(self):
        nume = self.get_nume()
        tip = self.get_tip()
        res = self.__service.stergere(nume, tip, self.tip_blocat)
        if res == True:
            print("Emisiunea a fost stearsa cu succes!")
        elif res == False:
            print("Nu exista aceasta emisiune!!!")
        elif res == -1:
            print("!!!Emisiune blocata!!!")

    def modifica_emisiune(self):
        nume = self.get_nume()
        tip = self.get_tip()
        durata = self.get_durata()
        descriere = self.get_descriere()
        res = self.__service.modificare(nume, tip, durata, descriere, self.tip_blocat)
        if res == True:
            print("Emisiunea a fost modificata cu succes!")
        elif res == False:
            print("Nu exista aceasta emisiune!!!")
        elif res == -1:
            print("!!!Emisiune blocata!!!")

    def tip_de_blocat(self):
        tip = input("Tipul pe care doriti sa il blocati: ")
        self.tip_blocat = tip

    def generare_random(self):
        ora_inceput = int(input("Ora de inceput: "))
        ora_sfarsit = int(input("Ora de ora sfarsit: "))
        print("ORA      NUME         TIP        DESCRIERE")
        emisiune = ["    Jurnal         Stiri       Informatii  ",
                    "    Reportaj       Informare   Viata la sat",
                    "    Divertisment   Film        5 sanse     "]

        reluare = ["    Jurnal         Stiri       *****  ",
                   "    Reportaj       Informare   *****  ",
                   "    Divertisment   Film        *****  "]
        j = 0
        for i in range(ora_inceput, ora_sfarsit):
            if j < len(emisiune):
                print(str(i) + str(emisiune[j]))
                j += 1
            else:
                print(str(i) + str(random.choice(reluare)))

    def start(self):

        self.menu()
        while True:
            option = input("Alege optiune: ")
            if option == "1":
                self.sterge_emisiune()
            if option == "2":
                self.modifica_emisiune()
            if option == "3":
                self.generare_random()
            if option == "4":
                self.tip_de_blocat()
            if option == "menu":
                self.menu()
            if option == "x":
                print("Exit!")
                break
