#include<iostream>
#include<chrono>
#include<thread>
#include<fstream>
#include<string>



using namespace std;
void Adminchoice();
void Addpatient();
void Adddoctor();
void Viewpatients();
void Viewdoctors();

string Adminusername;
void Adminchoice() {
	int adminchoice;

	cout << "_______________________________" << endl;
	cout << "|                             |" << endl;
	cout << "|=======Daryeel Hospital======|" << endl;
	cout << "|                             |" << endl;
	cout << "-------------------------------" << endl;
	cout << endl;
	cout << "Welcome Admin "<<Adminusername<<" to Daryeel Hospital\n";
	cout << endl;

	cout << "1.Add Patient\n2.View Patients\n3.Add Doctor\n4.View Doctors\n";
	cout << "5.Log Out\n";
	cout << "Enter your Choice: ";
	cin >> adminchoice;

	switch (adminchoice) {
	case 1:
		Addpatient();
		break;
	case 2:
		Viewpatients();
		break;
	case 3:
		Adddoctor();
		break;
	case 4:
		Viewdoctors();
		break;
	case 5:
		cout << "Loggin OUt.";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(1));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(2));
		cout << ".";
		this_thread::sleep_for(chrono::seconds(2));
		cout << "\nLogged out Sucessfully!";
		break;

	default:
		cout << "Invalid Choice.Please Try again....\n";
		Adminchoice();
		break;
	}
}
void Addpatient() {
	string patientName, patientAge, patientIllness;

	cout << "Enter Patient Name: ";
	cin.ignore();
	getline(cin, patientName);

	cout << "Enter Patient Age: ";
	getline(cin, patientAge);

	cout << "Enter Patient Illness: ";
	getline(cin, patientIllness);

	ofstream file("Patients.txt", ios::app);
	if (file.is_open()) {
		file << patientName << " " << patientAge << " " << patientIllness << endl;
		file.close();
		cout << "Saving patient.";
		for (int q = 0;q < 6;q++) {
			cout << ".";
			this_thread::sleep_for(chrono::seconds(1));
		}
		cout << "\nPatient added successfully!\n";
	}
	else {
		cout << "ERROR: opening patients.txt!!\n";
	}
}
void Viewpatients() {
	ifstream file("Patients.txt");
	if (file.is_open()) {
		string line;
		cout << "_______________________________" << endl;
		cout << "|                             |" << endl;
		cout << "|=========Patient List========|" << endl;
		cout << "|                             |" << endl;
		cout << "-------------------------------" << endl;

		cout << endl;
		cout << "Name---------Age------Illness" << endl;
		while (getline(file, line)) {
				cout << line << endl;
		}
		cout << endl;
		file.close();
	}
	else {
		cout << "No Patients were found or unable to open doctors.txt\n";
	}
}
void Adddoctor() {
	string doctorName, doctornSpecilist;
	string doctorNumber;
	cout << "Enter Doctor Name: ";
	cin.ignore();
	getline(cin, doctorName);

	cout << "Enter Doctor Specilizatiom: ";
	getline(cin, doctornSpecilist);

	cout << "Enter Doctor Phone Number: ";
	getline(cin, doctorNumber);


	ofstream file("Doctors.txt", ios::app);
	if (file.is_open()) {
		file << doctorName << " " << doctornSpecilist << " " << doctorNumber << endl;
		file.close();
		cout << "Saving Doctor Info.";
		for (int i = 0; i < 6; i++) {
			cout << ".";
		}
		cout << "\nDoctor added successfully!\n";
	}
	else {
		cout << "ERROR: opeing doctors.txt!!!\n";
	}

}
void Viewdoctors() {
	

	ifstream file("Doctors.txt");
	if (file.is_open()) {
		string line;
		
	cout << "_______________________________" << endl;
	cout << "|                             |" << endl;
	cout << "|=========Doctors List========|" << endl;
	cout << "|                             |" << endl;
	cout << "-------------------------------" << endl;

	cout << endl;
	while (getline(file, line)) {
		cout << line << endl;
		
	}
	cout << endl;
	file.close();
	}
	else {
		cout << "Unable to open file or NO doctors were registered yet!!\n";
	}
}

int main() {
	string Adminusername, Adminpassword;
	cout << "\n_______________________________" << endl;
	cout << "|                             |" << endl;
	cout << "|=======SYSTEM SECURITY=======|" << endl;
	cout << "|                             |" << endl;
	cout << "-------------------------------" << endl;

	
	cout << "Enter Admin Username: ";
	cin >> Adminusername;

	cout << "Enter Admin Password: ";
	cin >> Adminpassword;


	if (Adminusername == "Mohammed" && Adminpassword == "2024") {
		Adminchoice();
	}
	else {
		cout << "Invalid Username or Password.. PLease Try again.";
			for (int i = 0; i < 6; i++) {
				cout << ".";
				this_thread::sleep_for(chrono::seconds(1));
			}
			main();
		
	}
	return 0;
}