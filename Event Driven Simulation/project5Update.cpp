#include "pch.h"
#include <iostream>
using namespace std;
#include "Constants.h"
#include "LinkedNodeClass.h"
#include "FIFOQueueClass.h"
#include "SortedListClass.h"
#include "CustomerClass.h"
#include "EventClass.h"
#include "random.h"
#include "SimulationClass.h"
#include "ValidInputCheck.h"

int main()
{
    // provide input value here
    // all values should be positive
    // max value should be no smaller than min value

    double randomSeed;
    // not negative
    cout << "Please input random seed to start: ";
    ValidInputCheck(randomSeed, INPUT_NOT_NEGATIVE_BOUND);
    randomSeed = int(randomSeed);

    double closingTimeValue;
    // not negative
    cout << "Please enter closing time: ";
    ValidInputCheck(closingTimeValue, INPUT_NOT_NEGATIVE_BOUND);
    closingTimeValue = int(closingTimeValue);

    double uniformMinValue;
    // positive
    cout << "Please enter uniform min value: ";
    ValidInputCheck(uniformMinValue, INPUT_POSITIVE_BOUND);
    uniformMinValue = int(uniformMinValue);

    double uniformMaxValue;
    // no smaller than min
    cout << "Please enter uniform max value: ";
    ValidInputCheck(uniformMaxValue, uniformMinValue);
    uniformMaxValue = int(uniformMaxValue);

    double normalMeanValue;
    // positive
    cout << "Please enter normal mean value: ";
    ValidInputCheck(normalMeanValue, INPUT_POSITIVE_BOUND);

    double normalStdValue;
    // not negative
    cout << "Please enter normal std value: ";
    ValidInputCheck(normalStdValue, INPUT_NOT_NEGATIVE_BOUND);

    double lengthOfNotWaitValue;
    // not negative
    cout << "Please enter queue length constraint for not waiting: ";
    ValidInputCheck(lengthOfNotWaitValue, INPUT_NOT_NEGATIVE_BOUND);
    lengthOfNotWaitValue = int(lengthOfNotWaitValue);

    double percentOfNotWaitValue; 
    // not negative
    cout << "Please enter percent for not waiting within in 0 and 1: ";
    ValidInputCheck(percentOfNotWaitValue, INPUT_NOT_NEGATIVE_BOUND);

    SimulationClass simulator(closingTimeValue, uniformMinValue, \
        uniformMaxValue, normalMeanValue, normalStdValue, \
        percentOfNotWaitValue, lengthOfNotWaitValue);

    setSeed(randomSeed);
    simulator.handleEvent();
    simulator.print();

}
