#include "ATM.h"
#include <iostream>
ATM::ATM(Bank* bank){
	Linked_bank = bank;
}
ATM::ATM(int balance, Bank* bank){
	Atm_cash_balance = balance;
	Linked_bank = bank;
}
bool ATM::Input_check(int input){
	return input == 0;
}
bool ATM::Input_check(string input){
	return input == "0";
}

void ATM::Set_admin(string cardnumber, string passwords){
	Admin_cards.insert(pair<string, string>(cardnumber, passwords));
	return;
}
bool ATM::Admin_card_check(string cardnumber){
	auto item = Admin_cards.find(cardnumber);
	return item != Admin_cards.end();
}
bool ATM::Admin_check(string cardnumber, string passwords){
	auto item = Admin_cards.find(cardnumber);
	return passwords == item->second;
}
void ATM::Admin_mode(string cardnumber){
	string passwords;
	Atm_ui->Display(1);
	cin>>passwords;
	if(Input_check(passwords)){return End_session();}
	if(Admin_check(cardnumber, passwords)){
		Atm_ui->Display(5);
		int check;
		cin>>check;
		if(Input_check(check)){return End_session();}
		if(check){
			Atm_ui->Display_session_history(Atm_log);
			End_session();
		}
	}
	else{return Admin_mode(cardnumber);}
}

void ATM::Init_step(){
	Atm_ui->Display(0);
	Card_check_step();
	return;
}
void ATM::Card_check_step(){
	string input;
	cin>>input;
	if(Input_check(input)){return End_session();}
	if(Admin_card_check(input)){return Admin_mode(input);}
	else if(Linked_bank->Check_card(input)){
		Account_type1 = 0;
		return Passwords_check_step(input);
	}
	else if(Linked_bank->Check_card_linked_bank(input)){
		Account_type1 = 1;
		return Passwords_check_step(input);
	}
	else{
		Atm_ui->Error_message(0);
		return Init_step();
	}
}

void ATM::Passwords_check_step(string cardnumber){
	for(int i=0; i<3; i++){
		Atm_ui->Display(1);
		string passwords;
		cin>>passwords;
		if(Input_check(passwords)){return End_session();}
		if(Linked_bank->Check_pw(cardnumber, passwords)){
			return Do_transaction(cardnumber);
		}
		else{
			Atm_ui->Error_message(1);
			continue;
		}
	}
	void End_session();
}
void ATM::Do_transaction(string cardnumber){
	Account* target;
	if(!Account_type1){
		target = Linked_bank->Search_Account(cardnumber);
	}
	else{
		target = Linked_bank->Search_Account_linked_bank(cardnumber);
	}
	Session_log[0] = target->Get_account_name();
	Atm_ui->Display(2);
	int mode;
	cin>>mode;
	switch(mode){
		case 1:
		return Deposit(target);
		case 2:
		return Withdrawal(target);
		case 3:
		return Check_account(target);
		default:
		return End_session();
	}
}
void ATM::Deposit(Account* account){
	int sel;
	int cash = 0;
    Atm_ui->Display(3);
    cin>>cash;
    if(Input_check(cash)){return End_session();}

	try{
		int fee = Deposit_fee[Account_type1];
		Linked_bank->Deposit(account, cash - fee);
		Atm_cash_balance += cash;
		Session_log[1] = "Deposit";
		Session_log[2] = to_string(cash);
		Session_log[3] = "";
		Session_log[4] = to_string(account->Get_account_number());
		Session_log[5] = to_string(fee);
		return Print_log();
	}
	catch(int type){
		Atm_ui->Error_message(type);
		return this->Deposit(account);
	}
}
void ATM::Withdrawal(Account* account){
	int cash;
	Atm_ui->Display(3);
	cin>>cash;
	if(Input_check(cash)){return End_session();}
	if(cash>Atm_cash_balance){
		Atm_ui->Error_message(2);
		return Withdrawal(account);
	}
	try{
		int fee = Withdrawal_fee[Account_type1];
		this->Linked_bank->Withdrawal(account, cash + fee);
		this->Atm_cash_balance-=cash;
		Session_log[1] = "Withdrawal";
		Session_log[2] = to_string(cash);
		Session_log[3] = to_string(account->Get_account_number());
		Session_log[4] = "";
		Session_log[5] = to_string(fee);
		return Print_log();
	}
	catch(int type){
		Atm_ui->Error_message(type);
		return this->Withdrawal(account);
	}
}

void ATM::Check_account(Account* account){
	Atm_ui->Display_account(Linked_bank->Get_account_info(account), Linked_bank->Get_account_log(account));
	return End_session();
}
void ATM::Display_transaction_history(){
	Atm_ui->Display_session_history(this->Atm_log);
}
void ATM::End_session(){
	Atm_ui->Display(4);

	return;
}
void ATM::Print_log(){
	Atm_log.push_back(Session_log);
	Atm_ui->Display_session(Session_log);
	
	End_session();
}
void ATM::Run(){
    Init_step();
	return;
}