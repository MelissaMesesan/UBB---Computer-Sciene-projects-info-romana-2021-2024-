#include "console.h"
#include "disciplina.h"
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

void Console::display(const vector<Offer>& offers) {
    cout << "Offers:\n";
    for (const auto& of : offers) {
        cout << "Name: " << of.getName() << "; Teacher: " << of.getTeacher() << "; Type: " << of.getType() << "; Hour: " << of.getHour() << ".\n";
    }
}

void Console::adaugaUI() {
    string name, teacher, type, pr;
    int ok = 0, valid=0, valid2=0;
    int hour;
    cout << "name: ";
    cin >>name;
    cout << "teacher: ";
    cin >> teacher;
    cout << "type: ";
    cin >> type;
    cout << "hour: ";
    cin >> pr;
    if (pr.length() < 7) {
        for (int i = 0; i < pr.length(); i++) {
            if (!isdigit(pr[i])) {
                valid = 1;
                break;
            }
        }
        if (name.length() < 20 && teacher.length() < 20 && type.length() < 20 && valid==0) {
            valid2 = 1;
            hour = stoi(pr);
            str.addOffer(name, teacher, type, hour);
        }
    }
    
    if(valid2==0) {
        cout << "invalid data!\n";
    }
    


}

void Console::start() {
    while (true) {
        cout << "Menu:\n";
        cout << "1.Add\n2.display\n3.sort by feature\n4.filter by hour\n0.exit\n";
        string cmd;
        cout << "command: ";
        cin >> cmd;
        string feature;
        /*try {
            switch (cmd) {
                case 1:
                    adaugaUI();
                    break;
                case 2:
                    display(str.getAll());
                    break;
                case 3:
                    cout << "1.sort by name\n2.sort by destination\n3.sort by type and price\n";
                    //string feature;
                    cin >> feature;
                    if (feature == "1") {
                        display(str.sortByName());
                    } else if (feature == "2") {
                        display(str.sortByDestination());
                    } else if (feature == "3") {
                        display(str.sortByTypePrice());
                    } else {
                        cout << "invalid feature!\n";
                    }
                    break;
                case 4:
                    cout << "1.filter by destination\n2.filter by price\n";
                    //string feature;
                    cin >> feature;
                    if(feature=="1"){
                        cout<<"give destination: ";
                        string filter_destination;
                        cin>>filter_destination;
                        //vector<Offer> list=str.filterDestination(filter_destination)
                        display(str.filterDestination(filter_destination));
                    }else if(feature=="2"){
                        cout<<"give price: ";
                        int filter_price;
                        cin>>filter_price;
                        display(str.filterPrice(filter_price));
                    }

                    break;

                case 0:

                    return;

                default:
                    cout << "invalid option!\n";
                }
        }*/

        if (cmd == "1") {
            adaugaUI();
        }
        else if (cmd == "2") {
            display(str.getAll());
        }
        else if (cmd == "3") {
            cout << "1.sort by name\n2.sort by teacher\n3.sort by type and price\n";
            //string feature;
            cin >> feature;
            if (feature == "1") {
                display(str.sortByName());
            }
            else if (feature == "2") {
                display(str.sortByTeacher());
            }
            else if (feature == "3") {
                display(str.sortByTypeHour());
            }
            else {
                cout << "invalid feature!\n";
            }
        }
        else if (cmd == "4") {
            cout << "1.filter by teacher\n2.filter by hour\n";
            //string feature;
            cin >> feature;
            if (feature == "1") {
                cout << "give teacher: ";
                string filter_destination;
                cin >> filter_destination;
                //vector<Offer> list=str.filterDestination(filter_destination)
                display(str.filterTeacher(filter_destination));
            }
            else if (feature == "2") {
                cout << "give hour: ";
                int filter_hour;
                cin >> filter_hour;
                display(str.filterHour(filter_hour));
            }
        }
        else if (cmd == "0") {
            return;
        }
        else {
            cout << "invalid comand!\n";
        }
        /*catch (const Agency_Repo_Exception& ex) {
            cout << ex <<'\n';
        }*/
        /*catch (const Agency_Repo_Exception& ex) {
            cout << ex << '\n';
        }*/
    }
}

