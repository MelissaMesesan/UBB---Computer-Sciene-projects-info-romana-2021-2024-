class UI:
    def __init__(self, repo, service):
        """
        initializarea clasei ui
        :param repo: repo
        :param service: service
        """
        self.__repo = repo
        self.__service = service
        self.data_setata = ""
        self.lista = []

    def menu(self):
        """
        meniu
        """
        print("1. Adaugare examen")
        print("2. Seteaza data")
        print("3. Export fisier")
        print("menu. Meniu")
        print("x. Exit")

    def get_materie(self):
        """
        materie
        """
        materie = input("Materie: ")
        ok = 1
        while ok:
            if materie == "":
                ok = 1
                print("Materia nu poate sa fie vida!!!")
                materie = input("Materie: ")
            else:
                ok = 0
        return materie

    def get_tip(self):
        """
        tip: normala sau restanta
        """
        lista = ["normala", "restanta"]
        tip = input("Tip: ")
        ok = 1
        while ok:
            if tip not in lista:
                print("Tipul nu este corect!!!")
                ok = 1
                tip = input("Tip: ")
            else:
                ok = 0
        return tip

    def get_data(self):
        """
        data format dd.mm
        """
        data = input("Data: ")
        data_ok = data.split(".")
        ok = 1
        luna1 = [1, 3, 5, 7, 8, 10, 12]
        luna2 = [2, 4, 6, 9, 11]
        while ok:
            if len(data_ok) == 2:
                if data_ok[0].isnumeric() and data_ok[1].isnumeric() and (
                        (int(data_ok[0]) <= 30 and (int(data_ok[1])) in luna2) or (
                        int(data_ok[0]) <= 31 and (int(data_ok[1])) in luna1)):
                    ok = 0
                else:
                    ok = 1
            else:
                ok = 1
            if ok == 1:
                print("Nu este o data valida!!!")
                data = input("Data: ")
                data_ok = data.split(".")
                ok = 1
        return data

    def get_ora(self):
        """
        ora format mm.hh
        """
        ora = input("Ora: ")
        ora_ok = ora.split(":")
        ok = 1
        while ok:
            if len(ora_ok) == 2:
                if ora_ok[0].isnumeric() and ora_ok[1].isnumeric() and int(ora_ok[0]) <= 24 and int(ora_ok[1]) <= 60:
                    ok = 0
                else:
                    ok = 1
            else:
                ok = 1
            if ok == 1:
                print("Nu este o ora valida!!!")
                ora = input("Ora: ")
                ora_ok = ora.split(":")
                ok = 1
        return ora

    def afisare_examene_de_maine(self):
        """
        afisarea examenelor de maine
        """
        lista = self.__service.sortare_filtrare()
        print()
        print("Examenele de maine: ")
        print("")
        print(" DATA  ORA MATERIE TIP")
        for i in lista:
            print(i)
        print()

    def adaugare_examen(self):
        """
        adaugare examen
        """
        data = self.get_data()
        ora = self.get_ora()
        materie = self.get_materie()
        tip = self.get_tip()
        res = self.__service.adaugare(data, ora, materie, tip)
        if res == False:
            print("Examenul acesta exista deja!!!")

    def setare_data(self):
        """
        setarea datei
        """
        self.data_setata = input("Setati data pentru a vedea examenele din urmatoarele 3 zile: ")
        self.lista = self.__service.examene_zile_viitoare(self.data_setata)

        for i in self.lista:
            print(i)

    def lista_date(self):
        """
        afisarea examenelor
        """
        print("EXAMENELE DIN URMATOARELE 3 ZILE DE LA DATA: " + str(self.data_setata) + ": ")
        for i in self.lista:
            print(i)

    def export_in_fisier(self):
        """
        export in fisier examene sortate
        """
        lista_fisiere = ["fisier1.txt", "fisier2.txt", "fisier3.txt"]
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
        sir_caractere = input("Sirul de caractere: ")
        lista = self.__service.sortare_export(sir_caractere)
        with open(fisier, 'w') as f:
            for examen in lista:
                f.write(str(examen) + '\n')
        print("Examenele au fost exportate cu succes in '" + fisier + "'!")

    def start(self):
        """
        meniu consola
        """
        self.afisare_examene_de_maine()
        self.menu()
        while True:

            option = input("Alege optiune: ")

            if option == "1":
                self.adaugare_examen()
                if self.data_setata != "":
                    self.lista_date()
            if option == "2":
                self.setare_data()
            if option == "3":
                self.export_in_fisier()
                if self.data_setata != "":
                    self.lista_date()
            if option == "menu":
                self.menu()
            if option == "x":
                print("Exit!")
                break
