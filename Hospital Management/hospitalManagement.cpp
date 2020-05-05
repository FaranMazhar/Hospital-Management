//Program by Faran Mazhar to Manage a hospital's Patient Record
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	cout << "***Patient Record Management System***\n";
	const int SIZE = 1000;
	int type[SIZE];
	int id[SIZE];
	int age[SIZE];
	char gender[SIZE];
	char gen;            // for avoiding error
	int specRoom[SIZE];  //for saving the patient's room number
	char names[SIZE][30];
	char diseases[SIZE][50];
	int roomNum;
	int roomCount201 = 5, roomCount202 = 5, roomCount203 = 5, roomCount204 = 5, roomCount205 = 5;   //for capacity of a room
	int searchID, edit, totalCharge, charge, deposit, day, month, year;
	int deletingPatient = -1;
	bool repeat = false;
	int itr = 0;         // patient counter
	char billChoice;    //for giving billing option
	cout << "---Today's Date---\n";
	bool correctDate = false;   // for correct date input
	bool correctBill = false;   //for correct bill choice input
	for (; !correctDate;)
	{
		cout << "Day [1-30] ------ ";
		cin >> day;
		if ((day >= 1) && (day <= 30))
		{
			correctDate = true;
		}
		else
		{
			cout << "Invalid Date.\nPlease enter Date again\n";
		}
	}

	bool correctMonth = false;
	for (; !correctMonth;)
	{
		cout << "Month [1-12] ---- ";
		cin >> month;
		if ((month >= 1) && (month <= 12))
		{
			correctMonth = true;
		}
		else
		{
			cout << "Invalid Month.\nPlease enter Month again\n";
		}
	}

	bool correctYear = false;
	for (; !correctYear;)
	{
		cout << "Year  ----------- ";
		cin >> year;
		if ((year >= 2000) && (year <= 2030))
		{
			correctYear = true;
		}
		else
		{
			cout << "Invalid Year.\nPlease enter Year again\n";
		}
	}
	cout << "Press any key to Proceed";
	_getch();
	system("cls");
	for (; !repeat;)
	{
		int choose;
		cout << "1. Add a new Patient.\n";
		cout << "2. Search or Edit Patient.\n";
		cout << "3. Delete Patient Record.\n";
		cout << "4. Show Patients Record.\n";
		cout << "0. EXIT\n";
		cout << "Choose an option[0-4]: ";
		cin >> choose;
		if (choose == 1)
		{
			system("cls");
			cout << "***Adding a new Patient***\n";
			cout << "\n---Patient's Type---\n";
			cout << "1. O.P.D\n";
			cout << "2. Emergency Patient\n";
			bool correctType = false;
			for (; !correctType;)
			{
				cout << "Choose Patient's Type[1/2]: ";
				cin >> type[itr];
				if (type[itr] == 2 || type[itr] == 1)
				{
					correctType = true;
				}
				else
				{
					cout << "Invalid Type.\nPlease enter Type again\n";
				}
			}
			system("cls");
			if (type[itr] == 1)
			{
				cout << "***Adding a new OPD Patient***\n";
			}
			else
			{
				cout << "***Adding a new Emergency Patient***\n";
			}
			id[itr] = itr + 1;
			cout << "Patient's ID --------------------------------- " << id[itr] << endl;
			cout << "Enter Patient's Name ------------------------- ";
			for (int n = 0; n < 2; n++)
			{
				cin.getline(names[itr], 30);
			}
			bool correctGen = false;
			for (; !correctGen;)
			{
				cout << "Enter Patient's Gender[M/F] ------------------ ";
				cin >> gen;
				if (gen == 'm' || gen == 'M' || gen == 'f' || gen == 'F')
				{
					correctGen = true;
				}
				else
				{
					cout << "Invalid Gender.\nPlease enter Gender again\n";
				}
			}
			gender[itr] = gen;
			bool correctAge = false;
			for (; !correctAge;)
			{
				cout << "Enter Patient's Age -------------------------- ";
				cin >> age[itr];
				if (age[itr] > 0 && age[itr] < 120)
				{
					correctAge = true;
				}
				else
				{
					cout << "Invalid age. Please input Age again.\n";
				}
			}
			cout << "Enter Disease's (Seperate by Commas or Spcaes): ";
			for (int n = 0; n < 2; n++)
			{
				cin.getline(diseases[itr], 50);
			}
			cout << "Available rooms are: \n";
			if (roomCount201 > 0)
			{
				cout << "Room 201 [Space: " << roomCount201 << "]\n";
			}
			if (roomCount202 > 0)
			{
				cout << "Room 202 [Space: " << roomCount202 << "]\n";
			}
			if (roomCount203 > 0)
			{
				cout << "Room 203 [Space: " << roomCount203 << "]\n";
			}
			if (roomCount204 > 0)
			{
				cout << "Room 204 [Space: " << roomCount204 << "]\n";
			}
			if (roomCount205 > 0)
			{
				cout << "Room 205 [Space: " << roomCount205 << "]\n";
			}
			else
			{
				cout << "No Rooms Available. We apologize for the inconvenience.\n";
			}
			bool correctRoom = false;
			for (; !correctRoom;)
			{
				cout << "Choose Room Number: ";
				cin >> roomNum;
				if (roomNum == 201 || roomNum == 202 || roomNum == 203 || roomNum == 204 || roomNum == 205)
				{
					correctRoom = true;
				}
				else
				{
					cout << "Invalid room choosen. Please choose again.\n";
				}
			}cout << "Press any key to Proceed";
			_getch();
			system("cls");
			if (roomNum == 201)
			{
				specRoom[itr] = 201;
				roomCount201--;
			}
			else if (roomNum == 202)
			{
				specRoom[itr] = 202;
				roomCount202--;
			}
			else if (roomNum == 203)
			{
				specRoom[itr] = 203;
				roomCount203--;
			}
			else if (roomNum == 204)
			{
				specRoom[itr] = 204;
				roomCount204--;
			}
			else if (roomNum == 205)
			{
				specRoom[itr] = 205;
				roomCount205--;
			}

			for (; !correctBill;)
			{

				cout << "Would you like to Proceed to billing?[Y/N] ";
				cin >> billChoice;
				if (billChoice == 'Y' || billChoice == 'y' || billChoice == 'N' || billChoice == 'n')
				{
					correctBill = true;
				}
				else
				{
					cout << "Invalid option choosen. Please choose again!\n";
				}
			}
			if (billChoice == 'Y' || billChoice == 'y')
			{
				system("cls");
				cout << "***Billing***\n";
				cout << "Total Charge -------------------- ";
				cin >> charge;
				cout << "Enter Money Deposited ----------- ";
				cin >> deposit;
				totalCharge = deposit - charge;
				if (deposit > charge)
				{
					cout << "Hospital needs to return " << totalCharge << " PKR to Patient.\n";
					cout << "Press any key to Proceed";
					_getch();
					system("cls");
				}
				else if (deposit < charge)
				{
					totalCharge = totalCharge * -1;
					cout << "Charged amount has exceeded deposited amount.\n";
					cout << "Patient needs to deposit " << totalCharge << " PKR to complete their Bill.\n";
					cout << "Press any key to Proceed";
					_getch();
					system("cls");
				}
				else
				{
					cout << "The bill has been completely cleared.\n";
					cout << "Press any key to proceed ";
					_getch();
					system("cls");
				}
			}
			else
			{
				system("cls");
			}
			itr++;
		}
		else if (choose == 2)
		{

			system("cls");
			cout << "***Searching for a Patient***\n";
			cout << "Enter Patient's ID:";
			cin >> searchID;
			system("cls");
			bool foundCheck = false;
			for (int search = 0; search < itr; search++)
			{
				if (searchID == id[search])
				{
					foundCheck = true;
					if (type[search] == 1)
					{
						cout << "\n---O.P.D Patient---.\n";
					}
					else if (type[search] == 2)
					{
						cout << "\n---Emergency Patient---.\n";
					}
					int option;
					cout << "ID ------------------------------ " << id[search] << endl;
					cout << "Patient's Name ------------------ " << names[search] << endl;
					cout << "Age ----------------------------- " << age[search] << endl;
					cout << "Gender -------------------------- " << gender[search] << endl;
					cout << "Disease(s) ---------------------- " << diseases[search] << endl;
					cout << "Specialist's Room Number -------- " << specRoom[search] << endl;
					cout << "What would you like to do with Patient" << id[search] << endl;
					cout << "1. Edit\n";
					cout << "2. Bill\n";
					cout << "3. Nothing\n";
					cout << "Choose [1/2/3]: ";
					cin >> option;
					system("cls");
					if (option == 1)
					{
						bool repeatED = false;
						for (; !repeatED;)
						{
							cout << "***Editing Patient's Record***\n";
							cout << "0. Patient Type\n";
							cout << "1. Age\n";
							cout << "2. Gender\n";
							cout << "3. Disease(s)\n";
							cout << "4. Specialist's Room Number -------- " << specRoom[search] << endl;
							cout << "What would you like to edit for Patient ID[0-4]: " << id[search] << " ?";
							cin >> edit;
							system("cls");
							if (edit == 1)
							{
								cout << "***Editing Age***\n";
								bool correctAgeED = false;
								for (; !correctAgeED;)
								{

									cout << "Enter Patient's Age ------------------------ ";
									cin >> age[itr];
									if (age[itr] > 0 && age[itr] < 120)
									{
										correctAgeED = true;
									}
									else
									{
										cout << "Invalid age. Please input Age again.\n";
									}
								}
							}
							else if (edit == 2)
							{
								cout << "***Editing Gender***\n";
								bool correctGenED = false;
								for (; !correctGenED;)
								{
									cout << "Edit Patient's Gender[M/F] ------------------ ";
									cin >> gen;
									if (gen == 'm' || gen == 'M' || gen == 'f' || gen == 'F')
									{
										correctGenED = true;
									}
									else
									{
										cout << "Invalid Gender.\nPlease enter Gender again\n";
									}
								}
								gender[search] = gen;
							}
							else if (edit == 3)
							{
								cout << "***Editing  Disease-ID***\n";
								cout << "Enter Disease's (Seperate by Commas/Spcaes): ";
								for (int n = 0; n < 2; n++)
								{
									cin.getline(diseases[search], 50);
								}
							}
							else if (edit == 4)
							{
								cout << "***Moving Rooms***\n";
								cout << "Available rooms are: \n";
								if (roomCount201 > 0)
								{
									cout << "Room 201 [Space: " << roomCount201 << "]\n";
								}
								if (roomCount202 > 0)
								{
									cout << "Room 202 [Space: " << roomCount202 << "]\n";
								}
								if (roomCount203 > 0)
								{
									cout << "Room 203 [Space: " << roomCount203 << "]\n";
								}
								if (roomCount204 > 0)
								{
									cout << "Room 204 [Space: " << roomCount204 << "]\n";
								}
								if (roomCount205 > 0)
								{
									cout << "Room 205 [Space: " << roomCount205 << "]\n";
								}
								else
								{
									cout << "No Rooms Available to move the patient.\n";
								}
								bool correctRoomED = false;
								for (; !correctRoomED;)
								{
									cout << "Choose Room: ";
									cin >> roomNum;
									if (roomNum == 201 || roomNum == 202 || roomNum == 203 || roomNum == 204 || roomNum == 205)
									{
										correctRoomED = true;
									}
									else
									{
										cout << "Invalid room choosen. Please choose again.\n";
									}
								}

								if (roomNum == 201)
								{
									if (specRoom[search] == 201)
									{
										roomCount201++;
									}
									else if (specRoom[search] == 202)
									{
										roomCount202++;
									}
									else if (specRoom[search] == 203)
									{
										roomCount203++;
									}
									else if (specRoom[search] == 204)
									{
										roomCount204++;
									}
									else if (specRoom[search] == 205)
									{
										roomCount205++;
									}
									specRoom[search] = 201;
									roomCount201--;
								}
								else if (roomNum == 202)
								{
									if (specRoom[search] == 201)
									{
										roomCount201++;
									}
									else if (specRoom[search] == 202)
									{
										roomCount202++;
									}
									else if (specRoom[search] == 203)
									{
										roomCount203++;
									}
									else if (specRoom[search] == 204)
									{
										roomCount204++;
									}
									else if (specRoom[search] == 205)
									{
										roomCount205++;
									}
									specRoom[search] = 202;
									roomCount202--;
								}
								else if (roomNum == 203)
								{
									if (specRoom[search] == 201)
									{
										roomCount201++;
									}
									else if (specRoom[search] == 202)
									{
										roomCount202++;
									}
									else if (specRoom[search] == 203)
									{
										roomCount203++;
									}
									else if (specRoom[search] == 204)
									{
										roomCount204++;
									}
									else if (specRoom[search] == 205)
									{
										roomCount205++;
									}
									specRoom[search] = 203;
									roomCount203--;
								}
								else if (roomNum == 204)
								{
									if (specRoom[search] == 201)
									{
										roomCount201++;
									}
									else if (specRoom[search] == 202)
									{
										roomCount202++;
									}
									else if (specRoom[search] == 203)
									{
										roomCount203++;
									}
									else if (specRoom[search] == 204)
									{
										roomCount204++;
									}
									else if (specRoom[search] == 205)
									{
										roomCount205++;
									}
									specRoom[search] = 204;
									roomCount204--;
								}
								else if (roomNum == 205)
								{
									if (specRoom[search] == 201)
									{
										roomCount201++;
									}
									else if (specRoom[search] == 202)
									{
										roomCount202++;
									}
									else if (specRoom[search] == 203)
									{
										roomCount203++;
									}
									else if (specRoom[search] == 204)
									{
										roomCount204++;
									}
									else if (specRoom[search] == 205)
									{
										roomCount205++;
									}
									specRoom[search] = 205;
									roomCount205--;
								}
							}
							else if (edit == 0)
							{
								cout << "***Editing Type***\n";
								bool correctTypeED = false;
								for (; !correctTypeED;)
								{
									cout << "1. OPD\n2. Emergency";
									cout << "Edit Patient's Type[1/2]: ";
									cin >> type[itr];
									if (type[itr] == 2 || type[itr] == 1)
									{
										correctTypeED = true;
									}
									else
									{
										cout << "Invalid Type.\nPlease enter Type again\n";
									}
								}

							}
							cout << "Press 'e' if you would like to edit anything else ";
							char edChoice;
							cin >> edChoice;
							if (edChoice == 'e' || edChoice == 'E')
							{
								repeatED = true;
							}
							system("cls");
						}
					}
					else if (option == 2)
					{
						system("cls");
						cout << "***Billing***\n";
						cout << "Total Charge -------------------- ";
						cin >> charge;
						cout << "Enter Money Deposited ----------- ";
						cin >> deposit;
						totalCharge = deposit - charge;
						if (deposit > charge)
						{
							cout << "Hospital needs to return " << totalCharge << " PKR to Patient.\n";
							cout << "Press any key to Proceed";
							_getch();
							system("cls");
						}
						else if (deposit < charge)
						{
							totalCharge = totalCharge * -1;
							cout << "Charged amount has exceeded deposited amount.\n";
							cout << "Patient needs to deposit " << totalCharge << " PKR to complete their Bill.\n";
							cout << "Press any key to Proceed";
							_getch();
							system("cls");
						}
						else
						{
							cout << "The Bill has been Paid\n";
							cout << "Press any key to Proceed";
							_getch();
							system("cls");
						}
					}
					else if (option == 3)
					{
						system("cls");
					}
				}
			}
			if (!foundCheck)
			{
				cout << "No Records Found.\n";
				cout << "Press any key to proceed ";
				_getch();
				system("cls");
			}

		}
		else if (choose == 3)
		{
			system("cls");
			cout << "***Deleting Patient***\n";
			cout << "Enter Patient's ID to Delete: ";
			cin >> searchID;
			system("cls");

			bool foundCheckDel = false;
			for (int del = 0; del < itr; del++)
			{
				if (id[del] == searchID)
				{
					foundCheckDel = true;
					cout << "ID ------------------------------ " << id[del] << endl;
					cout << "Patient's Name ------------------ " << names[del] << endl;
					cout << "Age ----------------------------- " << age[del] << endl;
					cout << "Gender -------------------------- " << gender[del] << endl;
					cout << "Disease(s) ---------------------- " << diseases[del] << endl;
					cout << "Specialist's Room Number -------- " << specRoom[del] << endl;
					cout << "Press 'D' to delete Patient: " << id[del] << endl;
					char delChoice;
					cin >> delChoice;
					if (delChoice == 'd' || delChoice == 'D')
					{
						id[del] = deletingPatient;
						age[del] = deletingPatient;
						gender[del] = deletingPatient;
						if (specRoom[del] == 201)
						{
							roomCount201++;
						}
						else if (specRoom[del] == 202)
						{
							roomCount202++;
						}
						else if (specRoom[del] == 203)
						{
							roomCount203++;
						}
						else if (specRoom[del] == 204)
						{
							roomCount204++;
						}
						else if (specRoom[del] == 205)
						{
							roomCount205++;
						}
						specRoom[del] = deletingPatient;

						cout << "***Patient's record has been deleted***\n";
					}
					cout << "Press any key to Proceed";
					_getch();
				}
			}
			if (!foundCheckDel)
			{
				cout << "No Records Found.\n";
				cout << "Press any key to proceed ";
				_getch();
				system("cls");
			}

		}
		else if (choose == 4)
		{
			system("cls");
			cout << "***Listing Patients***\n";
			int sort;
			cout << "Show patient's list according to: \n";
			cout << "1. ID\n";
			cout << "2. OPD Patients\n";
			cout << "3. Emergency Patients\n";
			cout << "How would you like the patient list to be shown? ";
			cin >> sort;
			system("cls");
			if (sort == 1)
			{
				cout << "***Listing by IDs***\n";

				bool foundCheckID = false;
				for (int out = 0; out < itr; out++)
				{
					if (id[out] != deletingPatient)
					{
						foundCheckID = true;
						if (type[out] == 1)
						{
							cout << "\n---O.P.D Patient---.\n";
						}
						else if (type[out] == 2)
						{
							cout << "\n---Emergency Patient---.\n";
						}
						cout << "ID ------------------------------ " << id[out] << endl;
						cout << "Patient's Name ------------------ " << names[out] << endl;
						cout << "Age ----------------------------- " << age[out] << endl;
						cout << "Gender -------------------------- " << gender[out] << endl;
						cout << "Disease(s) ---------------------- " << diseases[out] << endl;
						cout << "Specialist's Room Number -------- " << specRoom[out] << endl;
						cout << "*************************************\n";
					}
				}
				if (!foundCheckID)
				{
					cout << "No Records Found.\n";
				}
				cout << "Press any key to proceed ";
				_getch();
				system("cls");
			}
			else if (sort == 2)
			{
				cout << "***Listing by OPD Type***\n";

				bool foundCheckOPD = false;
				for (int opd = 0; opd < itr; opd++)
				{
					if (id[opd] != deletingPatient)
					{

						if (type[opd] == 1)
						{
							foundCheckOPD = true;
							cout << "\n---O.P.D Patient---.\n";
							cout << "ID ------------------------------ " << id[opd] << endl;
							cout << "Patient's Name ------------------ " << names[opd] << endl;
							cout << "Age ----------------------------- " << age[opd] << endl;
							cout << "Gender -------------------------- " << gender[opd] << endl;
							cout << "Disease(s) ---------------------- " << diseases[opd] << endl;
							cout << "Specialist's Room Number -------- " << specRoom[opd] << endl;
							cout << "*************************************\n";
						}
					}
				}
				if (!foundCheckOPD)
				{
					cout << "No OPD Records Found.\n";
				}
				cout << "Press any key to proceed ";
				_getch();
				system("cls");
			}
			else if (sort == 3)
			{
				cout << "***Listing by Emergency Type***\n";

				bool foundCheckEM = false;
				for (int em = 0; em < itr; em++)
				{
					if (id[em] != deletingPatient)
					{
						if (type[em] == 2)
						{
							foundCheckEM = true;
							cout << "\n---Emergency Patient---.\n";
							cout << "ID ------------------------------ " << id[em] << endl;
							cout << "Patient's Name ------------------ " << names[em] << endl;
							cout << "Age ----------------------------- " << age[em] << endl;
							cout << "Gender -------------------------- " << gender[em] << endl;
							cout << "Disease(s) ---------------------- " << diseases[em] << endl;
							cout << "Specialist's Room Number -------- " << specRoom[em] << endl;
							cout << "*************************************\n";
						}
					}
				}
				if (!foundCheckEM)
				{
					cout << "No Emergency Records Found.\n";
				}
				cout << "Press any key to proceed ";
				_getch();
				system("cls");
			}
		}
		else if (choose == 0)
		{
			repeat = true;
		}
	}
}