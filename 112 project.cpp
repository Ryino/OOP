#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include<vector>

using namespace std;

class Car 
{
protected:

	string name, make, type, drive;
	float milage, top_speed, model, engine_pow;
public:
	//default construtor 
	Car() 
	{
		name = "CAR";
		make = "COMPANY";
		type = "TYPE";
		drive = "FWD/RWD/4WD";
		milage = 0;
		top_speed = 0;
		model = 1;
		engine_pow = 0;
	}
	// assigning values entered by user to protected 
	void set_data(string a, string h, string b, string c, float d, float e, float f, float g) {
		name = a;
		make = h;
		type = b;
		drive = c;
		milage = d;
		top_speed = e;
		model = f;
		engine_pow = g;
	}
	void cal_price(string a, string h, string b, string c, float d, float e, float f, float g)// polymorphism(fucntion overridden furthur in the program 
	{
		cout << "Insufficient data given , price cannot be calculated!";
	}
	

		
	
};


class Buy 
{
private:
	float max_price, min_price;

public:
	fstream myfile;
	Buy() 
	{
		max_price = 0;
		min_price = 0;
	}
	// 2 parameter constructor for user 
	Buy(float x, float y) {
		max_price = x;
		min_price = y;
	}

	void fileRead(string** arr, fstream& myfile)// double pointer is used as it is 2d dynamic array 
		//file is being read and is being stored in an array
	{
		myfile.open("CARS.txt", ios::in);
		while (!myfile.eof())
		{
			for (int k = 0; k < 10; k++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (j < 9)
					{
						//element of array is being selected till the : and being displayed as next element
						getline(myfile, arr[k][j], ':');

					}
					else
						getline(myfile, arr[k][j], '\n');

				}
			}

		}
		myfile.close();
	}

	void options(string** arr, int num[10])
	{

		for (int i = 0; i < 10; i++) {
			if (arr[i][9] == "Available") {
				float price = stof(arr[i][8]);//convert to float as we are reading in string 
				if (price <= max_price && price >= min_price)
				{

					num[i] = i + 1;
					cout << num[i] << "." << endl;
					cout << "NAME: " << arr[i][0] << endl;
					cout << "MAKE: " << arr[i][1] << endl;
					cout << "TYPE: " << arr[i][2] << endl;
					cout << "DRIVE: " << arr[i][3] << endl;
					cout << "MILAGE: " << arr[i][4] << endl;
					cout << "TOP SPEED: " << arr[i][5] << endl;
					cout << "MODEL: " << arr[i][6] << endl;
					cout << "ENGINE POWER: " << arr[i][7] << endl;
					cout << "PRICE: $" << arr[i][8] << endl;
					cout << "STATUS: " << arr[i][9] << endl;

					cout << endl;
				}
			}
		}
		cout << "SELECT THE CAR YOU WANT TO PURCHASE: " << endl;
		int number;
		bool notfound = false;
		while (1)
		{
			cin >> number;
			for (int h = 0; h < 10; h++) {
				if (number == num[h]) {
					notfound = false;
					cout << endl;
					cout << "CONGRATULATIONS YOU HAVE SUCCESSFULLY BOUGHT YHIS CAR: " << endl;
					cout << endl;
					arr[h][9] = "SOLD";
					cout << "NAME: " << arr[h][0] << endl;
					cout << "MAKE: " << arr[h][1] << endl;
					cout << "TYPE: " << arr[h][2] << endl;
					cout << "DRIVE: " << arr[h][3] << endl;
					cout << "MILAGE: " << arr[h][4] << endl;
					cout << "TOP SPEED: " << arr[h][5] << endl;
					cout << "MODEL: " << arr[h][6] << endl;
					cout << "ENGINE POWER: " << arr[h][7] << endl;
					cout << "PRICE: $" << arr[h][8] << endl;
					cout << "STATUS: " << arr[h][9] << endl;
					break;

				}
				else {
					notfound = true;
				}
			}
			if (notfound) {
				cout << "ENTERED THE WRONG NUMBER" << endl;
				continue;
			}
			else {
				myfile.open("CARS.txt", ios::out);
				for (int j = 0; j < 10; j++) {
					myfile << arr[j][0] << ":" << arr[j][1] << ":" << arr[j][2] << ":" << arr[j][3] << ":" << arr[j][4] << ":" << arr[j][5] << ":" << arr[j][6] << ":" << arr[j][7] << ":" << arr[j][8] << ":" << arr[j][9] << endl;
				}
				myfile.close();
				break;

			}
		}
	}
};


class Sell :public Car //inheritance 
{
public:
	float price;
	void cal_price() //overridden function
	{

		float mil_p = 100000 / milage;
		float model_p = model / 100;
		float eng_p = engine_pow * 2;
		float speed_p = top_speed;
		price = mil_p + model_p + eng_p + speed_p;
		cout << "THE CALCLUATED PRICE OF YOUR VEHICLE IS: " << endl;
		cout << price;
		price = price + 1500;
	}

	void sell_vehicle() 
	{
		fstream myfile;


		myfile.open("CARS.txt", ios::app);

		myfile << name << ":" << make << ":" << type << ":" << drive << ":" << milage << ":" << top_speed << ":" << model << ":" << engine_pow << ":" << price << ":" << "Available" << endl;

		myfile.close();
		cout << "CONGRATULATIONS YOUR CAR HAS BEEN SOLD " << endl;
	}

};

void menu() 
{

	cout << "SELECT THE OPTION: " << endl;
	cout << "1. BUY A VEHICLE" << endl;
	cout << "2. SELL A VEHICLE" << endl;


}

class Check
{
protected:
	float age1;
public:
	int age;
	void set_age()
	{
		age1 = age;

	}
	
	friend istream& operator >>(istream& input, Check& obj)
	{
		input >>obj.age;

		return input;
	}

};


int main()
{
	cout << "WELCOME TO RS MOTORS!!!" << endl;
	cout << endl;
	cout << "=======================" << endl;
	cout << endl;
	fstream myfile;

	cout << "Enter your name:" << endl;
	string name;
	cin >> name;
	//exception handling for user name 
	try
	{
		throw name;
	}
	catch (string name)
	{
		cout << "Welcome " << name<<"!\n";
	}

	cout << "Enter your Age:";
	Check c;
	
	cin >> c.age;//operator overloading 

	

	if (c.age>=18)
	{ 
		cout << "Enter your  5 digit CNIC number digit by digit:";
		vector<int> id;
		int i[5];
		for (int j = 0; j < 5; j++)
		{
			cin >> i[j];
			id.push_back(i[j]);
		}
		cout << "Your CNIC number is:";
		cout << i[0];
		for (int j = 1; j < 4; j++)
		{
			cout<<"*";
			
		}
		cout << i[4];

		cout << "\nTHE TOTAL NUMBER OF CARS IN THIS SHOWROOM ARE: " << endl;
		myfile.open("CARS.txt", ios::in);
		string s;
		int x = -1;
		while (!myfile.eof()) {
			x++;
			getline(myfile, s);
		}
		cout << x;
		myfile.close();
		cout << endl;

		menu();

		int a;
		cin >> a;
		while (1)
		{
			if (a == 1 || a == 2)
			{
				break;
			}
			else {
				cout << "WORNG INPUT...ENTER AGAIN" << endl;
				cin >> a;
			}
		}

		float c, d;
		string** arr = new string * [x];
		for (int i = 0; i < x; i++) {
			arr[i] = new string[10];
		}

		int num[10] = { 0 };

		if (a == 1) {

			cout << "ENTER YOUR MAXIMUM BUDGET: ";
			cin >> c;
			cout << "ENTER YOUR MINIMUM BUDGET: ";
			cin >> d;
			Buy b1(c, d);
			b1.fileRead(arr, myfile);
			cout << "YOUR OPTIONS ARE: " << endl;
			cout << endl;
			b1.options(arr, num);
		}
		else if (a == 2) {

			Sell s1;

			string i, j, k, l;
			float m, n, o, p;
			cout << "PLEASE ENTER THE DETAILS OF YOU VEHICLE: " << endl;
			cout << "ENTER NAME OF THE VEHICLE: ";
			cin >> i;
			cout << "ENTER THE MAKE OF THE VEHICLE: ";
			cin >> j;
			cout << "ENTER THE TYPE OF THE VEHICLE ( Sedan , Hatchback , Sports ): ";
			cin >> k;
			cout << "ENTER THE DRIVE TYPE OF THE VEHICLE ( FWD , RWD , AWD , 4WD ): ";
			cin >> l;
			cout << "ENTER THE MILAGE OF THE VEHICLE: ";
			cin >> m;
			cout << "ENTER THE TOP SPEED OF THE VEHICLE: ";
			cin >> n;
			cout << "ENTER THE MODEL OF THE VEHICLE: ";
			cin >> o;
			cout << "ENTER THE ENGINE POWER OF THE VEHICLE: ";
			cin >> p;
			s1.set_data(i, j, k, l, m, n, o, p);


			s1.cal_price();
			int x;
			cout << endl;
			cout << "CONFIRM IF YOU WANT TO SELL YOUR VEHICLE (1/2) : " << endl;
			cout << "1. SELL" << endl;
			cout << "2. DO NOT SELL" << endl;
			cin >> x;
			while (1)
			{
				if (x == 1 || x == 2)
				{
					break;
				}
				else {
					cout << "WORNG INPUT...ENTER AGAIN" << endl;
					cin >> x;
				}
			}

			switch (x)
			{
			case 1:

				s1.sell_vehicle();
				break;

			case 2:
				cout << "THANK FOR THE PATIENCE " << name << "!!!";
				break;

			}

		}
	}
	else
	{
		cout << "Please get a guardian over 18 years of age!";

	}
}