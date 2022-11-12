#ifndef __H_ACCOUNT__
#define __H_ACCOUNT__

#include <string>
#include <vector>
#include <map>

using namespace std;

class Account{
private:
	int Account_id;
	int Balance;
	string Name;
	map<string, string> Cards;
	vector<string> Temp_log = {"", "", ""};
	vector< vector<string> > Account_log;
public:
	Account();
	Account(int id, string name, int balance);
	string Get_account_name();
	int Get_account_balance();
	int Get_account_number();
	vector<string>& Get_account_info();
	vector< vector<string> >& Get_account_log();
	void Card_registration(string, string);

	bool Check_card(string);
	bool Check_pw(string, string);
	
	
	void Deposit(int);
	void Withdrawal(int);
};
#endif