stereo matching 
==========
Simple CPU implementation from sratch of Block Matching using simple Sum of Square difference Matching Cost. Also have the option for parallel computing  
You can either compile the code to executable with gcc or visual studio with Opencv installed   

left image:  
![image](im1.png)  
right image:  
![image](im2.png)  
disparity image with fixed windows ssd:  
![image](depth.png)  
disparity image with rank transform:  
![image](depth_rank.png)  
disparity image with census transform:  
![image](depth_census.png)  

Clearly, using rank transform or census transform looks better, probably the nature of these transform make left and right images less sensitive to illumination changes.  

---
## Reqirement 

    $OPENCV

**Usage**

    ./stereo_mathing -left=<left image> -right=<right image> -max-disparity=<disparity range> -output=<output image file> -parallel=<if you want to run parallel version> -cost=<matching cost function ex: rank or census>

**Examples**

    ./stereo_matching -left=im1.png -right=im2.png -max-disparity=50 -output=depth.png -parallel=no -cost=rank


