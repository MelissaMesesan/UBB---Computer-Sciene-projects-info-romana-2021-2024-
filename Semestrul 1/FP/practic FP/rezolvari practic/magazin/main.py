from repository.produs_repo import ProdusRepo
from service.produs_service import ProdusService
from ui.ui import UI


class Run:
    def run(self):
        repo = ProdusRepo()
        service = ProdusService(repo)
        ui = UI(repo, service)
        ui.start()


if __name__ == '__main__':
    app = Run()
    app.run()
