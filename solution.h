#include<string.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include<iterator>
#include<algorithm>
#include<string>
#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
struct Myclass
{
public:
	int Myclass_year, Myclass_month, Myclass_date;
	string country, countryname, region;
	int death, c_death, daily_count_confirmed, cum_comfirmed;
	int weight;
	Myclass* next; 
	int active_cases;
	int total;
	Myclass()
	{
		Myclass_year = Myclass_month = Myclass_date = death = c_death = daily_count_confirmed = cum_comfirmed =weight = total = active_cases = 0;
		next = NULL;
	}
    void set(int y, int m, int d, string country, string reg, int no_of_deaths, int cummulative_deaths, int da_c, int cum)
	{
        Myclass_year = y, Myclass_month = m, Myclass_date = d, region = reg, death = no_of_deaths, c_death = cummulative_deaths, 
        da_c =daily_count_confirmed, cum_comfirmed = cum_comfirmed; 
        this->country = country;
	}
	void operator = (const Myclass &D )
	{
		total = D.total;
		Myclass_year = D.Myclass_year;
		Myclass_month = D.Myclass_month;
		Myclass_date = D.Myclass_date;
		country = D.country;
		countryname = D.countryname;
		region = D.region;
		weight = D.weight;
		death = D.death;
		c_death= D.c_death;
		daily_count_confirmed = D.daily_count_confirmed;
		cum_comfirmed = D.cum_comfirmed;
		next = D.next;
		active_cases = D.active_cases;
	}
	string return_date_string()
	{
		string year, month, day, result;

		year =  to_string(Myclass_year);
		month = to_string(Myclass_month);
		day = to_string(Myclass_date);
		result = year + "/" + month + "/" + day;
		return result;
	}
	Myclass& return_node_details()
	{
		return *this;
	}
	
};
void swap(Myclass* a, Myclass* b)
{
	Myclass t = *a;
	*a = *b;
	*b = t;
}
class struct_one//used in part B
{
	public:
	string name_of_country;
	int max_no_death;
	int max_cum_cases;
	int MY_Linked_List_cases_all;

	struct_one()
	{
		MY_Linked_List_cases_all = 99999999;
		max_no_death = -1;
		max_cum_cases = -1;
	}
	void set_name(string s)
	{
		name_of_country = s;
	}
	void set_all_cases(int i)
	{
		MY_Linked_List_cases_all = i;
	}
	int max(int a, int b)
	{
		if(a>b)
			return a;
		return b;
	}
	void set_val(int death, int cases)
	{
		max_no_death = max(max_no_death, death);
		max_cum_cases = max(max_cum_cases, cases);
	}
	
};	
void swap(struct_one* a, struct_one* b)
{
	struct_one T=*a;
	*a = *b;
	*b = T;
}
struct struct_three
{
	string starting_date;
	string ending_date;
	int item_value;
	int item_counter;
	int max_val;
	struct_three()
	{
		max_val = 9999999;
	}

};
struct struct_five
{
	int item_value;
	string Myclass_date;
};
struct struct_four
{
	int item_value;
	struct_five* struct_seven;
};
struct struct_six
{
    string name_of_country;
    int item_value;
    int item_amount;
    public:
    	struct_six()
    	{
        	item_value = item_amount = 9999999;

    	}
		bool operator < (const struct_six &D )
		{
			if(item_value < D.item_value)
				return true;
			return false;
		}
    
};
void swap(struct_six* a, struct_six* b)
{
	struct_six T=*a;
	*a = *b;
	*b = T;
}
struct struct_seven
{
	string name_of_country;
	int item_value;
};
void swap(struct_seven* a, struct_seven* b)
{
	struct_seven T=*a;
	*a = *b;
	*b = T;
}
//***********************************************SOME UTILITY FUNCTIONS***************************************************

//******************************MAXIMUM VALUE FUNCTION********************
int find_maximum_from_int_array(int *arr , int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i];
      return max;     
}
int find_maximum_value(int func_array[], int n) 
{ 
    int result = find_maximum_from_int_array(func_array,n);
    return result; 
} 
//**************************COUNTING SORT FUNCTION************************
void sort_by_count_func1(int count[], int func_array[], int n, int exp)
{
	for (int i = 0; i < n; i++) 
        count[ (func_array[i]/exp)%10 ]++;
}
void sort_by_count_func2(int count[])
{
	for (int i = 1; i < 10; i++) 
        count[i] += count[i - 1];
}
void sort_by_count_func3(int output[],int count[],int func_array[],int exp, int n)
{
	for (int i = n - 1; i >= 0; i--) 
    	{ 
      	output[count[ (func_array[i]/exp)%10 ] - 1] = func_array[i]; 
        	count[ (func_array[i]/exp)%10 ]--; 
    	} 
}
void sort_by_count_func4(int func_array[], int output[], int n)
{
	for (int i = 0; i < n; i++) 
		func_array[i] = output[i]; 
}
void sort_by_count(int func_array[], int n, int exp) 
{ 
    int output[n]; 
    int i, count[10] = {0}; 
	sort_by_count_func1(count,func_array, n, exp);
	sort_by_count_func2(count);
	sort_by_count_func3(output,count,func_array,exp,n);
	sort_by_count_func4(func_array,output,n);
} 
//********************************RADIX SORT FUNCTION********************* 
void sort_by_radix(int func_array[], int n) 
{ 
    int m = find_maximum_value(func_array, n); 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        sort_by_count(func_array, n, exp); 
} 
//**********************DATE FUNCTIONS******************
int get_year_from_string(string str)
	{
		string y = str.substr(7, 4); 
		return stoi(y);
		
	}
int get_month_from_string(string str)
	{
		string m = str.substr(3, 3); 
		return stoi(m);
		
	}
int get_day_from_string(string str)
	{
		string d = str.substr(0, 2); 
		return stoi(d);
	}
int convert_year(int Myclass_year)
{
	int perform = Myclass_year*365;
	return perform;
}
long day30_month(int Myclass_month){return (long)Myclass_month *30;}
long day31_month(int Myclass_month){return (long)Myclass_month*31;}
long day29_month(int Myclass_month){return (long)Myclass_month *29;}
long convert_month(int Myclass_month)
{
	if(Myclass_month == 10 ||Myclass_month == 4 ||Myclass_month == 6 ||Myclass_month == 11)
		return day30_month(Myclass_month);
	else if (Myclass_month == 2)
		return day29_month(Myclass_month);
	else 
		return day31_month(Myclass_month);

}
int subtract_conversion(string s1)
{return convert_year(get_year_from_string(s1)) + convert_month(get_month_from_string(s1))+ get_day_from_string(s1); }
int substract(string date_one, string date_two)
{
	if(date_one == date_two)
		return 0;
	return ( subtract_conversion(date_one) - subtract_conversion(date_two));	
}
//******************************USER DEFINED LINKED LIST***********************
class MY_Linked_List
{
private:
	Myclass** ptr_array;
	int item_counter;
	int item;
	struct_one* struct_one_array_ptr;
	struct_three* struct_three_array_ptr;
	int temp_value;
public:
//*************************CONSTRUCTOR****************************
	MY_Linked_List()
	{
		struct_one_array_ptr = new struct_one[213];
		item = 0;
		temp_value = 0;
		item_counter = 0;
		ptr_array = new Myclass* [213];
		struct_three_array_ptr = new struct_three[97];
		
	}
//*************************USEFUL CLASS MEMBER FUNCTIONS********************
	int search_by_binary_con(int lower_bound, int upper_bound, string country_name)
	{ 
		if (upper_bound >= lower_bound) 
		{ 
			int mid = lower_bound + (upper_bound - lower_bound)/2; 
			if (ptr_array[mid]->countryname == country_name) 
				return mid; 
			if (ptr_array[mid]->countryname > country_name) 
				return search_by_binary_con(lower_bound, mid-1, country_name); 
			return search_by_binary_con(mid+1, upper_bound, country_name); 
		} 
		return -1; 
	} 
	int exponential_search(string country_name)  
	{ 
		if (ptr_array[0]->countryname == country_name) 
			return 0; 
		int i = 1; 
		while (i < 212 && ptr_array[i]->countryname <= country_name) 
			i = i*2; 
		return search_by_binary_con( i/2, min(i, 212), country_name); 
	} 
	int g_C_date_I(string c, string Myclass_date)
	{
		int i = exponential_search(c); 
		Myclass* temp = ptr_array[i];
		int j = 0;
		while(temp)
		{
			if(temp->return_date_string() == Myclass_date)
			{
				return j;
			}
			j++;
			temp = temp->next;
		}
		return -1;

	}
	Myclass* get_city_on_Index(string c, int &val)
	{
		val = exponential_search(c);
		if(val == -1)
		{
			return NULL;
		}
		else return ptr_array[val];
	}
	Myclass* get_node_city_date(string c, string Myclass_date)
	{
		int count;
		Myclass* temp =get_city_on_Index(c, count);
        while(temp)
		{
			if(temp->return_date_string() == Myclass_date)
			{
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
	struct_one* get_node_with_most_val(string s)
	{
		
		int i = 0;
		while(struct_one_array_ptr[i].name_of_country!=s)
		{
			i++;
		}
		return &struct_one_array_ptr[i];

	}
	int binary_search_for_max_index(struct_five func_array[], vector<int>& T, int l, int r,  int key) 
	{ 
		while (r - l > 1) { 
			int m = l + (r - l) / 2; 
			if (func_array[T[m]].item_value >= key) 
				r = m; 
			else
				l = m; 
		} 
	
		return r; 
	} 
	void get_values_with_a_start_end(string start_date, string end_date, string country_name)
	{
		int val=0;
		int i =0;
		Myclass *temp = get_node_city_date(country_name, start_date);
		if(temp == NULL)
		{
			get_node_with_most_val(country_name)->set_all_cases(val);
		}
		else
		{
			while(temp->return_date_string()!=end_date)
			{
				val+=temp->daily_count_confirmed;
				temp = temp->next;
				i++;
			}
			val+=temp->daily_count_confirmed;
			get_node_with_most_val(country_name)->set_all_cases(val);
		}
	}
	struct_four& get_city_for_struct_four(Myclass *temp, char which)
	{
		
		struct_four* struct_temp_var = new struct_four;
		int i= 0;
		if(which == 'd')
		{
			struct_temp_var->struct_seven = new struct_five[temp->total];
			while(temp)
			{
				struct_temp_var->struct_seven[i].item_value = temp->death;
				struct_temp_var->struct_seven[i].Myclass_date = temp->return_date_string();
				temp = temp->next;
				i++;
			}
			struct_temp_var->item_value = i;
			return *struct_temp_var;	
		}
		else if(which == 'f' || which == 'c')
		{
			struct_temp_var->struct_seven = new struct_five[temp->total];
			while(temp)
			{
				struct_temp_var->struct_seven[i].item_value = temp->daily_count_confirmed;
				struct_temp_var->struct_seven[i].Myclass_date = temp->return_date_string();
				temp = temp->next;
				i++;
			}
			struct_temp_var->item_value = i;
			return *struct_temp_var;
		}
	}
//*********************************DATA INSERTION***************************************	
	void data_insertion(Myclass &obj, string &val1, string &val2)
	{
		if(ptr_array[0]== NULL)
		{
			ptr_array[item_counter] = new Myclass;
			ptr_array[item_counter]->return_node_details() = obj;
			ptr_array[item_counter]->return_node_details().next = NULL;
			ptr_array[item_counter]->return_node_details().total+=1;
		}
		else if(val1==val2)
		{
			Myclass* temp = ptr_array[item_counter];
			while(temp->next!=NULL)temp = temp->next;
			temp->next = new Myclass;
			temp->next->return_node_details() = obj;
			temp->next->next = NULL;
			temp = temp->next;
			ptr_array[item_counter]->return_node_details().total+=1;
		}
		else if(val1!=val2)
		{
			item_counter++;
			ptr_array[item_counter] = new Myclass;
			Myclass* temp = ptr_array[item_counter];
			temp->return_node_details() = obj;
			temp->next = NULL;
			temp = temp->next;
			val1 = val2;
			ptr_array[item_counter]->return_node_details().total+=1;
		}
		struct_one_array_ptr[item_counter].set_name(obj.countryname);
		struct_one_array_ptr[item_counter].set_val(obj.c_death, obj.cum_comfirmed);
		item++;
	}
	Myclass* get_link_iserik(int val)
	{
		return ptr_array[val];
	}
	Myclass* get_node_if_given_country(string c)
	{
		for (int i = 0 ; i<213; i++)
		{
			if(ptr_array[i]->return_node_details().countryname == c)
			{
				return &ptr_array[i]->return_node_details();
			}
		}
		return NULL;
	}
//********************************************************FUNCTIONS FOR PART A*********************************************************	
	int partition_a(struct_seven func_array[], int low, int high)  
	{
			
			int point = func_array[high].item_value;
			int i = (low - 1); 
		
			for (int j = low; j <= high - 1; j++)  
			{  
				if (func_array[j].item_value < point)  
				{  
					i++; 
					swap(&func_array[i], &func_array[j]);  
				}  
			}  
			swap(&func_array[i + 1], &func_array[high]);  
			return (i + 1);   
		
	}  
	void quickSort_a(struct_seven arr[], int min, int max)   
	{  
		if (min < max)  
		{
			int pi = partition_a(arr, min, max);  
			quickSort_a(arr, min, pi - 1);  
			quickSort_a(arr, pi + 1, max);  
		}  
	}  
	void Solution_of_part_A(string Myclass_date)
	{
		struct_seven array[213];
		int temp_val = 0;
		Myclass* temp;
		for( ; temp_val<213 ; temp_val++)
		{
			temp = get_node_city_date(ptr_array[temp_val]->countryname, Myclass_date);
			if(!temp)
			{
				array[temp_val].item_value = -1;
			}
			else
			{
				array[temp_val].item_value = temp->daily_count_confirmed;
			}
			array[temp_val].name_of_country = ptr_array[temp_val]->countryname;
		}
		quickSort_a(array,0, 212);
		cout<<"\033[33m"<<"The list of top 20 countries with the most confirmed cases on a given day is : "<<endl;
		for(int x=212 ; x>=213-20 ; x--)
			cout<<"Country : "<<array[x].name_of_country<<"  --- Cases = "<<array[x].item_value<<endl;
		
	}
//********************************************************FUNCTIONS FOR PART B****************************************************		
	int partition_b(struct_one array_ptr[], int min, int max)  
	{  
			int point = array_ptr[max].MY_Linked_List_cases_all;
			int i = (min - 1); 
		
			for (int j = min; j <= max - 1; j++)  
			{  
				if (array_ptr[j].MY_Linked_List_cases_all < point)  
				{  
					i++; 
					swap(&array_ptr[i], &array_ptr[j]);  
				}  
			}  
			swap(&array_ptr[i + 1], &array_ptr[max]);  
			return (i + 1);  
		
	}  
	void quickSort_b(struct_one arr[], int min, int max)   
	{  
		if (min < max)  
		{
			int pi = partition_b(arr, min, max);  
			quickSort_b(arr, min, pi - 1);  
			quickSort_b(arr, pi + 1, max);  
		}  
	} 
	void Solution_of_part_B(string d_starting, string d_ending)
	{
		int i = 0;
		while(i< 213)
		{
			get_values_with_a_start_end(d_starting,d_ending,ptr_array[i]->return_node_details().countryname);
			i++;
		}
		quickSort_b(struct_one_array_ptr,0, 212);
	
		int return_value = struct_one_array_ptr[213-1].MY_Linked_List_cases_all;
		int val = 213-1;
		cout<<"\033[36m"<<"Country : ";
		while(return_value==struct_one_array_ptr[val].MY_Linked_List_cases_all)
		{
			cout<<struct_one_array_ptr[val].name_of_country<<endl;
			cout<<"Cases = "<<struct_one_array_ptr[val].MY_Linked_List_cases_all<<endl;
			val--;
		}
		
	}
//********************************************************FUNCTIONS FOR PART C********************************************************	
	void perform(Myclass* temp)
	{
		struct_four mn = get_city_for_struct_four(temp, 'c');
		int size = mn.item_value;
		//initialize with 0
		vector<int> current_index(size, 0); 
		//initialize with -1
		vector<int> previous_index(size, -1);
		int length_of_days = 1, counter = 1; 
		for  (counter = 1; counter < size; counter++) 
		{ 
			if (mn.struct_seven[counter].item_value < mn.struct_seven[current_index[0]].item_value) 
			{ 
				current_index[0] = counter; 
			} 
			else if (mn.struct_seven[counter].item_value > mn.struct_seven[current_index[length_of_days - 1]].item_value)
			{ 
				previous_index[counter] = current_index[length_of_days - 1]; 
				current_index[length_of_days++] = counter; 
			} 
			else 
			{ 
				int pos = binary_search_for_max_index(mn.struct_seven, current_index, -1, length_of_days - 1, mn.struct_seven[counter].item_value); 
			
				previous_index[counter] = current_index[pos - 1]; 
				current_index[pos] = counter; 
			} 
		} 
				
		cout<<"The days which have the longest spread period are: "<<endl;
		int j = current_index[length_of_days - 1];
		while ( j >= 0) 
		{
			cout <<" Date -> "<<mn.struct_seven[j].Myclass_date<<" **** Cases = "<<mn.struct_seven[j].item_value<<endl; 
			j = previous_index[j];
		}
		cout<<endl<< " Longest spread period elapsing "<<length_of_days<<" days!"<<endl;			
		
    }
	void Solution_of_part_C(string str)
	{ 
		int temp_value;
		Myclass* ptr = get_city_on_Index(str,temp_value);
		cout<<"\033[37m"<<"Country: "<<ptr->countryname<<endl;
		perform(ptr);
	}
//********************************************************FUNCTIONS FOR PART D*********************************************************	
	void _get_turned_1(struct_four &mn, vector<struct_five> LDS[], int n)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (mn.struct_seven[j].item_value > mn.struct_seven[i].item_value && LDS[j].size() > LDS[i].size())
					LDS[i] = LDS[j];
			}
			LDS[i].push_back(mn.struct_seven[i]);
		}
	}
	void _get_turned_2(vector<struct_five> LDS[], int n, int &j)
	{
		for (int i = 0; i < n; i++)
			if (LDS[j].size() < LDS[i].size())
						j = i;
	}
	void _get_turned_3(vector<struct_five> LDS[],int&j)
	{
		int k = 0;
		struct_five l;
		cout<<"\033[32m"<<"Following is the longest death occurence decrease in the given country: "<<endl;
		for (struct_five i : LDS[j])
		{
			if(k == 0)
			{
				cout <<"Starting date =  "<<i.Myclass_date<<endl;
				cout << i.item_value <<endl;
			}
			else
			{
				cout << i.item_value <<endl;
			}
			l = i;
			k++;
		}
		cout<<"Ending date = "<<l.Myclass_date<<endl;
		cout<<"Length is: "<<k<<endl;
	
	}
	void _get_turned(Myclass*temp)
    	{
			struct_four mn = get_city_for_struct_four(temp, 'd');
			int n = mn.item_value;
			vector<struct_five> LDS[n];
			LDS[0].push_back(mn.struct_seven[0]);
			_get_turned_1(mn,LDS, n );
			int j = 0;
			_get_turned_2(LDS, n, j);
			_get_turned_3(LDS, j);
		}    	
    	void Solution_of_part_D(string s1)
    	{
			int temp_value;
			Myclass* ptr = get_city_on_Index(s1,temp_value);
			cout<<"Country: "<<ptr->countryname<<endl;
			_get_turned(ptr);
    	}
//********************************************************FUNCTIONS FOR PART E*********************************************************    	
    
	int partition_e(struct_six arr[], int min, int max)   
	{ 
		int point = arr[max].item_value;
		int i = (min - 1); 
		for (int j = min; j <= max - 1; j++)  
		{  
			if (arr[j].item_value < point)  
			{  
				i++; 
				swap(&arr[i], &arr[j]);  
			}  
		}  
		swap(&arr[i + 1], &arr[max]);  
		return (i + 1);  
		
	}  
	void sort_e(struct_six arr[], int max, int min)   
	{  
		if (min < max)  
		{
			int pi = partition_e(arr, min, max);  
			sort_e(arr, min, pi - 1);  
			sort_e(arr, pi + 1, max);  
		}  
	}  
    int get_last_days_active_cases(Myclass * temp)//function to get the last day's active cases
	{
		while(temp->next!= NULL)
		{
			temp = temp->next;
		}
		return temp->active_cases;
	}
	void fill_it_up(struct_six a[])
	{
		for(int i = 0; i<213; i++)
		{
            	a[i].name_of_country = ptr_array[i]->countryname; 
				a[i].item_value = get_last_days_active_cases(ptr_array[i]);
            	if(ptr_array[i]->countryname == "undefined")
            	    a[i].item_amount =999999999;
           		else
				a[i].item_amount = ptr_array[i]->weight;
		}
	}
	void _print_answer(struct_six a[],int array_index[], int array_index_c , int iterator_count)
	{
		int l = 0;
		while(l<array_index_c)
		{
				cout<<"\033[1m\033[35m"<<l+1<<". Name of Country: "<<"\033[1m\033[32m"<<a[array_index[l]].name_of_country <<endl<<"\033[1m\033[37m"<<"\t            Total weight: "<<a[array_index[l]].item_amount<<endl;
				cout<<"\t            Active Cases: "<<a[array_index[l]].item_value<<endl;
				l++;
		}
		cout<<"\033[1m\033[33m"<<"Total countries are: "<<iterator_count<<endl;
	}
	void do_and_print(struct_six a[], int k)
	{
		int budget_amount_accum = 0, iterator_count = 0;
		int j = 212;
		int array_index[213] = {0};
		int array_index_c= 0;
		while(j>=0)
		{
			budget_amount_accum+= a[j].item_amount;
			if(budget_amount_accum<=k && a[j].item_amount!= 0)
			{
				array_index[array_index_c] = j;
				array_index_c++;
				iterator_count++;
				
			}
			else
			{
				budget_amount_accum-=a[j].item_amount;
			}
			
			j--;
		}
		_print_answer(a,array_index, array_index_c, iterator_count);
	}
	void perform_for_E(int k)
	{
		
		struct_six a[213];
		fill_it_up(a);
		sort(a, a+213);
		do_and_print(a, k);
		
	}	
    void Solution_of_part_E(int budget_value)
	{
		perform_for_E(budget_value);
	}
//********************************************************FUNCTIONS FOR PART F*********************************************************  
	void do_L_C_S_F(struct_five A[], struct_five B[], int size, int size_1, int begt, string country_1, string country_2) 
	{ 
		
		bool bool_false_ = false;
		string next_1, most_1;
		int matrix[size + 1][size_1 + 1] = {{0}}; 
		int previous_to_counter_one , previous_to_counter_two;
		int i = size - 1 ;
		while ( i >= 0 ) 
		{ 
			int j = size_1 - 1 ;
			while( j >= 0 ) 
			{ 
				int a = A[i].item_value - B[j].item_value;
				if(a<0)
					a = a * (-1);
				if (a<begt) 
				{
					
					matrix[i][j] = matrix[i + 1][j + 1] + 1; 
					if(!bool_false_)
					{
					next_1 = A[i].Myclass_date;
					most_1 = B[j].Myclass_date;
						bool_false_ = true;
					}
					previous_to_counter_one = i;
					previous_to_counter_two = j;
				}
				j--;
			} 
			i--;
		} 
		
		
		int which_max = 0; 
		int coungt_x = 0;
		while( coungt_x < size ) 
		{ 
			int countd = 0;
			while( countd < size_1) 
			{ 
				which_max = max(which_max, matrix[coungt_x][countd]); 
				countd++;
			
			} 
			coungt_x++;
		} 
		cout<<"\033[32m"<<"Similarity between "<<country_1<<" & "<<country_2<<" = " <<which_max;
		cout<<endl<<country_1<<" -> "<<g_C_date_I(country_1, A[previous_to_counter_one].Myclass_date);
		cout<<":"<<g_C_date_I(country_1,next_1)<<endl<<country_2<<" -> ";
		cout<<g_C_date_I(country_2, B[previous_to_counter_two].Myclass_date)<<":"<<g_C_date_I(country_2, most_1)<<endl;
		
	} 
	void Solution_of_part_F(string str1, string str2, int threshold)
	{
		int temp=0;
		struct_four struct_temp_var = get_city_for_struct_four(get_city_on_Index(str1, temp), 'f');
		temp=0;
		struct_four node1 = get_city_for_struct_four(get_city_on_Index(str2, temp),'f');
		
  	 	do_L_C_S_F(struct_temp_var.struct_seven,node1.struct_seven, struct_temp_var.item_value, node1.item_value, threshold, str1, str2);
	  
	}
};

void READ_FROM_WHO(MY_Linked_List& LINK)
	{
            string Myclass_year, Myclass_month, Myclass_date, 
            country, country_name, no_of_deaths, region, cummulative_deaths,
            confirmed_deaths, cummulative_confirmed_deaths, garbage_data, daily_count;
		fstream who_covid_file("WHO-COVID-19.csv");
		char check;
		getline(who_covid_file, garbage_data);
		int iterator =0;
		string new_data;
		string next_data;
		while(!who_covid_file.eof())
		{
			if(iterator == 9042)
				break;
                Myclass struct_temp_whofile;
				getline(who_covid_file, Myclass_year, '-');
            	getline(who_covid_file, Myclass_month, '-');
            	getline(who_covid_file, Myclass_date, ',');
            	getline(who_covid_file, country, ',');
            	who_covid_file>>check;
			if(int(check) == 34)
			{
				getline(who_covid_file, country_name, '"');
				if(iterator==0)
					new_data = country_name;
				else 
					next_data = country_name;
					
				who_covid_file>>check;
			}
			else
			{
                		int temp = who_covid_file.tellp();
				who_covid_file.seekp(temp-1);
				getline(who_covid_file, country_name, ',');
				if(iterator==0)
				{
					new_data = country_name;
				}
				else 
				{
					next_data = country_name;
				}
					
			}
            	getline(who_covid_file, region, ',');
            	getline(who_covid_file, no_of_deaths, ',');
            	getline(who_covid_file, confirmed_deaths, ',');
            	getline(who_covid_file, daily_count, ',');
            	getline(who_covid_file, cummulative_confirmed_deaths);
            	
            	int year = stoi(Myclass_year);
				struct_temp_whofile.Myclass_year=(year);
			
            	int month = stoi(Myclass_month);
				struct_temp_whofile.Myclass_month=(month);
            	
            	int day = stoi(Myclass_date);
				struct_temp_whofile.Myclass_date=(day);
				struct_temp_whofile.country=(country);
				struct_temp_whofile.region=(region);
			
            	int death = stoi(no_of_deaths);
				struct_temp_whofile.death=(death);
			
				int con_death = stoi(confirmed_deaths);
				struct_temp_whofile.c_death=(con_death);
            
            	int daily_c = stoi(daily_count);
				struct_temp_whofile.daily_count_confirmed=(daily_c);
			
				int cum_comfirmed = stoi(cummulative_confirmed_deaths);
            	struct_temp_whofile.countryname=(country_name);
				struct_temp_whofile.active_cases = (cum_comfirmed - con_death);
				struct_temp_whofile.next = NULL;
			
			LINK.data_insertion(struct_temp_whofile, new_data, next_data);
			iterator++;
		}		
		fstream country_weight("CountryWeight.csv");
		getline(country_weight, garbage_data);
		string weight_s;
		string str;
		int file_iterator;
		while(!country_weight.eof())
		{
			country_weight>>check;
			if(int(check) == 34)
			{
				getline(country_weight, country_name, '"');
				
				country_weight>>check;
			}
			else
			{ 
                		int temp_value = country_weight.tellp();
				country_weight.seekp(temp_value-1);
				getline(country_weight, country_name, ',');
				
			}
			if(str == country_name)
				break;
				
			getline(country_weight, weight_s);
			if(LINK.get_link_iserik(file_iterator)->countryname == country_name)
			{
				LINK.get_link_iserik(file_iterator)->weight = stoi(weight_s);
				iterator++;
			}
			else
			{
                
				LINK.get_node_if_given_country(country_name)->weight = stoi(weight_s);
			}
			str = country_name;
		}
	
	}

