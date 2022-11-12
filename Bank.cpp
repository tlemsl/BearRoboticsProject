#include "Bank.h"
void Link_bank(Bank& b1, Bank& b2){
	b1.Bank_list.push_back(b2);
	b2.Bank_list.push_back(b1);
	return;
}
Bank::Bank(){
	Bank_name = "Shin han";
}
Bank::Bank(string name){
	Bank_name = name;
}
Bank::Bank(string name, vector<Bank>& list){
	Bank_name = name;
	Bank_list = list;
}
string Bank::Get_Bank_name(){return this->Bank_name;}
void Bank::Add_account(Account& account){Account_list.push_back(account);}
vector<string>& Bank::Get_account_info(Account* account){return account->Get_account_info();}
vector<vector<string> >& Bank::Get_account_log(Account* account){return account->Get_account_log();}

Account* Bank::Search_Account(string cardnumber){
	try{
		vector<Account>::iterator it = Account_list.begin();
		for(; it != Account_list.end(); ++it){
			if(it->Check_card(cardnumber)){return &(*it);}
		}
		throw cardnumber;
	}
	catch(string cardnumber){
		throw;
	}
}
Account* Bank::Search_Account(int account_number){
	try{
		vector<Account>::iterator it = Account_list.begin();
		for(; it != Account_list.end(); ++it){
			if(it->Get_account_number() == account_number){return &(*it);}
		}
		throw 3;
	}
	catch(int type){
		throw;
	}
}
Account* Bank::Search_Account_linked_bank(string cardnumber){
	try{
		for(Bank& temp : Bank_list){
			try{
				return temp.Search_Account(cardnumber);
			}
			catch(string cardnumber){
				continue;
			}
		}
		throw cardnumber;
	}
	catch(string cardnumber){
		throw;
	}
}
Account* Bank::Search_Account_linked_bank(int account_number){
	try{
		for(Bank& temp : Bank_list){
			try{
				return temp.Search_Account(account_number);
			}
			catch(int type){
				continue;
			}
		}
		throw 3;
	}
	catch(int type){
		throw;
	}

}
void Bank::Deposit(Account* account, int amount){
	try{
		account->Deposit(amount);
	}
	catch(int type){
		throw;
	}
}
void Bank::Withdrawal(Account* account, int amount){
	try{
		account->Withdrawal(amount);
	}
	catch(int type){
		throw;
	}
}
bool Bank::Check_card(string cardnumber){
	try{
		auto temp = Search_Account(cardnumber);
		return true;
	}
	catch(string cardnumber){
		return false;
	}
}
bool Bank::Check_card_linked_bank(string cardnumber){
	try{
		auto temp = Search_Account_linked_bank(cardnumber);
		return true;
	}
	catch(string cardnumber){
		return false;
	}
}
bool Bank::Check_pw(string cardnumber, string passwords){
	try{
		auto temp = Search_Account(cardnumber);
		return temp->Check_pw(cardnumber, passwords);
	}
	catch(string){
		auto temp = Search_Account_linked_bank(cardnumber);
		return temp->Check_pw(cardnumber, passwords);
	}
}
