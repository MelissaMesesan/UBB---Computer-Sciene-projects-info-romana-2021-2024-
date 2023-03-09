from domain.jucator import Jucator


class JucatorService:
    def __init__(self, repo):
        self.__repo = repo

    def add_jucator(self, nume, prenume, inaltime, post):
        jucator = Jucator(nume=nume, prenume=prenume, inaltime=inaltime, post=post)
        self.__repo.add(jucator)

    def modifica(self, nume, prenume, inaltime):
        self.__repo.update(nume, prenume, inaltime)

    def echipa(self):
        my_list = self.__repo.sortare()
        lista = []
        contor_fundas = 0
        contor_pivot = 0
        contor_extrema = 0

        for jucator in my_list:
            if jucator.get_post() == "extrema" and contor_extrema < 2:
                lista.append(jucator)
                contor_extrema += 1
            if jucator.get_post() == "pivot" and contor_pivot < 1:
                lista.append(jucator)
                contor_pivot += 1
            if jucator.get_post() == "fundas" and contor_fundas < 2:
                lista.append(jucator)
                contor_fundas += 1

        return lista

    def importa(self, ok, filename):
        self.__repo.read_from_file1(ok, filename)

    def nr_total(self):
        return len(self.__repo.jucatori)
