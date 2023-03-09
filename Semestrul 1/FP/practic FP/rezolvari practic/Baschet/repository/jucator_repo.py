import random

from domain.jucator import Jucator


class JucatorRepo:
    def __init__(self):
        self.jucatori = []
        self.filename = "jucator.txt"
        self.read_from_file()

    def add(self, jucator):
        """
        Adaugarea in lista a jucatorului si scrierea lui in fisier
        :param jucator: jucatorul
        """
        self.jucatori.append(jucator)
        self.update_file()

    def update(self, nume, prenume, inaltime):
        """
        Modificarea unui jucator si modificarea lui in fisier
        :param nume: str
        :param prenume: str
        :param inaltime: int
        """
        for jucator in self.jucatori:
            if jucator.get_nume() == nume and jucator.get_prenume() == prenume:
                jucator.set_inaltime(inaltime)
        self.update_file()

    def sortare(self):
        """
        Sortarea listei de jucatori dupa inaltime, descrescator
        :return: lista soratata
        """
        lista = sorted(self.jucatori, key=lambda x: x.get_inaltime(), reverse=True)
        return lista

    def read_from_file(self):
        """
        Citire din fisier
        pozitia 1 - nume
        pozitia 2 - prenume
        pozitia 3 - inaltime
        pozitia 4 - post
        """
        with open(self.filename, 'r') as f:
            for line in f:
                line = line.strip().split(";")
                jucator = Jucator(nume=line[0], prenume=line[1], inaltime=line[2], post=line[3])
                self.jucatori.append(jucator)

    def update_file(self):
        """
        scriere in fisier
        """
        with open(self.filename, 'w') as f:
            for jucator in self.jucatori:
                f.write(str(jucator))

    def read_from_file1(self, ok, filename1):
        """
        citire din fisier
        pozitia 1 - nume
        pozitia 2 - prenume
        random intre 150 si 250 - inaltime
        random choise - pozitie
        """
        # filename1 = "citire.txt"
        if ok:
            with open(filename1, 'r') as f:
                for line in f:
                    line = line.strip().split(";")
                    inaltime = random.randint(150, 250)
                    post = random.choice(["pivot", "extrema", "fundas"])
                    jucator = Jucator(nume=line[0], prenume=line[1], inaltime=inaltime, post=post)
                    ok = 1
                    for i in self.jucatori:
                        if jucator.get_nume() == i.get_nume() and jucator.get_prenume() == i.get_prenume():
                            ok = 0
                            break
                    if ok:
                        self.jucatori.append(jucator)
                        self.update_file()
        else:
            pass
