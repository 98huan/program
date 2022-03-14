using namespace std;

const long ASIZE = 500000L;

#include <iostream>
#include <cstdio>  //snprintf()
#include <cstdlib> //RAND_MAX

string get_a_target_string()
{
    long target = 0;
    char buf[10];

    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    snprintf(buf, 10, "%d", target);
    return string(buf);
}

long get_a_target_long()
{
    long target = 0;
    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    return target;
}

int compareLongs(const void *a, const void *b)
{
    return (*(long *)a - *(long *)b);
}

int compareStrings(const void *a, const void *b)
{
    if (*(string *)a > *(string *)b)
        return 1;
    else if (*(string *)a < *(string *)b)
        return -1;
    else
        return 0;
}
// --------------------------------------------
#include <array>
#include <iostream>
#include <ctime>
#include <cstdlib> //qsort, bsearch, NULL
namespace jj01
{
    void test_array()
    {
        cout << "\ntest_array().......... \n";

        array<long, ASIZE> c;
        clock_t timeStart = clock();
        for (long i = 0; i < ASIZE; ++i)
        {
            c[i] = rand();
        }
        cout << "milli-seconds : " << (clock() - timeStart) << endl; //
        cout << "array.size()= " << c.size() << endl;
        cout << "array.front()= " << c.front() << endl;
        cout << "array.back()= " << c.back() << endl;
        cout << "array.data()= " << c.data() << endl;

        long target = get_a_target_long();

        timeStart = clock();
        ::qsort(c.data(), ASIZE, sizeof(long), compareLongs);
        // for (int i = 0; i < 10; ++i)
        // {
        //     cout << c[i] << " ";
        // }
        // cout << endl;
        // for (int i = ASIZE; i > ASIZE - 10; --i)
        // {
        //     cout << c[i] << " ";
        // }
        // cout << endl;
        long *pItem = (long *)::bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);
        cout << "qsort()+bsearch(), milli-seconds : " << (clock() - timeStart) << endl; //
        if (pItem != NULL)
            cout << "found, " << *pItem << endl;
        else
            cout << "not found! " << endl;
    }
} // namespace jj01

// --------------------------------------------
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>
#include <algorithm> //sort()
namespace jj02       //使用vector
{
    void test_vector(long &value)
    {
        cout << "\ntest_vector()..........\n";
        vector<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0; i < value; ++i)
        {
            try
            {
                snprintf(buf, 10, "%d", rand());
                c.push_back(string(buf));
            }
            catch (exception &p)
            {
                cout << "i = " << i << " " << p.what() << endl;
                abort();
            }
        }
        cout << "milli-second:" << (clock() - timeStart) << endl;
        cout << "vector.size() = " << c.size() << endl;
        cout << "vector.front() = " << c.front() << endl;
        cout << "vector.back() = " << c.back() << endl;
        cout << "vector.data() = " << c.data() << endl;
        cout << "vector.capacity() = " << c.capacity() << endl;

        string target = get_a_target_string();
        {
            timeStart = clock();
            auto pItem = ::find(c.begin(), c.end(), target);
            cout << "::find(), milli-seconds:" << (clock() - timeStart) << endl;

            if (pItem != c.end())
                cout << "found, " << *pItem << endl;
            else
                cout << "not found!" << endl;
        }

        timeStart = clock();
        sort(c.begin(), c.end());
        string *pItem = (string *)bsearch(&target, (c.data()),
                                          c.size(), sizeof(string), compareStrings);
        cout << "sort() + bsearch(), milli-seconds:" << (clock() - timeStart) << endl;
        if (pItem != NULL)
            cout << "found, " << *pItem << endl;
        else
            cout << "not found!" << endl;
        
        c.clear();
    }
} // namespace jj02

// --------------------------------------------
#include <list>
#include <stdexcept>
#include <string>
#include <cstdlib>   //abort()
#include <cstdio>    //snprintf()
#include <algorithm> //find()
#include <iostream>
#include <ctime>
namespace jj03 //使用list
{
    void test_list(long &value)
    {
        cout << "\ntest_list().............\n";

        list<string> c;
        char buf[10];

        clock_t timeStart = clock();
        for (long i = 0; i < value; ++i)
        {
            try
            {
                snprintf(buf, 10, "%d", rand());
                c.push_back(string(buf));
            }
            catch (exception &p)
            {
                cout << "i = " << i << " " << p.what() << endl;
                abort();
            }
        }
        cout << "milli-seconds : " << (clock() - timeStart) << endl;
        cout << "list.size() = " << c.size() << endl;
        cout << "list.max_size()= " << c.max_size() << endl;
        cout << "list.front() = " << c.front() << endl;
        cout << "list.back() = " << c.back() << endl;

        string target = get_a_target_string();
        timeStart = clock();
        auto pItem = ::find(c.begin(), c.end(), target);
        cout << "::find(), milli-seconds:" << (clock() - timeStart) << endl;

        if (pItem != c.end())
            cout << "found, " << *pItem << endl;
        else
            cout << "not found!" << endl;

        timeStart = clock();
        c.sort();
        cout << "c.sort(), milli-seconds:" << (clock() - timeStart) << endl;
        c.clear();
    }
} // namespace jj03

// --------------------------------------------
#include <forward_list>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>
namespace jj04
{
    void test_forward_list(long &value)
    {
        cout << "\ntest_forward_list()..........\n";

        forward_list<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0; i < value; ++i)
        {
            try
            {
                snprintf(buf, 10, "%d", rand());
                c.push_front(string(buf));
            }
            catch (exception &p)
            {
                cout << "i = " << i << " " << p.what() << endl;
                abort();
            }
        }
        cout << "milli-seconds:" << (clock() - timeStart) << endl;
        cout << "forward_list.max_size() = :" << c.max_size() << endl;
        cout << "forward_list.front() = :" << c.front() << endl;

        string target = get_a_target_string();
        timeStart = clock();
        auto pItem = ::find(c.begin(), c.end(), target);
        cout << "::find, milli-seconds:" << (clock() - timeStart) << endl;

        if (pItem != c.end())
            cout << "found, " << *pItem << endl;
        else
            cout << "not found!" << endl;

        timeStart = clock();
        c.sort();
        cout << "c.sort(), milli-seconds :" << (clock() - timeStart) << endl;

        c.clear();
    }
} // namespace jj04

// --------------------------------------
#include <deque>
#include <stdexcept>
#include <string>
#include <cstdlib> //abort()
#include <cstdio>  //snprintf()
#include <iostream>
#include <ctime>
namespace jj05
{
    void test_deque(long &value)
    {
        cout << "\ntest_deque().......... \n";

        deque<string> c;
        char buf[10];
        clock_t timeStart = clock();
        for (long i = 0; i < value; ++i)
        {
            try
            {
                snprintf(buf, 10, "%d", rand());
                c.push_back(string(buf));
            }
            catch (exception &p)
            {
                cout << "i=" << i << " " << p.what() << endl;
                abort();
            }
        }
        cout << "milli-seconds : " << (clock() - timeStart) << endl;
        cout << "deque.size()= " << c.size() << endl;
        cout << "deque.front()= " << c.front() << endl;
        cout << "deque.back()= " << c.back() << endl;
        cout << "deque.max_size()= " << c.max_size() << endl; // 1073741821

        string target = get_a_target_string();
        timeStart = clock();
        auto pItem = find(c.begin(), c.end(), target);
        cout << "std::find(), milli-seconds : " << (clock() - timeStart) << endl;

        if (pItem != c.end())
            cout << "found, " << *pItem << endl;
        else
            cout << "not found! " << endl;

        timeStart = clock();
        sort(c.begin(), c.end());
        cout << "sort(), milli-seconds : " << (clock() - timeStart) << endl;

        c.clear();
    }
} // namespace jj05

int main()
{
    long value = 1000000;
    int jjxx;
    cin >> jjxx;
    switch (jjxx)
    {
    case 1:
        jj01::test_array();
        break;
    case 2:
        jj02::test_vector(value);
        break;
    case 3:
        jj03::test_list(value);
        break;
    case 4:
        jj04::test_forward_list(value);
        break;

    case 5:
        jj05::test_deque(value);
        break;
    case 6:

        break;
    case 7:

        break;
    case 8:

        break;
    default:
        break;
    }
}