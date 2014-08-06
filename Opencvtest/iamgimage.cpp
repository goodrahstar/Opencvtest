
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>

using namespace cv;

double alpha; /**< Simple contrast control */
int beta;  /**< Simple brightness control */

int main( int argc, char** argv )
{
    // Read image given by user
    // Change the path here to your image, look at form below
    Mat image = imread( "/users/rahulkumar/Desktop/untitled folder/ra.jpg" );
    Mat new_image = Mat::zeros( image.size(), image.type() );
    Mat new_image2 = Mat::ones(image.size(), image.type());
    
    // Initialize values
    std::cout<<" Basic Linear Transforms "<<std::endl;
    std::cout<<"-------------------------"<<std::endl;
    // std::cout<<"* Enter the alpha value [1.0-3.0]: ";std::cin>>alpha;
    //std::cout<<"* Enter the beta value [0-100]: "; std::cin>>beta;
    
    alpha=2.3;
    beta=50;
    
    // Do the operation new_image(i,j) = alpha*image(i,j) + beta
    for( int y = 0; y < image.rows; y++ )
    { for( int x = 0; x < image.cols; x++ )
    { for( int c = 0; c < 3; c++ )
    {
        new_image.at<Vec3b>(y,x)[c] =
        saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
        
        new_image2.at<Vec3b>(y,x)[c] =saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
        
    }
    }
    }
    
    // Create Windows
    namedWindow("Original Image");
    namedWindow("New Image");
    namedWindow("New Image2");
    
    // Show stuff
    imshow("Original Image", image);
    imshow("New Image", new_image);
    imshow("New Image2", new_image2);
    
    // Wait until user press some key
    waitKey();
    return 0;
}
