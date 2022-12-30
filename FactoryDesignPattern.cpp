#include<iostream>
using namespace std;

// Factory Design Pattern
// GOF says
// Defines an interface for creating an object but let subclasses decide which class to instantiate.
// Also known  as virtual constructor.

class coffee
{
	public:
		string name;
	coffee()
	{
		name = "Normal";
	}
};

class Lattecoffee: public coffee
{
	public:
	Lattecoffee()
	{
		name = "Latte";
	}
};

class Cappicoffee: public coffee
{
	public:
	
	Cappicoffee()
	{
		name = "Cappi";
	}
};

//Now comes Factory implementation
class CoffeeFactory
{
	public:
	coffee* m_coffee = nullptr;
	int m_choice ;
	CoffeeFactory()
	{
		cout<<"Coffee Factory"<<endl;
	}

	coffee* prepareNserve()
	{
		switch(m_choice)
		{
			case 0:
				m_coffee = new coffee;
				break;
			case 1:
				m_coffee = new Cappicoffee;
				break;
			case 2:
				m_coffee = new Lattecoffee;
				break;

		}
		return m_coffee;
	}

	int getchoice()
	{
		cout<<"Order your choice"<<endl;
		cout<<"For Normal coffee Press 0"<<endl;
		cout<<"For Latte coffee Press  1"<<endl;
		cout<<"For cappu coffee Press  2"<<endl;		
		cin>>m_choice;
		if (m_choice>=0 && m_choice<=2)
			cout<<"your choice is "<<m_choice<<endl;
		else

		cout<<"You have not pressed valid choice "<<endl;
		return 0;
	}

};

int main()
{
	//Get factory interface to create object;
	CoffeeFactory* factory = nullptr;
	factory = new CoffeeFactory;
	factory->getchoice();


		cout<<"Here is your "<<endl;
		cout<<factory->prepareNserve()->name<<endl;
		cout<<"Thank you "<<endl;
	
}