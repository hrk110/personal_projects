#include <iostream>
#include <thread>
#include <chrono>
#include <array>
#include <cmath>
#include <string>
using std::cout, std::endl;
using namespace std::chrono;
using std::this_thread::sleep_for;

// global variables
constexpr int SCREEN_HEIGHT = 25, SCREEN_WIDTH = 80;
constexpr int SCREEN_SIZE = SCREEN_HEIGHT*SCREEN_WIDTH;

constexpr double R1 = 0.01; // radius of 'cross section of donut'
constexpr double R2 = 2; // radius of 'donut'
constexpr double K2 = 5; // distance between observer and donut.
/*
K1 = z' = const, which means the distance between observer and screen.
K1 can be calculated based on screen width in this way:
max(x)*K1/(K2+0) = (1/2)*SCREEN_WIDTH*(3/4)
since max(x) = R1+R2, K1 is 50.
*/
constexpr int MAX_X = SCREEN_WIDTH*3/8, MAX_Y = MAX_X/2;

constexpr double TWO_PI = 6.28318;
constexpr double THETA_STEP = 0.07, PHI_STEP = 0.02;

constexpr char LUMINANCE[] = ".,-~:;=!*#$@";
constexpr int TIME_TO_SLEEP = 10; // millisecond

int main(int argc, char *argv[])
{
  double A = 0, B = 0;
  double phi, theta;
  std::array<double,SCREEN_SIZE> z_buffer; // stores inverse of distance between nearest point and observer.
  std::array<char,SCREEN_SIZE> output; // canvas
  cout << "\x1b[2J"; // clear terminal screen.

  while(true) {
    z_buffer.fill(0);
    output.fill(' ');
    for(theta=0; theta < TWO_PI; theta += THETA_STEP) {
      for(phi=0; phi < TWO_PI; phi += PHI_STEP) {
        double sin_phi = sin(phi);
        double cos_phi = cos(phi);
        double sin_theta = sin(theta);
        double cos_theta = cos(theta);
        double sin_A = sin(A);
        double cos_A = cos(A);
        double sin_B = sin(B);
        double cos_B = cos(B);

        double h = R2 + R1*cos_theta;
        double z = cos_A*h*sin_phi + R1*sin_A*sin_theta;
        double D = 1 / (K2 + z); // (distance from observer)^(-1)
        double t = sin_phi*h*sin_A - R1*sin_theta*cos_A;
        double x = cos_phi*h*cos_B + t*sin_B;
        double y = cos_phi*h*sin_B - t*cos_B;
        int X = SCREEN_WIDTH/2 + MAX_X * D * x;
        int Y = SCREEN_HEIGHT/2 + MAX_Y * D * y;
        int pos = X + SCREEN_WIDTH * Y; // position in output[].

        // Luminance.
        int L = 8.4 * ( cos_phi*cos_theta*sin_B - cos_A*cos_theta*sin_phi - sin_A*sin_theta + cos_B*(cos_A*sin_theta - cos_theta*sin_A*sin_phi) );

        // if in canvas & nearer
        if( (0<X&&X<SCREEN_WIDTH) && (0<Y&&Y<SCREEN_HEIGHT) && D>z_buffer[pos] ) {
          z_buffer[pos] = D;
          output[pos] = LUMINANCE[L > 0 ? L : 0];
        }
      }
    }
    cout << "\x1b[H"; // move cursor to upper-left corner
    for(int i=0; i<SCREEN_SIZE+1; i++) {
      cout << (i % SCREEN_WIDTH ? output[i] : '\n');
    }
    sleep_for(milliseconds(TIME_TO_SLEEP));
    A += TWO_PI/360;
    B += TWO_PI/343;
  }
  return EXIT_SUCCESS;
}