#include <iostream>
#include <stdlib.h>
#include<string>
using namespace std;
void MENU();
void seller();
void buyer();
void reportforsolditems();
int feedback(int);
void Header();
int number_of_items;
int i;

struct startingdate
{
	int day;
	int month;
}date;

struct items
{
	string category;
	long starting_big_price;
	string status = "available";
	startingdate starting_date;
}item[100];
int x = 0, z = 0;

struct entering
{
	string username;
	string password;
	long long id;
	int points = 0;
}user[100];

struct buying
{
	string username;
	string password;
	long long id;
	int points = 0;
}member[100];





int main()
{

	MENU();
	system("cls");

}

void MENU()
{
	while (true)
	{

		Header();

		cout << "1.Sell items\n";
		cout << "2.Buy items\n";
		cout << "3.Report for items\n";
		cout << "4.Feedback\n";
		cout << "5.Login with another account\n";
		cout << "6.Exit\n";
		cout << "Choose number:";
		int seller_or_Buyer;
		cin >> seller_or_Buyer;
		system("cls");
		if (seller_or_Buyer == 1)
		{
			cout << "\t\t\t WELCOME!! \n\n";
			cout << "Enter username please :";
			cin.ignore();
			getline(cin, user[x].username);
			cout << "Enter password please :";
			cin >> user[x].password;
			cout << "Enter Id :";
			cin >> user[x].id;

			system("cls");
			seller();

		}

		else if (seller_or_Buyer == 2)
		{

			cout << "\t\t\t WELCOME!! \n\n";
			cout << "Enter username please :";
			cin.ignore();
			getline(cin, member[z].username);
			cout << "Enter password please :";
			cin >> member[z].password;
			cout << "Enter Id :";
			cin >> member[z].id;
			system("cls");
			buyer();

		}

		else if (seller_or_Buyer == 3)
		{
			reportforsolditems();
			system("pause");
			system("cls");
		}
		else if (seller_or_Buyer == 4)
		{

			int rating;
			string comment;
			cout << "1.Rating\n";
			cout << "2.comment\n";
			cout << "Choose :";
			int RatingorComment;
			cin >> RatingorComment;
			if (RatingorComment == 1)
			{
				cout << "Enter rating please (From 1 to 5):";
				cin >> rating;
				feedback(rating);

			}
			else if (RatingorComment == 2)
			{
				cin.ignore();
				cout << "Enter your comment please :";
				getline(cin, comment);
				cout << "Thanks for your comment\n";
				system("pause");
				system("cls");
				MENU();

			}




		}
		else if (seller_or_Buyer == 5)
		{

			cout << "Do you want to login again !!\n";
			cout << "1.Seller\n";
			cout << "2.Buyer\n";
			cout << "3.exit\n";
			cout << "Choose number:";
			int loginorexit;
			cin >> loginorexit;;
			system("cls");
			if (loginorexit == 1)
			{

				x++;
				cout << "\t\t\t WELCOME!! \n\n";
				cout << "Enter username please :";
				cin.ignore();
				getline(cin, user[x].username);
				cout << "Enter password please :";
				cin >> user[x].password;
				cout << "Enter Id :";
				cin >> user[x].id;

				system("cls");
				seller();
			}
			else if (loginorexit == 2)
			{
				z++;
				cout << "\t\t\t WELCOME!! \n\n";
				cout << "Enter username please :";
				cin.ignore();
				getline(cin, member[z].username);
				cout << "Enter password please :";
				cin >> member[z].password;
				cout << "Enter Id :";
				cin >> member[z].id;
				system("cls");
				buyer();
			}
			else if (loginorexit == 3)
			{
				exit(0);
				break;
			}

		}


		else if (seller_or_Buyer == 6)
		{
			exit(0);
		}




	}

}

void seller()
{
	//function for sell items
	Header();

	int n = 0;
	cout << "How many items do you want to sell\n";
	cout << "Enter number:";
	cin >> number_of_items;

	for (; n < number_of_items; i++)
	{
		n++;

		cout << "Item " << n << "\n";
		cout << "Enter category name of item :";
		cin >> item[i].category;
		cout << "Enter starting price :";
		cin >> item[i].starting_big_price;


		while (true)
		{
			cout << "Starting day :";
			cin >> item[i].starting_date.day;
			cout << "starting month :";
			cin >> item[i].starting_date.month;
			if ((item[i].starting_date.day > 0 && item[i].starting_date.day < 31) && (item[i].starting_date.month == 4 || item[i].starting_date.month == 6 || item[i].starting_date.month == 9 || item[i].starting_date.month == 11))
			{

				cout << "Valid\n";
				break;
			}

			else if ((item[i].starting_date.day > 0 && item[i].starting_date.day < 32) && (item[i].starting_date.month == 1 || item[i].starting_date.month == 3 || item[i].starting_date.month == 5 || item[i].starting_date.month == 7 || item[i].starting_date.month == 8 || item[i].starting_date.month == 10 || item[i].starting_date.month == 12))
			{

				cout << "Valid\n";
				break;
			}
			else if ((item[i].starting_date.day > 0 && item[i].starting_date.day < 29) && item[i].starting_date.month == 2)
			{
				cout << "Valid\n";
				break;
			}
			else
			{
				cout << "Invalid\n";


			}
		}




		cout << "\n";

	}
	system("cls");

	cout << "Do you want back to menu\n";
	cout << "1.Menu\n";                            //if you want to get back to menu or not
	cout << "2.Exit\n";
	cout << "Choose number:";
	int back_to_menu;
	cin >> back_to_menu;
	system("cls");
	if (back_to_menu == 1) {
		MENU();
		system("cls");

	}
	else {
		exit(0);
	}




}

int j = 0;
int new_status;

void buyer() {
	bool flag = false;
	string categoryx;

	Header();                                        //function for buy items

	cout << "1.All items avaliable\n";
	cout << "2.Search for individual item\n";
	cout << "3.Back to menu\n";
	cout << "Choose:";
	int all_or_search;
	cin >> all_or_search;
	system("cls");
	j = 0;
	if (all_or_search == 1)
	{
		//print all items 
		for (; j < i; j++)
		{
			cout << "Number of item :" << j + 1 << "\n";
			cout << "Category :";
			cout << item[j].category;
			cout << "\n";
			cout << "Price :";
			cout << item[j].starting_big_price;
			cout << "\n";
			cout << "Status :";
			cout << item[j].status;
			cout << "\n";
			cout << "Starting day :";
			cout << item[j].starting_date.day;
			cout << "\n";
			cout << "starting month :";
			cout << item[j].starting_date.month;
			cout << "\n";
			cout << "Valid for 3 days";
			cout << "\n\n";
		}
		system("pause");

		cout << "Do you want to buy one of this item\n";
		cout << "1.Yes\n";
		cout << "2.No\n";
		int Buy_or_not;

		cin >> Buy_or_not;
		if (Buy_or_not == 1)
		{
			cout << "Enter number of item:";
			cin >> new_status;
			j = new_status - 1;

			if (item[j].status == "sold") {
				cout << "can't buy it\n";
				system("pause");
				system("cls");
				MENU();
			}
			else {
				cout << "Enter suggested price:";
				int* ptr = new int;
				cin >> *ptr;
				if (*ptr >= item[j].starting_big_price)
				{
					cout << "Approve\n";
					system("pause");
					j = new_status - 1;
					item[j].status = "sold";
					system("cls");

				}
				else
				{
					cout << "Rejected\n";
					item[j].status = "available";
					system("pause");
					system("cls");
					MENU();
					system("cls");

				}

			}
		}
		else if (Buy_or_not == 2)
		{
			system("cls");
			MENU();
		}



	}

	else if (all_or_search == 2)
	{
		cout << "choose\n";                          /* if you want to search about items by category
													 or both category and price */
		cout << "1.search by category\n";
		cout << "2.search by both category and price\n";
		int categoryonlyorbothcategoryandprice;
		cin >> categoryonlyorbothcategoryandprice;


		if (categoryonlyorbothcategoryandprice == 1)
		{

			cout << "enter category :";
			cin >> categoryx;
			for (j; j < i; j++)
			{

				if (categoryx == item[j].category)
				{
					flag = true;
					cout << "Number of item :" << j + 1 << "\n";
					cout << "Category :";
					cout << item[j].category;
					cout << "\n";
					cout << "Price :";
					cout << item[j].starting_big_price;
					cout << "\n";
					cout << "Status :";
					cout << item[j].status;
					cout << "\n";
					cout << "Starting day :";
					cout << item[j].starting_date.day;
					cout << "\n";
					cout << "starting month :";
					cout << item[j].starting_date.month;
					cout << "\n";
					cout << "Valid for 3 days";
					cout << "\n\n";

				}



			}
			if (flag)
			{
				system("pause");
			}
			else
			{
				cout << "Unavaliable\n";
				system("cls");
				MENU();
			}
		}
		else if (categoryonlyorbothcategoryandprice == 2)
		{
			bool flag2 = false;
			int* ptr2 = new int;
			cout << "enter category:";
			cin >> categoryx;
			cout << "enter price:";
			cin >> *ptr2;
			/*if price more than or equal to original price
			 will print the item */
			for (j; j < i; j++)
			{
				if (*ptr2 >= item[j].starting_big_price)
				{
					if (categoryx == item[j].category)
					{
						flag = true;

						flag2 = true;
						cout << "Number of item :" << j + 1 << "\n";
						cout << "Category :";
						cout << item[j].category;
						cout << "\n";
						cout << "Price :";
						cout << item[j].starting_big_price;
						cout << "\n";
						cout << "Status :";
						cout << item[j].status;
						cout << "\n";
						cout << "Starting day :";
						cout << item[j].starting_date.day;
						cout << "\n";
						cout << "starting month :";
						cout << item[j].starting_date.month;
						cout << "\n";
						cout << "Valid for 3 days";
						cout << "\n\n";
					}

				}
			}

			if (flag2 && flag)
			{
				system("pause");
			}
			else
			{
				cout << "Unavaliable\n";
				system("cls");
				MENU();
			}
		}

		cout << "Do you want to buy this item\n";
		cout << "1.Yes\n";
		cout << "2.No\n";
		int Buy_or_not;
		cin >> Buy_or_not;

		if (Buy_or_not == 1)
		{
			cout << "Enter number of item:";
			cin >> new_status;
			j = new_status - 1;
			if (item[j].status == "sold")
			{
				cout << "can't buy it\n";
				system("pause");
				system("cls");
				MENU();
			}


			else
			{
				cout << "Enter suggested price:";
				int* ptr = new int;
				cin >> *ptr;
				if (*ptr >= item[j].starting_big_price)
				{
					cout << "Approve\n";
					system("pause");
					j = new_status - 1;
					item[j].status = "sold";
					system("cls");


				}
				else {
					cout << "Rejected\n";
					item[j].status = "available";
					system("pause");
					system("cls");
					MENU();
					system("cls");

				}

			}

		}
		else
		{
			system("cls");
			MENU();

		}

	}
	else if (all_or_search == 3)
	{

		MENU();
	}

	cout << "Do you want back to menu\n";
	cout << "1.Menu\n";
	cout << "2.Exit\n";
	cout << "Choose number:";
	int  backtomenuorexit;
	cin >> backtomenuorexit;
	if (backtomenuorexit == 1)
	{
		system("cls");
		MENU();

	}
	else
	{
		exit(0);
	}



	system("cls");

}



void reportforsolditems()
{                                            //function for sold items




	for (j = 0; j < i; j++)
	{
		if (item[j].status == "sold")
		{

			cout << "Number of item :" << j + 1 << "\n";
			cout << "Category :";
			cout << item[j].category << "\n";
			cout << "Price :";
			cout << item[j].starting_big_price << "\n";
			cout << "Status :";
			cout << item[j].status;
			cout << "\n";
			cout << "Starting day :";
			cout << item[j].starting_date.day;
			cout << "\n";
			cout << "starting month :";
			cout << item[j].starting_date.month;
			cout << "\n\n";

		}
	}




}


int feedback(int ratingx)
{                                                  //function for feedback from user


	if (ratingx == 3 || ratingx == 4 || ratingx == 5)
	{

		user[x].points++;

		cout << "User points increased\n";

		cout << "thanks for rating\n";
		system("pause");
		system("cls");
		MENU();


	}
	else if (ratingx == 2 || ratingx == 1)
	{
		cout << "thanks for rating\n";
		system("pause");
		system("cls");
		MENU();

	}
	else
	{
		cout << "enter rating from 1 to 5\n";
		system("pause");
		system("cls");
		MENU();
	}



	return ratingx;
}

void Header()
{

	cout << "\t\t\t Auction online system \n";
	cout << "\t\t ***********************************\n\n";

}