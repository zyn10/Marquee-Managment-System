#include<list>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<stdio.h>
#include<cstring>
#include<string.h>
using namespace std;
class CustomerForm;
struct Marquee;
struct HallTiming;
void LoadMarqueeData(Marquee*);
void displayDataFromFile(Marquee*);
void displayOptimalMarqueeInfo(Marquee*, list<int>);
void optimalMarquee(Marquee*,CustomerForm*);
int getRange(int, int);
bool setMaxPoints(int,int);
struct HallTiming
{
	int hour, minute;
};

struct Marquee {
	HallTiming objT;
	string marqueeLocation, promoCode;
	list<string> cuisineName;
	int noOfCuisine, guestCapacity, perHeadPrice, transportQuantityCar, transportQuantityBus;
	double marqueeRent, cateringPrice;
	bool funLand, package, transportService;
};

class CustomerForm
{
	list<pair<string,int>> cuisineIndex;
	HallTiming objTime;
	string customerLocation, promoCode, marqueeName, customerName;
	double marqueeRent, cateringPrice, transportPrice;
	float packageDiscount, promoDiscount;
	int no_of_Guests, perHeadPrice, NoOfCuisine, transportQuantityCar, transportQuantityBus;
	bool funLand, package, transportService, code;
public:
	CustomerForm() {

	};
	void clearInput() {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	void CustomerFormFill()
	{
		int option = 0;
		cout << "ENTER CUSTOMER NAME: ";
		getline(cin, customerName);
		do {
			displayLocations();
			cout << "\nENTER YOUR LOCATION: ";
			cin >> option;
			if (cin.fail())
			{
				clearInput();
			}
			else if (option >= 0 || option < 9)
			{
				break;
			}
		} while (true);
		setCustomerLocation(option);
		do {
			displayCuisine();
			cout << "\nHOW MANY CUISINES YOU WANT: ";
			cin >> NoOfCuisine;
			if (cin.fail())
			{
				clearInput();
			}
			else if (NoOfCuisine >= 0 || NoOfCuisine < 8)
			{
				break;
			}
		} while (true);

		displayCuisine();
		for (int i = 0; i < NoOfCuisine; i++)
		{
			int select = 0;
			cout << "\nSELECT THE CUISINES YOU WANT: ";
			cin >> select;
			if (select <= 0 || select > 8)
			{
				cout << "CUISINE NOT FOUND\n";
				i--;
			}
			else
			{
				switch (select) {
					case 1:
						cuisineIndex.push_back(make_pair("PAKISTANI CUISINE", select));
						break;
					case 2:
						cuisineIndex.push_back(make_pair("THAI CUISINE", select));
						break;
					case 3:
						cuisineIndex.push_back(make_pair("FRENCH CUISINE", select));
						break;
					case 4:
						cuisineIndex.push_back(make_pair("CHINESE CUISINE", select));
						break;
					case 5:
						cuisineIndex.push_back(make_pair("ITALIAN CUISINE", select));
						break;
					case 6:
						cuisineIndex.push_back(make_pair("SPANISH CUISINE", select));
						break;
					case 7:
						cuisineIndex.push_back(make_pair("JAPANESE CUISINE", select));
						break;
					case 8:
						cuisineIndex.push_back(make_pair("TURKISH CUISINE", select));
						break;
				}
			}
		}
	
		do {
			cout << "ENTER THE GUEST CAPACITY: ";
			cin >> option;
			if (cin.fail())
			{
				clearInput();
			}
			else if (option >= 0)
			{
				break;
			}
		} while (true);
		no_of_Guests = option;

		do
		{
			cout << "ENTER MARQUEE PRICE RANGE: ";
			cin >> option;
			if (cin.fail())
			{
				clearInput();
			}
			else if (option > 0)
			{
				break;
			}
		} while (true);
		marqueeRent = option;

		do
		{
			cout << "ENTER YOUR CATERING PRICE RANGE: ";
			cin >> option;
			if (cin.fail())
			{
				clearInput();
			}
			else if (option > 0)
			{
				break;
			}
		} while (true);
		cateringPrice = option;

		do
		{
			cout << "ENTER YOUR PER HEAD PRICE RANGE: ";
			cin >> option;
			if (cin.fail())
			{
				clearInput();
			}
			else if (option > 0)
			{
				break;
			}
		} while (true);
		perHeadPrice = option;

		do
		{
			cout << "DO YOU NEED A FUN LAND FOR KIDS? 1) YES\t2) NO\n";
			cin >> option;
			if (cin.fail())
			{
				clearInput();
			}
			else
			{	
				if (option == 1)
				{
					funLand = true;
					break;
				}
				else if (option == 2)
				{
					funLand = false;
					break;
				}
			}
		} while (true);

		do
		{
			cout << "FOR HOW MANY HOURS YOU WANNA BOOK THE MARQUEE?\n";
			cout << "HOURS : ";
			cin >> objTime.hour;
			cout << "MINUTES : ";
			cin >> objTime.minute;
			if (cin.fail())
			{
				clearInput();
			}
			else if ((objTime.hour > 0) && (objTime.minute > 0))
			{
				break;
			}
		} while (true);

		do
		{
			cout << "DO YOU NEED A PACKAGE? 1) YES\t2) NO\n";
			cin >> option;
			if (option == 1)
			{
				package = true;
				do
				{
					cout << "\nENTER '1' FOR 2 DAY PACKAGE WHICH HOLDS THE DISCOUNT OF 5% ON TOTAL.\n";
					cout << "\nENTER '2' FOR 3 DAY PACKAGE WHICH HOLDS THE DISCOUNT OF 11% ON TOTAL.\n";
					cin >> option;
					if (cin.fail())
					{
						clearInput();
					}
					else if (option == 1)
					{
						packageDiscount = 0.05;
						break;
					}
					else if (option == 2)
					{
						packageDiscount = 0.11;
						break;
					}
					else
					{
						cout << "SELECT THE WRITE INPUT.\n";
						break;
					}
				} while (true);
				break;
			}
			else if (option == 2)
			{
				package = false;
				break;
			}
		} while (true);

		do
		{
			cout << "DO YOU NEED A TRANSPORT SERVICE? 1) YES\t2) NO\n";
			cin >> option;
			if (option == 1)
			{
				transportService = true;
				do
				{
					cout << "ENTER '1' FOR THE BUS SERVICE.\nENTER '2' FOR THE CAR SERVICE.\nENTER '3' FOR BOTH.\n";
					cin >> option;
					if (option == 1)
					{
						do
						{
							cout << "HOW MANY BUSES WOULD YOU LIKE? ";
							cin >> transportQuantityBus;
						} while (transportQuantityBus < 0);
						transportPrice = transportQuantityBus * 2500;
						break;
					}
					else if (option == 2)
					{
						do
						{
							cout << "HOW MANY CARS WOULD YOU LIKE? ";
							cin >> transportQuantityCar;	
						} while (transportQuantityCar < 0);
						transportPrice = transportQuantityCar * 3500;
						break;
					}
					else if (option == 3)
					{
						do
						{
							cout << "HOW MANY BUSES WOULD YOU LIKE? ";
							cin >> transportQuantityBus;
						} while (transportQuantityBus < 0);
						do
						{
							cout << "HOW MANY CARS WOULD YOU LIKE? ";
							cin >> transportQuantityCar;
						} while (transportQuantityCar < 0);
						transportPrice = (transportQuantityBus * 2500) + (transportQuantityCar * 3500);
						break;
					}
				} while (true);
				break;
			}
			else if (option == 2)
			{
				transportService = false;
				break;
			}
		} while (true);

		do
		{
			cout << "DO YOU HAVE A PROMO CODE? 1) YES.\t2) NO.\n";
			cin >> option;
			if (option == 1)
			{
				code = true;
				cout << "ENTER YOUR PROMOCODE : ";
				getline(cin, promoCode);
				getline(cin, promoCode);
				if (promoCode.compare("punjab") == 0)
				{
					promoDiscount = 0.050;
				}
				else if (promoCode.compare("sindh") == 0)
				{
					promoDiscount = 0.045;
				}
				else if (promoCode.compare("balochistan") == 0)
				{
					promoDiscount = 0.037;
				}
				else if (promoCode.compare("kpk") == 0)
				{
					promoDiscount = 0.025;
				}
				else
				{
					cout << "PROMOCODE NOT FOUND.\n";
				}
				break;
			}
			else if (option == 2)
			{
				code = false;
				break;
			}
		} while (true);
	}
	void displayLocations()
	{
		cout << "1)JOHAR TOWN\n2)EDEN GARDEN\n3)BAHRIA TOWN\n4)DHA\n5)DEEN GARDENS\n6)AHMDABAD\n7)GULBERG\n8)MODEL TOWN\n9)MALIR CANTT";
	}
	void displayCuisine()
	{
		cout << "1)PAKISTANI CUISINE\n2)THAI CUISINE\n3)FRENCH CUISINE\n4)CHINESE CUISINE\n5)ITALIAN CUISINE\n6)SPANISH CUISINE\n7)JAPANESE CUISINE\n8)TURKISH CUISINE";
	}
	void setCustomerLocation(int option)
	{
		switch (option) {
			case 1:
				customerLocation = "johar town";
				break;
			case 2:
				customerLocation = "EDEN GARDEN";
				break;
			case 3:
				customerLocation = "BAHRIA TOWN";
				break;
			case 4:
				customerLocation = "DHA";
				break;
			case 5:
				customerLocation = "DEEN GARDENS";
				break;
			case 6:
				customerLocation = "AHMDABAD";
				break;
			case 7:
				customerLocation = "GULBERG";
				break;
			case 8:
				customerLocation = "MODEL TOWN";
				break;
			case 9:
				customerLocation = "MALIR CANTT";
				break;
		}
	}

	friend void optimalMarquee(Marquee* , CustomerForm*);
};

void LoadMarqueeData(Marquee *obj)
{
	ifstream myFile;
	for (int i = 0; i < 4; i++)
	{
		int temp = i + 1;
		string str = "marquee" + to_string(temp);
		str += ".txt";
		myFile.open(str);
		getline(myFile, obj[i].marqueeLocation , '\n');
		myFile >> obj[i].noOfCuisine;
		getline(myFile, str, '\n');
		for (int j = 0; j < obj[i].noOfCuisine; j++)
		{
			getline(myFile, str, '\n');
			obj[i].cuisineName.push_back(str);
		}
		myFile >> obj[i].guestCapacity;
		myFile >> obj[i].marqueeRent;
		myFile >> obj[i].cateringPrice;
		myFile >> obj[i].perHeadPrice;
		myFile >> obj[i].funLand;
		myFile >> obj[i].objT.hour >> obj[i].objT.minute;
		myFile >> obj[i].package;
		myFile >> obj[i].transportService >> obj[i].transportQuantityBus >> obj[i].transportQuantityCar;
		getline(myFile, str, '\n');
		getline(myFile, obj[i].promoCode);
		myFile.close();
	}
}

void displayDataFromFile(Marquee *obj)
{
	for (int i = 0; i < 4; i++)
	{
		cout << obj[i].marqueeLocation << endl;
		cout << obj[i].noOfCuisine << endl;

		for (auto it = obj[i].cuisineName.begin(); it != obj[i].cuisineName.end(); ++it)
			cout << *it << endl;


		cout << obj[i].guestCapacity << endl;
		cout << obj[i].marqueeRent << endl;
		cout << obj[i].cateringPrice << endl;
		cout << obj[i].perHeadPrice << endl;
		cout << obj[i].funLand << endl;
		cout << obj[i].objT.hour << " " << obj[i].objT.minute << endl;
		cout << obj[i].package << endl;
		cout << obj[i].transportService << " " << obj[i].transportQuantityBus << " " << obj[i].transportQuantityCar << endl;
		cout << obj[i].promoCode;
		cout << endl << endl;
	}
}

void optimalMarquee(Marquee *obj1, CustomerForm *obj2)
{
	int maxOptimalPoints = 0, tempOptimalPoints = 0, i = 0, j = 0, *range = new int[6];
	list<int>OptimalMarqueeIndex;


	for (i = 0; i < 6; i++)
		range[i] = INT_MAX;

	for (i = 0; i < 4; i++)
	{
		tempOptimalPoints = 0;
		
		if (obj1[i].marqueeLocation.compare(obj2->customerLocation) == 0)
		{
			tempOptimalPoints++;
		}
		for (auto it = obj2->cuisineIndex.begin(); it != obj2->cuisineIndex.end(); ++it)
		{
			for (auto ip = obj1[i].cuisineName.begin(); ip != obj1[i].cuisineName.end(); ++ip)
			{
				if ((*it).first.compare(*ip) == 0)
				{
					tempOptimalPoints++;
				}
			}
		}
		j = 0;
		if (getRange(obj1[i].guestCapacity, obj2->no_of_Guests) > 0 && getRange(obj1[i].guestCapacity, obj2->no_of_Guests) < range[j])
		{
			range[j] = getRange(obj1[i].guestCapacity, obj2->no_of_Guests);
			tempOptimalPoints++;
			j++;
		}
		if (getRange(obj1[i].marqueeRent, obj2->marqueeRent) > 0 && getRange(obj1[i].marqueeRent, obj2->marqueeRent) < range[j])
		{
			range[j] = getRange(obj1[i].marqueeRent, obj2->marqueeRent);
			tempOptimalPoints++;
			j++;
		}
		if (getRange(obj1[i].cateringPrice, obj2->cateringPrice) > 0 && getRange(obj1[i].cateringPrice, obj2->cateringPrice) < range[j])
		{
			range[j] = getRange(obj1[i].cateringPrice, obj2->cateringPrice);
			tempOptimalPoints++;
			j++;
		}
		if (getRange(obj1[i].perHeadPrice, obj2->perHeadPrice) > 0 && getRange(obj1[i].perHeadPrice, obj2->perHeadPrice) < range[j])
		{
			range[j] = getRange(obj1[i].perHeadPrice, obj2->perHeadPrice);
			tempOptimalPoints++;
			j++;
		}		
		if (obj1[i].funLand == obj2->funLand)
		{
			tempOptimalPoints++;
		}
		if (getRange(obj1[i].objT.hour, obj2->objTime.hour) > 0 && getRange(obj1[i].objT.hour, obj2->objTime.hour) < range[j])
		{
			range[j] = getRange(obj1[i].objT.hour, obj2->objTime.hour);
			tempOptimalPoints++;
			j++;
		}
		if (obj1[i].package == obj2->package)
		{
			tempOptimalPoints++;
		}
		if (obj1[i].transportService == obj2->transportService)
		{
			tempOptimalPoints++;
		}
		if (obj1[i].promoCode.compare(obj2->promoCode) == 0)
		{
			tempOptimalPoints++;
		}
		if (setMaxPoints(tempOptimalPoints, maxOptimalPoints))
		{
			maxOptimalPoints = tempOptimalPoints;
			OptimalMarqueeIndex.push_back(i);
		}
	}

	displayOptimalMarqueeInfo(obj1,OptimalMarqueeIndex);
}

void displayOptimalMarqueeInfo(Marquee *obj,list<int>OptimalMarqueeIndex)
{
	for (auto it = OptimalMarqueeIndex.begin(); it != OptimalMarqueeIndex.end(); ++it)
	{
		cout << obj[*it].marqueeLocation << endl;
		cout << obj[*it].noOfCuisine << endl;

		for (auto ip = obj[*it].cuisineName.begin(); ip != obj[*it].cuisineName.end(); ++ip)
			cout << *ip << endl;


		cout << obj[*it].guestCapacity << endl;
		cout << obj[*it].marqueeRent << endl;
		cout << obj[*it].cateringPrice << endl;
		cout << obj[*it].perHeadPrice << endl;
		cout << obj[*it].funLand << endl;
		cout << obj[*it].objT.hour << " " << obj[*it].objT.minute << endl;
		cout << obj[*it].package << endl;
		cout << obj[*it].transportService << " " << obj[*it].transportQuantityBus << " " << obj[*it].transportQuantityCar << endl;
		cout << obj[*it].promoCode;
		cout << endl << endl;
	}
}

int getRange(int i, int j)
{
	if (i > j)
		return i - j;
}

bool setMaxPoints(int tempOptimalPoints, int maxOptimalPoints)
{
	if (tempOptimalPoints > maxOptimalPoints)
	{
		return true;
	}
	return false;
}
int main()
{
	Marquee *obj = new Marquee[4];
	CustomerForm *obj1 = new CustomerForm;
	LoadMarqueeData(obj);
	obj1->CustomerFormFill();
	optimalMarquee(obj, obj1);
	system("pause>0");
}