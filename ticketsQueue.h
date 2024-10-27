#pragma once


#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include "clsDate.h"


using namespace std;


class clsQueueLine {

    string _prefix="";
    short _TotalTicket = 0;
    short _TicketNumber = 0;
    short _PredictedServeTime = 0;
    short _servedClient = 0;

    class clsTicket {

        string _prefix = "";
        short _ClientNumber = 0;
        short _PredictedServeTime = 0;
        short _WaitingClient = 0;
        static short _ServedClient ;
        string _TicketTime;
       

    public:
        clsTicket(string prefix, short ClientNumber,short PredictedServeTime, short WaitingClient)
        {
            clsDate date;

            _prefix = prefix;
            _ClientNumber = ClientNumber;
            _PredictedServeTime = PredictedServeTime;
            _TicketTime = date.GetDateAndTime();
            _WaitingClient = WaitingClient;
           

        }

        string prefix()
        {
            return  _prefix;
        }
       
        short TicketNumber()
        {
            return _ClientNumber;
        }

        short PredictedServeTime()
        {
            return _PredictedServeTime * _WaitingClient;
        }

        int WaitingClient()
        {
             
            return (_ClientNumber - _ServedClient) - 1;

        }

        static void setServedClients(int ServedClients)
        {

            _ServedClient = ServedClients;

        }

        string FullNumber()
        {
            return _prefix + to_string(_ClientNumber);
        }

        short ExpectedServeTime()
        {

            return _PredictedServeTime * WaitingClient();

        }

        string TicketTime()
        {

            return _TicketTime;

        }

        void Print()
        {

            cout << "\n\t\t\t  _______________________\n";
            cout << "\n\t\t\t\t    " << FullNumber();
            cout << "\n\n\t\t\t    " << _TicketTime;
            cout << "\n\t\t\t    Wating Clients = " << WaitingClient();
            cout << "\n\t\t\t      Serve Time In";
            cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
            cout << "\n\t\t\t  _______________________\n";



        }


    };

protected:

    queue<clsTicket> ticketsQueue;

public:

    clsQueueLine(string prefix, short PredictedServeTime)
    {
        _prefix = prefix;
        _PredictedServeTime = PredictedServeTime;

       
    }

    short WaitingClients()
    {

        return ticketsQueue.size();

    }

    void IssueTicket()
    {
        _TicketNumber++;
        _TotalTicket++;

        

        clsTicket ticket(_prefix, _TicketNumber, _PredictedServeTime, WaitingClients());

        ticketsQueue.push(ticket);

    }

    void PrintInfo()
    {
        cout << "\n\t\t\t  _______________________\n";
        cout << "\n\t\t\t       Queue Info\n";
        cout << "\n\t\t\t  _______________________\n";
        cout << "\n\t\t\t\tPrefix=" << _prefix;
        cout << "\n\n\t\t\t    Total Tickets=" << _TotalTicket;
        cout << "\n\t\t\t    Served Clients = " << _servedClient;
        cout << "\n\t\t\t    Wating Clients = " << ticketsQueue.size();
        cout << "\n\t\t\t  _______________________\n";


   }

    void PrintTicketsLineRTL()
    {

        queue<clsTicket>temp = ticketsQueue;

        cout << "\t\t\t\t";

        for (short i = 0; i < ticketsQueue.size(); i++)
        {

            cout  << temp.front().TicketNumber() << "<--";
            temp.pop();
        }
        cout << endl;
    }

    void PrintTicketsLineLTR()
    {

        queue<clsTicket>temp = ticketsQueue;

        stack<clsTicket>Stemp;


        for (short i = 0; i < ticketsQueue.size(); i++)
        {
            Stemp.push(temp.front());
            temp.pop();
        }


        cout << "\t\t\t\t";
        for (short i = 0; i < ticketsQueue.size(); i++)
        {

            cout  <<Stemp.top().TicketNumber() << "-->";
            Stemp.pop();

        }
        cout << endl;
    }

    void PrintTicket(clsTicket ticket)
    {

        short waitingClients = (ticket.TicketNumber() - _servedClient) - 1;
      
        ticket.Print();


    }

    void PrintAllTickets()
    {

        cout << "\n\t\t\t     ---Tickets---\n";

        queue<clsTicket>temp = ticketsQueue;

        while (!temp.empty())
        {

            PrintTicket(temp.front());
            temp.pop();
        }


    }

    void ServeNextClient()
    {

        _servedClient++;
     
        ticketsQueue.pop();
        
        //ticketsQueue.front().setServedClients(_servedClient);
        clsTicket::setServedClients(_servedClient);
    }

};

short clsQueueLine::clsTicket::_ServedClient = 0;

