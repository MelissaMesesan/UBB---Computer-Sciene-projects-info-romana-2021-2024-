from domain.produs import Produs


class ProdusRepo:
    def __init__(self):
        self.produse = []
        self.filename = "produse.txt"
        self.read_from_file()

    def add(self, produs):
        self.produse.append(produs)
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
                produs = Produs(id_produs=line[0], denumire=line[1], pret=line[2])
                self.produse.append(produs)

    def update_file(self):
        """
        scriere in fisier
        """
        with open(self.filename, 'w') as f:
            for produs in self.produse:
                f.write(str(produs))

    def stergere(self, id_produs):
        for i in range(len(self.produse)):
            if self.produse[i].get_id_produs() == id_produs:
                del self.produse[i]
                self.update_file()
                return True
        return False

    def get_all(self):
        return self.produse
