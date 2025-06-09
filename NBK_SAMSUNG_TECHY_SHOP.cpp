/*Author: Nurhalini Binti Kamarudin
*Date: 20 June 2024
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct OrderDetails {
    string device;
    double devicePrice;
    int amount;
    string colour;
    string accessory;
    double accessoryPrice;
    double totalPrice;
};

// Function prototypes
void setTablet();
void setPhone();
void accessoryTablet(string code, double &accessory_price, string &accessory);
void accessoryPhone(string code, double &accessory_price, string &accessory);
void purchaseTablet(string code, int &amount, string &colour, double &device_price, double &totalPrice, double &accessory_price, string &accessory, double totalSales[]);
void purchaseSmartphone(string code, int &amount, string &colour, double &device_price, double &totalPrice, double &accessory_price, string &accessory, double totalSales[]);
void confirmOrder(const OrderDetails orders[], int orderCount);
int findHighestSales(const OrderDetails orders[], int orderCount);
void staffMenu(OrderDetails orders[], int &orderCount, double totalSales[], int MAX_PRODUCTS);

int main() {
	system("Color 8B"); // --> Change the Terminal Color to Light Aqua with Grey Background [Limited to certain IDEs]
	const int MAX_PRODUCTS = 5;  // Assuming you have 4 products, adjust as needed
	double totalSales[MAX_PRODUCTS] = {0.0};
    const int MAX_ORDERS = 100;  // Adjust the maximum number of orders as needed
    char choice;
    OrderDetails orders[MAX_ORDERS];
    int orderCount = 0;

    cout << "\t\t\t\t\t";
	cout << "\a\a" << setfill('*') << setw(48) << "NBK Samsung Techy Shop" << setfill('*') << setw(28) << "*\n\n\n" << setfill(' ');
	cout << setw(99) << "\aWelcome to NBK Samsung Techny's homepage!" << endl << endl;
	cout << "\n" <<  setw(122) << "\aNBK Samsung Techy offers a wide range of electronic devices for customers of all ages!" << endl;
	cout << "\n\n" << setw(107) << "\aI am NBKsonic, your friendly AI helper at your service!" << endl << endl;
	
	while (choice != 'c' || choice != 'C'  && choice != 'N' || choice != 'n') {
		
		//The selection below allows the user to choose
		cout << setw(80) << "\aA. e-Catalogue" << endl;
	    cout << setw(79) << "\aB. Staff Menu" << endl;
	    cout << setw(73) << "\aC. Exit" << endl << endl;
	    cout << setw(88.5) << "\aWhat can I do for you? : " ;
	    cin >> choice ;
	    
		if (choice == 'A' || choice == 'a') {
			// Loop to take multiple orders
		    do {
		    	OrderDetails order;
                setTablet();
                cout << "\nAddition Accessories For Tablets (The amounts of tablets will determine the total price of accessories): " << endl;
                cout << "S9 Pen Pro: RM299.00" << endl << endl;

                setPhone();
                cout << "\nAddition Accessories For Smartphones (The amounts of smartphones will determine the total price of accessories): " << endl;
                cout << "S Pen with Air Actions: RM259.00" << endl;

                cout << "Does any of our Samsung devices interest you? Please input the code choice of your device: ";
                cin >> order.device;

                if (order.device == "FE" || order.device == "fe") {
                    order.device = "Galaxy Tab S9 FE";
                    purchaseTablet(order.device, order.amount, order.colour, order.devicePrice, order.totalPrice, order.accessoryPrice, order.accessory, totalSales);
                } else if (order.device == "S9U" || order.device == "s9u") {
                    order.device = "Galaxy Tab S9 Ultra";
                    purchaseTablet(order.device, order.amount, order.colour, order.devicePrice, order.totalPrice, order.accessoryPrice, order.accessory, totalSales);
                } else if (order.device == "S23U" || order.device == "s23u") {
                    order.device = "Galaxy S23 Ultra";
                    purchaseSmartphone(order.device, order.amount, order.colour, order.devicePrice, order.totalPrice, order.accessoryPrice, order.accessory, totalSales);
                } else if (order.device == "S23" || order.device == "s23") {
                    order.device = "Galaxy S23";
                    purchaseSmartphone(order.device, order.amount, order.colour, order.devicePrice, order.totalPrice, order.accessoryPrice, order.accessory, totalSales);
                } else {
                    cout << "Invalid product code! Please enter a valid code. ";
                    return 1;
                }

                orders[orderCount] = order;
                orderCount++;

                cout << endl << setw(102) << "Do you want to place another order? (Y/N): ";
                cin >> choice;

            } while (choice == 'Y' || choice == 'y'); {
            	// Display all orders
				confirmOrder(orders, orderCount);
				cout << endl << endl << setw(106) << "Do you want to continue explore our website? (Y/N): ";
				cin >> choice;
			} 
        } else if (choice == 'B' || choice == 'b') {
            staffMenu(orders, orderCount, totalSales, MAX_PRODUCTS);
            cout << setw(106) << "Do you want to continue exploring our website? (Y/N): ";
            cin >> choice;
			    		
	    } else if (choice == 'C' || choice == 'c') {
			cout << setw(108) << "\aFeel free to browse NBK Samsung Techy's Online Shop again!" << endl << endl;
			cout << setw(86) << "\aHave a good day!";
			return 1;
			
		} else {
			cout << "\n" << setw(80) << "\a505. That's an error." << endl << endl;
			cout << setw(100) << "There was an error. Please try again later" << endl << endl;
			cout << "\n\n\n" << setw(90) << "\aFAQ  |  CUSTOMER SERVICE " << endl << endl;
			cout << setw(93) << "Available 24/7 at (800) 295-9315";
			return 1;
	}
}

    return 0;
}

void setTablet() {
	cout << "TABLET : " << endl;
    string tabletTable[3][8] = {
        {"Name", "\t\tCode", "Display", "\t\tResolution", "\tStorage", "\tBattery", "\tColour", "\t\tPrice"},
        {"Galaxy Tab S9 FE", "FE", "10.9'90Hz LCD", "\t2304 x 1440(WUXGA+)", "128GB/6GB", "8,000mAH", "Black(B)/White (W)", "RM 2,699.00"},
        {"Galaxy Tab S9 Ultra", "S9U", "14.6'Dynamic AMOLED 2X", "2960 x 1848(WQXGA+)", "256GB/12GB", "11,200mAH", "Black(B)/White(W)", "RM 5,999.00"}
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << tabletTable[i][j] << "\t";
        }
        cout << endl;
    }
}

void setPhone() {
	cout << "SMARTPHONE : " << endl;
    string phoneTable[3][8] = {
        {"Name", "\t\tCode", "Display", "\t\tResolution", "\tStorage", "\tBattery", "\tColour", "Price"},
        {"Galaxy S23 Ultra", "S23U", "6.8' Dynamic AMOLED 2X", "3088 x 1440(Quad HD+)", "512GB/12GB", "5,000 mAH", "Cream (C)/Golden (G)", "RM 6,199.00"},
        {"Galaxy S23", "\tS23", "6.1' Dynamic AMOLED 2X", "2340 x 1080 (FHD+)", "256GB/8GB", "3,900 mAH", "Cream (C)/Golden (G)", "RM 3,899.00"}
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << phoneTable[i][j] << "\t";
        }
        cout << endl;
    }
}

void accessoryTablet(string code, double &accessory_price, string &accessory) {
    char accessory_choice;
    cout << "Would you like to add any accessories for " << code << "? \nRDH Samsung Elite offers S9 Pen Pro: RM299!" << endl;
    cout << "Are you interested? (Y/N) : ";
    cin >> accessory_choice;
    if (accessory_choice == 'Y' || accessory_choice == 'y') {
        accessory_price = 299.00;
        accessory = "S9 Pen Pro";
    } else if (accessory_choice == 'N' || accessory_choice == 'n') {
        accessory_price = 0.00;
        accessory = "S9 Pen Pro";
    } else {
        cout << "You put the wrong decision!";
    }
}

void accessoryPhone(string code, double &accessory_price, string &accessory) {
    char accessory_choice;
    cout << "Would you like to add any accessories for " << code << "? \nRDH Samsung Elite offers S Pen with Air Actions for only RM259! ";
    cout << "Are you interested? (Y/N) : ";
    cin >> accessory_choice;
    if (accessory_choice == 'Y' || accessory_choice == 'y') {
        accessory_price = 259.00;
        accessory = "S Pen with Air Actions";
    } else if (accessory_choice == 'N' || accessory_choice == 'n') {
        accessory_price = 0.00;
        accessory = "S Pen with Air Actions";
    } else {
        cout << "You put the wrong decision!";
    }
}

void purchaseTablet(string code, int &amount, string &colour, double &device_price, double &totalPrice, double &accessory_price, string &accessory, double totalSales[]) {
    cout << "\nHow many amounts of " << code << " tablet would you like to purchase? : ";
    cin >> amount;
    cout << "What colour would you choose for " << code << "? Black (B) or White (W). Please input the colour code: ";
    cin >> colour;
    while (colour != "B" && colour != "W" && colour != "b" && colour != "w") {
        cout << "Invalid colour code. Please enter 'B' for Black or 'W' for White: ";
        cin >> colour;
    }
      // Set the device price based on the chosen tablet
    if (code == "Galaxy Tab S9 FE") {
        device_price = 2699.00;
        totalSales[0] += totalPrice;
    } else if (code == "Galaxy Tab S9 Ultra") {
        device_price = 5999.00;
        totalSales[1] += totalPrice;
    }
    accessoryTablet(code, accessory_price, accessory);
    totalPrice = (device_price + accessory_price) * amount + 5.00;
}

void purchaseSmartphone(string code, int &amount, string &colour, double &device_price, double &totalPrice, double &accessory_price, string &accessory, double totalSales[]) {
    cout << "\nHow many amounts of " << code << " smartphone would you like to purchase? : ";
    cin >> amount;
    cout << "What colour would you choose for " << code << "? Cream (C) or Golden (G). Please input the colour code: ";
    cin >> colour;
    while (colour != "C" && colour != "G" && colour != "c" && colour != "g") {
        cout << "Invalid colour code. Please enter 'C' for Cream or 'G' for Golden: ";
        cin >> colour;
    }
       // Set the device price based on the chosen smartphone
    if (code == "Galaxy S23 Ultra") {
        device_price = 6199.00;
        totalSales[2] += totalPrice;
    } else if (code == "Galaxy S23") {
        device_price = 3899.00;
        totalSales[3] += totalPrice;
    }
    accessoryPhone(code, accessory_price, accessory);
    totalPrice = (device_price + accessory_price) * amount + 5.00;
}

void confirmOrder(const OrderDetails orders[], int orderCount) {
	cout << "\n\n\n" << setw(98) << "\aThank you for choosing RDH Samsung Elite!" << endl << endl;
    cout << setw(85) << "All orders details:" << endl << endl;
    

    for (int i = 0; i < orderCount; ++i) {
        cout << "\nOrder " << i + 1 << ":\n";
        cout << setw(77) << "Device: " << orders[i].device << endl;
        cout << setw(80) << "Device Price: RM " << fixed << setprecision(2) << orders[i].devicePrice << endl;
        cout << setw(84) << "Charge of Delivery : Rm 5.00" << endl;
        cout << setw(77) << "Amount: " << orders[i].amount << endl;
        cout << setw(77) << "Accessory: " << orders[i].accessory << endl;
        cout << setw(80) << "Accessory Price: RM " << fixed << setprecision(2) << orders[i].accessoryPrice << endl;
        cout << setw(80) << "Total Price: RM " << fixed << setprecision(2) << orders[i].totalPrice << endl;
    }

    cout << setw(84) << "Have a great day!" << endl;
    cout << setw (92) << "Thank you for shopping with us!" << endl;
}

// Implement function to find the index of the product with the highest sales
int findHighestSales(const double totalSales[], int MAX_PRODUCTS) {
    int highestSalesIndex = 0;

    for (int i = 1; i < MAX_PRODUCTS; ++i) {
        if (totalSales[i] > totalSales[highestSalesIndex]) {
            highestSalesIndex = i;
        }
    }

    return highestSalesIndex;
}


// Implement staff menu function
void staffMenu(OrderDetails orders[], int &orderCount, double totalSales[], int MAX_PRODUCTS) {
    int staffChoice;
    int staffID;

    cout << setw(80) << "Enter Staff ID: ";
    cin >> staffID;

    cout << endl << setw(80) << "Staff Menu:" << endl;
    cout << setw(93) << "1. View Highest Sales of a Product" << endl;
    cout << setw(86) << "2. Return to Main Menu" << endl;
    cout << setw(85) << "Enter your choice: ";
    cin >> staffChoice;

    if (staffChoice == 1) {
        // Find the index of the product with the highest sales
        int highestSalesIndex = findHighestSales(totalSales, MAX_PRODUCTS);

        // Display information about the product with the highest sales
        if (totalSales[highestSalesIndex] > 0) {
            cout << setw(85) << "Highest sales: RM " << fixed << setprecision(2) << totalSales[highestSalesIndex] << endl;
        } else {
            cout << setw(89) << "No sales data available." << endl;
        }
    } else if (staffChoice == 2) {
        // Return to Main Menu
        cout << "Returning to the main menu..." << endl;
    } else {
        cout << "Invalid choice. Please enter a valid option." << endl;
    }
}

