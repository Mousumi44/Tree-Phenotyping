# Tree-Phenotyping
* Created custom COCO dataset for detection of Tree Phenotypes (Branch and Trunk) using [cvat](https://cvat.org)
* Trained [Detectron2](https://github.com/facebookresearch/detectron2) with custom COCO dataset
  * Fine-tuned a coco-pretrained [R50-FPN Mask R-CNN model](https://github.com/facebookresearch/detectron2/blob/master/configs/COCO-InstanceSegmentation/mask_rcnn_R_50_FPN_3x.yaml) on custom dataset
  * It took ~6 minutes to train 300 iterations on Colab's K80 GPU with 90% accuracy
  * Randomly selected a sample to visualize the prediction results
  
  [![](https://img.shields.io/badge/Notebook-Run_in_Colab-EE4C2C?logo=PyTorch)](https://colab.research.google.com/drive/1FIHlN1xKRe8ufO0k42GvL_SqD06pAdp7)
  
# Stereo Matching 
Simple CPU implementation from scratch of Block Matching using simple Sum of Square difference and rank transform as matching cost. 
You can either compile the code to executable with g++ with Opencv installed. This have been tested in Mac.    

---
**Reqirement**

    ### OpenCV ###
    * To install OpenCV using brew
    
      brew install opencv
    
    * To install pkg-config using brew
    
      brew install pkg-config
    
    * View OpenCV linker flags
    
      pkg-config --cflags --libs opencv4
    

**Compile**

    g++ $(pkg-config --cflags --libs opencv4) -std=c++11 stereo_matching.cpp -o stereo_matching 

**Usage**

    ./stereo_mathing -left=<left image> -right=<right image> -max-disparity=<disparity range> -window_size=<window size for block matching> -tranwin_size=<window size for transformation> -output=<output image file> 

**Examples**

    ./stereo_matching -left=left000116.png -right=right000116.png -max-disparity=50 -window_size=6 -tranwin_size=7 -output=depth_new.png


**Theory**

[Youtube](https://www.youtube.com/watch?v=jzis4WE3Vc8&ab_channel=UCFCRCV)

