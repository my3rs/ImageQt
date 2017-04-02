#include "image.h"


Image::Image(QString path)
{
    pixmap.load(path);
    img.load(path);
    QFile file(path);
    info = new QFileInfo(file.fileName());
}


Image::~Image()
{

    if (info)
    {
        delete info;
        info = NULL;
    }
}

void Image::load(QString path)
{
    pixmap.load(path);
    QFile file(path);
    if (info)
    {
        delete info;
        info = new QFileInfo(file.fileName());
    }
}

void Image::save(QString path)
{
    pixmap.save(path, 0, 60);

}

QPixmap Image::pixmapObject()
{
    return pixmap;
}

QImage Image::imageObject()
{
    return img;
}

QString Image::path()
{
    return info->absoluteFilePath();

}

QString Image::name()
{
    return info->fileName();
}

QString Image::baseName()
{
    return info->baseName();
}

QString Image::extension()
{
    return "." + info->suffix();
}

QString Image::directory()
{
    return info->path() + "/";
}

int Image::width()
{
    pixmap.width();
}

int Image::height()
{
    pixmap.height();
}


void Image::updatePixmap(QPixmap newPixmap)
{

    pixmap = QPixmap(newPixmap);
}

void Image::updateImage(const QImage &image)
{
    img = image;
}
