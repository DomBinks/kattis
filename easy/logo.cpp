#include <iostream>
#include <cmath>
#include <cstdio>

#define PI 3.14159265

using namespace std;

int main()
{
    // Get number of test cases
    int t;
    cin >> t;

    // For each case
    while(t-- > 0)
    {
        // Get number of commands
        int n;
        cin >> n;

        // Set the start x and y coordinates and angle 5
        // 0 is to the right, 0 to 180 is going clockwise, -1 to -179 is going anti-clockwise
        double x = 0;
        double y = 0;
        int r = 0;

        // For each command
        for(int i = 0; i < n; i++)
        {
            // Get the command and amount
            string a;
            int b;
            cin >> a >> b;

            // Switch the direction of the turn if negative
            if(a == "lt" || b < 0)
            {
                a = "rt";
                b *= -1;
            }
            if(a == "rt" || b < 0)
            {
                a = "lt";
                b *= -1;
            }

            // If the command is move forwards or backwards
            if(a == "fd" || a == "bk")
            {
                double dx; // x difference
                double dy; // y difference
                
                // Calculate dx and dy using trigonometry, converting the r to
                // the correct angle for the calculation, using PI/180 to
                // convert from degrees to radians

                // If in 4th quadrant
                if(r >= 0 && r <= 90)
                {
                    dx = cos(r*PI/180.0) * b;
                    dy = -1.0 * sin(r*PI/180.0) * b;
                }
                // If in in 3rd quadrant
                else if(r > 90)
                {
                    dx = -1.0 * cos((180-r)*PI/180.0) * b;
                    dy = -1.0 * sin((180-r)*PI/180.0) * b;
                }
                // If in 1st quadrand
                else if(r < 0 && r >= -90)
                {
                    dx = cos((-1.0*r)*PI/180.0) * b;
                    dy = sin((-1.0*r)*PI/180.0) * b;
                }
                else
                // If in 2nd quadrant
                {
                    dx = -1.0 * cos((-1.0*(180-r))*PI/180.0) * b;
                    dy = sin((-1.0*(180-r))*PI/180.0) * b;
                }

                // If moving forward
                if(a == "fd")
                {
                    // Add the differences
                    x += dx;
                    y += dy;
                }
                // If moving backward
                else
                {
                    // Minus the differences
                    x -= dx;
                    y -= dy;
                }
            }
            // If the command is turning left
            else if(a == "lt")
            {
                // Decrement the angle
                r -= b;
            }
            // If the command is turning right
            else
            {
                // Increment the angle
                r += b;
            }

            // Correct the angle if necessary to keep within -179 to 180
            // by wrapping the value around
            while(r > 180)
            {
                r -= 360;
            }
            while(r <= -180)
            {
                r += 360;
            }
        }

        // Output the magnitude of the distance to (x,y) from (0,0)
        printf("%.0f\n", round(sqrt(pow(x, 2.0)+pow(y, 2.0))));
    }

    return 0;
}
