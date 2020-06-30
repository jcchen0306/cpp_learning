#ifndef IMGFILE_H
#define IMGFILE_H

#include <opencv2/opencv.hpp>
#include <QImage>
#include <QPixmap>



QImage  cvMatToQImage( const cv::Mat &inMat );

cv::Mat QImageToCvMat( const QImage &inImage, bool inCloneImageData = true );

QPixmap cvMatToQPixmap( const cv::Mat &inMat );

cv::Mat QPixmapToCvMat( const QPixmap &inPixmap, bool inCloneImageData = true );

#endif // IMGFILE_H
