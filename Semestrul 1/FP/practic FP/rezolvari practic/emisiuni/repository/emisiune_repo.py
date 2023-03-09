from domain.emisiune import Emisiune


class EmisiuneRepo:
    def __init__(self):
        self.filename = "emisiuni.txt"
        self.emisiuni = []
        self.read_from_file()

    def read_from_file(self):
        """
        Citire din fisier
        pozitia 1 - titlu
        pozitia 2 - artist
        pozitia 3 - gen
        pozitia 4 - data
        """
        with open(self.filename, 'r') as f:
            for line in f:
                line = line.strip().split(";")
                emisiune = Emisiune(nume=line[0], tip=line[1], durata=line[2], descriere=line[3])
                self.emisiuni.append(emisiune)

    def update_file(self):
        """
        scriere in fisier
        """
        with open(self.filename, 'w') as f:
            for emisiune in self.emisiuni:
                f.write(str(emisiune) + '\n')

    def delete(self, nume, tip, tip_blocat):
        for i in range(len(self.emisiuni)):
            if self.emisiuni[i].get_nume() == nume and self.emisiuni[i].get_tip() == tip:
                if self.emisiuni[i].get_tip() == tip_blocat:
                    return -1
                del self.emisiuni[i]
                self.update_file()
                return True
        return False

    def add(self, emisiune):
        self.emisiuni.append(emisiune)
        self.update_file()

    def update(self, nume, tip, durata, descriere, tip_blocat):
        ok = 0
        for emisiune in self.emisiuni:
            if emisiune.get_nume() == nume and emisiune.get_tip() == tip:
                if emisiune.get_tip() == tip_blocat:
                    return -1
                ok = 1
                emisiune.set_durata(durata)
                emisiune.set_descriere(descriere)
        if ok:
            self.update_file()
            return True
        return False
