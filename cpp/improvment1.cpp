double threshold;

class Image_block{
public:

  //int pointnumber;
  double density;
  std::vector<CvPoint2D32f> ori_point;
  std::vector<CvPoint2D32f> new_point;

  image_block();

  bool density_jugdment();
  //bool load_point();
  double cal_block_density();
  ~image_block();
}


std::vector<std::vector<Mat> > partitionImage(Mat&src, int rows, int cols)
{
	std::vector<std::vector<Mat> > array(rows, std::vector<Mat>(cols));

	int irows = src.rows, icols = src.cols;
	int dr = irows / rows, dc = icols / cols;
	int delt_y=(irows%rows)/2,delt_x=(icols%cols)/2;

  Image_block **bp;

  //分割图像并加载特征点
  for(int i=0;i<rows;i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int x = j * dc + delt_x, y = i * dr + delt_y;
			array[i][j] = src(cv::Rect(x, y, dc, dr));
      for(int p = 0; p < final_matches.size(); p++)
      {
        int pre_x = j*dc + delt_x, pre_y = i*dr + delt_y;
        int nex_x = (j+1)*dc + delt-x, nex_y = (i+1)*dr + delt_y;
        if(kpt.pt.x >= pre_x&&kpt.pt.x <= nex_x && kpt.pt.y >= pre_y &&kpt.pt.y <= nex_y)
        {
          bp[i][j].ori_point.push_back(kpt);
        }
      }
		}
	}
	//return array;
}



//计算每份块图像的特征点密度
double image_block::cal_block_density(vector<KeyPoint>&kpoint){

  std::vector<std::vector<Mat> > array(rows, std::vector<Mat>(cols));

	int irows = src.rows, icols = src.cols;
	int dr = irows / rows, dc = icols / cols;

	int delt_y=(irows%rows)/2,delt_x=(icols%cols)/2;

  //density = ori_point.size()/((dc+delt_x)*(dr+delt_y);
  for(int i=0; i<rows; i)

  return density;
}

//计算加权平均密度
double Cal_Ave_Density(){

  return ave_density;
}

//密度判断
bool image_block::density_jugdment(){
  if(fabs(density-ave_density)<=threshold){
    cout<<"this block doesn't need to be expended"<<endl;
    return true;
  }
  else if(fabs(density-ave_density)>threshold){

    //执行扩张点的操作
    for (int i = 0; i < final_matches.size(); i = i + 4) {
      const cv::KeyPoint&kp_1 = ori_point[i].queryIdx];
      const cv::KeyPoint&kp_2 = ori_point[i + 1].queryIdx];
      const cv::KeyPoint&kp_3 = ori_point[i + 2].queryIdx];
      const cv::KeyPoint&kp_4 = ori_point[i + 3].queryIdx];
      new_point.push_back(CrossPoint1(kp_1, kp_2, kp_3, kp_4));
      new_point.push_back(CrossPoint1(kp_1, kp_3, kp_2, kp_4));
      new_point.push_back(CrossPoint1(kp_1, kp_4, kp_2, kp_3));
    }

    //计算扩张后的密度
    for(int i = 0; i<new_point.size(); i++){
      ori_point.push_back(new_point[i]);
    }
    cal_block_density(ori_point);

    //再次判断
    density_jugdment();
  }
}
