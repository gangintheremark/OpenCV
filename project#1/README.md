## [C++ OpenCV]
#### 1. 이진영상 만들기

Thresholding 임계값 처리로 binary 이미지 만들기

```c++

	threshold(image, result, 128, 255, THRESH_BINARY);

```
임계값 128을 기준으로 이상이면 1, 이하면 0으로 처리한다.



