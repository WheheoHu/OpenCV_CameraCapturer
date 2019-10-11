#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>




int main() {

	//init cameracapturer
	cv::VideoCapture capture(2);
	capture.set(cv::CAP_PROP_FRAME_WIDTH, 1920);
	capture.set(cv::CAP_PROP_FRAME_HEIGHT, 1080);

	//init videowriter
	std::string filename = "test.mp4";
	cv::Size videoSize(capture.get(cv::CAP_PROP_FRAME_WIDTH), capture.get(cv::CAP_PROP_FRAME_HEIGHT));
	double frame_rate = 30;
	cv::VideoWriter videoWriter(filename, cv::CAP_OPENCV_MJPEG, frame_rate, videoSize);


	while (true)
	{
		cv::Mat frame;
		capture >> frame;
		cv::imshow("camera", frame);
		videoWriter.write(frame);
		

		//exit with ESC key pressed and save last frame as jpg file
		if (cv::waitKey(1) == 27) {
			imwrite("output.jpg", frame);
			break;
		}
	}
	videoWriter.release();
	capture.release();

	cv::destroyAllWindows();
	return 0;
}