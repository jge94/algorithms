#ifndef _MYITEM
#define _MYITEM

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class myItem
{
	public:
		myItem();
		myItem(int sn, string s);
		int serialNumber;
		string name;
		
		bool operator==(/*inout*/myItem& myItem2);             // Equal to
		bool operator<(/*inout*/myItem& myItem2);              // Less than
		bool operator>(/*inout*/myItem& myItem2);              // Greater than
		bool operator<=(/*inout*/myItem& myItem2);             // Less than or equal to
		bool operator>=(/*inout*/myItem& myItem2);             // Greater than or equal to

};

#endif