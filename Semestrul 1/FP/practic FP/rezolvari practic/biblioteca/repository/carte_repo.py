from domain.carte import Carte


class CarteRepo:
    def __init__(self):
        self.carti = []
        self.filename = "carti.txt"
        self.read_from_file()

    def add(self, carte):
        self.carti.append(carte)
        self.update_file()

    def read_from_file(self):
        """
        Citire din fisier
        pozitia 1 - id_carte
        pozitia 2 - titlu
        pozitia 3 - autor
        pozitia 4 - an_aparitie
        """
        with open(self.filename, 'r') as f:
            for line in f:
                line = line.strip().split(";")
                carte = Carte(id_carte=line[0], titlu=line[1], autor=line[2], an_aparitie=line[3])
                self.carti.append(carte)

    def update_file(self):
        """
        scriere in fisier
        """
        with open(self.filename, 'w') as f:
            for carte in self.carti:
                f.write(str(carte))

    def stergere(self, an_aparitie):
        for i in range(len(self.carti)+1):
            if self.carti[i].get_an_aparitie() == an_aparitie:
                del self.carti[i]
                self.update_file()
                return True
        return False

    def get_all(self):
        return self.carti
