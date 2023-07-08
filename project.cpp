#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Data.h"
#include "Property.h"
#include <list>
using std::cout;
using std:: cin;
using std::endl;
using std::ofstream;



void removeProperty(std::list<Data>& l)
{
    std::string agentid;
    std::cout << "Enter Agent ID of the property to remove: ";
    std::cin >> agentid;

   
    bool found = false;
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        if (it->getAgentId() == agentid)
        {
            found = true;
            l.erase(it); 
            std::cout << "Property removed successfully!" << std::endl;
            break;
        }
    }

    if (!found)
    {
        std::cout << "No property found with the specified Agent ID." << std::endl;
    }
}





void editSales(std::list<Data> &l)
{
    std::string agentid;
    std::cout << "Enter Agent ID: ";
    std::cin >> agentid;

   
    bool found = false;
    for (auto& data : l)
    {
        if (data.getAgentId() == agentid)
        {
            found = true;
            std::string newSellingPrice;
            std::cout << "Enter new Selling Price: ";
            std::cin >> newSellingPrice;

           
            data.setSellingPrice(newSellingPrice);
            std::cout << "Sales entry updated successfully!" << std::endl;
            break;
        }
    }

    if (!found)
    {
        std::cout << "No property found with the specified Agent ID." << std::endl;
    }
}



void addPropertyAgent(std::list<Data>& l)
{
   string agentid, password;
    cout << "Enter the Agent ID: ";
    cin >> agentid;

    for (auto it = l.begin(); it != l.end(); ++it) {
        if (it->getAgentId() == agentid) {
            cout << "Agent ID " << agentid << " already exists. Aborting." << endl;
            return;
        }
    }

    cout << "Enter the password for Agent " << agentid << ": ";
    cin >> password;

    Data agentData;
    agentData.setAgentId(agentid);
    agentData.setContact(password);

    
    l.push_back(agentData);

    cout << "Agent " << agentid << " has been added successfully." << endl;
}

void removePropertyAgent(std::list<Data>& l)
{
    string agentid;
    cout << "Enter the Agent ID to remove: ";
    cin >> agentid;

    bool found = false;
    for (auto it = l.begin(); it != l.end(); ++it) {
        if (it->getAgentId() == agentid) {
            l.erase(it);
            found = true;
            cout << "Agent " << agentid << " has been removed successfully." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Agent " << agentid << " not found." << endl;
    }
}


void administration(std::list<Data>& l)
{
    char option;
    cout << "Administration Menu" << endl;
    cout << "(a) Add property agent" << endl;
    cout << "(b) Remove property agent" << endl;
    cin >> option;

    switch (option)
    {
        case 'a':
        {
            addPropertyAgent(l);
            break;
        }
        case 'b':
        {
            removePropertyAgent(l);
            break;
        }

		case 'g':
    administration(l);
    break;

        default:
        {
            cout << "Invalid option. Returning to main menu." << endl;
            break;
        }
    }
}











void addProperty(std::list<Data> &l)
{
	Data datos;
	string agentid,contact,size,roomtype,location,sellingprice;
	cout<<"welcome to the propperty adding menu"<<endl;
	
	cout<<"Please insert your Agent ID:"<<endl; 
	cin >> agentid;
	datos.setAgentId(agentid);
	cout<<"please insert your Contact:"<<endl; 
	cin >> contact;
	datos.setContact(contact);
	cout<<"please insert your Property Size:"<<endl; 
	cin >> size;
	datos.setPropertySize(size);
	cout<<"please insert your RoomType:"<<endl; 
	cin >> roomtype;
	datos.setRoomType(roomtype);
	cout<<"please insert your Location:"<<endl; 
	cin >> location;
	datos.setLocation(location);
	cout<<"please insert your Selling Price:"<<endl; 
	cin >> sellingprice;
	datos.setSellingPrice(sellingprice);
	l.push_back(datos);	
}

void OrderList(std::list<Data> &l,char option)
{
	char resp=option;
	do{
		
		if(resp!='a'&&resp!='d')
		{
			cout<<"ERROR, Please be careful"<<endl;
		}	
	}while(resp!='a'&&resp!='d');
	l.sort();
	
	if(resp=='d'){
	l.reverse();
	}
	if (option == 'a' || option == 'd') {
           
            cout << "List of properties:" << endl;
            for (auto it = l.begin(); it != l.end(); ++it) {
                cout << "Agent ID: " << it->getAgentId() << endl;
                cout << "Contact: " << it->getContact() << endl;
                cout << "Property Size: " << it->getPropertySice() << endl;
                cout << "Room Type: " << it->getRoomType() << endl;
                cout << "Location: " << it->getLocation() << endl;
                cout << "Selling Price: " << it->getSellingPrice() << endl;
                cout << endl;
            }
        }
}




bool findpass(string pass, string id)
{	
	string pas,ag;
	bool found=false;
	std::ifstream passwords;
	passwords.open("passwords.in");
	while(!passwords.eof() && !found) 
	{
		passwords>>pas>>ag;
		
	
		if(pass==pas && ag == id)
		{
			found=true;
		
		}
	}
	passwords.close();
	return found;
}

bool login(string agentid,string password )
{
	bool pass,granted =false;
	
	
	
	pass=findpass(password,agentid);
	if(pass)
	{
		
		cout<<"access granted"<<endl;
		granted=true;
		
	}else{
		cout<<"\nLogin Failed!!\n";
	}
	return (granted);
} 




		
		
		



char menu ()
{
	char option;
	
	cout<<"Menu"<<endl;
	cout<<"(a) Add new property"<<endl;
	cout<<"(b) Remove property "<<endl;
	cout<<"(c) Edit sales entries"<<endl;
	cout<<"(d) List property sale items in ascending or descending order"<<endl;
	cout<<"(e) Administration - add / remove property agent"<<endl; 
	
	cout<<"(Q) Quit"<<endl;
	cin>>option;	
	return (option);
}

void load(std::list<Data> l)
{
	Data datos;
	
	int i=0;
	unsigned int encontro,anterior;
	std::string STRING,agentid,contact,size,roomtype,location,sellingprice;
	std::ifstream infile;
	infile.open ("data.in");
	while(!infile.eof()) 
	{
		getline(infile,STRING); 
		encontro = STRING.find(':', 0); 
		if(encontro != std::string::npos )
		{
			agentid = STRING.substr(0, encontro);
			datos.setAgentId(agentid);
			
		} 
		anterior=encontro+1;
		encontro= STRING.find(':', anterior);
		
		if(encontro != std::string::npos )
		{
			contact = STRING.substr(anterior, encontro-anterior);
			datos.setContact(contact);
		} 
		anterior=encontro+1;
		encontro= STRING.find(':', anterior);
		
		if(encontro != std::string::npos )
		{
			size = STRING.substr(anterior, encontro-anterior);
			datos.setPropertySize(size);
		} 
		
		anterior=encontro+1;
		
		encontro= STRING.find(':', anterior+1); 
		
		if(encontro != std::string::npos )
		{
			roomtype = STRING.substr(anterior, encontro-anterior);
			datos.setRoomType(roomtype);
		} 
		
		anterior=encontro+1;
		
		encontro= STRING.find(':', anterior+1); 
		
		if(encontro != std::string::npos )
		{
			location = STRING.substr(anterior, encontro-anterior);
			datos.setLocation(location);
		} 
		
		anterior=encontro+1;
		
		
		
		
		
		sellingprice= STRING.substr(anterior, STRING.length()-anterior);
		datos.setSellingPrice(sellingprice);
		
		l.push_back(datos); 
		
		

		
		
		i++;
	}
	infile.close();
	
	
}

	

void show(std::list<Data> l)
{
	char option;
	
	do{ 
		cout<<"please insert (a) to see the list in ascending order"<<endl;
		cout<<"please insert (d) to see the is in descending order"<<endl;
		cout<<"else for returning to main menu"<<endl;
		cin>>option;
		switch (option)
		{
		case 'a':
OrderList(l,option);
			break;
		case 'd':
OrderList(l,option);
			break;
		default:option=' ';	
		}
		
	}while(option!=' ' &&option !='a' &&option!='b');
	
	
	
	
}

int main()
{
	std::list<Data> l;
	string agentid,password;
	cout<<"please insert your AgentID"<<endl;
	cin>>agentid;
	cout<<" please insert your password"<<endl;
	cin>>password;
	if(login(agentid,password)){
	
	load(l);
	char option ; 
	do{
		option=menu();
		
		switch (option)
		{
		case 'a':
			addProperty(l);
			break;
		case 'b':
		removeProperty(l);
			break;
		case 'c':
		editSales(l);
			break;
		case 'd':
		 show(l);
			break;
		case 'e':
		 administration(l);
			break;
		
		case 'Q': cout<<"good bye"<<endl;
				break;
				
		
			
		
		default:cout<<"wrong selection"<<endl;
		
		
		}
		
		
	}while(option!='Q');
	}
	return (0);
	
}


