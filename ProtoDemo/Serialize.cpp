#include "Serialize.h"
#include "sample.pb.h"
#include <iostream>
#include <fstream>
using namespace std;
void print_demo(const Demo& demo)
{
	cout << "name:" << demo.name() << endl;
	cout << "numb:" << demo.numb() << endl;
	cout << "week:" << demo.week() << endl;
	cout << "rep:";
	for (auto it = demo.rept().begin(); it != demo.rept().end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "mpsi:";
	for (auto it = demo.mpsi().begin(); it != demo.mpsi().end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	cout << "cust:" << demo.cust().attr1() << "  " << demo.cust().attr2() << endl;
	cout << "----------------------------------------------" << endl;
}

void serialize()
{
	Demo demo;
	demo.set_name("张三");
	demo.set_numb(100);
	demo.add_rept(10);
	demo.add_rept(20);
	demo.add_rept(30);
	demo.set_week(Week::Thu);
	demo.mutable_mpsi()->insert({ "aaa",111 });
	demo.mutable_mpsi()->insert({ "bbb",222 });
	demo.mutable_mpsi()->insert({ "ccc",333 });
	demo.mutable_cust()->set_attr1(123);
	demo.mutable_cust()->set_attr2(456);
	// 二进制序列存储到哪里呢？
	// 1. 序列化到数组/从数组反序列化
	int object_size = demo.ByteSizeLong();
	char* data = new char[object_size];
	demo.SerializeToArray(data, object_size);
	
	
	Demo newDemo1;
	newDemo1.ParseFromArray(data, object_size);
	print_demo(newDemo1);
	
	delete[] data;
	data = nullptr;
	// 2. 序列化到字符串/从字符串反序列化
	Demo newDemo2;
	string str; 
	demo.SerializeToString(&str);
	newDemo2.ParseFromString(str);
	print_demo(newDemo2);
	// 3. 序列化到输出流
	ofstream ofs("demo.bin",ios::binary); // demo.bin 与工程 同目录
	demo.SerializeToOstream(&ofs);
	ofs.close();
	
	Demo newDemo3;
	ifstream ifs("demo.bin", ios::binary);
	newDemo3.ParseFromIstream(&ifs);
	ifs.close();
	print_demo(newDemo3);

}
