#include "BaseOperate.h"
#include "sample.pb.h"
#include <iostream>
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
    demo.mutable_mpsi()->insert({ "aaa",100 });
    demo.mutable_mpsi()->insert({ "bbb",200 });
    demo.mutable_mpsi()->insert(pair<string, int>("ccc", 300));
    bool being = demo.mpsi().contains("ccc");
    if (being)
    {
        cout << "存在键值为ccc的项" << endl;
    }
    else
    {
        cout << "没有查找到键值为ccc的项" << endl;
    }
    auto pos1 = demo.mutable_mpsi()->find("bbb");
    if (pos1 != demo.mutable_mpsi()->end())
    {

        pos1->second = 500;
        cout << pos1->first << "," << pos1->second << endl;

    }
    //demo.mutable_mpsi()->erase(pos1);
    for (auto it = demo.mpsi().begin(); it != demo.mpsi().end(); it++)
    {
        cout << it->first << " " << it->second << " ";
    }
    cout << endl;
}
// 4. 自定义类型
void test04()
{
    Demo demo;
    demo.mutable_cust()->set_attr1(123);
    demo.mutable_cust()->set_attr2(456);
    cout << "demo.cust().attr1() = " << demo.cust().attr1() << "  " << "demo.cust().attr2() = " << demo.cust().attr2() << endl;
}