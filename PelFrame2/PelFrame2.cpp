#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

int main() {
	std::string videoPath = "video.mp4";
	cv::VideoCapture videoCapture(videoPath);

	if (!videoCapture.isOpened()) {
		std::cout << "Failed to open the video file." << std::endl;
		return -1;
	}

	double frameCount = videoCapture.get(cv::CAP_PROP_FRAME_COUNT);
	double fps = videoCapture.get(cv::CAP_PROP_FPS);
	int width = videoCapture.get(cv::CAP_PROP_FRAME_WIDTH);
	int height = videoCapture.get(cv::CAP_PROP_FRAME_HEIGHT);
	std::string codec = videoCapture.getBackendName();

	std::cout << "Frame count: " << frameCount << std::endl;
	std::cout << "FPS: " << fps << std::endl;
	std::cout << "Width: " << width << std::endl;
	std::cout << "Height: " << height << std::endl;
	std::cout << "Codec: " << codec << std::endl;

	cv::Mat frame;
	int frameNumber = 0;

	while (videoCapture.read(frame)) {
		cv::putText(frame, "Frame: " + std::to_string(frameNumber), cv::Point(10, 30),
			cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 2);
		cv::putText(frame, "Resolution: " + std::to_string(width) + "x" + std::to_string(height),
			cv::Point(10, 60), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 2);
		cv::putText(frame, "Codec: " + codec, cv::Point(10, 90),
			cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 2);
		cv::putText(frame, "FPS: " + std::to_string(fps), cv::Point(10, 120),
			cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255), 2);

		cv::imshow("Video Frame", frame);
		cv::waitKey(25);

		frameNumber++;
	}

	videoCapture.release();
	cv::destroyAllWindows();

	return 0;
}