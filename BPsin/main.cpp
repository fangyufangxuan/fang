// C++ code to make task manager generate sine graph

//#include <iostream>
#include "stdio.h"
#include "windows.h"
#include "stdlib.h"
#include "math.h"

using namespace std;

// 把每一条正弦曲线0~2n之间的弧度等分为200份进行抽样，
// 计算每个抽样点的振幅，然后每隔300ms的时间取下一个抽样点
// 并让CPU工作对应振幅的时间

const int SAMPLING_COUNT = 200;
const double PI = 3.14159265358979;
const int TOTAL_AMPLITUDE = 300;

int _tmain(int argc, _TCHAR * argv[])
{
    DWORD busyspan[SAMPLING_COUNT];
    int amplitude = TOTAL_AMPLITUDE / 2;
    double radian = 0.0;
    double radianIncrement = 2.0 / (double)SAMPLING_COUNT;

    for (int i = 0; i < SAMPLING_COUNT; i++)
    {
        busyspan[i] = (DWORD)(amplitude + (sin(PI*radian) * amplitude));
        radian += radianIncrement;
        printf("%d\t%d",busyspan[i], TOTAL_AMPLITUDE - busyspan[i]);
    }

    DWORD startTime = 0;
    for (int j = 0; ; j = (j + 1) % SAMPLING_COUNT)
    {
        startTime = GetTickCount();
        while ((GetTickCount() - startTime) <= busyspan[j])
            ;
        Sleep(TOTAL_AMPLITUDE - busyspan[j]);
    }

    //cout << "Hello world!" << endl;
    return 0;
}
