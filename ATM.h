#ifndef __H_ATM__
#define __H_ATM__

#include "Bank.h"
#include "UI.h"

class ATM{
private:
	int Atm_cash_balance = 1000; // $1000

	map<string, string> Admin_cards;

	Bank* Linked_bank;
	UI* Atm_ui = new UI_ENG;
	vector< vector<string> > Atm_log;
	vector<string> Session_log = vector<string>(6);
	int Session_count = 0;
	bool Account_type1 = 0; // 0 : Primary 1 : Another
	int Deposit_fee[2] = {0, 1};    //Fee of Depoist   0 : Primary Bank(Linked Bank), 1 : Another Bank
	int Withdrawal_fee[2] = {0, 1}; //Fee of Withdrawl 0 : Primary Bank(Linked Bank), 1 : Another Bank
	bool Input_check(int);
	bool Input_check(string);
	bool Admin_card_check(string);
	bool Admin_check(string, string);
	void Init_step();
	void Card_check_step();
	void Admin_mode(string);
	void Passwords_check_step(string);
	void Do_transaction(string);
	void Deposit(Account*);
	void Withdrawal(Account*);
	void Check_account(Account*);
	void Display_transaction_history();
	void End_session();
	void Print_log();

public:
	ATM(Bank*);
	ATM(int, Bank*);
	void Set_admin(string, string);
	void Run();
};

#endif