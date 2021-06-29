#include <stdint.h>

#include <algorithm>
#include <filesystem>
#include <iostream>
#include <iterator>
#include <memory>
#include <regex>
#include <sstream>
#include <vector>

#include "haha.h"

using namespace       std;

namespace MyNameSpace
{
}

// FixNamespaceComments
namespace Outer
{
namespace Inner
{
namespace VeryInner
{
}
} // namespace Innereeeee
} // namespace Outer

// CompactNamespaces
namespace Outer
{
namespace Inner
{
namespace VeryInner
{
}
} // namespace Inner
} // namespace Outer

struct A
{
public:
    A(int a);
};

A::A(int a)
{


    cout << "hello";
    if (a < 3)     {
        cout << "geza" << endl;
    }

    else    {
        cout << "hi";
    }
    for (int a = 1; a < 5; ++a)
    {
        ;
    }
}

struct AppleDevice : public MakarenaDevice, private WindowDevice, protected ShieldDevice
{
    AppleDevice(int apple, std::string banana, std::vector<std::string> strList);
    AppleDevice(int a, std::string b);
    int apple;
    std::string banana;
    std::vector<std::string> strList;
};

AppleDevice::AppleDevice(int apple, std::string banana, std::vector<std::string> strList)
    : apple{apple},
      banana{banana},
      strList{strList}
{
}

AppleDevice::AppleDevice(int a, std::string b)
    : apple{a},
      banana{b},
      strList{}
{
}

struct A
{
    A(int a)
    {
        cout << "A: " << a << endl;
    }
};

struct B
{
    B()
    {
        cout << "B" << endl;
    }
    static A a1;
    static A a2;
    static A a3;
};

A B::a2{2};
A B::a3{3};
A B::a1{1};

void longFunctionCallLine()
{
    thisIsAVeryLongFunctionName(argumentOne, argumentTwo, argumentThree, argumentFour, argumentFive, argumentSix);

    thisIsAVeryLongFunctionName(argumentOne, argumentTwo, argumentThree);

    thisIsAVeryLongFunctionName(argumentOne, argumentTwo, argumentThree, argumentFour,
                                thisIsAVeryLongFunctionName(argumentOne, argumentTwo, argumentThree), argumentSix);
}

void longExpressions()
{
    auto result1 = argumentOne + argumentTwo / argumentThree * argumentFour - argumentFive / argumentSix;
    auto result2 = argumentOne + argumentTwo == argumentThree * argumentFour && argumentFive / argumentSix != argumentSeven;
}

void longConditions()
{
    if (argumentOne + argumentTwo == argumentThree * argumentFour
        && argumentFive / argumentSix != argumentSeven
        && (argumentOne % 2) != 0
        && argumentTwo == 4)
    {
        cout << "Hello";
    }
    if (argumentOne + argumentTwo != argumentThree * argumentFour
        || argumentFive / argumentSix != argumentSeven
                && argumentOne % 2
                && argumentTwo == 4)
    {
        cout << "Hello";
    }
    if (argumentOne + argumentTwo == argumentThree * argumentFour
                && argumentFive / argumentSix != argumentSeven
                && argumentOne % 2
        || argumentTwo == 4)
    {
        cout << "Hello";
    }
}

void switchCase(int apple)
{
    switch (apple)
    {
    case 0:
    {
        cout << "hi";
        break;
    }
    case 1:
        cout << "one";
        break;
    default:
        cout << "default";
        break;
    }
}

void lambdas()
{
    auto lambda1 = []()
    {
    };
    auto lambda2 = []()
    {
        return true;
    };
    auto lambda3 = [=](float f, int a)
    {
        const auto r = f + a;
        return r;
    };
    functionCallWithLambda([](int a, int b)
                           {
                               return a * b;
                           });
}

int main()
{
    cout << "ulong sz " << sizeof(unsigned long) << endl;
    return 0;
}
