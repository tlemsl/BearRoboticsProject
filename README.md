# BearRoboticsProject
## UML Diagram 

![UML](https://user-images.githubusercontent.com/50408036/201504856-b16160bd-da80-45ba-90ee-773021df3e41.png)

## API Description
### Account & Card
1. Account::Account(int id, string name, int balance)
  * id : Account Number 
  * name : Account Name
  * balance : Account Balance
```
Account ACC_Bear(123, "BearRobotics", 100000000);
```
2. void Account::Card_registration(string cardnumber, string passwords)
  * Cardnumber : cardnumber 
  * passwords : passwords
```
ACC_Bear.Card_registration("1111", "1234");
```
### Bank
1. Bank();
	Bank(string name);
	Bank(string name, vector<Bank>& list);



### ATM


## How to Run(Example case)

