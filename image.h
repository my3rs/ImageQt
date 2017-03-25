#ifndef IMAGE_H
#define IMAGE_H

#include <QPixmap>
#include <QFile>
#include <QFileInfo>
#include <QImage>

class Image
{
private:
    QImage img;
    QPixmap pixmap;
    QFileInfo *info;

public:
    Image(QString path);
    ~Image();

    void load(QString path);
    void save(QString path);

    void updatePixmap(QPixmap newPixmap);
    void updateImage(const QImage &image);

    QPixmap pixmapObject();
    QImage imageObject();
    QString path();         // /home/ttj/Pictures/logo.png
    QString name();         // logo.png
    QString baseName();     //logo
    QString extension();    //.png
    QString directory();    // /home/ttj/Pictures

    int width();
    int height();
};

#endif // IMAGE_H
