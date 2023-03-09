from repository.examen_repo import ExamenRepo
from service.examen_service import ExamenService
from ui.ui import UI

class Run:
    def run(self):
        repo = ExamenRepo()
        service = ExamenService(repo)
        ui = UI(repo, service)
        ui.start()


if __name__ == '__main__':
    app = Run()
    app.run()
