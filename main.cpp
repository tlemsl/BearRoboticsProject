#include "Bank.h"
#include "Account.h"
#include "ATM.h"


int main(int argc, char* argv[]){
    Account ACC_Bear(123, "BearRobotics", 100000000); // Account id, Owner Name, Charge
    Account ACC_MJ(132, "Minjong", 1000);
	Account Dummy(1234, "Dummy", 0);
    ACC_Bear.Card_registration("1111", "1234"); // Card Registration: Card number, Passwords
	ACC_Bear.Card_registration("1112", "1234"); // Multiple cards can be registered.
    
    ACC_MJ.Card_registration("2222", "0514");
	
    Bank Shinhan("Shinhan");                    // Create New Bank
	Bank BOK("Bank of Korea");
	BOK.Add_account(ACC_Bear);                  //Regist Account
    BOK.Add_account(Dummy);                     // Multiple accounts can be registered.
	Shinhan.Add_account(ACC_MJ);
	Link_bank(Shinhan, BOK);                    // Linking Bank Each other


	ATM test_atm(500000, &Shinhan);             // Create ATM machine ATM of Shinhan Bank, Chage $500000
	test_atm.Set_admin("1234","1234");          // Regist Admin Card, Admin can see ATM transaction history

    while(1){
        test_atm.Run();                         //Run ATM
    }
}

