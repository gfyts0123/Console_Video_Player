#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;
//ʹ��opencv�������ռ�
using namespace cv;
class Player {
public:

	//���캯��
	Player();

	//��ȡ����̨��ǰ̨���ھ��
	void SetStdWindow(HANDLE hd, HWND hwnd);

	//���п���̨���ڵ�һЩ���ã�����ȫ��
	void SetWindowConfig();

	//���ļ��л�ȡÿһ֡������Ϊ�ַ�������������
	void GetFrameFromVideo();

	//��ӳ��Ƶ
	void PlayVideo();

	//���������С���û�������
	void SetPixelSize();

	//���������С
	void SetPixelSize(int size);

	//������ݵ��ı�
	void Output_to_file();

	//���ı��л�ȡ����
	void Gain_date_from_file();

	//�õ���ǰ�����С
	int Get_Myfontsize();

	//�û��趨ģʽ
	void Set();

	//�����ļ�·�����ļ���
	void Input_file();

	//�õ��ļ�·�����ļ���
	string Get_file_info();

	//������Ƶ�����ٶ�(�û�����)
	void Set_speed();

	//������Ƶ�����ٶȣ���������
	void Set_speed(double sp);

	//�õ���Ƶ�ٶ�
	double Get_speed();

	//������Ƶ��ȣ��û�������
	void Set_frame_width();

	//������Ƶ�߶ȣ��û�������
	void Set_frame_height();

	//������Ƶ��ȣ���������
	void Set_frame_width(int w);

	//������Ƶ�߶ȣ���������
	void Set_frame_height(int h);

	//�õ���Ƶ���
	int Get_frame_width();

	//�õ���Ƶ�߶�
	int Get_frame_height();

	//����֡�ʣ��û�������
	void Set_framerate();

	//����֡�ʣ���������
	void Set_framerate(int f);

	//�õ���ǰ֡��
	int Get_framerate();

	//չʾ����
	void show_info();

private:

	//�������֡�����õĵ��ַ�������
	vector<string> Frames;

	//֡����
	int FramesNum;

	//֡���
	int FrameWidth;

	//֡�߶�
	int FrameHeight;

	//��ӳ�ٶ�
	double speed;

	//֡��
	double FrameRate;

	//ǰ̨���ھ��
	HWND MyHwnd;

	//����̨���
	HANDLE MyHandle;

	//���ص��С
	int Myfontsize;

	//��Ƶ·��������
	string file;
};

#endif 