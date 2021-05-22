/**
 * @file main.c
 * @author Starman
 * @brief Main loop
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdbool.h>
#include <stdint.h>
#include "./songs/megalovania.h"
#include "./systick.c"

uint16_t calculatePeriodEnd(uint16_t number)
{
    return (number + currentMicroseconds());
}

uint16_t calculateNoteEnd(uint16_t duration)
{
    return ((duration * tickLengthMs) + currentMilliseconds());
}

int main()
{
    initSysTick();

    initMotors();

    uint16_t nextStateChangeDue[] = {
        calculatePeriodEnd(trackOne[0][0]),
        calculatePeriodEnd(trackTwo[0][0]),
        calculatePeriodEnd(trackThree[0][0]),
        calculatePeriodEnd(trackFour[0][0]),
        calculatePeriodEnd(trackFive[0][0])};

    uint32_t nextNoteChangeDue[] = {
        calculateNoteEnd(trackOne[0][1]),
        calculateNoteEnd(trackTwo[0][1]),
        calculateNoteEnd(trackThree[0][1]),
        calculateNoteEnd(trackFour[0][1]),
        calculateNoteEnd(trackFive[0][1])};

    uint16_t currentPositions[] = {
        0,
        0,
        0,
        0,
        0};

    uint16_t pauseNextTicks[] = {
        0,
        0,
        0,
        0,
        0};

    uint16_t skipTicks = 750;

    while (1)
    {
        uint32_t currentMilliS = currentMilliseconds();
        if (currentMilliS >= nextNoteChangeDue[0])
        {
            currentPositions[0]++;
            nextNoteChangeDue[0] = calculateNoteEnd(trackOne[currentPositions[0]][1]);
            pauseNextTicks[0] = 1;
        }
        if (currentMilliS >= nextNoteChangeDue[1])
        {
            currentPositions[1]++;
            nextNoteChangeDue[1] = calculateNoteEnd(trackTwo[currentPositions[1]][1]);
        }
        if (currentMilliS >= nextNoteChangeDue[2])
        {
            currentPositions[2]++;
            nextNoteChangeDue[2] = calculateNoteEnd(trackThree[currentPositions[2]][1]);
        }
        if (currentMilliS >= nextNoteChangeDue[3])
        {
            currentPositions[3]++;
            nextNoteChangeDue[3] = calculateNoteEnd(trackFour[currentPositions[3]][1]);
        }
        if (currentMilliS >= nextNoteChangeDue[4])
        {
            currentPositions[4]++;
            nextNoteChangeDue[4] = calculateNoteEnd(trackFive[currentPositions[4]][1]);
        }

        uint64_t currentMicroS = currentMicroseconds();
        if (currentMicroS >= nextStateChangeDue[0])
        {
            if (pauseNextTicks[0] > 0)
            {
                if (pauseNextTicks[0] == skipTicks)
                    pauseNextTicks[0] = 0;
                else
                    pauseNextTicks[0]++;
            }
            else
            {
                toggleMotor('F', 13);
                nextStateChangeDue[0] = calculatePeriodEnd(trackOne[currentPositions[0]][0]);
            }
        }

        if (currentMicroS >= nextStateChangeDue[1])
        {
            if (pauseNextTicks[1] > 0)
            {
                if (pauseNextTicks[1] == skipTicks)
                    pauseNextTicks[1] = 0;
                else
                    pauseNextTicks[1]++;
            }
            else
            {
                toggleMotor('E', 9);
                nextStateChangeDue[1] = calculatePeriodEnd(trackTwo[currentPositions[1]][0]);
            }
        }

        if (currentMicroS >= nextStateChangeDue[2])
        {
            if (pauseNextTicks[2] > 0)
            {
                if (pauseNextTicks[2] == skipTicks)
                    pauseNextTicks[2] = 0;
                else
                    pauseNextTicks[2]++;
            }
            else
            {
                toggleMotor('E', 11);
                nextStateChangeDue[2] = calculatePeriodEnd(trackThree[currentPositions[2]][0]);
            }
        }

        if (currentMicroS >= nextStateChangeDue[3])
        {
            if (pauseNextTicks[3] > 0)
            {
                if (pauseNextTicks[3] == skipTicks)
                    pauseNextTicks[3] = 0;
                else
                    pauseNextTicks[3]++;
            }
            else
            {
                toggleMotor('F', 14);
                nextStateChangeDue[3] = calculatePeriodEnd(trackFour[currentPositions[3]][0]);
            }
        }

        if (currentMicroS >= nextStateChangeDue[4])
        {
            if (pauseNextTicks[4] > 0)
            {
                if (pauseNextTicks[4] == skipTicks)
                    pauseNextTicks[4] = 0;
                else
                    pauseNextTicks[4]++;
            }
            else
            {
                toggleMotor('E', 13);
                nextStateChangeDue[4] = calculatePeriodEnd(trackFive[currentPositions[4]][4]);
            }
        }
    }
}