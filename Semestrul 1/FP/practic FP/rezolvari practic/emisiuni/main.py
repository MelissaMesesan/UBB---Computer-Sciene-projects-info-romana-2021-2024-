from repository.emisiune_repo import EmisiuneRepo
from service.emisiune_service import EmisiuneService
from ui.ui import UI

class Run:
    def run(self):
        repo = EmisiuneRepo()
        service = EmisiuneService(repo)
        ui = UI(repo, service)
        ui.start()


if __name__ == '__main__':
    app = Run()
    app.run()
