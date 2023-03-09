import datetime

from domain.examen import Examen


class ExamenService:
    def __init__(self, repo):
        """
        Initializarea clasei ExamenService
        :param repo: repository
        """
        self.__repo = repo

    def adaugare(self, data, ora, materie, tip):
        """
        adauga in lista un examen
        :param data: str
        :param ora: str
        :param materie: str
        :param tip: str
        :return: True sau False
        """
        examen = Examen(data=data, ora=ora, materie=materie, tip=tip)
        res = self.__repo.add(examen)
        return res

    def sortare_filtrare(self):
        """
        examenele care se dau maine
        :return: lista examenelor de maine
        """
        data_cureta = datetime.date.today()
        data_maine = str(data_cureta.day + 1)+".0"+str(data_cureta.month)
        return self.__repo.sortare(data_maine)

    def examene_zile_viitoare(self, data):
        """
        examenele din urmatoarele 3 zile de la data data
        :param data: str
        :return: lista cu examenele din urmatoarele 3 zile
        """
        data_curenta = data.split(".")
        doi = int(data_curenta[0]) + 1
        trei = doi + 1
        data1 = data
        data2 = str(doi)+"."+str(data_curenta[1])
        data3 = str(trei)+"."+str(data_curenta[1])
        return self.__repo.exemene_peste_3_zile(data1, data2, data3)

    def sortare_export(self, sir):
        """
        lista care sorteaza examenele care au sir in tip
        :param sir: str
        :return: lista sortata
        """
        return self.__repo.sortare_cu_tip(sir)
