/************************************************************************
University of Leeds
School of Computing
COMP1711/XJCO1711- Procedural Programming
Coursework 1

I confirm that the following code has been developed and written by me and it is entirely the result of my own work.
I also confirm that I have not copied any parts of this program from another person or any other source or facilitated someone to copy this program from me.
I confirm that I will not publish the program online or share it with anyone without permission of the module leader.

Student Name:
Student ID:
Email:
Date Work Commenced:

*************************************************************************/


// ********************************************************************************************************************
// DO NOT CHANGE ANYTHING IN THE FOLLOWING SECTION. IF YOU CHANGE ANYTHING, YOUR CODE WILL FAIL THE AUTOGRADER TESTS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) // don't change this line
{
	int AUTOGRADING = 0;
	if (argc > 1 && !strcmp(argv[1], "g"))
		AUTOGRADING = 1;

	// the following variables have been defined for you, please use them in your code
	// if you need more variables, you can define them after this section
	// please DO NOT MODIFY the names of these variables as this will cause your program to fail the autograder tests
	short UserChoice;		// the menu choice the user has entered, 1=compute a bill, 2=show sums and statistics, 3=quit the program
	int CustomerType;		// the type of the customer for which a bill is to be computed, 1=domestic, 2=commercial
	int QWaterConsumption;	// the quarterly water consumption of this customer
	double QFreshWaterCharge;	// the quarterly charge for fresh water for this customer
	double QWasteWaterCharge;	// the quarterly charge for waste water for this customer
	double QSurfaceWaterCharge;	// the quarterly charge for surface water for this customer
	double QStandingCharges;	// the quarterly standing charge for this customer
	double QTotalCharge;		// the total of all quarterly charges
	double QVAT;				// the quarterly VAT on all charges, remember that domestic customers don't pay VAT, i.e. VAT = 0
	double QAmountToPay;		// the total amount of the quarterly bill for this customer
	double QTotalFreshWater;	// total amount of fresh water provided to all customers in this quarter
	double QTotalDomestic;	// total amount of fresh water provided to domestic customers in this quarter
	double QRevenue;			// quaretrly revenue made from the sale of water to ALL customers
	double QCost ;			// quaretrly cost of the water provided to ALL customers
	double QProfit;			// quaretrly profit made from the sale of water to ALL customers
	double QIncomeTax;		// the quaretrly income tax that must be paid to the government
	double QAverageDomesticBill;	// the average of all domestic bills in this quarter
	double QMaxDomesticBill;		// the maximum value of a domestic bill in this quarter


// END OF CODE SECTION THAT SHOULD NOT BE CHANGED
// ************************************************

// --------------------------------------------------------------------------------------------------
// NOW IT IS YOUR TURN, YOU CAN DEFINE ANY OTHER VARIABLES YOU MAY NEED BELOW THIS LINE
// YOU WILL ALSO USE THIS SECTION TO INITIALISE ANY VARAIABLES THAT REQUIRE PROPER INITIALISATION

	short int BillNum = 0;
	short int Start = 0;

// END OF SECTION FOR DECLARRING ADDITIONAL VARIABLES AND INITIALISING ANY VARIABLES THAT NEED INITIALISATION
// -----------------------------------------------------------------------------------------------------------


// ******************************************************************************************************************
// DO NOT CHANGE ANYTHING IN THE FOLLOWING SECTION. IF YOU CHANGE ANYTHING, YOUR CODE WILL FAIL THE AUTOGRADER TESTS

	// display the menu and prompt the user to enter a choice
	if (!AUTOGRADING) // do not display the menu if autograding
	{
		printf ("1. Compute and display the bill for a customer\n");
		printf ("2. Display sums and statistics\n");
		printf ("3. Quit the program\n");
	}
	while (1) // repeat forever (or until the user enters 3 for choice)
	{
		if (!AUTOGRADING) // don't show a prompt if autograding
			printf ("\nEnter your choice (1, 2, or 3):");  // prompt the user to enter a menu choice number
		scanf ("%hi", &UserChoice); // read the choice number

		// process the user choice
		switch (UserChoice)
		{
		case 1: // the choice for computing and displaying the bill for one customer
			if (!AUTOGRADING) // don't show the prompt if autograding
				printf ("Enter customer type (1=domestic, 2=commercial):");
			scanf (" %i", &CustomerType);
			if (!AUTOGRADING) // don't process customer type if autograding
			{
				while (CustomerType != 1 && CustomerType != 2)
				{
					printf ("This is not a valid customer type!\nTry again:");
					scanf ("%i", &CustomerType);
				}
			}
			if (!AUTOGRADING) // don't show the prompt if autograding
				printf ("Enter water consumption:");
			scanf ("%i", &QWaterConsumption); // input the quarterly water consumption

// END OF CODE SECTION THAT SHOULD NOT BE CHANGED
// ************************************************

// -------------------------------------------------------------------------------------------
// NOW IT IS YOUR TURN, WRITE BELOW THE CODE FOR COMPUTING THE BILL AND UPDATING CUMULATIVE VALUES

//所有客户消耗的淡水总量
//国内用户消耗的淡水总量
//10英镑固定费用 + 分级处理费 +  废水处理费

	if(Start == 0)//数据初始化 
	{
		Start = 1;
		QFreshWaterCharge = 0;
		QWasteWaterCharge = 0;
		QSurfaceWaterCharge = 0;	// the quarterly charge for surface water for this customer
		QStandingCharges = 0;	// the quarterly standing charge for this customer
	    QTotalCharge = 0;		// the total of all quarterly charges
	    QVAT = 0;				// the quarterly VAT on all charges, remember that domestic customers don't pay VAT, i.e. VAT = 0
	    QAmountToPay = 0;		// the total amount of the quarterly bill for this customer
	    QTotalFreshWater = 0;	// total amount of fresh water provided to all customers in this quarter
	    QTotalDomestic = 0;	// total amount of fresh water provided to domestic customers in this quarter
	    QRevenue = 0;			// quaretrly revenue made from the sale of water to ALL customers
	    QCost = 0;			// quaretrly cost of the water provided to ALL customers
	    QProfit = 0;			// quaretrly profit made from the sale of water to ALL customers
	    QIncomeTax = 0;		// the quaretrly income tax that must be paid to the government
	    QAverageDomesticBill = 0;	// the average of all domestic bills in this quarter
	    QMaxDomesticBill = 0;
	}
 
//其他费用 
    if(CustomerType == 1)//国内用户 
   {
	   	   //分级处理 
	   if(QWaterConsumption <= 5)
	   {
	   		QFreshWaterCharge = QWaterConsumption * 0.20; 
	   }
	   else if(QWaterConsumption>= 6 && QWaterConsumption <= 12)
	   {
	   		QFreshWaterCharge = 1 + (QWaterConsumption - 5) * 0.35;
	   }
	   else if(QWaterConsumption >= 13 && QWaterConsumption <= 25)
	   {
	   		QFreshWaterCharge = 3.45 + (QWaterConsumption - 12) * 0.50;
	   }
	   else if(QWaterConsumption >= 26 && QWaterConsumption <= 40)
	   {
	   		QFreshWaterCharge = 10.95 + (QWaterConsumption - 25) * 0.75;
	   }
	   else if(QWaterConsumption > 40)
	   {
	   		QFreshWaterCharge = 29.7 + (QWaterConsumption - 40) * 2.5;
	   }
   	QStandingCharges = 10 + 0.10 * 91;   //固定处理费
   	QSurfaceWaterCharge = 0;   //地表水费用
   	QWasteWaterCharge =  QWaterConsumption * 0.95 * 0.25;   //废水处理费
   }
   else//国外用户 
   {
   	QFreshWaterCharge = QWaterConsumption * 2.5;
   	QStandingCharges = 1.3 * 91 + 10;   //固定处理费
   	QSurfaceWaterCharge = 50;   //地表水费用
   	QWasteWaterCharge =  QWaterConsumption * 0.95 * 2;   //废水处理费 
   }
   
   QTotalCharge = QFreshWaterCharge + QStandingCharges + QSurfaceWaterCharge + QWasteWaterCharge; //总费用 
   
   //商业版用户还要交税
   if(CustomerType == 2)
   {
   	QVAT = QTotalCharge * 0.2;
   }
   else
   {
   	QVAT = 0;
   }
   
   QAmountToPay = QVAT + QTotalCharge;//加上税收,应该支付的费用 
   if(CustomerType == 1) BillNum++; //用户数量更新，用于计算平均值

//所有账单的收入总额(不包括增值税，因为增值税必须转到政府)
   QTotalFreshWater +=  QWaterConsumption;//本季度向客户提供的淡水总量
   if(CustomerType == 1)//国内用户淡水总量
   {
   	QTotalDomestic += QWaterConsumption;
   } 
   
   QRevenue += QTotalCharge;//因为不包括增值税，所以直接加费用即可
    
//向客户提供水的总成本。假设公司每立方米水的平均成本是1英镑。
//这个价值包括所有的费用，包括新鲜和废水处理，抽水，维护，工资，广告，等等。
   	
   	QCost = QTotalFreshWater * 1.0;//提供多少水就有多少成本 

//公司的利润(或亏损!)记住利润=收入-成本

	QProfit = QRevenue - QCost;//利润 = 收入 - 成本 

//假设所得税税率为25%，公司必须向政府缴纳的所得税

	QIncomeTax = QRevenue * 0.25;
//	QIncomeTax = QProfit * 0.25;

//国内票据的平均价值

	QAverageDomesticBill = QTotalDomestic / BillNum;

//国内汇票的最高金额

	if(CustomerType == 1)
	{
		if(QMaxDomesticBill < QAmountToPay)
		{
			QMaxDomesticBill = QAmountToPay;
		}
	}


// END OF SECTION FOR WRITING YOUR CODE
// -------------------------------------------------------------------------------------------


// *****************************************************************************************************************
// DO NOT CHANGE ANYTHING IN THE FOLLOWING SECTION. IF YOU CHANGE ANYTHING, YOUR CODE WILL FAIL THE AUTOGRADER TESTS

			// THIS IS THE CODE FOR DISPLAYING THE BILL ON THE SCREEN. IT HAS ALREADY BEEN WRITTEN FOR YOU
			if (!AUTOGRADING)
			{
				printf ("\n------------------------------------------\n");
				printf ("Customer Type: ");
				if (CustomerType == 1)
					printf ("Domestic\n");
				else
					printf ("Commercial\n");
				// now let's display the bill
				printf ("Fresh Water Consumption:  %i Cubic Meter\n" , QWaterConsumption);
				printf ("Fresh Water Charge:       %.2f GBP\n", QFreshWaterCharge);
				printf ("Waste Water Charge:       %.2f GBP\n" , QWasteWaterCharge);
				printf ("Surface Water Charge:     %.2f GBP\n", QSurfaceWaterCharge);
				printf ("Standing Charges:         %.2f GBP\n", QStandingCharges);
				printf ("Total Charges:            %.2f GBP\n" , QTotalCharge);
				printf ("VAT:                      %.2f GBP\n" , QVAT);
				printf ("Amount to Pay:            %.2f GBP\n" , QAmountToPay);
				printf ("-------------------------------------------\n\n");
			}
			else
			{
				if (argc == 2 && !strcmp (argv[1],"g"))
				{
					printf ("%d\n" , QWaterConsumption);
					printf ("%.2f\n", QFreshWaterCharge);
					printf ("%.2f\n" , QWasteWaterCharge);
					printf ("%.2f\n", QSurfaceWaterCharge);
					printf ("%.2f\n", QStandingCharges);
					printf ("%.2f\n" , QTotalCharge);
					printf ("%.2f\n" , QVAT);
					printf ("%.2f\n" , QAmountToPay);
				}
			}
			break;
		case 2: // the choice for displaying the sums
			if (!AUTOGRADING)
			{
				printf ("Total Fresh Water Supplied:              %.2f Cubic Meter\n" , QTotalFreshWater);
				printf ("Total Fresh Water to Domestic Customers: %.2f Cubic Meter\n", QTotalDomestic);
				printf ("Total Revenue:                           %.2f GBP\n" , QRevenue);
				printf ("Total Cost:                              %.2f GBP\n" , QCost);
				if (QProfit >= 0)
					printf ("Profit:                                  %.2f GBP\n" , QProfit);
				else
					printf ("Loss:                                    %.2f GBP\n" , QProfit);

				printf ("Income Tax:                              %.2f GBP\n" , QIncomeTax);
				printf ("Maximum Domestic Bill:                   %.2f GBP\n", QMaxDomesticBill);
				printf ("Average Domestic Bill:                   %.2f GBP\n", QAverageDomesticBill);
			}
			else
			{
				if (argc == 3 && (!strcmp (argv[2], "tfw") || !strcmp (argv[2], "all")))
					printf ("%.2f\n" , QTotalFreshWater);
				if (argc > 2 && (!strcmp (argv[2], "tdm") || !strcmp (argv[2], "all")))
					printf ("%.2f\n", QTotalDomestic);
				if (argc > 2 && (!strcmp (argv[2], "rev") || !strcmp (argv[2], "all")))
					printf ("%.2f\n" , QRevenue);
				if (argc > 2 && (!strcmp (argv[2], "cst") || !strcmp (argv[2], "all")))
					printf ("%.2f\n" , QCost);
				if (argc > 2 && (!strcmp (argv[2], "prf") || !strcmp (argv[2], "all")))
					printf ("%.2f\n" , QProfit);
				if (argc > 2 && (!strcmp (argv[2], "tax") || !strcmp (argv[2], "all")))
					printf ("%.2f\n" , QIncomeTax);
				if (argc > 2 && (!strcmp (argv[2], "max") || !strcmp (argv[2], "all")))
					printf ("%.2f\n", QMaxDomesticBill);
				if (argc > 2 && (!strcmp (argv[2], "avg") || !strcmp (argv[2], "all")))
					printf ("%.2f\n", QAverageDomesticBill);
			}
			break;
		case 3:
			exit (0);
		default:
			printf ("not a valid option number");
		}
	}
	return 0;
}

// END OF CODE SECTION THAT SHOULD NOT BE CHANGED
// ***********************************************

//								END OF PROGRAM. DO NOT WRITE ANYTHING BELOW THIS LINE
//==============================================================================
