#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <climits>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);    //change color
void food_menu() //food menu
{
	SetConsoleTextAttribute(h,15);
	cout<<endl;
	cout<<"\t\t\t\t\t\t=====| FOOD MENU |====="<<endl<<endl;
	cout<<"\t\t\t\t\t=========================================="<<endl<<endl;
	string foods_names[] = {"PIZZA\t\t- Rs800","BURGER\t- Rs600","FIRED-RICE\t- Rs300","KOTTU\t\t- Rs550","NOODLES\t- Rs200","SANDWICH\t- Rs300","BIRIYANI\t- Rs600"};
	for(int a=0; a<7; a++)
	{
		cout<<"\t\t\t\t\t+\t"<<a+1<<")"<<foods_names[a]<<"\t\t+"<<endl<<endl;
	}
	cout<<"\t\t\t\t\t   5% DISCOUNT FOR ABOVE RS 2500/- ORDER"<<endl;
	cout<<"\t\t\t\t\t  10% DISCOUNT FOR ABOVE RS 5000/- ORDER"<<endl<<endl;
	cout<<"\t\t\t\t\t=========================================="<<endl;
	SetConsoleTextAttribute(h,15);
}
int opt_menu() //main menu
{
	int opt;
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout<<endl;
	SetConsoleTextAttribute(h,15);
	cout<<"\t\t\t\t\t-------------------------------------------------"<<endl;
	cout<<"\t\t\t\t\t|\tWELCOME TO FAST-FOODS RESTAURANT\t|"<<endl;
	cout<<"\t\t\t\t\t-------------------------------------------------"<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t MAIN MENU"<<endl;
	cout<<"\t\t\t\t\t\t\t============"<<endl<<endl<<endl;
	cout<<"\t\t\t\tORDER FOOD\t:\t[1]\t"<<endl;
	cout<<"\t\t\t\tEXIT\t\t:\t[2]\t"<<endl<<endl;
	option:
	cout<<"\t\t\t\tSELECT OPTION\t:\t";
	cin>>opt;
	SetConsoleTextAttribute(h,15);
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		SetConsoleTextAttribute(h,12);
		cout<<"\t\t\t\t\t\tINVALID INPUT!!"<<endl<<endl;
		SetConsoleTextAttribute(h,15);
		goto option;
	}
	if(opt>0&&opt<3)
	{
			return opt;
	}
	else
	{
		SetConsoleTextAttribute(h,12);
		cout<<"\t\t\t\t\t\tINVALID INPUT!!"<<endl<<endl;
		SetConsoleTextAttribute(h,15);
		goto option;
	}
	system("cls");

}
double food_price(int opt2,int qty) // price
{
	double price,p_pizza=800,burger=600,chicken_rice=300,kottu=550,noodles=200,sandwich=300,biriyani=600;
	if(opt2==1)
	{
		price=p_pizza*qty;	
	}
	else if(opt2==2)
	{
		price=burger*qty;	
	}
	else if(opt2==3)
	{
		price = chicken_rice*qty;	
	}
	else if(opt2==4)
	{
		price = kottu*qty;	
	}
	else if(opt2==5)
	{
		price = noodles*qty;
	}
	else if(opt2==6)
	{
		price = sandwich*qty;	
	}
	else
	{
		price = biriyani*qty;	
	}
	return price;
}
double discount(double f_price) //discount
{
	double disc;
	if(f_price>=5000)
	{
		disc = (f_price*10)/100;
	}
	else if(f_price>=2500)
	{
		disc = (f_price*5)/100;
	}
	else
	{
		disc = 0;
	}
	return disc;	
}
string food_name(int opt2) //food name
{
	string name;
	if(opt2==1)
	{
		name = "PIZZA\t";
	}
	else if(opt2==2)
	{
		name = "BURGER\t";
	}
	else if(opt2==3)
	{
		name = "FRIED-RICE\t";
	}
	else if(opt2==4)
	{
		name = "KOTTU\t";
	}
	else if(opt2==5)
	{
		name = "NOODLES\t";
	}
	else if(opt2==6)
	{
		name = "SANDWICH\t";
	}
	else
	{
		name = "BIRIYANI\t";
	}
	return name;
}
void load()
{
	cout<<"\n\n";
	cout<<"\t\t\t\t\tGENERATING BILL ";
	char x=219;
	SetConsoleTextAttribute(h,10);
	for(int ii=0; ii<30; ii++)
	{
		Sleep(40);
		cout<<x;
	}
}
//Generate Bill
void bill(double price[],string food[],int quant[],double sum,int count1,double disc,double balance,double cash,int od_num)
{
	fstream myfile;
	time_t nowuptime=time(0);
	char*date=ctime(&nowuptime);
	double tot = sum-disc;
	
	myfile.open("bill.txt");
	myfile<<"\t\t\t\t############################################################"<<endl<<endl;
	myfile<<"\t\t\t\t\t\tFAST-FOODS RESTAURANT"<<endl<<endl;
	myfile<<"\t\t\t\t\t\tNO 17, Matale."<<endl;
	myfile<<"\t\t\t\t\t\tTP :- 081-2345678"<<endl<<endl;
	myfile<<"\t\t\t\t  ORDER NUMBER  :- "<<od_num<<endl;
	myfile<<"\t\t\t\t  DATE & TIME\t:-\t"<<date<<endl;
	myfile<<"\t\t\t\t  ITEM NAME\tQUANTITY\tUNIT PRICE\tTOTAL"<<endl;
	myfile<<"\t\t\t\t  __________\t__________\t__________\t________"<<endl<<endl;
	for(int j=0;j<count1; j++)
	{
		myfile<<"\t\t\t\t  "<<j+1<<") "<<food[j]<<"\t"<<quant[j]<<fixed<<setprecision(2)<<"\tRs "<<price[j]/quant[j]<<"\tRs "<<price[j]<<endl;
	}
	myfile<<"\t\t\t\t----------------------------------------------------------"<<endl;
	myfile<<fixed<<setprecision(2)<<"\t\t\t\t\tTOTAL PRICE\t"<<"\t:\tRs "<<sum<<endl;
	if(disc>0)
	{
	
		myfile<<fixed<<setprecision(2)<<"\t\t\t\t\tDISCOUNT PRICE\t"<<"\t:\tRs "<<disc<<endl;
	}
	else
	{
		SetConsoleTextAttribute(h,12);
		myfile<<"\t\t\t\t\tDISCOUNT PRICE\t"<<"\t:\tNOT AVAILABLE!!"<<endl;
		SetConsoleTextAttribute(h,15);
	}
	myfile<<"\t\t\t\t==========================================================="<<endl;
	myfile<<fixed<<setprecision(2)<<"\t\t\t\t\tGRAND TOTAL\t"<<"\t:\tRs "<<tot<<endl;
	myfile<<"\t\t\t\t==========================================================="<<endl<<endl;
	myfile<<fixed<<setprecision(2)<<"\t\t\t\t\t\tPAID\t"<<"\t:\tRs "<<cash<<endl;
	myfile<<fixed<<setprecision(2)<<"\t\t\t\t\t\tBALANCE\t"<<"\t:\tRs "<<balance<<endl;
	myfile<<"\t\t\t\t----------------------------------------------------------"<<endl<<endl;
	myfile<<"\t\t\t\t\t\t~ T H A N K | Y O U !! ~"<<endl<<endl;
	myfile<<"\t\t\t\t############################################################"<<endl<<endl;
	sleep(3);
	myfile.close();
	string mytext1;
	ifstream MyReadFile("bill.txt");
	while (getline(MyReadFile,mytext1))
	{
		cout<<mytext1<<endl;
	}
	cout<<endl<<endl;
	MyReadFile.close();
}
void clean() //clear txt file
{
	ofstream myfile;
	myfile.open("bill.txt",ofstream::out|ofstream::trunc);
	myfile.close();
}
int main()
{
	int i=0,qty,count=0,opt1,order_number=7100,opt2,quantity[100];
	double f_price,f_disc,sum=0,cash,balance,remain,total,price[100],temp=0,pay=0;
	string f_name,foods[100]; 
	string ans;
	start:
	SetConsoleTextAttribute(h,15);
	system("cls");
	opt1 = opt_menu();
	switch(opt1)
		{
			case 1:
				system("cls");
				c_start:
				clean();
				//food_menu();
				SetConsoleTextAttribute(h,15);
				cout<<endl;
				again:
				do
				{
					system("cls");
					food_menu();
					cout<<endl;
					option:
					cout<<"\t\t\t\tSELECT YOUR FOOD OPTION\t\t:\t";
					cin>>opt2;
					while(cin.fail())
					{
						cin.clear();
						cin.ignore(INT_MAX,'\n');
						SetConsoleTextAttribute(h,12);
						cout<<"\t\t\t\t\t\tPLEASE SELECT CORRECT OPTION!!"<<endl<<endl;
						SetConsoleTextAttribute(h,15);
						goto option;
					}
					if(opt2>0&&opt2<8)
					{	
						if(opt2==1)
						{
							qty1:
							cout<<"\t\t\t\tENTER QUANTITY (MAX-50)\t\t:\t";
							cin>>qty;
							while(cin.fail())
							{
								cin.clear();
								cin.ignore(INT_MAX,'\n');
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty1;
							}
							if(qty>0&&qty<=50)
							{
								f_price = food_price(opt2,qty);
								price[i]=f_price;
								quantity[i] = qty;
								sum+=price[i];
								f_name = food_name(opt2);
								foods[i] = f_name;	
							}
							else
							{
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty1;	
							}
						}
						else if(opt2==2)
						{
							qty2:
							cout<<"\t\t\t\tENTER QUANTITY (MAX-50)\t\t:\t";
							cin>>qty;
							while(cin.fail())
							{
								cin.clear();
								cin.ignore(INT_MAX,'\n');
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty2;
							}
							if(qty>0&&qty<=50)
							{
								f_price = food_price(opt2,qty);
								price[i]=f_price;
								quantity[i] = qty;
								sum+=price[i];
								f_name = food_name(opt2);
								foods[i] = f_name;
							}
							else
							{
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty2;	
							}
							
						}
						else if(opt2==3)
						{
							qty3:
							cout<<"\t\t\t\tENTER QUANTITY (MAX-50)\t\t:\t";
							cin>>qty;
							while(cin.fail())
							{
								cin.clear();
								cin.ignore(INT_MAX,'\n');
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty3;
							}
							if(qty>0&&qty<=50)
							{
								f_price = food_price(opt2,qty);
								price[i]=f_price;
								quantity[i] = qty;
								sum+=price[i];
								f_name = food_name(opt2);
								foods[i] = f_name;
							}
							else
							{
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty3;	
							}
						}
						else if(opt2==4)
						{
							qty4:
							cout<<"\t\t\t\tENTER QUANTITY (MAX-50)\t\t:\t";
							cin>>qty;
							while(cin.fail())
							{
								cin.clear();
								cin.ignore(INT_MAX,'\n');
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty4;
							}
							if(qty>0&&qty<=50)
							{
								f_price = food_price(opt2,qty);
								price[i]=f_price;
								quantity[i] = qty;
								sum+=price[i];
								f_name = food_name(opt2);
								foods[i] = f_name;
							}
							else
							{
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty4;	
							}
						}
						else if(opt2==5)
						{
							qty5:
							cout<<"\t\t\t\tENTER QUANTITY (MAX-50)\t\t:\t";
							cin>>qty;
							while(cin.fail())
							{
								cin.clear();
								cin.ignore(INT_MAX,'\n');
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty5;
							}
							if(qty>0&&qty<=50)
							{
								f_price = food_price(opt2,qty);
								price[i]=f_price;
								quantity[i] = qty;
								sum+=price[i];
								f_name = food_name(opt2);
								foods[i] = f_name;
							}
							else
							{
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty5;	
							}
						}
						else if(opt2==6)
						{
							qty6:
							cout<<"\t\t\t\tENTER QUANTITY (MAX-50)\t\t:\t";
							cin>>qty;
							while(cin.fail())
							{
								cin.clear();
								cin.ignore(INT_MAX,'\n');
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty6;
							}
							if(qty>0&&qty<=50)
							{
								f_price = food_price(opt2,qty);
								price[i]=f_price;
								quantity[i] = qty;
								sum+=price[i];
								f_name = food_name(opt2);
								foods[i] = f_name;
							}
							else
							{
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty6;	
							}
						}
						else if(opt2==7)
						{
							qty7:
							cout<<"\t\t\t\tENTER QUANTITY (MAX-50)\t\t:\t";
							cin>>qty;
							while(cin.fail())
							{
								cin.clear();
								cin.ignore(INT_MAX,'\n');
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty7;
							}
							if(qty>0&&qty<=50)
							{
								f_price = food_price(opt2,qty);
								price[i]=f_price;
								quantity[i] = qty;
								sum+=price[i];
								f_name = food_name(opt2);
								foods[i] = f_name;
							}
							else
							{
								SetConsoleTextAttribute(h,12);
								cout<<"\t\t\t\t\t\tPLEASE ENTER VALID QUANTITY!!"<<endl<<endl;
								SetConsoleTextAttribute(h,15);
								goto qty7;	
							}
						}
						cout<<endl;
						SetConsoleTextAttribute(h,10);
						cout<<"\t\t\t\t\tSUCCESSFULLY ADDED TO BILL!!"<<endl<<endl;
						SetConsoleTextAttribute(h,15);
						cout<<"\t\t\t\t================|YOUR ORDER |======================="<<endl<<endl;
						cout<<"\t\t\t\t\t"<<foods[i]<<" -\t"<<quantity[i]<<" -\t RS "<<price[i]<<endl;
						cout<<"\t\t\t\t===================================================="<<endl<<endl;
						SetConsoleTextAttribute(h,15);
						ask:
						cout<<"\t\t\t\tWOULD YOU LIKE TO ORDER ANYTHING ELSE?(Y/N)\t:\t";
						cin>>ans;
						if(ans=="y"||ans=="Y")
						{
							ans = "y";
						}
						else if(ans=="n"||ans=="N")
						{
							ans = "n";
						}
						else
						{
							SetConsoleTextAttribute(h,12);
							cout<<"\t\t\t\t\t\tINVALID INPUT!!"<<endl<<endl;
							SetConsoleTextAttribute(h,15);
							goto ask;
						}
					}
					else
					{
						SetConsoleTextAttribute(h,12);
						cout<<"\t\t\t\t\t\tPLEASE SELECT CORRECT OPTION!!"<<endl<<endl;
						SetConsoleTextAttribute(h,15);
						goto option;
					}
				i++;
				count++;
				}while(ans=="y"||ans=="Y");
				cout<<endl<<endl;
				SetConsoleTextAttribute(h,9);
				cout<<"\t\t\t======================| ORDER DETAILS |=========================="<<endl<<endl;
				for(int b=0; b<count; b++)
				{
						cout<<"\t\t\t  "<<b+1<<")"<<foods[b]<<"\t\t-\t"<<quantity[b]<<"\t-\t RS "<<price[b]<<endl;
				}
				cout<<"\t\t\t=================================================================="<<endl<<endl;
				f_disc = discount(sum);
				total= sum-f_disc;
				//SetConsoleTextAttribute(h,9);
				cout<<"\t\t\t\t\t==========|| TOTAL ||============"<<endl<<endl;
				cout<<"\t\t\t\t\tTOTAL PRICE\t:\tRs "<<total<<endl;
				cout<<"\t\t\t\t\t================================="<<endl;
				SetConsoleTextAttribute(h,15);
				check:
				cout<<"\t\t\t\t\tENTER CASH\t:\tRs ";
				cin>>cash;
				while(cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX,'\n');
					SetConsoleTextAttribute(h,12);
					cout<<"\t\t\t\t\t\tPLEASE ENTER VALID AMOUNT!!"<<endl<<endl;
					SetConsoleTextAttribute(h,15);
					goto check;
				}
				if(cash>=0)
				{
					pay+=cash;
					if(pay>=total)
					{
						balance = pay-total;
					}
					else
					{
						double temp = total-pay;
						SetConsoleTextAttribute(h,12);
						cout<<"\t\t\t\t\tUNSUFFICENT AMOUNT!! PAY MORE:- Rs "<<temp<<endl<<endl;
						SetConsoleTextAttribute(h,15);
						goto check;
					}
					
				}
				else
				{
					SetConsoleTextAttribute(h,12);
					cout<<"\t\t\t\t\t\tUNSUFFICENT CASH!!"<<endl<<endl;
					SetConsoleTextAttribute(h,15);
					goto check;
				}
				cout<<endl<<endl;
				SetConsoleTextAttribute(h,10);
				cout<<"\t\t\t\t\tORDER PLACED SUCCESSFULLY(_/)"<<endl<<endl;
				sleep(1);
				SetConsoleTextAttribute(h,15);
				load();
				cout<<endl<<endl;
				SetConsoleTextAttribute(h,15);
				bill(price,foods,quantity,sum,count,f_disc,balance,pay,order_number);
				sum-=sum;
				i-=i;
				count-=count;
				cash-=cash;
				pay-=pay;
				temp-=temp;
				order_number++;
				cout<<endl;
				ask1:
				cout<<"\t\t\t\tSTART NEW ORDER?(Y/N)\t:\t";
				cin>>ans;
				if(ans=="y"||ans=="Y")
				{
					system("cls");
					goto c_start;
				}
				else if(ans=="n"||ans=="N")
				{
					goto start;
				}
				else
				{
					SetConsoleTextAttribute(h,12);
					cout<<"\t\t\t\t\t\tINVALID INPUT!!"<<endl<<endl;
					SetConsoleTextAttribute(h,15);
					goto ask1;
				}
				break;
			case 2:
				system("cls");
				break;
			default:
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				SetConsoleTextAttribute(h,12);
				cout<<"\t\t\t\t\t\tPLEASE SELECT CORRECT OPTION!!"<<endl<<endl;
				SetConsoleTextAttribute(h,15);
				sleep(2);
				system("cls");
				goto start;
				break;
		}
}