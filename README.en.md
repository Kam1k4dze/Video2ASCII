## [Русская версия](README.md)

# Video2ASCII


Video2ASCII allows you to play video in Windows CMD
## Requirements
- [ffmpeg](https://www.gyan.dev/ffmpeg/builds/)
- [OpenCV](https://opencv.org/releases/)


## Installation

#### 1.ffmpeg
 - Download latest build [ffmpeg](https://www.gyan.dev/ffmpeg/builds/)
 - Unpack to `C:\`
 - Add `C:\ffmpeg\bin` to `PATH`

#### 2.OpenCV
- Download and install version `4.5.4` or higher
- Run in `cmd`
```
setx -m OPENCV_DIR C:\opencv\build
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


