#ifndef __H_UI__
#define __H_UI__
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */

using namespace std;
class UI{
private:
	void (UI::*Display_functions[6])()={
		&UI::Input_card,
		&UI::Input_pw, 
		&UI::Set_transaction,
		&UI::Input_cash,
		&UI::End_session,
		&UI::Admin_mode
		};
	void (UI::*Error_functions[5])()={
		&UI::Wrong_cardnumber, 
		&UI::Wrong_passwords, 
		&UI::Lack_of_balance, 
		&UI::Wrong_account_number, 
		&UI::Over_max_atm_input
		};
protected:
	string Transaction_type[3];
	virtual void End_session() = 0;
	virtual void End_session_message() = 0;
	virtual void Input_card() = 0;
	virtual void Input_pw() = 0;
	virtual void Set_transaction() = 0;
	virtual void Input_cash() = 0;

	virtual void Wrong_cardnumber() = 0;
	virtual void Wrong_passwords() = 0;
	virtual void Lack_of_balance() = 0;
	virtual void Wrong_account_number() = 0;
	virtual void Over_max_atm_input() = 0;
	virtual void Session_display(vector<string>&) = 0;
	virtual void Session_history(vector<vector<string> >&) = 0;
	virtual void Account_history(vector<string>&, vector<vector<string> >&) = 0;
	virtual void Admin_mode()=0;
public:
	void Display(int type){
		(this->*Display_functions[type])();
	}
	void Error_message(int type){
		(this->*Error_functions[type])();
	}
	void Display_session(vector<string>& log){
		Session_display(log);
	}
	void Display_session_history(vector<vector<string> >& logs){
		Session_history(logs);
	}
	void Display_account(vector<string>& info, vector<vector<string> >& logs){
		Account_history(info, logs);
	}
};
class UI_ENG : public UI{
protected:
	void End_session(){
		cout<<BOLDGREEN<<"Session is end Thank you"<<RESET<<endl<<endl<<endl<<endl<<endl;
	}
	void End_session_message(){
		cout<<"If you want end this session press 0"<<endl;
	}
	void Input_card(){
		cout<<"---------------------------------------"<<endl;
		cout<<"                 WELCOME               "<<endl<<endl;
		cout<<"To start, Please insert your debit card"<<endl;
		cout<<"Card Number : ";
	};
	void Input_pw(){
		End_session_message();
		cout<<"Input Passwords : "<<endl;
	};
	void Set_transaction(){
		End_session_message();
		cout<<"Select Transaction 1 : Deposit, 2 : Withdrawal, 3 : Check Account "<<endl;
	};
	void Input_cash(){
		End_session_message();
		cout<<"Input Cash : "<<endl;
	};

	void Admin_mode(){
		End_session_message();
		cout<<"WELCOME Admin if you want check Transaction History please Input 1"<<endl;
	}
	void Wrong_cardnumber(){
		cout<<BOLDRED<<"Input Wrong cardnumber"<<RESET<<endl;
	}
	void Wrong_passwords(){
		cout<<BOLDRED<<"Input Wrong passwords"<<RESET<<endl;
	}
	void Lack_of_balance(){
		cout<<BOLDRED<<"Lack_of_balance error"<<RESET<<endl;
	}
	void Wrong_account_number(){
		cout<<BOLDRED<<"Input Wrong Account number"<<RESET<<endl;
	}
	void Over_max_atm_input(){
		cout<<BOLDRED<<"Over Max ATM input"<<RESET<<endl;
	}
	void Session_display(vector<string>& log){
		cout<<BOLDBLACK<<"Session Log!"<<RESET<<endl;
		cout<<setw(10)<<"User name"<<setw(17)<<"Transaction type"<<setw(15)<<"Amount($)"<<setw(17)<<"Source Account"<<setw(20)<<"Destinaion Account"<<setw(15)<<"fee"<<endl;
		cout<<setw(10)<<log[0]<<setw(17)<<log[1]<<setw(15)<<log[2]<<setw(17)<<log[3]<<setw(20)<<log[4]<<setw(15)<<log[5]<<endl;
	}
	void Session_history(vector<vector<string> >& logs){
		ofstream ofs("Transaction_history.csv");
		ofs<<"id,User name,Transaction type,Amount,Source Account,Destinaion Account,fee"<<endl;
		cout<<setw(3)<<"id"<<setw(10)<<"User name"<<setw(17)<<"Transaction type"<<setw(15)<<"Amount"<<setw(17)<<"Source Account"<<setw(20)<<"Destinaion Account"<<setw(15)<<"fee"<<endl;
		int id = 0;
		for(vector<string>& log : logs){
			ofs<<id<<","<<log[0]<<","<<log[1]<<","<<log[2]<<","<<log[3]<<","<<log[4]<<","<<log[5]<<endl;
			cout<<setw(3)<<id<<setw(10)<<log[0]<<setw(17)<<log[1]<<setw(15)<<log[2]<<setw(17)<<log[3]<<setw(20)<<log[4]<<setw(15)<<log[5]<<endl;
			id++;
		}
	}
	void Account_history(vector<string>& info, vector<vector<string> >& logs){
		cout<<setw(15)<<"Name"<<setw(20)<<"Account Number"<<setw(15)<<"Balance"<<endl;
		cout<<setw(15)<<info[0]<<setw(20)<<info[1]<<setw(15)<<info[2]<<endl;
		cout<<"Transaction History"<<endl;
		cout<<setw(3)<<"id"<<setw(15)<<"Deposit"<<setw(15)<<"Withdrawal"<<setw(15)<<"Balance"<<endl;
		int id = 0;
		for(vector<string>& log : logs){
			cout<<setw(3)<<id<<setw(15)<<log[0]<<setw(15)<<log[1]<<setw(15)<<log[2]<<endl;
			id++;
		}
	}
};
#endif