#include "unittest.h"
#include "processInput.h"
#include <algorithm>
#include <sstream>
#include <stack>

using namespace std;

typedef stack<int> Stack;

void fillStack (Stack& stack, int k) {
    while (k > 0) {
        stack.push (k % 10);
        k = k / 10;
    }
}

string printStack(Stack& stack)
{
    ostringstream out;
    print (out, stack);
    return out.str();
}

UnitTest(print1)
{
    Stack s;
    fillStack(s, 24681);
    ostringstream out;
    print (out, s);
    assertThat (out.str(), isEqualTo("18642"));
}

UnitTest(print2)
{
    Stack s;
    fillStack(s, 10);
    ostringstream out;
    print (out, s);
    assertThat (out.str(), isEqualTo("01"));
}


UnitTest(uniqueDigit1)
{
    Stack s;
    fillStack(s, 123);
    int remaining[] = {1, 1, 1, 1, 0,  1, 1, 1, 1, 1};
    bool inStack[] = {false, true, true, true, false,
                        false, false, false, false, false};
    processInputDigit (4, s, inStack, remaining);
    assertThat(printStack(s), isEqualTo("3214"));
    bool expected[] = {false, true, true, true, true,
                        false, false, false, false, false};
    assertThat (arrayOfLength(inStack, 10), matches(arrayOfLength(expected, 10)));

}

UnitTest(uniqueDigit2)
{
    Stack s;
    fillStack(s, 123);
    int remaining[] = {1, 1, 1, 1, 0,  1, 1, 1, 1, 1};
    bool inStack[] = {false, true, true, true, false,
                        false, false, false, false, false};
    processInputDigit (0, s, inStack, remaining);
    assertThat(printStack(s), isEqualTo("0"));
    bool expected[] = {true, false, false, false, false,
                        false, false, false, false, false};
    assertThat (arrayOfLength(inStack, 10), matches(arrayOfLength(expected, 10)));

}

UnitTest(uniqueDigit3)
{
    Stack s;
    fillStack(s, 123);
    int remaining[] = {2, 2, 2, 0, 0,  1, 1, 1, 1, 1};
    bool inStack[] = {false, true, true, true, false,
                        false, false, false, false, false};
    processInputDigit (0, s, inStack, remaining);
    assertThat(printStack(s), isEqualTo("30"));
    bool expected[] = {true, false, false, true, false,
                        false, false, false, false, false};
    assertThat (arrayOfLength(inStack, 10), matches(arrayOfLength(expected, 10)));

}



UnitTest(largerDigit)
{
    Stack s;
    fillStack(s, 2);
    int remaining[] = {1, 1, 1, 1, 1,  1, 1, 1, 1, 1};
    bool inStack[] = {false, false, true, false, false,
                        false, false, false, false, false};
    processInputDigit (9, s, inStack, remaining);
    assertThat(printStack(s), isEqualTo("29"));
    bool expected[] = {false, false, true, false, false,
                        false, false, false, false, true};
    assertThat (arrayOfLength(inStack, 10), matches(arrayOfLength(expected, 10)));

}

UnitTest(smallerDigit)
{
    Stack s;
    fillStack(s, 2);
    int remaining[] = {1, 1, 1, 1, 1,  1, 1, 1, 1, 1};
    bool inStack[] = {false, false, true, false, false,
                        false, false, false, false, false};
    processInputDigit (0, s, inStack, remaining);
    assertThat(printStack(s), isEqualTo("0"));
    bool expected[] = {true, false, false, false, false,
                        false, false, false, false, false};
    assertThat (arrayOfLength(inStack, 10), matches(arrayOfLength(expected, 10)));

}
