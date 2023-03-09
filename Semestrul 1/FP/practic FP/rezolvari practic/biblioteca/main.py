from repository.carte_repo import CarteRepo
from service.carte_service import CarteService
from ui.ui import UI


class Run:
    def run(self):
        repo = CarteRepo()
        service = CarteService(repo)
        ui = UI(repo, service)
        ui.start()


if __name__ == '__main__':
    app = Run()
    app.run()
