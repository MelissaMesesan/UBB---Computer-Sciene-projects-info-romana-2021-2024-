#include <iostream>
#include "Repository.h"
#include "FileRepository.h"
#include "Service.h"
#include "UI.h"


using namespace std;

int main() {


	//Tests teste;
	//teste.runTests();
	{
		FileRepository repo{ "Telefon.txt" };
		//Repository repo;
		Service serv{ repo };
		UI ui{ serv };
		ui.run();
		serv.srv_add(1000, "Apple", "iPhone12", "4500");
		serv.srv_add(1001, "Samsung", "Glaxy 1", "400");
		serv.srv_add(1002, "Huawei", "model 1", "2000");
		serv.srv_add(1003, "Apple", "iPhone13", "5000");
		serv.srv_add(1004, "Samsung", "Galaxy 2", "4020");
		serv.srv_add(1005, "Huawei", "model 2", "1002");
		serv.srv_add(1006, "Apple", "iPhone11", "3500");
		serv.srv_add(1007, "Samsung", "Galaxy 3", "3780");
		serv.srv_add(1008, "Huawei", "model 3", "3000");
		serv.srv_add(1009, "Apple", "iPhone10", "3100");
	}
	return 0;
}