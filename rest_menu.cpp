#include <iostream>
#include <cstring>
#include <stdlib.h>

#define CONTINUE 1
#define CANCEL -1
#define PLACE_ORDER 0

using namespace std;

//Array for maintaining the no. of deals for each item
int no_del_ord[6] = {0};

/* Function to maintain the order in the no. of deals array */
void order_maintain(int order, int deals){

    no_del_ord[order - 1] = no_del_ord[order - 1] + deals;
    return;
}

/*Display menu Function*/
void menu_display(){

    cout << "*-------------------------MENU-------------------------*" << endl;
    cout << endl;
    cout << "(1) Chicken Palao\t\t\tRs.80 only." << endl;
    cout << "(2) Chicken Burgar\t\t\tRs.100 only." << endl;
    cout << "(3) Chicken Rice\t\t\tRs.110 only." << endl;
    cout << "(4) Chicken Briyani\t\t\tRs.120 only." << endl;
    cout << "(5) Nawabi Pizza\t\t\tRs.300 only." << endl;
    cout << "(6) 2.5 Litre Coke\t\t\tRs.150 only." << endl;
    cout << endl;

    return;

}

int main(){

    int order, no_deals, total_bill = 0;
    unsigned short status = 1;
    string con_opt;

    /* Loop to iterate for the user order */
    while(status == CONTINUE)
    {
	system("clear");
	menu_display();

	cout << "Please select the order number: ";
	cin >> order;

	cout << "Please enter the number of deals: ";
	cin >> no_deals;

	cout << endl;

	order_maintain(order, no_deals);
opt_menu:

	/*Continue Option*/
	cout << "Would you like to order anything else..? y/n: ";
	cin >> con_opt;

	if(con_opt == "yes" || con_opt == "y" || con_opt == "Y")
	    status = CONTINUE;
	else if(con_opt == "no" || con_opt == "n" || con_opt == "N")
	    status = PLACE_ORDER;
	else
	    goto opt_menu;

    }

    system("clear");
    cout << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~ BILLING PART ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    cout << "S.No  " << "Items\t\t" << "No. of Deals\t" << "Each Price\t"<< "Price" << endl;
    int i,sn = 1;
    for(i = 0;i < 6;i++){
	if(no_del_ord[i] == 0)
	    continue;
	switch(i+1){

	    case 1:

		total_bill += (80 * no_del_ord[0]);
		cout << " " << sn << ".  Chicken Palao\t\t" << no_del_ord[0] << "\tRs.80 only\t" << "Rs." << 80 * no_del_ord[0] << " only." << endl;
		sn++;
		break;

	    case 2:

		total_bill += (100 * no_del_ord[1]);
		cout << " " << sn << ".  Chicken Burgar\t\t" << no_del_ord[1] << "\tRs.100 only." << "\tRs." << 100 * no_del_ord[1] << " only." << endl;
		sn++;
		break;

	    case 3:

		total_bill += (110 * no_del_ord[2]);
		cout << " " << sn << ".  Chicken Rice\t\t" << no_del_ord[2] << "\tRs.110 only." << "\tRs." << 110 * no_del_ord[2] << " only." << endl;
		sn++;
		break;

	    case 4:

		total_bill += (120 * no_del_ord[3]);
		cout << " " << sn << ".  Chicken Briyani\t\t" << no_del_ord[3] << "\tRs.120 only." << "\tRs." << 120 * no_del_ord[3] << " only." << endl;
		sn++;
		break;

	    case 5:

		total_bill += (300 * no_del_ord[4]);
		cout << " " << sn << ".  Nawabi Pizza\t\t" << no_del_ord[4] << "\tRs.300 only." << "\tRs." << 300 * no_del_ord[4] << " only." << endl;
		sn++;
		break;

	    case 6:

		total_bill += (150 * no_del_ord[5]);
		cout << " " << sn << ".  2.5 Litre Coke\t\t";
		cout << no_del_ord[5];
		cout << "\tRs.150 only." << "\tRs." << 150 * no_del_ord[5] << " only." << endl;
		sn++;
		cout << endl;
		break;

	}

    }

    cout << endl;

    cout << "***********************************************************************" << endl;
    cout << "\t\tTotal Bill = " << total_bill << endl;
    cout << "***********************************************************************" << endl;

    cout << endl;
    cout << endl;
    cout << "~~------------------------THANK YOU FOR COMING------------------------~~" << endl;

    return 0;

}
