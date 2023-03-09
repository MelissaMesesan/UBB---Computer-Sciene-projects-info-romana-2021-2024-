from domain.examen import Examen


class ExamenRepo:

    def __init__(self):
        """
        initializare clasa ExamenRepo
        """
        self.examene = []
        self.filename = "examen.txt"
        self.read_from_file()

    def read_from_file(self):
        """
        Citirea din fisier
        """
        with open(self.filename, 'r') as f:
            for line in f:
                line = line.strip().split(";")
                examen = Examen(data=line[0], ora=line[1], materie=line[2], tip=line[3])
                self.examene.append(examen)

    def update_file(self):
        """
        scriere in fisier
        """
        with open(self.filename, 'w') as f:
            for examen in self.examene:
                f.write(str(examen) + '\n')

    def add(self, examen):
        """
        adauga in fisier
        :param examen:
        :return: False daca exista materia si tipul deja
        """
        for i in self.examene:
            if i.get_materie() == examen.get_materie() and i.get_tip == examen.get_tip():
                return False
        self.examene.append(examen)
        self.update_file()
        return True

    def sortare(self, data):
        """
        examenele dintr-o anumita data
        :param data: str
        :return: lista cu examenele
        """
        my_list = []
        for examen in self.examene:
            if examen.get_data() == data:
                my_list.append(examen)

        lista = sorted(my_list, key=lambda x: x.get_ora(), reverse=False)
        return lista

    def exemene_peste_3_zile(self, data1, data2, data3):
        """
        determina examenele din urmatoarele 3 date
        :param data1: str
        :param data2: str
        :param data3: str
        :return: lista cu examele din urmatoarele 3 date
        """
        my_list = []
        for examen in self.examene:
            if examen.get_data() == data1 or examen.get_data() == data2 or examen.get_data() == data3:
                my_list.append(examen)
        return my_list

    def sortare_cu_tip(self, sir):
        """
        sorteaza lista dupa data si dupa ora care au sir in tip
        :param sir: str
        :return: lista sortata
        """
        my_list = []
        for examen in self.examene:
            if sir in examen.get_tip():
                my_list.append(examen)
        lista = sorted(sorted(my_list, key=lambda x: x.get_ora()), key=lambda x: x.get_data(), reverse=False)
        return lista
