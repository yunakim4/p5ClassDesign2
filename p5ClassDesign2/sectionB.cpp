#include "sectionB.h"
#include <iostream>
#include <string>
#include <sstream>
ImageMD::ImageMD(std::string file, std::string imgType, int month, int day, int year, double sizeMB, std::string author, int width, int height, std::string aSize, std::string expTime, int isoValue, bool flash)
    : _file{ file }, _imgType{ imgType }, _month{ month }, _day{ day }, _year{ year }, _sizeMB{ sizeMB }, _author{ author }, _width{ width }, _height{ height }, _aSize{ aSize }, _expTime{ expTime }, _isoValue{ isoValue }, _flash{ flash } { }

std::string ImageMD::getFile() const{
    return _file;
}

void ImageMD::setFile(std::string file) {
    _file = file;

}

std::string ImageMD::getImgType() const {
    return _imgType;

}

void ImageMD::setImgType(std::string imgType) {
    if (imgType[0] == 'P' && imgType[1] == 'N' && imgType[2] == 'G') {
        _imgType = imgType;

    }
    else if (imgType[0] == 'G' && imgType[1] == 'I' && imgType[2] == 'F') {
        _imgType = imgType;

    }
    else if (imgType[0] == 'J' && imgType[1] == 'P' && imgType[2] == 'E' && imgType[3] == 'G') {
        _imgType = imgType;

    }
    else {
        std::cout << "Error (Not able to set value) Invalid Format of Image Type \n";

    }
}

int ImageMD::getMonth() const{
    return _month;
}

void ImageMD::setMonth(int month) {
    if (month > 0 && month < 13) {
        _month = month;
    }
    else {
        std::cout << "Error (Not able to set value) Invalid Format of Month \n";

    }
}
int ImageMD::getDay() const {
    return _day;
}

void ImageMD::setDay(int day, ImageMD imageMD) {
    int month = imageMD.getMonth();
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day <= 31 && day > 0) {
            _day = day;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day <= 30 && day > 0) {
            _day = day;
        }
    }
    if (month == 2) {
        if (imageMD.getYear() % 4 == 0) {
            if (day <= 29 && day > 0) {
                _day = day;
            }
        }
        else {
            if (day <= 28 && day > 0) {
                _day = day;
            }
        }
    }
    else {
        std::cout << "Error (Not able to set value) Invalid Format of Day \n";

    }

}

int ImageMD::getYear() const {
    return _year;
}

void ImageMD::setYear(int year) {
    if (year > 0) {
        _year = year;
    }
    else {
        std::cout << "Error (Not able to set value) Invalid Format of Year \n";

    }
}

double ImageMD::getSizeMB() const {
    return _sizeMB;
}

void ImageMD::setSizeMB(double sizeMB) {
    if (sizeMB >= 0) {
        _sizeMB = sizeMB;
    }
    else {
        std::cout << "Error (Not able to set value) Invalid Format of Size in MB \n";

    }
}

std::string ImageMD::getAuthor() const {
    return _author;
}

void ImageMD::setAuthor(std::string author) {
    _author = author;
}

int ImageMD::getWidth() const{
    return _width;
}

void ImageMD::setWidth(int width) {
    if (width >= 0) {
        _width = width;
    }
    else {
        std::cout << "Error (Not able to set value) Invalid Format of Width \n";

    }
}

int ImageMD::getHeight() const{
    return _height;
}

void ImageMD::setHeight(int height) {
    if (height >= 0) {
        _height = height;
    }
    else {
        std::cout << "Error (Not able to set value) Invalid Format of Height \n";

    }
}


std::string ImageMD::getASize() const{
    return _aSize;
}

void ImageMD::setASize(std::string aSize) {
    int num = 0;
    if (aSize[0] == 'f' && aSize[1] == '/') {
        for (int i = 2; i < aSize.size(); i++) {
            if (isdigit(aSize[i]) == false || isdigit(aSize[i + 1]) == false) {
                break;
            }
            if (isdigit(aSize[i]) == true && isdigit(aSize[i + 1]) == true) {
                num++;
            }

        }
        if (num > 0) {
            _aSize = aSize;
        }

    }
    else {
        std::cout << "Error (Not able to set value) Invalid Format of Aperture Size \n";

    }
}

std::string ImageMD::getExpTime() const {
    return _expTime;
}
void ImageMD::setExpTime(std::string expTime) {
    int num = 0;
    int count = 0;
    int dashOverOne = 0;
    int dashCount = 0;
    int negativeSignCount = 0;
    for (int i = 0; i < expTime.size(); i++) {
        if (expTime[i] == '-') {
            negativeSignCount++;
        }

        if (expTime[i] == '/') {
            count++;
            dashCount++;
            if (count > 1) {
                dashOverOne++;
            }
        }
        if (count <= 1) {
            if (expTime[i] != '/') {
                if (isdigit(expTime[i]) == false) {
                    num++;
                }

            }
        }
    }


    if (num == 0 && count <= 1 && dashOverOne == 0 && dashCount > 0 && negativeSignCount == 0) {
       
            _expTime = expTime;
        
    }
    else {
        std::cout << "Error (Not able to set value) Invalid Format of Exposure Time \n";
       

    }

}

int ImageMD::getIsoValue() const {
    return _isoValue;
}


void ImageMD::setIsoValue(int IsoValue) {
    if (IsoValue >= 0) {
        _isoValue = IsoValue;
    }
    else {
        std::cout << "Error (Not able to set value) Invalid Format of ISO Value \n";
    }
}

bool ImageMD::getFlash() const {
    return _flash;
}

void ImageMD::setFlash(bool flash) {
    if (flash == true || flash == false) {
        _flash = flash;
    }
    else {
        std::cout << "Error (Not able to set value) Invalid Format of Flash \n";
    }
}


std::ostream& operator<<(std::ostream& out, const ImageMD& imageMD) {

    std::string flash;
    if (imageMD.getFlash() == true) {
        flash = "Flash: Enabled \n";

    }

    if (imageMD.getFlash() == false) {
        flash = "Flash: Disenabled \n";
    }

    out << "Here are the properties of your image Metadata....\n File Name: " << imageMD.getFile() << "\n Image Type: "
        << imageMD.getImgType() << "\n Date Created: " << imageMD.getMonth() << "/" << imageMD.getDay() <<
        "/" << imageMD.getYear() << "\n Size in MB: " << imageMD.getSizeMB() << " MB \n Author Name"
        << imageMD.getAuthor() << "\n Image Dimensions in PPI (width x height): " << imageMD.getWidth() << " x " << imageMD.getHeight() <<
        "\n Aperture Size: " << imageMD.getASize() << "\n Exposure Time: " << imageMD.getExpTime() << "\n ISO Value: "
        << imageMD.getIsoValue() << "\n" << flash << "\n";

    return out;
}