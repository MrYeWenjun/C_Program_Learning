#include <stdio.h>

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int totalPosionedTime = 0;
    int positionedEndTime = 0;
    int i;
    for( i = 0; i < timeSeriesSize; ++i )
    {
        totalPosionedTime += duration - ( timeSeries[i] < positionedEndTime ) * ( positionedEndTime - timeSeries[i] );
        positionedEndTime = timeSeries[i] + duration;
    }
    return totalPosionedTime;
}

int main( void )
{
    int size = 9;
    int timeS[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int duration = 100;
    int returnNum = findPoisonedDuration( timeS, size, duration );
    printf("%d\n", returnNum);
    return 0;
}
