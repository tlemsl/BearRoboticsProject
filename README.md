# BearRoboticsProject
## UML Diagram 

![UML](https://user-images.githubusercontent.com/50408036/201504856-b16160bd-da80-45ba-90ee-773021df3e41.png)

## API Description
### Assumption
  * Account Numbers are distinct values that do not overlap. 
  * Card Numbers are distinct values that do not overlap.
  * ATM has Primary Bank, and ATM Can access another bank(Linked bank). but there is some transaction fee($1)
### Account & Card
1. Account::Account(int id, string name, int balance)  
  Create Account, Account has account number, name, balance
  * id : Account Number(Distinct value)
  * name : Account Name
  * balance : Account Balance
```
Account ACC_Bear(123, "BearRobotics", 100000000);
Account ACC_MJ(132, "Minjong", 1000);
```
2. void Account::Card_registration(string cardnumber, string passwords)  
  Card Registration. Multiple card can be registered.
  * Cardnumber : cardnumber(Distinct value)
  * passwords : passwords(Can overlap)
```
ACC_Bear.Card_registration("1111", "1234");
ACC_Bear.Card_registration("1112", "1234");
```
### Bank
1.Bank::Bank() Bank::Bank(string name) Bank::Bank(string name, vector<Bank>& list)  
  Create Bank with bank name and manual linked bank list.
  * name : Bank name default : "Shinhan"
  * list : Linked bank list, default : None
```
Bank BOK("Bank of Korea");
Bank Shinhan("Shinhan");
```

2. void Bank::Add_account(Account& account)  
  Add Account to bank. Multiple account can be registered.
  * account : Predefined account
```
BOK.Add_account(ACC_Bear);
BOK.Add_account(Dummy);  
```
3. void Link_bank(Bank& b1, Bank& b2)  
  Link bank each other. if Bank's atm can access another bank's account. Need to link each bank. multiple bank can be linked.
  * b1, b2 : Linked banks(Regardless of order)

```
Link_bank(Shinhan, BOK);
```

### ATM
1. ATM::ATM(Bank* bank) ATM::ATM(int balance, Bank* bank)  
  Create ATM.
  * bank : primary bank of atm
  * balance : atm cash balance default : $1000
```
ATM test_atm(500000, &Shinhan);
```
2. void ATM::Set_admin(string cardnumber, string passwords)  
  Set ATM's Admin card. Admin Can check the atm transaction history. ATM provide csv file of trasaction history.
  * Cardnumber : cardnumber(Distinct value)
  * passwords : passwords
```
test_atm.Set_admin("1234","1234");
```
3. void ATM::Run()  
  ATM runs one session.
```
while(1){
	test_atm.Run();                         //Run ATM
}
```


## How to Run(Example case)
```
git clone https://github.com/tlemsl/BearRoboticsProject
cd BearRoboticsProject
make
./atm.out
```

