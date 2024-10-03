#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std ;
using namespace cv  ;
int main( int argc , char* argv[] ) {
    Mat png = imread("tiger.png");
    Mat img(png.rows, png.cols, CV_8UC3, Scalar(255,255,255));
    
    std::ofstream file("tiger_histogram.txt");

    // Read the data from the file and store it in the array.
    int vals[255];
    for (int i = 0; i < png.rows; i++) {
        for (int j = 0; j < png.cols; j++) {
            int val = png.at<uchar>(i, j);            
            vals[val] = vals[val] + 1;
        }
    }
    
    for (int i = 0; i <= 255; i++) {
        cout << vals[i]/(png.rows*png.cols) << endl;
    }
    
    
    file.close();
    
    /*
    RNG rng(1617620);
    cout << png.rows << " " << png.cols << endl;
    
     // Create a file input object.
    std::ifstream file("blue_noise.txt");

    // Open the file.
    if (!file.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    // Create a 2D array to store the data.
    int matrix[64][64];

    // Read the data from the file and store it in the array.
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            file >> matrix[i][j];
        }
    }

    // Close the file.
    file.close();
    
    for (int row = 0; row < png.rows; row++) {
        for(int col = 0; col < png.cols; col++) {
            Vec3b pixel = png.at<Vec3b>(row, col);
            int val = (int) ((pixel[0] + pixel[1] + pixel[2])/3);
            
            unsigned int x = rng.next();
            int limit = x * 255.0 / UINT_MAX;;
            // matrix[row%64][col%64]
            if(val < matrix[row%64][col%64]) {
                val = 0;
            } else {
                val = 255;
            }
            
            img.at<Vec3b>(row, col) = {val, val, val};
        }
    }
            
    imwrite("dithered_vader.png", img);
    
    Mat png1 = imread("wolf.png");
    for (int row = 0; row < png1.rows; row++) {
        for(int col = 0; col < png1.cols; col++) {
            Vec3b pixel = png1.at<Vec3b>(row, col);
            int val = (int) ((pixel[0] + pixel[1] + pixel[2])/3);
            
            unsigned int x = rng.next();
            int limit = x * 255.0 / UINT_MAX;;
            // matrix[row%64][col%64]
            if(val < matrix[row%64][col%64]) {
                val = 0;
            } else {
                val = 255;
            }
            
            img.at<Vec3b>(row, col) = {val, val, val};
        }
    }
            
    imwrite("dithered_wolf.png", img);
    
    Mat png2 = imread("tiger.png");
    for (int row = 0; row < png2.rows; row++) {
        for(int col = 0; col < png2.cols; col++) {
            Vec3b pixel = png2.at<Vec3b>(row, col);
            int val = (int) ((pixel[0] + pixel[1] + pixel[2])/3);
            
            unsigned int x = rng.next();
            int limit = x * 255.0 / UINT_MAX;;
            // matrix[row%64][col%64]
            if(val < matrix[row%64][col%64]) {
                val = 0;
            } else {
                val = 255;
            }
            
            img.at<Vec3b>(row, col) = {val, val, val};
        }
    }
            
    imwrite("dithered_tiger.png", img);
    
    Mat png3 = imread("yoda.png");
    for (int row = 0; row < png3.rows; row++) {
        for(int col = 0; col < png3.cols; col++) {
            Vec3b pixel = png3.at<Vec3b>(row, col);
            int val = (int) ((pixel[0] + pixel[1] + pixel[2])/3);
            
            unsigned int x = rng.next();
            int limit = x * 255.0 / UINT_MAX;;
            // matrix[row%64][col%64]
            if(val < matrix[row%64][col%64]) {
                val = 0;
            } else {
                val = 255;
            }
            
            img.at<Vec3b>(row, col) = {val, val, val};
        }
    }
    
            
    imwrite("dithered_yoda.png", img);
    */
    
    return 0;
}