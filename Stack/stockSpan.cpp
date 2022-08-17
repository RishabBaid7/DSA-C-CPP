#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <new>
#include <cmath>
#include <cstring>
#include <cstdbool>
#include <cctype>
#include <cstdarg>
#include <climits>

#define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

using namespace std;

void printTrace(int line, const char *fileName, const char *msg, ...)
{
    va_list args;
    char buffer[1024 + 2] = {0};

    snprintf(buffer, sizeof(buffer), "%s(%d) : ", fileName, line);
    int stringLength = strnlen(buffer, 1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer + stringLength, remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << flush;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[7] = {100, 80, 60, 70, 60, 75, 85};
    int len = 7;

    int count = 0;
    stack<pair<int, int>> s;
    vector<int> v;

    for (int i = 0; i < len; i++)
    {
        if (s.empty())
        {
            v.push_back(-1);
        }
        else if (s.top().first > arr[i])
        {
            v.push_back(s.top().second);
        }
        else if (s.top().first < arr[i])
        {
            while ((s.size() > 0) && (s.top().first < arr[i]))
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top().second);
            }
        }
        s.push({arr[i], i});
    }

    for (int i = 0; i < v.size(); i++)
    {
        v[i] = i - v[i];
    }
    
    return 0;
}