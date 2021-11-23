## [Русская версия](README.ru.md)

# Video2ASCII


![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/vadimkacool/Video2ASCII?color=gree)
![GitHub Repo stars](https://img.shields.io/github/stars/vadimkacool/Video2ASCII)


Video2ASCII allows you to play video in Windows CMD

## Examples


https://user-images.githubusercontent.com/40305144/142914078-6e5fd419-4e05-4779-8bc0-9c8110fc5c90.mp4



https://user-images.githubusercontent.com/40305144/142915540-402ae262-9c98-4408-ab40-65cbdecb9fcd.mp4

## Requirements
- [ffmpeg](https://www.gyan.dev/ffmpeg/builds/)
- [OpenCV](https://opencv.org/releases/)


## Installation

### **Download [Video2ASCII witch ffmpeg and OpenCV](https://github.com/vadimkacool/Video2ASCII/releases/latest)**

### OR

#### 1.ffmpeg
 - Download latest build [ffmpeg](https://www.gyan.dev/ffmpeg/builds/)
 - Unpack to `C:\`
 - Add `C:\ffmpeg\bin` to `PATH`

#### 2.OpenCV
- Download and install [OpenCV](https://opencv.org/releases/) version `4.5.4` or higher
- Run in `cmd`
```
setx -m OPENCV_DIR C:\opencv\build\x64\vc15
```

#### 3
- Download compiled [code](https://github.com/vadimkacool/Video2ASCII/releases/latest)

##### OR

- Download the source code
```
git clone https://github.com/vadimkacool/Video2ASCII
```

## Usage

```
Video2ASCII.exe PathToFile Width Height
```
- `PathToFile` - path to file in `""`. Don't use `\`, replace it with `/` or `\\`
- `Width` - The width of the command line in characters.
- `Height` - The height of the command line in characters.

To keep the proportions, when choosing `Width` and `Height`, take into account the size of the font sign in `cmd` in pixels.

You can view and change it in:
- `right-click` on the top panel `cmd` 
  - Properties 
    - Font



