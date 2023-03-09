from repository.melodie_repo import MelodieRepo
from service.melodie_service import MelodieService
from ui.ui import UI

class Run:
    def run(self):
        repo = MelodieRepo()
        service = MelodieService(repo)
        ui = UI(repo, service)
        ui.start()


if __name__ == '__main__':
    app = Run()
    app.run()
