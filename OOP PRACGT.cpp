
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <random>
#include <unordered_map>

int cancel = 0;



using namespace std;

class checker {
private:
    bool wrong;
public:
    checker() : wrong(false) {}
    void Int(int& bbc, int start, int end, string msg) {
        while (true) {
            cout << msg << endl;
            if (wrong != false) {
                cout << "wrong input, try again" << endl;
            }
            std::cin >> bbc;
            if (cin.fail()) {
                cin.clear();               // Скидаємо прапорці помилки вводу
                cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                wrong = true;
                system("cls");

                continue;

            }
            if (bbc == -1) {
                cancel = 1;
                wrong = false;
                break;
            }
            if (bbc > end or bbc < start) {
                wrong = true;
                system("cls");
                continue;

            }
            else {
                wrong = false;
                break;
            }
        }
    }

    void String(string input, string msg) {
        cout << msg << endl;
        getline(cin, input);
        if (input == "c" or input == "C") {
            cancel = 1;
        }
        else {
            wrong = false;
        }
    }
}; 

class date {
public:
    int day;
    int month;
    int year;

    date() : day(0), month(0), year(0) {} // Default constructor

    date(int d, int m, int y) : day(d), month(m), year(y) {}

    void setDay(int d) {
        day = d;
    }

    void setMonth(int m) {
        month = m;
    }

    void setYear(int y) {
        year = y;
    }

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }
    // Оператор віднімання дат
    int operator-(const date& other) const {
        int days1 = year * 365 + month * 30 + day;
        int days2 = other.year * 365 + other.month * 30 + other.day;
        return days1 - days2; 
    }
    // Оператор присвоєння
    date& operator=(const date& other) {
        if (this == &other)
            return *this;

        day = other.day;
        month = other.month;
        year = other.year;

        return *this;
    }
    friend std::istream& operator>>(std::istream& is, date& d) {
        std::string dateString;
        is >> dateString;

        std::istringstream iss(dateString);
        std::string token;

        std::getline(iss, token, '.');
        d.setDay(std::stoi(token));

        std::getline(iss, token, '.');
        d.setMonth(std::stoi(token));

        std::getline(iss, token, '.');
        d.setYear(std::stoi(token));

        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const date& d) {
        os << d.getDay() << "." << d.getMonth() << "." << d.getYear();
        return os;
    }
    std::string toString() const {
        std::string dateString = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
        return dateString;
    }
};

class human { // абстрактний клас "людина"
protected:
    string SFP; //прізвище ім'я по-батькові
    string phone; //номер телефону
    string adress;       //адрес

public:

    virtual void setSFP() = 0; // чисто віртуальний метод зміни ПІБ
    virtual void setPhone() = 0; // чисто віртуальний метод зміни телефону
    virtual void setAdress() = 0; // чисто віртуальний метод зміни адреси

    virtual void getInfo() const = 0; // чисто віртуальний метод для отримання інформації про людину
    virtual void getShortInfo() const = 0;
    human(string newSFP, string newPhone, string newAdress) { //конструктор 
        SFP = newSFP;
        phone = newPhone;
        adress = newAdress;
    }
    // Конструктор копіювання
    human(const human& other) {
        SFP = other.SFP;
        phone = other.phone;
        adress = other.adress;
    }

};

class manager : public human { //клас менеджера
private:
    string name_of_tcompany; //назва тур. компанії
public:
    void directSFP(string newSFP) {
        SFP = newSFP;
    }
    void directPhone(string newPhone) {
        phone = newPhone;
    }
    void directAdress(string newAdress) {
        adress = newAdress;
    }
    void directName(string newName) {
        name_of_tcompany  = newName;
    }
    void setSFP() override {
        string inputSFP="";
        cout << "Enter SFP of manager (write c to cancel operation): " << endl;
        getline(cin,inputSFP);
        if (inputSFP == "c" or inputSFP == "C") {
            cancel = 1;
        }
        else {
            SFP = inputSFP;
        }
    }

    void setPhone() override {
        string inputPhone;
        cout << "Enter Phone of manager (write c to cancel operation): " << endl;
        cin >> inputPhone;
        if (inputPhone == "c" or inputPhone == "C") {
            cancel = 1;
        }
        else {
             phone = inputPhone;
        }
        
    }

    void setAdress() override {
        string inputAdress;
        cout << "Enter Adress of manager (write c to cancel operation): " << endl;
        cin >> inputAdress;
        if (inputAdress == "c" or inputAdress == "C") {
            cancel = 1;
        }
        else {
            adress = inputAdress;
        }
        

    }
    void setNameOfTCompany() { //метод зміни назви тур. компанії
        string inputName;
        cout << "Enter name of TCompany (write c to cancel operation): " << endl;
        cin >> inputName;
        if (inputName == "c" or inputName == "C") {
            cancel = 1;
        }
        else {
            name_of_tcompany = inputName;
        }
    }

    void getShortInfo() const {
        cout << "SFP: " << SFP << endl;
        cout << "Company Name: " << name_of_tcompany << endl;
        cout << "----------------------" << endl;
    }

    void getInfo() const override {
        cout << "SFP: " << SFP << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << adress << endl;
        cout << "Company Name: " << name_of_tcompany << endl;
        cout << "----------------------" << endl;
    }
    string getSFP() {
        return SFP;
    }
    string getPhone() {
        return phone;
    }
    string getAdress() {
        return adress;
    }
    string getName() {
        return name_of_tcompany;
    }
    
    manager(string newSFP, string newPhone, string newAdress, string newName) : human(newSFP, newPhone, newAdress) { //конструктор
        name_of_tcompany = newName;
    }
    manager(const manager& other) : human(other) { //конструктор копіювання
        name_of_tcompany = other.name_of_tcompany;
    }

};

class client : public human { //клас клієнт
private:
    string name_of_tcompany; //назва тур. компанії
    string name_of_tour;     //назва туру
    int id_of_tour;       //ідентифікаційний номер туру

public:
    
    void directSFP(string newSFP) {
        SFP = newSFP;
    }
    void directPhone(string newPhone) {
        phone = newPhone;
    }
    void directAdress(string newAdress) {
        adress = newAdress;
    }
    void directName(string newName) {
        name_of_tcompany = newName;
    }
    void directNTour(string newTour) {
        name_of_tour = newTour;
    }
    void directId(int newId) {
        id_of_tour = newId;
    }
    void setSFP() override {
        string inputSFP = "";
        cout << "Enter SFP of client (write c to cancel operation): " << endl;
        getline(cin, inputSFP);
        if (inputSFP == "c" or inputSFP == "C") {
            cancel = 1;
        }
        else {
            SFP = inputSFP;
        }
    }

    void setPhone() override {
        string inputPhone;
        cout << "Enter Phone of client (write c to cancel operation): " << endl;
        cin >> inputPhone;
        if (inputPhone == "c" or inputPhone == "C") {
            cancel = 1;
        }
        else {
            phone = inputPhone;
        }

    }

    void setAdress() override {
        string inputAdress;
        cout << "Enter Adress of client (write c to cancel operation): " << endl;
        cin >> inputAdress;
        if (inputAdress == "c" or inputAdress == "C") {
            cancel = 1;
        }
        else {
            adress = inputAdress;
        }


    }
    void setNameOfTCompany() { //метод зміни назви тур. компанії
        string inputName;
        cout << "Enter name of TCompany (write c to cancel operation): " << endl;
        cin >> inputName;
        if (inputName == "c" or inputName == "C") {
            cancel = 1;
        }
        else {
            name_of_tcompany = inputName;
        }
    }

    void setNameOfTour() {     //метод зміни назви туру
        string inputNTour;
        cout << "Enter name of Tour (write c to cancel operation): " << endl;
        cin >> inputNTour;
        if (inputNTour == "c" or inputNTour == "C") {
            cancel = 1;
        }
        else {
            name_of_tour = inputNTour;
        }
    }

    void setIdOfTour() {         //метод присвоєння ідентифікаційного номеру
        int inputId;
        bool wrong = false;
        
        while (true) {
            cout << "Enter id of tour (write -1 to cancel operation):" << endl;
            cin >> inputId;
            wrong = false;
            if (wrong != false) {
                cout << "wrong input, try again" << endl;
            }
            if (cin.fail()) {
                cin.clear();               // Скидаємо прапорці помилки вводу
                cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                wrong = true;
                system("cls");
                continue;

            }
            if (inputId == -1) {
                cancel = 1;
                break;
            }
            if (inputId < 0) {
                wrong = true;
                system("cls");
                continue;

            }
            else {
                wrong = false;
                id_of_tour = inputId;
                break;
            }
        }
    }
    string getSFP() {
        return SFP;
    }
    string getPhone() {
        return phone;
    }
    string getAdress() {
        return adress;
    }
    string getName() {
        return name_of_tcompany;
    }
    string getNtour() {
        return name_of_tour;
    }
    int getId() {
        return id_of_tour;
    }

    void getShortInfo() const override {
        cout << "SFP: " << SFP << endl;
        cout << "Tour ID: " << id_of_tour << endl;
        cout << "----------------------" << endl;
    }

    void getInfo() const override {
        cout << "SFP: " << SFP << endl;
        cout << "Phone: " << phone << endl;
        cout << "Adress: " << adress << endl;
        cout << "Company Name: " << name_of_tcompany << endl;
        cout << "Tour Name: " << name_of_tour << endl;
        cout << "Tour ID: " << id_of_tour << endl;
        cout << "----------------------" << endl;
    }
   

    client(string newSFP, string newPhone, string newAdress, string newName, string newTourName, int newId) : human(newSFP, newPhone, newAdress) { //конструктор
        name_of_tcompany = newName;
        name_of_tour = newTourName;
        id_of_tour = newId;
    }
};

class tour { //клас тур
private:
    string country; //країна
    string city;    //місто
    int coast;      //ціна
    date date_of_start; //дата старту
    date date_of_end;   //дата кінця
    int id_of_tour;    //ідентифікаційний номер туру
    friend class checker;
public:
    void getInfo() const{
        cout << "Country: " << country << endl;
        cout << "City: " << city << endl;
        cout << "Coast: " << coast << endl;
        cout << "Date of start: " << date_of_start << endl;
        cout << "Date of end: " << date_of_end << endl;
        cout << "Tour ID: " << id_of_tour << endl;
        cout << "----------------------" << endl;
    }

    void directId(int newId) { //метод присвоєння ідентифікаційного номеру
        id_of_tour = newId;
    }
public:
    void directCountry(string newCountry) { //метод зміни країни
        country = newCountry;
    }

    void directCity(string newCity) { //метод зміни міста
        city = newCity;
    }

    void directCoast(int newCoast) {  //метод зміни завдання
        coast = newCoast;
    }

    void directDOS(date newDate) { //метод зміни дати початку
        date_of_start = newDate;
    }

    void directDOE(date newDate) { //метод зміни дати кінця
        date_of_end = newDate;
    }

    string getCountry() {
        return country;
    }

    string getCity() {
        return city;
    }
    
    double getCoast() {
        return coast;
    }

    date getDOS() {
        return date_of_start;
    }

    date getDOE() {
        return date_of_end;
    }

    double getId() {
        return id_of_tour;
    }

    void setCountry() {
        string inputCountry = "";
        cout <<"Enter country of tour (write c to cancel operation): " << endl;
        getline(cin, inputCountry);
        if (inputCountry == "c" or inputCountry == "C") {
            cancel = 1;
        }
        else {
            country = inputCountry;
        }

    }
    void setCity() {
        string inputCity = "";
        cout << "Enter city of tour (write c to cancel operation): " << endl;
        getline(cin, inputCity);
        if (inputCity == "c" || inputCity == "C") {
            cancel = 1;
        }
        else {
            city = inputCity;
        }
    }

    void setCoast() {
        int tcoast = 0;
        string coastmsg = "Enter coast of tour (write -1 to cancel): ";
        checker ccoast;
        ccoast.Int(tcoast, 0, 99999999, coastmsg);
        coast = tcoast;
    }
    void setDOS() {
        int dd = 0;
        int mm = 0;
        int yyyy = 0;
        bool wrong=false;
        string daymsg ="Enter day of start (enter -1 to cancel)";
        string monthmsg = "Enter month of start (enter - 1 to cancel)";
        string yearmsg = "Enter year of start (1991-2050) (enter -1 to cancel)";
        cout << "Enter date of start:" << endl;
        checker dayOS;
        dayOS.Int(dd, 1, 31, daymsg);
        if (dd != -1) {
            checker monthOS;
            monthOS.Int(mm, 1, 12, monthmsg);
            if (mm != 1) {
                checker yearOS;
                yearOS.Int(yyyy, 1991, 2050, yearmsg);
                if (yyyy != 1) {
                    date DOS(dd, mm, yyyy);
                    date_of_start = DOS;
                }
            }
        }
    }
    void setDOE() {
        int dd = 0;
        int mm = 0;
        int yyyy = 0;
        bool wrong = false;
        string daymsg = "Enter day of end (enter -1 to cancel)";
        string monthmsg = "Enter month of end (enter - 1 to cancel)";
        string yearmsg = "Enter year of end (1991-2050) (enter -1 to cancel)";
        cout << "Enter date of end:" << endl;
        checker dayOE;
        dayOE.Int(dd, 1, 31, daymsg);
        if (dd != -1) {
            checker monthOE;
            monthOE.Int(mm, 1, 12, monthmsg);
            if (mm != 1) {
                checker yearOE;
                yearOE.Int(yyyy, 1991, 2050, yearmsg);
                if (yyyy != 1) {
                    date DOE(dd, mm, yyyy);
                    date_of_end = DOE;
                }
            }
        }
    }
    
    void setId() {
        int tid = 0;
        string idmsg = "Enter id of tour (write -1 to cancel):";
        checker cid;
        cid.Int(tid, 0, 99999999, idmsg);
        id_of_tour = tid;
    }
    tour(string newCountry, string newCity, int newCoast, date newDateOfStart, date newDateOfEnd, int newId) { //конструктор
        country = newCountry;
        city = newCity;
        coast = newCoast;
        date_of_start = newDateOfStart;
        date_of_end = newDateOfEnd;
        id_of_tour = newId;
    }

};

class manager_list {
private:
    
    int stoper=0;
    int choice = 0;
    bool wrong = false;
    string file = "m_list.txt";
    string data; // тимчасові дані
    string SFP; //прізвище ім'я по-батькові
    string phone; //номер телефону
    string adress;       //адрес
    string name_of_tcompany; //назва тур. компанії
    vector<manager> manager_vector;
    fstream fs;
public:
    void getDataFromFile() {
        fs.open(file, fstream::in | fstream::out | fstream::app);

        if (!fs.is_open()) {
            cout << "Error F1 error of opening the file." << endl;
        }
        else {
            while (getline(fs, data)) {

                istringstream iss(data);
                string token;

                // Розділення стрічки за комою і збереження відповідних значень в змінних
                getline(iss, token, ',');
                SFP = token.substr();

                getline(iss, token, ',');
                phone = token.substr();

                getline(iss, token, ',');
                adress = token.substr();

                getline(iss, token, ',');
                name_of_tcompany = token.substr();

                manager man(SFP, phone, adress, name_of_tcompany);
                manager_vector.push_back(man);
            }

        }
        fs.close();
    }
    void use() {
        system("cls");
        getDataFromFile();
        while (true) {
            stoper = 0;
            fs.open(file, fstream::in | fstream::out | fstream::app);
            system("cls");
            cout << "1 - add manager" << endl
                << "2 - remove manager" << endl
                << "3 - edit manager" << endl
                << "4 - save" << endl
                << "5 - back to menu" << endl
                << "----------------" << endl;
            for (int i = 0; i < manager_vector.size(); i++) {
                cout << "Manager`s  " << i + 1 << " info" << endl;
                manager_vector[i].getShortInfo();
            }


            
            cout << "Enter command (1-5): " << endl;


            if (wrong != false) {
                cout << "wrong input, try again" << endl;
            }
            cin >> choice;
            if (cin.fail()) {
                cin.clear();               // Скидаємо прапорці помилки вводу
                cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                wrong = true;
                system("cls");

                continue;

            }
            if (choice > 5 or choice < 1) {
                wrong = true;
                system("cls");
                continue;

            }
            else {
                wrong = false;
            }
            switch (choice) {
            case 1: {
                cancel = 0;
                system("cls");
                manager man(SFP, phone, adress, name_of_tcompany);
                cin.ignore();
                man.setSFP();
                if (cancel != 1) {
                    man.setPhone();
                    if (cancel != 1) {
                        man.setAdress();
                        if (cancel != 1) {
                            man.setNameOfTCompany();
                            manager_vector.push_back(man);
                            if (cancel == 1) {
                                manager_vector.pop_back();
                                system("cls");
                                cancel = 0;
                            }
                        }
                    }
                }
                break;

            }
            case 2: {
                int id_tbd;
                while (true) {
                    system("cls");
                    for (int i = 0; i < manager_vector.size(); i++) {
                        cout << "Manager`s  " << i + 1 << " info" << endl;
                        manager_vector[i].getInfo();
                    }
                    cout << "Enter id of manager that you want to delete (write -1 to cancel): " << endl;
                    if (wrong != false) {
                        cout << "wrong input, try again" << endl;
                    }
                    cin >> id_tbd;
                    if (id_tbd == -1) {
                        break;
                    }
                    if (cin.fail()) {
                        cin.clear();               // Скидаємо прапорці помилки вводу
                        cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                        wrong = true;
                        system("cls");
                        continue;

                    }
                    if (id_tbd < 1 or id_tbd  > manager_vector.size()) {
                        wrong = true;
                        system("cls");
                        continue;

                    }

                    else {
                        wrong = false;
                        manager_vector.erase(manager_vector.begin() + id_tbd - 1);
                        break;
                    }


                }
                break;

            }
            case 3: {

                int id_tbe, choice = 0;
                while (true) {
                    system("cls");
                    for (int i = 0; i < manager_vector.size(); i++) {
                        cout << "Manager`s  " << i + 1 << " info" << endl;
                        manager_vector[i].getInfo();
                    }
                    cout << "Enter id of manager that you want to edit (write -1 to cancel): " << endl;
                    if (wrong != false) {
                        cout << "wrong input, try again" << endl;
                    }
                    cin >> id_tbe;
                    if (id_tbe == -1) {
                        break;
                    }
                    if (cin.fail()) {
                        cin.clear();               // Скидаємо прапорці помилки вводу
                        cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                        wrong = true;
                        system("cls");
                        continue;

                    }
                    if (id_tbe < 1 or id_tbe  > manager_vector.size()) {
                        wrong = true;
                        system("cls");
                        continue;

                    }

                    else {
                        wrong = false;

                        while (choice !=6) {
                            system("cls");
                            cout << "Manager`s " << id_tbe << " info:" << endl;
                            manager_vector[id_tbe - 1].getInfo();
                            cout << "Select what you want to edit:" << endl 
                                << "1 - SFP" << endl 
                                << "2 - Phone number" << endl 
                                << "3 - Adress" << endl 
                                << "4 - Name of TCompany" << endl 
                                << "5 - all" << endl 
                                << "6 - quit" << endl;
                            if (wrong != false) {
                                cout << "wrong input, try again" << endl;
                            }
                            cin >> choice;
                            if (cin.fail()) {
                                cin.clear();               // Скидаємо прапорці помилки вводу
                                cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                                wrong = true;
                                system("cls");

                                continue;

                            }
                            if (choice > 6 or choice < 1) {
                                wrong = true;
                                system("cls");
                                continue;

                            }
                            else {
                                wrong = false;
                                switch (choice) {
                                case 1: {
                                    cin.ignore();
                                    manager_vector[id_tbe - 1].setSFP();
                                    break;
                                }
                                case 2: {
                                    cin.ignore();
                                    manager_vector[id_tbe - 1].setPhone();
                                    break;
                                }
                                case 3: {
                                    cin.ignore();
                                    manager_vector[id_tbe - 1].setAdress();
                                    break;
                                }
                                case 4: {
                                    cin.ignore();
                                    manager_vector[id_tbe - 1].setNameOfTCompany();
                                    break;
                                }
                                case 5: {
                                    manager mbuf(manager_vector[id_tbe - 1].getSFP(), manager_vector[id_tbe - 1].getPhone(), manager_vector[id_tbe - 1].getAdress(), manager_vector[id_tbe - 1].getName());
                                    cancel = 0;
                                    system("cls");
                                    cout << "Manager`s " << id_tbe << " info:" << endl;
                                    manager_vector[id_tbe - 1].getInfo();
                                    cin.ignore();
                                    manager_vector[id_tbe - 1].setSFP();
                                    if (cancel != 1) {
                                        manager_vector[id_tbe - 1].setPhone();
                                        if (cancel != 1) {
                                            manager_vector[id_tbe - 1].setAdress();
                                            if (cancel != 1) {
                                                manager_vector[id_tbe - 1].setNameOfTCompany();
                                            }
                                        }
                                    }
                                    if (cancel == 1) {
                                        manager_vector[id_tbe - 1].directSFP(mbuf.getSFP());
                                        manager_vector[id_tbe - 1].directPhone(mbuf.getPhone());
                                        manager_vector[id_tbe - 1].directAdress(mbuf.getAdress());
                                        manager_vector[id_tbe - 1].directName(mbuf.getName());
                                    }
                                    break;
                                }
                                }
                            }
                            system("cls");
                        }
                    }


                }
                break;
            }
            case 4: {
                fs.close();
                fs.open(file, fstream::out | fstream::trunc);
                for (int i = 0; i < manager_vector.size(); i++) {
                    string stroke = "";
                    stroke = manager_vector[i].getSFP() + "," + manager_vector[i].getPhone() + "," + manager_vector[i].getAdress() + "," + manager_vector[i].getName();
                    if (i != manager_vector.size() - 1) {
                        fs << stroke << endl;
                    }
                    else {
                        fs << stroke;
                    }
                }
                fs.close();
                break;
            }
            case 5: {
                system("cls");
                cout << "Do you want to save your data?" << endl << "1 - yes" << endl << "2 - no" << endl;
                cin >> choice;
                switch (choice) {
                case 1: {
                    fs.close();
                    fs.open(file, fstream::out | fstream::trunc);
                    for (int i = 0; i < manager_vector.size(); i++) {
                        string stroke = "";
                        stroke = manager_vector[i].getSFP() + "," + manager_vector[i].getPhone() + "," + manager_vector[i].getAdress() + "," + manager_vector[i].getName();
                        if (i != manager_vector.size() - 1) {
                            fs << stroke << endl;
                        }
                        else {
                            fs << stroke;
                        }
                    }
                    fs.close();
                    stoper = 1;
                    break;
                }
                case 2: {
                    stoper = 1;
                    break;
                }
                }
                break;
            }
            }
            if (stoper != 0) {
                system("cls");
                break;
            }
        }
    }
    

};

class tour_list {
private:
    int stoper = 0;
    int choice = 0;
    bool wrong = false;
    string file = "t_list.txt";
    string IDfile = "c_id_pair.txt";
    string data; // тимчасові дані
    string country; //країна
    string city;    //місто
    int coast;      //ціна
    date date_of_start; //дата старту
    date date_of_end;   //дата кінця
    string stringer;
    int id_of_tour = 0;       //ідентифікаційний номер туру
    vector<tour> tour_vector;
    vector<pair<int, int>> clientTourPairs; // Вектор пар <айді_клієнта, айді_тура>
    fstream fs;
public:

    string getCountry(int i) {
        return tour_vector[i].getCountry();
    }

    string getCity(int i) {
        return tour_vector[i].getCity();
    }

    int getCoast(int i) {
        return tour_vector[i].getCoast();
    }

    date getDOS(int i) {
        return tour_vector[i].getDOS();
    }

    date getDOE(int i) {
        return tour_vector[i].getDOE();
    }

    int getSizeCTP() {
        int size = clientTourPairs.size();
        return size;
    }

    int getId(int i) {
        return tour_vector[i].getId();
    }

;   int getIdOfLast() {
        return tour_vector[tour_vector.size()-1].getId();
    }
    
    void create_tour() {
        cancel = 0;
        system("cls");
        tour tourer(country, city, coast, date_of_start, date_of_end, id_of_tour);
        cin.ignore();
        tourer.setCountry();
        if (cancel != 1) {
            tourer.setCity();
            if (cancel != 1) {
                tourer.setCoast();
                if (cancel != 1) {
                    tourer.setDOS();
                    if (cancel != 1) {
                        tourer.setDOE();
                        if (cancel != 1) {
                            tourer.setId();
                            tour_vector.push_back(tourer);
                            if (cancel == 1) {
                                tour_vector.pop_back();
                                system("cls");
                                cancel = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    void getDataFromFile() {
        system("cls");
        fs.open(file, fstream::in | fstream::out | fstream::app);

        if (!fs.is_open()) {
            cout << "Error F1 error of opening the file." << endl;
        }
        else {
            while (getline(fs, data)) {
                istringstream iss(data);
                string token;

                // Розділення стрічки за комою і збереження відповідних значень в змінних
                getline(iss, token, ',');
                country = token.substr();

                getline(iss, token, ',');
                city = token.substr();
                getline(iss, token, ',');
                stringer = token.substr();
                istringstream iss5(stringer);
                if (iss5 >> coast) {
                    // Значення успішно конвертовано у тип double
                }
                else {
                    // Помилка при конвертації
                    std::cout << "Invalid id of coast" << std::endl;
                }
                getline(iss, token, ',');
                stringer = token.substr();
                istringstream iss3(stringer);
                if (iss3 >> date_of_start) {
                    // Значення успішно конвертовано у тип double
                }
                else {
                    // Помилка при конвертації
                    std::cout << "Invalid date of start" << std::endl;
                }
                getline(iss, token, ',');
                stringer = token.substr();
                istringstream iss4(stringer);
                if (iss4 >> date_of_end) {
                    // Значення успішно конвертовано у тип double
                }
                else {
                    // Помилка при конвертації
                    std::cout << "Invalid date of end" << std::endl;
                }

                getline(iss, token, ',');
                stringer = token.substr();
                istringstream iss2(stringer);
                if (iss2 >> id_of_tour) {
                    // Значення успішно конвертовано у тип double
                }
                else {
                    // Помилка при конвертації
                    std::cout << "Invalid id of tour" << std::endl;
                }
                tour t_obj(country, city, coast, date_of_start, date_of_end, id_of_tour);
                tour_vector.push_back(t_obj);
            }

        }
        fs.close();

        fs.open(IDfile, fstream::in | fstream::out | fstream::app);

        if (!fs.is_open()) {
            cout << "Error F1 error of opening the file." << endl;
        }
        else {
            while (getline(fs, data)) {
                std::stringstream ss(data);
                int first, second;

                if (ss >> first >> second) {
                    clientTourPairs.push_back(std::make_pair(first, second));
                }
            }

        }
        fs.close();
    }

     void sumVectors(tour_list tour, tour_list ctour) {
        for (const auto& element : ctour.tour_vector) {
            tour.tour_vector.push_back(element);
        }
    }

    void saveToFile() {
        fs.close();
        fs.open(file, fstream::out | fstream::trunc);
        for (int i = 0; i < tour_vector.size(); i++) {
            string stroke = "";
            stroke = tour_vector[i].getCountry() + "," +
                tour_vector[i].getCity() + "," +
                to_string(tour_vector[i].getCoast()) + "," +
                tour_vector[i].getDOS().toString() + "," +
                tour_vector[i].getDOE().toString() + "," +
                to_string(tour_vector[i].getId());
            if (i != tour_vector.size() - 1) {
                fs << stroke << endl;
            }
            else {
                fs << stroke;
            }
        }
        fs.close();
    }

    void use() {
        tour_vector.clear();
        getDataFromFile();
        while (true) {
            stoper = 0;
            fs.open(file, fstream::in | fstream::out | fstream::app);
            system("cls");
            cout << "1 - add tour"
                << endl << "2 - remove tour"
                << endl << "3 - edit tour"
                << endl << "4 - save"
                << endl << "5 - back to menu"
                << endl << "----------------"<<endl;
            for (int i = 0; i < tour_vector.size(); i++) {
                cout << "Tour`s " << i + 1 << " info" << endl;
                tour_vector[i].getInfo();
            }


            cout << "Enter command (1-5): " << endl;


            if (wrong != false) {
                cout << "wrong input, try again" << endl;
            }
            cin >> choice;
            if (cin.fail()) {
                cin.clear();               // Скидаємо прапорці помилки вводу
                cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                wrong = true;
                system("cls");
                fs.close();
                continue;

            }
            if (choice > 5 or choice < 1) {
                wrong = true;
                system("cls");
                fs.close();
                continue;

            }
            else {
                wrong = false;
            }
            switch (choice) {
            case 1: {
                create_tour();
                break;

            }
            case 2: {
                int id_tbd;
                while (true) {
                    system("cls");
                    for (int i = 0; i < tour_vector.size(); i++) {
                        cout << "Tour`s  " << i + 1 << " info" << endl;
                        tour_vector[i].getInfo();
                    }
                    cout << "Enter id of tour that you want to delete (write -1 to cancel): " << endl;
                    if (wrong != false) {
                        cout << "wrong input, try again" << endl;
                    }
                    cin >> id_tbd;
                    if (id_tbd == -1) {
                        break;
                    }
                    if (cin.fail()) {
                        cin.clear();               // Скидаємо прапорці помилки вводу
                        cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                        wrong = true;
                        system("cls");
                        continue;

                    }
                    if (id_tbd < 1 or id_tbd  > tour_vector.size()) {
                        wrong = true;
                        system("cls");
                        continue;

                    }

                    else {
                        wrong = false;
                        tour_vector.erase(tour_vector.begin() + id_tbd - 1);
                        break;
                    }


                }
                break;

            }
            case 3: {

                int id_tbe, choice = 0, ifer = 3;
                while (true) {
                    system("cls");
                    for (int i = 0; i < tour_vector.size(); i++) {
                        cout << "Tour`s  " << i + 1 << " info" << endl;
                        tour_vector[i].getInfo();
                    }
                    cout << "Enter id of tour that you want to edit (write -1 to cancel): " << endl;
                    if (wrong != false) {
                        cout << "wrong input, try again" << endl;
                    }
                    cin >> id_tbe;
                    if (id_tbe == -1) {
                        break;
                    }
                    if (cin.fail()) {
                        cin.clear();               // Скидаємо прапорці помилки вводу
                        cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                        wrong = true;
                        system("cls");
                        continue;

                    }
                    if (id_tbe < 1 or id_tbe  > tour_vector.size()) {
                        wrong = true;
                        system("cls");
                        continue;

                    }

                    else {
                        wrong = false;

                        while (choice != 8) {
                            system("cls");
                            cout << "Tour`s " << id_tbe << " info:" << endl;
                            tour_vector[id_tbe - 1].getInfo();
                            cout << "Select what you want to edit:" << endl
                                << "1 - Country" << endl
                                << "2 - City" << endl
                                << "3 - Coast" << endl
                                << "4 - Date of start" << endl
                                << "5 - Date of end" << endl
                                << "6 - Id of tour" << endl
                                << "7 - all" << endl
                                << "8 - quit" << endl;
                            if (wrong != false) {
                                cout << "wrong input, try again" << endl;
                            }
                            cin >> choice;
                            if (cin.fail()) {
                                cin.clear();               // Скидаємо прапорці помилки вводу
                                cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                                wrong = true;
                                system("cls");

                                continue;

                            }
                            if (choice > 8 or choice < 1) {
                                wrong = true;
                                system("cls");
                                continue;

                            }
                            else {
                                wrong = false;
                                switch (choice) {
                                case 1: {
                                    system("cls");
                                    cout << "Tour`s " << id_tbe << " info:" << endl;
                                    tour_vector[id_tbe - 1].getInfo();
                                    cin.ignore();
                                    tour_vector[id_tbe - 1].setCountry();
                                    break;
                                }
                                case 2: {
                                    system("cls");
                                    cout << "Tour`s " << id_tbe << " info:" << endl;
                                    tour_vector[id_tbe - 1].getInfo();
                                    cin.ignore();
                                    tour_vector[id_tbe - 1].setCity();
                                    break;
                                }
                                case 3: {
                                    system("cls");
                                    cout << "Tour`s " << id_tbe << " info:" << endl;
                                    tour_vector[id_tbe - 1].getInfo();
                                    system("cls");
                                    cout << "Tour`s " << id_tbe << " info:" << endl;
                                    tour_vector[id_tbe - 1].getInfo();
                                    cin.ignore();
                                    tour_vector[id_tbe - 1].setCoast();
                                    break;
                                }
                                case 4: {
                                    system("cls");
                                    cout << "Tour`s " << id_tbe << " info:" << endl;
                                    tour_vector[id_tbe - 1].getInfo();
                                    cin.ignore();
                                    tour_vector[id_tbe - 1].setDOS();
                                    break;
                                }
                                case 5: {
                                    system("cls");
                                    cout << "Tour`s " << id_tbe << " info:" << endl;
                                    tour_vector[id_tbe - 1].getInfo();
                                    cin.ignore();
                                    tour_vector[id_tbe - 1].setDOE();
                                    break;
                                }
                                case 6: {
                                    system("cls");
                                    cout << "Tour`s " << id_tbe << " info:" << endl;
                                    tour_vector[id_tbe - 1].getInfo();
                                    cin.ignore();
                                    tour_vector[id_tbe - 1].setId();
                                    break;
                                }
                                case 7: {
                                    tour mbuf(tour_vector[id_tbe - 1]);
                                    cancel = 0;
                                    system("cls");
                                    cout << "Tour`s " << id_tbe << " info:" << endl;
                                    tour_vector[id_tbe - 1].getInfo();
                                    cin.ignore();
                                    tour_vector[id_tbe - 1].setCountry();
                                    if (cancel != 1) {
                                        tour_vector[id_tbe - 1].setCity();
                                        if (cancel != 1) {
                                            tour_vector[id_tbe - 1].setCoast();
                                            if (cancel != 1) {
                                                tour_vector[id_tbe - 1].setDOS();
                                                if (cancel != 1) {
                                                    tour_vector[id_tbe - 1].setDOE();
                                                    if (cancel != 1) {
                                                        tour_vector[id_tbe - 1].setId();
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (cancel == 1) {
                                        tour_vector[id_tbe - 1] = mbuf;
                                    }
                                    break;
                                }
                                }
                            }
                            system("cls");
                        }
                    }


                }
                break;
            }
            case 4: {
                saveToFile();
                break;
            }
            case 5: {
                system("cls");
                cout << "Do you want to save your data?" << endl << "1 - yes" << endl << "2 - no" << endl;
                cin >> choice;
                switch (choice) {
                case 1: {
                    saveToFile();
                    stoper = 1;
                    break;
                }
                case 2: {
                    stoper = 1;
                    break;
                }
                }
                break;
            }
            }
            if (stoper != 0) {
                system("cls");
                break;
            }
        }
    }

    tour_list() = default;

    tour_list(const tour_list& other) {
        tour_vector = other.tour_vector;
    }

    void ask6() {
        int sum = 0;
        getDataFromFile();
        for (int i = 0; i < tour_vector.size(); i++) {
            sum += tour_vector[i].getCoast();
        }
       cout <<"Average coast of tour is: "
           << static_cast<double>(sum) / tour_vector.size()<< endl;
       string msg= "Choose\n1 - go back to menu\n2 - go to tour list";
       checker cask6;
       cask6.Int(sum, 1, 2, msg);
       switch (sum) {
       case 1: {
           system("cls");
           break;
       }
       case 2: {
           use();
           break;
       }
       }
    }
    
    void ask7() {
        int sum = 0;
        getDataFromFile();
        for (int i = 0; i < tour_vector.size(); i++) {
            sum += tour_vector[i].getDOE()- tour_vector[i].getDOS();
        }
        cout << "Average tour duration: "
            << static_cast<double>(sum) / tour_vector.size() << endl;
        string msg = "Choose\n1 - go back to menu\n2 - go to tour list";
        checker cask7;
        cask7.Int(sum, 1, 2, msg);
        switch (sum) {
        case 1: {
            system("cls");
            break;
        }
        case 2: {
            use();
            break;
        }
        }
    }

    void ask8() {
        int sum;
        // Створюємо словник для підрахунку кількості повторень країн
        unordered_map<std::string, int> countryCounts;
        getDataFromFile();
        // Підраховуємо кількість повторень для кожної країни
        for (int i = 0; i<tour_vector.size();i++) {
            std::string country = getCountry(i);
            countryCounts[country]++;
        }

        // Знаходимо максимальну кількість повторень
        int maxCount = 0;
        for (const auto& pair : countryCounts) {
            maxCount = std::max(maxCount, pair.second);
        }

        // Виводимо всі країни з максимальною кількістю повторень
        for (const auto& pair : countryCounts) {
            if (pair.second == maxCount) {
                std::cout << pair.first << std::endl;
            }
        }
        string msg = "Choose\n1 - go back to menu\n2 - go to tour list";
        checker cask7;
        cask7.Int(sum, 1, 2, msg);
        switch (sum) {
        case 1: {
            system("cls");
            break;
        }
        case 2: {
            use();
            break;
        }
        }
    }
};

class client_list {
private:
    
    int stoper = 0;
    int choice = 0;
    bool wrong = false;
    string file = "c_list.txt";
    string IDfile = "c_id_pair.txt";
    string tour_file = "t_list.txt";
    string data; // тимчасові дані
    string SFP;
    string phone;
    string adress;           //адрес
    string name_of_tcompany; //назва тур. компанії
    string name_of_tour;     //назва туру
    string sid_of_tour;
    int id_of_tour=0;       //ідентифікаційний номер туру
    vector<client> client_vector;
    vector<tour> tour_vector;
    tour_list ctour;
    fstream fs; 
    vector<pair<int, int>> clientTourPairs; // Вектор пар <айді_клієнта, айді_тура>
public:
    
    void addClientTourPair(int clientId, int tourId) {
        // Перевіряємо, чи пара <айді_клієнта, айді_тура> вже існує в контейнері
        for (const auto& pair : clientTourPairs) {
            if (pair.first == clientId && pair.second == tourId) {
                std::cout << "Error: Client-Tour pair already exists." << std::endl;
                return;
            }
        }
        // Додаємо нову пару <айді_клієнта, айді_тура> до контейнеру
        clientTourPairs.push_back(std::make_pair(clientId, tourId));
    }
    bool isClientTourPairExists(int clientId, int tourId) {
        // Перевіряємо, чи пара <айді_клієнта, айді_тура> існує в контейнері
        for (const auto& pair : clientTourPairs) {
            if (pair.first == clientId && pair.second == tourId) {
                return true;
            }
        }
        return false;
    }
    void removeClientTourPair(int idToRemove) {
        if (idToRemove >= 0 && idToRemove < clientTourPairs.size()) {
            clientTourPairs.erase(clientTourPairs.begin() + idToRemove); // Видалення елемента
        }
        else {
            std::cout << "Wrong id." << std::endl;
        }
    }
   
    string getCTP(int i) {
        if (i >= 0 && i < clientTourPairs.size()) {
            // Створення об'єкта stringstream
            std::stringstream ss;

            // Отримання пари за заданим індексом
            std::pair<int, int> pair = clientTourPairs[i];

            // Запис значення пари в stringstream
            ss << pair.first << ", " << pair.second;

            // Отримання рядка з stringstream
            std::string result = ss.str();

            // Виведення рядка
            std::cout << result << std::endl;
            return result;
        }
        else {
            std::cout << "Wrong index" << std::endl;
        }
    }

    void addClient(int id) {
        client cli(SFP, phone, adress, name_of_tcompany, name_of_tour, id_of_tour);
        cin.ignore();
        cli.setSFP();
        if (cancel != 1) {
            cli.setPhone();
            if (cancel != 1) {
                cli.setAdress();
                if (cancel != 1) {
                    cli.setNameOfTCompany();
                    if (cancel != 1) {
                        cli.setNameOfTour();
                        if (cancel != 1) {
                            cli.directId(id);
                            client_vector.push_back(cli);
                            addClientTourPair(client_vector.size()-1, id);
                            if (cancel == 1) {
                                client_vector.pop_back();
                                system("cls");
                                cancel = 0;
                            }
                        }
                    }
                }
            }
        }
    }

    int getSizeCTP() {
        return client_vector.size();
    }
    
    void getDataFromFile() {
        system("cls");
        fs.open(file, fstream::in | fstream::out | fstream::app);

        if (!fs.is_open()) {
            cout << "Error F1 error of opening the file." << endl;
        }
        else {
            while (getline(fs, data)) {
                istringstream iss(data);
                string token;

                // Розділення стрічки за комою і збереження відповідних значень в змінних
                getline(iss, token, ',');
                SFP = token.substr();

                getline(iss, token, ',');
                phone = token.substr();

                getline(iss, token, ',');
                adress = token.substr();

                getline(iss, token, ',');
                name_of_tcompany = token.substr();

                getline(iss, token, ',');
                name_of_tour = token.substr();

                getline(iss, token, ',');
                sid_of_tour = token.substr();
                istringstream iss2(sid_of_tour);
                if (iss2 >> id_of_tour) {
                    // Значення успішно конвертовано у тип int
                    iss2 >> id_of_tour;
                }
                else {
                    // Помилка при конвертації
                    std::cout << "Invalid id of tour" << std::endl;
                }
                client cli(SFP, phone, adress, name_of_tcompany, name_of_tour, id_of_tour);
                client_vector.push_back(cli);
            }

        }
        fs.close();

        fs.open(IDfile, fstream::in | fstream::out | fstream::app);

        if (!fs.is_open()) {
            cout << "Error F1 error of opening the file." << endl;
        }
        else {
            while (getline(fs, data)) {
                std::stringstream ss(data);
                int first, second;

                char comma;
                if (ss >> first >> comma >> second) {
                    clientTourPairs.push_back(std::make_pair(first, second));
                }

            }

        }
        fs.close();
    }

    void saveDataToFile() {
        fs.close();
        fs.open(IDfile, fstream::out | fstream::trunc);
        for (int i = 0; i < clientTourPairs.size(); i++) {
            string stroke = "";
            stroke = getCTP(i);
            if (i != clientTourPairs.size() - 1) {
                fs << stroke << endl;
            }
            else {
                fs << stroke;
            }
        }
        fs.close();


        fs.close();
        fs.open(file, fstream::out | fstream::trunc);
        for (int i = 0; i < client_vector.size(); i++) {
            string stroke = "";
            stroke = client_vector[i].getSFP() + "," +
                client_vector[i].getPhone() + "," +
                client_vector[i].getAdress() + "," +
                client_vector[i].getName() + "," +
                client_vector[i].getNtour() + "," +
                to_string(client_vector[i].getId());
            if (i != client_vector.size() - 1) {
                fs << stroke << endl;
            }
            else {
                fs << stroke;
            }
        }
        fs.close();

        tour_list tour;
        tour.getDataFromFile();
        tour.saveToFile();
        ctour.getDataFromFile();
        ctour.saveToFile();
    }

    void use() {
        client_vector.clear();
        getDataFromFile();
        
        while (true) {
            stoper = 0;
            fs.open(file, fstream::in | fstream::out | fstream::app);
            system("cls");
            cout << "1 - add client"<< endl 
                << "2 - remove client"<< endl 
                << "3 - edit client"<< endl 
                << "4 - save"<< endl 
                << "5 - back to menu" << endl 
                << "----------------" << endl;
            for (int i = 0; i < client_vector.size(); i++) {
                cout << "Client`s  " << i + 1 << " info" << endl;
                client_vector[i].getInfo();
            }


            
            cout<< "Enter command (1-5): " << endl;


            if (wrong != false) {
                cout << "wrong input, try again" << endl;
            }
            cin >> choice;
            if (cin.fail()) {
                cin.clear();               // Скидаємо прапорці помилки вводу
                cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                wrong = true;
                system("cls");
                fs.close();
                continue;

            }
            if (choice > 5 or choice < 1) {
                wrong = true;
                system("cls");
                fs.close();
                continue;

            }
            else {
                wrong = false;
            }
            switch (choice) {
            case 1: {
                cancel = 0;
                
                string schoice;
                while (schoice != "n") {
                    system("cls");
                    cout << "If you want to add client you have to create tour firstly (y/n)" << endl;
                    if (wrong != false) {
                        cout << "wrong input try again";
                    }
                    cin >> schoice;
                    
                    transform(schoice.begin(), schoice.end(), schoice.begin(), ::tolower);
                    if (schoice == "y") {
                        ctour.create_tour();
                        addClient(ctour.getIdOfLast());
                        break;
                    }
                    else if (schoice != "y" or schoice != "n") {
                        wrong = true;
                    }
                    else if (schoice == "n") {
                        wrong = false;
                        break;
                        
                    }

                }
                
                
                break;

            }
            case 2: {
                int id_tbd;
                while (true) {
                    system("cls");
                    for (int i = 0; i < client_vector.size(); i++) {
                        cout << "Clients`s  " << i + 1 << " info" << endl;
                        client_vector[i].getInfo();
                    }
                    cout << "Enter id of client that you want to delete (write -1 to cancel): " << endl;
                    if (wrong != false) {
                        cout << "wrong input, try again" << endl;
                    }
                    cin >> id_tbd;
                    if (id_tbd == -1) {
                        break;
                    }
                    if (cin.fail()) {
                        cin.clear();               // Скидаємо прапорці помилки вводу
                        cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                        wrong = true;
                        system("cls");
                        continue;

                    }
                    if (id_tbd < 1 or id_tbd  > client_vector.size()) {
                        wrong = true;
                        system("cls");
                        continue;

                    }

                    else {
                        wrong = false;
                        client_vector.erase(client_vector.begin() + id_tbd - 1);
                        break;
                    }
                    

                }
                break;

            }
            case 3: {

                int id_tbe, choice = 0;
                while (true) {
                    system("cls");
                    for (int i = 0; i < client_vector.size(); i++) {
                        cout << "Client`s  " << i + 1 << " info" << endl;
                        client_vector[i].getInfo();
                    }
                    cout << "Enter id of client that you want to edit (write -1 to cancel): " << endl;
                    if (wrong != false) {
                        cout << "wrong input, try again" << endl;
                    }
                    cin >> id_tbe;
                    if (id_tbe == -1) {
                        break;
                    }
                    if (cin.fail()) {
                        cin.clear();               // Скидаємо прапорці помилки вводу
                        cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                        wrong = true;
                        system("cls");
                        continue;

                    }
                    if (id_tbe < 1 or id_tbe  > client_vector.size()) {
                        wrong = true;
                        system("cls");
                        continue;

                    }

                    else {
                        wrong = false;

                        while (choice !=8) {
                            system("cls");
                            cout << "Client`s " << id_tbe << " info:" << endl;
                            client_vector[id_tbe - 1].getInfo();
                            cout << "Select what you want to edit:" << endl
                                << "1 - SFP" << endl
                                << "2 - Phone number" << endl
                                << "3 - Adress" << endl
                                << "4 - Name of TCompany" << endl
                                << "5 - Name of Tour" << endl
                                << "6 - Id of tour" << endl
                                << "7 - all" << endl
                                << "8 - quit" << endl;
                            if (wrong != false) {
                                cout << "wrong input, try again" << endl;
                            }
                            cin >> choice;
                            if (cin.fail()) {
                                cin.clear();               // Скидаємо прапорці помилки вводу
                                cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                                wrong = true;
                                system("cls");

                                continue;

                            }
                            if (choice > 8 or choice < 1) {
                                wrong = true;
                                system("cls");
                                continue;

                            }
                            else {
                                wrong = false;
                                switch (choice) {
                                case 1: {
                                    cin.ignore();
                                    client_vector[id_tbe - 1].setSFP();
                                    break;
                                }
                                case 2: {
                                    cin.ignore();
                                    client_vector[id_tbe - 1].setPhone();
                                    break;
                                }
                                case 3: {
                                    cin.ignore();
                                    client_vector[id_tbe - 1].setAdress();
                                    break;
                                }
                                case 4: {
                                    cin.ignore();
                                    client_vector[id_tbe - 1].setNameOfTCompany();
                                    break;
                                }
                                case 5: {
                                    cin.ignore();
                                    client_vector[id_tbe - 1].setNameOfTour();
                                    break;
                                }
                                case 6: {
                                    cin.ignore();
                                    client_vector[id_tbe - 1].setIdOfTour();
                                    break;
                                }
                                case 7: {
                                    client mbuf(client_vector[id_tbe - 1]);
                                    cancel = 0;
                                    system("cls");
                                    cout << "Manager`s " << id_tbe << " info:" << endl;
                                    client_vector[id_tbe - 1].getInfo();
                                    cin.ignore();
                                    client_vector[id_tbe - 1].setSFP();
                                    if (cancel != 1) {
                                        client_vector[id_tbe - 1].setPhone();
                                        if (cancel != 1) {
                                            client_vector[id_tbe - 1].setAdress();
                                            if (cancel != 1) {
                                                client_vector[id_tbe - 1].setNameOfTCompany();
                                                if (cancel != 1) {
                                                    client_vector[id_tbe - 1].setNameOfTour();
                                                    if (cancel != 1) {
                                                        client_vector[id_tbe - 1].setIdOfTour();
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    if (cancel == 1) {
                                        client_vector[id_tbe - 1] = mbuf;
                                    }
                                    break;
                                }
                                }
                            }
                            system("cls");
                        }
                    }


                }
                break;
            }
            case 4: {
                saveDataToFile();
                break;
            }
            case 5: {
                system("cls");
                cout << "Do you want to save your data?" << endl << "1 - yes" << endl << "2 - no" << endl;
                cin >> choice;
                switch (choice) {
                case 1: {
                    saveDataToFile();
                    stoper = 1;
                    break;
                }
                case 2: {
                    stoper = 1;
                    break;
                }
                }
                break;
            }
            }
            if (stoper != 0) {
                system("cls");
                break;
            }
        }
    }
    void ask4() {
        system("cls");
        getDataFromFile();
        cout << "Count of client = " << client_vector.size() << endl;
        cout << "You want to go back to menu or to client list?" << endl
            << "1 - menu" << endl
            << "2 - client list" << endl;
        while (true) {
            if (wrong != false) {
                cout << "wrong input, try again" << endl;
            }
            cin >> choice;
            if (cin.fail()) {
                cin.clear();               // Скидаємо прапорці помилки вводу
                cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
                wrong = true;
                system("cls");

                continue;

            }
            if (choice > 2 or choice < 1) {
                wrong = true;
                system("cls");
                continue;

            }
            else {
                wrong = false;
            }
            switch (choice) {
            case 1: {
                system("cls");
                stoper = 1;
                break;
            }
            case 2: {
                use();
                stoper = 1;
                break;
            }
            }
            if (stoper == 1) {
                break;
            }
        }
    }

    void ask5() {
        string askcountry;
        tour_list asktour;
        vector<client> ask5vector;
        int founding=1;
        asktour.getDataFromFile();
        getDataFromFile();
        system("cls");
        if (client_vector.size() != 0) {
            while (true) {
                
                if (founding != 1) {
                    cout << "There is no such country." << endl;
                    cout << "Enter anything to go back." << endl;
                    cin >> askcountry;
                    system("cls");
                }
                founding = 0;
                cout << "Enter country that you want to search clients by:" << endl;
                cin >> askcountry;
                for (int i = 0; i < client_vector.size(); i++) {
                    if (askcountry == asktour.getCountry(i)) {
                        for (int j = 0; j < client_vector.size(); j++) {
                            if (asktour.getId(i) == client_vector[j].getId()) {
                                ask5vector.push_back(client_vector[j]);
                                break;
                            }
                        }

                        founding = 1;
                    }
                }
                if (founding == 1) {
                    for (int i = 0; i < ask5vector.size();i++) {
                        cout << "Client`s " << i + 1 << " info: " << endl;
                        ask5vector[i].getShortInfo();
                    }
                    cout << "Enter anything to go back." << endl;
                    cin >> askcountry;
                    system("cls");
                    break;
                }

            }
        }
        else {
            cout <<"You dont have clients yet." << endl
                <<"Enter anything to go back."<<endl;
            cin >> askcountry;
            system("cls");
        }
        
    }
};



void print_menu() {
    
    cout << "_______  _____     _    ___ __ _______ __  __  __ __ ___ ___    _" << endl;
    cout << "|  _  |  | /\\ |   /^\\   | |/ / |_   _| || //|  ||_|| | |_| |   /^\\ " << endl;
    cout << "| | | |  | \\/_/  //_\\\\  |   <    | |   ||//||  \\__ | |  _  |  //_\\\\" << endl;
    cout << "|_| |_|  |_|    /_/ \\_\\ |_|\\_\\   |_|   |_/ ||     || |_| |_| /_/ \\_\\" << endl;

    cout <<"" << endl;
    cout << "1 - Show manager list" << endl
            << "2 - Open client list"<<endl
            << "3 - Open tour list"<<endl
            << "4 - Open count of clients" << endl
            << "5 - Show client by country" << endl
            << "6 - Show average tour coast" << endl
            << "7 - Show average tour duration" << endl
            << "8 - Show `Most Wanted (c)` country " << endl
            << "9 - Quit " << endl
            << "" << endl
            << "Enter command (1-9):" << endl;
}

int main() {
    

    int choice=0;
    bool wrong=false;
    
    
    while (true) {
        
        print_menu();
        if (wrong != false) {
            cout << "wrong input, try again" << endl;
        }
        cin >> choice;
        if (cin.fail()) {
            cin.clear();               // Скидаємо прапорці помилки вводу
            cin.ignore(10000, '\n');   // Ігноруємо решту символів у буфері вводу
            wrong = true;
            system("cls");
           
            continue;
            
        }
        if (choice > 9 or choice <1) {
            wrong = true;
            system("cls");
            continue;
           
        }
        else {
            wrong = false;
        }
        switch (choice) {
        case 1: {
            manager_list manager;
            manager.use();
            break;
        }
        case 2: {
            client_list client;
            client.use();
            break;
        }
        case 3: {
            tour_list tour;
            tour.use();
            break;
        }
        case 4: {
            client_list client;
            client.ask4();
            break;
        }
        case 5: {
            client_list client;
            client.ask5();
            break;
        }
        case 6: {
            tour_list tour;
            tour.ask6();
            break;
        }
        case 7: {
            tour_list tour;
            tour.ask7();
            break;
        }
        case 8: {
            tour_list tour;
            tour.ask8();
            break;
        }
        case 9:{
            cout <<"Thank`s for using"<<endl
                << "Author is Medunkiy Yaroslave AC-224 <3" << endl;
            break;
        }
        }
        if (choice == 9) {
            break;
        }
    }
}

