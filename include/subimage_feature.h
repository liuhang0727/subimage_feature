//
// Created by liuhang on 19-5-3.
//

#ifndef SUBIMAGE_FEATURE_H
#define SUBIMAGE_FEATURE_H

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

void detect(Mat image, int s, vector<KeyPoint> &kp)
{
    int rows = image.rows;
    int cols = image.cols;
    int row_tiles = ceil(1.0*rows/s);
    int col_tiles = ceil(1.0*cols/s);
    int remain_rows = rows % s;
    int remain_cols = cols % s;

    for(int i=0; i<row_tiles; i++)
    {
        for(int j=0; j<col_tiles; j++)
        {
            Mat sub_image;
            vector<KeyPoint> sub_kp;

            if(i != row_tiles-1)
            {
                if(j != col_tiles-1)
                {
                    sub_image = image(Rect(j*s, i*s, s, s));
                }
                else
                {
                    if(remain_cols != 0)
                    { sub_image = image(Rect(j*s, i*s, remain_cols, s)); }
                    else
                    { continue; }
                }
            }
            else
            {
                if(j != col_tiles-1)
                {
                    if(remain_rows != 0)
                    { sub_image = image(Rect(j*s, i*s, s, remain_rows)); }
                    else
                    { continue; }
                }
                else
                {
                    if(remain_rows != 0 && remain_cols != 0)
                    { sub_image = image(Rect(j*s, i*s, remain_cols, remain_rows)); }
                    else
                    { continue; }
                }
            }

            Ptr<FeatureDetector> det = FeatureDetector::create("ORB");
            det->detect(sub_image, sub_kp);
            for(int m=0; m<sub_kp.size(); m++)
            {
                KeyPoint p;
                p = sub_kp[m];
                p.pt.x = p.pt.x + j*s;
                p.pt.y = p.pt.y + i*s;

                kp.push_back(p);
            }
        }
    }
}

#endif //SUBIMAGE_FEATURE_H
