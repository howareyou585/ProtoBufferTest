#include<iostream>
#include<fstream>
#include "encode.pb.h"
#include "EncodeDemo.h"

using namespace std;

void encodeVarint()
{
	MyVarint data;
	data.set_num1(214748);
	data.set_num2(20);
	data.set_num3(true);
	ofstream fs("varint.bin", ios::binary);
	data.SerializeToOstream(&fs);
	fs.close();
}

void encodeFixed()
{
	MyFixed data;
	data.set_num1(10);
	data.set_num2(20);
	ofstream fs("fixed.bin", ios::binary);
	data.SerializeToOstream(&fs);
}

void encodeLen()
{
	MyLen data;
	data.set_num1("abc");
	ofstream fs("len.bin", ios::binary);
	data.SerializeToOstream(&fs);
	fs.close();
	
}

void encodeCustom()
{
	MyCustom data;
	data.add_num1(10);
	data.add_num1(20);
	data.mutable_num2()->insert({1,"aaa"});
	data.mutable_num2()->insert({2,"bbb"});
	ofstream fs("custom.bin", ios::binary);
	data.SerializeToOstream(&fs);
	fs.close();
}
void encode()
{
	encodeVarint();
	encodeFixed();
	encodeLen();
	encodeCustom();
}	

