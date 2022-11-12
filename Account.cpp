#include "Account.h"
Account::Account(){
	Account_id = 0;
	Balance = 0;
	Name = ""; 
}
Account::Account(int id, string name, int balance){
	Account_id = id;
	Name = name;
	Balance = balance;
	
}
string Account::Get_account_name(){return this->Name;}
int Account::Get_account_balance(){return this->Balance;}
int Account::Get_account_number(){return this->Account_id;}
void Account::Card_registration(string cardnumber, string passwords){
	Cards.insert(pair<string, string>(cardnumber, passwords));
	return;
}
bool Account::Check_card(string cardnumber){

	auto item = Cards.find(cardnumber);
	return item != Cards.end();
}
bool Account::Check_pw(string cardnumber, string passwords){
	auto item = Cards.find(cardnumber);
	return passwords == item->second;
}

vector<string>& Account::Get_account_info(){
	Temp_log[0] = this->Name;
	Temp_log[1] = to_string(this->Account_id);
	Temp_log[2] =  to_string(this->Balance);
	return Temp_log;
}
vector< vector<string> >& Account::Get_account_log(){
	return this->Account_log;
}
void Account::Deposit(int data){
	int temp = Balance + data;
	try{
		if(temp < 0){
			throw 2;
		}
		else{
			this->Balance = temp;
			vector<string> log = {to_string(data), to_string(0), to_string(Balance)};
			Account_log.push_back(log);
		}
	}
	catch(int type){
		throw;
	}
}
void Account::Withdrawal(int data){
	try{
		int temp = Balance - data;
		if(temp < 0){
			throw 2;
		}
		else{
			this->Balance = temp;
			vector<string> log{to_string(0), to_string(data), to_string(Balance)};
			Account_log.push_back(log);
		}
	}
	catch(int type){
		throw;
	}
	
}