/*
 *Author: Jonathan Drouillard
 *Assignment Title: "Atheletic Track"
 *Assignment Description: Given a length and width ratio, calculate the length and width
                          to have a track of 400 units in perimeter.
 *Due Date: 20120928
 *Date Created: 20120928
 *Last Modified: 20120928

 *Data Abstraction
    Creates double precision to store how close we want to the real answer.
    Creates doubles min and max to store the minimum and maximum perimeters.
    Creates doubles wid and len to store the current width and length.
    Creates double perimeter to store the current perimeter.
    Creates double arc to store the current arc length.
    Creates integer lenRatio and widRatio to store the desired ratios.
    Creates integer i to store the current case number.
 *Input
    Read in length and width ratios.
 *Process/Implementation
    User inputs length and width ratios.
    Calculate length from the minimum and maximum perimeter.
    Calculate width from this length and the given width/length ratios.
    Calculate the perimeter based off the new length/width.
    If the perimeter is less than the desired arc, discard half of the set.
    If the perimeter is greater than the desired arc, discard the other half of the set.
    Continue until the minumum and maximum values are nearly identical.
 *Output
    The calculated length and width using the original ratios.
 *Assumptions
    At most 1000 test cases.
    Ratios are integer values.
    Ratios are between and including 1 and 1000.
    Perimeter is 400 meters.
*/


#include <iomanip> //fixed, setprecision
#include <iostream> //cout, cin
#include <cmath> //sqrt, atan, fabs
using namespace std; //eliminates std::

const double PRECISION = 1e-10; //math hard etc

int main() {
    cout << fixed << setprecision(5);

    double min, max, wid, len, perimeter, arc;
    int lenRatio, widRatio, i=1;

    while(cin >> lenRatio >> widRatio) {
        min=0, max=400;
        do {
            len = (min+max)/2;
            wid = (len*widRatio)/lenRatio;
            perimeter = 2 * sqrt(len/2 * len/2 + wid/2 * wid/2) * atan(wid/len); //MATH REALLY HARD ETC
            arc = 200-len;
            if(perimeter < arc)
                min = len;
            else
                max = len;
        }while(fabs(max-min) > PRECISION);

        cout << "Case " << i << ": " << len << " " << wid << endl;

        i++;
    }
    return EXIT_SUCCESS;
}
