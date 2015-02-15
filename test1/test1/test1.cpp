// test1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"






















#include "random_seed.c"
#include "linkhash.c"
#include <iostream>
#include <string>
using namespace std;
void remove(lh_entry* e){
}

void ppp(){
	struct lh_table* p = lh_kchar_table_new(100,"name",remove);
	int a[10]={3,5,2,9,8,11,25,903,1,7};
	string name[]={"age","sex","tall","weight","node"};
	for(int i=0;i<5;i++){
		lh_table_insert(p, (void*)(name[i].c_str()), a+i+1);
	}
	lh_entry* tmpp;
	int b;
	lh_foreach(p, tmpp){
		name[0] = (char*)tmpp->k;
		b = *(int*)tmpp->v;
		cout<<name[0]<<"->"<<b<<endl;
	}
}































int _tmain(int argc, _TCHAR* argv[])
{
	char c;
	ppp();
	cin>>c;
	return 0;
}

