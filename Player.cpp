#include "pch.h"
#include "Player.h"
using namespace std;
using namespace cv;
using namespace std::chrono;

//���캯������ʼ����ֵ
Player::Player()
{
	FramesNum = 0;
	FrameWidth = 400;
	FrameHeight = 225;
	speed = 1.0;
	FrameRate = 30.0;
	Myfontsize = 2;
}


//�õ����
void Player::SetStdWindow(HANDLE hd, HWND hwnd)
{
	MyHandle = hd;
	MyHwnd = hwnd;
}


//������������ļ������û�У��ʹ���һ��
void Player::Output_to_file()
{
	ofstream file_txt;
	file_txt.open("set.txt", std::ios::out);
	file_txt << Myfontsize << endl;
	file_txt << speed << endl;
	file_txt << FrameHeight << endl;
	file_txt << FrameWidth << endl;
	file_txt << FrameRate << endl;
	file_txt << file << endl;
	file_txt.close();
}

//���ļ��л�ȡ���������
void Player::Gain_date_from_file()
{
	const int Number_of_int_data = 5;
	//��������洢����
	int data[Number_of_int_data];
	ifstream file_txt;
	try {
		file_txt.open("set.txt");
	}
	catch (exception) {
		cout << "�Ҳ���set.txt�ļ������������б����򲢽��г�ʼ��" << endl;
		return;
	}
	//��ȡ��������
	for (int i = 0; i < Number_of_int_data; i++) {
		file_txt >> data[i];
	}
	string file_info;
	file_txt >> file_info;

	//��ֵ����player����
	Myfontsize = data[0];
	speed = data[1];
	FrameHeight = data[2];
	FrameWidth = data[3];
	FrameRate = data[4];
	file = file_info;
	//���ﲻ�����������ڶ�ȡÿһ֡��ʱ���и���Ϣ��ʾ
	cout << endl;
	file_txt.close();

}

//�õ������С
int Player::Get_Myfontsize()
{
	return Myfontsize;
}

//���������
void Player::Set()
{
	double key = 1;
	cout << "�Ƿ���Ҫ���г�ʼ��������1���г�ʼ�����������ã�����ʹ����һ�ε����ã���99���뿪����ģʽ��" << endl;
	cout << endl;
	cout << "ע�⣬����ǵ�һ��ʹ�øó��򣬱����ʼ����" << endl;
	cin >> key;
	system("cls");
	if (key == 1) 
	{
		Input_file();
		
	}
	else if (key == 99) {
		cout << "ע�⣬�������˿�����ģʽ����" << endl;
		system("pause");
		system("cls");
		Input_file();
		Set_speed();
		SetPixelSize();
		Set_frame_width();
		Set_frame_height();
		Set_framerate();
		Output_to_file();
	}
	else
	{
		Gain_date_from_file();
	}

}

//�����ļ���Ϣ
void Player::Input_file()
{
	cout << "��һ���������ļ�·�����ļ�����" << endl;
	cout << endl;
	cout << "��ʾ����򵥵ķ�ʽ�ǽ���Ƶ����ͬһ·����Ȼ��ֱ�������ļ�����ʹ�����·�������磺��Ƶ.mp4" << endl;
	cout << endl;
	cout << "������Ҫ������������·��������·����" << endl;
	cout << "���磺C:/Users/zhyan/Desktop/ConsoleVideoPlayer/ConsoleVideoPlayer/��Ƶ.mp4" << endl;
	cout << "�����������ļ�·�����ļ�����";
	cin >> file;
	//ͨ���ļ���������Ƶ������·�������·����
	VideoCapture vc;

	while (!vc.open(file)) {
		cout << "��Ƶ·����ʽ�������Ƶ������" << endl;
		cout << "���������룺";
		cin >> file;
	}
	system("cls");
}



//�õ��ļ���Ϣ
string Player::Get_file_info()
{
	return file;
}

//���ò����ٶ�
void Player::Set_speed()
{
	string str;
	double d;
	while (1) {
		cout << "��������Ƶ�Ĳ����ٶȣ���������0.5-2.0��һ�����֣�" << endl;
		cin >> str;

		try {
			d = stod(str);
			if (d > 2 || d < 0.5) {
				cout << "����������������룺";
				continue;
			}
			break;
		}
		catch (exception) {
			cout << "����������������룺";
			continue;
		}
	}
	speed = d;
}

//���ò����ٶȣ���������
void Player::Set_speed(double sp)
{
	speed = sp;
}

//���ز����ٶ�
double Player::Get_speed()
{
	return speed;
}

//����ÿһ֡�Ŀ��
void Player::Set_frame_width()
{
	//�ṩ�Ƽ����õ���Ļ��С
	switch (Myfontsize) {
	case 1:
		cout << "�Ƽ����800���߶�450" << endl;
		break;
	case 2:
		cout << "�Ƽ����480���߶�270" << endl;
		break;
	case 3:
		cout << "�Ƽ����320���߶�180" << endl;
		break;
	case 4:
		cout << "�Ƽ����240,�߶�135" << endl;
		break;
	case 5:
		cout << "�Ƽ����160���߶�90" << endl;
		break;
	case 6:
		cout << "�Ƽ����160���߶�90" << endl;
		break;
	case 7:
		cout << "�Ƽ����160���߶�90" << endl;
		break;
	case 8:
		cout << "�Ƽ����160���߶�90" << endl;
		break;
	case 9:
		cout << "�Ƽ����120���߶�72" << endl;
		break;
	}
	cout << "ע�⣺������ſ��ٻ������������С��Ⱥ͸߶�" << endl;
	int w;
	string str;
	//�û������������ݴ���
	while (1) {
		cout << "����������Ҫ����Ƶ��ȣ�";
		cin >> str;
		try {
			w = stoi(str);
			if (w > 2000 || w < 20) {
				cout << "���벻��������������" << endl;
				continue;

			}
			break;
		}
		catch (exception) {
			cout << "���벻��������������" << endl;
			continue;
		}
	}
	FrameWidth = w;
}

//����ÿһ֡�ĸ߶�
void Player::Set_frame_height()
{
	string str;
	int h;
	
	//�û��������ݴ���
	while (1) {
		cout << "����������Ҫ����Ƶ�߶ȣ�";
		cin >> str;
		try {
			h = stoi(str);
			if (h > 2000 || h < 20) {
				cout << "���벻��������������" << endl;
				continue;

			}
			break;
		}
		catch (exception) {
			cout << "���벻��������������" << endl;
			continue;
		}
	}
	FrameHeight = h;
	system("cls");
}

//����ÿһ֡�Ŀ�ȣ���������
void Player::Set_frame_width(int w)
{
	FrameWidth = w;
}

//����ÿһ֡�ĸ߶ȣ���������
void Player::Set_frame_height(int h)
{
	FrameHeight = h;
}

//����֡�Ŀ��
int Player::Get_frame_width()
{
	return FrameWidth;
}

//����֡�ĸ߶�
int Player::Get_frame_height()
{
	return FrameHeight;
}

//����֡�ʣ��û�������
void Player::Set_framerate()
{
	cout << "������֡�ʣ�һ�벥�Ŷ���֡��" << endl;
	cout << "ע�⣬ʵ��֡������������йأ�����֡�ʴ���20��С��40" << endl;
	int f;
	string str;

	//�û��������ݴ���
	while (1) {
		cout << "����������Ҫ����Ƶ֡�ʣ�";
		cin >> str;
		try {
			f = stoi(str);
			if (f>65||f<0) {
				cout << "���벻��������������" << endl;
				continue;

			}
			break;
		}
		catch (exception) {
			cout << "���벻��������������" << endl;
			continue;
		}
	}
	FrameRate = f;
	system("cls");
}

//����֡��
void Player::Set_framerate(int f)
{
	FrameRate = f;
}

//�õ�֡��
int Player::Get_framerate()
{
	return FrameRate;
}

//��ʾ���õ���Ƶ����
void Player::show_info()
{
	cout << "�ļ���Ϣ��" << file << endl;
	cout << "���ش�С:" << Myfontsize << endl;
	cout << "�����ٶ�:" << speed << endl;
	cout << "��Ƶ�߶ȣ�" << FrameHeight << endl;
	cout << "��Ƶ��ȣ�" << FrameWidth << endl;
	cout << "֡�ʣ�" << FrameRate << endl;
}

//���ÿ���̨��Ϣ��ȫ����
void Player::SetWindowConfig()
{
	//�õ���Ļ����
	int screen_width = GetSystemMetrics(SM_CXSCREEN);

	//�õ���Ļ���
	int screen_length = GetSystemMetrics(SM_CYSCREEN);

	//��ȡhwnd�Ĵ�����Ϣ��GWL_STYLE��ȡ���ڷ����Ϣ
	//ע�⣺������һ�������ƴ���010101010101011�ȵȹ�32λ���ɵģ�ÿһλ����һ������
	LONG  l_Winstyle = GetWindowLong(MyHwnd, GWL_STYLE);

	//��������
	SetWindowLong(MyHwnd, GWL_STYLE, (l_Winstyle | WS_POPUP | WS_MAXIMIZE));

	//��������
	SetWindowPos(MyHwnd, HWND_TOP, 0, 0, screen_width, screen_length, 0);
}

//����Ƶ�л�ȡÿһ֡�����Ҵ������洢���ַ���������
void Player::GetFrameFromVideo()
{
	//ͨ���ļ���������Ƶ������·�������·����
	VideoCapture vc;
	try {
		vc.open(file);
	}
	catch (Exception) {
		cout << "��Ƶ·����ʽ�������Ƶ������" << endl;
		return;
	}

	//������ҪԤ�����֡
	Mat frameRaw;

	//�����Ƶ��֡��
	//CAP_PROP_FRAME_COUNT��opencv�궨���ץȡ֡������
	FramesNum = vc.get(CAP_PROP_FRAME_COUNT);
	Frames.resize(FramesNum + 2);

	//�������Ϊ���ɼ�,1��ʾ����ȣ�false��ʾ���ɼ�
	_CONSOLE_CURSOR_INFO cf = { 1,false };


	//ʹ��vector����������ÿһ֡
	//+3��Ϊ������
	vector<string> allframe(FramesNum + 3);

	//��¼��ʼʱ��
	double start = GetTickCount64();

	//������
	int framediff = 0, j, k;

	//����洢һ֡���ַ���
	string output = "";

	//����һ����ֵ���ַ���
	string sign[2] = { " ","#" };

	//CAP_PROP_POS_AVI_RATIO����Ƶ���λ��,0~1��һ��ֵ
	//����дһ����Ϊ������ 
	//������forѭ�����ڶ�ȡ��Ƶÿһ֡������ŵ������
	for (int i = 0; i < FramesNum && vc.get(CAP_PROP_POS_AVI_RATIO) < (1 - 10E-6); i++) {
		Mat frameGray, frameOut,frameRaw;
		//�������Ϊ���ɼ�
		SetConsoleCursorInfo(MyHandle, &cf);

		//�����һ֡�������δ��ù������ȡ��һ֡
		vc >> frameRaw;

		//��ֹ��Ƶ��֡��2019��6��1��19:20��׷�ٶ̵����debug����
		//dim��ά������͸߸�����һ��ά��
		if (frameRaw.dims == 0)
			break;
		//����ǰRGB֡ת��Ϊ�Ҷ�ͼ��
		cvtColor(frameRaw, frameGray, 7);

		//��С�ߴ�
		resize(frameGray, frameOut, Size(FrameWidth, FrameHeight));

		//��һ��forѭ�����б������ڶ���forѭ�����б���
		for (j = 0; j < FrameHeight; j++) {
			for (k = 0; k < FrameWidth; k++) {

				//��ֵ����ʾ���أ��Ҷȴ���127����ʾ
				if (frameOut.at<bool>(j, k) > 127) {
					output += "#";
					//putchar(' ');
				}
				else {
					output += " ";
					//putchar(' ');
				}
			}
			output += "\n";
		}
		Frames[i] = output;
		output = "";

	}
}

//ʹ����֡�㷨���з�ӳ��ԭ��ÿ�뻮��Ϊn�Σ����������һ֡����ʱ�䣬����ͣ����ֱ����һ��
void Player::PlayVideo()
{
	//����
	system("cls");

	//Ӧ����������
	SetPixelSize(Get_Myfontsize());

	//ȫ��
	SetWindowConfig();

	//���嵱ǰ֡��
	int framediff = 0, totalFrameNum = FramesNum, start = 0, startDisplay = 0,
		delay = 0;
	double span = 1000 / ((FrameRate + 1) * speed);

	//�����ƣ��趨����СΪ1�����ɼ�
	_CONSOLE_CURSOR_INFO cf = { 1,false };

	//startDisplay = GetTickCount64();
	auto startTime = high_resolution_clock::now();
	for (int i = 0; i < totalFrameNum; i++) {
		//ȷ��ÿһ֡����ʾ��궼���ɼ�
		//startDisplay = GetTickCount64();
		SetConsoleCursorInfo(MyHandle, &cf);

		//�ѹ��λ�ö����ڣ�0,0��λ�ã�����ʵ������Ч��
		SetConsoleCursorPosition(MyHandle, { 0,0 });


		//�������
		cout << Frames[i] << endl;
		auto endTime = high_resolution_clock::now();
		auto ftime = duration_cast<duration<double, ratio<1, 1000>>>(endTime - startTime).count();
		if (ftime < span) this_thread::sleep_for(milliseconds((int)(span - ftime)));


		//չʾĿǰ��֡��������֡��
		if (GetTickCount64() - start >= 1000) {
			string temp = "frame��" + to_string(i) + "  fps��" + to_string(i - framediff) + "display frame time:" + to_string(ftime);
			SetConsoleTitleA(temp.c_str());
			framediff = i + 1;
			start = GetTickCount64();
			//system("cls");

		}
		startTime = high_resolution_clock::now();
	}
	system("cls");
	SetPixelSize(30);
	cout << "��Ƶ�Ѳ�����ϣ���л����ʹ�ã�" << endl;
}

//���������С�������ص㣩
void Player::SetPixelSize()
{
	cout << "ע�⣺���ص�ϵ͵Ļ�Ҫ��һ����������" << endl;
	cout << "���������ص��С���޶���Χ1-9��" << endl;
	int size;
	string str;
	while (1) {
		cin >> str;
		try {
			size = stoi(str);
			if (size > 9 || size < 1) {
				cout << "���벻�������������루�޶���Χ1-9��" << endl;
				continue;
			}
			break;
		}
		catch (exception) {
			cout << "���벻��������������:" << endl;
			continue;
		}
	}
	Myfontsize = size;
	system("cls");
}

//�������壨���ص㣩��С����������
void Player::SetPixelSize(int size)
{
	Myfontsize = size;
	//��������
	WCHAR myFont[] = TEXT("Arial");
	//ʹ����������API����Ľṹ��
	_CONSOLE_FONT_INFOEX fontinfo = { sizeof(CONSOLE_FONT_INFOEX) ,
	1,
	{Myfontsize,Myfontsize},
	TMPF_FIXED_PITCH,
	400,
	*myFont };
	SetCurrentConsoleFontEx(MyHandle, false, &fontinfo);
}