
#include "subimage_feature.h"

int main()
{
    Mat image = imread("/home/liuhang/a.png");
    int tile_size = 150;
    vector<KeyPoint> kp;
    detect(image, tile_size, kp);


    Mat kpm;
    drawKeypoints(image, kp, kpm, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    cv::Size size(kpm.cols/2,kpm.rows/2);
    cv::resize(kpm, kpm, size, (0,0), (0,0), cv::INTER_LINEAR);
    imshow("kp", kpm);
    cout<<"sub_fea "<<kp.size()<<endl;
    imwrite("/home/liuhang/sub_fea.png", kpm);
    waitKey(0);

    return 0;
}