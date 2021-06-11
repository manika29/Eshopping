#include<bits/stdc++.h>
using namespace std;

void ManageAccount();
void ManageShop();
void ShowCart();
void SignUp();
void SignIn();
void Men();
void Women();
void M_Clothing();
void M_Footwear();
void M_Clothing_Discounted();
void M_Footwear_Discounted();
void M_Clothing_NonDiscounted();
void M_Footwear_NonDiscounted();
void W_Clothing();
void W_Footwear();
void W_Clothing_Discounted();
void W_Footwear_Discounted();
void W_Clothing_NonDiscounted();
void W_Footwear_NonDiscounted();
void Display();
void Delete_Record();
void Place_Order();

int main()
{
	int ch;
	while(1){
		cout<<"\n";
		cout<<"\n";
		cout<<"********** Welcome To E-Shopping Portal **********\n\n";
		cout<<"1. Account\n";
		cout<<"2. Shop\n";
		cout<<"3. Show Cart\n";
		cout<<"0. Exit\n";

		cout<<"Please Enter your Choice\n";
		cin>>ch;
		switch(ch){
			case 1: ManageAccount();
			        break;
			case 2: ManageShop();
					break;
			case 3: ShowCart();
					break;
			case 0:	cout<<"\nThanks for using the application\n";
			        return 0;
			default: cout<<"Wrong choice selected";
			         main();
		}

	}
	system("cls");
	return 0;
}

void SignUp(){
	string reguser,regpass,regname,regdob;

	system("cls");
	cout<<"Enter your name : ";
	cin>>regname;
	cout<<"Enter your username : ";
	cin>>reguser;
	cout<<"\nEnter your password : ";
	cin>>regpass;

	ofstream reg("account.txt", ios::app);
	reg<<regname<<' '<<regdob<<' '<<reguser<<' '<<regpass<<endl;
	cout<<"Registeration is Successful\n";
	SignIn();

}

void SignIn(){
	int exist;
	string user,pass,n,u,p;
	system("cls");

	cout<<"Enter the username : ";
	cin>>user;
	cout<<"\nEnter the password : ";
	cin>>pass;

	ifstream input("account.txt");
	while(input>>n>>u>>p){
		if(u==user && p==pass){
			exist=1;
		}

	}
	input.close();
	if(exist==1){
		cin.get();
		Place_Order();
	}
	else{

		cout<<"Sorry,Incorrect Credentials\n";
		cin.get();
		main();
	}

}

void ManageAccount(){
	int ch;
	int back=0;
	system("cls");
		cout<<"********** Please Register or Login to continue **********\n\n";
		cout<<"1. SignUp\n";
		cout<<"2. SignIn\n";
		cout<<"0. Back\n";

		cout<<"Please Enter your Choice\n";
		cin>>ch;
		switch(ch){
			case 1: SignUp();
			        break;
			case 2: SignIn();
					break;
			case 0: main();
		}

}


void Men(){
	int ch;
	system("cls");

		cout<<"********** Men Store **********\n\n";
		cout<<"1. Clothing\n";
		cout<<"2. Footwear\n";
		cout<<"0. Back\n";

		cout<<"Please Enter your Choice\n";
		cin>>ch;
		switch(ch){
			case 1: M_Clothing();
			        break;
			case 2: M_Footwear();
					break;
			case 0: ManageShop();
		}
}

void Women(){
	int ch;
	system("cls");

		cout<<"********** Women Store **********\n\n";
		cout<<"1. Clothing\n";
		cout<<"2. Footwear\n";
		cout<<"0. Back\n";

		cout<<"Please Enter your Choice\n";
		cin>>ch;
		switch(ch){
			case 1: W_Clothing();
			        break;
			case 2: W_Footwear();
					break;
			case 0: ManageShop();
		}
}
void ManageShop(){
	int ch;
	system("cls");

		cout<<"********** Select the Category **********\n\n";
		cout<<"1. Men\n";
		cout<<"2. Women\n";
		cout<<"0. Back\n";
		
		cout<<"Please Enter your Choice\n";
		cin>>ch;
		switch(ch){
			case 1: Men();
			        break;
			case 2: Women();
					break;
			case 0: main();
		}
}


void M_Clothing(){
	int ch;
	system("cls");
		cout<<"********** Select the Category **********\n\n";
		cout<<"1. Discounted Products\n";
		cout<<"2. Non-Discounted Products\n";
		cout<<"0. Back\n";
		
		cout<<"Please Enter your Choice\n";
		cin>>ch;
		switch(ch){
			case 1: M_Clothing_Discounted();
			        break;
			case 2: M_Clothing_NonDiscounted();
					break;
			case 0: main();
		}
}

void M_Footwear(){
	int ch;
	system("cls");

		cout<<"********** Select the Category **********\n\n";
		cout<<"1. Discounted Products\n";
		cout<<"2. Non-Discounted Products\n";
		cout<<"0. Back\n";
		
		cout<<"Please Enter your Choice\n";
		cin>>ch;
		switch(ch){
			case 1: M_Footwear_Discounted();
			        break;
			case 2: M_Footwear_NonDiscounted();
					break;
			case 0: main();
		}
}

void W_Clothing(){
	int ch;
	system("cls");

		cout<<"********** Select the Category **********\n\n";
		cout<<"1. Discounted Products\n";
		cout<<"2. Non-Discounted Products\n";
		cout<<"0. Back\n";
		
		cout<<"Please Enter your Choice\n";
		cin>>ch;
		switch(ch){
			case 1: W_Clothing_Discounted();
			        break;
			case 2: W_Clothing_NonDiscounted();
					break;
			case 0: main();
		}
}

void W_Footwear(){
	int ch;
	system("cls");

		cout<<"********** Select the Category **********\n\n";
		cout<<"1. Discounted Products\n";
		cout<<"2. Non-Discounted Products\n";
		cout<<"0. Back\n";
		
		cout<<"Please Enter your Choice\n";
		cin>>ch;
		switch(ch){
			case 1: W_Footwear_Discounted();
			        break;
			case 2: W_Footwear_NonDiscounted();
					break;
			case 0: main();
		}
}


void M_Clothing_Discounted(){

	int sno,code,mrp,dis;
	string name;
	int price;
	system("cls");

	cout<<"                                   *****  List of Items ***** \n";
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    cout<<"S.No."<<setw(9)<<"NAME"<<setw(17)<<"CODE"<<setw(14)<<"MRP"<<setw(18)<<"DISCOUNT IN %"<<setw(17)<<"FINAL PRICE\n";
    cout<<"-------------------------------------------------------------------------------------------------------------\n";
    ifstream infile;
    infile.open("Clothes_D.txt");
    while(infile>>sno>>name>>code>>mrp>>dis){
    	price=mrp-(dis*mrp)/100;
    	cout<<sno<<setw(15)<<name<<setw(15)<<code<<setw(15)<<mrp<<setw(15)<<dis<<setw(15)<<price<<"\n";
    }
    infile.close();
    cout<<"-------------------------------------------------------------------------------------------------------------\n";    

    int c,p,q;
    char ch='y';
    while(ch=='y' || ch=='Y'){

    	cout<<"Enter the product code : ";
	    cin>>c;
	    cout<<"\nEnter the price of the product : ";
	    cin>>p;
	    cout<<"\nEnter the quantity : ";
	    cin>>q;

	    ofstream ofile("orders.txt",ios::app);
	    ofile<<c<<' '<<p<<' '<<q<<endl;

	    cout<<"The Product is successfully added to the cart\n";	    
	    cout<<"Do you want to continue? (y/n) : ";
	    cin>>ch;
    }

    cout<<"\nDo you want to shop more from another category ? (y/n) : ";
    char ch1;
    cin>>ch1;
    if(ch1=='y')
    	ManageShop();
    else
    	main();
    
}

void M_Clothing_NonDiscounted(){

	int sno,code,price;
	string name;
	system("cls");

	cout<<"                                   *****  List of Items ***** \n";
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    cout<<"S.No."<<setw(9)<<"NAME"<<setw(17)<<"CODE"<<setw(18)<<"FINAL PRICE\n";
    cout<<"-------------------------------------------------------------------------------------------------------------\n";
    ifstream infile;
    infile.open("Clothes_ND.txt");
    while(infile>>sno>>name>>code>>price){
    	cout<<sno<<setw(15)<<name<<setw(15)<<code<<setw(15)<<price<<"\n";
    }
    infile.close();
    cout<<"-------------------------------------------------------------------------------------------------------------\n";   

    int c,p,q;
    char ch='y';
    while(ch=='y' || ch=='Y'){

    	cout<<"Enter the product code : ";
	    cin>>c;
	    cout<<"\nEnter the price of the product : ";
	    cin>>p;
	    cout<<"\nEnter the quantity : ";
	    cin>>q;

	    ofstream ofile("orders.txt",ios::app);
	    ofile<<c<<' '<<p<<' '<<q<<endl;

	    cout<<"The Product is successfully added to the cart\n";	    
	    cout<<"Do you want to continue? (y/n) : ";
	    cin>>ch;
    }

    cout<<"\nDo you want to shop more from another category ? (y/n) : ";
    char ch1;
    cin>>ch1;
    if(ch1=='y')
    	ManageShop();
    else
    	main(); 
    
}

void M_Footwear_Discounted(){

	int sno,code,mrp,dis;
	string name;
	int price;
	system("cls");

	cout<<"                                   *****  List of Items ***** \n";
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    cout<<"S.No."<<setw(9)<<"NAME"<<setw(17)<<"CODE"<<setw(14)<<"MRP"<<setw(18)<<"DISCOUNT IN %"<<setw(17)<<"FINAL PRICE\n";
    cout<<"-------------------------------------------------------------------------------------------------------------\n";
    ifstream infile;
    infile.open("Footwear_D.txt");
    while(infile>>sno>>name>>code>>mrp>>dis){
    	price=mrp-(dis*mrp)/100;
    	cout<<sno<<setw(15)<<name<<setw(15)<<code<<setw(15)<<mrp<<setw(15)<<dis<<setw(15)<<price<<"\n";
    }
    infile.close();
    cout<<"-------------------------------------------------------------------------------------------------------------\n";    
    
    int c,p,q;
    char ch='y';
    while(ch=='y' || ch=='Y'){

    	cout<<"Enter the product code : ";
	    cin>>c;
	    cout<<"\nEnter the price of the product : ";
	    cin>>p;
	    cout<<"\nEnter the quantity : ";
	    cin>>q;

	    ofstream ofile("orders.txt",ios::app);
	    ofile<<c<<' '<<p<<' '<<q<<endl;

	    cout<<"The Product is successfully added to the cart\n";	    
	    cout<<"Do you want to continue? (y/n) : ";
	    cin>>ch;
    }

    cout<<"\nDo you want to shop more from another category ? (y/n) : ";
    char ch1;
    cin>>ch1;
    if(ch1=='y')
    	ManageShop();
    else
    	main();
}

void M_Footwear_NonDiscounted(){

	int sno,code;
	string name;
	int price;
	system("cls");

	cout<<"                                   *****  List of Items ***** \n";
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    cout<<"S.No."<<setw(9)<<"NAME"<<setw(17)<<"CODE"<<setw(18)<<"FINAL PRICE\n";
    cout<<"-------------------------------------------------------------------------------------------------------------\n";
    ifstream infile;
    infile.open("Footwear_ND.txt");
    while(infile>>sno>>name>>code>>price){
    	cout<<sno<<setw(15)<<name<<setw(15)<<code<<setw(15)<<price<<"\n";
    }
    infile.close();
    cout<<"-------------------------------------------------------------------------------------------------------------\n";   

    int c,p,q;
    char ch='y';
    while(ch=='y' || ch=='Y'){

    	cout<<"Enter the product code : ";
	    cin>>c;
	    cout<<"\nEnter the price of the product : ";
	    cin>>p;
	    cout<<"\nEnter the quantity : ";
	    cin>>q;

	    ofstream ofile("orders.txt",ios::app);
	    ofile<<c<<' '<<p<<' '<<q<<endl;

	    cout<<"The Product is successfully added to the cart\n";	    
	    cout<<"Do you want to continue? (y/n) : ";
	    cin>>ch;
    } 

    cout<<"\nDo you want to shop more from another category ? (y/n) : ";
    char ch1;
    cin>>ch1;
    if(ch1=='y')
    	ManageShop();
    else
    	main();
    
}

void W_Clothing_Discounted(){

	int sno,code,mrp,dis;
	string name;
	int price;
	system("cls");

	cout<<"                                   *****  List of Items ***** \n";
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    cout<<"S.No."<<setw(9)<<"NAME"<<setw(17)<<"CODE"<<setw(14)<<"MRP"<<setw(18)<<"DISCOUNT IN %"<<setw(17)<<"FINAL PRICE\n";
    cout<<"-------------------------------------------------------------------------------------------------------------\n";
    ifstream infile;
    infile.open("Clothes_D.txt");
    while(infile>>sno>>name>>code>>mrp>>dis){
    	price=mrp-(dis*mrp)/100;
    	cout<<sno<<setw(15)<<name<<setw(15)<<code<<setw(15)<<mrp<<setw(15)<<dis<<setw(15)<<price<<"\n";
    }
    infile.close();
    cout<<"-------------------------------------------------------------------------------------------------------------\n";    

    int c,p,q;
    char ch='y';
    while(ch=='y' || ch=='Y'){

    	cout<<"Enter the product code : ";
	    cin>>c;
	    cout<<"\nEnter the price of the product : ";
	    cin>>p;
	    cout<<"\nEnter the quantity : ";
	    cin>>q;

	    ofstream ofile("orders.txt",ios::app);
	    ofile<<c<<' '<<p<<' '<<q<<endl;

	    cout<<"The Product is successfully added to the cart\n";	    
	    cout<<"Do you want to continue? (y/n) : ";
	    cin>>ch;
    }

    cout<<"\nDo you want to shop more from another category ? (y/n) : ";
    char ch1;
    cin>>ch1;
    if(ch1=='y')
    	ManageShop();
    else
    	main();
    
}

void W_Clothing_NonDiscounted(){

	int sno,code,price;
	string name;
	system("cls");

	cout<<"                                   *****  List of Items ***** \n";
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    cout<<"S.No."<<setw(9)<<"NAME"<<setw(17)<<"CODE"<<setw(18)<<"FINAL PRICE\n";
    cout<<"-------------------------------------------------------------------------------------------------------------\n";
    ifstream infile;
    infile.open("Clothes_ND.txt");
    while(infile>>sno>>name>>code>>price){
    	cout<<sno<<setw(15)<<name<<setw(15)<<code<<setw(15)<<price<<"\n";
    }
    infile.close();
    cout<<"-------------------------------------------------------------------------------------------------------------\n";   

    int c,p,q;
    char ch='y';
    while(ch=='y' || ch=='Y'){

    	cout<<"Enter the product code : ";
	    cin>>c;
	    cout<<"\nEnter the price of the product : ";
	    cin>>p;
	    cout<<"\nEnter the quantity : ";
	    cin>>q;

	    ofstream ofile("orders.txt",ios::app);
	    ofile<<c<<' '<<p<<' '<<q<<endl;

	    cout<<"The Product is successfully added to the cart\n";	    
	    cout<<"Do you want to continue? (y/n) : ";
	    cin>>ch;
    }

    cout<<"\nDo you want to shop more from another category ? (y/n) : ";
    char ch1;
    cin>>ch1;
    if(ch1=='y')
    	ManageShop();
    else
    	main(); 
    
}

void W_Footwear_Discounted(){

	int sno,code,mrp,dis;
	string name;
	int price;
	system("cls");

	cout<<"                                   *****  List of Items ***** \n";
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    cout<<"S.No."<<setw(9)<<"NAME"<<setw(17)<<"CODE"<<setw(14)<<"MRP"<<setw(18)<<"DISCOUNT IN %"<<setw(17)<<"FINAL PRICE\n";
    cout<<"-------------------------------------------------------------------------------------------------------------\n";
    ifstream infile;
    infile.open("Footwear_D.txt");
    while(infile>>sno>>name>>code>>mrp>>dis){
    	price=mrp-(dis*mrp)/100;
    	cout<<sno<<setw(15)<<name<<setw(15)<<code<<setw(15)<<mrp<<setw(15)<<dis<<setw(15)<<price<<"\n";
    }
    infile.close();
    cout<<"-------------------------------------------------------------------------------------------------------------\n";  

    int c,p,q;
    char ch='y';
    while(ch=='y' || ch=='Y'){

    	cout<<"Enter the product code : ";
	    cin>>c;
	    cout<<"\nEnter the price of the product : ";
	    cin>>p;
	    cout<<"\nEnter the quantity : ";
	    cin>>q;

	    ofstream ofile("orders.txt",ios::app);
	    ofile<<c<<' '<<p<<' '<<q<<endl;

	    cout<<"The Product is successfully added to the cart\n";	    
	    cout<<"Do you want to continue? (y/n) : ";
	    cin>>ch;
    } 

    cout<<"\nDo you want to shop more from another category ? (y/n) : ";
    char ch1;
    cin>>ch1;
    if(ch1=='y')
    	ManageShop();
    else
    	main(); 
    
}

void W_Footwear_NonDiscounted(){

	int sno,code;
	string name;
	int price;
	system("cls");

	cout<<"                                   *****  List of Items ***** \n";
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    cout<<"S.No."<<setw(9)<<"NAME"<<setw(17)<<"CODE"<<setw(18)<<"FINAL PRICE\n";
    cout<<"-------------------------------------------------------------------------------------------------------------\n";
    ifstream infile;
    infile.open("Footwear_ND.txt");
    while(infile>>sno>>name>>code>>price){
    	cout<<sno<<setw(15)<<name<<setw(15)<<code<<setw(15)<<price<<"\n";
    }
    infile.close();
    cout<<"-------------------------------------------------------------------------------------------------------------\n";   

    int c,p,q;
    char ch='y';
    while(ch=='y' || ch=='Y'){

    	cout<<"Enter the product code : ";
	    cin>>c;
	    cout<<"\nEnter the price of the product : ";
	    cin>>p;
	    cout<<"\nEnter the quantity : ";
	    cin>>q;

	    ofstream ofile("orders.txt",ios::app);
	    ofile<<c<<' '<<p<<' '<<q<<endl;

	    cout<<"The Product is successfully added to the cart\n";	    
	    cout<<"Do you want to continue? (y/n) : ";
	    cin>>ch;
    }

    cout<<"\nDo you want to shop more from another category ? (y/n) : ";
    char ch1;
    cin>>ch1;
    if(ch1=='y')
    	ManageShop();
    else
    	main(); 
    
}

void ShowCart(){
	system("cls");

		cout<<"1. Display all Records\n";
		cout<<"2. Delete Record\n";
		cout<<"3. Place Order\n";
		cout<<"0. Back\n";

		int ch;
		cout<<"Enter you choice : ";
		cin>>ch;

		switch(ch){
			case 1: Display();
			        break;
			case 2: Delete_Record();
					break;
			case 3: ManageAccount();
					break;
			case 0: main();
		}
}

void Display(){
	system("cls");
	int co,pr,qty;

	cout<<"                                   *****  List of Items ***** \n";
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    cout<<"ITEM CODE"<<setw(9)<<"PRICE"<<setw(17)<<"QUANTITY\n";
    cout<<"-------------------------------------------------------------------------------------------------------------\n";
    ifstream ifile;
    ifile.open("orders.txt");
    while(ifile>>co>>pr>>qty){
    	cout<<co<<setw(15)<<pr<<setw(15)<<qty<<"\n";
    }
    ifile.close();
    cout<<"-------------------------------------------------------------------------------------------------------------\n"; 

    cout<<"Do you want to place order ? (y/n) : ";
    char ch;
    cin>>ch;
    if(ch=='y')
    	ManageAccount();
    else
    	main();
    
}
void Delete_Record(){
	int flag = 0;
	int c,p,q;
	int code;
	system("cls");

	cout<<"Enter the code of the product you want to delete : ";
	cin>>code;

	ifstream ifs;
    ifs.open("orders.txt", ios::in);
  
    ofstream ofs;
    ofs.open("temp.txt", ios::out);
  
    while (ifs>>c>>p>>q) {
    	
    	if(c==code)
    		flag=1;
    	else
    		ofs<<c<<' '<<p<<' '<<q<<endl;


    }

    ofs.close();
    ifs.close();
  
    // delete the old file
    remove("orders.txt");
  
    // rename new file to the older file
    rename("temp.txt", "orders.txt");

    if(flag==1)
    	cout<<"The record has been successfully deleted ";
    else
    	cout<<"\nRecord not found";

}


 void Place_Order(){
 	system("cls");
 	cout<<"Welcome!"<<"\n";
	int co,pr,qty;
	int sum=0;

	cout<<"                                   *****  Your Order ***** \n";
    cout<<"------------------------------------------------------------------------------------------------------------\n";
    cout<<"ITEM CODE"<<setw(9)<<"PRICE"<<setw(17)<<"QUANTITY\n";
    cout<<"-------------------------------------------------------------------------------------------------------------\n";
    ifstream ifile;
    ifile.open("orders.txt");
    while(ifile>>co>>pr>>qty){
    	sum=sum+pr*qty;
    	if(co==101 || co==102 || co==103 || co==104 || co==105){
    	if(pr<1000){
    		for(int i=0; i<qty; i++){
    			sum+= (5*pr)/100;
    		}
    		
    	}
    	else {
    		for(int i=0; i<qty; i++){
     		sum+= (12*pr)/100;
   			
    		}
    	}
    		
    }

    if(co==111 || co==112 || co==113 || co==114 || co==115){
    	if(pr<500){
    		for(int i=0; i<qty; i++){
    			sum+= (5*pr)/100;
    		}
    		
    	}
    	else {
    		for(int i=0; i<qty; i++){
     		sum+= (18*pr)/100;
   			
    		}
    	}
    		
    }


    	cout<<co<<setw(15)<<pr<<setw(15)<<qty<<"\n";
    }   
    cout<<"-------------------------------------------------------------------------------------------------------------\n";   
    cout<<"\n";

 char ch;
 cout<<"Your Total Bill after adding GST is : "<<sum<<"\n";
 cout<<"Would you like to confirm order - ? ";
 cin>>ch;
 if(ch=='y'){
 	cout<<"Your Order has been successfully placed\n";
 	cout<<"Thankyou for Shopping with us";
 }
 else
 	cout<<"Order cancelled";

}
 	
 
