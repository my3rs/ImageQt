#ifndef GAUSSIANBLUR_H
#define GAUSSIANBLUR_H

#include <vector>

#include "qcolor.h"
#include "qimage.h"

using std::vector;

class GaussianBlur
{

public:
    GaussianBlur(int blurRadius, double sigma);

    QImage BlurImage(const QImage& in);

    float GaussFunc(float x);

    int getBlurRadius() const;
    void setBlurRadius(int value);

    float getSigma() const;
    void setSigma(float value);

    ~GaussianBlur();

private:

    vector<float> mConvolutionMatrix;

    int ReflectIndex(int x, int length);
    void CreateConvolutionMatrix();

    int mBlurRadius;
    float mSigma;
};

#endif // GAUSSIANBLUR_H
