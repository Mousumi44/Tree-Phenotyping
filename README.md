# Tree-Phenotyping
* Created custom COCO dataset for detection of Tree Phenotypes (Branch and Trunk) using [cvat](https://cvat.org)
* Trained [Detectron2](https://github.com/facebookresearch/detectron2) with custom COCO dataset
  * Fine-tuned a coco-pretrained [R50-FPN Mask R-CNN model](https://github.com/facebookresearch/detectron2/blob/master/configs/COCO-InstanceSegmentation/mask_rcnn_R_50_FPN_3x.yaml) on custom dataset
  * It took ~6 minutes to train 300 iterations on Colab's K80 GPU with 90% accuracy
  * Randomly selected a sample to visualize the prediction results
