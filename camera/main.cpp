//�����ܣ�ʵʱ��ȡ˫Ŀ��Ƶ,���������ڷֱ���ʾ��Camera����Camera����Ƶ��
//�ٷ���ַ�������� www.FpgaLena.com
//����汾��2016-11-V1.0
//��ע�������49�У���Ҫ���ݵ�������camera��������в������á�

#include <iostream>
#include <string>
#include <sstream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>    
#include <opencv2/opencv.hpp> 

using namespace std;
using namespace cv;

const char* keys =
{
	"{help h usage ? | | print this message}"
	"{@video | | Video file, if not defined try to use webcamera}"
};

int main(int argc, const char** argv)            //����������
{
	CommandLineParser parser(argc, argv, keys);
	parser.about("Video Capture");

	if (parser.has("help"))                      //������Ϣ
	{
		parser.printMessage();
		return 0;
	}
	String videoFile = parser.get<String>(0);

	if (!parser.check())
	{
		parser.printErrors();
		return 0;
	}

	VideoCapture cap;
	if (videoFile != "")
	{
		cap.open(videoFile);
	}
	else
	{
		//--�˴���Ҫ���ݵ���ʵ�����ӳ����豸��������ɿͻ����н��в�������------------------------------------
		cap.open(0);                             //������������Դ�����ͷһ����Ϊ0���������ͷ���Ϊ1���������ԣ�Ҳ�����Ƿ������ģ�
	    //--------------------------------------------------------------------------------------

		cap.set(CV_CAP_PROP_FRAME_WIDTH, 2560);  //���ò�����Ƶ�Ŀ��
		cap.set(CV_CAP_PROP_FRAME_HEIGHT, 720);  //���ò�����Ƶ�ĸ߶�
	}
	if (!cap.isOpened())                         //�ж��Ƿ�ɹ������
	{ 
		return -1;
	}

	Mat frame,frame_L,frame_R;
	
	cap >> frame;                                //���������һ֡ͼ��

	Mat grayImage;                               //���ڴ�ŻҶ�����

	double fScale = 0.5;                         //��������ϵ������2560*720ͼ�����������ʾ��2560*720ͼ�����Һ�����ֱ��ʽ�Сʱ����Ҫ���Ųſ�������ʾ����Ļ��  
	Size dsize = Size(frame.cols*fScale, frame.rows*fScale);
	Mat imagedst = Mat(dsize, CV_32S);
	resize(frame, imagedst, dsize);

	while (1)
	{
		cap >> frame;                            //���������һ֡ͼ��
		resize(frame, imagedst, dsize);          //�Բ�׽��ͼ��������Ų���

		frame_L = imagedst( Rect(0, 0, 640, 360));  //��ȡ���ź���Camera��ͼ��
		namedWindow("Video_L", 1); 
	    imshow("Video_L", frame_L);

		frame_R = imagedst(Rect(640, 0, 640, 360)); //��ȡ���ź���Camera��ͼ��
		namedWindow("Video_R", 2); 
		imshow("Video_R", frame_R);

		if (waitKey(30) >= 0) break;
	}

	cap.release();                               //�ͷŶ�����Ŀ���
	return 0;
}
