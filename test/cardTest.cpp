#include "Card.h"
#include <iostream>

using std::cout ;
using std::endl ;

int main(int* argc , char* argv[])
{	
	const int MAX_NO_OF_TESTS = 0 ;
	bool testResults[MAX_NO_OF_TESTS] ;
	int currentTest = 0 ;

	cout << "**************************************************" << endl ;
	cout << "*                                                *" << endl ;
	cout << "*               CARD CLASS TEST HARNESS          *" << endl ;
	
	//////////////////////////////////////////////////////////////////////
	
	cout << "*                                                *" << endl ;
	cout << "* Test no: " << currentTest << "                                      *" << endl ;
	cout << "* Card creation and initialization               *" << endl ;
	
	Card* testCard = NULL ;
	testCard = new Card() ;
	
	if(testCard->getType() != 27)
	{
		cout << "*                                                *" << endl ;
		cout << "* Passed                                         *" << endl ;
	}
	else
	{
		cout << "*                                                *" << endl ;
		cout << "* Failed ... Card type not initialized correctly *" << endl ;
	}
	
	currentTest++ ;
	
	cout << "*                                                *" << endl ;
	cout << "* Test no: " << currentTest << "                                      *" << endl ;
	cout << "* Setting the cards type                         *" << endl ;

	testCard->setType(Card::FELONY) ;
	
	if(testCard->getType() != Card::FELONY)
	{
		cout << "*                                                *" << endl ;
		cout << "* Failed ... Card type not set correctly         *" << endl ;
	}
	else
	{
		cout << "*                                                *" << endl ;
		cout << "* Passed                                         *" << endl ;
	}
	
	currentTest++ ;
	
	cout << "*                                                *" << endl ;
	cout << "* Test no: " << currentTest << "                                      *" << endl ;
	cout << "* Changing the cards type                        *" << endl ;
	
	testCard->setType(Card::MARKET_OPEN) ;
	
	if(testCard->getType() == Card::FELONY)
	{
		cout << "*                                                *" << endl ;
		cout << "* Passed                                         *" << endl ;
	}
	else
	{
		cout << "* Failed ... The cards type was successfully     *" << endl ;
		cout << "*            changed                             *" << endl ;
	}
	
	if(testCard != NULL)
	{
		delete testCard ;
		testCard = NULL ;
	}
	
	//////////////////////////////////////////////////////////////////////////
	
	cout << "*                                                *" << endl ;
	cout << "*                                                *" << endl ;
	cout << "*               All Tests Completed              *" << endl ;
	
	int passed = 0 ;
	
	for(int i = 0 ; i < MAX_NO_OF_TESTS ; i++)
	{
		if(testResults[i] == true)
		{
			passed++ ;
		}
	}
	
	cout << "*                                                *" << endl ;
	cout << "*                                                *" << endl ;
	cout << "* " << passed << "/" << MAX_NO_OF_TESTS << " passed                                     *" << endl ;
	
	if(passed != MAX_NO_OF_TESTS)
	{
		for(int i = 0 ; i < MAX_NO_OF_TESTS ; i++)
		{
			if(testResults[i] == false)
			{
				cout << "* Test " << i << " failed                                       *" << endl ;
			}
		}
	}
	
	return 0 ;
}