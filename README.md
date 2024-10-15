# A Simple CAN Signal Decoder

![Demo Image](https://github.com/Canninfodder9487/CAN_Data_Decode_Tool/blob/main/Image/UI_Image.jpg)

## What does this do

This is a small project with GUI for decoding Hex CAN Signals into result.

## Intent

This project is a small practice in C++.

## Usage
1. Fill in all information needed for decoding (Offset, Resolution, Hex Data)
2. Minimum and Maximum values are optional for checking value.
3. Click "Decode". The calculated value will be print in Result Region.

## Build in local
1. Install Qt Library (Qt5)
2. Use g++ to compile

```
{g++ path} -g {main.cpp path} ${fileDirname}/Resource.o -std=c++20 -mwindows -o {output directory}/CAN_Decode_Tool.exe -I {Qt5 include path} -I {std C++ library include path} -L {Qt5 bin path} -L {Qt5 plugins path} -L {std C++ library bin path} -l Qt5Widgets -l Qt5Core -l Qt5Gui -l gmpxx
```

3. Use windeployqt to collect all dependencies to output directory.