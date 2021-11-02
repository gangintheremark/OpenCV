## [C++ OpenCV]
#### 1. 이진영상 만들기

Thresholding 임계값 처리로 binary 이미지 만들기

```c++

	threshold(image, result, 128, 255, THRESH_BINARY);

```
임계값 128을 기준으로 이상이면 1, 이하면 0으로 처리한다.

![binary](https://user-images.githubusercontent.com/81904943/139826715-3d9b59ee-30ad-4e0d-8c12-881c8d7538c1.PNG)



