#define _USE_MATH_DEFINES
#include "gaussianblur.h"
#include <math.h>
#include <algorithm>
#include <numeric>
#include <functional>


GaussianBlur::GaussianBlur(int blurRadius, double sigma) :
                    mBlurRadius(blurRadius),
                    mSigma(sigma)
{
    CreateConvolutionMatrix();
}

QImage GaussianBlur::BlurImage(const QImage& in)
{
    if(in.isNull())
        return QImage();

    QImage image(in.size(), in.format());

    int matrixSize = mConvolutionMatrix.size();
    int halfMatrixSize = matrixSize / 2;

    float sumRed = 0.0f;
    float sumBlue = 0.0f;
    float sumGreen = 0.0f;
    float matrixValue = 0.0f;
    int x1 = 0, y1 = 0;

    for (int x = 0; x < in.width(); ++x)
    {
        for (int y = 0; y < in.height(); ++y)
        {
            for (int kx = -halfMatrixSize; kx <= halfMatrixSize; ++kx)
            {
                x1 = ReflectIndex(x - kx, in.width());

                QColor color(in.pixel(x1, y));

                matrixValue = mConvolutionMatrix[kx + halfMatrixSize];

                sumRed += color.red() * matrixValue;
                sumBlue += color.blue() * matrixValue;
                sumGreen += color.green() * matrixValue;
            }

            QRgb finalColor = qRgb(sumRed, sumGreen, sumBlue);
            image.setPixel(x, y, finalColor);

            sumRed = sumGreen = sumBlue = 0.0f;
        }
    }

    for (int x = 0; x < in.width(); ++x)
    {
        for (int y = 0; y < in.height(); ++y)
        {
            for (int ky = -halfMatrixSize; ky <= halfMatrixSize; ++ky)
            {
                y1 = ReflectIndex(y - ky, in.height());

                QColor color(image.pixel(x, y1));
                matrixValue = mConvolutionMatrix[ky + halfMatrixSize];

                sumRed += color.red() * matrixValue;
                sumBlue += color.blue() * matrixValue;
                sumGreen += color.green() * matrixValue;
            }

            QRgb finalColor = qRgb(sumRed, sumGreen, sumBlue);
            image.setPixel(x, y, finalColor);

            sumRed = sumGreen = sumBlue = 0.0f;
        }
    }

    return image;
}

float GaussianBlur::GaussFunc(float x)
{
    // Gaussian function in one dimension
    return (1 / sqrtf(2*M_PI * mSigma * mSigma)) *
            exp(-(x*x)/(2*mSigma*mSigma));
}

void GaussianBlur::CreateConvolutionMatrix()
{
    int x = 0;
    size_t matrixSize, halfMatrixSize;

    matrixSize = (size_t)(2*mBlurRadius + 1);
    halfMatrixSize = matrixSize / 2;

    mConvolutionMatrix.resize(matrixSize);

    vector<float>::iterator begin = mConvolutionMatrix.begin();
    vector<float>::iterator end = mConvolutionMatrix.end();

    x = -(int)halfMatrixSize;
    std::for_each(begin, end,
                [&] (float& val) mutable
                {
                    val = GaussFunc(x);
                    x++;
                });

    // normalize the values in the convolution matrix
    float sum = std::accumulate(begin, end, 0.0f);

    std::for_each(begin, end, [&] (float& val) { val /= sum; });
}

int GaussianBlur::ReflectIndex(int x, int length)
{
    if (x < 0)
        return -x - 1;
    else if(x >= length)
        return 2*length - x - 1;

    return x;
}

float GaussianBlur::getSigma() const
{
    return mSigma;
}

void GaussianBlur::setSigma(float value)
{
    mSigma = value;
    CreateConvolutionMatrix();
}

int GaussianBlur::getBlurRadius() const
{
    return mBlurRadius;
}

void GaussianBlur::setBlurRadius(int value)
{
    mBlurRadius = value;
    CreateConvolutionMatrix();
}

GaussianBlur::~GaussianBlur()
{
}
