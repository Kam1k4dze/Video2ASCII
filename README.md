# Video2ASCII


## Video2ASCII позволяет проигрывать видео в Windows CMD

## Требования
- [ffmpeg](https://www.gyan.dev/ffmpeg/builds/)
- [OpenCV](https://opencv.org/releases/)
## Установка


#### 1.ffmpeg
 - Скачайте последний билд [ffmpeg](https://www.gyan.dev/ffmpeg/builds/)
 - Распакуйте в `C:\`
 - Добавте `C:\ffmpeg\bin` в `PATH`

#### 2.OpenCV
- Скачайте и установите версию `4.5.4` или новее
- Выполните в `cmd`
```
setx -m OPENCV_DIR C:\opencv\build
```

#### 3
- Скачайте скомпилированный [код](https://github.com/vadimkacool/Video2ASCII/releases/latest)

##### или

- Скачайте исходный код
```
git clone https://github.com/vadimkacool/Video2ASCII
```

## Использование

```
Video2ASCII.exe PathToFile Width Height
```
- `PathToFile` - путь до файла
- `Width` - Ширина командной строки в символах
- `Height` - Высота командной строки в символах

Для сохранения пропорций, при выборе `Width` и `Height` берите во внимание размер знака шрифта `cmd` в пикселях.

- `ПКМ` по верхней панели `cmd` Свойства 
  - Шрифт


Здесь же, можно изменить шрифт и его размер
