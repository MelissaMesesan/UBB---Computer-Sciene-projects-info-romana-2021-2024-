#include "FileRepository.h"
#include <fstream>
#include <cstring>

using std::ifstream;
using std::ofstream;

void FileRepository::readFromFile()
{

	ifstream fin(filepath);

	if (fin.is_open()) {
		Repository::lista.clear(); // Repository::clearRepo();
		string input;

		while (getline(fin, input)) {
			//daca linia citita nu e goala
			if (input != "") {
				//convertesc linia la cstring ca sa pot sa fac strtok
				char* s = (char*)input.c_str();
				//fac strtok pe cstringul linie
				char* p;

				p = strtok(s, ",");
				vector<string>parts;

				while (p != NULL) {
					parts.push_back(p);//bag fiecare data intr-un vector de stringuri
					p = strtok(NULL, ",");
				}
				//salvez datele in variabile
				int id = stoi(parts[0]);
				string brand = parts[1];
				string model = parts[2];
				string pret = parts[3];
				//construiesc obiectul (Telefon)

				Telefon m{ id,brand,model,pret };
				Repository::add(m);
			}
		}
	}

	fin.close();
}

void FileRepository::writeToFile()
{
	ofstream fout(filepath);



	if (fout.is_open()) {
		for (const auto& telefon : getAll()) {
			fout << to_string(telefon.getID()) << "," << telefon.getBrand() << "," << telefon.getModel() << "," << telefon.getPret() << '\n';

		}
	}




	fout.close();

}



int FileRepository::add(const Telefon& m)
{
	readFromFile();
	Repository::add(m);
	writeToFile();
	return 1;
}

