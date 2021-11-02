## [C++ OpenCV]
### 1. 이진영상 만들기

Thresholding 임계값 처리로 binary 이미지 만들기

```c++

threshold(image, result, 128, 255, THRESH_BINARY);

```
임계값 128을 기준으로 이상이면 1, 이하면 0으로 처리한다.

### 2. 반전영상 만들기 

각 화소값이 영상 내 대칭이 되는 값으로 변환 

```c++
result = image.clone();

result = 255 - result;
// ex. 화소값 0번은 255번으로, 1번은 254번으로 
```

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

### 4. 앤드인 탐색 기법

> if(old pixel <= low) <br>
>   new pixel = 0 <br>
> else if (low <= old pixel && old pixel <= high) <br>
> 	new pixel = (old pixel - low ) x 255 / (high - low)  <br>
> else  <br>
> 	new pixel = 255  <br>
> - low : 입력 영상 내 가장 작은 값
> - high : 입력 영상 내 가장 큰 값  

```c++
for (int i = 0; i < image.rows; i++) {
	for (int j = 0; j < image.cols; j++) {
		if (lowvalue >= image.at<uchar>(i, j))
			result.at<uchar>(i, j) = 0;

		else if (lowvalue <= image.at<uchar>(i, j) && highvalue >= image.at<uchar>(i, j))
			result.at<uchar>(i, j) = (uchar)(image.at<uchar>(i, j) - lowvalue) * index;

		else if (highvalue <= image.at<uchar>(i, j))
			result.at<uchar>(i, j) = 255;
	}
}
```


