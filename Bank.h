#ifndef __H_BANK__
#define __H_BANK__

#include "Account.h"

class Bank{
private:
	string Bank_name;
	vector<Bank> Bank_list;
	vector<Account> Account_list;
public:
	Bank();
	Bank(string name);
	Bank(string name, vector<Bank>& list);
	string Get_Bank_name();

	void Add_account(Account&);
	Account* Search_Account(string);
	Account* Search_Account(int);
	Account* Search_Account_linked_bank(string);
	Account* Search_Account_linked_bank(int);
	bool Check_card(string);
	bool Check_card_linked_bank(string);
	bool Check_pw(string, string);
	void Deposit(Account*, int);
	void Withdrawal(Account*, int);
	vector<vector<string> >& Get_account_log(Account*);
	vector<string>& Get_account_info(Account*);
	friend void Link_bank(Bank&, Bank&);
	
};

#endif