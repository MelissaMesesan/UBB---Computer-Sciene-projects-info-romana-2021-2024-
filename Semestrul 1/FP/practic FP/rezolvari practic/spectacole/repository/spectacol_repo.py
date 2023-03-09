from domain.spectacol import Spectacol


class SpectacolRepo:
    def __init__(self):
        self.spectacole = []
        self.filename = "spectacole.txt"
        self.read_from_file()

    def read_from_file(self):
        """
        Citire din fisier
        pozitia 1 - titlu
        pozitia 2 - artist
        pozitia 3 - gen
        pozitia 4 - durata
        """
        with open(self.filename, 'r') as f:
            for line in f:
                line = line.strip().split(";")
                spectacol = Spectacol(titlu=line[0], artist=line[1], gen=line[2], durata=line[3])
                self.spectacole.append(spectacol)

    def update_file(self):
        """
        scriere in fisier
        """
        with open(self.filename, 'w') as f:
            for spectacol in self.spectacole:
                f.write(str(spectacol)+'\n')

    def add(self, spectacol):
        self.spectacole.append(spectacol)
        self.update_file()

    def update(self, titlu, artist, gen, durata):
        ok = 0
        for spectacol in self.spectacole:
            if spectacol.get_titlu() == titlu and spectacol.get_artist() == artist:
                ok = 1
                spectacol.set_gen(gen)
                spectacol.set_durata(durata)
        if ok:
            self.update_file()
            return True
        return False

    def sortare(self):
        lista = sorted(sorted(self.spectacole, key=lambda x: x.get_artist()), key=lambda x: x.get_titlu(), reverse=False)
        # lista_finala = sorted(lista, key=lambda x: x.get_artist())
        return lista
