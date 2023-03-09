from repository.jucator_repo import JucatorRepo
from service.jucator_service import JucatorService
from ui.ui import UI


class Run:

    def run(self):
        repo = JucatorRepo()
        service = JucatorService(repo)
        ui = UI(repo, service)
        ui.start()


if __name__ == '__main__':
    app = Run()
    app.run()
