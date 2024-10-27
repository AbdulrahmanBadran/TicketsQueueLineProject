#include <iostream>
#include<string>

#include "ticketsQueue.h"

using namespace std;

int main()
{
   
	clsQueueLine PayBill("A0",10);

	PayBill.IssueTicket();
	PayBill.IssueTicket();
	PayBill.IssueTicket();
	PayBill.IssueTicket();
	

	PayBill.PrintInfo();

	//PayBill.PrintTicketsLineLTR();
	//PayBill.PrintTicketsLineRTL();

	PayBill.PrintAllTickets();

	PayBill.ServeNextClient();

	PayBill.PrintInfo();

	PayBill.PrintAllTickets();

}



