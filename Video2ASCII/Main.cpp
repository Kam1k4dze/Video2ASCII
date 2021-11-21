#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>

#pragma comment(lib, "Winmm.lib")

using namespace cv;
using std::vector;
using std::string;
using std::cout;
using std::endl;


char ascii[13] = { '@', '$', '#', '*', '!', '=', ';', ':', '~', '-', ',', '.', ' ' };

int width = 0;
int	height = 0;
float fps = 0;
int frame_count = 0;
vector <string> out;
string frame_str;

char setascii(int x) {
	int i = round(((255 - x) * 13) / 256);
	return ascii[i];
}

int setdelay(float fps) {
	return static_cast<int>(1000 / fps);

}
std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}



LPCWSTR setname(string name) {
	std::wstring stemp = s2ws(name); //wstring to LPCWSTR
	LPCWSTR name_LPCWSTR = stemp.c_str();
	return name_LPCWSTR;
}





void print(string name, float fps) {
	int tic = 0;
	int toc = 0;
	int s1 = GetTickCount64();
	int startTime;
	int st_delay = setdelay(fps);
	int delay = 0;
	//HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//DWORD written = 0;
	int len = strlen(out[0].c_str());
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	timeBeginPeriod(1);

	PlaySoundA((LPCSTR)name.c_str(), NULL, SND_FILENAME | SND_ASYNC);

	for (int i = 0; i < out.size(); ++i) {
		startTime = GetTickCount64();
		delay = st_delay;
		delay += tic;
		tic = 0;


		//WriteConsoleA(stdOut, out[i].c_str(), strlen(out[i].c_str()), &written, NULL);
		WriteConsoleOutputCharacter(hConsole, setname(out[i]), len, { 0, 0 }, &dwBytesWritten);
		toc = (GetTickCount64() - startTime);
		if ((delay - toc) >= 0) {
			delay -= toc;
		}
		else {
			tic = delay - toc;
			continue;
		}
		Sleep(delay);

	}
	timeEndPeriod(1);
	int s2 = GetTickCount64();
	std::cout << (s2 - s1) << "ms\n";
}




void input_video(string filename, int cols, int rows) {

	VideoCapture cap(filename.c_str());

	if (!cap.isOpened())
	{
		cout << "Error opening video file" << endl;
		return;
	}


	width = cap.get(3);
	height = cap.get(4);
	fps = cap.get(5);
	frame_count = cap.get(7);




	while (true) {

		Mat frame, frame_gray, frame_gray_res;
		cap >> frame;
		if (frame.empty()) {
			break;
		}

		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
		Size ff(cols, rows);
		resize(frame_gray, frame_gray_res, ff, INTER_AREA);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t n = 0; n < cols; n++)
			{
				frame_str.push_back(setascii(frame_gray_res.at<uchar>(i, n)));

			}
		}
		out.push_back(frame_str);
		frame_str.clear();


	}




}





int main(int argc, char** argv)
{


	if (argc == 4) {


		string filename1 = argv[1];
		string filename2 = filename1.substr(0, filename1.find_last_of(".")) + ".wav";

		string ffmpeg = "ffmpeg -y -i \"" + filename1 + "\" -ac 2 -f wav \"" + filename2 + "\"";
		cout << filename1 << endl << filename2 << endl << ffmpeg;
		//return 2;
		system(("mode con cols=" + string(argv[2]) + "lines=" + string(argv[3])).c_str());
		system(ffmpeg.c_str());


		input_video(filename1, atoi(argv[2]), atoi(argv[3]));
		print(filename2, fps);
	}
	else
	{
		cout << "Usage: Video2ASCII.exe FILENAME WIDTH HEIGHT";
	}

	return 0;
}
