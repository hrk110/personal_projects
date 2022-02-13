// Compile: clang -o donut donut.c -lm
// (1) change variable name and define some constant.
// (2) slightly modify the order and expression according to donut-math.html.
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

const float R1 = 1, R2 = 2, K2 = 5;
const int screen_height = 22, screen_width = 80;
const int size = screen_height*screen_width;
const int max_x = screen_width*3/8;
// R1: radius of 'cross section of donut'
// R2: radius of 'donut'
// K2: distance between observer and donut.
// K1 = z' = const, which means the distance between observer and screen.
// K1 can be calculated based on screen width in this way:
// max(x)*K1/(K2+0) = (1/2)*screen_width*(3/4)
// max(x) = R1+R2, so K1 is 50.
const float max_angle = 6.28, theta_step = 0.07, phi_step = 0.02;

int main() {
  float A = 0, B = 0;
  float phi, theta;
  int k;
  float z_buf[size]; // stores inverse of distance between nearest point and observer.
  char output[size]; // canvas
  printf("\x1b[2J"); // clear terminal screen.
  for(;;) {
    memset(output, ' ', size);
    memset(z_buf, 0, size*sizeof(float));
    for(theta=0; theta < max_angle; theta += theta_step) {
      for(phi=0; phi < max_angle; phi += phi_step) {
        float sin_phi = sin(phi);
        float cos_phi = cos(phi);
        float sin_theta = sin(theta);
        float cos_theta = cos(theta);
        float sin_A = sin(A);
        float cos_A = cos(A);
        float sin_B = sin(B);
        float cos_B = cos(B);

        float h = R2 + R1*cos_theta;
        float z = cos_A*h*sin_phi + R1*sin_A*sin_theta;
        float D = 1 / (K2 + z); // (distance from observer)^(-1)
        float t = sin_phi*h*sin_A - R1*sin_theta*cos_A;
        float x = cos_phi*h*cos_B + t*sin_B;
        float y = cos_phi*h*sin_B - t*cos_B;
        int X = screen_width/2 + max_x * D * x;
        int Y = screen_height/2 + (max_x/2) * D * y;
        int pos = X + screen_width * Y; // position in output[].

        // Luminance. ranges between [-sqrt(2),sqrt(2)]
        // L = inner_product(N,[0,1,-1]) <= |N||[0,1,-1]| = 1*sqrt(2)
        // max of L should be 12, which is the length of character string.
        // so, multiply 12/sqrt(2) ~~ 8.48.
        int L = 8.4 * ( cos_phi*cos_theta*sin_B - cos_A*cos_theta*sin_phi - sin_A*sin_theta + cos_B*(cos_A*sin_theta - cos_theta*sin_A*sin_phi) );

        // if in canvas & nearer
        if( (0<Y&&Y<22) && (0<X&&X<80) && D>z_buf[pos] ) {
          z_buf[pos] = D;
          output[pos] = ".,-~:;=!*#$@"[L > 0 ? L : 0];
        }
      }
    }
    printf("\x1b[H"); // move cursor to upper-left corner
    for(k=0; k<size; k++) {
      putchar(k % screen_width ? output[k] : '\n');
      A += 0.00004;
      B += 0.00002;
    }
    usleep(30000);
  }
  return 0;
}