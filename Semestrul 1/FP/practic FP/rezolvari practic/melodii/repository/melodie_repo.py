from domain.melodie import Melodie


class MelodieRepo:
    def __init__(self):
        self.melodii = []
        self.filename = "melodii.txt"
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
                melodie = Melodie(titlu=line[0], artist=line[1], gen=line[2], data=line[3])
                self.melodii.append(melodie)

    def update_file(self):
        """
        scriere in fisier
        """
        with open(self.filename, 'w') as f:
            for melodie in self.melodii:
                f.write(str(melodie)+'\n')

    def add(self, melodie):
        self.melodii.append(melodie)
        self.update_file()

    def update(self, titlu, artist, gen, data):
        ok = 0
        for melodie in self.melodii:
            if melodie.get_titlu() == titlu and melodie.get_artist() == artist:
                ok = 1
                melodie.set_gen(gen)
                melodie.set_data(data)
        if ok:
            self.update_file()
            return True
        return False

    def sortare(self):
        lista = sorted(self.melodii, key=lambda x: x.get_data(), reverse=False)
        return lista
