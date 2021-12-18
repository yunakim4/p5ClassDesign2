#include <string>
#pragma once
class ImageMD {
public:
    ImageMD(std::string file,std::string imgType,  int month, int day,
        int year,  double sizeMB, std::string author, int width, int height, std::string aSize,
        std::string expTime, int IsoValue, bool flash);

    std::string getFile() const;
    void setFile(std::string file);
    std::string getImgType() const;
    void setImgType(std::string imgType);
    int getMonth() const;
    void setMonth(int month);
    int getDay() const;
    void setDay(int day, ImageMD imageMD);
    int getYear() const;
    void setYear(int year);
    double getSizeMB() const;
    void setSizeMB(double sizeMB);
    std::string getAuthor() const;
    void setAuthor(std::string author);
    int getWidth() const;
    int getHeight() const;
    void setWidth(int width);
    void setHeight(int height);
    std::string getASize() const;
    void setASize(std::string aSize);
    std::string getExpTime() const;
    void setExpTime(std::string expTime);
    int getIsoValue() const;
    void setIsoValue(int IsoValue);
    bool getFlash() const;
    void setFlash(bool flash);

private:
    std::string _file;
    std::string _imgType;
    int _month;
    int _day;
    int _year;
    double _sizeMB;
    std::string _author;
    int _width;
    int _height;
    std::string _aSize;
    std::string _expTime;
    int _isoValue;
    bool _flash;

};

std::ostream& operator<<(std::ostream& out, const ImageMD& imageMD);
