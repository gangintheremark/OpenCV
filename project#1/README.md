## [C++ OpenCV]
### 1. 이진영상 만들기

Thresholding 임계값 처리로 binary 이미지 만들기

```c++

	threshold(image, result, 128, 255, THRESH_BINARY);

```
임계값 128을 기준으로 이상이면 1, 이하면 0으로 처리한다.

![binary](https://user-images.githubusercontent.com/81904943/139826715-3d9b59ee-30ad-4e0d-8c12-881c8d7538c1.PNG)

### 2. 반전영상 만들기 

각 화소값이 영상 내 대칭이 되는 값으로 변환 

```c++
result = image.clone();

result = 255 - result;
// ex. 화소값 0번은 255번으로, 1번은 254번으로 
```

![반전](https://user-images.githubusercontent.com/81904943/139827596-4aa3a346-050d-43a0-91c0-73c5847a351e.PNG)

### 3. 기본 명암 대비 스트레칭 기법 

기본 명암 대비 스트레칭 공식을 이용한다.

> new pixel = (old pixel - low ) x 255 / (high - low)
> - low : 입력 영상 내 가장 작은 값
> - high : 입력 영상 내 가장 큰 값   

```c++
	float index = 255 / (float)(highvalue - lowvalue);

		for (int i = 0; i < image.rows; i++) {
			for (int j = 0; j < image.cols; j++) 
				result.at<uchar>(i, j) = (uchar)(image.at<uchar>(i, j) - lowvalue) * index;	 
		}	
```



