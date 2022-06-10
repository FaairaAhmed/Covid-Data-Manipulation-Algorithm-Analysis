#include "solution.h"
int main()
{ 
	
	MY_Linked_List Co_vid;
	READ_FROM_WHO(Co_vid);
	int choice=0;
	cout<<"\033[1m\033[31m"<<"-----------------------------------------Welcome to COVID-19 pandemic Information Portal--------------------------------------"<<endl;
	cout<<"-----------------------------------------Select from the Six option regarding your query--------------------------------------"<<endl;
	cout<<"\033[1m\033[34m"<<"Press 1 to Find the top 20 countries with the most confirmed cases on a given day."<<endl;
	cout<<"\033[1m\033[33m"<<"Press 2 to Find the country(s) with the highest new cases between two given dates."<<endl;
	cout<<"\033[1m\033[36m"<<"Press 3 to Find the starting and ending days of the longest spread period for a given country."<<endl;
	cout<<"\033[1m\033[37m"<<"Press 4 to Find the longest daily_count death toll decrease period for a given country."<<endl;
	cout<<"\033[1m\033[32m"<<"Press 5 to Find the countries eligible for aid given a budget of 300"<<endl;
	cout<<"\033[1m\033[35m"<<"Press 6 to Find the similarity between two countries given a threshold k"<<endl;
	cin>>choice;
	while(choice != 0){
		if(choice == 1){
			string d;
			cout<<"\033[34m"<<"To find the top 20 countries with the most confirmed cases"<<endl;
			cout<<"Kindly input the date in the format YYYY/M/D"<<endl;
			cin>>d;
			Co_vid.Solution_of_part_A(d);
		}
		else if(choice == 2){
			string date_one,date_two;
			cout<<"\033[33m"<<"To find the top 20 countries with the most confirmed cases on a given day"<<endl;
			cout<<"Please enter the two dates"<<endl;
			cout<<"Enter first date : ";
			cin>>date_one;
			cout<<"Enter second date : ";
			cin>>date_two;
			Co_vid.Solution_of_part_B(date_one,date_two);
		}
		else if(choice == 3){
			char country[30];
			cout<<"\033[36m"<<"To find the starting and ending days of the longest spread period for a given country"<<endl;
			cout<<"Please enter the name of the country. Kindly make sure you enter the correct spellings"<<endl;
			scanf(" %[^\n]s",country);
			Co_vid.Solution_of_part_C(string(country));
		}
		else if(choice == 4){
			char country[30];
			cout<<"\033[37m"<<"To find the longest daily_count death toll decrease period for a given country"<<endl;
			cout<<"Please enter the name of the country. Kindly make sure you enter the correct spellings"<<endl;
			scanf(" %[^\n]s",country);
			Co_vid.Solution_of_part_D(string(country));
		}
		else if(choice == 5){
			int k_value;
			int temp;
			cout<<"\033[32m"<<"If you want to specify the aid budget kindly press 1 otherwise 300 will be saved as your choice"<<endl;
			cin>>temp;
			if(temp == 1){
				cout<<"Enter the amount of budget : ";
				cin>>k_value;
				Co_vid.Solution_of_part_E(k_value);
			}
			else Co_vid.Solution_of_part_E(300);
		}
		else if (choice == 6){
			char country_name_one[30],country_name_two[30];
			int k_value;
			int temp;
			cout<<"\033[35m"<<"To find the similarity between two countries for given a threshold"<<endl;
			cout<<"Enter the name of the first country. Kindly make sure you enter the correct spellings"<<endl;
			scanf(" %[^\n]s",country_name_one);
			cout<<"Enter the name of the second country. Kindly make sure you enter the correct spellings"<<endl;
			scanf(" %[^\n]s",country_name_two);
			cout<<"If you want to specify the threshold value kindly press 1 otherwise 10 will be saved as your choice"<<endl;
			cin>>temp;
			if(temp == 1){
				cout<<"Enter the amount of budget : ";
				cin>>k_value;
				Co_vid.Solution_of_part_F(string(country_name_one),string(country_name_two),k_value);
			}
			else 
				Co_vid.Solution_of_part_F(string(country_name_one),string(country_name_two),10);	
		}
		cout<<"\033[31m";
		cout<<"Enter the choice number you want to proceed to next otherwise press 0 to exit"<<endl;
		cin>>choice;	
	}	
	
} 
