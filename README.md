# Tree-Phenotyping
* Create custom COCO dataset to detect for Tree Phenotypes (Branch and Trunk) using [cvat](https://cvat.org)
* Train [Detectron2](https://github.com/facebookresearch/detectron2) with custom COCO dataset
  * Fine-tune a coco-pretrained [R50-FPN Mask R-CNN model](https://github.com/facebookresearch/detectron2/blob/master/configs/COCO-InstanceSegmentation/mask_rcnn_R_50_FPN_3x.yaml) on custom dataset
  * It takes ~6 minutes to train 300 iterations on Colab's K80 GPU with 90% accuracy
  * Randomly select a sample to visualize the prediction results
