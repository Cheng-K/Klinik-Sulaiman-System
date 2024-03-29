// Klinik-Sulaiman-System.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author : Ong Cheng Kei TP055620
//			Kong Kei Zhong TP055016
//			Wong Jack Yih  TP055436

#include <iostream>
#include <string>
#include "Utility.h"
#include "LinkedList.h"
#include "Doctor.h"
#include "Nurse.h"
#include "PatientQueue.h"
#include "Patient.h"



Patient* INIT_PATIENTQUEUE[5] = { new Patient("PID6", "Hui Lin", "Loe", "20", "female", "0132223194","21,Jalan APU, Taman TPM","Fever", "", "Ong", false),
	new Patient("PID7", "James", "Ethan", "30","male","0124428984","21,Jalan APU, Taman TPM","Migraine", "", "Ong", true),
	new Patient("PID8", "Chi En", "Chew", "21","male","0193873275","21,Jalan APU, Taman TPM","Malnutrition", "", "Wong", false),
	new Patient("PID9", "Bruh", "Kong", "25","others","0162985667","21,Jalan APU, Taman TPM ","Infection", "", "Ong", true),
	new Patient("PID10", "Hua Iong", "Lee", "19","male","0193893758","21,Jalan APU, Taman TPM","Prostate disease", "", "Wong", false) };

Patient* INIT_HISTORYLIST[5] = { new Patient("PID1", "Hui Yin", "Loe","18","female","0193875637","21,Jalan APU, Taman TPM", "Fever", "", "Ong", false),
	new Patient("PID2", "Benson", "Junior", "17","others","0173846758","21,Jalan APU, Taman TPM","Migraine", "", "Ong", true),
	new Patient("PID3", "Chi En", "Ooi", "24","female","0183758275","21,Jalan APU, Taman TPM","Nauseous", "", "Wong", false),
	new Patient("PID4", "Kei Zhong", "Kong", "20","male","0162895784","21,Jalan APU, Taman TPM","Infection", "", "Ong", true),
	new Patient("PID5", "Hua Long", "Lee","35","male","0163847182","21,Jalan APU, Taman TPM ", "Prostate disease", "Antibiotics", "Wong", false) };

int INIT_HISTORYTIME[5][3] = {
	{9,01,01},
	{9,30,59},
	{10,05,0},
	{13,00,00},
	{16,55,0},
};

int INIT_HISTORYDATE[5][3] = {
	{9,9,121},
	{10,9,121},
	{11,9,121},
	{13,9,121},
	{16,9,121},
};

int main() {
	PatientQueue* p = new PatientQueue();
	LinkedList* h = new LinkedList();
	Doctor* doctor = new Doctor(p,h);
	Nurse* nurse = new Nurse(p,h);
	
	for (int i = 0;i < 5; i++)
	{
		p->insertPatient(INIT_PATIENTQUEUE[i]);
		INIT_HISTORYLIST[i]->setTime(INIT_HISTORYTIME[i][0], INIT_HISTORYTIME[i][1], INIT_HISTORYTIME[i][2]);
		INIT_HISTORYLIST[i]->setVisitDay(INIT_HISTORYDATE[i][0], INIT_HISTORYDATE[i][1], INIT_HISTORYDATE[i][2]);
		h->insertAtFront(INIT_HISTORYLIST[i]);
	}
	system("cls");
	std::string username;
	std::string password;
	char loginAsDoctor;
	int loginStatus = 1;
	while (true) {
		std::cout << "Login Page" << std::endl;
		std::cout << "Username : ";
		getline(std::cin, username);
		std::cout << "Password : ";
		password = Utility::getPassword();
		std::cout << "\nEnter 1 to login as doctor, otherwise enter any key to login as nurse :";
		std::cin >> loginAsDoctor;
		std::cin.ignore(256, '\n');
		loginStatus = Utility::login(username,password,loginAsDoctor,doctor,nurse);
		system("cls");
		if (loginStatus == -1) {
			std::cout << "Login failed. Invalid credentials provided. Please try again." << std::endl << std::endl;
			system("pause");
		}
		// Doctor
		else if (loginStatus == 0) {
			doctor->displayDoctorMenu();
		}
		else {
			//nurse
			nurse->displayNurseMenu();
		}
		system("cls");
	}
	return 0;
}



