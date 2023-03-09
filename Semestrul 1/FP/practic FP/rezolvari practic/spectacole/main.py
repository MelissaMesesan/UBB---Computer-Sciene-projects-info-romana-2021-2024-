from repository.spectacol_repo import SpectacolRepo
from service.spectacol_service import SpectacolService
from ui.ui import UI

class Run:
    def run(self):
        repo = SpectacolRepo()
        service = SpectacolService(repo)
        ui = UI(repo, service)
        ui.start()


if __name__ == '__main__':
    app = Run()
    app.run()
