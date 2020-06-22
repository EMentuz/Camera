#include "pch.h"
#include <opencv2/opencv.hpp>
#include <opencv/cv.hpp>
#include <opencv2/highgui.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	//Open the default video camera
	VideoCapture cap(0);

	// if not success, exit program
	if (cap.isOpened() == false)
	{
		cout << "Cannot open the video camera" << endl;
		cin.get(); //wait for any key press
		return -1;
	}

	double dWidth = cap.get(CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;

	

	while (true)
	{
		Mat frame;
		bool bSuccess = cap.read(frame); // read a new frame from video 
						// do any processing
		imwrite("image.png", frame);
			// Read the image file
		Mat image = imread("image.png");

		// Check for failure
		if (image.empty())
		{
			cout << "Could not open or find the image" << endl;
			cin.get();  //wait for any key press
			return -1;
		}

		String windowName = "CAMERA";  //Name of the window

		namedWindow(windowName);  // Create a window

		imshow(windowName, image); // Show our image inside the created window.
		if (waitKey(33) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}
		
		
	}
	




		
	return 0;

}

