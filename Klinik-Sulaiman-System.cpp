// Klinik-Sulaiman-System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include "Patient.h"
#include "PatientQueue.h"
#include "Utility.h"
#include "Doctor.h"
#include "Nurse.h"


int main() {
	PatientQueue* p = new PatientQueue();
	LinkedList* h = new LinkedList();
	Doctor* doctor = new Doctor(p,h);
	Nurse* nurse = new Nurse(p,h);
	std::string username;
	std::string password;
	char loginAsDoctor;
	int loginStatus = 0;
	while (true) {
		std::cout << "Login Page" << std::endl;
		std::cout << "Username : ";
		getline(std::cin, username);
		std::cout << "Password : ";
		password = Utility::getPassword();
		std::cout << "\nEnter 1 to login as doctor, otherwise enter any key to login as nurse :";
		std::cin >> loginAsDoctor;
		std::cin.ignore(256, '\n');
		loginStatus = Utility::login(username,password,loginAsDoctor);
		system("cls");
		if (loginStatus == -1) {
			std::cout << "Login failed. Invalid credentials provided. Please try again." << std::endl;
			system("pause");
		}
		// Doctor
		else if (loginStatus == 0) {
			char choice = 0;
			while (true) {
				Utility::displayDoctorMenu();
				std::cin >> choice;
				cin.ignore(256, '\n');
				if (choice == '1')
					doctor->viewInfo();
				else if (choice == '2') {
					// search and modify patients ("treat patient")
				}
				else if (choice == '3') {
					// search patient
					doctor->searchPatient();
				}
				else {
					break;
				}
			}
		}
		else {
			//nurse
			while (true) {
				nurse->displayNurseMenu();
			}
		}
		system("cls");
	}
	return 0;

}

int test() {

	//doctor* d = new doctor(p);
	//nurse* n = new nurse(p);
	//for (int i = 0; i < 3; i++) {
	//	patient* a;
	//	a = n->createpatient();
	//	if (i % 2 == 0)*/
	//	a = new patient("a" + std::to_string(i), "a", "a", "a", "a","a", true);*/
	//	else
	//		a = new patient("a" + std::to_string(i), "a", "a", "a", "a", false);
	//	p->insertpatient(a);
	//}
	//p->displayinqueue();
	//d->viewinfo();
	return 0;
}
