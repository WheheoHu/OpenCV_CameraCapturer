#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main() {

	//init cameracapturer
	VideoCapture capture(0);
	capture.set(CAP_PROP_FRAME_WIDTH, 1920);
	capture.set(CAP_PROP_FRAME_HEIGHT, 1080);

	//init videowriter
	String filename = "test.mp4";
	cv::Size videoSize(capture.get(CAP_PROP_FRAME_WIDTH), capture.get(CAP_PROP_FRAME_HEIGHT));
	double frame_rate = 30;
	VideoWriter videoWriter(filename, CAP_OPENCV_MJPEG, frame_rate, videoSize);


	while (true)
	{
		Mat frame;
		capture >> frame;
		imshow("camera", frame);
		videoWriter.write(frame);
		

		//exit with ESC key pressed
		if (waitKey(1) == 27)
			break;
	}
	videoWriter.release();
	capture.release();

	destroyAllWindows();
	return 0;
}