/*MY INFO*
(o^^)o  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~o(^^o)
                            Group       :   1
                            Name        :   Amir AHmed Hassan
                            Sec         :   1
                            BN          :   42
                            ID          :   9202315
(o^^)o  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~o(^^o)
*/
//Libraries
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
using namespace std;
                                        /*Constants:
    this constants stores maximum limits for different variables. It helps make the code re-usable
                                                    */
    const int       Min_EventDuration    =     30      ;         /*Minimum EventDuration in minutes*/
    const int       Max_EventDuration    =     480     ;         /*Maximum EventDuration in minutes*/
    const int       Min_GuestCount       =     10      ;         /*Maximum GuestCount*/
    const int       Max_GuestCount       =     1000    ;         /*Maximum GuestCount*/
    const int       Max_CString_Size     =     100     ;         /*array of characters max size*/
    const float     meal_price           =     54.5    ;         /*we can change price of meal at any time*/
    const float     waiter_hourly_wage   =     46.5    ;         /*we can change waiter wage in hour*/
    const float     waiter_minute_wage   =     1       ;         /*we can change waiter wage in hour*/
                                        /*Functions:
        this set of functions i used to check on user input and avoid corner cases
                                                    */
    void        display_Cstring (char mystring [Max_CString_Size])             {//display a cstring
    for (int i = 0 ; mystring[i] ; i++) {
        cout<<mystring[i];
    }
    }
    bool        check_number(char my_input [Max_CString_Size])                 {//check if a supposed number input has a symbol
                                        /*check number:
           this function returns 1 if number is not valid and 0 if it is valid
                                                    */
        int decimal_flag = 0;                               //flag to check for decimal points
        for (int i = 0 ; my_input[i] ; i++) {
            if(my_input[i]>='0' && my_input[i]<='9'){
                    continue;                               //ASCII code for valid numbers
            }
            else if (my_input[i]=='.'){                     //detecting a decimal point
                    decimal_flag++;                         //flag increases every time decimal point detected
            }
			else{return 1;}
		}

            if(decimal_flag>1){ return 1;}                  //string has more than 1 decimal symbol
            if (my_input[0]=='-') {                         //Number is negative
                    cout <<"number is negative..."<<endl;
                    return 1;
                }
			if(decimal_flag==1) {
                    cout << "your number is an invalid input..."<<endl;
                    cout << "input number should be a positive whole number..."<<endl;
                    cout << "rounding down your number..."<<endl;
                    cout << "your number is rounded down to first whole number successfully!"<<endl;

            }
        return 0;
        }
    double      whole_number_value(char my_input [Max_CString_Size])           {//get number from string type user input
                                        /*Whole_number_value
                        calculates number from string type user input ;)
                                                    */
    double sum = 0;
    int len=0;                                              // len is the whole number length
	for(int i = 0 ;my_input[i];i++){                        //stops when i hit null terminator
		if(my_input[i]=='.'){                               //also stops when i hit a decimal point
                break;
        }
     len++;
    }
    for(int i=0;i<len;i++){
        sum = sum + (my_input[i]-'0')* pow(10,len-i-1);     //converting string to integer (>->)
    }
    return sum;
    }
    double      number_input()                                                 {//my customized "cin>>"
        char my_input[Max_CString_Size];

        while (true){
            cin.getline(my_input,Max_CString_Size);
            if(my_input[0]=='\0'){
            cout<<"no data, please rewrite input: "<<endl;      //empty user input
            continue;
            }
			if(check_number(my_input)){                         //wrong user input
            cout<<"Error invalid input detected : please enter a positive whole number"<<endl;
            //Clears carriage input
            continue;
            }
			break;
		}
        return   whole_number_value(my_input);
    }
    bool        check_empty(char mystring [Max_CString_Size]){
    if(mystring[0]=='\0') return 1;
    else return 0;
    }
    bool        check_sentence_input(char sentence[Max_CString_Size] ){
    int length_counter = 0;
	int apostrophe_counter = 0;
    for (int i = 0 ; sentence[i] ; i++)
    {       length_counter++;
             if((sentence[i]>='a' && sentence[i]<='z')||(sentence[i]>='A' && sentence[i]<='Z')||(sentence[i] == ' ')||(sentence[i] == '\''))
            {
				if (sentence[i] == '\''){apostrophe_counter++;}
                    continue;                               //ASCII code for valid numbers
            }
            else
            {
                    cout<<"wrong input, name cant contain special characters or numbers"<<endl;
                    cout<<"please enter a valid name :"<<endl;
                    return false;
            }
    }
	if (apostrophe_counter>1) {
        cout<<"you cant add more than one apostrophe \"\'\" to the name, try again"<<endl;
        return false;
    }
    if (length_counter<3) {
        cout<<"name too small, please write 3 or more characters"<<endl;
        return false;
    }
    else if (length_counter>99) {
        cout<<"name too big, please make sure the name is valid"<<endl;
        return false;
    }

    return true;
    }
    bool        check_name_input(char sentence[Max_CString_Size] ){
    int space_flag = 0;
    int length_counter = 0;
    for (int i = 0 ; sentence[i] ; i++)
    {       length_counter++;
             if((sentence[i]>='a' && sentence[i]<='z')||(sentence[i]>='A' && sentence[i]<='Z')||sentence[i] == ' ')
            {
                    if(sentence[i] == ' '){space_flag++;}
                    if(space_flag>=2)
                    {
                        cout<<"please insert only 1 space between first and last name, no more spaces allowed"<<endl;
                        cout<<"re-enter first and last name: "<<endl;
                        return false;
                    }
                    continue;                               //ASCII code for valid numbers
            }
            else
            {
                    cout<<"wrong input, name cant contain special characters or numbers"<<endl;
                    cout<<"please enter a valid name :"<<endl;
                    return false;
            }
    }
    if ((length_counter<3)&&(space_flag==0)) {
        cout<<"your first name too small, please write 3 or more characters"<<endl;
        return false;
    }
    else if ((length_counter<7)&&(space_flag==1)) {
        cout<<"please make sure you write both your first and last name correctly with a single space in between:"<<endl;
        return false;
    }
    else if (length_counter>99) {
        cout<<"name too big, please make sure the name is valid"<<endl;
        return false;
    }
    return true;
    }
class Event {
private:
    //note: i didn't use integer data type to avoid automatic type casting of user input later on
    char        EventName          [Max_CString_Size];           /*hold name of event*/
    char        CustomerName       [Max_CString_Size];           /*hold name of customer*/
    double      GuestCount                           ;           /*hold number of guests*/
    double      EventDuration                        ;           /*hold time in minutes*/
    double      NumberOfWaiters                      ;           /*hold number of waiters*/
    double      CostPerWaiter                        ;           /*hold expenses of waiters*/
    double      FoodCost                             ;           /*hold expenses of meals*/
    double      TotalCost                            ;           /*hold total expenses*/
    double      DepositAmount                        ;           /*hold 25% of total expenses*/
public:
	void getEventName()
	{   cout << "Enter the name of the event" << endl;          //User should input name of event
		cin.getline(EventName, Max_CString_Size);               //no checking condition on names :)
		while (check_empty(EventName)){
            cout<<"no data, please rewrite input: "<<endl;
            cin.getline(EventName, Max_CString_Size);
		}
		while (!check_sentence_input(EventName)){
            cin.getline(EventName, Max_CString_Size);
		}

	}
	void getCustomerName()
	{
	    cout << "Enter the customer's first and last name" << endl;
		cin.getline(CustomerName, Max_CString_Size);
        while (check_empty(CustomerName)){
            cout<<"no data, please rewrite input: "<<endl;
            cin.getline(CustomerName, Max_CString_Size);
		}
        while (!check_name_input(CustomerName)){
            cin.getline(CustomerName, Max_CString_Size);
		}
	}
    void getGuestCount()
    {
        cout<< "Enter the number of guests" << endl;
        GuestCount = number_input();                         //user defined input function at line 79
        while(GuestCount>Max_GuestCount){                    //check on limits
                cout<<"sorry, you have exceeded the maximum limit of guests "<<endl;
                cout<<"check our limits : "<<endl<<"maximum : "<<Max_GuestCount<<endl;
                cout<<"enter another guest number : "<<endl;
                GuestCount = number_input();
                }
        while(GuestCount<Min_GuestCount){
                cout<<"sorry, you did not reach the minimum limit of guests "<<endl;
                cout<<"check our limits : "<<endl<<"minimum : "<<Min_GuestCount<<endl;
                cout<<"enter another guest number : "<<endl;
                GuestCount = number_input();
                }
    }
	void getEventDuration()
	{
	    cout << "Enter the number of minutes in the event" << endl;

		EventDuration = number_input();                         //user defined input function at line 79

		 while(EventDuration>Max_EventDuration){                //check on limits
                cout<<"sorry, you have exceeded the maximum limit of Event Duration "<<endl;
                cout<<"check our limits : "<<endl<<"maximum : "<<Max_EventDuration<<endl;
                cout<<"enter another Event Duration (in minutes) : "<<endl;
                EventDuration = number_input();
                }
        while(EventDuration<Min_EventDuration){
                cout<<"sorry, you did not reach the minimum limit of Event Duration "<<endl;
                cout<<"check our limits : "<<endl<<"minimum : "<<Min_EventDuration<<endl;
                cout<<"enter another Event Duration (in minutes) : "<<endl;
                EventDuration = number_input();
                }
	}

	void getNumberOfWaiters()
        {
		NumberOfWaiters = ceil(GuestCount / 20);
	    }

    void getCostPerWaiter()
	    {
		/* if the waiter worked for more than 46 mins, it is more feasible to let him
            complete his working hour and get 46.5 L.E. only so that it lowers expenses
            we have now 3 sources of waiter expenses :
            1- 46.5 x   Number of full hours
            2- 1    x   Number of minutes as long as they are less than or equal to 46.5
            3- 46.5     if number of minutes excceeded 46 minutes
        */
        int full_hours,remainder_minutes;
        remainder_minutes = int(EventDuration)%60;                      //to get full working hours
        full_hours = int(EventDuration-remainder_minutes)/60;              //to get minutes above complete hours

        if(remainder_minutes*waiter_minute_wage>waiter_hourly_wage)   { //will make him complete another hour
            CostPerWaiter = waiter_hourly_wage * (full_hours + 1);
            }
        else{                                                           //will pay him each minute
            CostPerWaiter = waiter_hourly_wage * (full_hours) + waiter_minute_wage * (remainder_minutes);
            }
    }
    void getFoodCost()
	    {
		FoodCost = GuestCount * meal_price;
	    }

	void CalcualteCost()

	{
	    getNumberOfWaiters();
	    getCostPerWaiter();
        getFoodCost();
		TotalCost = FoodCost + CostPerWaiter * NumberOfWaiters;
		DepositAmount = TotalCost * 0.25;
	}
	void PrintInfo()
	{   cout <<endl;
		cout << "--------------------------------------" << endl;
		display_Cstring (EventName);  cout<< " Event" << endl;
		cout << "Event estimate for ";display_Cstring (CustomerName);cout<<endl;
		cout << "--------------------------------------" << endl;
		cout << "Number of Waiters: " << NumberOfWaiters<< endl;
		cout << "The Cost per Waiter: " << CostPerWaiter << endl;
		cout << "The Cost for Food is: " << FoodCost << endl;
		cout << "Total cost is :" << TotalCost << endl;
		cout << "Please provide a 25% deposit to reserve the event" << endl;
		cout << "The deposit needed is: " <<DepositAmount<< endl;
	}

};
int main(){
    Again ://i used this while testing my code only by removing backslashes in line 212 and 220
	Event my_event;                         //Creates (my_event) of class event
	my_event.getEventName();                //Changes Event name inside my_event (no restrictions on name )
	my_event.getCustomerName();             //Changes Customer name inside my_event (no restrictions on name)
    my_event.getGuestCount();               //Changes GuestCount inside my_event ( restricted to be -negative , -decimal , -characters other than numbers and a single decimal point , higher than max limit or lower than minimum limit)
    my_event.getEventDuration();            //Changes Duration inside my_event ( restricted to be -negative , -decimal , -characters other than numbers and a single decimal point , higher than max limit or lower than minimum limit)
    my_event.CalcualteCost();               //does passive calculations to get Optimized cost
    my_event.PrintInfo();                   //prints the required output
    cout<<endl<<"Test Again"<<endl;goto Again;

	return 0;
}
                                        /*THANKS
                                    (o^^)o~~~~~o(^^o)
                                    (o^^)o~~~~~o(^^o)
                                        */
