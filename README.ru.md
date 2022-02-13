## [English readme](README.md)

# Video2ASCII

![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)
![GitHub release (latest by date)](https://img.shields.io/github/v/release/vadimkacool/Video2ASCII?color=gree)
![GitHub Repo stars](https://img.shields.io/github/stars/vadimkacool/Video2ASCII)

Video2ASCII позволяет проигрывать видео в Windows CMD

## Примеры


https://user-images.githubusercontent.com/40305144/142914078-6e5fd419-4e05-4779-8bc0-9c8110fc5c90.mp4



https://user-images.githubusercontent.com/40305144/142915540-402ae262-9c98-4408-ab40-65cbdecb9fcd.mp4
## Требования
- [ffmpeg](https://www.gyan.dev/ffmpeg/builds/)
- [OpenCV](https://opencv.org/releases/)
## Установка
### **Скачайте [Video2ASCII witch ffmpeg and OpenCV](https://github.com/vadimkacool/Video2ASCII/releases/latest)**

### Или установите их вручную

- #### 1.ffmpeg
   - Скачайте последний билд [ffmpeg](https://www.gyan.dev/ffmpeg/builds/)
   - Распакуйте в `C:\`
   - Добавте `C:\ffmpeg\bin` в `PATH`

- #### 2.OpenCV
  - Скачайте и установите версию [OpenCV](https://opencv.org/releases/) `4.5.4`
  - Выполните в `cmd`
```cmd
setx -m OPENCV_DIR C:\opencv\build\x64\vc15
```

- #### 3
  - Скачайте скомпилированный [код](https://github.com/vadimkacool/Video2ASCII/releases/latest)

- ##### или

  - Скачайте исходный код
```cmd
git clone https://github.com/vadimkacool/Video2ASCII
```

## Использование

```cmd
Video2ASCII.exe PathToFile Width Height
```
- `PathToFile` - путь до файла в "". Не используйте `\`, замените его на `/` или `\\`
- `Width` - Ширина командной строки в символах
- `Height` - Высота командной строки в символах

Для сохранения пропорций, при выборе `Width` и `Height` берите во внимание размер знака шрифта `cmd` в пикселях.

- `ПКМ` по верхней панели `cmd` Свойства 
  - Шрифт


Здесь же, можно изменить шрифт и его размер




