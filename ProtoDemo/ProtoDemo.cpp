// ProtoDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "sample.pb.h"
using namespace std;
// 1. 基本类型
void test01()
{
    Demo demo;
    demo.set_name("张三");
    demo.set_numb(18);
    demo.set_week(Week::Sat);
    cout << demo.name() << " " << demo.numb() << " " << demo.week() << endl;
}
// 2. repeated 类型
void test02()
{
    Demo demo;
    //基本方法
    demo.add_rept(100);
    demo.add_rept(200);
    demo.add_rept(300);
    cout << demo.rept_size() << endl;
    //可读可写
    cout << "修改之前：" << endl;
    demo.mutable_rept()->at(0) = 1000;
    for_each(demo.mutable_rept()->begin(), demo.mutable_rept()->end(), [](int& val) {

        cout << val << " ";
        
        });
    cout << endl;
    cout << "修改之后：" << endl;
    for_each(demo.mutable_rept()->begin(), demo.mutable_rept()->end(), [](int& val) {val += 100;
        cout << val << " ";
        });
    cout << endl;

    //只读访问
    //lamda表达式中如果是引用，必须是常引用类型。
    cout << demo.rept().at(0) << endl;
    cout << demo.rept()[0] << endl;
    for_each(demo.rept().begin(), demo.rept().end(), [](const int& val) {cout << val << " "; });
    cout << endl;
}
// 3. map 类型
void test03()
{
    Demo demo;
    demo.mutable_mpsi()->insert({"aaa",100});
    demo.mutable_mpsi()->insert({"bbb",200});
    demo.mutable_mpsi()->insert(pair<string, int>("ccc",300));
    bool being = demo.mpsi().contains("ccc");
    if (being)
    {
        cout << "存在键值为ccc的项" << endl;
    }
    else
    {
        cout <<"没有查找到键值为ccc的项" << endl;
    }
    /*auto pos1 = demo.mutable_mpsi()->find("bbb");
    if (pos1 != demo.mutable_mpsi()->end())
    {
        
        cout << pos1->first << "," << pos1->second << endl;
    }*/
    //demo.mutable_mpsi()->erase(pos1);
    for (auto it = demo.mpsi().begin(); it != demo.mpsi().end(); it++)
    {
        cout << it->first << " " << it->second << " ";
    }
    cout << endl;
}
int main()
{
    cout << "-------------------------invoke test01----------------------------------" << endl;
    test01();
    cout << "-------------------------invoke test02----------------------------------" << endl;
    test02();
    cout << "-------------------------invoke test03----------------------------------" << endl;
    test03();
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
