#include <iostream>
#include <fstream> //файловый ввод/вывод
#include <string> //методы для string
#include <Windows.h> //для реализации основного меню
#include <vector> //для вектора
#include <conio.h> //для пароля со *
#include <iomanip> //для шапки таблицы
#include <ctime> //для чтения текущей даты

using namespace std;

/*-------------------------------------------------------------КЛАССЫ-СУЩНОСТИ---------------------------------------------------------------------------*/

//класс для выбора менеджера	
class manager { //класс для выбора менеджера
private:
	vector<string> managers; //вектор, содержащий названия должностей
public:
	manager() {
		managers.push_back("Топ-менеджер"); //запись в вектор
		managers.push_back("Риск-менеджер");
		managers.push_back("Менеджер");
	}
	string choose_the_manager() {
		int j = 1;
		for (string i : managers) {
			cout << j << ' ' << i << endl; //вывод списка на экран
			j++;
		}
		int number_of_manager;
		string chosen_manager;
		cin >> number_of_manager;
		do {
			switch (number_of_manager) {
			case 1:chosen_manager = managers[0]; break;
			case 2:chosen_manager = managers[1]; break;
			case 3:chosen_manager = managers[2]; break;
			}
		} while (number_of_manager < 1 || number_of_manager > 3);
		return chosen_manager;
	}
};

//класс для выбора должности
class employee_position {
private:
	vector<string> positions; //вектор, содержащий названия должностей
	manager choose_the_type; //для выбора конкретного менеджера
	int default_hours_of_work; //часы работы по умолчанию
	int salary; //зп по умолчанию
public:
	employee_position() {
		default_hours_of_work = salary = 0;
		positions.push_back("Администратор"); //запись в вектор
		positions.push_back("Инженер");
		positions.push_back("Экономист");
		positions.push_back("Менеджер");
		positions.push_back("Уборщик");
		positions.push_back("Директор(исполнительный)");
		positions.push_back("Директор(финансовый)");
	}
	int get_default_hours_of_work() { return default_hours_of_work; } //геттер для часов
	int get_salary() { return salary; } //геттер для зп
	string choose_the_direction() {
		string chosen_position;
		int number_of_direction;
		int j = 1;
		for (string i : positions) {
			cout << j << ' ' << i << endl;
			j++;
		}
		cin >> number_of_direction;
		do {
			switch (number_of_direction) {
			case 1:chosen_position = positions[0]; default_hours_of_work = 40; salary = 600; break;
			case 2:chosen_position = positions[1]; default_hours_of_work = 40; salary = 900; break;
			case 3:chosen_position = positions[2]; default_hours_of_work = 40; salary = 800; break;
			case 4:chosen_position = choose_the_type.choose_the_manager(); default_hours_of_work = 40; salary = 800; break;
			case 5:chosen_position = positions[4]; default_hours_of_work = 15; salary = 400; break;
			case 6:chosen_position = positions[5]; default_hours_of_work = 35; salary = 2000; break;
			case 7:chosen_position = positions[6]; default_hours_of_work = 35; salary = 1500; break;
			}
		} while (number_of_direction < 1 || number_of_direction > 7);
		return chosen_position;
	}
};

//класс для выбора отдела
class subdivision {
private:
	vector<string> subdivisions;
public:
	subdivision() {
		subdivisions.push_back("Кадров");
		subdivisions.push_back("Закупок");
		subdivisions.push_back("Финансов");
		subdivisions.push_back("Производства");
		subdivisions.push_back("Развития");
		subdivisions.push_back("Продаж");
	}
	vector<string> get_sub() {
		return subdivisions;
	}
	string choose_the_department() {
		int j = 1;
		for (string i : subdivisions) {
			cout << j << " Отдел " << i << endl;
			j++;
		}
		string chosen_department;
		int number_of_department;
		cin >> number_of_department;
		do {
			switch (number_of_department) {
			case 1:chosen_department = subdivisions[0]; break;
			case 2:chosen_department = subdivisions[1]; break;
			case 3:chosen_department = subdivisions[2]; break;
			case 4:chosen_department = subdivisions[3]; break;
			case 5:chosen_department = subdivisions[4]; break;
			case 6:chosen_department = subdivisions[5]; break;
			}
		} while (number_of_department > 6 || number_of_department < 1);
		return chosen_department;
	}
};

//класс-сущность, содрежащий информацию о сотрудниках
class employee {
protected:
	string date_of_birth;
	string education;
	string position;
	string department;
	string marital_status;
	string date_of_contract_start;
	subdivision department_choice; //для выбора отдела
	employee_position choose_position; //для выбора должности
	string name;
	string lname;
	string sname;
	int hours;
	int salary;
public:
	string get_lname() { return lname; }
	string get_name() { return name; }
	string get_sname() { return sname; }
	string get_date_of_birth() { return date_of_birth; }
	string get_education() { return education; }
	string get_position() { return position; }
	string get_department() { return department; }
	string get_marital_status() { return marital_status; }
	string get_date_of_contract_start() { return date_of_contract_start; }
	int get_hours() { return hours; }
	int get_salary() { return salary; }
	void set_lname(string new_lname) { lname = new_lname; }
	void set_name(string new_name) { name = new_name; }
	void set_sname(string new_sname) { sname = new_sname; }
	void set_date_of_birth(string new_date) { date_of_birth = new_date; }
	void set_education(string new_education) { education = new_education; }
	void set_position(string new_position) { position = new_position; }
	void set_department(string new_department) { department = new_department; }
	void set_marital_status(string new_sp) { marital_status = new_sp; }
	void set_contract(string new_contract_date) { date_of_contract_start = new_contract_date; }
	void set_hours(int new_hours) { hours = new_hours; }
	void set_salary(int new_salary) { salary = new_salary; }
	employee() {
		lname = "";
	}
	~employee() {}
	void cap() {
		cout << setw(3)/*максимальный размер ячейки*/ << setiosflags(ios::left)/*выравнивание по левому краю*/ << "№" << "|"
			<< setw(47) << setiosflags(ios::left) << "ФИО" << "|"
			<< setw(14) << setiosflags(ios::left) << "Дата рождения" << "|"
			<< setw(12) << setiosflags(ios::left) << "Образование" << "|"
			<< setw(24) << setiosflags(ios::left) << "Должность" << "|"
			<< setw(20) << setiosflags(ios::left) << "Отдел" << "|"
			<< setw(20) << setiosflags(ios::left) << "Семейное положение" << "|"
			<< setw(22) << setiosflags(ios::left) << "Дата начала контракта" << "|"
			<< setw(5) << setiosflags(ios::left) << "Часы" << "|"
			<< setw(8) << setiosflags(ios::left) << "Зарплата" << "|" << endl;
		cout << "---------------------------------------------------"
			<< '+' << "--------------" << '+' << "------------" << '+'
			<< "------------------------" << '+' << "--------------------"
			<< '+' << "--------------------" << '+' << "----------------------"
			<< '+' << "-----" << '+' << "---------\n";
	}
	//ввод информации о сотруднике
	void input_employee() {
		cout << "Введите ФИО сотрудника: \n";
		cout << "Фамилия: "; cin >> lname;
		cout << "Имя: "; cin >> name;
		cout << "Отчество: "; cin >> sname;
		cout << "Введите дату рождения сотрудника (через точку): ";
		cin >> date_of_birth;
		cout << "Введите сведения об образовании сотрудника (абревиатура ВУЗа): ";
		cin >> education;
		cout << "Выберите занимаемую должность сотрудника:\n";
		position = choose_position.choose_the_direction();
		cout << "Выберите отдел, в котором работает сотрудник:\n";
		department = department_choice.choose_the_department();
		cout << "Введите сведения о семейном положении сотрудника: ";
		cin.ignore();
		getline(cin, marital_status);
		cout << "Введите дату начала сотрудничества: ";
		cin >> date_of_contract_start;
		hours = choose_position.get_default_hours_of_work();
		salary = choose_position.get_salary();
	}
	//вывод информации о сотруднике
	void output_employee(int i) {
		cout << setw(3) << i << "|" << setw(47) << setiosflags(ios::left) << lname + ' ' + name + ' ' + sname << "|"
			<< setw(14) << setiosflags(ios::left) << date_of_birth << "|"
			<< setw(12) << setiosflags(ios::left) << education << "|"
			<< setw(24) << setiosflags(ios::left) << position << "|"
			<< setw(20) << setiosflags(ios::left) << department << "|"
			<< setw(20) << setiosflags(ios::left) << marital_status << "|"
			<< setw(22) << setiosflags(ios::left) << date_of_contract_start << "|"
			<< setw(5) << setiosflags(ios::left) << hours << "|"
			<< setw(8) << setiosflags(ios::left) << salary << "|" << endl;
		cout << "---------------------------------------------------" << '+'
			<< "--------------" << '+' << "------------" << '+'
			<< "------------------------" << '+' << "--------------------"
			<< '+' << "--------------------" << '+' << "----------------------"
			<< '+' << "-----" << '+' << "---------\n";
	}
};

//подкласс employee для уволенных сотрудников
class fired_employee : public employee {
private:
	string reason;
	string when;
public:
	string get_reason() { return reason; }
	string get_when() { return when; }
	void set_reason(string tmp) { reason = tmp; }
	void set_when(string tmp) { when = tmp; }
	void fired_cap() {
		cout << setw(3)/*максимальный размер ячейки*/ << setiosflags(ios::left)/*выравнивание по левому краю*/ << "№" << "|"
			<< setw(47) << setiosflags(ios::left) << "ФИО" << "|"
			<< setw(12) << setiosflags(ios::left) << "Образование" << "|"
			<< setw(24) << setiosflags(ios::left) << "Должность" << "|"
			<< setw(20) << setiosflags(ios::left) << "Отдел" << "|"
			<< setw(22) << setiosflags(ios::left) << "Дата начала контракта" << "|"
			<< setw(20) << setiosflags(ios::left) << "Причина" << "|"
			<< setw(20) << setiosflags(ios::left) << "Дата увольнения" << "|" << endl;
		cout << "---------------------------------------------------"
			<< '+' << "------------" << '+' << "------------------------" << '+'
			<< "--------------------" << '+' << "----------------------"
			<< '+' << "--------------------" << '+' << "---------------------\n";
	}
	void output_fired(int i) {
		cout << setw(3) << i << "|" << setw(47) << setiosflags(ios::left) << lname + ' ' + name + ' ' + sname << "|"
			<< setw(12) << setiosflags(ios::left) << education << "|"
			<< setw(24) << setiosflags(ios::left) << position << "|"
			<< setw(20) << setiosflags(ios::left) << department << "|"
			<< setw(22) << setiosflags(ios::left) << date_of_contract_start << "|"
			<< setw(20) << setiosflags(ios::left) << reason << "|"
			<< setw(20) << setiosflags(ios::left) << when << "|" << endl;
		cout << "---------------------------------------------------"
			<< '+' << "------------" << '+' << "------------------------" << '+'
			<< "--------------------" << '+' << "----------------------"
			<< '+' << "--------------------" << '+' << "---------------------\n";
	}
};

/*-----------------------------------------------------------КЛАССЫ, УПРАВЛЯЮЩИЕ СУЩНОСТЯМИ--------------------------------------------------------------*/

//класс, предоставляющий методы записи векторов в файлы
class new_file {
private:
	string path, fired_path;
	ofstream fout; //для записи
	ifstream fin; //для чтения
public:
	new_file() {
		path = "employees.txt"; //файл для основной базы
		fired_path = "fired_employees.txt"; //файл для уволенных
	}
	void file_write_in(vector<employee>& database) {
		fout.open(path, ios::in | ios::app); //открытие на дозапись
		if (!fout.is_open())
			cout << "Ошибка открытия файла";
		else {
			for (int i = 0; i < 1; i++) {
				fout << database[i].get_lname() << ' ';
				fout << database[i].get_name() << ' ';
				fout << database[i].get_sname() << ' ';
				fout << database[i].get_date_of_birth() << ' ';
				fout << database[i].get_education() << ' ';
				fout << database[i].get_position() << ' ';
				fout << database[i].get_department() << ' ';
				fout << database[i].get_marital_status() << ' ';
				fout << database[i].get_date_of_contract_start() << ' ';
				fout << database[i].get_hours() << ' ';
				fout << database[i].get_salary() << '\n';
			}
		}
		fout.close();
	}
	void file_read_out(vector<employee>& database) {
		database.resize(database.size() + 1);
		fin.open(path, ios::in); //открытие только для чтения
		if (!fin.is_open()) cerr << "Ошибка открытия файла";
		else {
			string tmp;
			int i = 0;
			while (!fin.eof()) {
				getline(fin, tmp, ' '); database[i].set_lname(tmp);
				getline(fin, tmp, ' '); database[i].set_name(tmp);
				getline(fin, tmp, ' '); database[i].set_sname(tmp);
				getline(fin, tmp, ' '); database[i].set_date_of_birth(tmp);
				getline(fin, tmp, ' '); database[i].set_education(tmp);
				getline(fin, tmp, ' '); database[i].set_position(tmp);
				getline(fin, tmp, ' '); database[i].set_department(tmp);
				getline(fin, tmp, ' '); database[i].set_marital_status(tmp);
				getline(fin, tmp, ' '); database[i].set_contract(tmp);
				getline(fin, tmp, ' '); database[i].set_hours(atoi(tmp.c_str()));
				getline(fin, tmp, '\n'); database[i].set_salary(atoi(tmp.c_str()));
				i++;
				database.resize(database.size() + 1);
			}
			fin.close();
		}
	}
	void file_read_out(vector<fired_employee>& last) {
		last.resize(last.size() + 1);
		fin.open(fired_path, ios::in);
		if (!fin.is_open())
			cerr << "Ошибка открытия файла";
		else {
			string tmp;
			int i = 0;
			while (!fin.eof()) {
				getline(fin, tmp, ' '); last[i].set_lname(tmp);
				getline(fin, tmp, ' '); last[i].set_name(tmp);
				getline(fin, tmp, ' '); last[i].set_sname(tmp);
				getline(fin, tmp, ' '); last[i].set_education(tmp);
				getline(fin, tmp, ' '); last[i].set_position(tmp);
				getline(fin, tmp, ' '); last[i].set_department(tmp);
				getline(fin, tmp, ' '); last[i].set_contract(tmp);
				getline(fin, tmp, ' '); last[i].set_reason(tmp);
				getline(fin, tmp, '\n'); last[i].set_when(tmp);
				i++;
				last.resize(last.size() + 1);
			}
		}
	}
	void file_write_in(vector<fired_employee>& database) {
		fout.open(fired_path, ios::in | ios::app);
		if (!fout.is_open())
			cout << "Ошибка открытия файла";
		else {
			for (unsigned int i = 0; i < 1; i++) {
				fout << database[i].get_lname() << ' ';
				fout << database[i].get_name() << ' ';
				fout << database[i].get_sname() << ' ';
				fout << database[i].get_education() << ' ';
				fout << database[i].get_position() << ' ';
				fout << database[i].get_department() << ' ';
				fout << database[i].get_date_of_contract_start() << ' ';
				fout << database[i].get_reason() << ' ';
				fout << database[i].get_when() << '\n';
			}
		}
		fout.close();
	}
	void edit_in_file(vector<employee>& database) {
		fout.open(path, ios::out); //открытие на перезапись (при изменении данных)
		if (!fout.is_open())
			cout << "Ошибка открытия файла";
		else {
			for (unsigned int i = 0; i < database.size(); i++) {
				fout << database[i].get_lname() << ' ';
				fout << database[i].get_name() << ' ';
				fout << database[i].get_sname() << ' ';
				fout << database[i].get_date_of_birth() << ' ';
				fout << database[i].get_education() << ' ';
				fout << database[i].get_position() << ' ';
				fout << database[i].get_department() << ' ';
				fout << database[i].get_marital_status() << ' ';
				fout << database[i].get_date_of_contract_start() << ' ';
				fout << database[i].get_hours() << ' ';
				fout << database[i].get_salary() << '\n';
			}
		}
		fout.close();
	}
	void edit_in_file(vector<fired_employee>& database) {
		fout.open(fired_path, ios::out); //открытие на перезапись (при изменении данных)
		if (!fout.is_open())
			cout << "Ошибка открытия файла";
		else {
			for (unsigned int i = 0; i < database.size(); i++) {
				fout << database[i].get_lname() << ' ';
				fout << database[i].get_name() << ' ';
				fout << database[i].get_sname() << ' ';
				fout << database[i].get_education() << ' ';
				fout << database[i].get_position() << ' ';
				fout << database[i].get_department() << ' ';
				fout << database[i].get_date_of_contract_start() << ' ';
				fout << database[i].get_reason() << ' ';
				fout << database[i].get_when() << '\n';
			}
		}
		fout.close();
	}
	void write_hash(vector<string> &login, string hash_path) {
		fout.open(hash_path, ios::out);
		char rand_s = '0';
		if (!fout.is_open())
			cout << "Ошибка открытия файла";
		else 
			for (int i = 0; i < login.size(); i++) {
				fout << login[i] << rand_s;
			}
		fout.close();
	}
	vector<string> read_hash(string hash_path) {
		vector<string> login(1);
		fin.open(hash_path, ios::in);
		char rand_s = '0';
		if (!fin.is_open())
			cout << "Ошибка открытия файла";
		else {
			int i = 0;
			while (!fin.eof()) {
				getline(fin, login[i], rand_s);
				i++;
				login.resize(login.size() + 1);
			}
		}
		fout.close();
		return login;
	}
};

//класс поиска
class search_an_employee_to_edit {
protected:
	subdivision depts;
public:
	int index_finder(vector<employee>& database) {
		cout << "Введите номер сотрудника: ";
		int number;
		cin >> number;
		for (unsigned int i = 0; i < database.size(); i++) {
			if (number == i + 1)
				return i;
		}
		return -1;
	}
	int index_finder(vector<employee>& database, string FIO) {
		for (unsigned int i = 0; i < database.size(); i++)
			if (FIO == database[i].get_lname())
				return i;
	}
	int index_finder(vector<fired_employee>& database, string FIO) {
		for (unsigned int i = 0; i < database.size(); i++)
			if (FIO == database[i].get_lname())
				return i;
	}
	void find_and_show(vector<employee>& database) {
		system("cls");
		bool found = false;
		database[0].cap();
		int j = 1;
		for (employee i : database) {
			i.output_employee(j);
			j++;
		}
		cout << "Введите фамилию сотрудника: ";
		string FIO = "";
		cin >> FIO;
		j = 1;
		system("cls");
		database[0].cap();
		for (employee i : database)
			if (FIO == i.get_lname()) {
				found = true;
				i.output_employee(j);
			}
		if (!found) cerr << "Не найдено\n";
	}
	void find_and_show(vector<fired_employee>& database) {
		system("cls");
		bool found = false;
		database[0].fired_cap();
		int j = 1;
		for (fired_employee i : database) {
			i.output_fired(j);
			j++;
		}
		cout << "Введите фамилию бывшего сотрудника: ";
		string FIO = "";
		cin >> FIO;
		for (fired_employee i : database)
			if (FIO == i.get_lname()) {
				found = true;
				i.output_employee(j);
			}
		if (!found) cerr << "Не найдено\n";
	}
	string show_department_workers() {
		vector<string> subs = depts.get_sub();
		cout << "ОТДЕЛЫ:\n";
		cout << "-------------------\n";
		int j = 1;
		for (string i : subs) {
			cout << j << " Отдел " << i << endl;
			j++;
		}
		cout << "Выберите отдел: ";
		cin >> j;
		for (unsigned int k = 1; k <= subs.size(); k++) {
			if (j == k) return subs[k - 1];
		}
	}
};

//класс удаляющий элементы вектора
class remover {
private:
	search_an_employee_to_edit in_work;
public:
	void find_and_delete(vector<employee>& first, vector<fired_employee>& last) {
		first[0].cap();
		int j = 1;
		for (employee i : first) {
			i.output_employee(j);
			j++;
		}
		time_t rawtime;
		struct tm* timeinfo;
		char buffer[20];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, 20, "%d.%m.%Y", timeinfo);
		string str(buffer);
		int index_to_remove = in_work.index_finder(first);
		last.resize(last.size() + 1);
		last[last.size() - 1].set_lname(first[index_to_remove].get_lname());
		last[last.size() - 1].set_name(first[index_to_remove].get_name());
		last[last.size() - 1].set_sname(first[index_to_remove].get_sname());
		last[last.size() - 1].set_education(first[index_to_remove].get_education());
		last[last.size() - 1].set_position(first[index_to_remove].get_position());
		last[last.size() - 1].set_department(first[index_to_remove].get_department());
		last[last.size() - 1].set_contract(first[index_to_remove].get_date_of_contract_start());
		cout << "Причина увольнения: ";
		string tmp;
		cin >> tmp;
		last[last.size() - 1].set_reason(tmp);
		last[last.size() - 1].set_when(str);
		if (first[index_to_remove].get_lname() != "")
			first.erase(first.begin() + index_to_remove);
		else
			cerr << "Не найдено";
	}
	void find_and_delete(vector<employee>& first, string FIO) {
		int index_to_remove = in_work.index_finder(first, FIO);
		if (first[index_to_remove].get_lname() != "")
			first.erase(first.begin() + index_to_remove);
		else
			cerr << "Не найдено";
	}
	void delete_by_index(int index, vector<employee>& first) {
		first.erase(first.begin() + index);
	}
	void delete_by_index(int index, vector<fired_employee>& first) {
		first.erase(first.begin() + index);
	}
};

//класс, который проверяет вектор на пустые ячейки и удаляет их
template <class T> class checker {
private:
	remover for_checking;
public:
	void vector_size(vector<T>& first) {
		int i, j = 0;
		int size = first.size();
		for (i = first.size() - 1; i >= 0; i--)
			if (first[i].get_lname().empty())
				for_checking.delete_by_index(i, first);
	}
};

void name_sort(string &tmpi, string &tmpj, int k, vector<employee> &database, int real_size, int j) {
	checker<employee> extra_remove;
	if (tmpj[k] == tmpi[k]) {
		k++;
		extra_remove.vector_size(database);
		database.resize(real_size);
	}
	if (tmpj[k] < tmpi[k]) {
		k = 0;
		employee temp = database[j + 1];
		database[j + 1] = database[j];
		database[j] = temp;
		extra_remove.vector_size(database);
		database.resize(real_size);
	}
	else {
		extra_remove.vector_size(database);
		database.resize(real_size);
	}
	k = 0;
}

void date_sort(string& date, string& date_2, vector<employee>& database, int real_size, int j) {
	checker<employee> extra_remove;
	int day, month, year;
	int day_2, month_2, year_2;
	string _day = date; _day.erase(2);
	day = atoi(_day.c_str());
	_day = date_2; _day.erase(2);
	day_2 = atoi(_day.c_str());
	string _month = date.substr(3, 2);
	month = atoi(_month.c_str());
	_month = date_2.substr(3, 2);
	month_2 = atoi(_month.c_str());
	string _year = date.substr(6, 4);
	year = atoi(_year.c_str());
	_year = date_2.substr(6, 4);
	year_2 = atoi(_year.c_str());
	if (year > year_2) {
		employee temp = database[j + 1];
		database[j + 1] = database[j];
		database[j] = temp;
		extra_remove.vector_size(database);
		database.resize(real_size);
	}
	if (year == year_2) {
		if (month > month_2) {
			employee temp = database[j + 1];
			database[j + 1] = database[j];
			database[j] = temp;
			extra_remove.vector_size(database);
			database.resize(real_size);
		}
	}
	if (year == year_2 && month == month_2) {
		if (day > day_2) {
			employee temp = database[j + 1];
			database[j + 1] = database[j];
			database[j] = temp;
			extra_remove.vector_size(database);
			database.resize(real_size);
		}
	}
}

//класс сортировки
class sort_employees {
private:
	string tmpi;
	string tmpj;
	int temp_sal_i, temp_sal_j;
	checker<employee> extra_remove;
	checker<fired_employee> extra_remove_1;
public:
	void sort_the_data(vector<employee>& database) {
		system("cls");
		database[0].cap();
		for (unsigned int i = 0; i < database.size(); i++) {
			database[i].output_employee(i + 1);
		}
		cout << "1-Отсортировать по имени\n2-Отсортировать по зарплате\n3-Отсортировать по дате рождения\n4-Отсортировать по должности\n"
			<< "5-Отсортировать по отделу\n6-Отсортировать по дате заключения контракта\n7-Отсортировать по рабочим часам\n";
		int answer;
		cin >> answer;
		int k = 0;
		int real_size = database.size();
		if (answer == 1) {
			for (int i = 0; i <= real_size - 1; i++)
				for (int j = real_size - 2; j >= 0; j--) {
					tmpi = database[j].get_lname();
					tmpj = database[j + 1].get_lname();
					name_sort(tmpi, tmpj, k, database, real_size, j);
				}
		}
		else if (answer == 2) {
			for (int i = 0; i <= real_size - 1; i++)
				for (int j = real_size - 2; j >= 0; j--) {
					temp_sal_i = database[j].get_salary();
					temp_sal_j = database[j + 1].get_salary();
					if (temp_sal_j < temp_sal_i) {
						employee temp = database[j + 1];
						database[j + 1] = database[j];
						database[j] = temp;
						extra_remove.vector_size(database);
						database.resize(real_size);
					}
				}
		}
		else if (answer == 3) {
			int day, month, year;
			int day_2, month_2, year_2;
			string date, date_2;
			for (int i = 0; i <= real_size - 1; i++)
				for (int j = real_size - 2; j >= 0; j--) {
					date = database[j].get_date_of_birth();
					date_2 = database[j + 1].get_date_of_birth();
					date_sort(date, date_2, database, real_size, j);
				}
			}
		else if (answer == 4) {
			for (int i = 0; i <= real_size - 1; i++)
				for (int j = real_size - 2; j >= 0; j--) {
					tmpi = database[j].get_position();
					tmpj = database[j + 1].get_position();
					name_sort(tmpi, tmpj, k, database, real_size, j);
				}
		}
		else if (answer == 5) {
			for (int i = 0; i <= real_size - 1; i++)
				for (int j = real_size - 2; j >= 0; j--) {
					tmpi = database[j].get_department();
					tmpj = database[j + 1].get_department();
					name_sort(tmpi, tmpj, k, database, real_size, j);
				}
		}
		else if (answer == 6) {
			int day, month, year;
			int day_2, month_2, year_2;
			string date, date_2;
			for (int i = 0; i <= real_size - 1; i++)
				for (int j = real_size - 2; j >= 0; j--) {
					date = database[j].get_date_of_contract_start();
					date_2 = database[j + 1].get_date_of_contract_start();
					date_sort(date, date_2, database, real_size, j);
				}
		}
		else if (answer == 7) {
			for (int i = 0; i <= real_size - 1; i++)
				for (int j = real_size - 2; j >= 0; j--) {
					temp_sal_i = database[j].get_hours();
					temp_sal_j = database[j + 1].get_hours();
					if (temp_sal_j < temp_sal_i) {
						employee temp = database[j + 1];
						database[j + 1] = database[j];
						database[j] = temp;
						extra_remove.vector_size(database);
						database.resize(real_size);
					}
				}
		}
		else {
			system("cls");
			cerr << "Вы ввели некорректные данные, повторите попытку" << endl;
			system("pause");
		}
		system("cls");
	}
	void sort_the_data(vector<fired_employee>& database) {
		for (unsigned int i = 0; i < database.size(); i++)
			database[i].output_fired(i + 1);
		cout << "Отсортировать по имени?\n1 Да\n2 Нет\n";
		int answer;
		cin >> answer;
		int k = 0; int real_size = database.size();
		if (answer == 1) {
			for (unsigned int i = 0; i <= real_size - 1; i++)
				for (int j = real_size - 2; j >= 0; j--) {
					tmpi = database[j].get_lname();
					tmpj = database[j + 1].get_lname();
					if (tmpj[k] == tmpi[k]) {
						k++;
						extra_remove_1.vector_size(database);
						database.resize(real_size);
					}
					if (tmpj[k] < tmpi[k]) {
						k = 0;
						fired_employee temp = database[j + 1];
						database[j + 1] = database[j];
						database[j] = temp;
						extra_remove_1.vector_size(database);
						database.resize(real_size);
					}
					k = 0;
				}
		}
	}
};

//класс, предоставляющий методы редактирования сотрудников
class editor {
private:
	search_an_employee_to_edit finder;
	vector<string> full_text;
	string temp_info;
	subdivision editing;
	remover delete_me;
	checker<employee> extra_remove;
	employee_position new_pos;
public:
	editor() {
		full_text.push_back("1 - ФИО\n");
		full_text.push_back("2 - Образование\n");
		full_text.push_back("3 - Должность\n");
		full_text.push_back("4 - Подразделение\n");
		full_text.push_back("5 - Семейное положение\n");
	}
	void edit_the_info(vector<employee>& first) {
		system("cls");
		first[0].cap();
		int j = 1;
		for (employee i : first) {
			i.output_employee(j);
			j++;
		}
		int tmp = finder.index_finder(first);
		if (tmp == -1)
			cerr << "Не найдено\n";
		else {
			first[tmp].output_employee(tmp + 1);
			for (string i : full_text) cout << i;
			int criterion;
			string tlname, tname, tsname;
			cin >> criterion;
			cin.ignore();
			switch (criterion) {
			case 1:
				cout << "Текущее ФИО: " << (first[tmp].get_lname() + " " + first[tmp].get_name() + " " + first[tmp].get_sname()) << endl;
				cout << "Введите новое ФИО: ";
				cin.ignore();
				cin >> tlname >> tname >> tsname;
				first[tmp].set_lname(tlname);
				first[tmp].set_name(tname);
				first[tmp].set_sname(tsname);
				break;
			case 2:
				cout << "Текущее Образование: " << first[tmp].get_education() << endl;
				cout << "Введите новое Образование: ";
				cin >> temp_info;
				first[tmp].set_education(temp_info);
				break;
			case 3:
				cout << "Текущая Должность: " << first[tmp].get_position() << endl;
				cout << "Выберите новую Должность: \n";
				temp_info = new_pos.choose_the_direction();
				first[tmp].set_position(temp_info);
				first[tmp].set_hours(new_pos.get_default_hours_of_work());
				first[tmp].set_salary(new_pos.get_salary());
				break;
			case 4:
				cout << "Текущее Подразделение: " << first[tmp].get_department() << endl;
				cout << "Выберите новое Подразделение: ";
				temp_info = editing.choose_the_department();
				first[tmp].set_department(temp_info);
				break;
			case 5:
				cout << "Текущее Семейное положение: " << first[tmp].get_marital_status() << endl;
				cout << "Введите новое Семейное положение: ";
				cin >> temp_info;
				first[tmp].set_marital_status(temp_info);
				break;
			}
		}
	}
	void edit_info_for_finance(vector<employee>& first) {
		system("cls");
		int j = 1;
		first[0].cap();
		for (employee i : first) {
			i.output_employee(j);
			j++;
		}
		int tmp = finder.index_finder(first);
		first[tmp].output_employee(tmp + 1);
		cout << "Текущая заработная плата: " << first[tmp].get_salary() << endl;
		int new_salary;
		cout << "Введите актуальную заработную плату: ";
		cin >> new_salary;
		first[tmp].set_salary(new_salary);
	}
};

//класс, составляющий отчёты
class reports {
private:
	int salary_money;
	int workers_amount;
	search_an_employee_to_edit finder;
	checker<employee> extra_remove;
	vector <string> deps;
	subdivision to_choose;
	unsigned int choice;
public:
	reports() {
		salary_money = workers_amount = choice = 0;
	}
	void create_a_report(vector<employee>& first) {
		cout << "Выполнить отчёт по следующим подразделениям: \n";
		deps = to_choose.get_sub();
		deps.push_back("Все");
		int j = 1;
		for (string i : deps) {
			cout << j << ' ' << i << endl;
			j++;
		}
		cout << "Выберите пункт: ";
		cin >> choice;
		j = 0;
		system("cls");
		if (choice < deps.size() - 1) {
			for (employee i : first) {
				if (i.get_department() == deps[choice - 1]) {
					salary_money += i.get_salary();
					j++;
				}
			}
			workers_amount = j;
			cout << setw(20) << "Итого работников: " << setw(4) << workers_amount << " человек\n";
			cout << setw(20) << "Итого затрат: " << setw(4) << salary_money << " рублей/мес\n";
			workers_amount = salary_money = 0;
		}
		else if (choice == deps.size()) {
				cout << setw(20) << setiosflags(ios::left) << "Отдел" << " | " << setw(18) << "Затраты (руб/мес)" << " | " << setw(30) << "Количество сотрудников (чел)" << endl
					<< "--------------------------------------------------------------------------" << endl;
				for (int i = 0; i < deps.size() - 1; i++) {
					for (int k = 0; k < first.size(); k++) {
						if (first[k].get_department() == deps[i]) {
							salary_money += first[k].get_salary();
							j++;
						}
					}
					workers_amount = j;
					cout << setw(20) << setiosflags(ios::left) << deps[i] << " | " << setw(18) << salary_money << " | " << setw(30) << workers_amount << endl;
					salary_money = workers_amount = j = 0;
			}
				j = 0;
				for (employee i : first) {
					salary_money += i.get_salary();
					j++;
				}
				cout << "--------------------------------------------------------------------------" << endl;
				workers_amount = j;
				cout << setw(20) << setiosflags(ios::left) << "Итого работников: " << setw(4) << setiosflags(ios::left) << workers_amount << " человек\n";
				cout << setw(20) << setiosflags(ios::left) << "Итого затрат: " << setw(4) << setiosflags(ios::left) << salary_money << " рублей/мес\n";
				salary_money = 0; j = 0;
				cout << setw(20) << "Итого подразделений: " << setw(4) << deps.size() - 1 << endl;
		}
		else {
			cerr << "Вы ввели некорректные данные, повторите попытку" << endl;
		}
	}
};

//класс для смены логина и пароля
class login_changer {
private:
	new_file files;
	int choice;
	string hash_path_l;
	string hash_path_p;
public:
	login_changer() {
		hash_path_l = "LOGIN.txt";
		hash_path_p = "PASSWORD.txt";
	}
	string get_hash_l() { return hash_path_l; };
	string get_hash_p() { return hash_path_p; };
	void change_login(vector<string> &login, vector<string> &password, int k) {
		cout << "1-Сменить логин\n2-Сменить пароль\n";
		cin >> choice;
		if (choice == 1) {
			cout << "Текущий логин: " << login[k] << endl;
			string new_login;
			cout << "Введите новый логин: ";
			cin >> new_login;
			login[k] = new_login;
			for (int i = 0; i < login.size(); i++) {
				for (int j = 0; j < login[i].length(); j++)
					login[i][j] = login[i][j] + login.size();
			}
			files.write_hash(login, hash_path_l);
			cout << "Данные успешно изменены\n";
		}
		else if (choice == 2) {
			cout << "Текущий пароль: " << password[k] << endl;
			string new_password;
			cout << "Введите новый пароль: ";
			cin >> new_password;
			login[k] = new_password;
			for (int i = 0; i < password.size(); i++) {
				for (int j = 0; j < password[i].length(); j++)
					login[i][j] = password[i][j] + login.size();
			}
			files.write_hash(password, hash_path_p);
			cout << "Данные успешно изменены\n";
		}
		else {
			cerr << "Вы ввели некорректные данные, повторите попытку" << endl;
		}
	}
};

//управляющий класс, работающий со всеми классами
class manager_of_classes {
private:
	remover terminator;
	search_an_employee_to_edit in_work;
	editor edit_me;
	new_file files;
	checker<employee> extra_remove;
	checker<fired_employee> extra_remove_2;
	sort_employees nicer;
	reports paper;
	login_changer key;
public:
	void watch_info(vector<employee>& first) {
		first.resize(first.size() + 1);
		files.file_read_out(first);
		extra_remove.vector_size(first);
		first[0].cap();
		int j = 1;
		for (employee i : first) {
			i.output_employee(j);
			j++;
		}
	}
	void watch_info(vector<fired_employee>& last) {
		last.resize(last.size() + 1);
		files.file_read_out(last);
		extra_remove_2.vector_size(last);
		last[0].fired_cap();
		int j = 1;
		for (fired_employee i : last) {
			i.output_fired(j);
			j++;
		}
	}
	void input_info(vector<employee>& first) {
		int answer;
		string _lname;
		for (int i = 0; i < 1; i++) {
			first[i].input_employee();
			_lname = first[i].get_lname();
		}
		cin.ignore();
		cout << "Вы хотите сохранить? \n";
		cout << "1 - Да\n" << "2 - Нет\n";
		cin >> answer;
		if (answer == 1)
			files.file_write_in(first);
		else
			terminator.find_and_delete(first, _lname);
	}
	void remove(vector<employee>& first, vector<fired_employee>& last) {
		files.file_read_out(first);
		extra_remove.vector_size(first);
		files.file_read_out(last);
		terminator.find_and_delete(first, last);
		files.file_write_in(last);
		files.edit_in_file(first);
	}
	void searching_and_sort(vector<employee>& database) {
		database.resize(database.size() + 1);
		files.file_read_out(database);
		extra_remove.vector_size(database);
		cout << "1 Поиск\n2 Сортировка\n3 Поиск по отделам\n";
		int answer;
		cin >> answer;
			if (answer == 1) {
				in_work.find_and_show(database);
			}
			else if (answer == 2) {
				nicer.sort_the_data(database);
				files.edit_in_file(database);
				files.file_read_out(database);
				extra_remove.vector_size(database);
				database[0].cap();
				for (unsigned int i = 0; i < database.size(); i++) {
					database[i].output_employee(i + 1);
				}
			}
			else if (answer == 3) {
				string tmp = in_work.show_department_workers();
				database[0].cap();
				for (unsigned int i = 0; i < database.size(); i++) {
					if (tmp == database[i].get_department())
						database[i].output_employee(i + 1);
				}
			}
			else {
				cerr << "Вы ввели некорректные данные" << endl;
				system("pause");
			}
	}
	void searching_and_sort(vector <fired_employee>& database) {
		database.resize(database.size() + 1);
		files.file_read_out(database);
		extra_remove_2.vector_size(database);
		cout << "1 Поиск\n2 Сортировка\n";
		int answer;
		cin >> answer;
		if (answer == 1) {
			in_work.find_and_show(database);
		}
		if (answer == 2) {
			nicer.sort_the_data(database);
			files.edit_in_file(database);
			system("cls");
			files.file_read_out(database);
			extra_remove_2.vector_size(database);
			for (unsigned int i = 0; i < database.size(); i++)
				database[i].output_fired(i + 1);
		}
	}
	void edit_an_employee(vector<employee>& first) {
		files.file_read_out(first);
		extra_remove.vector_size(first);
		edit_me.edit_the_info(first);
		files.edit_in_file(first);
	}
	void edit_an_employee(vector<employee>& first, int for_finance) {
		files.file_read_out(first);
		extra_remove.vector_size(first);
		edit_me.edit_info_for_finance(first);
		files.edit_in_file(first);
	}
	void report(vector<employee>& first) {
		files.file_read_out(first);
		extra_remove.vector_size(first);
		paper.create_a_report(first);
	}
	void change_login(vector<string> &login, vector<string>& login_2, int k) {
		key.change_login(login, login_2, k);
	}
};

/*----------------------------------------------------------КЛАССЫ, УПРАВЛЯЮЩИЕ РАБОТОЙ МЕНЮ-------------------------------------------------------------*/

//класс выбора меню с применением наследования
class menu_choice {
protected:
	manager_of_classes watcher;
	int choice;
public:
	menu_choice() {
		choice = 0;
	}
	virtual void choice_m(vector<employee>& first) {}; //виртуальная функция для различной инициализации в подклассах
	virtual void choice_m(vector<employee>& first, int for_finance) {};
	virtual void choice_m(vector<fired_employee>& last) {};
	virtual void choice_m(vector<employee>& first, vector<fired_employee>& last) {};
	virtual void choice_m(vector<string>& login, vector<string>& login_2, int k) {};
};

class watch_info_m : public menu_choice {
public:
	void choice_m(vector<employee>& first) override {
		watcher.watch_info(first);
	}
	void choice_m(vector<fired_employee>& last) override {
		watcher.watch_info(last);
	}
};

class input_info_m : public menu_choice {
public:
	void choice_m(vector<employee>& first) override {
		watcher.input_info(first);
	}
};

class delete_any_info_m : public menu_choice {
public:
	void choice_m(vector<employee>& first, vector<fired_employee>& last) override {
		watcher.remove(first, last);
	}
};

class rewrite_the_info : public menu_choice {
public:
	void choice_m(vector<employee>& first) override {
		watcher.edit_an_employee(first);
	}
	void choice_m(vector<employee>& first, int for_finance) {
		watcher.edit_an_employee(first, for_finance);
	}
};

class find_info_m : public menu_choice {
public:
	void choice_m(vector<employee>& first) override {
		watcher.searching_and_sort(first);
	}
	void choice_m(vector<employee>& first, vector<fired_employee>& last) override {
		cout << "Выберите базу для поиска и сортировки:\n1 Текущие сотрудники\n2 Уволенные сотрудники\n";
		int choice;
		cin >> choice;
		if (choice == 1) watcher.searching_and_sort(first);
		else if (choice == 2) watcher.searching_and_sort(last);
		else cerr << "Неверно введены данные" << endl;
	}
};

class report_m: public menu_choice{
public:
	void choice_m(vector<employee>& first) override {
		watcher.report(first);
	}
};

class l_p_m : public menu_choice {
	void choice_m(vector <string> &login, vector <string> &login_2, int k) {
		watcher.change_login(login, login_2, k);
	}
};

//класс, поволяющий использовать тип подкласса для перенаправления в определённую функциональность
class selection {
public:
	void choice_m(menu_choice* selection, vector<employee>& first) {
		selection->choice_m(first);
	}
	void choice_m(menu_choice* selection, vector<employee>& first, int for_finance) {
		selection->choice_m(first, for_finance);
	}
	void choice_m(menu_choice* selection, vector<fired_employee>& last) {
		selection->choice_m(last);
	}
	void choice_m(menu_choice* selection, vector<employee>& first, vector<fired_employee>& last) {
		selection->choice_m(first, last);
	}
	void choice_m(menu_choice* selection, vector<string>& login, vector<string>& login_2, int k) {
		selection->choice_m(login, login_2, k);
	}
};

/*----------------------------------------------------------ГРАНИЧНЫЕ КЛАССЫ (UI)------------------------------------------------------------------------*/

//класс, обеспечивающий меню (интерфейс взаимодействия с пользователем)
class menu {
private:
	vector<string> menu_choice;
	vector<string> menu_choice_2;
	vector<string> menu_choice_3;
	watch_info_m item_1;
	selection start;
	input_info_m item_2;
	delete_any_info_m item_3;
	find_info_m item_4;
	rewrite_the_info item_5;
	report_m item_6;
	l_p_m item_7;
	int pointer;
public:
	menu() {
		pointer = 0;
		menu_choice.push_back("Список сотрудников\n");
		menu_choice.push_back("Добавить сотрудника\n");
		menu_choice.push_back("Удалить сотрудника (уволить)\n");
		menu_choice.push_back("Поиск и сортировка\n");
		menu_choice.push_back("Редактирование данных\n");
		menu_choice.push_back("Сменить логин и пароль\n");
		menu_choice.push_back("Выход\n");
		menu_choice_2.push_back(menu_choice[0]);
		menu_choice_2.push_back(menu_choice[3]);
		menu_choice_2.push_back(menu_choice[4]);
		menu_choice_2.push_back(menu_choice[5]);
		menu_choice_2.push_back(menu_choice[6]);
		menu_choice_3.push_back(menu_choice[0]);
		menu_choice_3.push_back(menu_choice[3]);
		menu_choice_3.push_back("Просмотр уволенных сотрудников\n");
		menu_choice_3.push_back("Отчёт по затратам\n");
		menu_choice_3.push_back(menu_choice[5]);
		menu_choice_3.push_back(menu_choice[6]);
	}
	void menu_work_1(int index, vector<string>& login, vector<string>& login_2) {
		vector<employee> Employee(0);
		vector<fired_employee> Fired(0);
			do {
				system("cls");
				for (unsigned int i = 0; i < menu_choice.size(); i++)
					cout << i + 1 << ' ' << menu_choice[i];
				cout << "Выберите пункт меню: ";
				cin >> pointer;
					switch (pointer) {
					case 1:system("cls"); start.choice_m(&item_1, Employee); system("pause"); break;
					case 2:system("cls"); Employee.resize(Employee.size() + 1); start.choice_m(&item_2, Employee); system("pause"); break;
					case 3:system("cls"); start.choice_m(&item_3, Employee, Fired); system("pause"); break;
					case 4:system("cls"); start.choice_m(&item_4, Employee); system("pause"); break;
					case 5:system("cls"); start.choice_m(&item_5, Employee); system("pause"); break;
					case 6:system("cls"); start.choice_m(&item_7, login, login_2, index); system("pause"); break;
					}
					if (pointer < 1 || pointer > 7) {
						cerr << "Вы ввели некорректные данные, повторите попытку" << endl;
						system("pause");
					}
			} while (pointer !=7);
	}
	void menu_work_2(int index, vector<string>& login, vector<string>& login_2) {
		vector<employee> Employee(0);
			do {
				system("cls");
				for (unsigned int i = 0; i < menu_choice_2.size(); i++)
					cout << i + 1 << ' ' << menu_choice_2[i];
				cout << "Выберите пункт меню: ";
				cin >> pointer;
					switch (pointer) {
					case 1:system("cls"); start.choice_m(&item_1, Employee); system("pause"); break;
					case 2:system("cls"); start.choice_m(&item_4, Employee); system("pause"); break;
					case 3:system("cls"); start.choice_m(&item_5, Employee, pointer); system("pause"); break;
					case 4:system("cls"); start.choice_m(&item_7, login, login_2, index); system("pause"); break;
				}
					if (pointer < 1 || pointer > 5) {
						cerr << "Вы ввели некорректные данные, повторите попытку" << endl;
						system("pause");
					}
			} while (pointer != 5);
	}
	void menu_work_3(int index, vector<string>& login, vector<string>& login_2) {
		vector<employee> Employee(0);
		vector<fired_employee> Fired(0);
		do {
			system("cls");
			for (unsigned int i = 0; i < menu_choice_3.size(); i++)
				cout << i + 1 << ' ' << menu_choice_3[i];
			cout << "Выберите пункт меню: ";
			cin >> pointer;
			switch (pointer) {
			case 1:system("cls"); start.choice_m(&item_1, Employee); system("pause"); break;
			case 2:system("cls"); start.choice_m(&item_4, Employee, Fired); system("pause"); break;
			case 3:system("cls"); start.choice_m(&item_1, Fired); system("pause"); break;
			case 4:system("cls"); start.choice_m(&item_6, Employee); system("pause"); break;
			case 5:system("cls"); start.choice_m(&item_7, login, login_2, index); system("pause"); break;
			}
			if (pointer < 1 || pointer > 6) {
				cerr << "Вы ввели некорректные данные, повторите попытку" << endl;
				system("pause");
			}
		} while (pointer != 6);
	}
};

//функции дешифровки пароля/логина
vector<string> un_hash(string hash_path) {
	vector<string> login;
	new_file files;
	login = files.read_hash(hash_path);
	login.resize(3);
	for (int i = 0; i < login.size(); i++) {
		for (int j = 0; j < login[i].length(); j++)
			login[i][j] = login[i][j] - login.size();
	}
	return login;
}

//класс пользовательского входа
class log_in {
private:
	menu one;
	string login;
	string password;
	int choice, index;
	vector<string> l;
	vector<string> p;
	login_changer paths;
public:
	log_in() {
		do {
			l = un_hash(paths.get_hash_l());
			p = un_hash(paths.get_hash_p());
			system("cls");
			cout << "1-Войти в учётную запись\n2-Выйти из программы\n";
			cin >> choice;
			if (choice == 1) {
				system("cls");
					cout << "Введите логин: ";
					cin >> login;
					cout << "Введите пароль: ";
					char c;
					while ((c = _getch()) != '\r') {
							password.push_back(c);
							_putch('*');
					}
					cout << endl;
					if (login == l[0] && password == p[0]) {
						index = 0;
						one.menu_work_1(index, l, p);
						login = "";
						password = "";
					}
					else if (login == l[1] && password == p[1]) {
						index = 1;
						one.menu_work_2(index, l, p);
						login = "";
						password = "";
					}
					else if (login == l[2] && password == p[2]) {
						index = 2;
						one.menu_work_3(index, l, p);
						login = "";
						password = "";
					}
					else {
						cerr << "Вы ввели неверный логин или пароль, повторите попытку!\n";
						login = "";
						password = "";
						system("pause");
					}
			}
			if (choice != 1 && choice != 2) {
				cerr << "Вы ввели некорректные данные, повторите попытку" << endl;
				system("pause");
			}
		} while (choice != 2);
		
	}
};

/*-----------------------------------------------------------------MAIN----------------------------------------------------------------------------------*/

int main() {
	system("color f0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	log_in start;
	return 0;
}