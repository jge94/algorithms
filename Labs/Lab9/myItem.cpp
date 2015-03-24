#include "stdafx.h"
#include "myItem.h"
#include <iostream>
#include <string>

using namespace std;

myItem::myItem()
{

}

myItem::myItem(int sn, string s)
{
	this->serialNumber = sn;
	this->name = s;
}

bool myItem::operator==(/*inout*/myItem& myItem2)
{
	return(this->serialNumber == myItem2.serialNumber);
}

bool myItem::operator<(/*inout*/myItem& myItem2)
{
	return(this->serialNumber < myItem2.serialNumber);
}

bool myItem::operator>(/*inout*/myItem& myItem2)
{
	return(this->serialNumber > myItem2.serialNumber);
}

bool myItem::operator<=(/*inout*/myItem& myItem2)
{
	return(this->serialNumber <= myItem2.serialNumber);
}

bool myItem::operator>=(/*inout*/myItem& myItem2)
{
	return(this->serialNumber >= myItem2.serialNumber);
}