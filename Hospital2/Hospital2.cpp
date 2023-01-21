#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;

class Patients
{
public:
	string name;
	int    age;
	string disease;
	vector<string>  disease_history;

	Patients(const char* _name, int _age, const char* _disease, const vector<string>& list_of_diseases) : disease_history(list_of_diseases)
	{
		disease = _disease;

		name = string(_name);
		age = _age;
	}
};


class Hospital
{
private:

	vector<string> list_of_diseases;
	map<int, Patients> patients;
	int k = 0;

public:

	Hospital(const vector<string>& vec) : list_of_diseases(vec)
	{


	}


	void registration(int id, Patients& patient)
	{
		patients.insert({ id, patient });
	}

	void write_out(int id, Patients patient)
	{
		map<int, Patients>::iterator it = patients.find(id);

		cout << "patient  with id =" << id << " and name" << (*it).second.name << "  - write out; " << endl << endl;
		patients.erase(it);
	}

	void procedures(int id, Patients& patient)
	{
		for (int i = 0; i < list_of_diseases.size(); i++)
		{
			if (patient.disease == list_of_diseases[i])
			{
				cout << "patient  with id =" << id << "   and name = " << patient.name << "  - procedure performed; " << endl;
				write_out(id, patient);
				k++;
				return;
			}
		}


		cout << " transferred to another hospital" << endl;
		write_out(id, patient);
	}

	int  number_procedures_performed()
	{
		return k;
	}
};

int main()
{

	Patients pati_1("aaa", 10, "aaa", { "q1", "w2", "e3" });
	Patients pati_2("ddd", 2, "ddd", { "qq", "ww", "ee" });
	Patients pati_3("ccc", 2, "xxx", { "qq", "ww", "ee" });


	Hospital hospital({ "aaa", "bbb", "ccc" });

	hospital.registration(1, pati_1);
	hospital.registration(2, pati_2);
	hospital.registration(3, pati_3);

	hospital.procedures(1, pati_1);
	hospital.procedures(2, pati_2);

	hospital.write_out(3, pati_3);


}
