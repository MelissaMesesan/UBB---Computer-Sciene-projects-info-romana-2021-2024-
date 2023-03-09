class Examen:
    def __init__(self, data, ora, materie, tip):
        """
        Initializarea clase Examen
        :param data: str
        :param ora: str
        :param materie: str
        :param tip: str
        """
        self.__data = data
        self.__ora = ora
        self.__materie = materie
        self.__tip = tip

    def __str__(self):
        """
        Constructor
        :return: examen
        """
        return f'{self.__data};{self.__ora};{self.__materie};{self.__tip}'

    def __repr__(self):
        return f'{self.__data};{self.__ora};{self.__materie};{self.__tip}'

    def get_data(self):
        """
        get data
        :return: data
        """
        return self.__data

    def get_ora(self):
        """
        get ora
        :return: ora
        """
        return self.__ora

    def get_materie(self):
        return self.__materie

    def get_tip(self):
        return self.__tip

