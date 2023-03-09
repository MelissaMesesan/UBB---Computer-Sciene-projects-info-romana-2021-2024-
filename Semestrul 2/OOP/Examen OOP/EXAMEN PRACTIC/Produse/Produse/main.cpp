#include "Produse.h"
#include <QtWidgets/QApplication>
#include "Gui.h"
void testAdd() {

	ofstream fout("TestFile.txt");
	Validator val;
	Repo repo{ "TestFile.txt" };
	Service serv{ repo,val };
	serv.add(1, "name1", "tip1", 53.2);
	serv.add(2, "name2", "tip2", 1);
	serv.add(3, "name3", "tip3", 87.73);
	serv.add(4, "name4", "tip4", 52);
	const vector<Prod>& all = serv.getAll();
	assert(all.size() == 4);
	const Prod& p = all[0];
	assert(p.getId() == 1);
	assert(p.getName() == "name1");
	assert(p.getType() == "tip1");
	assert(p.getPrice() == 53.2);

	const Prod& t = all[3];
	assert(t.getId() == 4);
	assert(t.getName() == "name4");
	assert(t.getType() == "tip4");
	assert(t.getPrice() == 52);

	try {
		serv.add(1, "dwqd", "ewqop", 43);
		assert(false);
	}
	catch (RepoError& ex)
	{
		assert(ex.getErrors() == "Element existent!\n");
	}

	fout.close();
}
void testLoadFromFile() {
	ofstream fout("TestFile.txt");
	fout << "1 obiect tip 54.21" << endl;
	fout << "4 obiect2 tip2 99" << endl;
	fout.close();


	Validator val;
	Repo repo{ "TestFile.txt" };
	Service serv{ repo,val };
	const vector<Prod>& all = serv.getAll();
	assert(all.size() == 2);

	const Prod& p = all[0];
	assert(p.getId() == 1);
	assert(p.getName() == "obiect");
	assert(p.getType() == "tip");
	assert(p.getPrice() == 54.21);


	const Prod& t = all[1];
	assert(t.getId() == 4);
	assert(t.getName() == "obiect2");
	assert(t.getType() == "tip2");
	assert(t.getPrice() == 99);
}
void testValidator() {
	Validator val;
	Prod p{ 2,"lupa","utilitar",23 };
	try {
		val.validate(p);
		assert(true);
	}
	catch (ValidateException) {
		assert(false);
	}
	Prod t{ 3,"","",555 };
	try {
		val.validate(t);
		assert(false);
	}
	catch (ValidateException& ex) {
		assert(ex.getErrors() == "Nume invalid!\nTip invalid!\nPret invalid!\n");
	}


}
void testAll() {
	testLoadFromFile();
	testAdd();
	testValidator();
}
int main(int argc, char* argv[])
{
	testAll();
	QApplication a(argc, argv);
	Validator val;
	Repo repo{ "Prods.txt" };
	Service serv{ repo,val };
	Gui gui{ serv };
	gui.show();
	return a.exec();
}